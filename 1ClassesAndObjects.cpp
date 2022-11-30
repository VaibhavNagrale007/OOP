#include<bits/stdc++.h>
using namespace std;

class Employee {                        // Employee is class
public:
    int id;                             // Class Variable
    string name;
    void intro(){                       // Methods
        cout <<"ID : "<< id << endl;
        cout <<"Name : "<< name << endl;
    }
};

int main(){
    Employee employee1;                 // employee1 is a object
    employee1.id=12345;
    employee1.name="Sam Rojers";
    employee1.intro();
}

/*
===== * Theory * =====
1. Class
    user-defined data type, which holds its own data members and member functions, which can be accessed and 
    used by creating an instance of that class. A class is like a blueprint for an object.
    eg. class Car, the data member will be speed, mileage etc and member functions can apply brakes, increase speed etc.
2. Object
    An Object is an identifiable entity with some characteristics and behaviour. An Object is an instance of a Class. 
    When a class is defined, no memory is allocated but when it is instantiated (i.e. an object is created) memory is allocated.
3. Access Modifiers
    1. Public    : All the class members declared under the public specifier will be available to everyone
    2. Private   : not allowed to be accessed directly by any object or function outside the class (except friend function)
    3. Protected : Similar to Private plus also can be accessed by derived/child class
        friend fuction : written friend.globalFunction or friend.anyClass (can also access private and protected)
Note :  Classes and Objects are stored in Heap
|=============================================================================================================================================================|
|            Instance variables	                                            |                Static (class) variables                                         |
|===========================================================================+=================================================================================|
|    Instance variables are declared in a class,                            | Class variables also known as static variables are declared with the            |
|    but outside a method, constructor or any block.	                    |    static keyword in a class, but outside a method, constructor or a block.     |
|                                                                           |                                                                                 |
|    Instance variables are created when an object is created with the      | Static variables are created when the program starts                            |
|    use of the keyword 'new' and destroyed when the object is destroyed.	|and destroyed when the program stops.                                            |
|                                                                           |                                                                                 |
|    Instance variables can be accessed directly by calling the variable    | Static variables can be accessed by calling with                                |
|    name inside the class. However, within static methods (when instance   | the class name ClassName.VariableName.                                          |
|    variables are given accessibility), they should be called using        |                                                                                 |
|    the fully qualified name. ObjectReference.VariableName.	            |                                                                                 |
|                                                                           |                                                                                 |
|    Instance variables hold values that must be referenced by more than    | There would only be one copy of each class variable per class,                  |
|    one method, constructor or block, or essential parts of an             |regardless of how many objects are created from it.                              |
|    object's state that must be present throughout the class.	            |                                                                                 |
|===========================================================================+=================================================================================|
*/