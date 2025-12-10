#include <stdio.h>

char* bulanApa (int bulan){
	switch (bulan){
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
		case 1: return "Makanan";
		case 2: return "Jajan";
		case 3: return "Kos";
		default: return "Lainnya";
	}
}

char* masukLuar (int masukLuar){
	switch (masukLuar){
		case 1: return "Pemasukan";
		case 2: return "Pengeluaran";
		default: return "Error masukLuar";
	}
}

struct Catatan {
  int tipe;
  int masukLuar;
  int hari;
  int bulan;
  int tahun;
  int nominal;
};

void printCatatan(struct Catatan c){
	printf("%-15s %-20s %-2d %-+5s %-4d %20d\n", tipeApa(c.tipe), masukLuar(c.masukLuar), c.hari, bulanApa(c.bulan), c.tahun, c.nominal);
}


void update(struct Catatan *c) {
	
	printf("\nTipe Transaksi: 1) Makanan, 2) Jajan, 3) Kos, selain itu dibilang Lainnya\n>> ");
	scanf("%d",&c->tipe);
	
	do {
		printf("\n1) Pemasukan, 2) Pengeluaran, gaboleh selain itu\n>> ");
		scanf("%d",&c->masukLuar);
	} while (c->masukLuar != 1 && c->masukLuar != 2);
	
	printf("\nAbis ato dpt brp bang\n>> ");
	scanf("%d",&c->nominal);
	
	printf("\nHari bulan keberapa tahun\n>> ");
	scanf("%d %d %d",&c->hari,&c->bulan,&c->tahun);
}

int main() {
	struct Catatan luaran;

	update(&luaran);
  
  
	printf("%-15s %-20s %-20s %-15s\n","Tipe","Luar Masuk","Tanggal","Nominal");
	printf("==========================================================================\n");
 	printCatatan(luaran);

  return 0;
}