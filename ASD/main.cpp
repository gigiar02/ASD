#include <iostream>
using namespace std;
#include <fstream>
#include "lezione16.hpp"
#include <sstream>

/*
    Creato da Luigi il 30/12/2024
    Corso algoritmi e strutture dati

    Le librerie create contengono gli esercizi fatti in ogni lezione.

     -------------------------
    | Lezione 1  | lezione1.hpp  | Data: 30/12/2024
    | Lezione 2  | lezione2.hpp  | Data: 31/12/2024 Da non considerare poiché la mia salute mentale mi ha abbandonato
    | Lezione 3  | lezione3.hpp  | Data: 07/12/2024
    | Lezione 16 | lezione16.hpp | Data: 10/1/2025 14:35 Problema dello zaino 0-1
    |

*/


int main()
{
    vector<Object> libri;
    //libri.push_back(Object(0,0));
    libri.push_back(Object(5,2));
    libri.push_back(Object(4,3));
    libri.push_back(Object(5,4));
    libri.push_back(Object(6,2));
    int W = 5;
    Zaino zaino(W,libri);
    vector<Object> oggettiInclusi;
    oggettiInclusi = zaino.problemaZainoMin01(9);
    //cout<<"Oggetti = "<<oggettiInclusi.size();
    for(int i = 0; i < oggettiInclusi.size();i++)
    {
        cout<<i<<" Weight "<<oggettiInclusi[i].weight<<" Value "<<oggettiInclusi[i].value<<endl;
    }
    vector<Object> insiemeMinimo;



    return 0;
}
