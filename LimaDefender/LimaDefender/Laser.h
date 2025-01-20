#pragma once
#include "Entidad.h"

class Laser : public Entidad
{
private:
	int color;
	int visible;
public:
	Laser(int x_maquina, int y_maquina, int color) :Entidad()
	{
		this->ancho = 17;
		this->alto = 29;
		this->x = x_maquina + 34;
		this->y = y_maquina + 63;
		this->dx = 0;
		this->dy = 10;
		this->color = color;
		this->visible = true;
		this->indiceX = 0;
		this->indiceY = 0;
	}

	~Laser() {}

	int getVisibilidad() { return this->visible; }

	void Dibujar(BufferedGraphics^ buffer)
	{
		Rectangle areaUsar = Rectangle(0, 0, ancho, alto);
		Rectangle aumento = Rectangle(x, y, ancho, alto);

		if (color == 0) {
			Bitmap^ red_laser = gcnew Bitmap("../Contents/red_laser.png");
			buffer->Graphics->DrawImage(red_laser, aumento, areaUsar, GraphicsUnit::Pixel);
		}
		if (color == 1) {
			Bitmap^ blue_laser = gcnew Bitmap("../Contents/blue_laser.png");
			buffer->Graphics->DrawImage(blue_laser, aumento, areaUsar, GraphicsUnit::Pixel);
		}

		
	}

	void Mover(BufferedGraphics^ buffer) {
		
		Dibujar(buffer);
		if (y + dy + alto < buffer->Graphics->VisibleClipBounds.Height) y += dy;
		else visible = false;
	}

	Rectangle getHitbox()
	{
		Rectangle hitbox;
		hitbox = Rectangle(x, y + 50, ancho - 10, alto - 50);
		return hitbox;
	}
};

