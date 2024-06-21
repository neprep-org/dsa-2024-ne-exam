#include <iostream>
#include <string>

// include our defined headers
#include "patients/Patient.h"
#include "doctors/Doctor.h"
#include "appointments/Appointment.h"

using namespace std;


void menu() {

    // initializing linked lists we'll be using
    PatientLinkedList patientLinkedList;
    DoctorLinkedList doctorLinkedList;
    AppointmentLinkedList appointmentLinkedList;

    int choice;
    do {
        cout << "\nMenu:\n";
        cout << "1. Register a Patient\n";
        cout << "2. Register a Doctor\n";
        cout << "3. Register an appointment\n";
        cout << "4. Display Patients\n";
        cout << "5. Display Doctors\n";
        cout << "6. Display Appointments\n";
        cout << "7. Exit \n";

        // Get user's choice
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {

                int id;
                string name;
                string dob;
                string gender;

                cout << "\n\n" << "PATIENT REGISTRATION";
                cout <<           "\n--------------------\n\n";

                // request data and validate them
                ask_for_patient_id:
                cout << "ID: ";
                cin >> id;

                // Check if patient with given id already exist
                if (patientLinkedList.doesPatientExistById(id)) {
                    cout << "\nPatient with this id already exist";
                    cout << "\nTry different Id";
                    goto ask_for_patient_id;
                }

                cout << "\nNAME: ";
                cin >> name;
                cout << "\nDoB: ";
                cin >> dob;
                cout << "\nGENDER: ";
                cin >> gender;

                // create a patient with provided data
                Patient patient(id, name, dob, gender);

                // save patient to patient linkedlist
                patientLinkedList.addPatient(patient);
                break;
            }
            case 2: {
                int id;
                string name;
                string specialization;

                cout << "\n\n" << "DOCTOR REGISTRATION";
                cout <<           "\n-------------------\n\n";

                // request data
                ask_for_doctor_id:
                cout << "ID: ";
                cin >> id;

                // Check if patient with given id already exist
                if (doctorLinkedList.doesDoctorExistById(id)) {
                    cout << "\nDoctor with this id already exist";
                    cout << "\nTry different Id";
                    goto ask_for_doctor_id;
                }

                cout << "\nNAME: ";
                cin >> name;
                cout << "\nSPECIALIZATION: ";
                cin >> specialization;

                // create a doctor with provided data
                Doctor doctor(id, name, specialization);

                // save doctor to doctor linkedlist
                doctorLinkedList.addDoctor(doctor);
                break;
            }
            case 3: {
                int id;
                int patient_id;
                int doctor_id;

                string date;
                cout << "\n\n" << "APPOINTMENT REGISTRATION";
                cout <<           "\n------------------------\n\n";

                // request data and validate them
                ask_for_appointment_id:
                cout << "ID: ";
                cin >> id;

                if (appointmentLinkedList.doesAppointmentExistById(id)) {
                    cout << "\nAppointment with this id already exist";
                    cout << "\nTry different Id";
                    goto ask_for_appointment_id;
                }

                ask_for_patient_id_app:
                cout << "\nP_ID: ";
                cin >> patient_id;

                if (!patientLinkedList.doesPatientExistById(patient_id)) {
                    cout << "\nPatient with provided id doesn't exist";
                    cout << "\nTry different Id";
                    goto ask_for_patient_id_app;
                }

                ask_for_doctor_id_app:
                cout << "\nD_ID: ";
                cin >> doctor_id;

                if (!doctorLinkedList.doesDoctorExistById(doctor_id)) {
                    cout << "\nDoctor with provided id doesn't exist";
                    cout << "\nTry different Id";
                    goto ask_for_doctor_id_app;
                }

                cout << "\nDATE: ";
                cin >> date;

                // create an appointment with provided data
                Appointment appointment(id, patient_id, doctor_id, date);

                // save an appointment to appointment linkedlist
                appointmentLinkedList.addAppointment(appointment);
                break;
            }
            case 4: {
                patientLinkedList.displayPatients();
                break;
            }
            case 5: {
                doctorLinkedList.displayDoctors();
                break;
            }
            case 6: {
                appointmentLinkedList.displayAppointments();
                break;
            }
            case 7: {
                cout << "\nSaving session data & Exiting....";
                const string filename = R"(C:\Users\User\Documents\dsa-logs\data.csv)";
                patientLinkedList.saveToCSV(filename);
                doctorLinkedList.saveToCSV(filename);
                appointmentLinkedList.saveToCSV(filename);
                cout << "\nDone, bye!";
                break;
            }
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 7);
}

int main() {
    menu();
    return 0;
}
