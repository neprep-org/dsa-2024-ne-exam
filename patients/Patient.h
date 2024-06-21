//
// Created by pacifiquem on 20/06/2024.
//

#ifndef DSA_PATIENT_H
#define DSA_PATIENT_H


#include <string>

// Patients class
class Patient {
public:
    int id;
    std::string name;
    std::string dob;
    std::string gender;
    Patient(int id, std::string name, std::string dob, std::string gender);
};

// Node class for patients linked list
class PatientNode {
public:
    Patient patient;
    PatientNode* next;
    PatientNode(Patient patient);
};

// Linkedlist for patients
class PatientLinkedList {
public:
    PatientNode* head;
    PatientLinkedList();
    void addPatient(Patient patient);
    void displayPatients();
    bool doesPatientExistById(int id);
    void saveToCSV(const std::string& filename);
};

#endif //DSA_PATIENT_H
