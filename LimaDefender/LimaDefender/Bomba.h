#pragma once
using namespace System;
using namespace System::Drawing;

class Bomba
{
private:
	int x, y, ancho, alto;
	bool visible;
public:
	Bomba()
	{
		Random^ r = gcnew Random();
		this->x = r->Next(0, 950);
		this->y = r->Next(430, 450);
		this->ancho = 32;
		this->alto = 32;
		this->visible = true;
	}
	~Bomba() {}
	void setvisible(bool visible) { this->visible = visible; }
	bool getvisible() { return this->visible; }
	void reposicionar()
	{
		Random^ r = gcnew Random();
		this->x = r->Next(0, 950);
		this->y = r->Next(430, 450);
	}
	void dibujar(BufferedGraphics^ buffer)
	{
		Bitmap^ bomba = gcnew Bitmap("../Contents/Bomb.png");

		System::Drawing::Rectangle areaUsar = System::Drawing::Rectangle(0, 0, ancho, alto);
		System::Drawing::Rectangle aumento = System::Drawing::Rectangle(x, y, ancho, alto);
		buffer->Graphics->DrawImage(bomba, aumento, areaUsar, GraphicsUnit::Pixel);
	}

	System::Drawing::Rectangle getHitbox()
	{
		return System::Drawing::Rectangle(x, y, ancho, alto);
	}





};