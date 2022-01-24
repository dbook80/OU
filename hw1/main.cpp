#include <iostream>
#include "linked_list.h"
using namespace std;

int main() 
{
  LinkedList<int> list;
  char option;
  int i;

  option = menu();
	while(option != 'q')
  {
	    switch(option)
      {
          case 'i':
            cout<<"Enter an integer.\n";
            cin >> i;
            list.push_front(i);
        break;
          case 'd':
            list.pop_front();
        break;
          case 'r':
            list.reverse();
        break;
          case 'p':
            list.print();
        break;
          case 'q':
        break;
          default:
            cout<<"Not an option.\n";
        break;
	    } //bottom of the switch
	    option = menu();
  }
  return 0;
}



