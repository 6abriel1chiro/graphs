#pragma once
#include <iostream>
#include <list>
#include "Cabecera.h"
#include "Tripla.h"

#include <map>
#include <vector>
#include <queue>
#include <list>
#include <cstring>

#define TAM 10000

using namespace std;

class Grafo
{
private:
	Cabecera vec[TAM];
public:
	Grafo();
	~Grafo();
	void insertarArista(int v1, int v2);
	void mostrar();
	bool busquedaAmplitud(int origen, int destino);
	bool busquedaProfundidad(int origen, int destino);
	void Dikjstra(map<string, vector<pair<string, int> > > grafo, map<string, int>& distancias, string ori);
	void contraer(int v1,int v2);
};