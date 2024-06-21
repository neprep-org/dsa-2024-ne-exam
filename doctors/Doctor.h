//
// Created by pacifiquem on 20/06/2024.
//

#ifndef DSA_DOCTOR_H
#define DSA_DOCTOR_H


#include <string>

class Doctor {
public:
    int id;
    std::string name;
    std::string specialization;
    Doctor(int id, std::string name, std::string specialization);
};

// Node class for doctors linked list
class DoctorNode {
public:
    Doctor doctor;
    DoctorNode* next;
    DoctorNode(Doctor doctor);
};

// Linkedlist for doctor
class DoctorLinkedList {
public:
    DoctorNode* head;
    DoctorLinkedList();
    void addDoctor(Doctor doctor);
    void displayDoctors();
    bool doesDoctorExistById(int id);
    void saveToCSV(const std::string& filename);
};

#endif //DSA_DOCTOR_H
