#include <stdio.h>
#include <string.h>
#include "header.h"

int ambilHargaMotor(const char *tipe, int *harga, float *diskon) {
    FILE *fp = fopen("harga.dat", "rb");
    if (!fp) return 0;

    struct Harga h;

    while (fread(&h, sizeof(struct Harga), 1, fp) == 1) {
        if (strcmp(h.tipe_motor, tipe) == 0) {
            *harga = h.harga;
            *diskon = h.diskon;
            fclose(fp);
            return 1;
        }
    }

    fclose(fp);
    return 0;
}

int menentukanHarga(char *tipe_motor, int harga, float diskon)
{
    FILE *fp = fopen("harga.dat", "ab");
    if (!fp) return -1;

    struct Harga h;
    strcpy(h.tipe_motor, tipe_motor);
    h.harga = harga;
    h.diskon = diskon;

    fwrite(&h, sizeof(struct Harga), 1, fp);

    fclose(fp);
    return harga;
}

void masukkanHargaKeMotor() {
    FILE *fpMotor = fopen("motor.dat", "rb");
    if (!fpMotor) {
        printf("Data motor belum ada!\n");
        return;
    }

    int jumlah;
    fread(&jumlah, sizeof(int), 1, fpMotor);

    struct Motor data[50];
    fread(data, sizeof(struct Motor), jumlah, fpMotor);
    fclose(fpMotor);

    int harga;
    float diskon;

    for (int i = 0; i < jumlah; i++) {
        if (ambilHargaMotor(data[i].tipe, &harga, &diskon)) {
            data[i].harga_final = harga - (harga * diskon);
        } else {
            data[i].harga_final = 0;
        }
    }

    FILE *fpBaru = fopen("motor_tmp.dat", "wb");
    fwrite(&jumlah, sizeof(int), 1, fpBaru);
    fwrite(data, sizeof(struct Motor), jumlah, fpBaru);
    fclose(fpBaru);

    remove("motor.dat");
    rename("motor_tmp.dat", "motor.dat");

    printf("\nHarga berhasil dimasukkan ke motor.dat!\n");
}
