#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <conio.h>
#include <stdbool.h>

#define ENTER 13
#define TAB 9
#define BCKSPC 8


struct User
{
    char username[50];
    char name[50];
    char email[50];
    char password[50];
    char address[50];
    char gender[20];
};
 
void takeInput(char input[50])
{
    fgets(input, 50, stdin);
    input[strlen(input) - 1] = 0;
}

void takePassword(char password[50])
{
    int i;
    char input;
    while (1) {
        input = getch();
        if (input == ENTER || input == TAB) {
            password[i] = '\0';
            break;
        } else if (input == BCKSPC) {
            if (i > 0) {
                i--;
                printf("\b \b");
            }   
        } else {
            password[i++] = input;
            printf("* \b");
        }  
    }
    printf("\n");
}

char generateUsername(char email[50], char username[50])
{
    for (int i = 0; i < strlen(email); i++) {
        if (email[i] == '@')
            break;
        else 
            username[i] = email[i];
    }
}

int loginPembeli()
{
    int opt;
    bool user_found;
    char confirm_password[50];
    struct User user;
    FILE *file_password;

    printf("Choose Your Option: \n");
    printf("1. Sign Up\n");
    printf("2. Login\n");
    printf("3. exit\n");
    printf("Your Choice: ");
    scanf("%d", &opt);
    fgetc(stdin);

    switch (opt) {
    case 1:
        printf("Enter Your Fullname: ");
        takeInput(user.name);
        printf("Enter Your Email: ");
        takeInput(user.email);
        printf("Enter Your gender: ");
        takeInput(user.gender);
        printf("Enter Your Address: ");
        takeInput(user.address);
        printf("Enter Your Password: ");
        takePassword(user.password);
        printf("Confirm Your Password: ");
        takePassword(confirm_password);

        if (strcmp(user.password, confirm_password) == 0) {
            generateUsername(user.email, user.username);

            file_password = fopen("User.dat", "a+");

            fwrite(&user, sizeof(user), 1, file_password);            
            if (fwrite != 0) 
                printf("\n\nUser Regitration succsess, Your username is %s", user.username);
            else
                printf("\nsomething went Wrong");

            fclose(file_password);
        } else {
            printf("\nYour password do not matched");
        }
        break;

    case 2:
        char username[50], password[50];
        struct User usr;
        int chances = 3;
        user_found = false;

        printf("\nEnter your username: ");
        takeInput(username);

        file_password = fopen("User.dat", "r");

        if (file_password == NULL) {
            printf("\nNo user database found!");
            break;
        }

        while (fread(&usr, sizeof(user), 1, file_password)) {
            if (strcmp(usr.username, username) == 0) {
                user_found = true;

                while (chances > 0) {
                    printf("\nEnter your Password (%d chances left): ", chances);
                    takePassword(password);

                    if (strcmp(usr.password, password) == 0) {
                        printf("\n\nLogin Successful!");
                        printf("\nWelcome %s", usr.username);
                        printf("\n|Full Name:\t  %s", usr.name);
                        printf("\n|Email:\t      %s", usr.email);
                        printf("\n|Username:\t  %s", usr.username);
                        printf("\n|Address:\t  %s\n", usr.address);
                        chances = -1;  
                        break;
                    } else {
                        printf("\nWrong password!");
                        chances--;
                    }
                }

                if (chances == 0) {
                    printf("\n\nYou have used all 3 attempts! Login Failed.\n");
                }

                break;
            }
        }

        if (!user_found) {
            printf("\nUser is not registered!");
        }

        fclose(file_password);
        break;

    default:
        printf("Exiting...\n");
        break;
    }

    return 0;
}