using namespace std;
#include <iostream>
#include <string>
#include <fstream>
#include <vector>

#include "Slider.hpp"

Slider::Slider()
{
    srand (time(NULL));
    short int movements = rand() % 30 + 20;
    short int choosedMoviment = rand() % 4;

    readFromFile("s0.txt");

    for (short int i = 0; i < movements; i++)
    {
        switch (choosedMoviment)
        {
        case 0:
            if(movableDown()) moveDown();
            break;

        case 1:
            if(movableUp()) moveUp();
            break;

        case 2:
            if(movableLeft()) moveLeft();
            break;

        case 3:
            if(movableRight()) moveRight();
            break;
        
        default:
            if(movableRight()) moveRight();
            break;
        }

        choosedMoviment = rand() % 4;
    }
    
}

Slider::Slider(string filename)
{
    readFromFile(filename);
}

Slider::~Slider()
{
}

string Slider::toString()
{
    string aux="";
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

string Slider::serialize()
{
    string toBeReturned = "";
    for (size_t i = 0; i < slidersize; i++)
    {
        for (size_t j = 0; j < slidersize; j++)
        {
            toBeReturned += to_string(this->matrix[i][j]);
        }
        
    }

    return toBeReturned;
    
}

vector<short int> Slider::toVectorWithoutZero()
{
    vector<short int> _vector;

    for (size_t i = 0; i < slidersize; i++)
    {
        for (size_t j = 0; j < slidersize; j++)
        {
            _vector.push_back(this->matrix[i][j]);
        }
        
    }

    return _vector;
}

bool Slider::isSolvable()
{
    vector<short int> _vector = toVectorWithoutZero();

    int inv_count = 0; 
    for (int i = 0; i < sliderarea - 1; i++) 
        for (int j = i+1; j < sliderarea; j++) 
             if (_vector[j] && _vector[i] &&  _vector[i] > _vector[j]) 
                  inv_count++;

    return inv_count%2 == 0;
}

bool Slider::readFromFile(string filename)
{
    fstream in(inputpath + filename);

    if (!in) {
    cout << "Erro. Arquivo não encontrado\n";
    return false;
    }

    for (size_t i = 0; i < slidersize; i++) {
        for (size_t j = 0; j < slidersize; j++) {
            in >> this->matrix[i][j];
            if(this->matrix[i][j]==0) {xZero=i; yZero=j;}
        }
    }

    return true;
}