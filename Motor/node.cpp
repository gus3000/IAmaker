#include "node.hpp"

template <typename StateType>
Node<StateType>::Node(StateType s)
{

}

template <typename StateType>
Node<StateType>::~Node()
{
    //we delete every child
    for(auto it = children.begin(); it != children.end(); it++)
    {
        delete *it;
    }

    //note that we did not delete the parent node, so if you want to destroy the whole tree you want to call delete on root.
}
