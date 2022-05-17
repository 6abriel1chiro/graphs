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
		 cout << "7--mostrart camino--" << endl;
        cout << "8-Salir--" << endl;
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
			int ori, dest;
			cout<<"ingrese origen "; cin>>ori;
			cout<<"ingrese origen "; cin>>dest;

			if (myGraph.BFS(ori,dest))
			{
				cout<<" camino encontrado "<<endl;
			} 
			else
			{
				cout<<" camino no encontrado "<<endl;

			}
    
        }
        if (opcion == 6)
        {
			int ori, dest;
			cout<<"ingrese origen "; cin>>ori;
			cout<<"ingrese origen "; cin>>dest;
			if (myGraph.DFS(ori,dest))
			{
				cout<<" camino encontrado "<<endl;
			}   
			else
			{
				cout<<" camino no encontrado "<<endl;

			}
		
		}

		 if (opcion == 7)
        {
			int  dest;
			cout<<"ingrese dest "; cin>>dest;
			myGraph.mostrarCamino(dest);
		}

    } while (opcion != 8);
    
}


int main()
{

    testMenu();

}