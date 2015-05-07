#ifndef NODE_HPP
#define NODE_HPP

#include "action.hpp"

#include <vector>

using std::vector;

/**
 * the templated Statetype must extend State
 */
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
    Node(Node* p, Action *a) : parent(p), depth(p->depth + 1), state(a(p->state)) {}
    ~Node();

    //computes children
    void develop();
};

#endif // NODE_HPP
