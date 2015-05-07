#ifndef NODE_HPP
#define NODE_HPP

#include <vector>

using std::vector;

template <typename StateType>
class Node
{
private:
    const Node* parent;
    const int depth;
    StateType state;
    double f,g,h; //f = g+h
    vector<Node *> children;

public:
    Node(StateType s);
    ~Node();
};

#endif // NODE_HPP
