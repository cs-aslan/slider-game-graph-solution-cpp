using namespace std;
#include <iostream>

#include "constants.hpp"
#include "class/Slider/Slider.hpp"
#include "class/SliderGraph/SliderGraph.hpp"

int main(int argc, char const *argv[])
{
    Slider a;
    cout << a.toString();
    cout << "\n";
    cout << a.moveDown().toString();
}
