void menu(struct Catatan c[],int n){
	int opsi;
	
	cekCatatan(c,n);
	puts("");
	
	printf("1. Buka File Catatan\n");
	printf("2. Perbarui Catatan\n");
	printf("3. Simpan Catatan dalam File\n");
	printf("4. Tutup Program\n");
	
	scanf("%d",&opsi);
	
	switch(opsi){
		case 1: bukaFile(); break;
		case 2: {
			for (i=0;i<n;i++){
				updateCatatan(&c[i]);
			}
			break;
		}
		case 3: simpanFile(); break;
		case 4: exit(0); break;
	}
}