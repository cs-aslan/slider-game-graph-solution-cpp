using namespace std;
#include <iostream>
#include <string>

#include "../Slider/Slider.hpp"
#include "SliderGraph.hpp"
#include "SliderMovementType.hpp"

SliderGraph::SliderGraph()
{
    this->up = NULL;
    this->down = NULL;
    this->left = NULL;
    this->right = NULL;
    this->moved = original;
}

SliderGraph::~SliderGraph()
{
}

string SliderGraph::toString()
{
    return SliderMovementTypeToString(this->moved) + "\n" + Slider::toString();
}

void SliderGraph::createChildren()
{
    if(this->moved != movedUp && Slider::movableDown())
    {
        this->down = (SliderGraph*) malloc(sizeof(SliderGraph));
        *(this->down) = (*this);
        this->down->moveDown();
    }
}