#include <stdio.h>
#include <stdlib.h>
#include "structFormat.c"
#include "sortTanggal.c"
#include "cekCatatan.c"
#include "updateCatatan.c"
#include "fileHandling.c"
#include "menu.c"

int main () {
	struct Catatan c[7] =
						{{2,3,10000,1,1,1111,11110101},
						{1,0,999999999,1,1,9999,99990101},
						{1,0,999999999,1,1,9999,99990101},
						{2,1,12000,11,9,1111,11110911},
						{2,1,12000,11,9,1111,11110911},
						{2,1,12000,11,9,1111,11110911},
						{2,2,31000,31,1,1111,11110131}};
	int n = sizeof(c)/sizeof(c[0]);
	
	int abc = cariCatatan(c,n,0);
	printf("%d\n",abc);
//	hapusCatatan(&c[1]);
	sortTanggal(c,n);
	
//	updateCatatan(&c[0]);
	menu(c,n);
//	cekCatatan(c,n);
	
	return 0;
}