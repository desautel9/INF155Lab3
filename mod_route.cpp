#include "mod_route.h"
#define _CRT_SECURE_NO_WARNINGS

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
		t_voie* voies = voie_init(max_vehicules_voie, longueur_visible);
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
	InitRandom(); //initialise le generateur de hasard

	int nb_erreurs = 0;
	while(nb_vehicules > 0)
	{
		t_vehicule* nouveau_vehicule = vehicule_init();

		int indice_voie = entier_aleatoire(0, route->nb_voies-1); //choisie une voie au hasard
		nouveau_vehicule->voie = indice_voie;
		nouveau_vehicule->position = nb_aleatoire(0, route->voies[indice_voie]->longueur_km); //choisie une position au hasard entre 0 et la longueur max
		nouveau_vehicule->vitesse = nb_aleatoire(route->vitesse_min, route->vitesse_max); //choisie une vitesse au hasard entre les minimums et maximums de la route
		nouveau_vehicule->vitesse_cible = nb_aleatoire(route->vitesse_min, route->vitesse_max); //choisie une vitesse cible au hasard entre les minimums et maximums de la route

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
double route_ratio_insatisfaits(const t_route* route) // pierre
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
	//Variable texte
	FILE* mon_fichier;

	//Ouverture d'un fichier txt
	mon_fichier = fopen(nom_fichier, "w");
	if (mon_fichier == NULL) //Vérification si ouverture ou non
	{
		return 0;
	}

	fprintf(mon_fichier, "%d\n", route->nb_voies); //Affichier le nombre de voie

	for (int i = 0; i < route->nb_voies; i++) //Parcourir les voies de la routes
	{	 
		fprintf(mon_fichier, "%d %d\n", i, route->voies[i]->nb_vehicules); //Afficher le nombre de vehicule dans la voie en quesiton

		for (int j = 0; j < route->voies[i]->nb_vehicules; j++) //Parcourir les voitures de la voie en question
		{
			//Afficher la position, la vitesse ainsi que la vitesse cible du vehicule en question
			fprintf(mon_fichier, "%.2lf %.0lf %.0lf\n", route->voies[i]->vehicules[j]->position, route->voies[i]->vehicules[j]->vitesse, route->voies[i]->vehicules[j]->vitesse_cible);
		}
	}

	if (fclose(mon_fichier) != 0) //Si la fermeture du fichier ne se fait pas comme il faut
	{
		return 0;
	}

	return 1; //Retourne vrai si le fichier a pu être sauvegarde
}



void InitRandom(void)
{
	srand((int)time(NULL));
}

double nb_aleatoire(double min, double max)
{
	return min + rand() / (RAND_MAX + 0.001) * (max - min + 1);
}


int entier_aleatoire(int min, int max)
{
	return (rand() % (max - min + 1)) + min;
}