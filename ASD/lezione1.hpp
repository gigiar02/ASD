#include <iostream>
using namespace std;

/*
    Esercizio delle anfore Lezione 1 slide 37
*/

class Contenitore
{
    private:
        //Memorizza la quantità d'acqua
        int qt;

    public:
        Contenitore(int qt){this->qt = qt;}
        void versa(int lt);
        void togli(int lt);
        int getQt();
};

class Anfora : public Contenitore
{
    private:
        int capacita;

    public:
        Anfora(int capacita) : Contenitore(0)
        {this->capacita = capacita;}
        int getCapacita();
        void riempi();
        void svuota();
        bool isVuota();
        bool isPiena();
        void spostaContenuto(Anfora &anfora);

};


void risolviIndovinello();

void std_stato(Anfora A,Anfora B);
