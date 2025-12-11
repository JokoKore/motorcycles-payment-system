#include <stdio.h>
#include "header.h"
#include "menu_admin.h"
#include "kelola_data_motor.h"

void menuAdmin() {
    int pilihan_admin;
    do {
        printf("\n=========== MENU ADMIN ===========\n");
        printf("1. Kelola Data Motor\n");
        printf("0. Logout\n");
        printf("Pilih menu: ");
        scanf("%d", &pilihan_admin);

        switch(pilihan_admin) {
            case 1:
                kelolaDataMotor();
                break;

            case 2: {
                // char tipe_motor[50];
                // int harga;
                // float diskon;

                // printf("Masukkan tipe motor (Sport/Matic/Bebek): ");
                // scanf("%s", tipe_motor);

                // printf("Masukkan harga motor: ");
                // scanf("%d", &harga);

                // printf("Masukkan diskon motor (0.1 untuk 10%%): ");
                // scanf("%f", &diskon);

                // menentukanHarga(tipe_motor, harga, diskon);
                // masukkanHargaKeMotor();

                // float harga_final = harga - (harga * diskon);
                // printf("Harga motor setelah diskon : %.2f\n", harga_final);

                break;
            }

            case 3: 

            case 0:
                printf("Logout berhasil!\n");
                break;

            default:
                printf("Pilihan tidak valid!\n");
        }
    } while (pilihan_admin != 0);
}
