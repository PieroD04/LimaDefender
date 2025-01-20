#pragma once
#include "Entidad.h"
#include "Laser.h"
#include <vector>
class Aliado : public Entidad
{
private:
	int color;
	int n_lasers;
	bool estado;
	std::vector<Laser*> lasers;
public:
	Aliado(int x, int y, int dx, int color) :Entidad()
	{
		this->ancho = 128;
		this->alto = 128;
		this->x = x;
		this->y = y;
		this->dx = dx;
		this->dy = 0;
		this->estado = false;
		this->color = color;
		this->n_lasers = 0;
		indiceX = 0;
		indiceY = 0;
	}

	~Aliado() {}

	bool getestado_aliado() { return this->estado; }
	void setestado_aliado(bool estado) { this->estado = estado; }

	int getn_lasers() { return this->n_lasers; }

	void Dibujar(BufferedGraphics^ buffer)
	{
		if (color == 0) {
			Bitmap^ maquina = gcnew Bitmap("../Contents/Aliado_verde.png");
			Rectangle areaUsar = Rectangle(0, 0, ancho, alto);
			Rectangle aumento = Rectangle(x, y, 88, 88);
			buffer->Graphics->DrawImage(maquina, aumento, areaUsar, GraphicsUnit::Pixel);
		}
		if (color == 1) {
			Bitmap^ maquina = gcnew Bitmap("../Contents/Aliado_azul.png");
			Rectangle areaUsar = Rectangle(0, 0, ancho, alto);
			Rectangle aumento = Rectangle(x, y, 88, 88);
			buffer->Graphics->DrawImage(maquina, aumento, areaUsar, GraphicsUnit::Pixel);
		}
	
	}

	void Mover(BufferedGraphics^ buffer)
	{
		if (x + dx < 0 || x + dx + ancho > buffer->Graphics->VisibleClipBounds.Width) {
			this->dx *= -1;
		}
		Dibujar(buffer);
		x += dx;
	}

	void addLaser()
	{
		if (color == 0)
		{
			lasers.push_back(new Laser(this->x, this->y, 0));
			this->n_lasers++;
		}
		if (color == 1)
		{
			lasers.push_back(new Laser(this->x, this->y, 1));
			this->n_lasers++;
		}
	}

	void Movimiento_Lasers(BufferedGraphics^ buffer)
	{
		for (int i = 0; i < lasers.size(); i++)
		{
			lasers.at(i)->Mover(buffer);
		}
	}

	void Eliminar_Lasers()
	{
		for (int i = 0; i < lasers.size(); i++)
		{
			if (!lasers.at(i)->getVisibilidad())
			{
				delete lasers.at(i);
				lasers.erase(lasers.begin() + i);
				n_lasers--;
				i--;
			}
		}
	}

	void Colision_Laser(int i)
	{
		delete lasers.at(i);
		lasers.erase(lasers.begin() + i);
		n_lasers--;
	}


	Rectangle getHitbox_lasers(int i)
	{
		return lasers.at(i)->getHitbox();
	}
};
