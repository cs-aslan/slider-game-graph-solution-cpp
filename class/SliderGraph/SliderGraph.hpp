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
    string pathToRoot();
    void depthSearchRecursive(SliderGraph ** bestSolution, int recursions, int minimumPath);
    void createChildren();
    
public:
    SliderGraph();
    SliderGraph(string filename);
    ~SliderGraph();
    void trimTree();

    string toString();
    string toStringFullTree();

    bool isSolvable();
    string widhtSearch();
    string depthSearch();
};

#endif