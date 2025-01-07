#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

//Crea un file con il nome passato come argomento e ne restituisce il puntatore
fstream creaFile(string nome,bool scrittura,bool lettura);
bool controllaRipetizioni(string F_traccia,string F_soluzione);

//Dati in inpur due file, controlla che ad ogni riga i segni siano uguali(rispetta i versi)
bool contrallacorrettezza(string traccia,string soluzione);

string estrapolazioneStringa(string s);
