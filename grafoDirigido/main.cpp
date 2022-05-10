#include "graph.h"

void testMenu() 
{

    graph<int> myGraph;
    int opcion;
    do
    {
        cout << "MENU" << endl;
        cout << "1. load file--" << endl;
        cout << "2. Insertar Arista--" << endl;
        cout << "3. MostrarPadres" << endl;
		cout << "4--Mostrar Grafo--" << endl;
        cout << "5--BFS--" << endl;
        cout << "6--DFS--" << endl;
        cout << "7-Salir--" << endl;
        cin >> opcion;
        system("cls");
        if (opcion == 1)
        {
        myGraph.cargarArchivo("testDefensa.txt");

     
        } 
        if (opcion == 2)
        {

            myGraph.insArista(2, 3);
        }
        if (opcion == 3)
        {
            myGraph.mostrarPadres();
        }
		if (opcion == 4)
        {
            myGraph.mostrar();
        }
        if (opcion == 5)
        {
         myGraph.BFS(1,2);
    
        }
        if (opcion == 6)
        {
            myGraph.DFS(1,2);

        }

    } while (opcion != 7);
    
}


int main()
{

    testMenu();

}