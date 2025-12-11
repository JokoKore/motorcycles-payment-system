#include "header.h"
#include <stdio.h>
#include <string.h>



int menuPembeli() {
  int pilihan;

  do {
    printf("\n\n========================================\n");
    printf("           MENU  PEMBELI\n");
    printf("========================================\n");
    printf("1. Input Data Diri\n");
    printf("2. Menu Pembelian\n");
    printf("3. Lihat Daftar Motor\n");
    printf("4. Keluar\n");
    printf("========================================\n");
    printf("Masukkan pilihan Anda: ");
    scanf("%d", &pilihan);

    switch (pilihan) {
    case 1: {
    
      struct DataPembeli pembeli;
      FILE *fp;

      printf("\n=== INPUT DATA DIRI ===\n");
      printf("Masukkan Nama Lengkap: ");
      getchar(); 
      scanf("%[^\n]", pembeli.nama);
      getchar(); 

      printf("Masukkan Alamat: ");
      scanf("%[^\n]", pembeli.alamat);
      getchar();

      printf("Masukkan No. Telepon: ");
      scanf("%[^\n]", pembeli.noTelp);
      getchar();

      printf("Masukkan Email: ");
      scanf("%[^\n]", pembeli.email);
      getchar();

      fp = fopen("dataPembeli.dat", "ab");

      if (fp != NULL) {
        fwrite(&pembeli, sizeof(struct DataPembeli), 1, fp);
        fclose(fp);
        printf("\nData diri berhasil disimpan!\n");
      } else {
        printf("\nGagal menyimpan data!\n");
      }
      break;
    }

    case 2: {
      char merkMotor[30], tipeMotor[30];
      int metodePembayaran, hargaMotor;

      printf("\n=== MENU PEMBELIAN ===\n");
      printf("Masukkan Merk Motor yang ingin dibeli: ");
      getchar(); 
      scanf("%[^\n]", merkMotor);
      getchar();

      printf("Masukkan Tipe Motor: ");
      scanf("%[^\n]", tipeMotor);
      getchar();

      printf("Masukkan Harga Motor: Rp ");
      scanf("%d", &hargaMotor);

      printf("\nMetode Pembayaran:\n");
      printf("1. Cash\n");
      printf("2. Credit\n");
      printf("Pilih Metode (1/2): ");
      scanf("%d", &metodePembayaran);

      if (metodePembayaran == 1) {
        int jumlahBayar, kembalian;

        printf("\n=== PEMBAYARAN CASH ===\n");
        printf("Total Harga: Rp %d\n", hargaMotor);
        printf("Masukkan Jumlah Uang: Rp ");
        scanf("%d", &jumlahBayar);

        if (jumlahBayar >= hargaMotor) {
          kembalian = jumlahBayar - hargaMotor;
          printf("\n--- STRUK PEMBAYARAN ---\n");
          printf("Motor        : %s %s\n", merkMotor, tipeMotor);
          printf("Harga        : Rp %d\n", hargaMotor);
          printf("Jumlah Bayar : Rp %d\n", jumlahBayar);
          printf("Kembalian    : Rp %d\n", kembalian);
          printf("Metode       : Cash\n");
          printf("------------------------\n");
          printf("\nPembelian Berhasil!\n");
        } else {
          printf("\nUang tidak cukup! Kurang Rp %d\n",
                 hargaMotor - jumlahBayar);
        }

      } else if (metodePembayaran == 2) {
        int dp, tenor;
        float sisaHutang, cicilanPerBulan, bunga = 0.02; 

        printf("\n=== PEMBAYARAN CREDIT ===\n");
        printf("Total Harga: Rp %d\n", hargaMotor);
        printf("Masukkan (DP): Rp ");
        scanf("%d", &dp);

        if (dp > hargaMotor) {
          printf("\nDP tidak boleh lebih besar dari harga motor!\n");
          break;
        }

        printf("Masukkan Tenor (bulan): ");
        scanf("%d", &tenor);

        if (tenor <= 0) {
          printf("\nTenor harus lebih dari 0 bulan!\n");
          break;
        }

        sisaHutang = hargaMotor - dp;
        cicilanPerBulan = (sisaHutang + (sisaHutang * bunga * tenor)) / tenor;

        printf("\n--- DETAIL KREDIT ---\n");
        printf("Motor           : %s %s\n", merkMotor, tipeMotor);
        printf("Harga Total     : Rp %d\n", hargaMotor);
        printf("DP              : Rp %d\n", dp);
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

    case 3: {
  
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

          printf("%-5d %-15s %-15s %-10d Rp %-15f\n", i + 1, 
                data[i].merk,data[i].tipe, data[i].tahun, data);
        }
      }
      break;
    }

    case 4:
      printf("\nTerima kasih telah menggunakan layanan  kami!\n");
      break;

    default:
      printf("\nPilihan invalid!\n");
      break;
    }

  } while (pilihan != 4);

  return 0;
}




