using namespace std;
#include <iostream>

#include "constants.hpp"
#include "class/Slider/Slider.hpp"
#include "class/SliderGraph/SliderGraph.hpp"

int main(int argc, char const *argv[])
{
    SliderGraph * a = new SliderGraph();

    a->createChildren();

    cout << a->toStringFullTree();

    a->~SliderGraph();
    
    return 0;
}
