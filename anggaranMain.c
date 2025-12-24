#include <stdio.h>
#include <stdlib.h>
#include "structFormat.c"
#include "sortTanggal.c"
#include "cekCatatan.c"
#include "updateCatatan.c"
#include "fileHandling.c"
#include "menu.c"

int main () {
	struct Catatan c[100] =	{0};
	int n = sizeof(c)/sizeof(c[0]);	
	menu(c,n);
	
	return 0;
}