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

	route->nb_voies = nb_voies;
	route->vitesse_min = vitesse_min;
	route->vitesse_max = vitesse_max;

	for (int i = 0; i < nb_voies; i++)
	{
		t_voie* voies = voie_init(longueur_visible, max_vehicules_voie);
		route->voies[i] = voies;
	}

	return route;
}

int route_ajouter_vehicule(t_route* route, t_vehicule* vehicule, int num_voie)
{
	return voie_ajouter_vehicule(route->voies[num_voie], vehicule, DISTANCE_MIN_ENTRE_VEHICULES);
}

int route_ajout_vehicules_aleatoirement(t_route* route, int nb_vehicules)
{
	srand(time(NULL)); //initialise le generateur de hasard

	int nb_erreurs = 0;
	while(nb_vehicules > 0)
	{
		t_vehicule* nouveau_vehicule = vehicule_init();

		int indice_voie = rand() % route->nb_voies; //choisie une voie au hasard
		nouveau_vehicule->position = rand() % route->voies[indice_voie]->longueur_km; //choisie une position au hasard entre 0 et la longueur max
		nouveau_vehicule->vitesse = rand() % (route->vitesse_max - route->vitesse_min) + route->vitesse_min; //choisie une vitesse au hasard entre les minimums et maximums de la route
		nouveau_vehicule->vitesse_cible = rand() % (route->vitesse_max - route->vitesse_min) + route->vitesse_min; //choisie une vitesse cible au hasard entre les minimums et maximums de la route

		int succes = voie_ajouter_vehicule(route->voies[indice_voie], nouveau_vehicule, DISTANCE_MIN_ENTRE_VEHICULES);
		if (succes)
			nb_vehicules--;
		else
			nb_erreurs++;

		if (nb_erreurs >= MAX_INFRUCTUEUX) //si trop d'erreurs, on abandonne et retourne 0
			return 0;
	}

	return 1;
}

void route_liberer(t_route* route)
{
	free(route);
}
