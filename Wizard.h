/*
Ricardo Nuñez Alanis
A01703259
Programacion orientada a objetos
Proyecto final
*/
/*
Clase Wizard, recibe elementos vacios de los stats y los llena
Crea las acciones de los ataques y las guardias
*/
#ifndef WIZARD_H
#define WIZARD_H

#include <cstdlib>
#include <ctime>
#include <iostream>
#include "rol.h"
#include "monster.h"

class Wizard: public Rol
{
	public:
		Wizard(string nam):Rol(nam,150,20,20,50){//Recibe parametros vacios y da valores
			
		}
		void Staff(Monster &m){//Accion de ataque con stat de atk
			m.damage(getAttack()+30);
		}
		void Fireball(Monster &m){//Accion de ataque con stat de mag
			m.damage(getMagic()+30);
		}
		void Guard(Rol &r){//Accion de defensa
			r.guarding(getDefense());
		}

};
#endif
