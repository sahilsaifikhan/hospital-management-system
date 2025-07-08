// include/doctor.h

#ifndef DOCTOR_H
#define DOCTOR_H

struct Doctor {
    int id;
    char name[50];
    char specialty[50];
};

void doctorMenu();
void addDoctor();
void viewDoctors();

#endif