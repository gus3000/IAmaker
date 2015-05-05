#include "board.hpp"

void Board::executeAction(Action a)
{
    if(a.dir == Action::Direction::ROW)
    {
	moveRow(a.index, a.mag == Action::Magnitude::RIGHT);
    }
    else
    {
	moveColumn(a.index, a.mag == Action::Magnitude::DOWN);
    }
}

void Board::moveRow(int index, bool right)
{
    cout << "moving row " << index << " " << (right ? "right" : "left") << " !" << endl;

    if(right)
    {
	int save = tab[index][width-1];
		
	for(int i=width-2; i>=0; i--)
	{
	    tab[index][i+1] = tab[index][i];
	}
	tab[index][0] = save;
    }
    else
    {
	int save = tab[index][0];

	for(int i=0; i<width-1; i++)
	{
	    tab[index][i] = tab[index][i+1];
	}
	tab[index][width-1] = save;
    }
	    
}

void Board::moveColumn(int index, bool down)
{
    cout << "moving column " << index << " " << (down ? "down" : "up") << " !" << endl;

    if(down)
    {
	int save = tab[height-1][index];
		
	for(int i=height-2; i>=0; i--)
	{
	    tab[i+1][index] = tab[i][index];
	}
	tab[0][index] = save;
    }
    else
    {
	int save = tab[0][index];
		
	for(int i=0; i<height-1; i++)
	{
	    tab[i][index] = tab[i+1][index];
	}
	tab[height-1][index] = save;
    }
	    
	
}

string Board::toString()
{
    stringstream ss;

    for(auto it = tab.begin(); it != tab.end(); it++)
    {
	for(auto it2 = (*it).begin(); it2 != (*it).end(); it2++)
	{
	    ss << *it2;
	}
	ss << "\n";
    }
	    
    return ss.str();
}

ostream& operator<< (ostream &s, Board &b)
{
    s << b.toString();
    return s;
}
