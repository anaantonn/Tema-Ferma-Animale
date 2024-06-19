#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Animal
{
    public:
        string Nume;
        string Specie;
        string Rasa;
        string CategorieDeProductie;
        int Greutate;
        int Varsta;

    Animal(){};
    Animal(string nume, string specie, string rasa, string categorieDeProductie, int greutate, int varsta)
        : Nume(nume), Specie(specie), Rasa(rasa), CategorieDeProductie(categorieDeProductie), Greutate(greutate), Varsta(varsta) {}
    
    friend ostream& operator << (ostream& os, const Animal& a);
    friend istream& operator >> (istream& in, Animal& a);

};


ostream& operator << (ostream& os, const Animal& a)
{
    os << "Nume: " << a.Nume << " " << "Specie: " << a.Specie << " " << "Categorie de productie: " << a.CategorieDeProductie << " " << "Greutate: " << a.Greutate << " "
    << "Varsta: " << a.Varsta << endl;

    return os;
}

istream& operator >> (istream& in, Animal& a)
{
    cout << "Nume: ";
    in >> a.Nume;
    cout << "Specie: ";
    in >> a.Specie;
    cout << "Rasa: ";
    in >> a.Rasa;
    cout << "Categorie de productie: ";
    in >> a.CategorieDeProductie;
    cout << "Greutate: ";
    in >> a.Greutate;
    cout << "Varsta: ";
    in >> a.Varsta;

    return in;
}

// Function to convert a string to lowercase
string toLowerCase(const string& str)
{
    string lowerStr = str;
    transform(lowerStr.begin(), lowerStr.end(), lowerStr.begin(), ::tolower);
    return lowerStr;
}

// Helper function to find an animal by name (case-insensitive)
vector<Animal>::iterator findAnimalByName(vector<Animal>& animals, const string& name)
{
    string lowerName = toLowerCase(name);
    return find_if(animals.begin(), animals.end(), [&lowerName](const Animal& a) { return toLowerCase(a.Nume) == lowerName; });
}


int showMenu()
{
    int number;
    cout << "Alegeti una dintre optiuni:" << endl;
    cout << "\t 1) Adaugati animal" << endl;
    cout << "\t 2) Afisati lista animalelor" << endl;
    cout << "\t 3) Editati detaliile unui animal" << endl;
    cout << "\t 4) Eliminati un animal" << endl;
    cout << "\t 5) Iesiti din aplicatie" << endl;
    cin >> number;
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
    if(animals.size() == 0)
        {
            cout << "Niciun animal intordus!" << endl;
            return;
        }
        
    for(Animal &a : animals) 
    {
        cout << a << endl;
    }
        
}



void changeAnimalDetails(vector<Animal>& animals)
{
    string animalDeCautat;
    Animal a;

    if(animals.size() == 0)
         {
             cout << "Niciun animal intordus!" << endl;
             return;
         }

    cout << "Introduceti numele animalului pentru care doriti sa faceti modificarea: ";
    cin >> animalDeCautat;
    auto it = findAnimalByName(animals, animalDeCautat);//auto it = find(animals.begin(), animals.end(), animalDeCautat); // cauta in vector dupa nume si pozitie
    if (it != animals.end())
    {
        int index = distance(animals.begin(), it); // calculeaza pozitia in functie de distanta de la inceputul vectorului pana la iterator
        cout << "Introduceti modificarile: ";
        cin >> a;
        *it = a;
    }
    else
        cout << "Animalul nu exista!" << endl;
}


void deleteAnimal(vector<Animal>& animals)
{
    string animalDeSters;

    if(animals.size() == 0)
         {
             cout << "Niciun animal intordus!" << endl;
             return;
         }
                        

    cout << "Introduceti numele animalului pe care doriti sa il stergeti: ";
    cin >> animalDeSters;
    auto itToDelete = findAnimalByName(animals, animalDeSters);
    if (itToDelete != animals.end())
         {
             animals.erase(itToDelete);
             cout << "Animalul a fost sters." << endl;
         }
    else
        cout << "Animalul nu a fost gasit." << endl;
}


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
