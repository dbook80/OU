/*
    This is the Othello class implementations derived 
    from the game class

    Donovan Booker  Fall 2017
*/

#include "Othello.h"
#include "game.h"
#include <string>
#include <cctype>
#include <iostream>
using namespace std;
namespace main_savitch_14
{

void Othello::restart()
{
    for(int i = 0; i < 8; i++)
    {
        for(int j = 0; j < 8; j++)
        {
            if(i == 3 && j == 3 || i == 4 && j == 4)
            {
                board[i][j].set_piece(1);
            }
            else if(i == 3 && j == 4 || i == 4 && j == 3)
            {
                board[i][j].set_piece(2);
            }
            else
            {
                board[i][j].set_piece(0);
            }
        }
    }
}
bool Othello::is_legal(const std::string& move)const
{
    char first, second;
    int row, col;
    first = move.at(0);
    second = move.at(1);
    if(first == int(toupper('a')))
    {
        col = 0;
    }
    else if(first == int(toupper('b')))
    {
        col = 1;
    }
    else if(first == int(toupper('c')))
    {
        col = 2;
    }
    else if(first == int(toupper('d')))
    {
        col = 3;
    }
    else if(first == int(toupper('e')))
    {
        col = 4;
    }
    else if(first == int(toupper('f')))
    {
        col = 5;
    }
    else if(first == int(toupper('g')))
    {
        col = 6;
    }
    else if(first == int(toupper('h')))
    {
        col = 7;
    }
    if(second == '1')
    {
        row = 0;
    }
    else if(second == '2')
    {
        row = 1;
    }
    else if(second == '3')
    {
        row = 2;
    }
    else if(second == '4')
    {
        row = 3;
    }
    else if(second == '5')
    {
        row = 4;
    }
    else if(second == '6')
    {
        row = 5;
    }
    else if(second == '7')
    {
        row = 6;
    }
    else if(second == '8')
    {
        row = 7;
    }

    

    if(search_right(row, col) == true || search_left(row, col) == true || search_up(row, col) == true || search_down(row, col) == true || search_upright(row, col) == true || search_upleft(row, col) == true || search_downleft(row, col) == true || search_downright(row, col) == true) 
    {
        return true;
    }
    else
    {
        return false;
    }
    

}
void Othello::make_move(const std::string& move)
{
    char first, second;
    int row, col;
    first = move.at(0);
    second = move.at(1);
    if(first == int(toupper('a')))
    {
        col = 0;
    }
    else if(first == int(toupper('b')))
    {
        col = 1;
    }
    else if(first == int(toupper('c')))
    {
        col = 2;
    }
    else if(first == int(toupper('d')))
    {
        col = 3;
    }
    else if(first == int(toupper('e')))
    {
        col = 4;
    }
    else if(first == int(toupper('f')))
    {
        col = 5;
    }
    else if(first == int(toupper('g')))
    {
        col = 6;
    }
    else if(first == int(toupper('h')))
    {
        col = 7;
    }
    if(second == '1')
    {
        row = 0;
    }
    else if(second == '2')
    {
        row = 1;
    }
    else if(second == '3')
    {
        row = 2;
    }
    else if(second == '4')
    {
        row = 3;
    }
    else if(second == '5')
    {
        row = 4;
    }
    else if(second == '6')
    {
        row = 5;
    }
    else if(second == '7')
    {
        row = 6;
    }
    else if(second == '8')
    {
        row = 7;
    }
  
   if(get_moves() % 2 == 0)
   {
       board[row][col].set_piece(2);
        if(search_right(row, col) == true)
        {
            col++;
            while(board[row][col].get_piece() != 2)
            {
                board[row][col].flip();
                col++;
            }
        }
        if(search_left(row, col) == true)
        {
            col--;
            while(board[row][col].get_piece() != 2)
            {
                board[row][col].flip();
                col--;
            }
        }
        if(search_up(row, col) == true)
        {
            row--;
            while(board[row][col].get_piece() != 2)
            {
                board[row][col].flip();
                row--;
            }
        }
        if(search_down(row, col) == true)
        {
            row++;
            while(board[row][col].get_piece() != 2)
            {
                board[row][col].flip();
                row++;
            }
        }
        if(search_upright(row, col) == true)
        {
            col++;
            row--;
            while(board[row][col].get_piece() != 2)
            {
                board[row][col].flip();
                col++;
                row--;
            }
        }
        if(search_upleft(row, col) == true)
        {
            col--;
            row--;
            while(board[row][col].get_piece() != 2)
            {
                board[row][col].flip();
                col--;
                row--;
            }
        }
        if(search_downleft(row, col) == true)
        {
            col--;
            row++;
            while(board[row][col].get_piece() != 2)
            {
                board[row][col].flip();
                col--;
                row++;
            }
        }
        if(search_downright(row, col) == true)
        {
            col++;
            row++;
            while(board[row][col].get_piece() != 2)
            {
                board[row][col].flip();
                col++;
                row++;
            }
        }
   }
   else
   {
        board[row][col].set_piece(1);
        if(search_right(row, col) == true)
        {
            col++;
            while(board[row][col].get_piece() != 1)
            {
                board[row][col].flip();
                col++;
            }
        }
        if(search_left(row, col) == true)
        {
            col--;
            while(board[row][col].get_piece() != 1)
            {
                board[row][col].flip();
                col--;
            }
        }
        if(search_up(row, col) == true)
        {
            row--;
            while(board[row][col].get_piece() != 1)
            {
                board[row][col].flip();
                row--;
            }
        }
        if(search_down(row, col) == true)
        {
            row++;
            while(board[row][col].get_piece() != 1)
            {
                board[row][col].flip();
                row++;
            }
        }
        if(search_upright(row, col) == true)
        {
            col++;
            row--;
            while(board[row][col].get_piece() != 1)
            {
                board[row][col].flip();
                col++;
                row--;
            }
        }
        if(search_upleft(row, col) == true)
        {
            col--;
            row--;
            while(board[row][col].get_piece() != 1)
            {
                board[row][col].flip();
                col--;
                row--;
            }
        }
        if(search_downleft(row, col) == true)
        {
            col--;
            row++;
            while(board[row][col].get_piece() != 1)
            {
                board[row][col].flip();
                col--;
                row++;
            }
        }
        if(search_downright(row, col) == true)
        {
            col++;
            row++;
            while(board[row][col].get_piece() != 1)
            {
                board[row][col].flip();
                col++;
                row++;
            }
        }       
   }
   next_move();
}

void Othello::display_status()const
{
    cout << "\e[41m"; // It's Christmas time, Red and green it is!
    int row_count = 1; //row label
    char cols[8]; // column label
    cols[0] = 'A';
    cols[1] = 'B';
    cols[2] = 'C';
    cols[3] = 'D';
    cols[4] = 'E';
    cols[5] = 'F';
    cols[6] = 'G';
    cols[7] = 'H';
    cout << " "  << GREEN << " | ";
    for(int x = 0; x < 8; x++)
    {
        cout << CYAN << cols[x];
        cout << GREEN << " | ";
    }
    cout << endl;

    for(int i = 0; i < 8; i++)
    {
        cout << CYAN << row_count;
        cout << GREEN << " | ";
        for(int j = 0; j < 8; j++)
        {
            if(board[i][j].get_piece() == 0)
            {
                cout<< GREEN <<"0";
                cout << " | ";
            }
            else if(board[i][j].get_piece() == 1)
            {
                cout<< WHITE <<"*";//December bound = snowflakes
                cout << GREEN << " | ";
            }
            else if(board[i][j].get_piece() == 2)
            {
                cout<< BLACK <<"$";// a lot of money spent on Christmas
                cout << GREEN << " | ";
            }
        }
        row_count++;
        cout << endl;
    }
}
bool Othello::search_right(int row, int col)const
{
    col++;
    if(get_moves() % 2 == 0)
    {
        while(board[row][col].get_piece() != 0 && col < 7)
        {
            if(board[row][col].get_piece() == 1)
            {
                col++;
                if(board[row][col].get_piece() == 2)
                {
                    return true;
                }
                else
                {
                    return false;
                }
            }
            else
            {
                return false;
            }
        }
    }
    else
    {
        while(board[row][col].get_piece() != 0 && col < 7)
        {
            if(board[row][col].get_piece() == 2)
            {
                col++;
                if(board[row][col].get_piece() == 1)
                {
                    return true;
                }
            }
            else
            {
                return false;
            }
        }
    }
}
bool Othello::search_left(int row, int col)const
{
    col--;
    if(get_moves() % 2 == 0)
    {
        while(board[row][col].get_piece() != 0 && col > 0)
        {
            if(board[row][col].get_piece() == 1)
            {
                col--;
                if(board[row][col].get_piece() == 2)
                {
                    return true;
                }
            }
            else
            {
                return false;
            }
        }
    }
    else
    {
        while(board[row][col].get_piece() != 0 && col > 0)
        {
            if(board[row][col].get_piece() == 2)
            {
                col--;
                if(board[row][col].get_piece() == 1)
                {
                    return true;
                }
            }
            else
            {
                return false;
            }
        }
    }
}
bool Othello::search_up(int row, int col)const
{
    row--;
    if(get_moves() % 2 == 0)
    {
        while(board[row][col].get_piece() != 0 && row > 0)
        {
            if(board[row][col].get_piece() == 1)
            {
                row--;
                if(board[row][col].get_piece() == 2)
                {
                    return true;
                }
            }
            else
            {
                return false;
            }
        }
    }
    else
    {
        while(board[row][col].get_piece() != 0 && row > 0)
        {
            if(board[row][col].get_piece() == 2)
            {
                row--;
                if(board[row][col].get_piece() == 1)
                {
                    return true;
                }
            }
            else
            {
                return false;
            }    
        }   
    }
}
bool Othello::search_down(int row, int col)const
{
    row++;
    if(get_moves() % 2 == 0)
    {
        while(board[row][col].get_piece() != 0 && row < 7)
        {
            if(board[row][col].get_piece() == 1)
            {
                row++;
                if(board[row][col].get_piece() == 2)
                {
                    return true;
                }
            }
            else
            {
                return false;
            }
        }
    }
    else
    {
        while(board[row][col].get_piece() != 0 && row < 7)
        {
            if(board[row][col].get_piece() == 2)
            {
                row++;
                if(board[row][col].get_piece() == 1)
                {
                    return true;
                }
            }
            else
            {
                return false;
            }    
        }
    }
}
bool Othello::search_upright(int row, int col)const
{
    col++;
    row--;
    if(get_moves() % 2 == 0)
    {
        while(board[row][col].get_piece() != 0 && col < 7 && row > 0)
        {
            if(board[row][col].get_piece() == 1)
            {
                col++;
                row--;
                if(board[row][col].get_piece() == 2)
                {
                    return true;
                }
            }
            else
            {
                return false;
            }
        }
    }
    else
    {
        while(board[row][col].get_piece() != 0 && col < 7 && row > 0)
        {
            if(board[row][col].get_piece() == 2)
            {
                col++;
                row--;
                if(board[row][col].get_piece() == 1)
                {
                    return true;
                }
            }
            else
            {
                return false;
            }
        }   
    }
}
bool Othello::search_upleft(int row, int col)const
{
    col--;
    row--;
    if(get_moves() % 2 == 0)
    {
        while(board[row][col].get_piece() != 0 && col > 0 && row > 0)
        {
            if(board[row][col].get_piece() == 1)
            {
                col--;
                row--;
                if(board[row][col].get_piece() == 2)
                {
                    return true;
                }
            }
            else
            {
                return false;
            }
        }
    }
    else
    {
        while(board[row][col].get_piece() != 0 && col > 0 && row > 0)
        {
            if(board[row][col].get_piece() == 2)
            {
                col--;
                row--;
                if(board[row][col].get_piece() == 1)
                {
                    return true;
                }
            }
            else
            {
                return false;
            }
        }
    }
}
bool Othello::search_downleft(int row, int col)const
{
    col--;
    row++;
    if(get_moves() % 2 == 0)
    {
        while(board[row][col].get_piece() != 0 && col > 0 && row < 7)
        {
            if(board[row][col].get_piece() == 1)
            {
                col--;
                row++;
                if(board[row][col].get_piece() == 2)
                {
                    return true;
                }
            }
            else
            {
                return false;
            }
        }
    }
    else
    {
        while(board[row][col].get_piece() != 0 && col > 0 && row < 7)
        {
            if(board[row][col].get_piece() == 2)
            {
                col--;
                row++;
                if(board[row][col].get_piece() == 1)
                {
                    return true;
                }
            }
            else
            {
                return false;
            }
        }
    }
}
bool Othello::search_downright(int row, int col)const
{
    col++;
    row++;
    if(get_moves() % 2 == 0)
    {
        while(board[row][col].get_piece() != 0 && col < 7 && row < 7)
        {
            if(board[row][col].get_piece() == 1)
            {
                col++;
                row++;
                if(board[row][col].get_piece() == 2)
                {
                    return true;
                }
            }
            else
            {
                return false;
            }
        }
    }
    else
    {
        while(board[row][col].get_piece() != 0 && col < 7 && row < 7)
        {
            if(board[row][col].get_piece() == 2)
            {
                col++;
                row++;
                if(board[row][col].get_piece() == 1)
                {
                    return true;
                }
            }
            else
            {
                return false;
            }
        }
    }
}
void Othello::skip()const
{
    
}
bool Othello::is_game_over()const
{
    int board_pieces = 0; //counting black and white pieces 
    for(int i = 0; i < 8; i++)
    {
        for(int j = 0; j < 8; j++)
        {
            if(board[i][j].get_piece() != 0)
            {
                board_pieces++;
            }
        }
    }
    if(board_pieces == 64)
    {
        return true;
    }
    else
    {
        return false;
    }

   
}
void Othello::winner()
{
    int black_counter = 0; // number of black pieces
    int white_counter = 0; // number of white pieces
    for(int x = 0; x < 8; x++)
    {
        for(int y = 0; y < 8; y++)
        {
            if(board[x][y].get_piece() == 1)
            {
                white_counter++;
            }
        }
    }
    for(int n = 0; n < 8; n++)
    {
        for(int m = 0; m < 8; m++)
        {
            if(board[n][m].get_piece() == 2)
            {
                black_counter++;
            }
        }
    }
    
    while(is_game_over() == true)
    {
        if(black_counter > white_counter)
        {
            cout << "Black Player wins!" << endl;
        }
        else
        {
            cout << "White Player wins!" << endl;
        }
    }
}
void Othello::compute_moves(queue<string>& moves)const
{
    string one, two;
    while(!moves.empty())
    {
        moves.pop();
    }
    for(char i = 'A'; i <= 'H'; i++)
    {
        for(char j = '1'; j <= '8'; j++)
        {
            one = i;
            two = j;
            one += two;
            if(is_legal(one))
            {
                moves.push(one);
            }
        }
    }
}

int Othello::evaluate()const
{
   int counter = 0;
   int x, y;
   string move, tmp;
   for(char i = 'A'; i <= 'H'; i++)
   {
       for(char j = '1'; j <= '8'; j++)
       {
           move = i;
           tmp = j;
           move += tmp;
           x = int(toupper(i) - 'A');
           y = int(j -'1');
           if(move == "A1" || move == "H1" || move == "A8" || move == "H8")//corners
           {
               if(board[x][y].get_piece() == 1)
               {
                   counter += 2;
               }
               else
               {
                   counter -= 2;
               }
           }
           else
           {
               if(board[x][y].get_piece() == 1)
               {
                   counter += 1;
               }
               else
               {
                   counter -= 1;
               }
           }
       }
   }
}
}