#pragma once
#include "Node.h"
#include <fstream>
#define TAM 100
template <class T>
class graph
{
private:
	Node<T> arr[TAM];
	Lista8<T>* cola;
public:
	graph();
	~graph();
	void insArista(T dato1, T dato2);
	void mostrarPadres();
	void mostrar();
	bool DFS(T ori, T dest);
	bool BFS(T ori, T dest);
	void cargarArchivo(string nom);

	void mostrarCamino(int dest);
};
template <class T>
graph<T>::graph()
{
	cola = new Lista8<T>();
}
template <class T>
graph<T>::~graph()
{

}
template <class T>
void graph<T>::insArista(T dato1, T dato2)
{
	arr[dato1].getLista()->addFront(dato2);
		
}
template <class T>
void graph<T>::mostrarPadres()
{
	for (int i = 0; i < TAM; i ++)
	{
		if (arr[i].getLista()->findInPos(0) != NULL)
			cout << arr[i].getPadre() << " ";
	}
}
template <class T>
void graph<T>::mostrar()
{
	for (int i = 0; i < TAM; i ++)
	{
		if (arr[i].getLista()->findInPos(0) != NULL)
			cout << i << "->";
			arr[i].getLista()->mostrar();
	}
}
template <class T>
bool graph<T>::DFS(T ori, T dest)
{
		bool found = false;
	arr[ori].setMarca(true);
	int i = 0;
	T adya = arr[ori].getLista()->findInPos(i);
	while (adya != NULL)
	{
		if (found == false && arr[adya].getMarca() == false)
		{
			arr[adya].setPadre(ori);
			if (adya == dest)
			{
				found = true;
			}
			else
			{
				found = DFS(adya, dest);
			}
		}
		i += 1;
		adya = arr[ori].getLista()->findInPos(i);
	}
	return found;
}
template <class T>
bool graph<T>::BFS(T ori, T dest)
{
	int i;
	bool found = false;
	arr[ori].setMarca(true);
	cola->addBack(ori);
	while (cola != NULL && found == false)
	{
		i = 0;
		T vert = cola->findInPos(0);
		T adya = arr[vert].getLista()->findInPos(i);
		while (adya != NULL && found == false)
		{
			if (arr[adya].getMarca() == false)
			{
				//cout<<adya<<" ";
				arr[adya].setPadre(vert);
				if (adya == dest)
				{found = true;}
				else
				{
					arr[adya].setMarca(true);
					cola->addBack(adya);
				}
			}
			i += 1;
			adya = arr[vert].getLista()->findInPos(i);

		}
	}
	return found;
}
template <class T>
void graph<T>::cargarArchivo(string nom)
{
	int i = 0;
	ifstream arch;
	arch.open(nom);
	T vec[100];

		while (!arch.eof())
		{
			T dato = 0;
			while (dato != -1)
			{
				arch >> dato;
				vec[i] = dato;
				if (dato != -1)
				i += 1;
			}
			for (int pos = 1; pos < i; pos += 1)
			{
				insArista(vec[0], vec[pos]);
			}
			for (int pos = 0; pos < i; pos += 1)
			{
				vec[i] = NULL;
			}
			i = 0;
	}

  

}

template <class T>
	void graph<T>::mostrarCamino(int dest)
	{
		if (dest != -1)
		{
			mostrarCamino(arr[dest].getPadre());
			cout<<dest<<" - ";
		}
	}
