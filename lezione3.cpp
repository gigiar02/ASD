#include "lezione3.hpp"

//Aggiungi un impiegato alla lista di impiegati
void linkeList::addImpiegato(Impiegato *impiegato)
{

    //Se la lista è vuota alla l'impiegato verrà aggiunto in testa
    if(this->testa == nullptr)
    {
        testa = impiegato;
        coda = testa;
    }else
    {
        //Inserisci l'impiegato alla fine della lista
        coda->setNext(impiegato);
        //Aggiorniamo la coda all'ultimo elemento della lista
        coda = coda->getNext();


    }

}

Impiegato* operator+(Impiegato imp1,Impiegato imp2)
{
    Impiegato *imp = new Impiegato("Tot",imp1.getSalario() + imp2.getSalario());
    return imp;
}

void linkeList::stampaImpiegati()
{
    //Parto dalla testa e stampo tutti gli impiegati
    Impiegato *imp = testa;
    //Impiegat fantoccio utile a memorizzare la somma totale
    Impiegato *fantoccio = new Impiegato("Fantoccio",0);
    int sum = 0;
    while(imp->getNext())
    {
        imp->getInfo();
        Impiegato imp_sum1("",imp->getSalario());
        imp = imp->getNext();
        if(imp != nullptr)
        {
            Impiegato imp_sum2("",imp->getSalario());
            fantoccio = imp_sum1 + imp_sum2;
            sum += fantoccio->getSalario();

        }

    }

    cout<<"Salario totale = "<<sum;
}



