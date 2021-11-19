#ifndef MOD_VEHICULE_H
#define MOD_VEHICULE_H

#include "mod_dessin.h"
#include "mod_geo.h"
#include "mod_voie.h"

//L'accélération maximale d'un véhicule en KM/h.s 
#define VEHICULE_ACCEL_MAX 20
//La déclaration maximale d'un véhicule en KM/h.s
#define VEHICULE_DECEL_MAX 20
//La longueur en pixels d’un véhicule à l’écran
#define VEHICULE_LONGUEUR 10
//La largeur, en pixels, d’un véhicule à l’écran
#define VEHICULE_LARGEUR 4
typedef struct route t_route; //Type-route qui sera défini plus tard
typedef struct vehicule t_vehicule;

//Définit le type struct vehicule
struct vehicule {
	t_polygone geometrie;
	double position; //La position actuelle du véhicule sur l'autoroute
	double vitesse; //La vitesse actuelle du véhicule
	double vitesse_cible; //La vitesse idéale que souhaite avoir le
	//conducteur du véhicule
	int voie; //La voie sur laquelle se trouve le véhicule.
	//-1 si le véhicule n'est sur aucune voie.
};


t_vehicule* vehicule_init();

void vehicule_free(t_vehicule* vehicule);

void vehicule_reset_geometrie(t_vehicule* vehicule);

void vehicule_decision(t_vehicule* vehicule, const t_route* route, double delai_sec, int faciliter_depassement);

int vehicule_changer_voie(t_vehicule* vehicule, const t_route* route, int nouvelle_voie);

double vehicule_calculer_deplacement(t_vehicule* vehicule, double delta_t_sec);

#endif //INF155_20193_TP3_MOD_VEHICULE_H