#include "Grafo.h"

Grafo::Grafo()
{
}

Grafo::~Grafo()
{
}

void Grafo::insertarArista(int v1, int v2)
{
	vec[v1].getLista8()->addBack(new Numero(v2));
}

void Grafo::mostrar()
{
	for (int i = 0; i < TAM; i++)
	{
		if (vec[i].getLista8()->getPrimer() != NULL)
		{
			cout << i << " -> "<<endl;
			vec[i].getLista8()->mostrarLista(Numero::mostrarS);
			cout << endl;
		}
	}
}

bool Grafo::busquedaAmplitud(int origen, int destino)
{
	bool encontre = false;
	vec[origen].setMarca(true);
	list<int> cola;
	cola.push_back(origen);
	while (cola.empty() == false && encontre == false)
	{
		int iesimo = 1;
		int vert = cola.front();
		cola.pop_front();
		Numero* adya = vec[vert].getLista8()->buscarIesimaPosicion(iesimo);
		while (adya != NULL && encontre == false)
		{
			if (vec[adya->getNumero()].getMarca() == false)
			{
				vec[adya->getNumero()].setPadre(vert);
				if (adya->getNumero() == destino)
				{
					encontre = true;
				}
				else
				{
					vec[adya->getNumero()].setMarca(true);
					cola.push_back(adya->getNumero());
				}
			}
			iesimo = iesimo + 1;
			adya = vec[vert].getLista8()->buscarIesimaPosicion(iesimo);
		}
	}
	return encontre;
}

bool Grafo::busquedaProfundidad(int origen, int destino)
{
	bool encontre_cam = false;
	vec[origen].setMarca(true);
	int iesimo = 1;
	Numero* adya = vec[origen].getLista8()->buscarIesimaPosicion(iesimo);
	while (adya != NULL)
	{
		if (encontre_cam == false && vec[adya->getNumero()].getMarca() == false)
		{
			vec[adya->getNumero()].setPadre(origen);
			if (adya->getNumero() == destino)
			{
				encontre_cam = true;
			}
			else
			{
				encontre_cam = busquedaProfundidad(adya->getNumero(), destino);
			}
		}
		iesimo++;
		adya = vec[origen].getLista8()->buscarIesimaPosicion(iesimo);
	}
	return encontre_cam;
}

void Grafo::Dikjstra(map<string, vector<pair<string, int> > > grafo, map<string, int>& distancias, string ori)
{
	queue <string> cola;
	cola.push(ori);
	distancias[ori] = 0;
	while (!cola.empty())
	{
		string origen = cola.front();
		for (int c = 0; c < grafo[origen].size(); c++)
		{
			string destino = grafo[origen][c].first;
			if (distancias[origen] + grafo[origen][c].second < distancias[destino])
			{
				distancias[destino] = distancias[origen] + grafo[origen][c].second;
				cola.push(destino);
			}
		}
		cola.pop();
	}
}

void Grafo::contraer(int v1, int v2)
{
	Tripla<Numero>* caminante;
	vec[v2].getLista8()->eliminar(new Numero(v1));
	vec[v1].getLista8()->eliminar(new Numero(v2));
	caminante = vec[v2].getLista8()->getPrimer();
	while (caminante != NULL)
	{
		vec[v2].getLista8()->addBack(caminante->getDato());
		vec[caminante->getDato()->getNumero()].getLista8()->eliminar(new Numero(v2));
		vec[caminante->getDato()->getNumero()].getLista8()->addBack(new Numero(v1));
		caminante = caminante->getSiguiente();
	}
	vec[v2].
}
