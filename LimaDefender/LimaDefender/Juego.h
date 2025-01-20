#pragma once
#include "Zombie.h"
#include "Generador.h"
#include "Aliado.h"
#include "Jugador.h"
#include "Laser.h"
#include "Bomba.h"
#include "Boss.h"
#include <vector>

using namespace std;
using namespace System;
using namespace System::Drawing;
using namespace Windows::Forms;

const int max_oleada = 15;

class Juego
{
private:
	vector<Zombie*> zombies;
	Boss* jefe;
	Generador* estructura;
	Aliado* maquina_verde;
	Aliado* maquina_azul;
	Bomba* bomb;
	Jugador* player;
	int tiempo_restante;
	int puntaje;
	int n_zombies;
	int estado;
	int n_oleadas;
public:
	Juego()
	{
		this->estructura = new Generador();
		this->maquina_verde = new Aliado(600, 250, 10, 0);
		this->maquina_azul = new Aliado(300, 150, -10, 1);
		this->bomb = new Bomba();
		this->player = new Jugador(300, 450);
		this->jefe = new Boss(900, 400);
		this->tiempo_restante = 500;
		this->n_zombies = 0;
		this->puntaje = 0;
		this->estado = 0;
		this->n_oleadas = 0;
	}
	~Juego() {}
	//valores de juego
	int getestado() { return this->estado; }
	int getpuntaje() { return this->puntaje; }
	//Movimiento de jugador y añadir aliados
	void detectarTeclas(Keys tecla, bool accion)
	{
		if (accion == true)
		{
			switch (tecla)
			{
				//Movimiento del jugador:
			case Keys::Left:
				player->setDireccion(3);
				break;
			case Keys::Right:
				player->setDireccion(4);
				break;
			case Keys::Up:
				player->setDireccion(2);
				break;
			case Keys::Down:
				player->setDireccion(1);
				break;
				//Disparar
			case Keys::Space:
				player->setDireccion(0);
				player->setDisparo(true);
				break;
			case Keys::L:
				if (maquina_azul->getestado_aliado() == false) maquina_azul->setestado_aliado(true);
				else if (maquina_verde->getestado_aliado() == false) maquina_verde->setestado_aliado(true);
				break;
			}
		}
		else
		{
			player->setDireccion(0);
		}
	
	}
	//Movimiento y colisiones
	void dibujarTodo(BufferedGraphics^ buffer)
	{
		colision_bomba();
		if (bomb->getvisible()) bomb->dibujar(buffer);
		
		estructura->Dibujar(buffer);
		estructura->Dibujar_barra(buffer);
		//Jugador
		if(!player->getDisparo()) player->mueveJugador(buffer);
		else
		{
			player->setDireccion(0);
			player->mueveJugador(buffer);
			player->addBala();
			player->setDisparo(false);
		}
		//Balas
		player->moverBalas(buffer);
		//Maquinas
		if (maquina_azul->getestado_aliado() == true)
		{
			maquina_azul->Mover(buffer);
			maquina_azul->Movimiento_Lasers(buffer);
		}

		if (maquina_verde->getestado_aliado() == true)
		{
			maquina_verde->Mover(buffer);
			maquina_verde->Movimiento_Lasers(buffer);
		}

		for (int i = 0; i < zombies.size(); i++)
		{
			if (colision_generador(i))
			{
				if (zombies.at(i)->getIndiceX() == 2) estructura->reducirvida(1); //Solo hara daño 1 vez cada repeticion de movimiento
				zombies.at(i)->Atacar(buffer);
			}//Movimiento zombies
			else zombies.at(i)->Mover(buffer);

			if (colision_zombie_laser_verde(i)) zombies.at(i)->setvida(zombies.at(i)->getvida()- 2);
			if (colision_zombie_laser_azul(i)) zombies.at(i)->setvida(zombies.at(i)->getvida() - 2);
			if (colision_zombie_bala(i)) zombies.at(i)->setvida(zombies.at(i)->getvida() - 1);
		}
	}
	//Boss
	void boss_ataque() { jefe->atacar(); }
	//Colisiones:
	bool colision_generador(int i)
	{
		Rectangle r_zombie;
		r_zombie = zombies.at(i)->getHitbox();

		if (r_zombie.IntersectsWith(estructura->getHitbox())) return true;

		return false;
	}
	bool colision_zombie_laser_verde(int i)
	{
		//Colision lasers: maquina verde
		for (int j = 0; j < maquina_verde->getn_lasers(); j++)
		{
			if (maquina_verde->getHitbox_lasers(j).IntersectsWith(zombies.at(i)->getHitbox()))
			{
				maquina_verde->Colision_Laser(j);
				return true;
			}
		}
		return false;
	}
	bool colision_zombie_laser_azul(int i)
	{
		//Colision lasers: maquina azul
		for (int j = 0; j < maquina_azul->getn_lasers(); j++)
		{
			if (maquina_azul->getHitbox_lasers(j).IntersectsWith(zombies.at(i)->getHitbox()))
			{
				maquina_azul->Colision_Laser(j);
				return true;
			}
		}
		return false;
	}
	bool colision_zombie_bala(int i)
	{
		//Colision balas: jugador
		for (int j = 0; j < player->getn_balas(); j++)
		{
			if (player->getHitbox_balas(j).IntersectsWith(zombies.at(i)->getHitbox()))
			{
				player->Colision_Bala(j);
				return true;
			}
		}
		return false;
	}
	void colision_bomba()
	{
		if (bomb->getHitbox().IntersectsWith(estructura->getHitbox())) bomb->reposicionar();
		if (bomb->getHitbox().IntersectsWith(player->getHitbox()) && bomb->getvisible())
		{
			bomb->setvisible(false);
			bomb->reposicionar();
			for (int i = 0; i < zombies.size(); i++) zombies.at(i)->setvida(0);
			jefe->dañar();
		}
	}
	//Oleadas de zombies
	void oleadas(int n)
	{
		switch (n) //Oleadas
		{
		case 0:
			zombies.push_back(new Zombie(1, true, 370));
			zombies.push_back(new Zombie(0, true, 390));
			zombies.push_back(new Zombie(1, true, 410));
			zombies.push_back(new Zombie(0, false, 430));
			zombies.push_back(new Zombie(1, false));
			n_zombies += 5;
			break;
		case 1:
			zombies.push_back(new Zombie(1, true, 370));
			zombies.push_back(new Zombie(0, true, 390));
			zombies.push_back(new Zombie(1, true, 410));
			zombies.push_back(new Zombie(1, true, 420));
			zombies.push_back(new Zombie(0, true, 430));
			zombies.push_back(new Zombie(1, true));
			n_zombies += 6;
			break;
		case 2:
			zombies.push_back(new Zombie(1, false, 380));
			zombies.push_back(new Zombie(0, false, 388));
			zombies.push_back(new Zombie(1, false, 400));
			zombies.push_back(new Zombie(1, false, 410));
			zombies.push_back(new Zombie(0, false, 420));
			zombies.push_back(new Zombie(1, false));
			n_zombies += 6;
			break;
		case 3:
			zombies.push_back(new Zombie(1, true));
			zombies.push_back(new Zombie(0, false, 370));
			zombies.push_back(new Zombie(0, true, 390));
			zombies.push_back(new Zombie(0, false, 400));
			zombies.push_back(new Zombie(0, true, 370));
			zombies.push_back(new Zombie(0, false, 410));
			zombies.push_back(new Zombie(0, false));
			n_zombies += 7;
			break;
		case 4:
			zombies.push_back(new Zombie(2, true, 370));
			zombies.push_back(new Zombie(2, true, 410));
			zombies.push_back(new Zombie(2, false, 370));
			zombies.push_back(new Zombie(2, false, 410));
			zombies.push_back(new Zombie(2, true, 390));
			zombies.push_back(new Zombie(2, false, 390));
			n_zombies += 6;
			break;
		}
	}
	//Bomba
	void activar_bomba() { bomb->setvisible(true); }
	//Niveles
	void Nivel1(BufferedGraphics^ buffer)
	{
		//Oleadas
		if(n_zombies <= 0) 
		{
			Random^ r = gcnew Random();	
			oleadas(r->Next(0, 4));
			n_oleadas++;
		}
		//Eliminar zombies
		for (int i = 0; i < zombies.size(); i++)	
		{
			if (zombies.at(i)->getvida() < 1)
			{
				delete zombies.at(i);
				zombies.erase(zombies.begin() + i);
				i--;
				n_zombies--;
				puntaje++;
			}
		}
		//Generación de laseres
		if (maquina_azul->getestado_aliado() == true)
		{
			if (maquina_azul->getx() % 9 == 0 || maquina_verde->getx() % 7 == 0) { maquina_azul->addLaser(); }
			//Eliminar laseres colisionados
			maquina_azul->Eliminar_Lasers();
		}
		if (maquina_verde->getestado_aliado() == true)
		{
			if (maquina_verde->getx() % 7 == 0 || maquina_verde->getx() % 13 == 0) { maquina_verde->addLaser(); }
			//Eliminar laseres colisionados
			maquina_verde->Eliminar_Lasers();
		}
		//Eliminar balas colisionadas
		player->eliminarBalas();
		//dibujar
		dibujarTodo(buffer);
		//Estado del generador
		estructura->estadoGenerador();

		if (estructura->getvida() <= 0) //fin del juego
		{
			this->estado = 1;
		}
		if (n_oleadas >= max_oleada) this->estado = 2;
		
	}
	void Nivel2(BufferedGraphics^ buffer)
	{
		//Oleadas de zombies bestia
		if (n_zombies <= 0)
		{
			oleadas(4);
			n_oleadas++;
		}
		//Eliminar zombies
		for (int i = 0; i < zombies.size(); i++)
		{
			if (zombies.at(i)->getvida() < 1)
			{
				delete zombies.at(i);
				zombies.erase(zombies.begin() + i);
				i--;
				n_zombies--;
				puntaje++;
			}
		}
		//Generación de laseres
		if (maquina_azul->getestado_aliado() == true)
		{
			if (maquina_azul->getx() % 9 == 0 || maquina_verde->getx() % 7 == 0) { maquina_azul->addLaser(); }
			//Eliminar laseres colisionados
			maquina_azul->Eliminar_Lasers();
		}
		if (maquina_verde->getestado_aliado() == true)
		{
			if (maquina_verde->getx() % 7 == 0 || maquina_verde->getx() % 13 == 0) { maquina_verde->addLaser(); }
			//Eliminar laseres colisionados
			maquina_verde->Eliminar_Lasers();
		}
		//Eliminar balas colisionadas
		player->eliminarBalas();
		//dibujar
		dibujarTodo(buffer);
		//Estado del generador
		estructura->estadoGenerador();

		//animar jefe
		jefe->Dibujar(buffer);
		//el jefe ha escupido? XD
		if (jefe->gethaDaniado())
		{
			jefe->sethaDaniado(false);
			estructura->reducirvida(15);
		}
	
		if (estructura->getvida() <= 0) //formas de finalizar el juego
		{
			this->estado = 1;
		}
		if (jefe->getvida() == 0) this->estado = 2;

		//Indicador de vida
		buffer->Graphics->DrawString(
			"" + jefe->getvida(),
			gcnew Font("Impact", 64),
			Brushes::White,
			RectangleF(800, 0, 200, 200));
	}






};