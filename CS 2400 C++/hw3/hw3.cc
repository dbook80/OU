// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
//
//   program:     Homework 3
//
//   Name  :      Donovan Booker
//
//   Description: This program is designed to find a four digit
//   number tht satifies four conditions:
//
//   all four digits are different
//
//   the digit in the thousands place is three times as much as the tens place digit
//
//   The number is odd
//
//   The sum of the digits is 27
//
//   Date  :   February 20, 2017
//
// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

#include<iostream>
#include<cmath>
using namespace std;

int main()
{
	int num;
	int digit1;
	int digit2;
	int digit3;
	int digit4;
	int secret;
	num = 0;
	secret = 9837;

	digit1 = num / 1000;
	digit2 = (num / 100) % 10;
	digit3 = (num / 10) % 10;
	digit4 = num % 10;

	cout<<"Enter in a four digit number"<<endl;
	cin>>num;

	while( num >= 1000 && num < 10000)
	{

        	digit1 = num / 1000;
        	digit2 = (num / 100) % 10;
        	digit3 = (num / 10) % 10;
        	digit4 = num % 10;

		if (digit1 == digit2 || digit1 == digit3 || digit1 == digit4 || digit2 == digit3 || digit2 == digit4 || digit3 == digit4)
		{
			cout<<"The digits must all be different, try again\n";
		}
		else if (digit1 != digit3 * 3)
		{
			cout<<"The Thousands place digit must be three times as much as the tens place digit, try again\n";
		}
		else if (num % 2 == 0)
		{
			cout<<"The number must be odd, try again\n";
		}
		else if (digit1 + digit2 + digit3 + digit4 != 27)
		{
			cout<<"The sum of the digits must equal 27, try again\n";
		}
		else if(num == secret)
		{
			cout<<"Congratulations, you have found the secret number!\n";
			return 0;
		}
		else
		{
			cout<<"You are way off, try again\n";
		}

		cout<<"Enter in a four digit number"<<endl;
                cin>>num;

	}
	return 0;
}
