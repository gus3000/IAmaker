#ifndef ACTION_HPP
#define ACTION_HPP

#include <vector>

#include "state.hpp"

using std::vector;

class Action
{
public:

    virtual State *operator()(State *s) = 0;
    virtual vector<Action *> allActions(State *s) = 0;
};

#endif // ACTION_HPP
