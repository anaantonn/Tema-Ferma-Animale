#include "Functions.h"
#include <algorithm>
#include <vector>

using namespace std;

int showMenu()
{
    int number;

    cout << "Alegeti una dintre optiuni:" << endl;
    cout << "\t 1) Adaugati animal" << endl;
    cout << "\t 2) Afisati lista animalelor" << endl;
    cout << "\t 3) Editati detaliile unui animal" << endl;
    cout << "\t 4) Eliminati un animal" << endl;
    cout << "\t 5) Iesiti din aplicatie" << endl;
    cout << "Selectie: ";
    cin >> number;
    system("clear");

    return number;
}

void addNewAnimal(vector<Animal>& animals)
{
    Animal a;

    cout << "Ati ales sa adaugati un animal nou. Va rugam introduceti urmatoarele detalii: " << endl;
    cin >> a;

    animals.push_back(a);    
}

void showEntireList(vector<Animal>& animals)
{
    for(int i = 0; i < animals.size(); i++)
    {
        cout << i+1 << ")" << animals[i] << endl;
    }
}

void changeAnimalDetails(vector<Animal>& animals)
{   
    if(animals.size() == 0)
    {
        cout << "Niciun animal intordus!" << endl;
        return;
    }

    Animal updated;
    int indexToUpdate;

    showEntireList(animals);

    cout << "Introduceti numarul corespunzator animalului pentru care doriti sa faceti modificarile: ";
    cin >> indexToUpdate;

    if (indexToUpdate > 0 && indexToUpdate <= animals.size())
    {
        cout << "Introduceti modificarile: " << endl;
        cin >> updated;
        animals[indexToUpdate-1] = updated;
    }
    else
    {
        cout << "Animalul nu a fost gasit." << endl;
    }
}

void deleteAnimal(vector<Animal>& animals)
{   

    if(animals.size() == 0)
    {
        cout << "Niciun animal intordus!" << endl;
        return;
    }

    int indexToDelete;

    showEntireList(animals);

    cout << "Introduceti numarul corespunzator animalului pe care doriti sa il eliminati din lista: ";
    cin >> indexToDelete;

    if (indexToDelete > 0 && indexToDelete <= animals.size())
    {
        animals.erase(animals.begin()+indexToDelete-1);
        cout << "Animalul a fost sters." << endl;
    }
    else
    {
        cout << "Animalul nu a fost gasit." << endl;
    }
}