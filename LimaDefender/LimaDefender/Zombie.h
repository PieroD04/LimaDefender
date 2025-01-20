#pragma once
#include "Entidad.h"
const int vida_zombie_0 = 7;
const int vida_zombie_1 = 5;
const int vida_zombie_2 = 7;

class Zombie : public Entidad
{
private:
	int tipo; // 0 = Zombie hombre, 1 = mujer, o 2 = bestia
	int vida; //golpes que puede recibir
	bool esDerecha; //direccion;
	bool estaAtacando;
public:
	Zombie() :Entidad()
	{
		this->tipo = 0;
		this->vida = 10;
		this->esDerecha = true;
		this->estaAtacando = false;
	}

	Zombie(int tipo, bool esDerecha)
	{
		Random^ r = gcnew Random();
		this->tipo = tipo;
		this->esDerecha = esDerecha;
		this->ancho = 96;
		this->alto = 96;
		if (this->esDerecha) // si se dirige a la derecha
		{
			switch (this->tipo)
			{
			case 0:
				this->x = 0;
				this->y = r->Next(370, 450);
				this->dx = r->Next(1, 4);
				this->dy = 0;
				this->vida = vida_zombie_0;
				this->estaAtacando = false;
				this->indiceX = 0;
				this->indiceY = 0;
				break;
			case 1:
				this->x = 0;
				this->y = r->Next(370, 450);
				this->dx = r->Next(3, 6);
				this->dy = 0;
				this->vida = vida_zombie_1;
				this->estaAtacando = false;
				this->indiceX = 0;
				this->indiceY = 0;
				break;
			case 2:
				this->x = 0;
				this->y = r->Next(370, 450);
				this->dx = r->Next(4, 7);
				this->dy = 0;
				this->vida = vida_zombie_2;
				this->estaAtacando = false;
				this->indiceX = 0;
				this->indiceY = 0;
				break;
			}

		}
		else //si se dirige a la izquierda
		{
			switch (this->tipo)
			{
			case 0:
				this->x = 950;
				this->y = r->Next(370, 450);
				this->dx = -1 * r->Next(2, 5);
				this->dy = 0;
				this->vida = vida_zombie_0;
				this->estaAtacando = false;
				this->indiceX = 7;
				this->indiceY = 0;
				break;
			case 1:
				this->x = 950;
				this->y = r->Next(370, 450);
				this->dx = -1 * r->Next(2, 5);
				this->dy = 0;
				this->vida = vida_zombie_1;
				this->estaAtacando = false;
				this->indiceX = 6;
				this->indiceY = 0;
				break;
			case 2:
				this->x = 950;
				this->y = r->Next(370, 450);
				this->dx = -1 * r->Next(2, 5);
				this->dy = 0;
				this->vida = vida_zombie_2;
				this->estaAtacando = false;
				this->indiceX = 9;
				this->indiceY = 0;
				break;
			}
		}
	}

	Zombie(int tipo, bool esDerecha, int y)
	{
		Random^ r = gcnew Random();
		this->tipo = tipo;
		this->esDerecha = esDerecha;
		this->ancho = 96;
		this->alto = 96;
		if (this->esDerecha) // si se dirige a la derecha
		{
			switch (this->tipo)
			{
			case 0:
				this->x = 0;
				this->y = y;
				this->dx = r->Next(2, 5);
				this->dy = 0;
				this->vida = vida_zombie_0;
				this->estaAtacando = false;
				this->indiceX = 0;
				this->indiceY = 0;
				break;
			case 1:
				this->x = 0;
				this->y = y;
				this->dx = r->Next(2, 5);
				this->dy = 0;
				this->vida = vida_zombie_1;
				this->estaAtacando = false;
				this->indiceX = 0;
				this->indiceY = 0;
				break;
			case 2:
				this->x = 0;
				this->y = y;
				this->dx = r->Next(4, 7);
				this->dy = 0;
				this->vida = vida_zombie_2;
				this->estaAtacando = false;
				this->indiceX = 0;
				this->indiceY = 0;
				break;
			}

		}
		else //si se dirige a la izquierda
		{
			switch (this->tipo)
			{
			case 0:
				this->x = 950;
				this->y = y;
				this->dx = -1 * r->Next(2, 5);
				this->dy = 0;
				this->vida = vida_zombie_0;
				this->estaAtacando = false;
				this->indiceX = 7;
				this->indiceY = 0;
				break;
			case 1:
				this->x = 950;
				this->y = y;
				this->dx = -1 * r->Next(2, 5);
				this->dy = 0;
				this->vida = vida_zombie_1;
				this->estaAtacando = false;
				this->indiceX = 6;
				this->indiceY = 0;
				break;
			case 2:
				this->x = 950;
				this->y = y;
				this->dx = -1 * r->Next(4, 7);
				this->dy = 0;
				this->vida = vida_zombie_2;
				this->estaAtacando = false;
				this->indiceX = 9;
				this->indiceY = 0;
				break;
			}
		}
	}


	~Zombie() {}
	void setvida(int vida) { this->vida = vida; }
	int getvida() { return vida; }
	int getIndiceX() { return indiceX; }

