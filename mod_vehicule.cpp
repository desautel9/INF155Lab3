#include "mod_vehicule.h"


t_vehicule* vehicule_init(void)
{
	//Variables
	t_vehicule* vehicule;

	//Allouer la m�moire de facon dynamique a un v�hicule
	vehicule = (t_vehicule*)malloc(sizeof(t_vehicule));

	if (vehicule == NULL) //Toujours v�rifier si l'allocation a fonctionn�
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
	free(&vehicule); //Lib�re l�espace m�moire d�un v�hicule
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
	//on commence par trouver ou est le vehicule en question
	t_voie* voie;
	int indice_voie;
	int indice_vehicule;
	for (int i = 0; i < route->nb_voies; i++��)
	{
		int indice_possible = voie_trouver_vehicule(route->voies[i], vehicule);
		if (indice_possible > 0)
		{
			indice_voie = i;
			indice = indice_possible;
			voie = route->voies[i];
			break; //on a trouve le vehicule, pas besoin de continuer a chercher
		}
	}
	
	//toutes les informations dont on a besoins pour les conditions qui suivent
	double distance_derriere = voie_dist_vehicule_precedent(voie, vehicule);
	double distance_devant = voie_dist_vehicule_suivant(voie, vehicule);
	double vitesse_cible_derriere = voie_vitesse_cible_vehicule_precedent(voie, vehicule);
	double vitesse_devant = voie_vitesse_vehicule_suivant(voie, vehicule);
	int insertion_droite_ok = 0;
	int insertion_droite_pos = voie_position_insertion(voie, vehicule, DISTANCE_MIN_ENTRE_VEHICULES);
	if (voie_indice < route->nb_voies - 1)
		insertion_droite_ok = voie_insertion_valide(route->voies[indice_voie + 1], vehicule, insertion_droite_pos);
	int insertion_gauche_ok;
	int insertion_gauche_pos;

	//reduire la vitesse si on est trop proche
	if (distance_devant < DISTANCE_MIN_ENTRE_VEHICULES_FREINAGE &&
		distance_devant >= 0) //une distance negative indique qu'il n'y a pas de vehicule suivant 
	{
		vehicule->vitesse = voie->vehicules[indice_vehicule+1]->position
	}
	//sinon, deplacer le vehicule sur la droite si le vehicule est plus lent que celui derriere lui
	else if (vehicule->vitesse == vehicule->vitesse_cible &&
		vitesse_cible_derriere > vehicule->vitesse&&
		insertion_droite_ok)
	{
		vehicule_changer_voie(vehicule, route, indice_voie + 1);
	}
	//sinon, deplacer le vehicule si le vehicule veut aller plus vite que celui devant.
	else if(vehicule->vitesse_cible > vitesse_devant &&
			insertion_gauche_ok)
		
}

int vehicule_changer_voie(t_vehicule* vehicule, const t_route* route, int nouvelle_voie)
{

	for (int i = 0; i < route->nb_voies; i++)
	{
		int position_actuelle = voie_trouver_vehicule(route->voies[i], vehicule); //on cherche le vehicule dans toutes les voies une par une
		if (position_actuelle != -1) //si on trouve le vehicule
		{
			int succes_retrait = voie_retirer_vehicule(route->voies[i], vehicule); //on retire le vehicule de sa vieille voie
			int succes_ajout = voie_ajouter_vehicule(route->voies[nouvelle_voie], vehicule, DISTANCE_MIN_ENTRE_VEHICULES); //on met le vehicule dans sa nouvelle voie. 
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

