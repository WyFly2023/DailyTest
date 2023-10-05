cmake_minimum_required(VERSION 3.26)
project(AddressBook C)

set(CMAKE_C_STANDARD 99)

add_executable(AddressBook ContactTest.c
        Contacts.c
        Contacts.h)
