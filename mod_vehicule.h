#ifndef MOD_VEHICULE_H
#define MOD_VEHICULE_H

#include "mod_dessin.h"
#include "mod_geo.h"
#include "mod_voie.h"
#include "mod_route.h"
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

//La vitesse par defaut d'un nouveau vehicule en KM/h
#define VEHICULE_VITESSE_DEFAUT 100

//L'accélération maximale d'un véhicule en KM/h.s
#define VEHICULE_ACCEL_MAX 20

//La déclaration maximale d'un véhicule en KM/h.s
#define VEHICULE_DECEL_MAX 20

//La longueur en pixels d’un véhicule à l’écran
#define VEHICULE_LONGUEUR 10

//La largeur, en pixels, d’un véhicule à l’écran
#define VEHICULE_LARGEUR 4

typedef struct t_route t_route; //Type-route qui sera défini plus tard
typedef struct t_vehicule t_vehicule;
//Définit le type struct vehicule
struct t_vehicule {
	t_polygone geometrie;
	double position; //La position actuelle du véhicule sur l'autoroute
	double vitesse; //La vitesse actuelle du véhicule
	double vitesse_cible; //La vitesse idéale que souhaite avoir le
	//conducteur du véhicule
	int voie; //La voie sur laquelle se trouve le véhicule.
	//-1 si le véhicule n'est sur aucune voie.
};
t_vehicule* vehicule_init(void);
/*Alloue la m�moire pour un v�hicule et initialise la g�om�trie(polygone) du
v�hicule.Le v�hicule sera positionn� � la position zero et aura une vitesse
r�elle et une vitesse cible nulles.
La fonction retourne une r�f�rence vers le v�hicule cr��.
*/

void vehicule_liberer(t_vehicule* vehicule);
//Libère l’espace mémoire d’un véhicule dont la référence est passée en
//paramètre.

void vehicule_reset_geometrie(t_vehicule* vehicule);
/*Réinitialise le polygone du véhicule dont la référence est passée en
paramètre.Ensuite, la fonction doit définir les coordonnées des points du
polygone en se basant sur VEHICULE_LONGUEUR et VEHICULE_LARGEUR.Le premier
point du polygone doit absolument se trouver aux coordonnées(0, 0).*/

int vehicule_changer_voie(t_vehicule* vehicule, const t_route* route, int nouvelle_voie);
/*
Modifie la voie du véhicule « vehicule » pour le déplacer vers la voie ayant
pour numéro « nouvelle_voie » (qui représente l’indice dans le tableau de
voies de la route « route »).
La fonction doit retourner une valeur vraie si le changement de voie a pu
avoir lieu, ou une valeur fausse sinon.
Note 1 : Plusieurs fonctions développées à la semaine 2 vous seront utiles.
Note 2 : Ne pas oublier de retirer le véhicule de sa voie actuelle.
Note 3 : Assurez-vous que la voie existe et que celle-ci n’est pas celle sur
 laquelle le véhicule se trouve déjà.
*/

void vehicule_decision(t_vehicule* vehicule, const t_route* route, double delai_sec, int faciliter_depassement);

double vehicule_calculer_deplacement(t_vehicule* vehicule, double delta_t_sec);
/*Calcule et retourne la valeur du déplacement du véhicule(passé par
référence) après un temps delta_t en se basant sur sa vitesse.*/


#endif //INF155_20193_TP3_MOD_VEHICULE_H