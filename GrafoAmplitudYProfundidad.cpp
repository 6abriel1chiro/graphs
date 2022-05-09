#include "Grafo.h"
#include <fstream>
#include <vector>
#include <sstream>
#include <string>

void leerDeArchivo(Grafo &grafo)
{
    ifstream archi;
    int numerosArchivo;
    int inicio;
    int cont=0;
    //usar animales para 3000+ 
    //usar animalesCorto para 100
    archi.open("Test.txt");

    if (!archi)
        cout << "No se puede abrir";
    else
        while (!archi.eof() && archi >> numerosArchivo)
        {
            if (cont == 0)
            {
                inicio = numerosArchivo;
            }
            else
            {
                cont = numerosArchivo;
            }
            if (inicio != -1 && cont!=0)
            {
                grafo.insertarArista(inicio,cont);
            }
            else if(inicio == -1)
            {
                cont = 0;
            }
        }
    archi.close();
}

void leerDeArchivoAvanzado(Grafo& grafo)
{
    ifstream archi;
    int numerosArchivo;

    //usar animales para 3000+ 
    //usar animalesCorto para 100
    archi.open("Test.txt");
    string line;

    if (!archi)
        cout << "No se puede abrir";
    else
        while (getline(archi,line))
        {
            istringstream iss(line);
            int n;
            int inicio;
            //vector<int> v;
            iss >> inicio;

            while (iss >> n)
            {
                //v.push_back(n);
                if (n != -1)
                {
                    grafo.insertarArista(inicio, n);
                } 
            }
        }
    archi.close();
}

int main()
{
    Grafo grafo;
    leerDeArchivoAvanzado(grafo);
    //leerDeArchivo(grafo);
    /*grafo.insertarArista(0, 1);
    grafo.insertarArista(1, 3);
    grafo.insertarArista(2, 1);
    grafo.insertarArista(2, 3);
    grafo.insertarArista(3, 0);
    grafo.insertarArista(4, 2);*/
    grafo.mostrar();
}