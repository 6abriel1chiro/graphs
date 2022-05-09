#pragma once
#include <iostream>
class Numero
{
private:
	int NUM;
public:
	Numero(int num);
	~Numero();
	static void mostrarS(Numero* p);
	void mostrar();
	bool operator==(Numero* p);
	bool operator>(Numero* p);
	int getNumero();
};