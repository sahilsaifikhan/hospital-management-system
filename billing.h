// include/billing.h

#ifndef BILLING_H
#define BILLING_H

struct Bill {
    int patientId;
    char patientName[50];
    float doctorFee;
    float medicineCharges;
    float roomCharges;
    float total;
};

void billingMenu();
void generateBill();
void viewBills();

#endif