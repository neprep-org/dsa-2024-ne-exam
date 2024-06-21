//
// Created by pacifiquem on 20/06/2024.
//

#include <iostream>
#include <fstream>
#include "Doctor.h"

// Constructor of Doctor class
Doctor::Doctor(int id, std::string name, std::string specialization) : id(id), name(name), specialization(specialization) {}

// Constructor of DoctorNode class
DoctorNode::DoctorNode(Doctor doctor) : doctor(doctor), next(nullptr) {}

// Constructor of DoctorLinkedList class
DoctorLinkedList::DoctorLinkedList() : head(nullptr) {}

// Method to add a doctor to linked list
void DoctorLinkedList::addDoctor(Doctor doctor) {
    DoctorNode* newNode = new DoctorNode(doctor);
    if (!head) {
        head = newNode;
    } else {
        DoctorNode* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Method to display doctors
void DoctorLinkedList::displayDoctors() {
    DoctorNode* temp = head;
    while (temp) {
        std::cout << "\nDoctor ID: " << temp->doctor.id << ", Name: " << temp->doctor.name <<" , Specialization: " << temp->doctor.specialization;
        std::cout << std::endl;
        temp = temp->next;
    }
}

// Method to check whether a given id is already taken in doctors linked list
bool DoctorLinkedList::doesDoctorExistById(int id) {
    DoctorNode* temp = head;
    while (temp) {
        if (temp->doctor.id == id) {
            return true;
        }
        temp = temp->next;
    }
    return false; // Didn't find a doctor with given ID, return false;
}

// Method to save doctors' data to csv file
void DoctorLinkedList::saveToCSV(const std::string &filename) {
    std::ofstream file(filename);
    if (file.is_open()) {
        file << "Doctors Data" << std::endl;
        DoctorNode* temp = head;
        while (temp) {
            file << temp->doctor.id << "," << temp->doctor.name << temp->doctor.specialization;
            file << std::endl;
            temp = temp->next;
        }
        file.close();
    } else {
        std::cout << "Unable to open file";
    }
}
