int cekKosong(struct Catatan c[],int n){
    for (i = 0; i < n; i++) {
        if (c[i].kodeTanggal == 0) {
            return i;
        }
    }
    return 0;
}

void header(){
	printf("%-20s %-20s %-20s %-10s\n","Kategori","Luar Masuk","Tanggal","Nominal");
	printf("==============================================================================\n");
}
	
void printCatatan(struct Catatan c){
	
	printf("%-20s ", tipeApa(c.tipe));
	printf("%-20s ", masukLuar(c.masukLuar));
	printf("%-2d ", c.hari);
	printf("%-9s ", bulanApa(c.bulan));
	printf("%-9d ", c.tahun);
	printNominal(c.nominal);
	   
}

void printSeluruhCatatan(struct Catatan c[], int size){
	if (cekKosong(c,size)==0) {
		printf("Belum Ada Catatan\n");
		return;
	}	
	
	header();
	i=0;
	while (c[i].kodeTanggal>0) {
		printCatatan(c[i]);
		i++;
	}
}

void cekCatatan(struct Catatan c[],int size){
	int opsi, filter;
	int hmin,bmin,tmin,hmax,bmax,tmax, tglMin, tglMax;
	int noMin, noMax;
	
	if (cekKosong(c,size)==0) {
		printf("Belum Ada Catatan\n");
		return;
	}	
	
	sortTanggal(c,sizeof(*c)/sizeof(c[0]));
	
	printf("1. Lihat seluruh transaksi\n");
	printf("2. Filter sesuai kategori\n");
	printf("3. Filter sesuai tanggal\n");
	printf("4. Filter sesuai nominal\n");
	printf("5. Kembali ke menu\n");
	printf(">> ");
	scanf("%d",&opsi);
	
	switch (opsi){
		case 1:
			printSeluruhCatatan(c,size);
			break;
		case 2: 
			printf("0) Pemasukan, 1) Kos/Sewa, 2) Transportasi,\n");
			printf("3) Makanan, 4) Tagihan Bulanan, 5) Perlengkapan Kuliah,\n");
			printf("6) Keperluan Pribadi, 7) Hiburan, 8) Lainnya.\n");
			scanf("%d",&filter);
			
			header();
			i=0;
			while (c[i].kodeTanggal>0) {
				if (c[i].tipe==filter) printCatatan(c[i]);
				i++;
			}
			
			break;
		case 3:
			printf("Minimal hh bb tttt ");
			scanf("%d %d %d",&hmin,&bmin,&tmin);
			tglMin = kodeTgl(hmin,bmin,tmin);
			
			printf("Maximal (hh bb tttt) ");
			scanf("%d %d %d",&hmax,&bmax,&tmax);
			tglMax = kodeTgl(hmax,bmax,tmax);
			
			header();
			i=0;
			while (c[i].kodeTanggal>0) {
				if (c[i].kodeTanggal>tglMin&&c[i].kodeTanggal<tglMax) printCatatan(c[i]);
				i++;
			}
			
			break;
		case 4: 
			printf("Nominal minimal");
			scanf("%d",&noMin);
			
			printf("Nominal maximal");
			scanf("%d",&noMax);
			
			header();
			for (i=0;i<size;i++) if (c[i].nominal>noMin&&c[i].nominal<noMax) printCatatan(c[i]);
			
			break;
		case 5:
			//arahin kembali ke menu
			break;
	}
}