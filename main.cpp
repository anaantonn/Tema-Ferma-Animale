#include <iostream>
#include <vector>
#include "Functions.h"
#include "Animal.h"
#include "Functions.cpp"

using namespace std;


int main()
{
    vector<Animal> animals;
    int choice;

    do
    {
        cout << "Ferma contine " << animals.size() << " animale." << endl;
        choice = showMenu();
        switch(choice)
        {
            case 1:
                addNewAnimal(animals);
                break;

            case 2: // Afiseaza intreaga lista a animalelor
                
                showEntireList(animals);                   
                break;

            case 3: // Modifica detaliile unui animal
                                         
                changeAnimalDetails(animals);
                break;
            

            case 4: //  sterge un element din lista
                
                deleteAnimal(animals);                    
                break;
            

            case 5:
                cout << "Iesire din aplicatie." << endl;
                break;

            default:
                cout << "Va rog selectati o optiune valabila." << endl;
                break;


        }

    }
    while (choice != 5);


    return 0;

}
