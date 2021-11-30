#include "mod_vehicule.h"


t_vehicule* vehicule_init(void)
{
	//Variables
	t_vehicule* vehicule;

	//Allouer la mémoire de facon dynamique a un véhicule
	vehicule = (t_vehicule*)malloc(sizeof(t_vehicule));

	if (vehicule == NULL) //Toujours vérifier si l'allocation a fonctionné
	{
		printf("Erreur d'allocation memoire!\n");
		exit(EXIT_FAILURE);
	}

	//Initialise les parametres d'un vehicule
	vehicule->geometrie; 
	vehicule->position = 0;
	vehicule->vitesse = VEHICULE_VITESSE_DEFAUT;
	vehicule->vitesse_cible = VEHICULE_VITESSE_DEFAUT;

	//Mettre un polygone dans un vehicule
	geo_init_polygone(&(vehicule->geometrie), 4); //4 points dans le vehicule
	vehicule_reset_geometrie(vehicule); //Faire la forme du vehicule

	return vehicule;
}

void vehicule_free(t_vehicule* vehicule)
{
	free(&vehicule); //Libère l’espace mémoire d’un véhicule
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

	for (int i = 0; i < route->nb_voies; i++)
	{
		int position_actuelle = voie_trouver_vehicule(route->voies[i]);// on cherche le vehicule dans toutes les voies une par une
		if (position_actuelle != -1) //si on trouve le vehicule
		{
			int succes_retrait voie_retirer_vehicule(route->voies[i], vehicule); //on retire le vehicule de sa vieille voie
			int succes_ajout = voie_ajouter_vehicule(nouvelle_voie, vehicule, DISTANCE_MIN_ENTRE_VEHICULES); //on met le vehicule dans sa nouvelle voie. 
			if (succes_retrait && succes_ajout)
			{
				return 1;
			}
		}
	}

	return 0;
}

double vehicule_calculer_deplacement(t_vehicule* vehicule, double delta_t_sec)
{
	double variation_position = ((vehicule->vitesse / 3600) * delta_t_sec); //calcul variation position


	return variation_position;
}

