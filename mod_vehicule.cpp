#include "mod_vehicule.h"


t_vehicule* vehicule_init(void)
{
	t_vehicule* vehicule;

	//Allouer la mémoire de facon dynamique a un véhicule
	vehicule = (t_vehicule*)malloc(sizeof(t_vehicule));

	if (vehicule == NULL) //Toujours vérifier si l'allocation a fonctionné
	{
		printf("Erreur d'allocation memoire!\n");
		exit(EXIT_FAILURE);
	}

	vehicule->geometrie; //Initialise la gemoetrie du vehicule
	vehicule->position = 0;
	vehicule->vitesse = VEHICULE_VITESSE_DEFAUT;
	vehicule->vitesse_cible = VEHICULE_VITESSE_DEFAUT;

	geo_init_polygone(&(vehicule->geometrie), 4);
	vehicule_reset_geometrie(vehicule);

	return vehicule;
}

void vehicule_free(t_vehicule* vehicule)
{
}

void vehicule_reset_geometrie(t_vehicule* vehicule)
{
	geo_init_polygone(&(vehicule->geometrie), 4);

	vehicule->geometrie.points[0].x = 0;
	vehicule->geometrie.points[0].y = 0;

	vehicule->geometrie.points[1].x = VEHICULE_LONGUEUR;
	vehicule->geometrie.points[1].y = 0;

	vehicule->geometrie.points[2].x = VEHICULE_LONGUEUR;
	vehicule->geometrie.points[2].y = VEHICULE_LARGEUR;

	vehicule->geometrie.points[3].x = 0;
	vehicule->geometrie.points[3].y = VEHICULE_LARGEUR;
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
	double variation_position = ((vehicule->vitesse/3600) * delta_t_sec); //calcul variation position


	return variation_position;
}