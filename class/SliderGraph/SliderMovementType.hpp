#ifndef SLIDERMOVEMENTTYPE_HPP
#define SLIDERMOVEMENTTYPE_HPP

using namespace std;
#include <iostream>
#include <string>
#include "../../constants.hpp"
#include "../Slider/Slider.hpp"

typedef enum{
    movedUp, movedDown, movedLeft, movedRight, original
} SliderMovementType;

string SliderMovementTypeToString(SliderMovementType sliderMovementType);

#endif