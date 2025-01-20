#pragma once
using namespace System;
using namespace System::Drawing;

class Generador
{
private:
	int x;
	int y;
	int ancho;
	int alto;
	int indiceX;
	int indiceY;
	int vida;
public:
	Generador()
	{
		this->x = 430;
		this->y = 440;
		this->ancho = 312;
		this->alto = 137;
		this->indiceX = 0;
		this->indiceY = 0;
		this->vida = 300;
	}

	~Generador() {}

	int getvida() { return this->vida; }
	void reducirvida(int danio) { this->vida -= danio; }

	void Dibujar_barra(BufferedGraphics^ buffer)
	{
		int ancho_barra = 451;
		int alto_barra = 92;
		int indice_alto = 5;
		if (vida <= 300) indice_alto = 5;
		if (vida < 230) indice_alto = 4;
		if (vida < 170) indice_alto = 3;
		if (vida < 110) indice_alto = 2;
		if (vida < 50) indice_alto = 1;

		Bitmap^ barra = gcnew Bitmap("../Contents/HealthBar.png");
		Rectangle areaUsar = Rectangle(0, indice_alto * alto_barra, ancho_barra, alto_barra);
		Rectangle aumento = Rectangle(10, 10, ancho_barra - 120, alto_barra - 30);

		buffer->Graphics->DrawImage(barra, aumento, areaUsar, GraphicsUnit::Pixel);
	}

	void Dibujar(BufferedGraphics^ buffer)
	{
		Bitmap^ generador = gcnew Bitmap("../Contents/generador.png");
		Rectangle areaUsar = Rectangle(indiceX * ancho , indiceY * alto, ancho, alto);
		Rectangle aumento = Rectangle(x, y, ancho - 100, alto - 50);

		buffer->Graphics->DrawImage(generador, aumento, areaUsar, GraphicsUnit::Pixel);
	}
	void estadoGenerador()
	{
		if (vida <= 300) { indiceX = 0; indiceY = 0; }
		if (vida < 230) { indiceX = 2; indiceY = 0; }
		if (vida < 170) { indiceX = 0; indiceY = 1; }
		if (vida < 110) { indiceX = 2; indiceY = 1; };
		if (vida < 50) { indiceX = 0; indiceY = 2; }
	}

	Rectangle getHitbox()
	{
		Rectangle hitbox;

		hitbox = Rectangle(x + 10, y + 10, ancho - 120, alto - 70);

		//buffer->Graphics->DrawRectangle(gcnew Pen(Color::Red), hitbox);

		return hitbox;
	}









};