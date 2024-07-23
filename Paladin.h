/*
Ricardo Nuñez Alanis
A01703259
Programacion orientada a objetos
Proyecto final
*/
/*
Clase Paladin, recibe elementos vacios de los stats y los llena
Crea las acciones de los ataques y las guardias
*/
#ifndef PALADIN_H
#define PALADIN_H

#include <cstdlib>
#include <ctime>
#include <iostream>
#include "rol.h"
#include "monster.h"

class Paladin: public Rol
{
	public:
		Paladin(string nam):Rol(nam,200,10,50,25){//Recibe parametros vacios y da valores
			
		}
		void Sword(Monster &m){//Accion de ataque con stat de atk
			m.damage(getAttack()+30);
		}
		void Smite(Monster &m){//Accion de ataque con stat de mag
			m.damage(getMagic()+30);
		}
		void Guard(Rol &r){//Accion de defensa
			r.guarding(getDefense());
		}

};
#endif
