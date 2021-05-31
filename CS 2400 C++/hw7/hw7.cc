// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
//
//   program:     Homework 7
//
//   Name  :      Donovan Booker
//
//   Description: This program is designed to compute fuel efficeincy using classes
//
//   and functions.
//
//   Date  :   April 16, 2017
//
// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

#include<iostream>
using namespace std;


class Odometer
{
	public:
		Odometer(double miles, double gallons);
		Odometer();
		double get_miles();
		double get_gallons();
		void add_in_trip_miles();
		void add_gas();
		double mpg();
		void reset();

	private:
		double miles;//miles driven
		double gallons;//gallons of gas in the car
};

int main()
{
	Odometer obj;
	char ans;

	cout<<"Enter in letter m to see total miles\n";
	cout<<"Enter in letter g to see total gallons\n";
	cout<<"Enter in letter d to record more miles driven\n";
	cout<<"Enter in letter p to record gallons pumped in the tank\n";
	cout<<"Enter in letter a to see the average mpg the car has received\n";
	cout<<"Enter in letter r to reset the odometer\n";
	cout<<"Enter in letter q to quit\n";
	cin>> ans;

	while(ans != 'q')
	{
		if(ans == 'm')
		{
			cout<<"Total mile count = "<< obj.get_miles() << endl;
		}
		else if(ans == 'g')
		{
			cout<<"Total amount of gallons in tank = "<< obj.get_gallons() << endl;
		}
		else if(ans == 'd')
		{
			obj.add_in_trip_miles();
		}
		else if(ans == 'p')
		{
			obj.add_gas();
		}
		else if(ans == 'a')
		{
			cout<<"The average mpg is "<< obj.mpg() << endl;
		}
		else if(ans == 'r')
		{
			obj.reset();
		}
		else
		{
			cout<<"Invalid entry\n";
		}
		cout<<"Enter in letter m to see total miles\n";
        	cout<<"Enter in letter g to see total gallons\n";
        	cout<<"Enter in letter d to record more miles driven\n";
        	cout<<"Enter in letter p to record gallons pumped in the tank\n";
        	cout<<"Enter in letter a to see the average mpg the car has received\n";
        	cout<<"Enter in letter r to reset the odometer\n";
        	cout<<"Enter in letter q to quit\n";
        	cin>> ans;
	}
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);
	cout<<"The total mpg is "<< obj.mpg() << endl;
}
Odometer::Odometer(double miles, double gallons)
{
	cin>> miles;
	cin>> gallons;
}
Odometer::Odometer()
{
	miles = 0;
	gallons = 0;
}
double Odometer::get_miles()
{
	return miles;
}
double Odometer::get_gallons()
{
	return gallons;
}
void Odometer::add_in_trip_miles()
{
	double x;
	cin >> x;
	miles += x;
}
void Odometer::add_gas()
{
	double y;
	cin >> y;
	gallons += y;
}
double Odometer::mpg()
{
	return miles / gallons;
}
void Odometer::reset()
{
	miles = 0;
	gallons = 0;
}
