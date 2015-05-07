#ifndef ACTION_HPP
#define ACTION_HPP

#include <state.hpp>


class Action
{
public:
    Action();
    virtual ~Action() = 0;

    virtual State *operator()(State *s) = 0;
};

#endif // ACTION_HPP
