#include "lezione16.hpp"


void stampaMatrice(vector<vector<int>> c,int w)
{
    for(int i = 0; i < c.size();i++)
    {
        for(int W = 0; W <= w; W++ )
        {
            //cout<<"C["<<i<<"]"<<"["<<W<<"]"<<" = "<<c[i][W]<<endl;
            cout<<c[i][W]<<" ";
        }
        cout<<endl;
    }    cout<<"La matrice è stata stampata correttamente"<<endl<<endl;
}
vector<Object> Zaino::problemaZaino01()
{

           object.insert(object.begin(), Object(0,0));
           cout<<"Inizio object = "<<object.size()<<endl;
            vector<vector<int>> c;
            //Gli alloco lo spazio necessario
            for(int i = 0; i < object.size();i++)
            {
                //cout<<"i ="<<i<<endl;
                c.push_back(vector<int>());
                //c[i].push_back(0);
                for(int w = 0; w <= totalCapacity;w++)
                {

                    c[i].push_back(0);
                    cout<<"Stampo"<<c[i][w]<<endl;
                }
            }
            //Imposto i valori nel caso base c[0,w] e c[i,0]
            for(int i = 0; i < object.size();i++)
            {
                c[i][0] = 0;
            }
            for(int w = 0; w < totalCapacity; w++)
            {
                c[0][w] = 0;
            }
            stampaMatrice(c,totalCapacity);
            for(int i = 1; i < object.size();i++)
            {
                for(int w = 1; w <= totalCapacity;w++)
                {
                    //Caso in cui l' oggetto non può essere preso poiché non entra nello zaino
                    c[i][w] = c[i-1][w];
                    if(w < object[i].weight)
                    {
                        c[i][w] = c[i-1][w];
                    //Se l'oggetto può essere preso dobbiamo vedere se prenderlo ci porti effettivamente un vantaggio rispetto al non prenderlo
                    }else if(c[i-1][w] > c[i-1][w-object[i].weight] + object[i].value)
                    {
                        c[i][w] = c[i-1][w];
                    }else if(c[i-1][w] < c[i-1][w-object[i].weight] + object[i].value)
                    {
                        c[i][w] = c[i-1][w-object[i].weight] + object[i].value;
                    }
                }
            }
            stampaMatrice(c,totalCapacity);
            //A questo punto devo vedere gli oggetti che sono stati presi e restituirli
            vector<Object> oggettiInclusi;
            int i = object.size()-1;
            int k = totalCapacity;
            while (i > 0 && k > 0)
            {
                //cout<<"i"<<i<<"k"<<k<<endl;
                if(c[i][k] == c[i-1][k])
                {
                    i = i-1;
                }else if(c[i][k] != c[i-1][k])
                {
                    //cout<<"Entro?"<<endl;
                    oggettiInclusi.push_back(Object(object[i].value,object[i].weight));
                    k = k - object[i].weight;
                    i = i-1;

                }

            }
            //cout<<"Peso = "<<oggettiInclusi[0].weight<<" Value "<<oggettiInclusi[0].value<<endl;
            return oggettiInclusi;
}


//Variante del problema dello zaino 01 in cui dobbiamo massimizzare il valore della soluzione, ma quest'ultima deve essere < di una soglia G
vector<Object> Zaino::problemaZainoMin01(int G)
{

           object.insert(object.begin(), Object(0,0));
           cout<<"Inizio object = "<<object.size()<<endl;
            vector<vector<int>> c;
            //Gli alloco lo spazio necessario
            for(int i = 0; i < object.size();i++)
            {
                //cout<<"i ="<<i<<endl;
                c.push_back(vector<int>());
                //c[i].push_back(0);
                for(int w = 0; w <= totalCapacity;w++)
                {

                    c[i].push_back(0);
                    cout<<"Stampo"<<c[i][w]<<endl;
                }
            }
            //Imposto i valori nel caso base c[0,w] e c[i,0]
            for(int i = 0; i < object.size();i++)
            {
                c[i][0] = 0;
            }
            for(int w = 0; w < totalCapacity; w++)
            {
                c[0][w] = 0;
            }
            stampaMatrice(c,totalCapacity);
            for(int i = 1; i < object.size();i++)
            {
                for(int w = 1; w <= totalCapacity;w++)
                {
                    //Caso in cui l' oggetto non può essere preso poiché non entra nello zaino
                    c[i][w] = c[i-1][w];
                    if(w < object[i].weight)
                    {
                        c[i][w] = c[i-1][w];
                    //Se l'oggetto può essere preso dobbiamo vedere se prenderlo ci porti effettivamente un vantaggio rispetto al non prenderlo
                    }else if(c[i-1][w] > c[i-1][w-object[i].weight] + object[i].value)
                    {
                        c[i][w] = c[i-1][w];
                    }else if(c[i-1][w] < c[i-1][w-object[i].weight] + object[i].value)
                    {
                        c[i][w] = c[i-1][w-object[i].weight] + object[i].value;
                    }
                    if(c[i][w] > G)
                    {
                        c[i][w] = c[i-1][w];
                    }
                }
            }
            stampaMatrice(c,totalCapacity);
            //A questo punto devo vedere gli oggetti che sono stati presi e restituirli
            vector<Object> oggettiInclusi;
            int i = object.size()-1;
            int k = totalCapacity;
            while (i > 0 && k > 0)
            {
                //cout<<"i"<<i<<"k"<<k<<endl;
                if(c[i][k] == c[i-1][k])
                {
                    i = i-1;
                }else if(c[i][k] != c[i-1][k])
                {
                    //cout<<"Entro?"<<endl;

                    oggettiInclusi.push_back(Object(object[i].value,object[i].weight));
                    k = k - object[i].weight;
                    i = i-1;

                }

            }

            stampaMatrice(c,totalCapacity);
            //cout<<"Peso = "<<oggettiInclusi[0].weight<<" Value "<<oggettiInclusi[0].value<<endl;
            return oggettiInclusi;
}





