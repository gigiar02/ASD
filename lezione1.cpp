#include "lezione1.hpp"
/*
    Lezione  1 slide 37 esercizio delle anfore
*/

//Metodi per la classe contenitore


//Ottieni la quantità di acqua nel tuo contenitore
int Contenitore::getQt()
{
    return this->qt;
}
//Versa nel contenitore lt di acqua
void Contenitore::versa(int lt)
{
    this->qt += lt;
}

//toglie l acqua dal contenitore
void Contenitore::togli(int lt)
{
    this->qt -= lt;
}


//Metodi per la classe anfora


//Restituisce la capacita massima dell'anfora
int Anfora::getCapacita()
{
    return capacita;
}
//Riempi l'anfora completamente
void Anfora::riempi()
{
    this->togli(this->getQt());
    this->versa(capacita);
}
//Svuota l'anfora completamente
void Anfora::svuota()
{
    this->togli(this->getQt());
}
//isPiena() isVuota() ???

//Sposta l'acqua nell'anfora passata come argomento
void Anfora::spostaContenuto(Anfora &B)
{
    //Considero la quantità da aggiungere a B
    int da_aggiungere = this->getQt() + B.getQt();
    //Se la quantità da aggiungere a B è maggiore della capacità di B
    if(da_aggiungere <= B.capacita)
    {
        B.versa(this->getQt());
        this->svuota();
    }else if(da_aggiungere > B.capacita)
    {
        //Togli ad A il contenuto che viene trasferito a B
        int da_togliere = B.capacita - B.getQt();
        this->togli(da_togliere);
        B.riempi();

    }

}
void std_stato(Anfora A,Anfora B)
{
    cout<<" A: "<<A.getQt()<<" B: "<<B.getQt()<<endl;
}
void risolviIndovinello()
{
    cout<<"Inizio Indovinello"<<endl;
    Anfora A(5);
    Anfora B(3);
    std_stato(A,B);
    A.riempi(); B.riempi();
    std_stato(A,B);
    B.svuota();
    std_stato(A,B);
    A.spostaContenuto(B);
    std_stato(A,B);
    B.svuota();
    std_stato(A,B);
    A.spostaContenuto(B);
    std_stato(A,B);
    A.riempi();
    std_stato(A,B);
    A.spostaContenuto(B);
    std_stato(A,B);

}





