#pragma once
#include "Entidad.h"
#include "Bala.h"

using namespace System::Drawing;

class Jugador : public Entidad {
private:
	bool haDisparado;
	int ultimaTecla;
	int direccion;
	int n_balas;
	std::vector<Bala*> balas;
public:
	Jugador() : Entidad() {}

	Jugador(int x, int y) {
		this->x = x;
		this->y = y;
		this->dx = 0;
		this->dy = 0;
		this->ultimaTecla = 1;
		this->direccion = 0;
		this->ancho = 64;
		this->alto = 70;
		this->indiceX = 0;
		this->indiceY = 0;
		this->haDisparado = false;
		this->n_balas = 0;
	}

	~Jugador() {}

	int getn_balas() { return this->n_balas; }
	void setDisparo(bool haDisparado) { this->haDisparado = haDisparado; }
	bool getDisparo() { return this->haDisparado; }
	void addBala() { balas.push_back(new Bala(this->x, this->y, this->ultimaTecla)); n_balas++; }
	void moverBalas(BufferedGraphics^ buffer) {for (int i = 0; i < balas.size(); i++) balas.at(i)->Dibujar(buffer);}
	void setDireccion(int direccion) { this->direccion = direccion; }

	void eliminarBalas()
	{
		for (int i = 0; i < balas.size(); i++)
		{
			if (!balas.at(i)->getVisibilidad())
			{
				delete balas.at(i);
				balas.erase(balas.begin() + i);
				n_balas--;
				i--;
			}
		}
	}
	void Dibujar(BufferedGraphics^ buffer, Bitmap^ bmp) {
		Rectangle areaUsar = Rectangle(indiceX * ancho, indiceY * alto, ancho, alto);
		Rectangle aumento = Rectangle(x, y, ancho / 1.2, alto / 1.2);
		buffer->Graphics->DrawImage(bmp, aumento, areaUsar, GraphicsUnit::Pixel);

		if (x + dx >= 0 && x + dx + ancho / 1.2 < buffer->Graphics->VisibleClipBounds.Width) {
			x += dx;
		}
		if (y + dy >= 420 && y + dy + alto / 1.2 < buffer->Graphics->VisibleClipBounds.Height) {
			y += dy;
		}

	}
	void mueveJugador(BufferedGraphics^ buffer) {
		Bitmap^ jugadorIdle = gcnew Bitmap("../Contents/Principal_IdleArma.png");
		Bitmap^ jugadorCamina = gcnew Bitmap("../Contents/Principal_CaminaArmado.png");

		switch (direccion) //Movimiento
		{
		case 1: //Abajo = 1
			indiceY = 0;
			if (indiceX >= 0 && indiceX < 5) {
				indiceX++;
			}
			else {
				indiceX = 0;
			}
			dx = 0;
			dy = 6;
			ultimaTecla = 1;
			Dibujar(buffer, jugadorCamina);
			break;
		case 2: //Arriba = 2
			indiceY = 3;
			if (indiceX >= 0 && indiceX < 5) {
				indiceX++;
			}
			else {
				indiceX = 0;
			}
			dx = 0;
			dy = -6;
			ultimaTecla = 2;
			Dibujar(buffer, jugadorCamina);
			break;

		case 3: // Izquierda = 3
			indiceY = 1;
			if (indiceX >= 0 && indiceX < 5) {
				indiceX++;
			}
			else {
				indiceX = 0;
			}
			dx = -8;
			dy = 0;
			ultimaTecla = 3;
			Dibujar(buffer, jugadorCamina);
			break;
		case 4: //Derecha = 4
			indiceY = 2;
			if (indiceX >= 0 && indiceX < 5) {
				indiceX++;
			}
			else {
				indiceX = 0;
			}
			dx = 8;
			dy = 0;
			ultimaTecla = 4;
			Dibujar(buffer, jugadorCamina);
			break;
		case 0: //Jugador quieto Ninguna = 0
			dx = 0;
			dy = 0;
			switch (ultimaTecla)
			{
			case 1:
				indiceX = 0;
				indiceY = 0;
				break;
			case 2:
				indiceX = 2;
				indiceY = 0;
				break;
			case 3:
				indiceX = 1;
				indiceY = 0;
				break;
			case 4:
				indiceX = 3;
				indiceY = 0;
				break;
			}
			Dibujar(buffer, jugadorIdle);
			break;
		}
	}
	void Colision_Bala(int i)
	{
		delete balas.at(i);
		balas.erase(balas.begin() + i);
		n_balas--;
	}
	Rectangle getHitbox_balas(int i)
	{
		return balas.at(i)->getHitbox();
	}

	Rectangle getHitbox()
	{
		Rectangle hitbox;
		hitbox = Rectangle(x + 15, y + 10, ancho - 40, alto - 20);
		return hitbox;
	}


};