	void Dibujar(BufferedGraphics^ buffer, Bitmap^ bmp)
	{
		Rectangle areaUsar = Rectangle(indiceX * ancho, indiceY * alto, ancho, alto);
		Rectangle aumento = Rectangle(x, y, ancho, alto);

		buffer->Graphics->DrawImage(bmp, aumento, areaUsar, GraphicsUnit::Pixel);
		if (x + dx >= 0 && x + dx + ancho < buffer->Graphics->VisibleClipBounds.Width){ x += dx; }
	}

	void Mover(BufferedGraphics^ buffer)
	{
		Bitmap^ zombie0_derecha = gcnew Bitmap("../Contents/Zombie0_Derecha.png");
		Bitmap^ zombie0_izquierda = gcnew Bitmap("../Contents/Zombie0_Izquierda.png");
		Bitmap^ zombie1_derecha = gcnew Bitmap("../Contents/Zombie1_Derecha.png");
		Bitmap^ zombie1_izquierda = gcnew Bitmap("../Contents/Zombie1_Izquierda.png");
		Bitmap^ zombie2_derecha = gcnew Bitmap("../Contents/Zombie2_Derecha.png");
		Bitmap^ zombie2_izquierda = gcnew Bitmap("../Contents/Zombie2_Izquierda.png");

		if (this->esDerecha)
		{
			switch (this->tipo)
			{
			case 0:
				Dibujar(buffer, zombie0_derecha);
				if (indiceX >= 0 && indiceX < 7) indiceX++;
				else indiceX = 0;
				break;
			case 1:
				Dibujar(buffer, zombie1_derecha);
				if (indiceX >= 0 && indiceX < 6) indiceX++;
				else indiceX = 0;
				break;
			case 2:
				Dibujar(buffer, zombie2_derecha);
				if (indiceX >= 0 && indiceX < 9) indiceX++;
				else indiceX = 0;
				break;
			}
		}
		else
		{
			switch (this->tipo)
			{
			case 0:
				Dibujar(buffer, zombie0_izquierda);
				if (indiceX > 0 && indiceX <= 7) indiceX--;
				else indiceX = 7;
				break;
			case 1:
				Dibujar(buffer, zombie1_izquierda);
				if (indiceX > 0 && indiceX <= 6) indiceX--;
				else indiceX = 6;
				break;
			case 2:
				Dibujar(buffer, zombie2_izquierda);
				if (indiceX > 0 && indiceX <= 9) indiceX--;
				else indiceX = 9;
				break;
			}
		}

	}
	void Atacar(BufferedGraphics^ buffer)
	{
		Bitmap^ zombie0_derecha = gcnew Bitmap("../Contents/Zombie0_Ataque_Derecha.png");
		Bitmap^ zombie0_izquierda = gcnew Bitmap("../Contents/Zombie0_Ataque_Izquierda.png");
		Bitmap^ zombie1_derecha = gcnew Bitmap("../Contents/Zombie1_Ataque_Derecha.png");
		Bitmap^ zombie1_izquierda = gcnew Bitmap("../Contents/Zombie1_Ataque_Izquierda.png");
		Bitmap^ zombie2_derecha = gcnew Bitmap("../Contents/Zombie2_Ataque_Derecha.png");
		Bitmap^ zombie2_izquierda = gcnew Bitmap("../Contents/Zombie2_Ataque_Izquierda.png");
		this->dx = 0;

		if (this->esDerecha)
		{
			switch (this->tipo)
			{
			case 0:
				Dibujar(buffer, zombie0_derecha);
				if (indiceX >= 0 && indiceX < 3) indiceX++;
				else indiceX = 0;
				break;
			case 1:
				Dibujar(buffer, zombie1_derecha);
				if (indiceX >= 0 && indiceX < 3) indiceX++;
				else indiceX = 0;
				break;
			case 2:
				Dibujar(buffer, zombie2_derecha);
				if (indiceX >= 0 && indiceX < 3) indiceX++;
				else indiceX = 0;
				break;
			}

		}
		else
		{
			switch (this->tipo)
			{
			case 0:
				Dibujar(buffer, zombie0_izquierda);
				if (indiceX > 0 && indiceX < 3) indiceX--;
				else indiceX = 2;
				break;
			case 1:
				Dibujar(buffer, zombie1_izquierda);
				if (indiceX > 0 && indiceX < 3) indiceX--;
				else indiceX = 2;
				break;
			case 2:
				Dibujar(buffer, zombie2_izquierda);
				if (indiceX > 0 && indiceX < 3) indiceX--;
				else indiceX = 2;
				break;
			}
		}
	}

	Rectangle getHitbox()
	{
		Rectangle hitbox;

		switch (this->tipo)
		{
		case 0:
			hitbox = Rectangle(x + 25, y + 20, ancho - 40, alto - 20);
			break;
		case 1:
			hitbox = Rectangle(x + 25, y + 20, ancho - 40, alto - 20);
			break;
		case 2:
			hitbox = Rectangle(x, y + 50, ancho - 10, alto - 50);
			break;
		}

		return hitbox;
	}
};