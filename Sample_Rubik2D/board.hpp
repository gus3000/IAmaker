#ifndef BOARD_HPP
#define BOARD_HPP

#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using std::vector;
using std::string;
using std::stringstream;
using std::cout;
using std::endl;
using std::ostream;

struct Action;

class Board
{
private:
    int width;
    int height;
    vector<vector<int>> tab;
    
public:
    Board(int w, int h, int **t) : width(w), height(h)
	{
	    for(int i=0; i<w; i++)
	    {
		vector<int> v;
		tab.push_back(v);
		for(int j=0; j<h; j++)
		{
		    tab[i].push_back(t[i][j]);
		}
	    }
	}

    void executeAction(Action a);
    void moveRow(int index, bool right);
    void moveColumn(int index, bool down);

    string toString();
    
    ~Board()
	{
	}
};

ostream& operator<< (ostream &s, Board &b);

struct Action
{
    static vector<Action> allActions;
    enum Direction {ROW,COLUMN};
    enum Magnitude {UP, DOWN, LEFT, RIGHT};
    Direction dir;
    int index;
    Magnitude mag;

    Action(Direction d, int i, Magnitude m) : dir(d), index(i), mag(m) {}
};

#endif
