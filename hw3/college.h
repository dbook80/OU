/******************************************************
    This is the header file for the container class 
    for Project 3
	Donovan Booker		Fall 2017
**********************************************************/
#include"node.h"
#include"course.h"
#include<iostream>
#include<fstream>
using namespace std;

class College{
    public:
        College(){head = NULL;}
        College(string fullname)
        {
            head = NULL;
            student_name = fullname;
        }
        //Big 3 functions
        ~College();
        College(const College& other);
        College& operator = (const College& other);
        
        void load(istream& fin);
        void add(course& c);
        void display();
        void remove(string coursename);
        double hours();
        double gpa();
        void save(ostream& fout);

    private:
        string student_name;
        node* head;
};
