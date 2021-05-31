// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
//
//   program:     Homework 6
//
//   Name  :      Donovan Booker
//
//   Description: This program is designed to organize the retirement accounts at
//
//   Unlimited Software Limited to determine who's ready for retirement.
//
//   Date  :   April 4, 2017
//
// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

#include<iostream>
#include<fstream>
#include<cstdlib>
#include<string>
#include<cctype>
using namespace std;

int main()
{
	ifstream in_stream;
	ofstream out_stream;
	string file1, file2;
	string line;
	string name1, name2, name3, name4;
	string num1, num2, num3, num4;
	int pos, pos2, pos3, pos4, pos5;
	int totalamt = 0;
	int count = 0;

	cout<<"Enter in file names\n";//read in files
	cin>> file1 >> file2;

	in_stream.open("oldretirement.txt");//opening files
	out_stream.open(file2.c_str());

	if(in_stream.fail())
	{
		cout<<"Cannot open file\n";//check to make sure file opens 
		return -1;
	}

	while(!in_stream.eof())
	{
		getline(in_stream, line); //get each line of the input file

		for(int i = 0; i < line.size(); i++)
		{
			
			line.find(','); //find the first comma in each line

			if(isalpha(line[i] - 1))//if previous character is a letter, correct format
			{
				out_stream << line[i];
			}
			else //otherwise, reformat name using substrings
                        {
				pos = line.find(' ');
				name2 = line.substr(0, pos);
				pos2 = line.find(' ', pos);
				name3 = line.substr(pos, pos2-(pos));
				pos3 = line.find(' ', pos2 + 1);
				if(pos3 == string :: npos)
				{
					name4 = line.substr(pos2 + 1);
				}

				out_stream << name4 << name2 << name3;
			}
			if(isdigit(line[i] - 1) && isdigit(line[i] + 1)) 
			{
				pos4 = line.rfind(',');
				num1 = line.substr((pos4) - 3, pos4);//if there's a comma in the middle of the dollar amount
				num2 = line.substr(pos4, (pos4) + 3);//then make 2 substrings and mathematically combine them.
				atoi(num1.c_str());
				atoi(num2.c_str());
				num3 = num1 + "," + num2;
				pos5 = line.find('1');
				num4 = line.substr(pos5, (pos5) + 3);
				out_stream << num3;
			}
			else if(atoi(num4.c_str()) <= 1957 && atoi(num3.c_str()) >= 300000)
			{
				out_stream << line[i] + "Ready";//if the person is at least 60 years old and has contributed at
			}                                       //at least 300,000$ print out ready by their line
			else
			{
				out_stream << line[i];
   			}
   		
		out_stream << endl;
	}

	getline(in_stream, line);
	
	//if(line[i] == line[1] + "Ready")
	//{
		//count++;
		//out_stream << count << "amount of employees are ready for retirement\n";
	//}
	//totalamt += line[i];
	//out_stream<< totalamt << "is the total amount of employee contributions to the retirement fund;

	in_stream.close();
	out_stream.close();
	return 0;
}
}
