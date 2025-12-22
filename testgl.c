#include <stdio.h>
#include <stdlib.h>

struct Catatan {
	int hari;
	int bulan;
	int tahun;
	int kodeTanggal;
};

void updateTanggal(int *hh, int *bb, int *tttt, int *kode){
	printf("Tahun:\n");
	do {
		scanf("%d", tttt);
	} while (*tttt<1000||*tttt>9999);
	
	printf("Bulan:\n");
	do {
		scanf("%d", bb);
	} while (*bb<1||*bb>12);
	
	printf("Hari:\n");
	do {
		scanf("%d", hh);
	} while (*hh<1 || *hh>31 || *hh>30&&(*bb==4||*bb==6||*bb==9||*bb==11) || *hh>29&&*bb==2 || *hh>28&&*bb==2&&*tttt%4!=0);

	*kode = *tttt*10000 + *bb*100 + *hh;
}

void updateCatatan(struct Catatan *c){
	updateTanggal(&c->hari,&c->bulan,&c->tahun,&c->kodeTanggal);
}

int compareTanggal(const void* a, const void* b){
	int arg1 = ((struct Catatan*) a)->kodeTanggal;
	int arg2 = ((struct Catatan*) b)->kodeTanggal;
	if (arg1<arg2||arg2==0&&arg1!=0) return -1;
	else if(arg1==arg2) return 0;
	else return 1;
}

void sortTanggal(struct Catatan tanggal[],int size){
	printf("\nSORT !!\n\n");
	qsort(tanggal,size,sizeof(tanggal[0]),compareTanggal);
}

int main () {
	int hh,bb,tttt,kode;
	int i, n = 3;
	struct Catatan tanggal[10] = {};
	
	for (i=0;i<n;i++){
		updateCatatan(&tanggal[i]);
	}
	
	for(i=0;i<n;i++){
		printf("Index %d: %d %d %d\n",i, tanggal[i].hari,tanggal[i].bulan,tanggal[i].tahun);
		printf("Kode: %d\n",tanggal[i].kodeTanggal);
	}
	
	sortTanggal(tanggal,sizeof(tanggal)/sizeof(tanggal[0]));
	
	for(i=0;i<n;i++){
		printf("Index %d: %d %d %d\n",i, tanggal[i].hari,tanggal[i].bulan,tanggal[i].tahun);
		printf("Kode: %d\n",tanggal[i].kodeTanggal);
	}
	
	return 0;
}