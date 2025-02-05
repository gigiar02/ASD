#include "lezione12.hpp"
//Colori che un nodo può assumere
enum Color
{
    RED,
    BLACK,
};
//Correzione della famiglia. Ristabilisce i ruoli
Template
void familyCorrection(Node<T>* node,Node<T>* &father,Node<T>* &grandPa);
Template
void LEFT_ROTATE(Node<T>* &x,Node<T>* &root);
//Nodo utilizzato dai red and black
class RbNode : public Data
{
    private:
    //Colore del nodo
     Color color;

    public:
     //Il costruttore accetta il colore con cui sarà inizializzato il nodo e la chiave del nodo
     RbNode(Color color,int key) : Data(key) {this->color = color;}
     //Costruttore vuoto
     RbNode() : Data(0) {this->color =RED;}
     RbNode(int key) : Data(key) {this->color =RED;}

     //Imposta il colore del nodo
     void setColor(Color color) {this->color = color;}
     Color getColor() {return color;}


};

//Classe template che fornisce i metodi per utilizzare un albero red and black
Template
class RbTree : public ABR<T>
{
    public:
        RbTree() : ABR<T>() {}

        //Operazione di inserimento
        void rbInsert(Node<T>* node);
        //Popola l'albero con nodi predefiniti
        void popola();
};

//Crea un albero red and black
RbTree<RbNode>* CreateRbTree(vector<int> h);

#include "lezione13.tpp"
