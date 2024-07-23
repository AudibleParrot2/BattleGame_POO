/*
Ricardo Nuñez Alanis
A01703259
Programacion orientada a objetos
Proyecto final
*/
/*
Clase Spider, recibe elementos vacios de los stats y los llena
Crea las acciones de los ataques y las guardias
*/
#ifndef SPIDER_H
#define SPIDER_H

#include <cstdlib>
#include <ctime>
#include <iostream>
#include "rol.h"
#include "monster.h"

class Spider: public Monster
{
	public:
		Spider(string nam):Monster(nam,300,50,50,60){//Recibe parametros vacios y da valores
			
		}
		void Bite(Rol &r){//Accion de ataque con stat de atk
			r.damage(getAttack());
		}
		void Venom(Rol &r){//Accion de ataque con stat de mag
			r.damage(getMagic());
		}
		void Guard(Monster &m){//Accion de defensa
			m.guarding(getDefense());
		}

};
#endif
