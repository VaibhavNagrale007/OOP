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
    virtual void Work(){                // here Work is showing polymorphic behaviour
        cout << name <<" is checking emails and work it has"<< endl;
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
    void Work(){
        cout << name <<" is writing code in "<< FavourateProgrammingLanguage <<" language"<< endl;
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
    void Prepare(){                                         // just for printing
        cout << name <<", is preparing for "<< subject << endl;
    }
    void Work(){
        cout << name <<" is teacing "<< subject <<" subject"<< endl;
    }
};

int main(){
    Developer d = Developer(12345, "Cathy Joe", "C++");
    Teacher t = Teacher(23456, "Bill Mathew", "Programming");
    // d.Work(); if called Work, then if Work in derived class, then print that else base class (while doing this Work in base class is not virtual)
    Employee* e1 = &d;                                      // base class pointer to a derived class object
    Employee* e2 = &t;
    e1->Work();                                             // e with virtual Work in base then prints derived class Work
    e2->Work();                                             // else if normal Work in base then always prints base class Work 
}

/*
===== * Theory * =====
1. Polymorphism
    The word polymorphism means having many forms or as the ability of a message to be displayed in more than one form.
    Types: 1. Operator overloading : making operator perform differently in different instances
           2. Function overloading : using single function name to perform different tasks
    eg. here we used virtual Work in base class, thus we did Function oveloading, if Work in derived class then perform that
        otherwise use base class Work (thus showing polymorphism)
2. Virtual function
    when a virtual function is invoked it says, hey if there is implementation of this 
    fuction in my derived classes if yes please execute that else execute which it has
*/