#include "mod_route.h"


t_vehicule* vehicule_init(void)
{
	t_vehicule* vehicule;

	//Allouer la m�moire de facon dynamique a un v�hicule
	vehicule = (t_vehicule*)malloc(sizeof(t_vehicule));

	if (vehicule == NULL) //Toujours v�rifier si l'allocation a fonctionn�
	{
		printf("Erreur d'allocation memoire!\n");
		exit(EXIT_FAILURE);
	}

	vehicule->geometrie; //Initialise la gemoetrie du vehicule
	vehicule->position = 0;
	vehicule->vitesse = NULL;
	vehicule->vitesse_cible = NULL;

	return vehicule;
}


void vehicule_liberer(t_vehicule* vehicule)
{
	//Important: lib�rer la m�moire allou�e dynamiquement quand on l'utilise plus
	free(vehicule);
	vehicule = NULL;
}


t_route* route_init(int nb_voies, double vitesse_min, double vitesse_max, double longueur_visible, int max_vehicules_voie)
{
	t_route* route;

	//Allouer la m�moire de facon dynamique a une route
	route = (t_route*)malloc(sizeof(t_route));
	if (route == NULL) //Toujours v�rifier si l'allocation a fonctionn�
	{
		printf("Erreur d'allocation memoire!\n");
		exit(EXIT_FAILURE);
	}

	route->voies = (t_voie**)malloc(sizeof(t_voie*)); //Alloue un emplacement pour un tableau de t_voie
	if (route->voies == NULL)
	{
		printf("Erreur d'allocation!\n");
		exit(EXIT_FAILURE);
	}

	route->nb_voies = nb_voies;
	route->vitesse_min = vitesse_min;
	route->vitesse_max = vitesse_max;

	for (int i = 0; i < ; i++)
	{
		route
	}

	return route;
}
