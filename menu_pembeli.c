#include "header.h"
#include <stdio.h>
#include <string.h>

void hapusMotor(int indexHapus);

int menuPembeli() {
  int pilihan;

  do {
    printf("\n\n========================================\n");
    printf("           MENU  PEMBELI\n");
    printf("========================================\n");
    printf("1. Menu Pembelian\n");
    printf("2. Lihat Daftar Motor\n");
    printf("3. Keluar\n");
    printf("========================================\n");
    printf("Masukkan pilihan Anda: ");
    scanf("%d", &pilihan);

    switch (pilihan) {
    case 1: {
        int metodePembayaran;

        struct Motor data[50];
        int jumlah = 0;
        FILE *fp;

        fp = fopen("motor.dat", "rb");
        if (fp == NULL) {
          printf("\nBelum ada data motor tersedia!\n");
          break;
        }

        fread(&jumlah, sizeof(int), 1, fp);
        fread(data, sizeof(struct Motor), jumlah, fp);
        fclose(fp);

        int pilihanMotor;
        printf("\nPilih motor yang ingin dibeli:\n");
        scanf("%d", &pilihanMotor);

        struct Motor motor;
        for (int i = 0; i < jumlah; i++) {
            if (i == pilihanMotor) {
                motor = data[i];
              }
        }

        printf("\n=== MENU PEMBELIAN ===\n");
        printf("\nMetode Pembayaran:\n");
        printf("1. Cash\n");
        printf("2. Credit\n");
        printf("Pilih Metode (1/2): ");
        scanf("%d", &metodePembayaran);

        if (metodePembayaran == 1) {
        float jumlahBayar, kembalian;
        printf("\n=== PEMBAYARAN CASH ===\n");
        printf("Masukkan Jumlah Uang: Rp ");
        scanf("%f", &jumlahBayar);

        if (jumlahBayar >= motor.harga_final) {
          kembalian = jumlahBayar - motor.harga_final;
          printf("\n--- STRUK PEMBAYARAN ---\n");
          printf("Motor        : %s %s\n", motor.merk, motor.tipe);
          printf("Harga        : Rp %.0f\n", motor.harga_final);
          printf("Jumlah Bayar : Rp %.0f\n", jumlahBayar);
          printf("Kembalian    : Rp %.0f\n", kembalian);
          printf("Metode       : Cash\n");
          printf("------------------------\n");
          printf("\nPembelian Berhasil!\n");

          hapusMotor(pilihanMotor);
        } else {
          printf("\nUang tidak cukup! Kurang Rp %.0f\n",
                 motor.harga_final - jumlahBayar);
        }

      } else if (metodePembayaran == 2) {
        int tenor;
        float dp;
        float sisaHutang, cicilanPerBulan, bunga = 0.02; 

        printf("\n=== PEMBAYARAN CREDIT ===\n");
        printf("Total Harga: Rp %.2f\n", motor.harga_final);
        printf("Masukkan (DP): Rp ");
        scanf("%f", &dp);

        if (dp > motor.harga_final) {
          printf("\nDP tidak boleh lebih besar dari harga motor!\n");
          break;
        }

        printf("Masukkan Tenor (bulan): ");
        scanf("%d", &tenor);

        if (tenor <= 0) {
          printf("\nTenor harus lebih dari 0 bulan!\n");
          break;
        }

        sisaHutang = motor.harga_final - dp;
        cicilanPerBulan = (sisaHutang + (sisaHutang * bunga * tenor)) / tenor;

        printf("\n--- DETAIL KREDIT ---\n");
        printf("Motor           : %s %s\n", motor.merk, motor.tipe);
        printf("Harga Total     : Rp %.2f\n", motor.harga_final);
        printf("DP              : Rp %.2f\n", dp);
        printf("Sisa Hutang     : Rp %.0f\n", sisaHutang);
        printf("Tenor           : %d bulan\n", tenor);
        printf("Bunga           : %.0f%% per bulan\n", bunga * 100);
        printf("Cicilan/Bulan   : Rp %.0f\n", cicilanPerBulan);
        printf("Total Bayar     : Rp %.0f\n", dp + (cicilanPerBulan * tenor));
        printf("Metode          : Credit\n");
        printf("---------------------\n");
        printf("\nPembelian dengan Credit Berhasil!\n");

      } else {
        printf("\nMetode pembayaran tidak valid!\n");
      }

      break;
    }

    case 2: {
  
      struct Motor data[50];
      int jumlah = 0;
      FILE *fp;

      fp = fopen("motor.dat", "rb");
      if (fp == NULL) {
        printf("\nBelum ada data motor tersedia!\n");
        break;
      }

      fread(&jumlah, sizeof(int), 1, fp);
      fread(data, sizeof(struct Motor), jumlah, fp);
      fclose(fp);

      if (jumlah == 0) {
        printf("\nData motor masih kosong!\n");
      } else {
        printf("\n=== DAFTAR MOTOR TERSEDIA ===\n");
        printf("%-5s %-15s %-15s %-10s %-15s\n", "No.", "Merk", "Tipe", "Tahun",
               "Harga");
        printf("==============================================================="
               "===\n");

        for (int i = 0; i < jumlah; i++) {
          printf("%-5d %-15s %-15s %-10d Rp %-15.0f\n", i + 1, 
                data[i].merk,data[i].tipe, data[i].tahun, data[i].harga_final);
        }
      }
      break;
    }

    case 3:
      printf("\nTerima kasih telah menggunakan layanan  kami!\n");
      break;

    default:
      printf("\nPilihan invalid!\n");
      break;
    }

  } while (pilihan != 4);

  return 0;
}



void hapusMotor(int indexHapus) {
    FILE *fp = fopen("motor.dat", "rb");
    if (!fp) return;

    int jumlah;
    struct Motor data[50];

    fread(&jumlah, sizeof(int), 1, fp);
    fread(data, sizeof(struct Motor), jumlah, fp);
    fclose(fp);

    for (int i = indexHapus; i < jumlah - 1; i++) {
        data[i] = data[i + 1];
    }

    jumlah--;

    fp = fopen("motor.dat", "wb");
    fwrite(&jumlah, sizeof(int), 1, fp);
    fwrite(data, sizeof(struct Motor), jumlah, fp);
    fclose(fp);
}
