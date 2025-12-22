int cekKosong(struct Catatan c[],int n){
    for (int i = 0; i < n; i++) {
        if (c[i].kodeTanggal == 0) {
            return 1;
        }
    }
    return 0;
}

void headerCatatan(){
	printf("%-20s %-20s %-20s %-15s\n","Kategori","Luar Masuk","Tanggal","Nominal");
	printf("=============================================================================\n");
}
	
void printCatatan(struct Catatan c){
	
	printf("%-20s ", tipeApa(c.tipe));
	printf("%-20s ", masukLuar(c.masukLuar));
	printf("%-2d ", c.hari);
	printf("%-+5s ", bulanApa(c.bulan));
	printf("%-4d ", c.tahun);
	printf("%15d\n", c.nominal);
	   
}

void cekCatatan(struct Catatan c[],int n){
	int opsi, filter;
	
	if (cekKosong(c,n)) {
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
			headerCatatan();
			for (i=0;i<n;i++) printCatatan(c[i]);
			break;
		case 2: 
			printf("0) Pemasukan, 1) Kos/Sewa, 2) Transportasi,\n");
			printf("3) Makanan, 4) Tagihan Bulanan, 5) Perlengkapan Kuliah,\n");
			printf("6) Keperluan Pribadi, 7) Hiburan, 8) Lainnya.\n");
			scanf("%d",&filter);
			headerCatatan();
			for (i=0;i<n;i++) if (c[i].tipe==filter) printCatatan(c[i]);
			break;
		case 3:
			printf("Minimal hh bb tttt");
			break;
		case 4: 
			printf("Nominal minimal");
			break;
		case 5:
			break;
	}
	
		
}