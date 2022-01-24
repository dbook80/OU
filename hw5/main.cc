/**********************************************
This is the main for tha Animal homes project

    Donovan Booker      Fall 2017
***********************************************/

#include<iostream>
#include<fstream>
#include<list>
#include<iterator>
#include"Homes.h"
using namespace std;

int menu();
//void load(ifstream& fin);
//void save(ofstream& fout);

int main(){
    Homes * tmp;
    list<Homes *> home;
    list<Homes *>::iterator it;
    int choice;
    string username, filename;
    ofstream fin;
    ofstream fout;

	cout<<"Welcome to Animal Construction Inc.\n\n";
	cout<<"Begin by entering your username: ";
	getline(cin,username);
	filename = username + ".txt";
	fin.open(filename.c_str());
    if(!fin.fail())
    {
        for(it = home.begin(); it != home.end(); it++)
        {
            (*it)->save(fout);
        }
    }
	fin.close();
	choice = 0;

	while(choice != 7){
	    choice = menu();
	    switch(choice){
        case 1:
            tmp = new jaguar;
            tmp-> input(cin);
            home.push_back(tmp);
			break;
        case 2: 
            tmp = new pig;
            tmp-> input(cin);
            home.push_back(tmp);
			break;
        case 3: 
            tmp = new bat;
            tmp-> input(cin);
            home.push_back(tmp);
			break;
        case 4: 
            tmp = new gorilla;
            tmp-> input(cin);
            home.push_back(tmp);
			break;
        case 5:
            tmp = new lombax;
            tmp-> input(cin);
            home.push_back(tmp);
			break;
        case 6:	
            for(it = home.begin(); it != home.end(); it++)
            {
                (*it)->output(cout);
            }
			break;
        default:
            break;
		} // bottom of the switch
	} // bottom of the while
	fout.open(filename.c_str());
        if(!fout.fail())
        for(it = home.begin(); it != home.end(); it++)
        {
            (*it)->save(fout);
        }
	else
	    cout<<"Unable to save data.\n";
	fout.close();

    cout<<"Have a great day, we hope you enjoy your new home!\n";
    
return 0;
}
	
int menu(){
	int ans;
	cout<<"Choose from the options below:\n";
	cout<<"1 - Order a home for a Jaguar.\n";
	cout<<"2 - Order a home for a Pig.\n";
	cout<<"3 - Order a home for a Bat.\n";
	cout<<"4 - Order a home for a Gorilla.\n";
	cout<<"5 - Order a home for a Lombax.\n";
	cout<<"6 - See the list of ordered homes. \n";
	cout<<"7 - Leave the program.\n";
	cin>>ans;
    return ans;
}
/*void load(ifstream& fin)
{
    Homes * tmp;
    list<Homes *> home;
    char animalcode; 
    if(animalcode == 'j')
    {
        tmp = new jaguar;
        tmp->input(fin);
        home.push_back(tmp);
    }
    else if(animalcode == 'p')
    {
        tmp = new pig;
        tmp->input(fin);
        home.push_back(tmp);
    }
    else if(animalcode == 'b')
    {
        tmp = new bat;
        tmp->input(fin);
        home.push_back(tmp);
    }
    else if(animalcode == 'g')
    {
        tmp = new gorilla;
        tmp->input(fin);
        home.push_back(tmp);
    }
    else if(animalcode == 'l')
    {
        tmp = new lombax;
        tmp->input(fin);
        home.push_back(tmp);
    }
    else
    {
        cout<<"error loading file" << endl;
        return;
    }
}
void save(ofstream& fout)
{
    Homes * tmp;
    list<Homes *> home;
    char animalcode; 
    if(animalcode == 'j')
    {
        tmp = new jaguar;
        tmp->output(fout);
        home.push_back(tmp);
    }
    else if(animalcode == 'p')
    {
        tmp = new pig;
        tmp->output(fout);
        home.push_back(tmp);
    }
    else if(animalcode == 'b')
    {
        tmp = new bat;
        tmp->output(fout);
        home.push_back(tmp);
    }
    else if(animalcode == 'g')
    {
        tmp = new gorilla;
        tmp->output(fout);
        home.push_back(tmp);
    }
    else if(animalcode == 'l')
    {
        tmp = new lombax;
        tmp->output(fout);
        home.push_back(tmp);
    }
    else
    {
        cout<<"error saving file" << endl;
        return;
    }
}*/
