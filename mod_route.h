#ifndef MOD_ROUTE_H
#define MOD_ROUTE_H

#include "mod_voie.h"

#define ROUTE_MAX_VOIES 10
#define DELTA_T_INTERATIONS_SECS 1.5 //Temps entre chaque boucle de simulation

typedef struct voie t_voie; //R�p�tition du type pour la compilation
typedef struct vehicule t_vehicule; //R�p�tition du type pour la compilation
typedef struct route t_route;

//D�finit le type struct route qui encapsule les voies
struct route {
	t_voie* voies[ROUTE_MAX_VOIES]; //Tableau statique de r�f�rences vers des voies
	int nb_voies; //Le nombre de voies dans le tableau de voies
	double vitesse_max; //La vitesse maximale autoris�e sur la route
	double vitesse_min; //La vitesse minimale autoris�e sur la route
};


void vehicule_liberer(t_vehicule* vehicule);//pierre
//Libère l’espace mémoire d’un véhicule dont la référence est passée en
//paramètre.
//t_voie* voie_init(int max_vehicules, double longeur_km);
//Alloue une voie pouvant accueillir un nombre maximal de véhicules déterminé
//(max_vehicules) et ayant une taille en KM déterminée(longueur_km).
//La fonction retourne une référence vers la voie créée.

void voie_liberer(t_voie* voie);
//Libère l’espace occupé par une voie.La fonction doit notamment libérer
//l’espace mémoire occupé par tous ses véhicules.
//t_route* route_init(int nb_voies, double vitesse_min,
//	double vitesse_max, double longueur_visible,
//	int max_vehicules_voie);
//Alloue l’espace mémoire pour une route et initialise ses champs aux valeurs
//des paramètres transmis.La fonction doit remplir le tableau de références
//vers des voies en créant de nouvelles voies.
//La fonction retourne la référence vers la route créée.

void route_liberer(t_route* route);
/*Lib�re tout l�espace m�moire occup� par la route dont la r�f�rence est
transmise en param�tre.Les voies et v�hicules contenus par la route doivent
�galement �tre lib�r�es.
int voie_insertion_valide(const t_voie* voie, const t_vehicule* vehicule,
	int indice, double distance_min);
Fonction priv�e du module qui d�termine s�il est possible d�ins�rer le
v�hicule � vehicule � sur la voie � voie � � la position � indice � du
tableau, en pr�servant une distance minimale � distance_min � entre le
v�hicule pr�c�dent et le v�hicule suivant.
La fonction retourne une valeur vraie si c�est possible, ou une valeur
fausse sinon.
*/

t_route* route_init(int nb_voies, double vitesse_min, double vitesse_max, double longueur_visible, int max_vehicules_voie);
/*Alloue l�espace m�moire pour une route et initialise ses champs aux valeurs
des param�tres transmis.La fonction doit remplir le tableau de r�f�rences
vers des voies en cr�ant de nouvelles voies.
La fonction retourne la r�f�rence vers la route cr��e.Alloue l�espace m�moire pour une route et initialise ses champs aux valeurs
des param�tres transmis.La fonction doit remplir le tableau de r�f�rences
vers des voies en cr�ant de nouvelles voies.
La fonction retourne la r�f�rence vers la route cr��e.
*/

#endif