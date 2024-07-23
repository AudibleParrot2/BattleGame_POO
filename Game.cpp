/*
Ricardo Nuñez Alanis
A01703259
Programacion orientada a objetos
Proyecto final
Diciembre / 4 / 2020
*/
/*
Este proyecto se baso en crear una simple pelea de un based-turned RPG
|------------------------------------------------------------------------------------------------------------------------------------------------|
Casos de prueba:
El la primera eleccion de casos:
1 -> Paladin
2 -> Hunter
3 -> Wizard
Despues de esto podras elegir diferentes acciones:
1 -> Ataque Fisico
2 -> Ataque Magico
3 -> Defenderse o Curarse (Depende del movimiento del enemimgo)
HAVE FUN!!!
|------------------------------------------------------------------------------------------------------------------------------------------------|
*/
//Bibliotecas
#include <iostream> //imprimir
#include <cstdlib> //random number generator
#include <ctime> //timer for order of turns

using namespace std;

//Tipos de herencias
#include "paladin.h"
#include "hunter.h"
#include "wizard.h"
#include "spider.h"

//Procedimiento del programa
int main()
{
	int election;
	int init;
	string username;
	
	//Introducir las herencias incluidas previamente con un nombre
	Paladin pala("Bill Ding");
	Hunter hunt("Al E. Gater");
	Wizard wiza("Otto Graf");
	Spider spid("Hoo Lee Fuk");
	
	//Iniciativa y manera de elegir aleatoriamente quien empieza
	srand(unsigned(time(0)));
	init = rand()%2+1;
	
	cout << "...\n";
	cout << "........\n";
	cout << "................\n";
	cout << "............................\n";
	cout << "'It's time to wake up...'\n";
	cout << "'Open your eyes... Quickly!!!'\n";
	cout << "The first thing you see... a enormous spider in front of YOU!\n\n";
	cout << "Choose a class\n 1 -> Paladin \n 2 -> Hunter \n 3 -> Wizard \n\n";
	
	//Te permite elegir que personaje te gustaria jugar (Elegir entre 3 casos)
	do{cin >> election;} while(election > 3 || election < 1);
	switch(election)
	{
		case 1:	//Te permite jugar como paladin y te enseña tus stats y los de tu oponente
			cout << " \n" << pala.getName() << " \n" << pala.getHealth()<< " Hp\n" << pala.getAttack() << " Str\n" << pala.getDefense()<< " Def\n" << pala.getMagic()<< " Mag\n" << endl;
			cout << "\n";
			cout << "'Let me help you, this is what I know of your opponent'\n";
			cout <<  " \n" << "Name:\n" << spid.getName() << " \n" << spid.getHealth()<< " Hp\n" << spid.getAttack() << " Str\n" << spid.getDefense()<< " Def\n" << spid.getMagic()<< " Mag\n" << endl;
			if (init == 1)
			{
				cout << "Your turn!\n";
			}
			while(pala.getHealth() > 0 || spid.getHealth() > 0){//Mientras tu y el enemigo tengan vida, el juego seguira corriendo
				cout << "What's your decision?\n 1 -> Attack with Sword \n 2 -> Smite him \n 3 -> Guard/Heal(If enemy doesn't attack) \n";
				//Te permite elegir entre 3 casos
				do{cin >> election;} while(election > 3 || election < 1);
				switch(election){
					case 1://Te deja hacer un ataque con tu stat de atk
						pala.Sword(spid);   
						cout << " \n"<< "You did " << pala.getAttack()+30<< " damage\n" << endl;
						break;
					case 2://Te deja hacer un ataque con tu stat de mag
						pala.Smite(spid);
						cout << " \n"<< "You did " << pala.getMagic()+30<< " damage\n" << endl;
						break;
					case 3://Te permite bloquear cierta cantidad de ataque
						pala.Guard(pala);
						cout << " \n"<< "You blocked " << pala.getDefense()<< " damage\n" << endl;
						break;
				}
				election = rand()%3; //Elige aleatoriamente lo que hará el enemigo
		
				switch(election){
		
					case 1://Permite al enemigo hacer un ataque con su stat de atk
						spid.Bite(pala);
						cout << "The monster dealt " << spid.getAttack() << " damage."<< endl;
						break;
					case 2://Permite al enemigo hacer un ataque con su stat de mag
						spid.Venom(pala);
						cout << "The monster dealt " << spid.getMagic() << " damage."<< endl;
						break;
					case 3://Permite al enemigo bloquear cantidad del ataque
						spid.Guard(spid);
						cout << "The monster blocked " << spid.getDefense() << " damage."<< endl;
						break;
				
				election = rand()%3;}
				
				cout << "The monster now has " << spid.getHealth() << " HP left.\n"; //Imprime la cantidad de vida que le queda al enemigo
				if(spid.getHealth() < 1){//Imprime y cierra el programa si el personaje gana
				cout << "You killed the monster! Beta completed!\n";
				return 0;
				}
				cout << "Your current HP is " << pala.getHealth() <<"!\n"; //Imprime la cantidad de vida que le queda al jugador
				if (pala.getHealth() < 1){//Imprime y cierra el programa si el personaje pierde
					cout << "You died! The monster fled with " << spid.getHealth() << " HP left... GAME OVER\n";
					return 0;
				}
				else{//Se repite la misma logica del codigo para que el enemigo tenga oportunidad de atacar primero
					cout << "Your turn!\n";
			while(pala.getHealth() > 0 || spid.getHealth() > 0){
				cout << "What's your decision?\n 1 -> Attack with Sword \n 2 -> Smite him \n 3 -> Guard/Heal(If enemy doesn't attack) \n";
				do{cin >> election;} while(election > 3 || election < 1);
				switch(election){
					case 1:
						pala.Sword(spid);  
						cout << " \n"<< "You did " << pala.getAttack()+30<< " damage\n" << endl;
						break;
					case 2:
						pala.Smite(spid);
						cout << " \n"<< "You did " << pala.getMagic()+30<< " damage\n" << endl;
						break;
					case 3:
						pala.Guard(pala);
						cout << " \n"<< "You blocked " << pala.getDefense()<< " damage\n" << endl;
						break;
				}
				election = rand()%3;
		
				switch(election){
		
					case 1:
						spid.Bite(pala);
						cout << "The monster dealt " << spid.getAttack() << " damage."<< endl;
						break;
					case 2:
						spid.Venom(pala);
						cout << "The monster dealt " << spid.getMagic() << " damage."<< endl;
						break;
					case 3:
						spid.Guard(spid);
						cout << "The monster blocked " << spid.getDefense() << " damage."<< endl;
						break;
				
				election = rand()%3;}
				
				cout << "The monster now has " << spid.getHealth() << " HP left.\n";
				if(spid.getHealth() < 1){
				cout << "You killed the monster! Beta completed!\n";
				return 0;
				}
				cout << "Your current HP is " << pala.getHealth() <<"!\n";
				if (pala.getHealth() < 1){
					cout << "You died! The monster fled with " << spid.getHealth() << " HP left... GAME OVER\n";
					return 0;
				}
			}
			}
			break;
		case 2://CASO 2! Este funciona completamente igual que el caso 1, pero con los stats del hunter -------------------------------------------------------
			cout << " \n" << hunt.getName() << " \n" << hunt.getHealth()<< " Hp\n" << hunt.getAttack() << " Str\n" << hunt.getDefense()<< " Def\n" << hunt.getMagic()<< " Mag\n" << endl;
			cout << "\n";
			cout << "'Let me help you, this is what I know of your opponent'\n";
			cout <<  " \n" << "Name:\n" << spid.getName() << " \n" << spid.getHealth()<< " Hp\n" << spid.getAttack() << " Str\n" << spid.getDefense()<< " Def\n" << spid.getMagic()<< " Mag\n" << endl;
			if (init == 1)
			{
				cout << "Your turn!\n";
			}
			while(hunt.getHealth() > 0 || spid.getHealth() > 0){
				cout << "What's your decision?\n 1 -> Shoot an arrow \n 2 -> Arcane Shot \n 3 -> Guard/Heal(If enemy doesn't attack) \n";
				do{cin >> election;} while(election > 3 || election < 1);
				switch(election){
					case 1:
						hunt.Bow(spid);   
						cout << " \n"<< "You did " << hunt.getAttack()+30<< " damage\n" << endl;
						break;
					case 2:
						hunt.Arcane_Shot(spid);
						cout << " \n"<< "You did " << hunt.getMagic()+30<< " damage\n" << endl;
						break;
					case 3:
						hunt.Guard(hunt);
						cout << " \n"<< "You blocked " << hunt.getDefense()<< " damage\n" << endl;
						break;
				}
				election = rand()%3;
		
				switch(election){
		
					case 1:
						spid.Bite(hunt);
						cout << "The monster dealt " << spid.getAttack() << " damage."<< endl;
						break;
					case 2:
						spid.Venom(hunt);
						cout << "The monster dealt " << spid.getMagic() << " damage."<< endl;
						break;
					case 3:
						spid.Guard(spid);
						cout << "The monster blocked " << spid.getDefense() << " damage."<< endl;
						break;
				
				election = rand()%3;}
				
				cout << "The monster now has " << spid.getHealth() << " HP left.\n";
				if(spid.getHealth() < 1){
				cout << "You killed the monster! Beta completed!\n";
				return 0;
				}
				cout << "Your current HP is " << hunt.getHealth() <<"!\n";
				if (hunt.getHealth() < 1){
					cout << "You died! The monster fled with " << spid.getHealth() << " HP left... GAME OVER\n";
					return 0;
				}
				else{
					cout << "Your turn!\n";
			while(hunt.getHealth() > 0 || spid.getHealth() > 0){
				cout << "What's your decision?\n 1 -> Shoot an arrow \n 2 -> Arcane Shot \n 3 -> Guard/Heal(If enemy doesn't attack) \n";
				do{cin >> election;} while(election > 3 || election < 1);
				switch(election){
					case 1:
						hunt.Bow(spid);
						cout << " \n"<< "You did " << hunt.getAttack()+30<< " damage\n" << endl;
						break;
					case 2:
						hunt.Arcane_Shot(spid);
						cout << " \n"<< "You did " << hunt.getMagic()+30<< " damage\n" << endl;
						break;
					case 3:
						hunt.Guard(hunt);
						cout << " \n"<< "You blocked " << hunt.getDefense()<< " damage\n" << endl;
						break;
				}
				election = rand()%3;
		
				switch(election){
		
					case 1:
						spid.Bite(hunt);
						cout << "The monster dealt " << spid.getAttack() << " damage."<< endl;
						break;
					case 2:
						spid.Venom(hunt);
						cout << "The monster dealt " << spid.getMagic() << " damage."<< endl;
						break;
					case 3:
						spid.Guard(spid);
						cout << "The monster blocked " << spid.getDefense() << " damage."<< endl;
						break;
				
				election = rand()%3;}
				
				cout << "The monster now has " << spid.getHealth() << " HP left.\n";
				if(spid.getHealth() < 1){
				cout << "You killed the monster! Beta completed!\n";
				return 0;
				}
				cout << "Your current HP is " << hunt.getHealth() <<"!\n";
				if (hunt.getHealth() < 1){
					cout << "You died! The monster fled with " << spid.getHealth() << " HP left... GAME OVER\n";
					return 0;
				}
			}
			}
			break;
		case 3://CASO 3! Este funciona completamente igual que el caso 1, pero con los stats del wizard -------------------------------------------------------
			cout << " \n" << wiza.getName() << " \n" << wiza.getHealth()<< " Hp\n" << wiza.getAttack() << " Str\n" << wiza.getDefense()<< " Def\n" << wiza.getMagic()<< " Mag\n" << endl;
			cout << "\n";
			cout << "'Let me help you, this is what I know of your opponent'\n";
			cout <<  " \n" << "Name:\n" << spid.getName() << " \n" << spid.getHealth()<< " Hp\n" << spid.getAttack() << " Str\n" << spid.getDefense()<< " Def\n" << spid.getMagic()<< " Mag\n" << endl;
			if (init == 1)
			{
				cout << "Your turn!\n";
			}
			while(wiza.getHealth() > 0 || spid.getHealth() > 0){
				cout << "What's your decision?\n 1 -> Hit with your staff \n 2 -> FIREBALL!!! \n 3 -> Guard/Heal(If enemy doesn't attack) \n";
				do{cin >> election;} while(election > 3 || election < 1);
				switch(election){
					case 1:
						wiza.Staff(spid); 
						cout << " \n"<< "You did " << wiza.getAttack()+30<< " damage\n" << endl;
						break;
					case 2:
						wiza.Fireball(spid);
						cout << " \n"<< "You did " << wiza.getMagic()+30<< " damage\n" << endl;
						break;
					case 3:
						wiza.Guard(wiza);
						cout << " \n"<< "You blocked " << wiza.getDefense()<< " damage\n" << endl;
						break;
				}
				election = rand()%3;
		
				switch(election){
		
					case 1:
						spid.Bite(wiza);
						cout << "The monster dealt " << spid.getAttack() << " damage."<< endl;
						break;
					case 2:
						spid.Venom(wiza);
						cout << "The monster dealt " << spid.getMagic() << " damage."<< endl;
						break;
					case 3:
						spid.Guard(spid);
						cout << "The monster blocked " << spid.getDefense() << " damage."<< endl;
						break;
				
				election = rand()%3;}
				
				cout << "The monster now has " << spid.getHealth() << " HP left.\n";
				if(spid.getHealth() < 1){
				cout << "You killed the monster! Beta completed!\n";
				return 0;
				}
				cout << "Your current HP is " << wiza.getHealth() <<"!\n";
				if (wiza.getHealth() < 1){
					cout << "You died! The monster fled with " << spid.getHealth() << " HP left... GAME OVER\n";
					return 0;
				}
				else{
					cout << "Your turn!\n";
			while(wiza.getHealth() > 0 || spid.getHealth() > 0){
				cout << "What's your decision?\n 1 -> Hit with your staff \n 2 -> FIREBALL!!! \n 3 -> Guard/Heal(If enemy doesn't attack) \n";
				do{cin >> election;} while(election > 3 || election < 1);
				switch(election){
					case 1:
						wiza.Staff(spid);   //Preguntar a Benji como imprimir los dos randoms en stats
						cout << " \n"<< "You did " << wiza.getAttack()+30<< " damage\n" << endl;
						break;
					case 2:
						wiza.Fireball(spid);
						cout << " \n"<< "You did " << wiza.getMagic()+30<< " damage\n" << endl;
						break;
					case 3:
						wiza.Guard(wiza);
						cout << " \n"<< "You blocked " << wiza.getDefense()<< " damage\n" << endl;
						break;
				}
				election = rand()%3;
		
				switch(election){
		
					case 1:
						spid.Bite(wiza);
						cout << "The monster dealt " << spid.getAttack() << " damage."<< endl;
						break;
					case 2:
						spid.Venom(wiza);
						cout << "The monster dealt " << spid.getMagic() << " damage."<< endl;
						break;
					case 3:
						spid.Guard(spid);
						cout << "The monster blocked " << spid.getDefense() << " damage."<< endl;
						break;
				
				election = rand()%3;}
				
				cout << "The monster now has " << spid.getHealth() << " HP left.\n";
				if(spid.getHealth() < 1){
				cout << "You killed the monster! Beta completed!\n";
				return 0;
				}
				cout << "Your current HP is " << wiza.getHealth() <<"!\n";
				if (wiza.getHealth() < 1){
					cout << "You died! The monster fled with " << spid.getHealth() << " HP left... GAME OVER\n";
					return 0;
				}
			}
			}
			break;
	}	
}
}
}
}
