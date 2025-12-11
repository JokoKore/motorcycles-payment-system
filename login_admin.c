#include <stdio.h>
#include <string.h>


int loginAdmin()
{  
    char user[20], password[20];
    int percobaan = 3;

    while (percobaan > 0) {
        
        printf("Username: ");
        scanf("%s", user);
        printf("Password: ");
        scanf("%s", password);
        
        if (strcmp(user, "admin") != 0 || strcmp(password, "123") != 0) {
            printf("Username atau password salah!\n");
            percobaan--;
            printf("\nPercobaan tersisa: %d\n", percobaan);
            continue;
        }

        printf("\nLogin berhasil! Selamat datang, Admin.\n");
        return 0;
    }

    printf("\nAnda telah gagal login 3 kali. Akses diblokir.\n");

    return 1;
}