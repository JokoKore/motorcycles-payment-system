#include <stdio.h>
#include "login_admin.c"
#include "login_pembeli.c"
#include "kelola_data_motor.c"

int main(int argc, char const *argv[])
{

    int pilihan;
    printf("\n\t\t\t\t-----------------Selamata datang diToko Motor KEL02-----------------\n");
    printf("\n\t\t\t\t-----------------Silaka Login Terlebih Dahulu-----------------\n");
    printf("1. Login Admin\n");
    printf("2. login Pembeli\n");
    printf("Masukkan Pilihan Anda : ");
    scanf("%d", &pilihan);


    switch (pilihan)
    {
        case 1:
            loginAdmin();
            kelolaDataMotor();

        break;

        case 2:
            loginPembeli();
            break;
    
         default:
         printf("Pilihan tidak valid!\n");
        break;
    }
    return 0;
}


