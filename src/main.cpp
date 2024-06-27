#include <iostream>
#include <vector>
#include "Functions.h"
#include "Animal.h"

using namespace std;

int main()
{
    vector<Animal> animals;
    do
    {
        cout << "Ferma contine " << animals.size() << " animale." << endl;
        switch(showMenu())
        {
            case 1:
                addNewAnimal(animals);
                break;
            case 2:        
                showEntireList(animals);                   
                break;
            case 3:                                        
                changeAnimalDetails(animals);
                break;          
            case 4:              
                deleteAnimal(animals);                    
                break;
            case 5:
                return 0;
            default:
                cout << "Va rog selectati o optiune valabila." << endl;
                break;
        }
    }
    while (true);
}