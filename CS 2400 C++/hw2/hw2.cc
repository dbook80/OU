
// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
//
//   program:     Homework 2
//
//   Name  :      Donovan Booker
//
//   Description: This program is designed to keep your spending
//
//   within the budget, so you can actually purchase your items
//
//   without any debt.
//
//   Date  :   February 3, 2017
//
// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

#include <iostream>
using namespace std;

int main()
{

int giftcard = 100;
const double SALES_TAX = .0675;
double x;
double y;
double z;
double totalamt;

cout.setf(ios::fixed);
cout.setf(ios::showpoint);
cout.precision(2);

	cout<< "How much is your gift card worth?\n";
	cin>>  giftcard;

	cout<< "Enter the amounts of your three items:\n";
	cin >> x >> y >> z;

	totalamt = (( x + y + z ) * SALES_TAX) + x + y + z;

while (giftcard < totalamt)
{
	cout<< "Your purchases with tax will total"<<" "<<totalamt<<endl;
	cout<< "Your gift card contains insufficient funds\n";
	cout<< "Try picking some different items.\n";
	cout<< "Enter the amounts of your three items:\n";
	cin>> x >> y >> z;
	totalamt = (( x + y + z ) * SALES_TAX) + x + y + z;

}
	cout<< "This works with your gift card.\n";
	cout<< "Have a good day.\n";
	cout<< "You will have a remaining balance of"<<" "<< giftcard - totalamt <<" "<< "left on your gift card.\n";

	return (0);
}


