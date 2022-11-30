#include<bits/stdc++.h>
using namespace std;

class Employee {
private:
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
};

int main(){
    Employee employee1 = Employee(12345, "Sam Rojers");
    employee1.intro();
    Employee employee2 = Employee(23456, "Adam Ross");
    employee2.intro();
    employee1.setName("Ben Klein");
    cout <<"getName used : "<< employee1.getName() << endl;
    employee1.intro();
}

/*
===== * Theory * =====
1. Encapsulation
    Encapsulation is defined as wrapping up of data and information under a single unit. In Object-Oriented 
    Programming, Encapsulation is defined as binding together the data and the functions that manipulate them.
    eg. lets say in a company, employee and finance deapartment, now if employee needs finance all data then
        they cannot get it directly. They must go to finance and ask for data and then they will provide
        them what they feel is good.
    Encapsulation = Class[Methods, Variables]
*/