using namespace std;
#include <iostream>
#include <string>

#include "Slider.hpp"

Slider::Slider()
{
    for (size_t i = 0; i < slidersize; i++)
    {
        for (size_t j = 0; j < slidersize; j++)
        {
            this->matrix[i][j] = -1;
        }
        
    }

    srand (time(NULL));

    short int randX = rand() % slidersize;
    short int randY = rand() % slidersize;
    
    for (size_t i = 0; i < sliderarea; i++)
    {
        while (this->matrix[randX][randY]!=-1)
        {
            randX = rand() % slidersize;
            randY = rand() % slidersize;
        }

        this->matrix[randX][randY]=i;

        if(i==0){
            this->xZero = randX;
            this->yZero = randY;
        }        
        
    }
    
}

Slider::~Slider()
{
}

string Slider::toString()
{
    
    string aux = "";
    for (size_t i = 0; i < slidersize; i++)
    {
        for (size_t j = 0; j < slidersize; j++)
        {
            aux += to_string(this->matrix[i][j]) + " ";
        }

        aux+="\n";
        
    }

    aux+= "Zero em <" + to_string(this->xZero) + "," + to_string(this->yZero) + ">\n";

    return aux;
}

bool Slider::movableDown()
{
    return this->xZero==0;
}

bool Slider::movableUp()
{
    return this->xZero==sliderlastelement;
}

bool Slider::movableRight()
{
    return this->yZero==0;
}

bool Slider::movableLeft()
{
    return this->yZero==sliderlastelement;
}

Slider Slider::moveDown()
{
    Slider newSlider = (*this); // Copy

    newSlider.matrix[xZero][yZero] = newSlider.matrix[xZero-1][yZero];
    newSlider.matrix[xZero-1][yZero] = 0;

    newSlider.xZero = xZero-1;

    return newSlider;
    
}

Slider Slider::moveUp()
{
    Slider newSlider = (*this); // Copy

    newSlider.matrix[xZero][yZero] = newSlider.matrix[xZero+1][yZero];
    newSlider.matrix[xZero+1][yZero] = 0;

    newSlider.xZero = xZero+1;

    return newSlider;
    
}

Slider Slider::moveRight()
{
    Slider newSlider = (*this); // Copy

    newSlider.matrix[xZero][yZero] = newSlider.matrix[xZero][yZero-1];
    newSlider.matrix[xZero][yZero-1] = 0;

    newSlider.yZero = yZero-1;

    return newSlider;
    
}

Slider Slider::moveLeft()
{
    Slider newSlider = (*this); // Copy

    newSlider.matrix[xZero][yZero] = newSlider.matrix[xZero][yZero+1];
    newSlider.matrix[xZero][yZero+1] = 0;

    newSlider.yZero = yZero+1;

    return newSlider;
    
}