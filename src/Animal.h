#pragma once
#include <iostream>
#include <string>

using namespace std;

class Animal
{
    public:
        Animal(){};
        Animal(string nume, string specie, string rasa, string categorieDeProductie, int greutate, int varsta)
            : Nume(nume), Specie(specie), Rasa(rasa), CategorieDeProductie(categorieDeProductie), Greutate(greutate), Varsta(varsta) {}
        
        friend ostream& operator << (ostream& os, const Animal& a);
        friend istream& operator >> (istream& in, Animal& a);

    private:
        string Nume;
        string Specie;
        string Rasa;
        string CategorieDeProductie;
        int Greutate;
        int Varsta;
};