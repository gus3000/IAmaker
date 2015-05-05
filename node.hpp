#include <vector>

#include "board.hpp"

using std::vector;

class Node
{
private:
    Node *parent = NULL;
    int depth = 0;
    Board *state = NULL;
    vector<Node*> children;

    bool developped;
    
public:
    Node(Node* p, Action a)
	{
	    parent = p;
	    //TODO : compute state from p.state && action
	}
    
    ~Node()
	{
	    if(state != NULL)
		delete state;
	    
	    if(developped)
	    {
		for(auto it = children.begin(); it != children.end(); it++)
		{
		    delete *it;
		}
	    }
	}

    void develop();
};
