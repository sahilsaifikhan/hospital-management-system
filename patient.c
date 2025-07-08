// patient.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "patient.h"
#include "billing.h"

#include "doctor.h"
#include "login.h"

#define FILE_NAME "patients.dat"

void patientMenu() {
    int choice;
    do {
        printf("\n--- Patient Management ---\n");
        printf("1. Add Patient\n");
        printf("2. View All Patients\n");
        printf("3. Search Patient by ID\n");
        printf("4. Delete Patient by ID\n");
        printf("5. Back to Main Menu\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addPatient(); break;
            case 2: viewPatients(); break;
            case 3: searchPatient(); break;
            case 4: deletePatient(); break;
            case 5: return;
            default: printf("Invalid choice!\n");
        }
    } while (choice != 5);
}

void addPatient() {
    FILE *fp = fopen(FILE_NAME, "ab");
    struct Patient p;

    printf("Enter Patient ID: ");
    scanf("%d", &p.id);
    printf("Enter Name: ");
    scanf(" %[^\n]", p.name);
    printf("Enter Age: ");
    scanf("%d", &p.age);
    printf("Enter Disease: ");
    scanf(" %[^\n]", p.disease);

    fwrite(&p, sizeof(struct Patient), 1, fp);
    fclose(fp);
    printf("Patient added successfully!\n");
}

void viewPatients() {
    FILE *fp = fopen(FILE_NAME, "rb");
    struct Patient p;
    printf("\n--- Patient List ---\n");
    while (fread(&p, sizeof(struct Patient), 1, fp)) {
        printf("ID: %d | Name: %s | Age: %d | Disease: %s\n", p.id, p.name, p.age, p.disease);
    }
    fclose(fp);
}

void searchPatient() {
    FILE *fp = fopen(FILE_NAME, "rb");
    struct Patient p;
    int id, found = 0;
    printf("Enter Patient ID to search: ");
    scanf("%d", &id);
    while (fread(&p, sizeof(struct Patient), 1, fp)) {
        if (p.id == id) {
            printf("ID: %d | Name: %s | Age: %d | Disease: %s\n", p.id, p.name, p.age, p.disease);
            found = 1;
            break;
        }
    }
    if (!found) printf("Patient not found.\n");
    fclose(fp);
}

void deletePatient() {
    FILE *fp = fopen(FILE_NAME, "rb");
    FILE *temp = fopen("data/temp.dat", "wb");
    struct Patient p;
    int id, found = 0;

    printf("Enter Patient ID to delete: ");
    scanf("%d", &id);

    while (fread(&p, sizeof(struct Patient), 1, fp)) {
        if (p.id != id) {
            fwrite(&p, sizeof(struct Patient), 1, temp);
        } else {
            found = 1;
        }
    }

    fclose(fp);
    fclose(temp);

    remove(FILE_NAME);
    rename("data/temp.dat", FILE_NAME);

    if (found)
        printf("Patient deleted successfully.\n");
    else
        printf("Patient not found.\n");
}