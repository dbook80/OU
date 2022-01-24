//***********************************************
// This is the implementation file for the checkbook class
//
// Donovan Booker
//
// cs2401- hw1
//
// 14 September 2017
//***********************************************
#include<iostream>
#include "check.h"
#include "checkbook.h"
using namespace std;

Checkbook::Checkbook(string owner)
{
    user = owner;
    balance = 0;
   used = 0;
}
void Checkbook::load_from_file(istream& ifs)
{
    ifs >> balance;
    while(!ifs.eof())
    {
      if(used >= SIZE)
      {
        break;
      }
      ifs >> array[used];
      if(ifs.eof()) break;
      used++;
    }       
    /*int i;
    do
    {
        ifs >> array[i];
        if(!ifs.eof())
        {
            i++;
        }
    } while(!ifs.eof());
         used = i;
    */
}
void Checkbook::deposit(double depamount)
{
    balance += depamount;
}
void Checkbook::write_check(istream& cin)
{
    array[used].write_check(cin);
    used++;
    balance -= array[used-1].get_amount();
}
double Checkbook::get_balance()
{
    return balance;
}
string Checkbook::get_payto()
{
    return "";
}
void Checkbook::show_all(ostream& cout)
{
    for(int i = 0; i < used; i++)
    {
        cout << array[i] << endl;
    }
}
void Checkbook::remove(int rmnum)
{
    int i;
    /*if(rmnum > used)
    {
        cout << "You cannot erase a check you've never written." << endl;
    }*/
    for(i = 0; i < used - 1; i++)
    {
        if(rmnum == array[i].get_num())
        {
            break;
        }
    }
    balance += array[i].get_amount();
    for(int j = i; j < used - 1; j++)
    {
        array[j] = array[j + 1];
    }
    used--;
}
void Checkbook::number_sort()
{
    Check tmp, tmp2;
    int i, j;
    for(i = 0; i < used; ++i)
    {
      for(j = 0; j < used - i - 1; ++j)
      {
        tmp = array[j];
        tmp2 = array[j+1];
        if(tmp.get_num() > tmp2.get_num())
        {
          array[j+1] = tmp;
          array[j] = tmp2;
        }
      }
    }
}
void Checkbook::payto_sort()
{
    Check tmp, tmp2;
    int i, j;
    for(i = 0; i < used; ++i)
    {
      for(j = 0; j < used - i - 1; ++j)
      {
        tmp = array[j];
        tmp2 = array[j+1];
        if(tmp.get_payto() > tmp2.get_payto())
        {
          array[j+1] = tmp;
          array[j] = tmp2;
        }
      }
    }
}
void Checkbook::date_sort()
{
    Check tmp, tmp2;
    int i, j;
    for(i = 0; i < used; ++i)
    {
      for(j = 0; j < used - i - 1; ++j)
      {
        tmp = array[j];
        tmp2 = array[j+1];
        if(tmp.get_date() > tmp2.get_date())
        {
          array[j+1] = tmp;
          array[j] = tmp2;
        }
      }
    }
}
void Checkbook::show(string payto_find)
{
    double totalamt = 0;
    for(int i = 0; i < used; i++)
    {
        if(array[i].get_payto() == payto_find)
        {
            cout << array[i] << endl;
            totalamt += array[i].get_amount();
        }

    }
    cout << "Total amount of the checks : " << totalamt << endl;
}
double Checkbook::average()
{
    return balance / used;
}
void Checkbook::save(ostream& ofs)
{
    ofs << balance << endl;
    for(int i = 0; i < used; ++i)
	{
		ofs<< array[i];
	}
}

