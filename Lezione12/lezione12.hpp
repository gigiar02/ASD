#include <iostream>
using namespace std;
#include <fstream>
#include "lezione16.hpp"
#include <sstream>


class Node
{
    //Data
    int dato;

    //Puntatori
    Node *father;
    Node *leftChild;
    Node *rightChild;

    //Costruttore
    public:
        Node(Node *father, Node *leftChild,Node *rightChild){this->father = father; this->leftChild = leftChild; this->rightChild = rightChild;}
        Node(){this->father = nullptr; this->leftChild = nullptr; this->rightChild = nullptr;}

    //Getters and Setters
    int getDato(){return dato;}
    Node* getLeftChild(){return leftChild;}
    Node* getRightChild(){return rightChild;}
    Node* getFather(){return father;}
    void setFather(Node* newFather){father = newFather;}
    void setLeftChild(Node* newChild){leftChild = newChild;}
    void setRightChild(Node* newChild){rightChild = newChild;}
    void setData(int newDato){dato = newDato;}
};


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
