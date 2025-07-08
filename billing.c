// billing.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "billing.h"
#include "patient.h"
#include "doctor.h"
#include "login.h"

#define FILE_NAME "bills.dat"

void billingMenu() {
    int choice;
    do {
        printf("\n--- Billing System ---\n");
        printf("1. Generate Bill\n");
        printf("2. View All Bills\n");
        printf("3. Back to Main Menu\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: generateBill(); break;
            case 2: viewBills(); break;
            case 3: return;
            default: printf("Invalid choice!\n");
        }
    } while (choice != 3);
}

void generateBill() {
    FILE *fp = fopen(FILE_NAME, "ab");
    struct Bill b;

    printf("Enter Patient ID: ");
    scanf("%d", &b.patientId);
    printf("Enter Patient Name: ");
    scanf(" %[^\n]", b.patientName);
    printf("Enter Doctor Fee: ");
    scanf("%f", &b.doctorFee);
    printf("Enter Medicine Charges: ");
    scanf("%f", &b.medicineCharges);
    printf("Enter Room Charges: ");
    scanf("%f", &b.roomCharges);

    b.total = b.doctorFee + b.medicineCharges + b.roomCharges;

    fwrite(&b, sizeof(struct Bill), 1, fp);
    fclose(fp);
    printf("Bill generated successfully! Total: ₹%.2f\n", b.total);
}

void viewBills() {
    FILE *fp = fopen(FILE_NAME, "rb");
    struct Bill b;

    printf("\n--- Bill Records ---\n");
    while (fread(&b, sizeof(struct Bill), 1, fp)) {
        printf("Patient ID: %d | Name: %s\n", b.patientId, b.patientName);
        printf("Doctor Fee: ₹%.2f | Medicine: ₹%.2f | Room: ₹%.2f | Total: ₹%.2f\n\n",
               b.doctorFee, b.medicineCharges, b.roomCharges, b.total);
    }
    fclose(fp);
}