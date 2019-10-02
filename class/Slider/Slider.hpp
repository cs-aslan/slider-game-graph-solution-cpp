#ifndef SLIDER_HPP
#define SLIDER_HPP

using namespace std;
#include <iostream>
#include <string>
#include "../../constants.hpp"

class Slider
{
private:
    short int matrix[slidersize][slidersize];
    short int xZero, yZero;
public:
    Slider();
    ~Slider();

    string toString();

    bool movableDown();
    bool movableUp();
    bool movableLeft();
    bool movableRight();

    Slider moveDown();
    Slider moveUp();
    Slider moveRight();
    Slider moveLeft();
};

#endif