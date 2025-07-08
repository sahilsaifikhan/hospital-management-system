// doctor.c

#include <stdio.h>
#include <stdlib.h>
#include "doctor.h"
#include "billing.h"
#include "patient.h"

#include "login.h"

#define FILE_NAME "doctors.dat"

void doctorMenu() {
    int choice;
    do {
        printf("\n--- Doctor Management ---\n");
        printf("1. Add Doctor\n");
        printf("2. View All Doctors\n");
        printf("3. Back to Main Menu\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addDoctor(); break;
            case 2: viewDoctors(); break;
            case 3: return;
            default: printf("Invalid choice!\n");
        }
    } while (choice != 3);
}

void addDoctor() {
    FILE *fp = fopen(FILE_NAME, "ab");
    struct Doctor d;

    printf("Enter Doctor ID: ");
    scanf("%d", &d.id);
    printf("Enter Name: ");
    scanf(" %[^\n]", d.name);
    printf("Enter Specialty: ");
    scanf(" %[^\n]", d.specialty);

    fwrite(&d, sizeof(struct Doctor), 1, fp);
    fclose(fp);
    printf("Doctor added successfully!\n");
}

void viewDoctors() {
    FILE *fp = fopen(FILE_NAME, "rb");
    struct Doctor d;
    printf("\n--- Doctor List ---\n");
    while (fread(&d, sizeof(struct Doctor), 1, fp)) {
        printf("ID: %d | Name: %s | Specialty: %s\n", d.id, d.name, d.specialty);
    }
    fclose(fp);
}