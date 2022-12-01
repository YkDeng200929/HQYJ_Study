#ifndef _CHESS_HPP
#define _CHESS_HPP

#include <iostream>

class Chess
{
public:
    virtual MoveChess() = 0;
};

class BlackChess
{
public:
    BlackChess(string color) : color(color){;}
    ~BlackChess()
private:
    string color;
};



#endif // end of chess.hpp