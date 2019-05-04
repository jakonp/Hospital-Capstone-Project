//
//  DepartmentMenu.cpp
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

const int DEPART_SIZE = 50;


void DepartmentMenu()
{
    
    //Read Departments into Array
    ifstream dFile;
    int count = 0;
    Department departments[DEPART_SIZE];
    
    dFile.open("departments.txt");
    
    if (dFile.fail())
    {
        cout << "Error in opening the department file. ";
        system("pause");
    }
    else {
        
        string dName;
        string dID;
      
        while (getline(dFile, dName, ',')) {
            
            dFile >> dID;
            
            departments[count].DepName = dName;
            departments[count].DepID = dID;
            count++;
            
            
            dFile.ignore();
            
            
        }
        dFile.close();
        //Finish Reading into Array
        
        
       
        cout << "-=-=-=- Department Menu -=-=-=-" << endl;
        cout << "1. List All" << endl;
        cout << "2. Add One" << endl;
        cout << "3. Search One" << endl;
        cout << "4. Return to Main Menu" << endl;
        
        int choice;
        cin >> choice;
        
        switch (choice)
        {
            case 1: {
                cout << "Department Name\tID" << endl;
                for(int i = 0; i < count; i++)
                {
                    cout << departments[i].DepName << "\t" << departments[i].DepID << endl;
                }
                DepartmentMenu();
            }
                break;
            case 2: {
                
                ofstream AddDep("departments.txt");
                for(int i = 0; i < count; i++)
                {
                    AddDep << departments[i].DepName << "," << departments[i].DepID << endl;
                }
                string addDepname;
                int addDepID;
                cout << "Enter New Department Name: ";
                cin >> addDepname;
                /*
                 getline(cin, addDepname, '\n');
                 system("pause");
                 */
                //this bit of code did not work on XCode
                
                cout << "Enter New Department ID: ";
                cin >> addDepID;
                AddDep << addDepname << "," << addDepID << endl;
                AddDep.close();
                DepartmentMenu();
            }
                break;
            case 3: {
                string departSearch;
                bool found;
                
              
                cout << "Enter the Department ID to search: " << endl;
                cin >> departSearch;
                
                found = false;
                for (int i = 0; i < count; i++) {
                    if (departments[i].getdepartID() == departSearch) {
                        found = true;
                        cout << endl << "Department found!" << endl
                        << "Printing department information"
                        << endl << "--------------------------" << endl;
                        departments[i].printInfo();
                        break;
                    }
                }
            
                if (!found) {
                    cout << " department " << departSearch << " is NOT found!"
                    << endl << endl;
                }
                DepartmentMenu();
            }
                break;
            case 4: {MainMenu();}
                break;
            default: {DepartmentMenu();}
                break;
        }
        
        
    }
}
