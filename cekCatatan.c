int cariCatatan(struct Catatan c[],int n, int key){
    for (i = 0; i < n; i++) {
        if (c[i].kodeTanggal == key) {
            return i;
        }
    }
    return -1;
}

void header(){
	printf("%-3s %-20s %-20s %-20s %-10s\n","No.","Kategori","Luar Masuk","Tanggal","Nominal");
	printf("==================================================================================\n");
}

void printNominal(int nom){
	int juta = nom/1000000;
	int ribu = (nom%1000000)/1000;
	int ratus = nom%1000;
	char nominal[10];
	if (nom>999999) sprintf(nominal,"Rp%d,%03d,%03d",juta,ribu,ratus);
	else if (nom>999) sprintf(nominal,"Rp%d,%03d",ribu,ratus);
	else sprintf(nominal,"%d",ratus);
	printf("%13s\n",nominal);
}
	
void printCatatan(struct Catatan c, int index){
	
	printf("%-3d ", index+1);
	printf("%-20s ", tipeApa(c.tipe));
	printf("%-20s ", masukLuar(c.masukLuar));
	printf("%-2d ", c.hari);
	printf("%-9s ", bulanApa(c.bulan));
	printf("%-9d ", c.tahun);
	printNominal(c.nominal);
	   
}

void printSeluruhCatatan(struct Catatan c[], int size, int opsi){
	int filter;
	unsigned int hmin,bmin,tmin,hmax,bmax,tmax, tglMin, tglMax;
	unsigned int noMin, noMax;
	
	sortTanggal(c,size);
	
	int kosong = cariCatatan(c,size,0);
	
	if (kosong==0) {
		printf("Belum Ada Catatan\n");
		return;
	}	else if (kosong==-1) kosong=size;
	
	switch (opsi){
		case 1:
			header();
			for (i=0;i<kosong;i++) printCatatan(c[i],i);
			
			break;
		case 2: 
			printf("0) Pemasukan, 1) Kos/Sewa, 2) Transportasi,\n");
			printf("3) Makanan, 4) Tagihan Bulanan, 5) Perlengkapan Kuliah,\n");
			printf("6) Keperluan Pribadi, 7) Hiburan, 8) Lainnya.\n");
			do{
				ask();
				scanf("%d",&filter);
			} while (filter<0||filter>8);
			
			puts("");
			header();
			for (i=0;i<kosong;i++) if (c[i].tipe==filter) printCatatan(c[i],i);
			
			break;
		case 3:
			printf("Dari tanggal (hh bb tttt): ");
			do{
				scanf("%d %d %d",&hmin,&bmin,&tmin);
			} while (hmin<1&&bmin<1&&tmin<1000);
			tglMin = kodeTgl(hmin,bmin,tmin);
			
			printf("Sampai tanggal (hh bb tttt): ");
			do{
				scanf("%d %d %d",&hmax,&bmax,&tmax);
			} while (hmax>31&&bmax>12&&tmax>9999);
			tglMax = kodeTgl(hmax,bmax,tmax);
			
			puts("");
			header();
			for(i=0;i<kosong;i++) if (c[i].kodeTanggal>=tglMin&&c[i].kodeTanggal<=tglMax) printCatatan(c[i],i);
			
			break;
		case 4: 
			printf("Nominal minimal (tidak kurang dari 0): ");
			do{
				scanf("%d",&noMin);
			} while (noMin<0);
			
			printf("Nominal maximal (tidak lebih dari jutaan): ");
			do{
				scanf("%d",&noMax);
			} while (noMax>999999999);
			
			puts("");
			header();
			for(i=0;i<kosong;i++) if (c[i].nominal>=noMin&&c[i].nominal<=noMax) printCatatan(c[i],i);
			
			break;
	}
}

void cekCatatan(struct Catatan c[],int size){
	puts("CEK CATATAN");
	
	int opsi;
	
	do{
		puts("");
		if (cariCatatan(c,size,0)==0) {
			printf("Belum Ada Catatan\n");
			return;
		}	
		
		printf("1. Lihat seluruh transaksi\n");
		printf("2. Filter sesuai kategori\n");
		printf("3. Filter sesuai tanggal\n");
		printf("4. Filter sesuai nominal\n");
		printf("5. Kembali ke menu\n");
		do{
			ask();
			scanf("%d",&opsi);
		} while (opsi<1||opsi>5);
		if (opsi==5) return;
		puts("");
		printSeluruhCatatan(c,size,opsi);
	} while (opsi!=5);
		
}