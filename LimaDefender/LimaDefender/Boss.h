#pragma once
#include "Entidad.h"

using namespace System::Drawing;

const int vida_boss = 10; //Cuantas golpes puede recibir el boss antes de morir (bombas sueltas por el mapa)

class Boss: public Entidad
{
private:
	int vida;
	bool aparicion;
	bool ataque;
	bool haDaniado;
public:
	Boss(): Entidad(){}
	Boss(int x, int y)
	{
		this->x = x;
		this->y = y;
		this->vida = vida_boss;
		this->dx = 0;
		this->dy = 0;
		this->indiceX = 0;
		this->indiceY = 0;
		this->ancho = 0; //Se modificara constantemente con cada animacion
		this->alto = 0;
		this->aparicion = true;
		this->ataque = false;
		this->haDaniado = false;
	}
	~Boss(){}
	int getvida() { return this->vida; }
	void sethaDaniado(bool haDaniado) { this->haDaniado = haDaniado; }
	bool gethaDaniado() { return this->haDaniado; }
	void dañar() { this->vida -= 1; }
	void atacar() { this->ataque = true; }
	void Aparicion(BufferedGraphics^ buffer)
	{

		Bitmap^ spawn = gcnew Bitmap("../Contents/boss_spawn.png");
		this->ancho = 190;
		this->alto = 137;
		Rectangle areaUsar = Rectangle(indiceX * ancho, indiceY * alto, ancho, alto);
		Rectangle aumento = Rectangle(x, y, ancho, alto);
		buffer->Graphics->DrawImage(spawn, aumento, areaUsar, GraphicsUnit::Pixel);
		
		//IndiceX max 5
		//IndiceY max 6
		
		if (indiceY < 6)
		{
			if (indiceX >= 0 && indiceX < 4) indiceX++;
			else { indiceY++; indiceX = 0; }
		}
		else { indiceY = 0; indiceX = 0; aparicion = false; }
	}
	void Idle(BufferedGraphics^ buffer)
	{

		Bitmap^ idle = gcnew Bitmap("../Contents/boss_idle.png");
		this->ancho = 119;
		this->alto = 156;
		Rectangle areaUsar = Rectangle(indiceX * ancho, indiceY * alto, ancho, alto);
		Rectangle aumento = Rectangle(x-5, y-20, ancho, alto);
		buffer->Graphics->DrawImage(idle, aumento, areaUsar, GraphicsUnit::Pixel);

		//IndiceX max 3
		//IndiceY max 3

		if (indiceY < 3)
		{
			if (indiceX == 0) indiceX = 2;
			else { indiceY++; indiceX = 0; }
		}
		else { indiceX = 0; indiceY = 0;}


	}
	void Ataque(BufferedGraphics^ buffer)
	{
		Bitmap^ attack = gcnew Bitmap("../Contents/boss_ataque.png");
		this->ancho = 550;
		this->alto = 159;
		Rectangle areaUsar = Rectangle(indiceX * ancho, indiceY * alto, ancho, alto);
		Rectangle aumento = Rectangle(x - 400, y - 20, ancho/1.05, alto/1.05);
		buffer->Graphics->DrawImage(attack, aumento, areaUsar, GraphicsUnit::Pixel);

		//IndiceX max 9
		//IndiceY max 1

		if (indiceY < 9)
		{
			if (indiceX == 0) indiceX = 1;
			else { indiceY++; indiceX = 0; }
		}
		else { indiceX = 0; indiceY = 0; ataque = false; haDaniado = true; }
	}
	void Dibujar(BufferedGraphics^ buffer)
	{
		if (this->ataque == false)
		{
			if (this->aparicion) Aparicion(buffer);
			else Idle(buffer);	
		}
		if (this->ataque == true) Ataque(buffer);
	}


};