
//Ristabilisce la gerarchia di node assegnando a father il suo padre e grandPa il suo nonno
Template
void familyCorrection(Node<T>* node,Node<T>* &father,Node<T>* &grandPa)
{
    if(node->getFather())
    {
        father = node->getFather();
        cout<<"father = "<<father->getData().key<<endl;
        if(father->getFather())
        {
            grandPa = father->getFather();
            cout<<"granpa = "<<grandPa->getData().key<<endl;
        }else
        {
            grandPa = nullptr;
        }
    }else
    {

        father = nullptr;
        grandPa = nullptr;
    }
    cout<<"Father = "<<father<<"  Grandpa "<<grandPa<<endl;



}
Template
bool esiste(Node<T>* es)
{
    if(es)
    {
        return true;
    }else
    {
        return false;
    }
}
Template
void LEFT_ROTATE(Node<T>* &x,Node<T>* root)
{
    Node<T>* y = x->getRight();
    x->setRight(y->getLeft());
    if(y->getLeft())
    {
        y->getLeft()->setFather(x);
    }
    y->setFather(x->getFather());
    if(!x->getFather())
    {
        root = y;
    }else if(x == x->getFather()->getLeft())
    {
        x->getFather()->setLeft(y);
    }else
    {
        x->getFather()->setRight(y);
    }
    y->setLeft(x);
    x->setFather(y);
}

Template
void RIGHT_ROTATE(Node<T>* &y,Node<T>* root)
{
    //Il nodo x sarà il figlio sinistro di y
    Node<T>* x = y->getLeft();
    //Se x ha un figlio destro
    if(x->getRight())
    {
        //Il figlio sinistro di y sarà il figlio destro di x
        cout<<"X -> GETRIGHT -> "<<x->getRight()->getData().key<<endl;
        y->setLeft(x->getRight());
        if(x->getRight())
        {
            x->getRight()->setFather(y);
        }
    }else
    {
        cout<<"Giustizia fatta"<<endl;
        y->setLeft(nullptr);
    }
    //Il padre di x è ora il padre di y
    //Se y è una radice
    if(!y->getFather())
    {
        root = x;
    }else
    {
        //IL padre di x sarà il padre di y
        x->setFather(y->getFather());
        //Se y è un figlio sinistro
        if(y->getFather()->getLeft() == y)
        {
            //Imposta il figlio sinistro del padre a x
            y->getFather()->setLeft(x);
        //Altrimenti è un figlio destro
        }else
        {
            //Imposta il figlio destro del padre a x
            y->getFather()->setRight(x);
        }

    }

    x->setRight(y);
    y->setFather(x);

}
Template
void RbTree<T>::rbInsert(Node<T>* node)
{
    //Inserimento del nodo nell'albero
    this->insertTree(node);

    //Il colore del nodo inizialmente è rosso
    node->getData().setColor(RED);
    //Se il nodo non è una radice e il padre è rosso
    Node<T>* f = node->getFather();
    Node<T>* grandPa = new Node<T>();
    if(esiste(f))
       {
          grandPa = f->getFather();
       }

    if(f == nullptr)
    {
        cout<<"il nodo non ha padre"<<f<<"   node: "<<node->getFather()<<endl;
    }
    Node<T>* uncle = new Node<T>();

        //Se il nodo ha un padre che non è la radice e non è di colore nero allora puoi continuare
        //Se il padre fosse la radice allora il nodo non avrebbe ne un nonno e ne uno zio
        int i = 0;
        while(f && f != this->getRoot() && f->getData().getColor() == RED)
        {
            i++;
            //cout<<i<<"******************************************************"<<endl;
            if(i < 10)
            {

            //cout<<"Entro"<<endl;
            //cout<<f->getData().key<<endl;
            //Se il nonno ha un figlio sinistro e il padre del nodo è figlio sinistro del nonno
            if(esiste(grandPa->getLeft()) && grandPa->getLeft() == f)
            {
                    //Verifico che esista lo zio, ossia il figlio destro del nonno e che sia rosso
                    if(grandPa->getRight() && grandPa->getRight()->getData().getColor() == RED)
                    {
                                uncle = grandPa->getRight();
                                //Il padre del nodo e lo zio diventano neri e il figlio resta cosi rosso
                                uncle->getData().setColor(BLACK);
                                f->getData().setColor(BLACK);
                                //Il nonno invece diventa un nodo rosso
                                grandPa->getData().setColor(RED);
                                //Il nodo da considerare diventa il nonno

                                node = grandPa;
                                familyCorrection(node,f,grandPa);


                    }else
                    {
                        //cout<<"Non è previsto che io sia qui f: "<<f<<endl;
                       //Se uncle non esiste o non è rosso
                       //Controllo se il nodo sia un figlio destro
                        if(node == f->getRight())
                        {
                            node = f;
                            familyCorrection(node,f,grandPa);
                            LEFT_ROTATE(node,this->getRoot());
                        }
                        //Se il nodo ha un padre e un nonno
                        if(f && grandPa)
                        {
                            //Imposta il colore del nuovo padre a nero e quello del nonno a rosso

                            grandPa->getData().setColor(RED);
                            f->getData().setColor(BLACK);
                            cout<<"Prima di right rotate"<<endl;
                            RIGHT_ROTATE(grandPa,this->getRoot());
                            familyCorrection(node,f,grandPa);
                            cout<<"Post right rotate"<<endl;

                            //cout<<"Node = "<<node->getData().key<<" f: "<<f->getData().key<<" color: "<<f->getData().getColor()<<endl;
                            //cout<<"right "<<f->getRight()->getData().key<<endl;
                        }
                    }


            }
            else
            {
                    //Verifico che esista lo zio, ossia il figlio sinistro del nonno e che sia rosso
                    if(grandPa->getLeft() && grandPa->getLeft()->getData().getColor() == RED)
                    {
                                uncle = grandPa->getLeft();
                                //Il padre del nodo e lo zio diventano neri e il figlio resta cosi rosso
                                uncle->getData().setColor(BLACK);
                                f->getData().setColor(BLACK);
                                //Il nonno invece diventa un nodo rosso
                                grandPa->getData().setColor(RED);
                                //Il nodo da considerare diventa il nonno

                                node = grandPa;
                                familyCorrection(node,f,grandPa);


                    }else
                    {
                        cout<<"Non è previsto che io sia qui f: "<<f<<endl;
                       //Se uncle non esiste o non è rosso
                       //Controllo se il nodo sia un figlio destro
                        if(node == f->getLeft())
                        {
                            node = f;
                            familyCorrection(node,f,grandPa);
                            RIGHT_ROTATE(node,this->getRoot());
                        }
                        //Se il nodo ha un padre e un nonno
                        if(f && grandPa)
                        {
                            //Imposta il colore del nuovo padre a nero e quello del nonno a rosso
                            f->getData().setColor(BLACK);
                            grandPa->getData().setColor(RED);
                            f->getData().setColor(BLACK);
                            cout<<"Prima di right rotate"<<endl;
                            LEFT_ROTATE(grandPa,this->getRoot());
                            cout<<"Post right rotate"<<endl;

                        }
                    }


            }
            }
        }




        //Colora la radice di nero
    this->getRoot()->getData().setColor(BLACK);

    cout<<"Fine cicloooooooooooooooooooooooooooooo"<<endl;
}


