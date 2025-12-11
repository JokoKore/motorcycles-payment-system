#include <stdio.h>
#include <string.h>
#include "header.h"

void saveToFile(struct Motor data[], int jumlah)
{
    FILE *fp = fopen("motor.dat", "wb");
    fwrite(&jumlah, sizeof(int), 1, fp);
    fwrite(data, sizeof(struct Motor), jumlah, fp);
    fclose(fp);
}

void loadFromFile(struct Motor data[], int *jumlah)
{
    FILE *fp = fopen("motor.dat", "rb");
    if (!fp) {
        *jumlah = 0;
        return;
    }
    fread(jumlah, sizeof(int), 1, fp);
    fread(data, sizeof(struct Motor), *jumlah, fp);
    fclose(fp);
}

int kelolaDataMotor()
{
    struct Motor data[50];
    int jumlah = 0;
    int pilihan;

    loadFromFile(data, &jumlah);

    do {
        printf("\n=== MENU KELOLA DATA MOTOR ===\n");
        printf("1. Tambah Data Motor\n");
        printf("2. Tampilkan Semua Data\n");
        printf("3. Edit Data Motor\n");
        printf("4. Hapus Data Motor\n");
        printf("5. Cari Motor Berdasarkan Merk\n");
        printf("6. Keluar\n");
        printf("Pilihan: ");
        scanf("%d", &pilihan);

        switch (pilihan) {

        case 1: {
            printf("\nMasukkan Merk Motor  : ");
            scanf("%s", data[jumlah].merk);

            printf("Masukkan Tipe Motor  : ");
            scanf("%s", data[jumlah].tipe);

            printf("Masukkan Tahun Motor : ");
            scanf("%d", &data[jumlah].tahun);
            
            printf("Masukkan harga Motor : ");
            scanf("%d", &data[jumlah].harga_final);
            
            data[jumlah].harga_final = 0;

            jumlah++;
            saveToFile(data, jumlah);

            printf("Data motor berhasil ditambahkan!\n");
            break;
        }

        case 2: {
            loadFromFile(data, &jumlah);
            if (jumlah == 0) {
                printf("\nData motor masih kosong!\n");
            } else {
                printf("\n=== LIST DATA MOTOR ===\n");

                for (int i = 0; i < jumlah; i++) {
                    printf("Data ke-%d:\n", i + 1);
                    printf("  Merk        : %s\n", data[i].merk);
                    printf("  Tipe        : %s\n", data[i].tipe);
                    printf("  Tahun       : %d\n", data[i].tahun);
                    printf("  Harga Final : %.2f\n", data[i].harga_final);

                }
            }
            break;
        }

        case 3: {
            int index;
            printf("\nMasukkan nomor data yang akan diedit (1 - %d): ", jumlah);
            scanf("%d", &index);
            index--;

            if (index >= 0 && index < jumlah) {
                printf("Merk Baru  : ");
                scanf("%s", data[index].merk);

                printf("Tipe Baru  : ");
                scanf("%s", data[index].tipe);

                printf("Tahun Baru : ");
                scanf("%d", &data[index].tahun);

                saveToFile(data, jumlah);
                printf("Data motor berhasil diperbarui!\n");
            } else {
                printf("Index tidak valid!\n");
            }
            break;
        }

        case 4: {
            int index;
            printf("\nMasukkan nomor data yang akan dihapus (1 - %d): ", jumlah);
            scanf("%d", &index);
            index--;

            if (index >= 0 && index < jumlah) {
                for (int i = index; i < jumlah - 1; i++) {
                    data[i] = data[i + 1];
                }
                jumlah--;
                saveToFile(data, jumlah);

                printf("Data berhasil dihapus!\n");
            } else {
                printf("Index tidak valid!\n");
            }
            break;
        }

        case 5: {
            char cari[30];
            int found = 0;

            printf("\nMasukkan merk motor yang dicari: ");
            scanf("%s", cari);

            printf("\n=== HASIL PENCARIAN ===\n");
            for (int i = 0; i < jumlah; i++) {
                if (strcmp(data[i].merk, cari) == 0) {
                    printf("Merk  : %s\n", data[i].merk);
                    printf("Tipe  : %s\n", data[i].tipe);
                    printf("Tahun : %d\n", data[i].tahun);
                    found = 1;
                }
            }

            if (!found) {
                printf("Data tidak ditemukan!\n");
            }
            break;
        }

        case 6:
            printf("\nKembali ke menu admin...\n");
            break;

        default:
            printf("Pilihan tidak valid!\n");
        }

    } while (pilihan != 6);

    return 0;
}
