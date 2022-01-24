/******************************************************
    This is the implementation file for the container
     class for Project 3
	Donovan Booker		Fall 2017
**********************************************************/
#include"college.h"
#include<iostream>
#include<fstream>
using namespace std;
//Big 3 functions
College::~College()
{
    node * rmptr;
    while(head == NULL)
    {
        rmptr = head;
        head = head -> link();
        delete rmptr;
    }
}
College::College(const College& other)
{
    if(other.head == NULL)
    {
        head = NULL;
    }
    else
    {
        const node * sptr;
        node *dptr;
        head = new node;
        head -> set_data(other.head -> data());
        head -> set_link(NULL);
        dptr = head;
        sptr = other.head -> link();
        while(sptr != NULL)
        {
            dptr-> set_link(new node(sptr -> data()));
            dptr = dptr->link();
            sptr = sptr-> link();
        }
    }
}
College& College::operator = (const College& other)
{
    if(this == &other)
    {
        return *this;
    }
    node * rmptr;
    while(head != NULL)
    {
        rmptr = head;
        head = head->link();
        delete rmptr;
    }
    if(other.head != NULL)
    {
        head = new node(other.head->data());
    }
    if(other.head == NULL)
    {
        head = NULL;
    }
    else
    {
        const node * sptr;
        node *dptr;
        head = new node;
        head -> set_data(other.head -> data());
        head -> set_link(NULL);
        dptr = head;
        sptr = other.head -> link();
        while(sptr != NULL)
        {
            dptr-> set_link(new node(sptr -> data()));
            dptr = dptr->link();
            sptr = sptr-> link();
        }
    }
    return *this;
}
void College::load(istream& fin)
{
    string coursenum, grade;
    double hours;
    course tmp;
    while(fin.peek()=='\n')fin.ignore();
    fin >> coursenum >> grade >> hours;
    tmp.set_course(coursenum, grade, hours);
    head = new node;
    head -> set_data(tmp);
    node * temp = head;
    while(!fin.eof())
    {
        fin >> coursenum >> grade >> hours;
        tmp.set_course(coursenum, grade, hours);
        temp -> set_link(new node);
        temp = temp -> link();
        temp -> set_data(tmp);
        temp -> set_link(NULL);
        fin >> coursenum >> grade >> hours;
    }
}
void College::add(course& c)
{
    if(head == NULL)
    {
        head = new node;
        head -> set_data(c);
        head-> set_link(NULL);
        return;
    }
    else if(head -> data().get_course_number() > c.get_course_number())
    {
        node* cursor = new node(c, head);
        head = cursor;
        return;
    }
    node* tmp = head;
    node* tmp2 = tmp->link();
    while(tmp2 != NULL)
    {
        if(tmp2 -> data().get_course_number() > c.get_course_number())
        {
            tmp2 = tmp2->link();
            node* cursor = new node(c, tmp2);
            tmp->set_link(cursor);
            break;
        }
        tmp = tmp2;
    }
    tmp2 = new node(c);
    tmp->set_link(tmp2);
    /*else
    {
        node * tmp;
        tmp = head;
        while(tmp->link() != NULL)
        {
           tmp = tmp->link(); 
        }
        tmp->set_link(new node);
        tmp = tmp->link();
        tmp->set_data(c);
        tmp->set_link(NULL);
    }*/
    
}
void College::display()
{
    node * cursor = head;
    while(cursor != NULL)
    {
        cout << cursor->data() << endl;
        cursor = cursor->link();
    }
}
void College::remove(string coursename)
{
    node * cursor, * previous;
    if(head == NULL)return;
    else if(head->data().get_course_number() == coursename)
    {
        cursor = head;
        head = head->link();
        delete cursor;
    }
    else
    {
        cursor = head;
        while(cursor != NULL && cursor->data().get_course_number() != coursename)
        {
            previous = cursor;
            cursor = cursor->link();
        }
        if(cursor != NULL)
        {
            previous->set_link(cursor -> link());
            delete cursor;
        }
    }
}
double College::hours()
{
    double totalhrs = 0.0;
    node * cursor = head;
    while(cursor != NULL)
    {
        totalhrs += cursor->data().get_hours();
        cursor = cursor->link();
    }
    return totalhrs;
    cout<<endl;
}
double College::gpa()
{
    double points = 0.0;
    double totalhrs = 0.0;
    double gpa = 0.0;
    node * cursor = head;
    while(cursor != NULL)
    {
        totalhrs += cursor->data().get_hours();
        points += cursor->data().get_number_grade() * cursor->data().get_hours();
        gpa = points / totalhrs;
        cursor = cursor->link();
    }
    return gpa;
    cout<<endl;
}
void College::save(ostream& fout)
{
    node * cursor = head;
    while(cursor != NULL)
    {
        fout << cursor->data() << endl;
        cursor = cursor->link();
    }
}