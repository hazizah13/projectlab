int i,j,k;

struct Catatan {
	int masukLuar;
	int tipe;
	int nominal;
	int hari;
	int bulan;
	int tahun;
	int kodeTanggal;
};

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