#include <iostream>
using namespace std;
#include <vector>

class Object
{
    public:
        //Dati
        int value;
        float weight;

        //Costruttori
        Object(int V,float Weight)
        {
        value = V;
        this->weight = Weight;
        }

};

void stampaMatrice(vector<vector<int>> c,int w);
class Zaino
{
    public:
        //Variabili interne
        int totalCapacity;
        vector<Object> object;

        //Costruttori
        Zaino(int W,vector<Object> oggetti){ totalCapacity = W; object = oggetti;  }

        //Metodi
        //Aggiungi un oggetto
        //Elimina n oggetti che rispettano dei filtri
        //Risolve il problema dello zaino 0-1 e restituisce l'insieme degli elementi inclusi.
        vector<Object> problemaZaino01();
        vector<Object> problemaZainoMin01(int G);



};




