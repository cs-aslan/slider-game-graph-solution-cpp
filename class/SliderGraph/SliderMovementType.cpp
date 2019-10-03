using namespace std;
#include <iostream>
#include <string>
#include "../../constants.hpp"
#include "SliderMovementType.hpp"

string SliderMovementTypeToString(SliderMovementType sliderMovementType){
    switch (sliderMovementType)
    {
    case original:
        return "Original";
    case movedUp:
        return "Movido para cima";

    case movedDown:
        return "Movido para baixo";

    case movedLeft:
        return "Movido para esquerda";

    case movedRight:
        return "Movido para direita";
    
    default:
        return "Inválido";
    }
}