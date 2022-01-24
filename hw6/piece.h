/*
    This is the pieces class where
    we determine the states of the pieces

    0 = empty  1 = white  2 = black

    Donovan Booker  Fall 2017
*/

#include <string>
#include <iostream>
using namespace std;

class piece{
    public:
        piece(){pieces = 0;}
        //accessor functions
        int get_piece()const {return pieces;}
        
        //mutator functions
        void set_piece(int a){pieces = a;}

        void flip()
        {
            if(pieces == 1)
            {
                pieces = 2;
            }
            else if(pieces == 2)
            {
                pieces = 1;
            }
        }

    private:
        int pieces;
};