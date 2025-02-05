
//Inserimento di un nodo nell' albero attraverso dato
Template
void ABR<T>::insertTree(T x) {
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
        if(x.key > y->getData().key)
        {
            y = y->getRight();
        }else
        //Cerca a sinistra
        {
            y = y->getLeft();
        }

    }
    //Se l'albero era vuoto allora il posto del nuovo nodo è sicuramente nella radice
    if(root == nullptr)
    {
        root = newNode;
    }else
    {
        //Imposto il padre del nuovo nodo a temp che è l'ultimo nodo non null
        newNode->setFather(temp);
        //Se il nuovo nodo ha chiave > del padre allora va a destra
        if(x.key > temp->getData().key)
        {
            temp->setRight(newNode);

        }else
        {
            //Altrimenti va inserito a sinistra
            temp->setLeft(newNode);
        }
    }
}
//Inserimento di un nodo già creato nell'albero
Template
void ABR<T>::insertTree(Node<T>* newNode)
{

    //Creo un nodo  contenente la radice
    Node<T>* y = root;
    //Conterrà di volta in volta un nodo all'interno dell'albero
    Node<T>* temp = nullptr;
    T x = newNode->getData();
    //Cerco il posto in cui inserire il nodo
    while(y != nullptr)
    {
        temp = y;

        //Cerca a destra
        if(x.key > y->getData().key)
        {
            y = y->getRight();
        }else
        //Cerca a sinistra
        {
            y = y->getLeft();
        }

    }
    //Se l'albero era vuoto allora il posto del nuovo nodo è sicuramente nella radice
    if(root == nullptr)
    {
        root = newNode;
    }else
    {
        //Imposto il padre del nuovo nodo a temp che è l'ultimo nodo non null
        newNode->setFather(temp);
        //Se il nuovo nodo ha chiave > del padre allora va a destra
        if(x.key > temp->getData().key)
        {
            temp->setRight(newNode);

        }else
        {
            //Altrimenti va inserito a sinistra
            temp->setLeft(newNode);
        }
    }
}

Template
 void ABR<T>::recursiveStampa(Node<T>* root,bool sx,bool dx,int i,int N)
 {
    i = i + 1;
    if(i < N)
    {


        if(root != nullptr)
        {
            if(!sx && !dx)
            {
                cout<<"      R: "<<root->getData().key<<endl;
            }else if(sx && !dx)
            {

                cout<<"      /   "<<endl;
                cout<<"     /  "<<endl;
                cout<<"    /   "<<endl;
                cout<<"   /    "<<endl;
                cout<<" SX: "<<root->getData().key<<endl<<endl;
            }else
            {

                cout<<"       \\   "<<endl;
                cout<<"        \\   "<<endl;
                cout<<"         \\   "<<endl;
                cout<<"          \\   "<<endl;
                cout<<"           DX: "<<root->getData().key<<endl<<endl;
            }

            Node<T>* left = new Node<T>();
            if((left = root->getLeft())!= nullptr)
            {
                cout<<"Stampo il figlio sinistro di "<<root->getData().key<<endl;
                recursiveStampa(left,true,false,i,N);
            }
            Node<T>* right = new Node<T>();
            if((right = root->getRight())!= nullptr)
            {
                 cout<<"Stampo il figlio destro di "<<root->getData().key<<endl;
                recursiveStampa(right,false,true,i,N);
            }

        }
    }
 }
Template
void ABR<T>::stampa()
{
    //Inizio dalla radice
    recursiveStampa(root,false,false,0,100);

}

