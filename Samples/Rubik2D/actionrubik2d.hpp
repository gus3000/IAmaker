#ifndef ACTIONRUBIK2D_HPP
#define ACTIONRUBIK2D_HPP

#include "board.hpp"

#include <Motor/action.hpp>



class ActionRubik2D : Action
{
public:
    ActionRubik2D();
    ~ActionRubik2D();

    State *operator()(State *s);
    vector<Action *> allActions(State *s);

};

#endif // ACTIONRUBIK2D_HPP
