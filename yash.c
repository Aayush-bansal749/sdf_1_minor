#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int choice;
    char password[100];

login_menu: // Label to jump back to the login menu if needed
    printf("Welcome to the login system.\n");
    printf("Please enter your choice:\n");
    printf("1. Admin Login\n");
    printf("2. Customer Login\n");

    scanf("%d", &choice);

switch_statement:
    switch (choice) {
        case 1:
            printf("Enter the admin password: ");
            scanf("%s", password);

            if (strcmp(password, "admin123") == 0) {
                printf("Admin login successful.\n");
                

            } else {
                printf("Wrong password. Please try again.\n");
                goto login_menu;
            }
            break;

        case 2:
            printf("Good choice! You are now logged in as a customer.\n");

            break;

        default:
            printf("Invalid choice. Please enter a valid option.\n");
            goto login_menu;
    }
}
