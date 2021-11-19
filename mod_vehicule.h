#ifndef MOD_VEHICULE_H
#define MOD_VEHICULE_H

#include "mod_dessin.h"
#include "mod_geo.h"
#include "mod_voie.h"

//L'acc�l�ration maximale d'un v�hicule en KM/h.s 
#define VEHICULE_ACCEL_MAX 20
//La d�claration maximale d'un v�hicule en KM/h.s
#define VEHICULE_DECEL_MAX 20
//La longueur en pixels d�un v�hicule � l��cran
#define VEHICULE_LONGUEUR 10
//La largeur, en pixels, d�un v�hicule � l��cran
#define VEHICULE_LARGEUR 4
typedef struct route t_route; //Type-route qui sera d�fini plus tard
typedef struct vehicule t_vehicule;

//D�finit le type struct vehicule
struct vehicule {
	t_polygone geometrie;
	double position; //La position actuelle du v�hicule sur l'autoroute
	double vitesse; //La vitesse actuelle du v�hicule
	double vitesse_cible; //La vitesse id�ale que souhaite avoir le
	//conducteur du v�hicule
	int voie; //La voie sur laquelle se trouve le v�hicule.
	//-1 si le v�hicule n'est sur aucune voie.
};


t_vehicule* vehicule_init();

void vehicule_free(t_vehicule* vehicule);

void vehicule_reset_geometrie(t_vehicule* vehicule);

void vehicule_decision(t_vehicule* vehicule, const t_route* route, double delai_sec, int faciliter_depassement);

int vehicule_changer_voie(t_vehicule* vehicule, const t_route* route, int nouvelle_voie);

double vehicule_calculer_deplacement(t_vehicule* vehicule, double delta_t_sec);

#endif //INF155_20193_TP3_MOD_VEHICULE_H