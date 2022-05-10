#pragma once
#include "Lista8.h"
template <class T>
class Node
{
private:
	Lista8<T>* lista;
	int padre;
	bool marca;
public:
	Node();
	~Node();
	Lista8<T>* getLista();
	int getPadre();
	bool getMarca();
	void setLista(Lista8<T>* lista);
	void insertarLista(T dato);
	void setPadre(int padre);
	void setMarca(bool marca);
};
template <class T>
Node<T>::Node()
{
	lista = new Lista8<T>();
	this->padre = -1;
	this->marca = false;
}
template <class T>
Node<T>::~Node()
{
	delete lista;
}
template <class T>
Lista8<T>* Node<T>::getLista()
{
	return lista;
}
template <class T>
int Node<T>::getPadre()
{
	return padre;
}
template <class T>
bool Node<T>::getMarca()
{
	return marca;
}
template <class T>
void Node<T>::setLista(Lista8<T>* lista)
{
	this->lista = lista;
}
template <class T>
void Node<T>::setPadre(int padre)
{
	this->padre = padre;
}
template <class T>
void Node<T>::setMarca(bool marca)
{
	this->marca = marca;
}
template <class T>
void Node<T>::insertarLista(T dato)
{
	lista->insPrin(dato);
}