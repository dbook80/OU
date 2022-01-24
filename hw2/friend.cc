/************************************************
   This is the implementation file for a class called Friend.
   It holds the information about a single Facebook
   friend, just their name and birthday. It uses a class
   called Date for the storage of the birthday. The member 
   functions are just accessors and input/output functions.
       Donovan Booker	Fall 2017	Ohio University
***********************************************************/

#include<iostream>
#include "friend.h"

Friend::Friend(std::string person, Date date)
{
    name = person;
    bday = date;
}
std::string Friend::get_name()const
{
    return name;
}
Date Friend::get_bday()const
{
    return bday;
}
bool Friend::operator == (const Friend& other)const
{
    return name == other.get_name() && bday == other.get_bday();
}
bool Friend::operator != (const Friend& other)const
{
    return name != other.get_name() || bday != other.get_bday();
}
void Friend::input(std::istream& ins)
{
    if(&ins == &std::cin)
    {
        ins >> name >> bday;
    }
    else
    {
        getline(ins, name);
        ins >> bday;
    }
    
}
void Friend::output(std::ostream& outs)const
{
    if(&outs == &std::cout)
    {
        outs << name << " " << bday << std::endl;
    }
    else
    {
        outs << name;
        outs << bday;
    }
}
std::istream& operator >>(std::istream& ins,Friend& f)
{
    f.input(ins);
    return ins;
}
std::ostream& operator <<(std::ostream& outs,const Friend& f)
{
    f.output(outs);
    return outs;
}
