#ifndef SLIDERGRAPH_HPP
#define SLIDERGRAPH_HPP

using namespace std;
#include <iostream>
#include <string>
#include "../../constants.hpp"
#include "../Slider/Slider.hpp"
#include "SliderMovementType.hpp"

class SliderGraph : private Slider
{
private:
    SliderGraph * up;
    SliderGraph * down;
    SliderGraph * left;
    SliderGraph * right;
    SliderMovementType moved;
public:
    SliderGraph(/* args */);
    ~SliderGraph();

    string toString();
    string toStringFullTree();
    void createChildren();
};

#endif