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
protected:
    bool movableDown();
    bool movableUp();
    bool movableLeft();
    bool movableRight();

    void moveDown();
    void moveUp();
    void moveRight();
    void moveLeft();
public:
    Slider();
    ~Slider();

    string toString();
    bool checkVictory();
};

#endif