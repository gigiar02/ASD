#include <iostream>
using namespace std;
#include <fstream>
#include "lezione3.hpp"

/*
    Creato da Luigi il 30/12/2024
    Corso algoritmi e strutture dati

    Le librerie create contengono gli esercizi fatti in ogni lezione.

     -------------------------
    | Lezione 1 | lezione1.hpp| Data: 30/12/2024
    | Lezione 2 | lezione2.hpp| Data: 31/12/2024 Da non considerare poiché la mia salute mentale mi ha abbandonato
    | Lezione 3 | lezione3.hpp| Data: 07/12/2024
    |

*/


int main()
{
   linkeList operai;


   for(int i = 0; i < 50; i++)
   {

       string numero = to_string(i);
       string nome = "luigi";
       nome += numero;
       Impiegato *impiegato = new Impiegato(nome,i+200);
       operai.addImpiegato(impiegato);
       for(int j = 0; j < 5; j++)
       {
           Manager *manager = new Manager(nome,i+700,i*20);
           operai.addImpiegato(manager);
       }
   }
    operai.stampaImpiegati();
    return 0;
}