Template
void RbTree<T>::popola()
{
    for(int i = 0; i <= 2; i++)
    {
        Node<T>* node = new Node<T>();
        T data;
        data.key = 10;
        if(i % 2 == 0)
        {
            data.key = i + 20;
        }else
        {
            data.key = i - 1;
        }
        node->setData(data);
        cout<<"Inserisco il nodo"<<data.key<<endl<<endl<<endl;
        this->rbInsert(node);
        this->stampa();
        cout<<"Fine inserimento"<<endl<<endl;
    }
}

    /*
    while(f && f->getData().getColor() == RED)
    {
        cout<<"Hello"<<endl;
        //Vedo se il padre del nodo corrente è figlio sinistro del padre
        if(grandPa->getLeft() == f)
        {
            //Mi prendo lo zio del nodo. Lo zio sarà il figlio destro del nonno
            Node<T>* uncle = f->getRight();
            //Se lo zio è rosso
            if(uncle->getData().getColor() == RED)
            {
                //Il padre del nodo e lo zio diventano neri e il figlio resta cosi rosso
                uncle->getData().setColor(BLACK);
                f->getData().setColor(BLACK);
                //Il nonno invece diventa un nodo rosso
                grandPa->getData().setColor(RED);
                //Il nodo da considerare diventa il nonno
                node = grandPa;
                familyCorrection(node,f,grandPa);
            }else
            {
                if(node == f->getRight())
                {

                }
            }
        }
        cout<<"Hello"<<endl;
    }
*/

