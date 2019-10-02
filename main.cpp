using namespace std;
#include <iostream>

#include "class/Slider/Slider.hpp"

int main(int argc, char const *argv[])
{
    Slider a;
    cout << a.toString();
    cout << "\n";
    cout << a.moveDown().toString();
}
