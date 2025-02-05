#include "lezione13.hpp"

//Crea un albero red and black attraverso inserimento di numeri presi dal vettore passato in input
RbTree<RbNode>* CreateRbTree(vector<int> h)
{
    RbTree<RbNode>* rb = new RbTree<RbNode>();
    for(int i = 0; i < h.size();i++)
    {
        cout<<"------------Inserimento del nodo "<<h[i]<<"------------------------------------------------------------------"<<endl<<endl;
        RbNode data(h[i]);
        Node<RbNode>* node = new Node<RbNode>();
        node->setData(data);
        rb->rbInsert(node);
        rb->stampa();
        cout<<"------------Fine inserimento iterazione  "<<i<<" --------------------------------------------------------------"<<endl<<endl;

    }
    return rb;
}
