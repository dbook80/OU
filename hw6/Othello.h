/*
    This is the Othello class derived 
    from the game class

    Donovan Booker  Fall 2017
*/

#include "game.h"
#include "piece.h"
#include "colors.h"
#include <string>
#include <cctype>
#include <iostream>
using namespace std;
namespace main_savitch_14
{

class Othello:public game{
    public:
        Othello(){restart();}
        void restart();
        bool is_legal(const std::string& move)const;
        void make_move(const std::string& move);
        void display_status()const;
        //Checking for illegal moves in the four basic directions
        bool search_right(int row, int col)const;
        bool search_left(int row, int col)const;
        bool search_up(int row, int col)const;
        bool search_down(int row, int col)const;
        //Checking illegal moves in the four diagonal directions
        bool search_upright(int row, int col)const;
        bool search_upleft(int row, int col)const;
        bool search_downleft(int row, int col)const;
        bool search_downright(int row, int col)const;

        int get_moves()const {return moves;}
        void next_move() {moves++;}
        void winner();
        void skip()const; // skip player's turn if no valid moves available

        game* clone()const {return new Othello(*this);}
        /// Compute all the moves that the next player can make:
    	void compute_moves(queue<string>& moves)const;
    	// Evaluate a board position:
	// NOTE: positive values are good for the computer.
    	int evaluate()const;
    	// Return true if the current game is finished:
        bool is_game_over()const;

        virtual who last_mover( ) const 
        { return (moves % 2 == 1 ? HUMAN : COMPUTER); }
        
	    virtual who next_mover( ) const
	    { return (moves % 2 == 0 ? HUMAN : COMPUTER); }

    private:
        piece board[8][8]; //[row][column]
        int moves;
};
}