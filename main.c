#include <stdio.h>
#include <stdlib.h>
#include "patient.h"
#include "doctor.h"
#include "billing.h"
#include "login.h"

void showMenu() {
    int choice;
    do {
        printf("\n--- Hospital Management System ---\n");
        printf("1. Patient Management\n");
        printf("2. Doctor Management\n");
        printf("3. Billing System\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: patientMenu(); break;
            case 2: doctorMenu(); break;
            case 3: billingMenu(); break;
            case 4: printf("Exiting...\n"); break;
            default: printf("Invalid choice!\n");
        }
    } while (choice != 4);
}

int main() {
    if (login()) {
        showMenu();
    } else {
        printf("Login failed.\n");
    }
    return 0;
}