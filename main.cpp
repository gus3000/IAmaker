#include <iostream>
#include <vector>
#include <string>
#include <sstream>

#include "board.hpp"

using std::vector;
using std::string;
using std::stringstream;
using std::cout;
using std::endl;


int main()
{
    int t1[] = {1,2,3};
    int t2[] = {4,5,6};
    int t3[] = {7,8,9};
    int *t[] = {t1,t2,t3};

    Board b (3,3, t);
    Action a1 (Action::Direction::ROW, 0, Action::Magnitude::LEFT);

    cout << b;
    b.executeAction(a1);
    cout << b;
}
