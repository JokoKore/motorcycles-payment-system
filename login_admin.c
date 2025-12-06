#include <stdio.h>
#include <string.h>


int loginAdmin() {  
    char user[20], pass[20];
    int percobaan = 3;
    while (percobaan > 0) {
        printf("\nPercobaan tersisa: %d\n", percobaan);

        printf("Username: ");
        scanf("%s", user);
        printf("Password: ");
        scanf("%s", pass);

        if (strcmp(user, "admin") == 0 && strcmp(pass, "123") == 0) {
            printf("\nLogin berhasil!\n");
            return 0;
        } else {
            printf("Username atau password salah!\n");
            percobaan--;
        }
    }

    printf("\nAnda telah gagal login 3 kali. Akses diblokir.\n");

    return 0;
}