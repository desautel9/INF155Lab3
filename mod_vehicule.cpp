
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

	//TODO: Compléter cette fonction
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
	vehicule->position = vehicule.position + (vehicule.vitesse * delta_t_sec); //attribue la nouvelle position en fonction de la vitesse 

	//TODO: Compléter cette fonction, la valeur de retournee ici est juste pour la compilation 
	return 0;
}