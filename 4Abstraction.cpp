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
    string name;
public:
    void intro(){
        cout <<"ID : "<< id << endl;
        cout <<"Name : "<< name << endl;
    }
    Employee (int Id, string Name){
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

int main(){
    Employee employee1 = Employee(12345, "Sam Rojers");
    Employee employee2 = Employee(23456, "Adam Ross");
    employee1.AskForPromotion();
    employee2.AskForPromotion();
}

/*
===== * Theory * =====
1. Abstraction
    Abstraction means displaying only essential information and hiding the details. 
    Data abstraction refers to providing only essential information about the data 
    to the outside world, hiding the background details or implementation.
    eg. man driving a car has noting to do with how engine works he just uses it
    Implementation :    1. Abstraction using Classes
                        2. Abstraction using Header files
2. Virtual functions
    It tells the compiler to perform late binding where the compiler matches the object with the right called function and executes it during the runtime.
    declared in the base class using the keyword virtual and is re-defined (Overriden) in the derived class.
        Base Class    : class from which the other classes are derived and inherit the methods and properties (Parent/Super class) 
        Derived Class : class that is constructed from a base class and has all qualities of base class plus it's own someting new (Child/Sub class)
3. Pure Virtual function/Abstract Class
    Abstrat Class         : Sometimes implementation of all function cannot be provided in a base class because we don’t know the implementation. 
                            Such a class is called abstract class. As here we used AskForPromotion (Abstraction).
    Pure Virtual Function : A pure virtual function (or abstract function) in C++ is a virtual function for which we can have implementation, 
                            but we must override that function in the derived class, otherwise the derived class will also become abstract class
                            A pure virtual function is declared by assigning 0 in declaration
*/