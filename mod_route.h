#include <stdio.h>
#include "mod_voie.h"
#include "mod_vehicule.h"
#include <stdlib.h> 
#include <time.h>

#define _CRT_SECURE_NO_WARNINGS

#ifndef MOD_ROUTE_H
#define MOD_ROUTE_H

#define ROUTE_MAX_VOIES 10
#define DELTA_T_INTERATIONS_SECS 1.5 //Temps entre chaque boucle de simulation
#define MAX_INFRUCTUEUX 1000
typedef struct t_voie t_voie; //Répétition du type pour la compilation
typedef struct t_vehicule t_vehicule; //Répétition du type pour la compilation
typedef struct t_route t_route;
//Définit le type struct route qui encapsule les voies
struct t_route {
	t_voie* voies[ROUTE_MAX_VOIES]; //Tableau statique de références vers
	//des voies
	int nb_voies; //Le nombre de voies dans le tableau de voies
	double vitesse_max; //La vitesse maximale autorisée sur la route
	double vitesse_min; //La vitesse minimale autorisée sur la route
};


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

double route_ratio_insatisfaits(const t_route* route);
/*Calcule le ratio d’automobilistes insatisfaits par rapport au nombre total
d’automobilistes sur la route.*/


int route_sauvegarder_route(const char* nom_fichier, const t_route* route);
/*
Sauvegarde l’état de la route « route » dans le fichier texte ayant pour nom
« nom_fichier ». Le fichier texte doit avoir le format cité ci-dessous.
La fonction retourne une valeur vraie si le fichier a pu être sauvegardé, ou
une valeur fausse sinon.
Format :
NOMBRE_VOIES
NUM_VOIE NOMBRE_VOITURES
POSITION_VOITURE1 VITESSE_VOITURE1 VITESSE_CIBLE_VOITURE1
......
Exemple :
Voici un exemple de fichier texte respectant le format cité ci-dessus:
2
0 3
5.4 100 120
7.8 90 110
12.0 95 95
1 2
10.0 60 75
12.4 100 110
Le fichier indique que la route a deux voies.
Sur la voie 0, il y’a 3 véhicules (aux km 5.4, 7.8 et 12.0 respectivement).
Sur la voie 1, il y’a 2 véhicules (aux km 10.0 et 12.4).
*/


int route_ajouter_vehicule(t_route* route, t_vehicule* vehicule, int num_voie);
/*Ajoute le véhicule « vehicule » sur la voie ayant pour indice « num_voie »
(dans le tableau de voies de la « route »). La fonction retourne une valeur
vraie si le véhicule a pu être placé sur la voie en question, ou une valeur
fausse sinon.
*/

int route_ajout_vehicules_aleatoirement(t_route* route, int nb_vehicules);
/*Tente d’ajouter « nb_vehicules » vehicules sur la route « route ».
La fonction doit initialiser chaque véhicule et lui attribuer une vitesse
actuelle et une vitesse cible aléatoirement entre les vitesses minimale et
maximale de la route. Ensuite, un choix de voie doit se faire aléatoirement
et une position aléatoire (entre 0 et la longueur de la voie) doit être
attribué au véhicule. Vous appellerez ensuite la fonction permettant de
placer le véhicule sur la voie.
Vous devez compter le nombre de fois que vous n’avez pas été capables de
placer un véhicule sur la voie choisie. Si le nombre de placements
infructueux atteint la constante privée MAX_INFRUCTUEUX (= 1000), vous devez
abandonner et retourner une valeur fausse. Sinon, si tous les nb_vehicules
ont été placés, vous retournez une valeur vraie.
*/


/*
Fonction: InitRandom
Initialise le générateur de nombre aleatoire. 
Doit etre appele avant nb_aleatoire() et entier_aleatoire()
*/
void InitRandom(void);


/*
 Fonction: nb_aleatoire
 Retourne un nombre decimal entre min et max.
 */
double nb_aleatoire(double min, double max);


/*
Fonction: entier_aleatoire
Retourne un nombre aléatoire entre min et max.
*/
int entier_aleatoire(int min, int max);

#endif