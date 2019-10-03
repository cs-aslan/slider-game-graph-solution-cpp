using namespace std;
#include <iostream>
#include <string>
#include <fstream>

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

Slider::Slider(string filename)
{
    fstream in(inputpath + filename);

    if (!in) {
    cout << "Erro. Arquivo não encontrado\n";
    return;
    }

    for (size_t i = 0; i < slidersize; i++) {
        for (size_t j = 0; j < slidersize; j++) {
            in >> this->matrix[i][j];
            if(this->matrix[i][j]==0) {xZero=i; yZero=j;}
        }
    }
}

Slider::~Slider()
{
}

string Slider::toString()
{
    string aux = "Zero em <" + to_string(this->xZero) + "," + to_string(this->yZero) + ">\n";
    for (size_t i = 0; i < slidersize; i++)
    {
        for (size_t j = 0; j < slidersize; j++)
        {
            aux += to_string(this->matrix[i][j]) + " ";
        }
        aux+="\n";
    }

    return aux;
}

bool Slider::movableDown()
{
    return !(this->xZero==0);
}

bool Slider::movableUp()
{
    return !(this->xZero==sliderlastelement);
}

bool Slider::movableRight()
{
    return !(this->yZero==0);
}

bool Slider::movableLeft()
{
    return !(this->yZero==sliderlastelement);
}

void Slider::moveDown()
{
    (*this).matrix[xZero][yZero] = (*this).matrix[xZero-1][yZero];
    (*this).matrix[xZero-1][yZero] = 0;

    (*this).xZero = xZero-1;
}

void Slider::moveUp()
{
    (*this).matrix[xZero][yZero] = (*this).matrix[xZero+1][yZero];
    (*this).matrix[xZero+1][yZero] = 0;

    (*this).xZero = xZero+1;
}

void Slider::moveRight()
{
    (*this).matrix[xZero][yZero] = (*this).matrix[xZero][yZero-1];
    (*this).matrix[xZero][yZero-1] = 0;

    (*this).yZero = yZero-1;
}

void Slider::moveLeft()
{
    (*this).matrix[xZero][yZero] = (*this).matrix[xZero][yZero+1];
    (*this).matrix[xZero][yZero+1] = 0;

    (*this).yZero = yZero+1;
}

bool Slider::checkVictory()
{
    if(this->xZero != sliderlastelement || this->yZero != sliderlastelement) return false;

    for (short int i = 0; i < slidersize; i++)
    {
        for (short int j = 0; j < slidersize; j++)
        {
            if (i==sliderlastelement && j==sliderlastelement) return true;

            if (this->matrix[i][j] != i*slidersize + j + 1)
            {
                return false;
            }
        }
    }

    return true;
}