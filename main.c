#include <stdio.h>
#include <stdlib.h>
#include "login_admin.h"
#include "login_pembeli.h"
#include "menu_admin.h"
#include "menu_pembeli.h"

int main()
{

    int pilihan;
    printf("\n\t\t\t\t-----------------Selamat datang di toko botor KELOMPOK 02-----------------\n");
    printf("\n\t\t\t\t-----------------Silakan login terlebih dahulu-----------------\n");
    printf("1. Login Admin\n");
    printf("2. Login Pembeli\n");
    printf("Masukkan Pilihan Anda: ");
    scanf("%d", &pilihan);


    switch (pilihan) {
        case 1:
            if (loginAdmin() != 0) {
                exit(1); 
            }
            menuAdmin();
            break;

        case 2:
          if (loginPembeli() == 1) {
                menuPembeli();
            }
            
            break;
    
        default:
            printf("Pilihan tidak valid!\n");
            break;
    }

    return 0;
}


