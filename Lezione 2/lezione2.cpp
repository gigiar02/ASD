#include "lezione2.hpp"
#include <iostream>
#include <fstream>
#include <vector>

/*
  Creato da Luigi il 31/12/2024 ore 20:45
*/

//Crea un file con il nome passato come argomento e ne restituisce il puntatore
fstream creaFile(string nome,bool lettura,bool scrittura)
{
    fstream file;
    if(lettura && scrittura)
    {
        file.open(nome,ios::in | ios::out);
    }else if(lettura)
    {
        file.open(nome,ios::in);
    }else if(scrittura)
    {
        file.open(nome,ios::out);
    }
    return file;

}
bool contrallacorrettezza(string F_traccia,string F_soluzione)
{
    if(controllaRipetizioni(F_traccia,F_soluzione))
    {
        fstream traccia,soluzione;
        traccia = creaFile(F_traccia,true,true);
        soluzione = creaFile(F_soluzione,true,true);
        string s;
        string t;
        string I_numsx,I_numdx;
        string S_numsx,S_numdx;
        S_numsx = "";
        int k = 0;
        while(getline(soluzione,s))
        {


        }
    return true;
}
return false;
}
bool controllaversi(string F_traccia,string F_soluzione)
{
    vector<string> rows;
    string currentRowSolution;
    string currentRowTrace;
    fstream traccia,soluzione;
    traccia = creaFile(F_traccia,true,true);
    soluzione = creaFile(F_soluzione,true,true);

    if(!traccia || !soluzione)
    {
        cout<<"Uno dei due file non è stato aperto correttamente"<<endl;
        return false;
    }
    while(getline(soluzione,currentRowSolution))
    {
        //Estraggo la riga della traccia e della soluzione corrente
        currentRowSolution = estrapolazioneStringa(currentRowSolution);
        getline(traccia,currentRowTrace);
        cout<<"currentrowsolution: "<<currentRowSolution<<"trace:  "<<currentRowTrace<<endl;
        if(currentRowSolution != currentRowTrace)
        {
            return false;
        }
    }

    return true;
}

string estrapolazioneStringa(string s)
{
    cout<<"La stringa è lunga: "<<s.size();
    string sum = "";
    for(int i = 0; i < s.size(); i++)
    {
        if(s[i] == '<' || s[i] == '>')
        {
            sum += s[i];
        }
    }
    return sum;
}
bool controllaRipetizioni(string F_traccia,string F_soluzione)
{
   if(controllaversi(F_traccia,F_soluzione))
   {
       fstream traccia,soluzione;
       traccia = creaFile(F_traccia,true,true);
       soluzione = creaFile(F_soluzione,true,true);
       string s;
        while(getline(soluzione,s))
        {
            string t;
            getline(traccia,t);
            int massimo = s.size();
            bool ripetizioni[massimo];
            for(int i = 0; i < massimo;i++)
            {
                ripetizioni[i] = false;
            }
            //Controllo che non ci siano ripetizioni
            string S_sum;
            int I_sum;
            for(int i = 0; i < s.size(); i++)
            {
                if(s[i] == '<' || s[i] == '>')
                {
                    I_sum = stoi(S_sum);
                    cout<<"i = "<<i<<"i_sum = "<<I_sum<<"Massimo "<<massimo<<endl;
                    if(ripetizioni[I_sum] == true || I_sum <= massimo)
                    {
                        cout<<"i = "<<i<<"i_sum = "<<I_sum<<endl;
                        return false;
                    }else
                    {
                        ripetizioni[I_sum] = true;
                    }
                    I_sum = 0;
                    S_sum = "";
                }else
                {
                    S_sum += s[i];
                }
            }
        }
   }else
   {
       return false;
   }
   return true;
}



