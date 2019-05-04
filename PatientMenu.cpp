//
//  PatientMenu.cpp
//  CapStone
//
//  Created by Nick Jakobczyk on 4/22/19.
//  Copyright © 2019 Nick Jakobczyk. All rights reserved.
//

#include <iostream>
#include <string>
#include "Classes.h"
#include <stdlib.h>
#include <ncurses.h>
#include <fstream>

using namespace std;

void MainMenu();
void DepartmentMenu();
void StaffMenu();
void PatientMenu();
const int PATIENT_SIZE = 50;

void PatientMenu()
{
    
    Patient patients[PATIENT_SIZE];
    int patientCount = 0;
    //create array
    ifstream pFile;
    pFile.open("patients.txt");
    
    if (pFile.fail())
    {
        cout << "Error in opening the department file. ";
        system("pause");
    }
    else {
        
        string FName, LName, Dob, gender, no, street, city, state, zip, phone, email;;
        string month, day, year, pID, dID;
        
        while (getline(pFile, FName, ',')) {
            (getline(pFile, LName, ','));
            (getline(pFile, pID, ','));
            (getline(pFile, dID, ','));
            (getline(pFile, month, '/'));
            (getline(pFile, day, '/'));
            (getline(pFile, year, ','));
            (getline(pFile, gender, ','));
            (getline(pFile, no, ','));
            (getline(pFile, street, ','));
            (getline(pFile, city, ','));
            (getline(pFile, state, ','));
            (getline(pFile, zip, ','));
            (getline(pFile, phone, ','));
            getline(pFile, email, '\n');
            
            
            patients[patientCount].setFName(FName);
            patients[patientCount].setLName(LName);
            patients[patientCount].setpID(pID);
            patients[patientCount].setdID(dID);
            patients[patientCount].setMonth(month);
            patients[patientCount].setDay(day);
            patients[patientCount].setYear(year);
            patients[patientCount].setGender(gender);
            patients[patientCount].setPhone(phone);
            patients[patientCount].setEmail(email);
            patients[patientCount].setHomeAddress(no, street, city, state, zip);
            patientCount++;
        }
        pFile.close();
            //end
            
    cout << "-=-=-=- Patient Menu -=-=-=-" << endl;
    cout << "1. List All" << endl;
    cout << "2. Add One" << endl;
    cout << "3. Search One" << endl;
    cout << "4. Return to Main Menu" << endl;
    
    int choice;
    cin >> choice;
    
    switch (choice)
    {
        case 1:
        {
            cout << patientCount;
            for (int i = 0; i < patientCount; i++)
            {
                    cout << patients[i].getFName() << " ";
                    cout << patients[i].getLName() << " ";
                    cout << patients[i].getpID() << " ";
                    cout << patients[i].getdID() << " ";
                    cout << patients[i].getMonth() << "/";
                    cout << patients[i].getDay() << "/";
                    cout << patients[i].getYear() << " ";
                    cout << patients[i].getGender() << " ";
                    cout << patients[i].getPhone() << " ";
                    cout << patients[i].getEmail() << " ";
                    cout << endl;
                    
                    
                }
            PatientMenu();
            }
            break;
        case 2:
        {
            string FName, LName, Dob, gender, no, street, city, state, zip, Phone, Email;
            string month, day, year, pID, dID;
            cin.ignore();
            cout << "Add a new Patient" << endl;
            cout << "First Name: ";
            getline(cin, FName);
            cout << "Last Name: ";
            getline(cin, LName);
            cout << "Patient ID: ";
            getline(cin, pID);
            cout << "Doctor ID: ";
            getline(cin, dID);
            cout << "Birth Month: ";
            getline(cin, month);
            cout << "Birth Day: ";
            getline(cin, day);
            cout << "Birth Year: ";
            getline(cin, year);
            cout << "Sex: ";
            getline(cin, gender);
            cout << "Phone Number: ";
            getline(cin, Phone);
            cout << "Email Address: ";
            getline(cin, Email);
            cout << "House Number: ";
            getline(cin, no);
            cout << "Street Name: ";
            getline(cin, street);
            cout << "City: ";
            getline(cin, city);
            cout << "State: ";
            getline(cin, state);
            cout << "Zip Code: ";
            getline(cin, zip);
            
            
            patients[patientCount].setFName(FName);
            patients[patientCount].setLName(LName);
            patients[patientCount].setpID(pID);
            patients[patientCount].setdID(dID);
            patients[patientCount].setMonth(month);
            patients[patientCount].setDay(day);
            patients[patientCount].setYear(year);
            patients[patientCount].setGender(gender);
            patients[patientCount].setPhone(Phone);
            patients[patientCount].setEmail(Email);
            patients[patientCount].setHomeAddress(no, street, city, state, zip);
            patientCount++;
            
            ofstream pout;
            pout.open("patients.txt", fstream::app);
            pout << endl << FName << ", " << LName << ", " << pID << ", " << dID << ", " <<
            month << ", " << day << ", " << year << ", " << gender << ", " << Phone <<
            ", " << Email << ", " << no << ", " << street << ", " << city << ", " <<
            state << ", " << zip << endl;
            pout.close();
            PatientMenu();
        }
            break;
        case 3:
        {
            string patientSearch;
            bool found;
            
            cout << "Enter the Patient ID to search: " << endl;
            cin >> patientSearch;
            
            found = false; // the department is not found yet
            for (int i = 0; i < patientCount; i++) {
                string pIDCom = patients[i].getpID();
                
                if (patients[i].getpID() == patientSearch) {
                    
                    found = true;
                    cout << endl << "Patient found!" << endl
                    << "Printing patient information"
                    << endl << "--------------------------" << endl;
                    patients[i].printInfo();
                    break;
                }
            }
            if (!found) {
                cout << " Patient " << patientSearch << " not Found!";
            }
            
        }
            break;
        case 4: {MainMenu();}
            break;
        default: {PatientMenu();}
            break;
    }
    
    
}
    }

