//
//  Classes.h
//  Capstone2.0
//
//  Created by Nick Jakobczyk on 4/24/19.
//  Copyright © 2019 Nick Jakobczyk. All rights reserved.
//

#ifndef Header_h
#define Header_h

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Address
{
private:
    string no, zipCode, street, city, state;
public:
    Address(string houseNo = "none", string s = "s", string c = "c",
            string State = "state", string zip = "none")
    {
        no = houseNo;
        street = s;
        city = c;
        state = State;
        zipCode = zip;
    }
    
    string getNo() { return no; }
    string getStreet() { return street; }
    string getCity() { return city; }
    string getState() { return state; }
    string getZip() { return zipCode; }
    void setNo(string houseNo) { no = houseNo; }
    void setStreet(string s) { street = s; }
    void setCity(string c) { city = c; }
    void setState(string State) { state = State; }
    void setZip(string zip) { zipCode = zip; }
    void printAddress()
    {
        cout << "House Number: " << no << endl << " Street: " << street << endl <<
        " City: " << city << endl << " State: " << state << endl << " Zip Code: "
        << zipCode << endl;
    }
};

class Person {
    
private:
    string fName, lName, email, gender, phone, day, month, year;
public:
    Person(string first = "f", string last = "l",
           string m = "none", string d = "none", string y = "none",
           string p = "no", string e = "e", string g = "g") {
        fName = first;
        lName = last;
        month = m;
        day = d;
        year = y;
        phone = p;
        email = e;
        gender = g;
    }
    void setFName(string first) { fName = first; }
    void setLName(string last) { lName = last; }
    void setMonth(string m) { month = m; }
    void setDay(string d) { day = d; }
    void setYear(string y) { year = y; }
    void setPhone(string Phone) { phone = Phone; }
    void setEmail(string Email) { email = Email; }
    void setGender(string Gender) { gender = Gender; }
    
    string getFName() { return fName; }
    string getLName() { return lName; }
    string getMonth() { return month; }
    string getDay() { return day; }
    string getYear() { return year; }
    string getPhone() { return phone; }
    string getEmail() { return email; }
    string getGender() { return gender; }
    
    void printInfo() {
        cout << "First Name" << fName << endl <<
        "Last Name" << lName << endl
        << month << "/" << day << "/" << year
        << endl << gender << endl << phone << endl << email << endl;
    }
};
class Staff :public Person {
    
private:
    string staffType, staffId, departmentId;
public:
    Staff(string stype = "none", string first = "None", string last = "None",
          string sID = "none", string departID = "none", string m = "none",
          string d = "none", string y = "none", string p = "no", string e = "none", string g = "none")
    : Person(first, last, m, d, y, p, e, g)
    {
        staffType = stype;
        staffId = sID;
        departmentId = departID;
    }
    string getstaffType() { return staffType; }
    string getsID() { return staffId; }
    string getdepartID() { return departmentId; }
    void setstaffType(string stype) { staffType = stype; }
    void setsID(string sID) { staffId = sID; }
    void setdepartID(string departID) { departmentId = departID; }
    void printInfo()
    {
        Person::printInfo();
        cout << "Staff Type:" << staffType << endl
        << "Staff ID: " << staffId << endl
        << "Department ID: " << departmentId << endl;
    }
};

class Patient :public Person
{
private:
    string patientId, doctorId;
    Address home;    
public:
    Patient(string first = "None", string last = "None",
            string pID = "none", string dID = "string", string m = "none",
            string d = "none", string y = "none", string houseNo = "none", string s = "no", string c = "none",
            string State = "none", string zip = "none", string p = "no", string e = "none", string g = "none")
    : Person(first, last, m, d, y, p, e, g), home(houseNo, s, c, State, zip)
    {
        patientId = pID;
        doctorId = dID;
    }
    Address getHomeAddress() { return home; }
    
    void setHomeAddress(string houseNo, string s, string c, string State, string zip)
    {
        home.setNo(houseNo);
        home.setStreet(s);
        home.setCity(c);
        home.setState(State);
        home.setZip(zip);
    }
    string getpID() { return patientId; }
    string getdID() { return doctorId; }
    void setpID(string pID) { patientId = pID; }
    void setdID(string dID) { doctorId = dID; }
    void printInfo()
    {
        Person::printInfo();
        cout << "Patient ID: " << patientId << endl
        << "Doctor ID: " << doctorId << endl;
        home.printAddress();
    }
    
};



struct Department {
    string DepName;
    string DepID;
    void setdname(string dname) { DepName = dname; }
    string getdname() { return DepName; }
    void setdepartID(string departID) { DepID = departID; }
    string getdepartID() { return DepID; }
    void printInfo() {
        cout << DepName << "," << DepID << endl;
    }
    
};

#endif /* Header_h */
