// login.c

#include <stdio.h>
#include <string.h>
#include "login.h"
#include "billing.h"
#include "patient.h"
#include "doctor.h"


int login() {
    char username[20], password[20];
    char validUser[] = "admin";
    char validPass[] = "1234";

    printf("------ Login ------\n");
    printf("Username: ");
    scanf("%s", username);
    printf("Password: ");
    scanf("%s", password);

    if (strcmp(username, validUser) == 0 && strcmp(password, validPass) == 0) {
        printf("Login successful!\n");
        return 1;
    } else {
        printf("Invalid credentials.\n");
        return 0;
    }
}