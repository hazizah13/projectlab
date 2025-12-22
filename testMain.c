#include <stdio.h>
#include <stdlib.h>
#include "structFormat.c"
#include "sortTanggal.c"
#include "updateCatatan.c"
#include "cekCatatan.c"
#include "fileHandling.c"
#include "menu.c"

int main () {
	int n = 3;
	struct Catatan c[100] = {};
	
	menu(c,n);
	
//	for(i=0;i<n;i++){
//		printf("Index %d: %d %d %d\n",i, c[i].hari,c[i].bulan,c[i].tahun);
//		printf("%s\n", bulanApa(c[i].bulan));
//		printf("Kode: %d\n",c[i].kodeTanggal);
//	}
//	
	return 0;
}