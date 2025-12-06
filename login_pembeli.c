#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <conio.h>

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
 
void takeInput(char ch[50]){
    fgets(ch, 50, stdin);
    ch[strlen(ch) - 1] = 0;
}

void takePass(char pwd[50]){
    int i;
    char ch;
    while (1)
    {
        ch = getch();
        if (ch == ENTER || ch == TAB)
        {
            pwd[i] = '\0';
            break;
        }else if (ch == BCKSPC)
        {
            if (i > 0)
            {
                i--;
                printf("\b \b");
            }
            
        }else{
            pwd[i++] = ch;
            printf("* \b");
        }
        
        
    }
    
}

char generateUsername(char Email[50], char username[50]){
    for (int i = 0; i < strlen(Email); i++)
    {
        if (Email[i] == '@') break;
        else username[i] = Email[i];
        
    }
    
}

int loginPembeli()
{
    int opt, userFound = 0;
    char password2[50];
    struct User user;
    FILE *fp;
    printf("Choose Your Option: \n");
    printf("1. Sign Up\n");
    printf("2. Login\n");
    printf("3. exit\n");
    printf("Your Choice: ");
    scanf("%d", &opt);
    fgetc(stdin);


    switch (opt)
    {
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
        takePass(user.password);
        printf("\nconfirm Your Password: ");
        takePass(password2);

        if (!strcmp(user.password, password2))
        {
            generateUsername(user.email, user.username);
            fp = fopen("User.dat", "a+");
            fwrite(&user, sizeof(user), 1, fp);
                if (fwrite != 0)  printf("\n\nUser Regitration succsess, Your username is %s", user.username);
                else printf("\nsomething went Wrong");
                fclose(fp);

        }else{
            printf("\nYour password do not matched");
        }
        
        break;
case 2:
    char username[50], pword[50];
    struct User usr;
    int chances = 3;
    userFound = 0;

    printf("\nEnter your username: ");
    takeInput(username);

    fp = fopen("User.dat", "r");

    if (fp == NULL) {
        printf("\nNo user database found!");
        break;
    }

    while (fread(&usr, sizeof(user), 1, fp)) {
        if (!strcmp(usr.username, username)) {
            userFound = 1;

            while (chances > 0) {
                printf("\nEnter your Password (%d chances left): ", chances);
                takePass(pword);

                if (!strcmp(usr.password, pword)) {
                    printf("\n\nLogin Successful!");
                    printf("\nWelcome %s", usr.username);
                    printf("\n|Full Name:\t  %s", usr.name);
                    printf("\n|Email:\t      %s", usr.email);
                    printf("\n|Username:\t  %s", usr.username);
                    printf("\n|Address:\t  %s\n", usr.address);
                    chances = -1;  
                    break;
                } 
                else {
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

    if (!userFound) {
        printf("\nUser is not registered!");
    }

    fclose(fp);
    break;


    default:
        break;
    }

    return 0;
}