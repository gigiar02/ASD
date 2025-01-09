#include <iostream>
using namespace std;
#include <fstream>
#include "lezione3.hpp"
#include <sstream>

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
   ifstream read("Impiegati.txt");
   string riga;
   if(!read)
   {
       cout<<"Aperto non"<<endl;
   }
   //leggo riga per riga
   getline(read,riga);
   //cout<<riga<<endl;
   while(getline(read,riga))
   {
        cout<<riga<<endl;
        //Elaborazione dell'impiegato
        istringstream stream(riga);
        string word;
        int bonus = -1;
        string Nome;
        int salario;
        int indice = 0;
        //Estrazione di ogni parola seaparata da uno spazio Esempio: 0 | Luigi | 300 | 200
        while(stream >> word)
        {
            cout<<"Parola: "<<word<<endl;
                switch (indice) {
                    case 0:
                        //Non ci serve l' informazione (Numero impiegato)
                        indice = indice + 1;
                        break;
                    case 1:

                        indice = indice + 1;
                        break;
                    case 2:
                        //Nome dell'impiegato
                        indice = indice + 1;
                        Nome = word;
                        break;
                    case 3:
                        indice = indice + 1;
                        break;
                    case 4:
                        //Salario dell'impiegato
                        indice = indice + 1;
                        salario = stoi(word);
                        break;
                    case 5:
                        indice = indice + 1;
                        break;
                    case 6:
                        //Nel caso dei manager c'è da considerare anche il bonus
                        bonus = stoi(word);


            }
        }
        //cout<<"Nome: "<<Nome<<" Salario: "<<salario<<" Bonus: "<<bonus<<endl;
        if(bonus != -1)
        {
            Manager *manager = new Manager(Nome,salario,bonus);
            operai.addImpiegato(manager);
            cout<<"Bonus"<<bonus<<endl;
        }else
        {
            Impiegato *imp = new Impiegato(Nome,salario);
            operai.addImpiegato(imp);
        }
        indice = 0;
        //operai.addImpiegato();
   }

   read.close();
   operai.stampaImpiegati();
   //Estrazione impiegati/Manager

   /*
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
    */
    return 0;
}
