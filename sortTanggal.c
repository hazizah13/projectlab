int compareTanggal(const void* a, const void* b){
	int arg1 = ((struct Catatan*) a)->kodeTanggal;
	int arg2 = ((struct Catatan*) b)->kodeTanggal;
	if (arg1<arg2&&arg1!=0||arg2==0) return -1;
	else if(arg1==arg2) return 0;
	else return 1;
}

void sortTanggal(struct Catatan c[],int size){
	qsort(c,size,sizeof(c[0]),compareTanggal);
}