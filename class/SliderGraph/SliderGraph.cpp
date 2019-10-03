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

string SliderGraph::toStringFullTree()
{
    string aux = toString() + "\n";

    if(this->up != NULL) aux += this->up->toString() + "\n";
    if(this->down != NULL) aux += this->down->toString() + "\n";
    if(this->left != NULL) aux += this->left->toString() + "\n";
    if(this->right != NULL) aux += this->right->toString() + "\n";

    return aux;
}

void SliderGraph::createChildren()
{
    if(this->moved != movedUp && Slider::movableDown())
    {
        this->down = (SliderGraph*) malloc(sizeof(SliderGraph));
        *(this->down) = (*this);
        this->down->moveDown();
        this->down->moved = movedDown;
    }

    if(this->moved != movedDown && Slider::movableUp())
    {
        this->up = (SliderGraph*) malloc(sizeof(SliderGraph));
        *(this->up) = (*this);
        this->up->moveUp();
        this->up->moved = movedUp;
    }

    if(this->moved != movedLeft && Slider::movableRight())
    {
        this->right = (SliderGraph*) malloc(sizeof(SliderGraph));
        *(this->right) = (*this);
        this->right->moveRight();
        this->right->moved = movedRight;
    }

    if(this->moved != movedRight && Slider::movableLeft())
    {
        this->left = (SliderGraph*) malloc(sizeof(SliderGraph));
        *(this->left) = (*this);
        this->left->moveLeft();
        this->left->moved = movedLeft;
    }
}