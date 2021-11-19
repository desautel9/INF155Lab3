//
// Créer par David Hill, Olivier Deshautels, Pierre Rayeroux
// Date remise : 2021-12-04
//

#include "mod_geo.h"

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

int geo_ajouter_tab_polygone(t_polygone* poly, t_point pts[], int nb_pts)
{
	return 0;
}

void geo_init_polygone(t_polygone* poly, int taille)
{
	if (taille > GEO_POLYGONE_MAX_PTS)
	{
		taille = 0;
		*t_polygone = taille;
	}
	else
	{
		*t_polygone = taille;
	}
}

int geo_ajouter_point_polygone(t_polygone* poly, t_point pt, int position)
{
	if (position >= 0 && position <= *poly->nb_points - 1)
	{
		*poly->points[position] += pt;

		return 1;
	}
	return 0;
}