#include "Numero.h"
Numero::Numero(int num)
{
	this->NUM = num;
}
Numero::~Numero()
{

}
void Numero::mostrarS(Numero* p)
{
	p->mostrar();
}
void Numero::mostrar()
{
	std::cout << NUM << std::endl;
}
bool Numero::operator==(Numero* p)
{
	return NUM == p->NUM;
}
bool Numero::operator>(Numero* p)
{
	return NUM > p->NUM;
}

int Numero::getNumero()
{
	return NUM;
}