/********************************************************************
   This is the header file for the node iterator class 

       Donovan Booker				Fall 2017
***********************************************************************/
#include<iostream>
#include"dnode.h"
using namespace std;

template <class T> class dlist;
template <class T> 

class node_iterator{
    public:
        friend class dlist<T>;

        node_iterator(dnode<T> * init = NULL){current = init;}
        T operator*(){return current->data();}

        bool operator !=(const node_iterator& other)
        {return current != other.current;}

        bool operator ==(const node_iterator& other)
        {return current == other.current;}

        node_iterator operator ++(){current = current->link(); return * this;}

        node_iterator operator ++(int)
        {
            node_iterator original(* this);
            current = current->link();
            return original;
        }

        node_iterator operator --(){current = current->prev_link(); return * this;}
        
        node_iterator operator --(int)
        {
            node_iterator original(* this);
            current = current->prev_link();
            return original;
        }
    private:
        dnode<T>* current;
};