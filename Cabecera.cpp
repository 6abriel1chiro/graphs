#include "Cabecera.h"

Cabecera::Cabecera()
{
	sig = NULL;
	ant = NULL;
	marca = false;
	padre = -1;
	lista8 = new Lista8<Numero>();
}

Cabecera::~Cabecera()
{
}

int Cabecera::getDato()
{
	return dato;
}

void Cabecera::setDato(int dato)
{
	dato = dato;
}

Cabecera* Cabecera::getSiguiente()
{
	return sig;
}

Cabecera* Cabecera::getAnterior()
{
	return ant;
}

void Cabecera::setMarca(bool marc)
{
	marca = marc;
}

bool Cabecera::getMarca()
{
	return marca;
}

void Cabecera::setPadre(int pad)
{
	padre = pad;
}

int Cabecera::getPadre()
{
	return padre;
}

Lista8<Numero>* Cabecera::getLista8()
{
	return lista8;
}

void Cabecera::crearSiguiente(Cabecera* dato)
{
	sig = dato;
}

void Cabecera::crearAnterior(Cabecera* dato)
{
	ant = dato;
}