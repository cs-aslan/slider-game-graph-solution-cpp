using namespace std;
#include <iostream>

#include "constants.hpp"
#include "class/Slider/Slider.hpp"
#include "class/SliderGraph/SliderGraph.hpp"

void showMenu()
{
    cout << "-------------------------------------------------------------\n";
    cout << "-        TP de Grafos - solucionador do N-puzzle            -\n";
    cout << "-------------------------------------------------------------\n";
    cout << "-Selecione uma opção:\n";
    cout << "1 - Mostrar slider em memória;\n";
    cout << "2 - Criar slider aleatório;\n";
    cout << "3 - Ler de um arquivo;\n";
    cout << "4 - Achar o melhor caminho por busca em largura;\n";
    cout << "5 - Achar o melhor caminho por busca em profundidade;\n";
    cout << "9 - Sair\n";
    cout << "-------------------------------------------------------------\n";
}

void reShowMenu()
{
    cout << "--- Digite 0 para mostrar o menu novamente -------------------\n";
}

int main(int argc, char const *argv[])
{
    SliderGraph * _sliderGraph = new SliderGraph();
    int option;
    string filename;

    showMenu();

    while (true)
    {
        cin >> option;

        if(option==0)
        {
            showMenu();
        }

        else if(option==1)
        {
            cout << _sliderGraph->toString();
        }
        
        else if(option==2) 
        {
            _sliderGraph = new SliderGraph();

            cout << "Slider gerado!\n";
            cout << _sliderGraph->toString();
        } 
        
        else if (option==3) 
        {
            cout << "Digite o nome do arquivo. Ele deve estar na pasta input\n";

            cin >> filename;
            _sliderGraph = new SliderGraph(filename);

            cout << "Slider gerado!\n";
            cout << _sliderGraph->toString();
        } 
        
        else if (option==4) 
        {
            if(!_sliderGraph->isSolvable()) {
                cout << "Slider sem solucao!\n";
            } else {
                cout << _sliderGraph->widhtSearch();
                _sliderGraph->trimTree();
            }

        } 
        
        else if (option==5) 
        {
            if(!_sliderGraph->isSolvable()) {
                cout << "Slider sem solucao!\n";
            } else {
                cout << _sliderGraph->depthSearch();
                _sliderGraph->trimTree();
            }

        } 
        
        else if (option==9) 
        {

            cout << "Obrigado!!\n";
            return 0;

        }
    }
    
    return 0;
    
}
