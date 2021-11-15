//
// Cr�er par David Hill, Olivier Deshautels, Pierre Rayeroux
// Date remise : 2021-12-04
//

#include "mod_geo.h"

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