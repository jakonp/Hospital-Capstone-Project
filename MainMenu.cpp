//
//  MainMenu.cpp
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

void MainMenu()
{
    system("clear"); //system clear does not work on mac or linux
    cout << "-=-=-=- Main Menu -=-=-=-" << endl;
    cout << "1. Department Menu" << endl;
    cout << "2. Staff Menu" << endl;
    cout << "3. Patient Menu" << endl;
    cout << "4. Exit" << endl;
    
    int choice;
    cin >> choice;
    
    switch (choice)//submenu choices
    {
        case 1: {DepartmentMenu();}
            break;
        case 2: {StaffMenu();}
            break;
        case 3: {PatientMenu();}
            break;
        case 4: {break;}
            break;
        default: {MainMenu();}//run main menu again if the choice isnt available
            break;
    }
    
    
}
