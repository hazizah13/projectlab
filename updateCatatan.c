void updateTanggal(int *hh, int *bb, int *tttt, int *kode){
	do {
		ask();
		printf("Tahun: ");
		scanf("%d", tttt);
	} while (*tttt<1000||*tttt>9999);
	
	do {
		ask();
		printf("Bulan: ");
		scanf("%d", bb);
	} while (*bb<1||*bb>12);
	
	do {
		ask();
		printf("Hari: ");
		scanf("%d", hh);
	} while (*hh<1 || *hh>31 || *hh>30&&(*bb==4||*bb==6||*bb==9||*bb==11) || *hh>29&&*bb==2 || *hh>28&&*bb==2&&*tttt%4!=0);

	*kode = kodeTgl(*hh,*bb,*tttt);
}

void hapusCatatan(struct Catatan *c){
	c->masukLuar=0;
	c->tipe=0;
	c->nominal=0;
	c->hari=0;
	c->bulan=0;
	c->tahun=0;
	c->kodeTanggal=0;
}

void updateCatatan(struct Catatan *c){
	do {
		printf("1) Pemasukan, 2) Pengeluaran.\n");
		ask();
		scanf("%d",&c->masukLuar);
	} while (c->masukLuar != 1 && c->masukLuar != 2);
	
	if (c->masukLuar==2) {
		do {
			printf("1) Kos/Sewa, 2) Transportasi, 3) Makanan,\n");
			printf("4) Tagihan Bulanan, 5) Perlengkapan Kuliah,\n");
			printf("6) Keperluan Pribadi, 7) Hiburan, 8) Lainnya.\n");
			ask();
			scanf("%d",&c->tipe);
		} while (c->tipe<1 || c->tipe>8);
	} else c->tipe = 0;
	
	do {
		printf("Nominal, tidak lebih dari jutaan.\n");
		ask();
		scanf("%d",&c->nominal);
	} while (c->nominal<1 || c->nominal>999999999);
	
	printf("Tanggal\n");
	updateTanggal(&c->hari,&c->bulan,&c->tahun,&c->kodeTanggal);
}

void inginUpdate(struct Catatan c[], int size){
	puts("PEMBARUAN CATATAN");
	
	int opsi, yn;
	do {
		sortTanggal(c,size);
		i = cariCatatan(c,size,0);
		puts("");
		
		if (i==-1) {
			puts("Catatan sudah penuh. 1) Edit suatu catatan, 2) Hapus suatu catatan, 3) Kembali ke menu.");
			do {
				ask();
				scanf("%d",&opsi);
			} while (opsi<1||opsi>3);
			if (opsi==3) return;
			
			printf("Masukkan nomor catatan yang ingin %s.\n", (opsi==1) ? "diedit" : "dihapus");
			ask();
			scanf("%d",&i);
			i--;
			puts(""); printCatatan(c[i],i); puts("");
			
			printf("%s catatan ini? 1) Ya, 2) Tidak.\n", (opsi==1) ? "Edit" : "Hapus");
			do{
				ask();
				scanf("%d",&yn);
			} while (yn<1||yn>2);
			
			if (opsi==2&&yn==1) {
				hapusCatatan(&c[i]);
				sortTanggal(c,size);
				printSeluruhCatatan(c,size,1);
				puts("Catatan berhasil dihapus.");
			} else if (opsi==1&&yn==1){
				updateCatatan(&c[i]);
				sortTanggal(c,size);
				printCatatan(c[i],i);
				puts("Catatan berhasil diedit."); 
				printSeluruhCatatan(c,size,1);
			}
		} else {
			do {
				puts("1) Edit Catatan Lama, 2) Hapus catatan lama, 3) Buat Catatan Baru, 4) Kembali ke Menu.");
				ask();
				scanf("%d",&opsi);
			} while (opsi<1||opsi>4);
			if (opsi==2) i++;
			else if (opsi==4) i = -1;
			updateCatatan(&c[i]);
			puts(""); printCatatan(c[i],i);
		}
		
	} while (i>=0);
}