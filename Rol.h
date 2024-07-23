/*
Ricardo Nuñez Alanís
A01703259
Programacion orientada a objetos
Proyecto final
*/
/*
Clase rol le hereda ints y sitrings a sus respectivas clases
Tambien tiene funciones para que el programa funcione
*/
#ifndef ROL_H
#define ROL_H

#include <iostream>
using namespace std;
class Rol{
	
	private:	
		int health;
		int attack;
		int defense;
		int magic;
		
		string name;
	
	public:
		Rol(string nam, int hp, int atk, int def, int mag){//constructor
			name = nam;
			health = hp;
			attack = atk;
			defense = def;
			magic = mag;
		}
		//getters
		int getHealth (){
			return health;
		}
		int getAttack (){
			return attack;
		}
		int getDefense (){
			return defense;
		}
		int getMagic (){
			return magic;
		}
		string getName (){
			return name;
		}
		
		void damage(int damage){//Funcion para hacer el daño
			health = health - damage;
		}
		void guarding (int guarding){ //Funcion para hacer defensa o recibir menos daño  
			health = health + guarding;
		}
		//setters
		void setHealth(int h){
			health = h;
		}
		void setAttack(int a){
			attack = a;
		}
		void setDefense(int d){
			defense = d;
		}
		void setMagic(int m){
			magic = m;
		}
};
#endif
