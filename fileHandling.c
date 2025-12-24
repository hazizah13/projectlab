#define DATA_FILE "catatan.dat"

void simpanFile(struct Catatan c[],int n){
    FILE *fp = fopen(DATA_FILE, "wb");
    if (fp == NULL){
        printf("Gagal membuka file untuk disimpan.\n");
        return;
    }

    size_t written = fwrite(c, sizeof(struct Catatan), (size_t)n, fp);
    fclose(fp);

    if (written != (size_t)n){
        printf("Gagal menulis data ke file.\n");
    } else {
        printf("Berhasil simpan %d slot catatan ke file.\n", n);
    }
}

void bukaFile(struct Catatan c[], int n){
    FILE *fp = fopen(DATA_FILE, "rb");
    if (!fp){
        printf("File belum ada atau gagal dibuka.\n");
        return;
    }

    i = 0;
    while (i < n && fread(&c[i], sizeof(struct Catatan), 1, fp) == 1){
        i++;
    }
    fclose(fp);

    printf("Berhasil load %d catatan dari file.\n", i);
}