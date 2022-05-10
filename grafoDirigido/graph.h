#pragma once
#include "Node.h"
#include <fstream>
#define TAM 1000
template <class T>
class graph
{
private:
	Node<T> array[TAM];
	Lista8<T>* cola;
public:
	graph();
	~graph();
	void insArista(T dato1, T dato2);
	void mostrarPadres();
	void mostrargraph();
	bool DFS(T ori, T dest);
	bool BFS(T ori, T dest);
	void cargarArchivo(string nom);
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
	array[dato1].getLista()->addFront(dato2);
	array[dato1].setPadre(dato1);
}
template <class T>
void graph<T>::mostrarPadres()
{
	for (int pos = 0; pos < TAM; pos += 1)
	{
		if (array[pos].getLista()->buscarIesimaPosicion(0) != NULL)
			cout << array[pos].getPadre() << " ";
	}
}
template <class T>
void graph<T>::mostrargraph()
{
	for (int pos = 0; pos < TAM; pos += 1)
	{
		if (array[pos].getLista()->buscarIesimaPosicion(0) != NULL)
			cout << array[pos].getPadre() << " ==> ";
			array[pos].getLista()->mostrar();
	}
}
template <class T>
bool graph<T>::DFS(T ori, T dest)
{
	bool encontre = false;
	array[ori].setMarca(true);
	int i = 1;
	T adya = array[ori].getLista()->buscarIesimaPosicion(i);
	while (adya != NULL)
	{
		if (encontre == false && array[ori].getMarca() == false)
		{
			array[adya].setPadre(ori);
			if (adya == dest)
			{
				encontre = true;
			}
			else
			{
				encontre = DFS(adya, dest);
			}
		}
		i += 1;
		adya = array[ori].getLista()->buscarIesimaPosicion(i);
	}
	return encontre;
}
template <class T>
bool graph<T>::BFS(T ori, T dest)
{
	int i;
	bool encontre = false;
	array[ori].setMarca(true);
	cola->addBack(ori);
	while (cola != NULL && encontre == false)
	{
		i = 1;
		T vert = cola->buscarIesimaPosicion(0);
		T adya = array[vert].getLista()->buscarIesimaPosicion(i);
		while (adya != NULL && encontre == false)
		{
			if (array[adya].getMarca() == false)
			{
				array[adya].setPadre(vert);
				if (adya == dest) encontre = true;
				else
				{
					array[adya].setMarca(true);
					cola->addBack(adya);
				}
			}
			i += 1;
			adya = array[vert].getLista()->buscarIesimaPosicion(i);
		}
	}
	return encontre;
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