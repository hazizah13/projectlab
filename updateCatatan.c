void updateTanggal(int *hh, int *bb, int *tttt, int *kode){
	do {
		printf("  Tahun: ");
		scanf("%d", tttt);
	} while (*tttt<1000||*tttt>9999);
	
	do {
		printf("  Bulan: ");
		scanf("%d", bb);
	} while (*bb<1||*bb>12);
	
	do {
		printf("  Hari: ");
		scanf("%d", hh);
	} while (*hh<1 || *hh>31 || *hh>30&&(*bb==4||*bb==6||*bb==9||*bb==11) || *hh>29&&*bb==2 || *hh>28&&*bb==2&&*tttt%4!=0);

	*kode = kodeTgl(*hh,*bb,*tttt);
}

void updateCatatan(struct Catatan *c){
	do {
		printf("1) Pemasukan, 2) Pengeluaran.\n");
		scanf("%d",&c->masukLuar);
	} while (c->masukLuar != 1 && c->masukLuar != 2);
	
	if (c->masukLuar==2) {
		do {
			printf("1) Kos/Sewa, 2) Transportasi, 3) Makanan,\n");
			printf("4) Tagihan Bulanan, 5) Perlengkapan Kuliah,\n");
			printf("6) Keperluan Pribadi, 7) Hiburan, 8) Lainnya.\n");
			scanf("%d",&c->tipe);
		} while (c->tipe<1 || c->tipe>8);
	} else c->tipe = 0;
	
	printf("Nominal, tidak lebih dari jutaan\n");
	scanf("%d",&c->nominal);
	
	printf("Tanggal\n");
	updateTanggal(&c->hari,&c->bulan,&c->tahun,&c->kodeTanggal);
}

void inginUpdate(struct Catatan c[]){
	int lagi;
	do {
		updateCatatan(&c[i]);
		puts(""); printCatatan(c[i]); puts("");
		do {
			printf("1) Edit Catatan, 2) Buat Catatan Baru, 3) Kembali ke Menu.\n");
			scanf("%d",&lagi);
		} while (lagi<1||lagi>3);
		if (lagi==2) i++;
		else if (lagi==3) i = -1;
	} while (i>=0);
}