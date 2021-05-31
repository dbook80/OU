// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
//
//   program:     Homework 5
//
//   Name  :      Donovan Booker
//
//   Description: This program is designed to report the speeds of cars to determine
//
//   if the police need to crack down on speeders down Main Street.
//
//   Date  :   March 17, 2017
//
// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

#include<iostream>
#include<fstream>
#include<cstdlib>
#include<iomanip>
#include<string>
using namespace std;

void get_filestreams(ifstream& in_stream, ofstream& out_stream);

void report(ifstream& in_stream, ofstream& out_stream, string month, string day);


int main ()
{
	ifstream in_stream;
	ofstream out_stream;
	string day;
	string month;
	cout<< "Enter in name of current month and day\n";
	cin>> month >> day;
	get_filestreams(in_stream, out_stream);
	report(in_stream, out_stream, month, day);
}

void get_filestreams(ifstream& in_stream, ofstream& out_stream)
{
	string file_name, file_name2;
	cout<<"Enter in the two file names\n";
	cin>> file_name >> file_name2;
	in_stream.open(file_name.c_str());
	out_stream.open(file_name2.c_str());
}

void report(ifstream& in_stream, ofstream& out_stream, string month, string day)
{
	double speeds = 0.00;
	double speeders = 0.00;
	double extreme_speeder_percent = 0.00;
	double extremespeeders = 0.00;
	double totalcars = 0.00;
	double sum = 0.00;
	double speeder_percentage;
	double avgspeed;
	double highspeed = 55.00;

	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(1);

	while(in_stream >> speeds)
	{
		if(speeds > 55.00)
		{
			if(speeds > highspeed)
			{
				highspeed = speeds;
			}
			extremespeeders ++;
		}
		if(speeds > 35)
		{
			sum += speeds;
			speeders++;
		}
		totalcars++;
	}

	speeder_percentage = speeders/totalcars;
	avgspeed = sum/speeders;
	speeder_percentage *= 100;
	extreme_speeder_percent = extremespeeders / speeders*100;

	out_stream << "Report for " << month << " " << day << endl;
	out_stream << speeders << " cars were speeding " << endl;
	out_stream << "This is " << speeder_percentage << "%" << " of all cars driving on Main Street" << endl;
	out_stream << "The average speed of these was " << avgspeed << " mph" << endl;
	out_stream << extremespeeders << " or " << extreme_speeder_percent << "%" << " of the speeders were in excess of 55 mph" << endl;
	out_stream << "The highest speed recorded was " << highspeed << " mph" << endl;

	in_stream.close();
	out_stream.close();
}
