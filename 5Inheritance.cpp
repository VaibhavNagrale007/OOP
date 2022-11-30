#include<bits/stdc++.h>
using namespace std;


class AbstractEmployee{                 // pure virtual funtion/Abstract class
    virtual void AskForPromotion()=0;   // rule that employee can do
};                                      // AbstractEmployee class has method AskForPromotion
                                        // Abstraction as we don't care how Promotion is implemented we can just ask for it
                                        // so it hides procedure for promotion (complex) and user has just to ask for it (simple)
                                        
class Employee:AbstractEmployee {       // Employee is inheriting form AbstractEmployee
private:                                // so Employee class is sining contract that he can ask for promotion
    int id;
protected:                              // can be accessed by derived/child class
    string name;
public:
    void intro(){
        cout <<"ID : "<< id << endl;
        cout <<"Name : "<< name << endl;
    }
    Employee (int Id, string Name){     // constructor
        id = Id;
        name = Name;
    }
    void setId(int Id){                 // setter method for id
        id = Id;
    }
    int getId(){                        // getter method for id
        return id;
    }
    void setName(string Name){
        name = Name;
    }
    string getName(){
        return name; // we can put if condition for lets say id validation then return if id is valid
    }
    void AskForPromotion(){
        if (id > 20000) cout << name <<" got promoted!"<< endl;
        else cout << name <<", sorry please try next time"<< endl;
    }
};

class Developer:public Employee{        // Developer became derived/child class using ":Employee" (by default private so cannot be accessed in main so make public)
public:
    string FavourateProgrammingLanguage;
    Developer(int Id, string Name, string favourateProgrammingLanguage)     // Job of this constructor is to construct Developer object
        : Employee(Id, Name)                                                // pass id and name to Employee constructor
    {                                                                       // (parameters must be same as Base class constructor plus our defined new parameters)
        FavourateProgrammingLanguage = favourateProgrammingLanguage;        // we don't have to worry about id and name as base class constructor does that
    }
    void FixBug(){
        cout << name <<", Id : "<< getId() <<", Favourate Language : "<< FavourateProgrammingLanguage << endl;
    }
};

class Teacher: public Employee{
public:                                                     // make public
    string subject;
    Teacher(int Id, string Name, string Subject)            // make constructor
        :Employee(Id, Name)
    {
        subject = Subject;
    }
    void Prepare(){                                            // just for printing
        cout << name <<", is preparing for "<< subject << endl;
    }
};

int main(){
    Developer d = Developer(12345, "Cathy Joe", "C++");
    Teacher t = Teacher(23456, "Bill Mathew", "Programming");
    t.Prepare();                                               // Developer and Teacher class is inherited form Employee class
    t.AskForPromotion();
}

/*
===== * Theory * =====
1. Inheritance
    The capability of a class to derive properties and characteristics from another class is called Inheritance
    eg. Car = (Petrol Car, Diesel Car, E Car, CNG Car) all these has same name, model, color, price, etc 
        but they are going to be different between them (inherited form base class plus properties of their own)
Note :  Every class has auto generated default constructors but once you decide to make your own constructor you loose your default constructors
        Rules for Constructors creation : 1. no return type 2. same name as the class 3. needs to be public
*/