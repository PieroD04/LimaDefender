#pragma once

using namespace System;
using namespace System::Drawing;

class Entidad
{
protected:
	int x;
	int y;
	int dx;
	int dy;
	int ancho;
	int alto;
	int indiceX;
	int indiceY;
public:
	Entidad()
	{
		this->x = 0;
		this->y = 0;
		this->dx = 0;
		this->dy = 0;
		this->ancho = 0;
		this->alto = 0;
		this->indiceX = 0;
		this->indiceY = 0;
	}

	Entidad(int x, int y, int dx, int dy, int ancho, int alto, int indiceX, int indiceY)
	{
		this->x = x;
		this->y = y;
		this->dx = dx;
		this->dy = dy;
		this->ancho = ancho;
		this->alto = alto;
		this->indiceX = indiceX;
		this->indiceY = indiceY;
	}

	~Entidad() {}

	int getx() { return this->x; }
	int gety() { return this->y; }
	int getancho() { return this->ancho; }
	int getalto() { return this->alto; }

	virtual void Dibujar(){}
};