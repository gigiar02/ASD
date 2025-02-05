
#include <iostream>
using namespace std;
#include <fstream>
#include <sstream>
//#include "lezione12.hpp"
#include "lezione13.hpp"

/*
    Creato da Luigi il 30/12/2024
    Corso algoritmi e strutture dati

    Le librerie create contengono gli esercizi fatti in ogni lezione.

     -------------------------
    | Lezione 1  | lezione1.hpp  | Data: 30/12/2024
    | Lezione 2  | lezione2.hpp  | Data: 31/12/2024 Da non considerare poiché la mia salute mentale mi ha abbandonato
    | Lezione 3  | lezione3.hpp  | Data: 07/12/2024
    | Lezione 12 | lezione12.hpp | Data: 24/01/2025 18:33
    | Lezione 13 | lezione13.hpp | Data: 03/02/2025 10:06
    | Lezione 16 | lezione16.hpp | Data: 10/1/2025 14:35 Problema dello zaino 0-1
    |

*/


int main()
{
   vector<int> h = {100,10,120,9,8};

   RbTree<RbNode> *tree = new RbTree<RbNode>();
   tree = CreateRbTree(h);


    return 0;
}

