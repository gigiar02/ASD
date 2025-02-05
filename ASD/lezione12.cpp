#include "lezione12.hpp"

ABR<Data>* CreateABR(vector<int> inserimenti)
{
    //Creo un nuovo ABR basa su nodi di tipo DATA
    ABR<Data>* abr = new ABR<Data>();
    for(int i = 0; i < inserimenti.size(); i++)
    {
        //Creo un nuovo Data
        Data data(inserimenti[i]);
        //Inserisco il nodo
        abr->insertTree(data);
    }
    return abr;
}










/*
Template
void ABR<T>::insertTree(T x)
{
    //Creo il nuovo nodo con valore x
    Node<T>* newNode = new Node<T>();
    newNode->setData(x);

    //Creo un nodo  contenente la radice
    Node<T>* y = root;
    //Conterrà di volta in volta un nodo all'interno dell'albero
    Node<T>* temp = nullptr;
    //Cerco il posto in cui inserire il nodo
    while(y != nullptr)
    {
        temp = y;

        //Cerca a destra
        if(x > y->getDato())
        {
            y = y->getRightChild();
        }else
        //Cerca a sinistra
        {
            y = y->getLeftChild();
        }

    }
    if(root == nullptr)
    {
        root = newNode;
    }else
    {
        newNode->setFather(temp);
        if(x > temp->getDato())
        {
            temp->setRightChild(newNode);

        }else
        {
            temp->setLeftChild(newNode);
        }
    }
}
*/
/*
void ABR::visita()
{
    cout<<"Inizio visita anticipata: root -> sx -> dx"<<endl;
    coutVisitaAnticipata(root);
}
void ABR::coutVisitaAnticipata(Node* root)
{
    if(root != nullptr)
    {
        cout<<" Dato = "<<root->getDato()<<endl;
        Node* left = new Node();
        if((left = root->getLeftChild())!= nullptr)
        {
            coutVisitaAnticipata(left);
        }
        Node* right = new Node();
        if((right = root->getRightChild())!= nullptr)
        {
            coutVisitaAnticipata(right);
        }

    }
}
void ABR::addNode(int x)
{
    //Creo il nuovo nodo con valore x
    Node* newNode = new Node();
    newNode->setData(x);
    //Creo un nodo  contenente la radice
    Node* y = root;
    //Conterrà di volta in volta un nodo all'interno dell'albero
    Node* temp = nullptr;
    //Cerco il posto in cui inserire il nodo
    while(y != nullptr)
    {
        temp = y;
        //Cerca a destra
        if(x > y->getDato())
        {
            y = y->getRightChild();
        }else
        //Cerca a sinistra
        {
            y = y->getLeftChild();
        }
    }
    if(root == nullptr)
    {
        root = newNode;
    }else
    {
        newNode->setFather(temp);
        if(x > temp->getDato())
        {
            temp->setRightChild(newNode);

        }else
        {
            temp->setLeftChild(newNode);
        }
    }



}
//IL successore di un nodo x è il piu piccolo tra i piu grandi
Node* ABR::findSuccessor(Node* x)
{
    if(!x || !x->getRightChild())
    {
        return nullptr;
    }
    Node* y = x->getRightChild();
    //Cerco il piu piccolo tra i piu grandi
    while(y->getLeftChild())
    {
        y = y->getLeftChild();
    }
    return y;
}
//Il predecessore di un nodo x è il piu grande tra i piu piccoli
Node* ABR::findPredecessor(Node* x)
{
    if(!x || !x->getLeftChild())
    {
        return nullptr;
    }
    Node* y = x->getLeftChild();
    //Cerco il piu grande tra i piu piccoli
    while(y->getRightChild())
    {
        y = y->getRightChild();
    }
    return y;
}
void ABR::addNode(Node* newNode)
{
    int x = newNode->getDato();
    //Creo un nodo  contenente la radice
    Node* y = root;
    //Conterrà di volta in volta un nodo all'interno dell'albero
    Node* temp = nullptr;
    //Cerco il posto in cui inserire il nodo
    while(y != nullptr)
    {
        temp = y;
        //Cerca a destra
        if(x > y->getDato())
        {
            y = y->getRightChild();
        }else
        //Cerca a sinistra
        {
            y = y->getLeftChild();
        }
    }
    if(root == nullptr)
    {
        root = newNode;
    }else
    {
        newNode->setFather(temp);
        if(x > temp->getDato())
        {
            temp->setRightChild(newNode);

        }else
        {
            temp->setLeftChild(newNode);
        }
    }



}
//Elimina un nodo dall'albero
void ABR::deleteNode(Node* x)
{
    Node* p = x->getFather();
    Node* sx = x->getLeftChild();
    Node* dx = x->getRightChild();
    //Se il nodo è vuoto o non ha figli
    if(!x || (!sx && !dx))
    {
        return;
    }
    //il nodo ha un solo figlio
    if(sx && !dx)
    {
        //il figlio sinistro diventa figlio del padre dell' ex nodo x
        sx->setFather(p);
        if(p->getLeftChild() == x)
        {
            p->setLeftChild(sx);
        }else if(p->getRightChild() == x)
        {
            p->setRightChild(sx);
        }


    }else if(!sx && dx)
    {
        //il figlio destro diventa figlio del padre dell' ex nodo x
        dx->setFather(p);
        if(p->getLeftChild() == x)
        {
            p->setLeftChild(dx);
        }else if(p->getRightChild() == x)
        {
            p->setRightChild(dx);
        }

    }
    //Il nodo ha sia figlio sx che dx
    else
    {
        //Trova il successore
        Node* y = findSuccessor(x);
        if(y->getRightChild())
        {
            cout<<"successor ="<<y->getDato()<<endl;
            deleteNode(y);
        }
        y->setFather(p);
        y->setLeftChild(sx);
        y->setRightChild(dx);
        sx->setFather(y);
        dx->setFather(y);
        if(p->getLeftChild() == x)
        {
            p->setLeftChild(y);

        }else
        {
            p->setRightChild(y);
        }
        delete x;
    }
}

Node* ABR::searchMaximum()
{
    Node* x = root;
    //Scorro l'albero completamente a destra in modo tale da prende sempre i valori piu grandi
    while(x->getRightChild())
    {
        x = x->getRightChild();
    }
    return x;

}

Node* ABR::searchMinimum()
{
    Node* x = root;
    //Scorro l'albero completamente a sinistra in modo tale da prendere sempre i valori piu piccoli
    while(x->getRightChild())
    {
        x = x->getLeftChild();
    }
    return x;

}

//Ricerca una chiave all'interno del ABR
Node* ABR::recursiveKeySearch(Node* start,int key)
{
    if(!start)
    {
        return start;
    }
    if(start->getDato() == key)
    {
        return start;
    }
    //Ciò significa che devo cercare a sinistra
    if(start->getDato() > key)
    {
        return recursiveKeySearch(start->getLeftChild(),key);
    //Altrimenti la chiave è maggiore e quindi devo ricercare a destra
    }else
    {
        return recursiveKeySearch(start->getRightChild(),key);
    }
}
Node* ABR::keySearch(int key)
{
    Node* temp = root;
    temp = recursiveKeySearch(temp,key);
    return temp;
}
void recursiveSommaFoglie(ABR* abr,Node* current,vector<int>& foglie)
{
    //Prendo i figli del nodo corrente
    Node* sx = current->getLeftChild();
    Node* dx = current->getRightChild();

    //Se il nodo corrente non ha figlio sinistro e figlio destro allora è una foglia
    if(!sx && !dx)
    {
        foglie.push_back(current->getDato());
    }else if(!sx && dx)
    {
        recursiveSommaFoglie(abr,current->getRightChild(),foglie);
    //Negli altri casi devo controllare i suoi figli per poter continuare la ricerca
    }else if(sx && !dx)
    {
        recursiveSommaFoglie(abr,current->getLeftChild(),foglie);
    }else
    {
        recursiveSommaFoglie(abr,current->getLeftChild(),foglie);
        recursiveSommaFoglie(abr,current->getRightChild(),foglie);
    }
}
int sommafoglie(ABR* abr)
{
    vector<int> foglie;
    recursiveSommaFoglie(abr,abr->getRoot(),foglie);
    int i = 0;
    int somma = 0;
    while(i < foglie.size())
    {
        somma += foglie[i];
        i+=1;
    }
    return somma;
}
*/

