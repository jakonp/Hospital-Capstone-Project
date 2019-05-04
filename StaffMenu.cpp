//
//  StaffMenu.cpp
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
const int STAFF_SIZE = 50;

void StaffMenu()
{
    
    Staff staff[STAFF_SIZE];
    int staffCount = 0;
    //create array
    ifstream sFile;
    sFile.open("staff.txt");
    
    if (sFile.fail())
    {
        cout << "Error in opening the department file. ";
        system("pause");
    }
    else {
        
        string Type, FName, LName, sID, dID, month, day, year, gender, phone, email;
        
        while (getline(sFile, Type, ',')) {
            (getline(sFile, FName, ','));
            (getline(sFile, LName, ','));
            (getline(sFile, sID, ','));
            (getline(sFile, dID, ','));
            (getline(sFile, month, '/'));
            (getline(sFile, day, '/'));
            (getline(sFile, year, ','));
            (getline(sFile, gender, ','));
            (getline(sFile, phone, ','));
            (getline(sFile, email, '\n'));
            
            
            staff[staffCount].setstaffType(Type);
            staff[staffCount].setFName(FName);
            staff[staffCount].setLName(LName);
            staff[staffCount].setsID(sID);
            staff[staffCount].setdepartID(dID);
            staff[staffCount].setMonth(month);
            staff[staffCount].setDay(day);
            staff[staffCount].setYear(year);
            staff[staffCount].setGender(gender);
            staff[staffCount].setPhone(phone);
            staff[staffCount].setEmail(email);
            staffCount++;
        }
        sFile.close();
        //end
        
    
        cout << "-=-=-=- Staff Menu -=-=-=-" << endl;
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
                for (int i = 0; i < staffCount; i++)
                {
                    cout << staff[i].getstaffType() << " ";
                    cout << staff[i].getFName() << " ";
                    cout << staff[i].getLName() << " ";
                    cout << staff[i].getsID() << " ";
                    cout << staff[i].getdepartID() << " ";
                    cout << staff[i].getMonth() << "/";
                    cout << staff[i].getDay() << "/";
                    cout << staff[i].getYear() << " ";
                    cout << staff[i].getGender() << " ";
                    cout << staff[i].getPhone() << " ";
                    cout << staff[i].getEmail() << " ";
                    cout << endl;
                    
                    
                }
                StaffMenu();
            }
                break;
            case 2:
            {
                string Type, FName, LName, sID, dID, month, day, year, gender, phone, email;
                
                cin.ignore();
                cout << "Add a new Patient" << endl;
                cout << "Staff Type: ";
                getline(cin, Type);
                cout << "First Name: ";
                getline(cin, FName);
                cout << "Last Name: ";
                getline(cin, LName);
                cout << "Staff ID: ";
                getline(cin, sID);
                cout << "Department ID: ";
                getline(cin, sID);
                cout << "Birth Month: ";
                getline(cin, month);
                cout << "Birth Day: ";
                getline(cin, day);
                cout << "Year: ";
                getline(cin, year);
                cout << "Gender: ";
                getline(cin, gender);
                cout << "Phone: ";
                getline(cin, phone);
                cout << "Email: ";
                getline(cin, email);
                
                
                staff[staffCount].setstaffType(Type);
                staff[staffCount].setFName(FName);
                staff[staffCount].setLName(LName);
                staff[staffCount].setsID(sID);
                staff[staffCount].setdepartID(dID);
                staff[staffCount].setMonth(month);
                staff[staffCount].setDay(day);
                staff[staffCount].setYear(year);
                staff[staffCount].setGender(gender);
                staff[staffCount].setPhone(phone);
                staff[staffCount].setEmail(email);
                staffCount++;
                
                ofstream pout;
                pout.open("staff.txt", fstream::app);
                pout << endl << Type << "," << FName << "," << LName << "," << sID << "," << dID << "," << month << "/" << day << "/" << year << "," << gender << "," << phone << "," << email;
                pout.close();
                StaffMenu();
            }
                break;
            case 3:
            {
                string staffsearch;
                bool found;
                
                cout << "Enter the Staff ID to search: " << endl;
                cin >> staffsearch;
                
                found = false;
                for (int i = 0; i < staffCount; i++) {
                    string pIDCom = staff[i].getsID();
                    
                    if (staff[i].getsID() == staffsearch) {
                        
                        found = true;
                        cout << endl << "Staff found!" << endl
                        << "Printing Staff information"
                        << endl << "--------------------------" << endl;
                        staff[i].printInfo();
                        break;
                    }
                }
                if (!found) {
                    cout << "Staff " << staffsearch << " not Found!";
                }
                StaffMenu();
            }
                break;
            case 4: {MainMenu();}
                break;
            default: {Staff();}
                break;
        }
        
        
    }
}

