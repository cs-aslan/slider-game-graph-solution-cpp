#ifndef SLIDERGRAPH_HPP
#define SLIDERGRAPH_HPP

using namespace std;
#include <iostream>
#include <string>
#include <queue>
#include "../../constants.hpp"
#include "../Slider/Slider.hpp"
#include "SliderMovementType.hpp"

class SliderGraph : private Slider
{
private:
    SliderGraph * up;
    SliderGraph * down;
    SliderGraph * left;
    SliderGraph * right;
    SliderMovementType moved;

    short int level;
    SliderGraph * father;
    
    void nullfillChildren();
public:
    SliderGraph();
    SliderGraph(string filename);
    ~SliderGraph();

    string toString();
    string toStringFullTree();
    void createChildren();

    string widhtSearch();
    string pathToRoot();
    void DepthSearchRecursive(SliderGraph ** bestSolution, int recursions, int minimumPath);
    string DepthSearch();
};

#endif