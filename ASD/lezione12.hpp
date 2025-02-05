#ifndef LEZIONE12_HPP
#define LEZIONE12_HPP
#undef byte
#include <iostream>
using namespace std;
//#include <fstream>
//#include <sstream>
#include <string>
#include <vector>
#define Template template <typename T>
/*
void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
*/
class Data
{
    public:
    int key;
    Data(int key) {this->key = key;}
    Data(){key = 10;}
};

class DataNode
{
    public:
       // string ciao;
};

Template
class Node
{


    //Dati interni del nodo
    T data;

    //Collegamenti del nodo
    Node* father;
    Node* left;
    Node* right;

    public:
    Node(){left = nullptr; right = nullptr; father = nullptr;}
    //Ottieni i dati del nodo
    T getData() {return data;}

    //Modifica o ottieni i dati del nodo
    void setData(T data) { this->data = data;}
    Node* getLeft() {return left;}
    Node* getRight() {return right;}
    Node* getFather() {return father;}

    void  setRight(Node* dx) {right = dx;}
    void  setLeft(Node* sx) {left = sx;}
    void  setFather(Node *f) {father = f;}

};

Template
class ABR
{
    //Radice
    Node<T>* root;

    public:
        ABR(){root = nullptr;}

        //Inserisci un nodo nell'albero
        void insertTree(T data);
        void insertTree(Node<T>* data);
        //Stampa l'albero
        void recursiveStampa(Node<T>* root,bool sx,bool dx,int i,int N);
        void stampa();
    protected:
        Node<T>* getRoot() {return root;}


};

//Crea e restituisce un ABR composto dai nodi inseriti man mano, nell'ordine in cui sono nel vettore passato come input
ABR<Data>* CreateABR(vector<int> h);


/*
class ABR
{
    //Dati
    Node* root;

    //Costruttore
    public:
        ABR(){root = nullptr;}

    //Metodi
        void addNode(int x);
        void addNode(Node* newNode);
        Node* getRoot(){return root;}
        //Visita root -> sx -> dx VisitaAnticipata
        void visita();
        void coutVisitaAnticipata(Node*root);
        //Trova il successore e il predecessore
        Node* findSuccessor(Node* x);
        Node* findPredecessor(Node* x);
        void deleteNode(Node* x);
        //Trova il minimo ed il massimo
        Node* searchMinimum();
        Node* searchMaximum();
        //Ricerca una chiave nell'albero. Restituisce il nodo contenente la chiave se la trova
        Node* recursiveKeySearch(Node* start,int key);
        Node* keySearch(int key);
};
//Algoritmi che si servono dell'utilizzo di un ABR
int sommafoglie(ABR* abr);
void recursiveSommaFoglie(ABR* abr,Node* current,vector<int>& foglie);
void searchKminimum(ABR *abr);
*/
#include "lezione12.tpp"  // Inclusione del file di implementazione

#endif // LEZIONE12_HPP

