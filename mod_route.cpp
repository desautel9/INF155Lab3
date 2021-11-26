#include "mod_route.h"


void vehicule_liberer(t_vehicule* vehicule)
{
	//Important: libérer la mémoire allouée dynamiquement quand on l'utilise plus
	free(vehicule);
	vehicule = NULL;
}


t_route* route_init(int nb_voies, double vitesse_min, double vitesse_max, double longueur_visible, int max_vehicules_voie)
{
	t_route* route;

	//Allouer la mémoire de facon dynamique a une route
	route = (t_route*)malloc(sizeof(t_route));
	if (route == NULL) //Toujours vérifier si l'allocation a fonctionné
	{
		printf("Erreur d'allocation memoire!\n");
		exit(EXIT_FAILURE);
	}

	//route->voies = (t_voie**)malloc(sizeof(t_voie*) * ROUTE_MAX_VOIES); //Alloue un emplacement pour un tableau de t_voie
	if (route->voies == NULL)
	{
		printf("Erreur d'allocation!\n");
		exit(EXIT_FAILURE);
	}

	route->nb_voies = nb_voies;
	route->vitesse_min = vitesse_min;
	route->vitesse_max = vitesse_max;

	for (int i = 0; i < nb_voies; i++)
	{
		t_voie* voies = voie_init(longueur_visible, max_vehicules_voie);
		//route->voies = voies;
	}

	return route;
}

void route_liberer(t_route* route)
{
	for (int i = 0; i <= route->nb_voies; ++i)
	{
		voie_free(route->voies[i]);
	}
	
	free(route);
}