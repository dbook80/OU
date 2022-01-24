#include<iostream>
#include "friend.h"
using namespace std;

int main()
{
    Friend Jane("Jane", Date(9,1,1996));
    Friend Joe("Joe", Date(10,1,1998));

     
    if(Joe == Jane) {
        cout << "true" << endl;
    }

    else {
        cout << "false" << endl;
    }
    if(Joe != Jane) {
        cout << "true" << endl;
    }

    else {
        cout << "false" << endl;
    }
    cout << Jane;
}