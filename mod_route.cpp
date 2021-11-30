#include "mod_route.h"


void vehicule_liberer(t_vehicule* vehicule)
{
	//Important: libérer la mémoire allouée dynamiquement quand on l'utilise plus
	free(vehicule);
	vehicule = NULL;
}


t_route* route_init(int nb_voies, double vitesse_min, double vitesse_max, double longueur_visible, int max_vehicules_voie)
{
	//Variables
	t_route* route;

	//Allouer la mémoire de facon dynamique a une route
	route = (t_route*)malloc(sizeof(t_route));
	if (route == NULL) //Toujours vérifier si l'allocation a fonctionné
	{
		printf("Erreur d'allocation memoire!\n");
		exit(EXIT_FAILURE);
	}

	//Initialise ses champs aux valeurs des parametres transmis
	route->nb_voies = nb_voies;
	route->vitesse_min = vitesse_min;
	route->vitesse_max = vitesse_max;

	for (int i = 0; i < nb_voies; i++)
	{
		//Remplit le tableau de références vers des voies en créant de nouvelles voies
		t_voie* voies = voie_init(longueur_visible, max_vehicules_voie);
		route->voies[i] = voies;
	}

	return route;
}

void route_liberer(t_route* route)
{

	free(route);

}
double route_ratio_insatisfaits(const t_route* route)
{
	int i;
	int chauffeur_mecontent=0;
	double ratio_insatisfait =0.0;
	int chauffeur_total =0;


	for (i = 0; i <= route->nb_voies; ++i)
	{
		chauffeur_mecontent += voie_nb_vehicules_sous_vitesse_cible(route->voies[i]); // somme chauffeur mecontent par voie
		chauffeur_total += route->voies[i]->nb_vehicules; //somme chauffeur total de la route 
	}
	
	return ratio_insatisfait = chauffeur_mecontent / chauffeur_total; // retourne le ratio d'insatifaction 
}

int route_sauvegarder_route(const char* nom_fichier, const t_route* route)
{
	FILE* nom_fichier;

	route->nb_voies;
	route->voies[i]->nb_vehicules;
	
}
