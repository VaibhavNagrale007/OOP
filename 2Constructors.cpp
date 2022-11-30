#include<bits/stdc++.h>
using namespace std;

class Employee {
public:
    int id;
    string name;
    void intro(){                                       // functions in a class are called methods
        cout <<"ID : "<< id << endl;
        cout <<"Name : "<< name << endl;
    }
    Employee (int Id, string Name){
        id = Id;
        name = Name;

    }
};

int main(){
    Employee employee1 = Employee(12345, "Sam Rojers"); // constructor gets called automatically when
    employee1.intro();                                  // we create the object of the class
}

/*
===== * Theory * =====
1. Constructors
    In class-based, object-oriented programming, a constructor (abbreviation: ctor) is a special 
    type of subroutine called to create an object. It prepares the new object for use, often accepting arguments 
    that the constructor uses to set required member variables.
2. Types : 1. Default           : constructor which doesn’t take any argument. It has no parameters. It is also called a zero-argument constructor. 
           2. Paramatrised      : constructor with arguments
           3. Copy constructors : A copy constructor is a member function that initializes an object using another object of the same class
*/