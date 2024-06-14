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

};


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

// Function to convert a string to lowercase
string toLowerCase(const string& str)
{
    string lowerStr = str;
    transform(lowerStr.begin(), lowerStr.end(), lowerStr.begin(), ::tolower);
    return lowerStr;
}


// Helper function to find an animal by name
//vector<Animal>::iterator findAnimalByName(vector<Animal>& animals, const string& name)
//{
//return find_if(animals.begin(), animals.end(), [&name](const Animal& a) { return a.Nume == name; });
//}

// Helper function to find an animal by name (case-insensitive)
vector<Animal>::iterator findAnimalByName(vector<Animal>& animals, const string& name)
{
    string lowerName = toLowerCase(name);
    return find_if(animals.begin(), animals.end(), [&lowerName](const Animal& a) { return toLowerCase(a.Nume) == lowerName; });
}

int main()
{
    vector<Animal> animals;
    int choice;
    Animal a;
    string animalDeCautat;
    string animalDeSters;
    do
    {
        cout << "Ferma contine " << animals.size() << " animale." << endl;
        choice = showMenu();
        switch(choice)
        {
            case 1:
            {
                cout << "Ati ales sa adaugati un animal nou. Va rugam introduceti urmatoarele detalii: " << endl;
                cout << "Nume: ";
                cin >> a.Nume;
                cout << "Specie: ";
                cin >> a.Specie;
                cout << "Rasa: ";
                cin >> a.Rasa;
                cout << "Categorie de productie: ";
                cin >> a.CategorieDeProductie;
                cout << "Greutate: ";
                cin >> a.Greutate;
                cout << "Varsta: ";
                cin >> a.Varsta;

                animals.push_back(a);
            }
            break;

            case 2: // Afiseaza intreaga lista a animalelor
                {
                    if(animals.size() != 0)
                    {
                        for(int i = 0; i < animals.size(); i ++)
                        cout << "Nume: " << animals[i].Nume << " " << "Specie: " << animals[i].Specie << " " << "Categorie de productie: " << animals[i].CategorieDeProductie
                        << " " << "Greutate: " << animals[i].Greutate << " " << "Varsta: " << animals[i].Varsta << endl;
                    }
                    else
                        cout << "Niciun animal intordus!" << endl;

            break;
                }

            case 3: // Modifica detaliile unui animal
                {
                     if(animals.size() != 0)
                    {
                        cout << "Introduceti numele animalului pentru care doriti sa faceti modificarea: ";
                        cin >> animalDeCautat;
                        auto it = findAnimalByName(animals, animalDeCautat);//auto it = find(animals.begin(), animals.end(), animalDeCautat); // cauta in vector dupa nume si pozitie
                        if (it != animals.end())
                        {
                            int index = distance(animals.begin(), it); // calculeaza pozitia in functie de distanta de la inceputul vectorului pana la iterator
                            string nume, specie, rasa, categoriedeproductie;
                            int varsta, greutate;
                            cout << "Introduceti modificarile: ";
                            cout << "Nume: ";
                            cin >> nume;
                            cout << "Specie: ";
                            cin >> specie;
                            cout << "Rasa: ";
                            cin >> rasa;
                            cout << "Categorie de productie: ";
                            cin >> categoriedeproductie;
                            cout << "Greutate: ";
                            cin >> greutate;
                            cout << "Varsta: ";
                            cin >> varsta;

                            *it = Animal(nume, specie, rasa, categoriedeproductie, greutate, varsta);

                        }
                        else
                            cout << "Animalul nu exista!" << endl;
                    }

                    else
                        cout << "Niciun animal intordus!" << endl;

                }
            break;

            case 4: //  sterge un element din lista
                {
                    if(animals.size() != 0)
                    {
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
                    else
                        cout << "Niciun animal intordus!" << endl;

                }
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
