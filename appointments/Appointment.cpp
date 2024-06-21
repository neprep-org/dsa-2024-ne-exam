//
// Created by pacifiquem on 20/06/2024.
//

#include <iostream>
#include <fstream>
#include "Appointment.h"

// Constructor of Appointment class
Appointment:: Appointment(int id, int patient_id, int doctor_id, std::string date) : id(id), patient_id(patient_id), doctor_id(doctor_id), date(date) {}

// Constructor of AppointmentNode class
AppointmentNode:: AppointmentNode(Appointment appointment) : appointment(appointment), next(nullptr) {}

// Constructor of AppointmentLinkedList class
AppointmentLinkedList::AppointmentLinkedList() : head(nullptr) {}

// Method to add a new appointment to linked list
void AppointmentLinkedList::addAppointment(Appointment appointment) {
    AppointmentNode* newNode = new AppointmentNode(appointment);
    if (!head) {
        head = newNode;
    } else {
        AppointmentNode* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Method to display appointments
void AppointmentLinkedList::displayAppointments() {
    AppointmentNode* temp = head;
    while (temp) {
        std::cout << "\nAppointment ID: " << temp->appointment.id << ", Patient ID: " << temp->appointment.patient_id <<" , Doctor ID: " << temp->appointment.doctor_id << " , Date: " << temp->appointment.date;
        std::cout << std::endl;
        temp = temp->next;
    }
}

// Method to check whether a given id is already taken in appointment linked list
bool AppointmentLinkedList::doesAppointmentExistById(int id) {
    AppointmentNode* temp = head;
    while (temp) {
        if (temp->appointment.id == id) {
            return true;
        }
        temp = temp->next;
    }
    return false; // Didn't find an appointment with given ID, return false;
}


void AppointmentLinkedList::saveToCSV(const std::string &filename) {
    std::ofstream file(filename);
    if (file.is_open()) {
        file << "Appointments Data" << std::endl;
        AppointmentNode* temp = head;
        while (temp) {
            file << temp->appointment.id << "," << temp->appointment.patient_id << "," << temp->appointment.doctor_id << "," << temp->appointment.date;
            file << std::endl;
            temp = temp->next;
        }
        file.close();
    } else {
        std::cout << "Unable to open file";
    }
}