//
// Created by pacifiquem on 20/06/2024.
//

#include <iostream>
#include <fstream>
#include "Patient.h"

// Constructor of Patient class
Patient::Patient(int id, std::string name, std::string dob, std::string gender) : id(id), name(name), dob(dob), gender(gender) {}

// Constructor of PatientNode class
PatientNode::PatientNode(Patient patient) : patient(patient), next(nullptr) {}

// Constructor of PatientLinkedList class
PatientLinkedList::PatientLinkedList() : head(nullptr) {}

// Method to add a new patient to linked list
void PatientLinkedList::addPatient(Patient patient) {

    // If no patient with given ID, create one.
    PatientNode* newNode = new PatientNode(patient);
    if (!head) {
        head = newNode;
    } else {
        PatientNode* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Method to display patients
void PatientLinkedList::displayPatients() {
    PatientNode* temp = head;
    while (temp) {
        std::cout << "\nPatient ID: " << temp->patient.id << ", Name: " << temp->patient.name <<" , DOB: " << temp->patient.dob <<", Gender: " << temp->patient.gender;
        std::cout << std::endl;
        temp = temp->next;
    }
}

// Method to check whether a given id is already taken in patients linked list
bool PatientLinkedList::doesPatientExistById(int id) {
    PatientNode* temp = head;
    while (temp) {
        if (temp->patient.id == id) {
            return true;
        }
        temp = temp->next;
    }

    return false; // Didn't find a patient with given ID, return false;
}

// Method to save patient's information to a csv file
void PatientLinkedList::saveToCSV(const std::string &filename) {
    std::ofstream file(filename);
    if (file.is_open()) {
        file << "Patients Data" << std::endl;
        PatientNode* temp = head;
        while (temp) {
            file << temp->patient.id << "," << temp->patient.name << temp->patient.dob << "," << temp->patient.gender;
            file << std::endl;
            temp = temp->next;
        }
        file.close();
    } else {
        std::cout << "Unable to open file";
    }
}
