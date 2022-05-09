#pragma once
#include <iostream>
#include <string>
using namespace std;

template<class T>
class Tripla
{
private:
	T* dato;
	Tripla* siguiente;
	Tripla* anterior;
public:
	Tripla(T* d);
	Tripla();
	~Tripla();
	T* getDato();
	void setDato(T* dato);
	Tripla<T>* getSiguiente();
	void crearSiguiente(Tripla<T>* dato);
	Tripla<T>* getAnterior();
	void crearAnterior(Tripla<T>* dato);
	bool operator==(Tripla* t);
};

template<class T>
Tripla<T>::Tripla(T* d)
{
	dato = d;
	siguiente = NULL;
	anterior = NULL;
}

template<class T>
Tripla<T>::Tripla()
{
	dato = NULL;
	siguiente = NULL;
	anterior = NULL;
}

template<class T>
Tripla<T>::~Tripla()
{

}

template<class T>
T* Tripla<T>::getDato()
{
	return dato;
}

template<class T>
void Tripla<T>::setDato(T* dato)
{
	this->dato = dato;
}


template<class T>
Tripla<T>* Tripla<T>::getSiguiente()
{
	return siguiente;
}

template<class T>
void Tripla<T>::crearSiguiente(Tripla<T>* nuevoSig)
{
	siguiente = nuevoSig;
}

template<class T>
Tripla<T>* Tripla<T>::getAnterior()
{
	return anterior;
}


template<class T>
void Tripla<T>::crearAnterior(Tripla<T>* nuevoAnt)
{
	anterior = nuevoAnt;
}

template<class T>
bool Tripla<T>::operator==(Tripla* t)
{
	return dato == t->getDato();
}







