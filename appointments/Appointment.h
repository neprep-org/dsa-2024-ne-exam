//
// Created by pacifiquem on 20/06/2024.
//

#ifndef DSA_APPOINTMENT_H
#define DSA_APPOINTMENT_H

#include <string>

// Appointments class
class Appointment {
public:
    int id;
    int patient_id;
    int doctor_id;
    std::string date;
    Appointment(int id, int patient_id, int doctor_id, std::string date);
};

// Node class for appointments linked list
class AppointmentNode {
public:
    Appointment appointment;
    AppointmentNode* next;
    AppointmentNode(Appointment appointment);
};

// Linked list for appointments
class AppointmentLinkedList {
public:
    AppointmentNode* head;
    AppointmentLinkedList();
    void addAppointment(Appointment appointment);
    void displayAppointments();
    bool doesAppointmentExistById(int id);
    void saveToCSV(const std::string& filename);
};

#endif //DSA_APPOINTMENT_H
