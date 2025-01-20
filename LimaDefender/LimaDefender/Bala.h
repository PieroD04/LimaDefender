#pragma once
using namespace System::Drawing;

class Bala : public Entidad {
private: 
	int direccion;
	int visible;
public:
	Bala(){}

	Bala(int x, int y, int direccion)
	{
		this->x = x;
		this->y = y;
		this->visible = true;
		this->direccion = direccion;

		switch (this->direccion)
		{
		case 1: //abajo
			this->ancho = 200;
			this->alto = 300;
			this->dx = 0;
			this->dy = 20;
			break;
		case 2: //arriba
			this->ancho = 200;
			this->alto = 300;
			this->dx = 0;
			this->dy = -20;
			break;
		case 3: //izquierda
			this->ancho = 300;
			this->alto = 200;
			this->dx = -20;
			this->dy = 0;
			break;
		case 4: //derecha
			this->ancho = 300;
			this->alto = 200;
			this->dx = 20;
			this->dy = 0;
			break;
		}

	}
	~Bala() {}

	int getVisibilidad() { return this->visible; }

	void Dibujar(BufferedGraphics^ buffer) {
		Bitmap^ bala_abajo = gcnew Bitmap("../Contents/bala_abajo.png");
		Bitmap^ bala_arriba = gcnew Bitmap("../Contents/bala_arriba.png");
		Bitmap^ bala_derecha = gcnew Bitmap("../Contents/bala_derecha.png");
		Bitmap^ bala_izquierda = gcnew Bitmap("../Contents/bala_izquierda.png");
		Rectangle areaUsar = Rectangle(0, 0, ancho, alto);
		Rectangle aumento_arriba = Rectangle(x + 16, y - 25, ancho/10, alto/10);
		Rectangle aumento_abajo = Rectangle(x + 16, y + 20, ancho / 10, alto / 10);
		Rectangle aumento_derecha = Rectangle(x + 37, y + 25, ancho / 10, alto / 10);
		Rectangle aumento_izquierda = Rectangle(x - 25, y + 25, ancho / 10, alto / 10);
		switch (this->direccion)
		{
		case 1: //abajo
			buffer->Graphics->DrawImage(bala_abajo, aumento_abajo, areaUsar, GraphicsUnit::Pixel);
			break;
		case 2: //arriba
			buffer->Graphics->DrawImage(bala_arriba, aumento_arriba, areaUsar, GraphicsUnit::Pixel);
			break;
		case 3: //izquierda
			buffer->Graphics->DrawImage(bala_izquierda, aumento_izquierda, areaUsar, GraphicsUnit::Pixel);
			break;
		case 4: //derecha
			buffer->Graphics->DrawImage(bala_derecha, aumento_derecha, areaUsar, GraphicsUnit::Pixel);
			break;
		}

		if (x + dx >= 0 && x + dx + ancho/10 < buffer->Graphics->VisibleClipBounds.Width) { x += dx; }
		else this->visible = false;
		
		if (y + dy >= 0 && y + dy + alto/10 < buffer->Graphics->VisibleClipBounds.Height) { y += dy; }
		else this->visible = false;

	}

	Rectangle getHitbox()
	{
		Rectangle hitbox;

		switch (this->direccion)
		{
		case 1:
			hitbox = Rectangle(x + 16, y - 25, ancho / 10, alto / 10);
			break;
		case 2:
			hitbox = Rectangle(x + 16, y + 20, ancho / 10, alto / 10);
			break;
		case 3:
			hitbox = Rectangle(x + 37, y + 25, ancho / 10, alto / 10);
			break;
		case 4:
			hitbox = Rectangle(x - 25, y + 25, ancho / 10, alto / 10);
			break;
		}
		return hitbox;
	}
};