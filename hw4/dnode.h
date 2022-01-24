/********************************************************************
   This is the header file for the dnode class. 
       Donovan Booker				Fall 2017
***********************************************************************/
#ifndef DNODE_H
#define DNODE_H

template<class T>

class dnode{
    public:
        //Universal Constructor
        dnode(const T& d = T(), dnode * n = NULL, dnode * p = NULL)
        {
            datafield = d; next = n; prev = p;
        }
        //Accessor Functions
        dnode * link(){return next;}
        dnode * prev_link(){return prev;}
        const dnode * link()const {return next;}
        const dnode * prev_link()const {return prev;}
        const T data() {return datafield;}
        //Mutator Functions
        void set_link(dnode* n){ next = n;}
        void set_prev_link(dnode* p){ prev = p;}
        void set_data(const T& d){datafield = d;}

    private:
        T datafield;
        dnode * next;
        dnode * prev;
};
#endif