void menu(struct Catatan c[],int size){
	int opsi;
	
	do {
		puts("MENU\n");
	
		printSeluruhCatatan(c,size,1);
		puts("");
		
		printf("1. Buka File Catatan\n");
		printf("2. Cek Catatan\n");
		printf("3. Perbarui Catatan\n");
		printf("4. Simpan Catatan dalam File\n");
		printf("5. Tutup Program\n");
		ask();
		
		scanf("%d",&opsi);
		puts("");
		
		switch(opsi){
			case 1: bukaFile(); break;
			case 2: cekCatatan(c,size); break;
			case 3: inginUpdate(c,size); break;
			case 4: simpanFile(); break;
			case 5: exit(0); break;
		}
		puts("");
	} while (opsi!=5);
	
}