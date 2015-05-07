#include "node.hpp"

template <typename StateType>
Node<StateType>::~Node()
{
    //we delete every child
    for(auto it = children.begin(); it != children.end(); it++)
    {
        delete *it;
    }

    //note that we did not delete the parent node, so if want to destroy the whole tree you must call delete on root.
}

template <typename StateType>
void Node<StateType>::develop()
{
    state.getChildren();
}
