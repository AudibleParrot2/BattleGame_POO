/*
Ricardo Nuñez Alanis
A01703259
Programacion orientada a objetos
Proyecto final
*/
/*
Clase Hunter, recibe elementos vacios de los stats y los llena
Crea las acciones de los ataques y las guardias
*/
#ifndef HUNTER_H
#define HUNTER_H

#include <cstdlib>
#include <ctime>
#include <iostream>
#include "rol.h"
#include "monster.h"

class Hunter: public Rol
{
	public:
		Hunter(string nam):Rol(nam,150,40,30,25){//Recibe parametros vacios y da valores
			
		}
		void Bow(Monster &m){//Accion de ataque con stat de atk
			m.damage(getAttack()+30);
		}
		void Arcane_Shot(Monster &m){//Accion de ataque con stat de mag
			m.damage(getMagic()+30);
		}
		void Guard(Rol &r){//Accion de defensa
			r.guarding(getDefense());
		}

};

#endif
