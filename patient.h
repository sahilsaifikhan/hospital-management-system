// include/patient.h

#ifndef PATIENT_H
#define PATIENT_H

struct Patient {
    int id;
    char name[50];
    int age;
    char disease[50];
};

void patientMenu();
void addPatient();
void viewPatients();
void searchPatient();
void deletePatient();

#endif