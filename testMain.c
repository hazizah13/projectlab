#include <stdio.h>
#include <stdlib.h>
#include "structFormat.c"
#include "sortTanggal.c"
#include "cekCatatan.c"
#include "updateCatatan.c"
#include "fileHandling.c"
#include "menu.c"

int main () {
	int n = 7;
	struct Catatan c[100] ={{0},
						{1,0,999999999,1,1,9999,99990101},
						{2,1,12000,11,9,1111,11110911},
						{2,2,31000,31,1,1111,11110131}};
	
	sortTanggal(c,n);
	
//	updateCatatan(&c[0]);
//	menu(c,n);
	cekCatatan(c,n);
	
	return 0;
}