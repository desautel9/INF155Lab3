#ifndef MOD_ROUTE_H
#define MOD_ROUTE_H

#include "mod_voie.h"

#define ROUTE_MAX_VOIES 10
#define DELTA_T_INTERATIONS_SECS 1.5 //Temps entre chaque boucle de simulation

typedef struct voie t_voie; //Répétition du type pour la compilation
typedef struct vehicule t_vehicule; //Répétition du type pour la compilation
typedef struct route t_route;

//Définit le type struct route qui encapsule les voies
struct route {
	t_voie* voies[ROUTE_MAX_VOIES]; //Tableau statique de références vers des voies
	int nb_voies; //Le nombre de voies dans le tableau de voies
	double vitesse_max; //La vitesse maximale autorisée sur la route
	double vitesse_min; //La vitesse minimale autorisée sur la route
};


void route_liberer(t_route* route);
/*Libère tout l’espace mémoire occupé par la route dont la référence est
transmise en paramètre.Les voies et véhicules contenus par la route doivent
également être libérées.
int voie_insertion_valide(const t_voie* voie, const t_vehicule* vehicule,
	int indice, double distance_min);
Fonction privée du module qui détermine s’il est possible d’insérer le
véhicule « vehicule » sur la voie « voie » à la position « indice » du
tableau, en préservant une distance minimale « distance_min » entre le
véhicule précédent et le véhicule suivant.
La fonction retourne une valeur vraie si c’est possible, ou une valeur
fausse sinon.
*/

t_route* route_init(int nb_voies, double vitesse_min, double vitesse_max, double longueur_visible, int max_vehicules_voie);
/*Alloue l’espace mémoire pour une route et initialise ses champs aux valeurs
des paramètres transmis.La fonction doit remplir le tableau de références
vers des voies en créant de nouvelles voies.
La fonction retourne la référence vers la route créée.Alloue l’espace mémoire pour une route et initialise ses champs aux valeurs
des paramètres transmis.La fonction doit remplir le tableau de références
vers des voies en créant de nouvelles voies.
La fonction retourne la référence vers la route créée.
*/

#endif