cmake_minimum_required(VERSION 3.28)
project(dsa)

set(CMAKE_CXX_STANDARD 17)

add_executable(dsa main.cpp
        patients/Patient.cpp
        patients/Patient.h
        doctors/Doctor.cpp
        doctors/Doctor.h
        appointments/Appointment.cpp
        appointments/Appointment.h
        utils/Validator.cpp
        utils/Validator.h
)
