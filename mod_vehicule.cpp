
#include "mod_vehicule.h"


t_vehicule* vehicule_init()
{
	return nullptr;
}

void vehicule_free(t_vehicule* vehicule)
{
}

void vehicule_reset_geometrie(t_vehicule* vehicule)
{ 
	for (int i = 0; i <= vehicule->geometrie->nb_points; i++)
	{ 
		vehicule->geometrie->points[i]->x = 0;
		vehicule->geometrie->points[i]->y = 0;
		
	}

	vehicule->geometrie->points[0]->x = 0;
	vehicule->geometrie->points[0]->y = 0;

	vehicule->geometrie->points[1]->x = VEHICULE_LONGUEUR;
	vehicule->geometrie->points[1]->y = 0;
	
	vehicule->geometrie->points[2]->x = 0;
	vehicule->geometrie->points[2]->y = VEHICULE_LARGEUR;

	vehicule->geometrie->points[3]->x = VEHICULE_LONGUEUR;
	vehicule->geometrie->points[3]->y = VEHICULE_LARGEUR;

	
}

void vehicule_decision(t_vehicule* vehicule, const t_route* route, double delai_sec, int faciliter_depassement)
{
}

int vehicule_changer_voie(t_vehicule* vehicule, const t_route* route, int nouvelle_voie)
{
	return 0;
}

double vehicule_calculer_deplacement(t_vehicule* vehicule, double delta_t_sec)
{
	double nouvelle_position =  (vehicule.vitesse * delta_t_sec); //calcul variation position
	

	return nouvelle_position;
}