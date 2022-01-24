//***********************************************
// This is the header file for the checkbook class
//
// Donovan Booker
//
// cs2401- hw1
//
// 14 September 2017
//***********************************************
#include<iostream>
#include<string>
#include<fstream>
#include "check.h"
using namespace std;

class Checkbook
{
public:
    static const size_t SIZE = 200;

    Checkbook(string owner);
    void load_from_file(istream& ifs);
    void deposit(double depamount);
    void write_check(istream& cin);
    double get_balance();
    string get_payto();
    void show_all(ostream& cout);
    void remove(int rmnum);
    void number_sort();
    void payto_sort();
    void date_sort();
    void show(string payto_find);
    double average();
    void save(ostream& ofs);
private:
    Check array[SIZE];
    size_t used;
    double balance;
    string user;
};