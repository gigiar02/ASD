/*
    Progettare ed implementare una lista (linked list) di
    impiegati di un'azienda. Un impiegato ha un nome ed un
    salario. Un manager è un impiegato cui viene corrisposto
    un bonus oltre al salario.

    1. Creare una lista di impiegati e stamparla a video
    sfruttando il principio del polimorfismo
    2. Implementare l'overload dell'operatore + in modo da
    sommare i salari di tutti gli impiegati.

*/

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

/*
    Definizione della classe impiegato
    che ha un nome, un salario e un puntatore
    ad un altro impiegato per andare a formare
    la linked list
*/
class Impiegato
{
    //Dati
    string Nome;
    int salario;
    //Punta all'impiegato successivo nella linked list
    Impiegato *next;

    //Costruttori
    public:
    Impiegato(){this->Nome = ""; this->salario = 0; this->next = nullptr;}
    Impiegato(string Nome){this->Nome = Nome; this->salario = 0; this->next = nullptr;}
    Impiegato(string Nome, int salario){this->Nome = Nome; this->salario = salario; this->next = nullptr;}
    Impiegato(string Nome, int salario,Impiegato *impiegato){this->Nome = Nome; this->salario = salario; this->next = impiegato;}

    //Metodi getter
    int getSalario(){return this->salario;}
    string getNome(){return this->Nome;}
    Impiegato* getNext(){return this->next;}
    //Metodi setter
    void setSalario(int salario){this->salario = salario;}
    void setNome(string Nome){this->Nome = Nome;}
    void setNext(Impiegato *collega){this->next = collega;}

    //Stampa le informazioni dell' impiegato
    virtual void getInfo(){cout<<" Nome: "<<Nome<<" Salario: "<<salario<<endl;}


};

//Definizione della classe Manager che è un impiegato ma ha anche un bonus
class Manager : public Impiegato
{
    //Dati
    float bonus;

    //Costruttori
    public:
    Manager(string Nome,int salario,int bonus) : Impiegato(Nome,salario){this->bonus = bonus;}

    //Metodi getter
    float getBonus(){return this->bonus;}

    //Metodi setter
    void setBonus(float bonus){this->bonus = bonus;}

    //Stampa le info del manager
     void getInfo(){cout<<" Nome: "<<this->getNome()<<" Salario: "<<this->getSalario()<<" Bonus: "<<bonus<<endl;}

};



class linkeList
{
    //Dati
    Impiegato *testa;
    Impiegato *coda;

    public:
    //Costruttori
    linkeList(){this->coda = nullptr; this->testa = nullptr;}

    //Aggiungi un impiegato
    void addImpiegato(Impiegato *impiegato);
    //Stampa la lista di impiegati
    void stampaImpiegati();

};


/*
 Definizione del main Se ne avrò voglia farò una funzione
 int main()
{
   linkeList operai;
   ifstream read("Impiegati.txt");
   string riga;
   if(!read)
   {

       cout<<"Non aperto correttamente"<<endl;
   }
   //leggo riga per riga
   getline(read,riga);
   //cout<<riga<<endl;
   while(getline(read,riga))
   {
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
*/
