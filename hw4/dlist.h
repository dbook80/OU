/********************************************************************
   This is the header file for the dnode, dlist, and node iterator 
   classes. 
       Donovan Booker				Fall 2017
***********************************************************************/
#include<iostream>
#include"dnode.h"
#include"iterator.h"
using namespace std;

template <class T> class node_iterator;
template <class T>

class dlist{
    public:
        dlist()
        {
            head = NULL;
            tail = NULL;
            counter = 0;
        }
        // big 3 functions
        
        ~dlist();
        dlist(const dlist& other);
        dlist& operator = (const dlist& other);
        
        void front_insert(const T& front);
        void rear_insert(const T& back);
        void show();
        void reverse_show();
        void front_remove();// 2 lines of code
        void rear_remove();// 2 lines of code

         typedef node_iterator<T>iterator;
         iterator begin()
         {return iterator(head);}
 
         iterator end()
         {return iterator(NULL);}
 
         iterator r_begin()
         {return iterator(tail);}
 
         iterator r_end()
         {return iterator(NULL);}
 
         void insert_before(iterator it, T item);
         void insert_after(iterator it, T item);
         int size(){return counter;}
         void remove(iterator it);
    private:
        int counter;
        dnode<T> * head;
        dnode<T> * tail;
};

#include "dlist.template"