using namespace std;
#include <iostream>

#include "constants.hpp"
#include "class/Slider/Slider.hpp"
#include "class/SliderGraph/SliderGraph.hpp"

int main(int argc, char const *argv[])
{
    SliderGraph * a = new SliderGraph();

    cout << a->toString();

    cout << a->widhtSearch();
    
    return 0;
}
