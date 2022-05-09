#pragma once
#include <iostream>
#include "Lista8.h"
#include "Numero.h"

using namespace std;

class Cabecera
{
private:
	Lista8<Numero>* lista8;
	Cabecera* sig;
	Cabecera* ant;
	bool marca;
	int padre;
	int dato;
public:
	Cabecera();
	~Cabecera();
	int getDato();
	void setDato(int dato);
	Cabecera* getSiguiente();
	Cabecera* getAnterior();
	void setMarca(bool marc);
	bool getMarca();
	void setPadre(int pad);
	int getPadre();
	Lista8<Numero>* getLista8();
	void crearSiguiente(Cabecera* dato);
	void crearAnterior(Cabecera* dato);
};