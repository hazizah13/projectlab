#include <stdio.h>
#include <stdlib.h>

int i,j,k;

struct Catatan {
	int masukLuar;
	int tipe;
	int hari;
	int bulan;
	int tahun;
	int tanggalKode;
	int nominal;
};

void menu(){
	int menu;
	
	printf("1. Cek Catatan\n");
	printf("2. Perbarui Catatan Lama\n");
	printf("3. Buat Catatan Baru\n");
	printf("4. Tutup Program\n");
	
	scanf("%d",&menu);
	
	switch(menu){
		case 1: break;
		case 2: break;
		case 3: break;
		case 4: break;
	}
}

char* bulanApa (int bulan){
	   switch (bulan) {
	   	case 1: return "Januari";
	   	case 2: return "Februari"; 
	   	case 3: return "Maret"; 
	   	case 4: return "April"; 
	   	case 5: return "Mei";
	   	case 6: return "Juni";
	   	case 7: return "Juli";
	   	case 8: return "Agustus";
	   	case 9: return "September";
	   	case 10: return "Oktober";
	   	case 11: return "November";
	   	case 12: return "Desember";
	   	default: return "Error Bulan";
	   }
}

char* tipeApa (int tipe){
	   switch (tipe){
	   	case 0: return "Pemasukan";
		case 1: return "Kos/Sewa";
	   	case 2: return "Transportasi";
	   	case 3: return "Makanan";
	   	case 4: return "Tagihan Bulanan";
	   	case 5: return "Perlengkapan Kuliah";
	   	case 6: return "Keperluan Pribadi";
	   	case 7: return "Hiburan";
	   	default: return "Lainnya";
	   }
}

char* masukLuar (int masukLuar) {
	   switch (masukLuar){
	   	case 1: return "Pemasukan (+)";
	   	case 2: return "Pengeluaran (-)";
	   	default: return "Error masukLuar";
	   }
}

void ask(){
	printf(" >> ");
}

void invalid(){
	printf("Data invalid.\n");
}

void updateTanggal(int* hh, int* bb, int* tttt){
	
	printf("Tahun:\n");
	do {
		ask();
		scanf("%d", tttt);
	} while (*tttt<1000||*tttt>9999);
	
	printf("Bulan:\n");
	do {
		ask();
		scanf("%d", bb);
	} while (*bb<1||*bb>12);
	
	printf("Hari:\n");
	do {
		ask();
		scanf("%d", hh);
	} while (*hh<1 || *hh>31 || *hh>30&&(*bb==4||*bb==6||*bb==9||*bb==11) || *hh>29&&*bb==2 || *hh>28&&*bb==2&&*tttt%4!=0);
}

int compareTanggal(const void *a, const void *b) {
	return ((struct Catatan*)a)->tanggalKode - ((struct Catatan*)b)->tanggalKode;
}

void sortTanggal(struct Catatan c[], int n){
	qsort(c ,n ,sizeof(struct Catatan),compareTanggal);
}

void printCatatan(struct Catatan c){
	
	printf("%-20s ", tipeApa(c.tipe));
	printf("%-20s ", masukLuar(c.masukLuar));
	printf("%-2d ", c.hari);
	printf("%-+5s ", bulanApa(c.bulan));
	printf("%-4d ", c.tahun);
	printf("%15d\n", c.nominal);
	   
}

void menuCek(struct Catatan c[]){
	int menu;
	
	printf("1. Lihat seluruh transaksi\n");
	printf("2. Filter sesuai kategori\n");
	printf("3. Filter sesuai tanggal\n");
	printf("4. Filter sesuai nominal\n");
	ask();
	scanf("%d",&menu);
	
	
	switch (menu){
		case 1:
			printf("%-20s %-20s %-20s %-15s\n","Kategori","Luar Masuk","Tanggal","Nominal");
			printf("=============================================================================\n");
			for (i=0;i<3;i++) printCatatan(c[i]);
			break;
		case 2: break;
			
	}
	
	
}

void update(struct Catatan *c) {
	
	do {
		printf("\n1) Pemasukan, 2) Pengeluaran.\n");
		scanf("%d",&c->masukLuar);
	} while (c->masukLuar != 1 && c->masukLuar != 2);
	
	if (c->masukLuar==2) {
		do {
			printf("\n1) Kos/Sewa, 2) Transportasi, 3) Makanan, 4) Tagihan Bulanan, 5) Perlengkapan Kuliah, 6) Keperluan Pribadi, 7) Hiburan, 8) Lainnya.\n");
			scanf("%d",&c->tipe);
		} while (c->tipe<1 || c->tipe>8);
	} else c->tipe = 0;
	
	printf("\nNominal, tidak lebih dari jutaa\n");
	scanf("%d",&c->nominal);
	
	printf("\nTanggal\n");
	updateTanggal(&c->hari,&c->bulan,&c->tahun);
	
	c->tanggalKode = c->tahun*10000 + c->bulan*100 + c->hari;
}

int main() {
	struct Catatan luaran[100];
	int i;
	int n = sizeof(luaran) / sizeof(luaran[0]);

	for(i=0;i<3;i++) update(&luaran[i]);
	
	sortTanggal(luaran, n);
  
	menuCek(luaran);
  return 0;
}