// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
//
//   program:     Homework 4
//
//   Name  :      Donovan Booker
//
//   Description: This program is designed to convert kilograms
//
//   and grams into pounds and ounces through procedural
//
//   abstraction.
//
//   Date  :   February 27, 2017
//
// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

#include<iostream>
#include<cmath>
#include<cctype>
using namespace std;

//Function declarations
void get_weight(int& KGs, double& Gs);

double kilograms_grams(int KGs, double Gs);//converts kilograms and grams to grams

double grams_ounces(double Gs, double oz);//converts grams to ounces

int pounds_ounces(int& lbs, double& oz, int&ozs);//calculates pounds and ounces from ounces

void print_results(int KGs, double Gs, int lbs, int ozs);

char do_again();


int main()
{
	int KGs, lbs, ozs;
	double Gs, oz;
    char ans = 'Y';
    while( toupper(ans) == 'Y')
    {
        get_weight(KGs, Gs);
		Gs =  kilograms_grams(KGs, Gs);
		oz = grams_ounces(Gs, oz);
		return static_cast<int>(oz);
		lbs = pounds_ounces(lbs, oz, ozs);
		ozs = pounds_ounces(lbs, oz, ozs);
        print_results(KGs, Gs, lbs, ozs);
        ans = do_again();
    }
	return 0;
}

//Function definitons
void get_weight(int& KGs, double& Gs)
{
        cout<<"Enter weight in Kilograms and grams\n";
        cin>> KGs >> Gs;
}
double kilograms_grams(int KGs, double Gs)
{
	Gs = ((KGs * 1000)+ Gs);
	return Gs;
}
double grams_ounces(double Gs, double oz)
{
	oz = (Gs * 0.03527396195);
	return static_cast<int>(oz);
}
int pounds_ounces(int& lbs, double& oz, int& ozs)
{
	lbs = oz / 16;
	ozs = oz % 16
	return lbs;
	return ozs;
}
void print_results(int KGs, double Gs, int lbs, int ozs)
{
        cout<< KGs <<" "<< Gs <<" "<< lbs <<" "<< ozs <<endl;
}
char do_again()
{
        char ans;
        cout<<"Do you wish to enter in two more weights?\n";
        cin >> ans;
        return ans;
}


