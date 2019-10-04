using namespace std;
#include <iostream>
#include <string>
#include <queue> 
#include <stack>

#include "../Slider/Slider.hpp"
#include "SliderGraph.hpp"
#include "SliderMovementType.hpp"

SliderGraph::SliderGraph()
{
    nullfillChildren();
    this->moved = original;

    this->father = NULL;
    this->level = 0;
}

SliderGraph::SliderGraph(string filename):Slider(filename)
{
    nullfillChildren();
    this->moved = original;

    this->father = NULL;
    this->level = 0;
}

SliderGraph::~SliderGraph()
{
    if(this->down != NULL) this->down->~SliderGraph();
    if(this->up != NULL) this->up->~SliderGraph();
    if(this->left != NULL) this->left->~SliderGraph();
    if(this->right != NULL) this->right->~SliderGraph();
}

void SliderGraph::nullfillChildren()
{
    this->down = NULL;
    this->up = NULL;
    this->left = NULL;
    this->right = NULL;
}

string SliderGraph::toString()
{
    // cout << this->down << "- down\n";
    // cout << this->up << "- up\n";
    // cout << this->left << "- left\n";
    // cout << this->right << "- right\n";

    return "Nível- " + to_string(this->level) + "\nPai- " + to_string((uintptr_t)this->father) + "\n" + SliderMovementTypeToString(this->moved) + "\n" + Slider::toString();
}

string SliderGraph::toStringFullTree()
{
    queue<SliderGraph*> _queue;
    string toBeReturned = "";

    _queue.push(this);
    while (!_queue.empty())
    {
        if(_queue.front()->up != NULL) _queue.push(_queue.front()->up);
        if(_queue.front()->down != NULL) _queue.push(_queue.front()->down);
        if(_queue.front()->left != NULL) _queue.push(_queue.front()->left);
        if(_queue.front()->right != NULL) _queue.push(_queue.front()->right);

        toBeReturned += _queue.front()->toString() + '\n';
        _queue.pop();
    }
    
    return toBeReturned;
}

void SliderGraph::createChildren()
{
    short int childrenLevel = this->level + 1;

    if(this->moved != movedUp && Slider::movableDown())
    {
        this->down = new SliderGraph(*this);
        this->down->moveDown();
        this->down->moved = movedDown;
        
        this->down->level = childrenLevel;
        this->down->father = this;
    }

    if(this->moved != movedDown && Slider::movableUp())
    {
        this->up =  new SliderGraph(*this);
        this->up->moveUp();
        this->up->moved = movedUp;

        this->up->level = childrenLevel;
        this->up->father = this;

        this->up->nullfillChildren();
    }

    if(this->moved != movedLeft && Slider::movableRight())
    {
        this->right =  new SliderGraph(*this);
        this->right->moveRight();
        this->right->moved = movedRight;

        this->right->level = childrenLevel;
        this->right->father = this;

        this->right->nullfillChildren();
    }

    if(this->moved != movedRight && Slider::movableLeft())
    {
        this->left =  new SliderGraph(*this);
        this->left->moveLeft();
        this->left->moved = movedLeft;

        this->left->level = childrenLevel;
        this->left->father = this;

        this->left->nullfillChildren();
    }
}

string SliderGraph::widhtSearch()
{
    queue<SliderGraph*> _queue;
    int count = 0;

    _queue.push(this);
    while (!_queue.empty() && count<widhtsearchmaxnodes)
    {

        if(_queue.front()->checkVictory()) // Victory condition
        {
            return _queue.front()->pathToRoot();
        }

        _queue.front()->createChildren();

        if(_queue.front()->up != NULL) _queue.push(_queue.front()->up);
        if(_queue.front()->down != NULL) _queue.push(_queue.front()->down);
        if(_queue.front()->left != NULL) _queue.push(_queue.front()->left);
        if(_queue.front()->right != NULL) _queue.push(_queue.front()->right);

        _queue.pop();
        count++;
    }

    return "Impossível determinar solução!\n";
}

string SliderGraph::pathToRoot()
{
    SliderGraph * swap = this;
    stack<SliderMovementType> _stack;
    string toBeReturned = "";
    int steps = 0;

    while(swap->father!=NULL)
    {
        _stack.push(swap->moved);
        swap = swap->father;
    }

    while(!_stack.empty())
    {
        toBeReturned += SliderMovementTypeToString(_stack.top()) + "\n";
        _stack.pop();
        steps++;
    }

    return toBeReturned + "Número de passos foi de " + to_string(steps) + "\n";
}

void SliderGraph::depthSearchRecursive(SliderGraph ** bestSolution, int recursions, int minimumPath)
{
    int newMinimumPath = minimumPath;

    if(this->level>minimumPath || recursions>dephtsearchmaxrecursion) {
        return;
    }

    if(this->checkVictory()) {
        if((*bestSolution) == NULL) (*bestSolution) = this;
        
        if (this->level<(**bestSolution).level) {
            newMinimumPath = (**bestSolution).level;
            (*bestSolution) = this;
            cout << "** Vitória com " << to_string((**bestSolution).level) << " movimentos\n";
        }
        return;
    }

    createChildren();

    if(this->down != NULL) this->down->depthSearchRecursive(bestSolution, (recursions+1), newMinimumPath);
    if(this->up != NULL) this->up->depthSearchRecursive(bestSolution, (recursions+1), newMinimumPath);
    if(this->left != NULL) this->left->depthSearchRecursive(bestSolution, (recursions+1), newMinimumPath);
    if(this->right != NULL) this->right->depthSearchRecursive(bestSolution, (recursions+1), newMinimumPath);
}

string SliderGraph::depthSearch()
{
    SliderGraph* bestSolution = NULL;

    depthSearchRecursive(&bestSolution, 0, 9999999);

    if(bestSolution==NULL) return "Impossível determinar solução!\n";
    
    return bestSolution->pathToRoot();
}

void SliderGraph::trimTree()
{
    this->down->~SliderGraph();
    this->up->~SliderGraph();
    this->left->~SliderGraph();
    this->right->~SliderGraph();

    nullfillChildren();
}