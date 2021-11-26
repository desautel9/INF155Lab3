#include "mod_voie.h"

t_voie* voie_init(int max_vehicules, double longeur_km)
{
	t_voie* voie;

	//Allouer la mémoire de facon dynamique a une voie
	voie = (t_voie*)malloc(sizeof(t_voie));

	if (voie == NULL) //Toujours vérifier si l'allocation a fonctionné
	{
		printf("Erreur d'allocation memoire!\n");
		exit(EXIT_FAILURE);
	}

	voie->max_vehicules = max_vehicules;
	voie->longueur_km = longeur_km;

	return voie;
}

void voie_free(t_voie* voie)
{
	free(voie->vehicules);
	free(voie);
}

int voie_ajouter_vehicule(t_voie* voie, t_vehicule* vehicule, double distance_min)
{
	int indice = voie_position_insertion(voie, vehicule, distance_min);
	if (voie_insertion_valide(voie, vehicule, indice, distance_min))
	{
		for (size_t i = voie->nb_vehicules-1; i > indice; i--)
		{
			voie->vehicules[i + 1] = voie->vehicules[i];
		}
		voie->vehicules[indice] = vehicule;
		voie->nb_vehicules++;
		
		return 1;
	}

	else
		return 0;
}

int voie_changement_voie_possible(const t_voie* nouvelle_voie, const t_vehicule* vehicule)
{
	return 0;
}

void voie_afficher_console(t_voie* voie)
{
}

int voie_position_insertion(const t_voie* voie, const t_vehicule* vehicule, double distance_min)
{
	for (int i = 0; i < voie->nb_vehicules; i++)
	{
		if (vehicule->position > voie->vehicules[i]->position)
			return i+1;
	}
	return -1;
}

int voie_trouver_vehicule(const t_voie* voie, const t_vehicule* vehicule)
{
	for (int i = 0; i < voie->nb_vehicules; i++)
	{
		if (voie->vehicules[i] == vehicule)
			return i;
	}
	return -1;
}

int voie_retirer_vehicule(t_voie* voie, const t_vehicule* vehicule)
{
	int indice = voie_trouver_vehicule(voie, vehicule);
	
	if (indice == -1) //vehicule invalide
		return -1;

	voie->nb_vehicules--;
	for (size_t i = indice; i < voie->nb_vehicules; i++)
	{
		voie->vehicules[i] = voie->vehicules[i+1];
	}
	
}

double calculer_distance_vehicules(const t_voie* voie, int pos1, int pos2)
{
	double distance= voie->vehicules[pos2]->position - voie->vehicules[pos1]->position;

	if (distance < 0.0 )
	{
		distance = distance + LONGUEUR_VOIE_KM;
		return distance;
	}

	
	return distance;
}

double voie_dist_vehicule_suivant(const t_voie* voie, const t_vehicule* vehicule)//pierre a faire
{
	return 0.0;
}

double voie_dist_vehicule_precedent(const t_voie* voie, const t_vehicule* vehicule)//pierre a faire
{
	return 0.0;
}

double voie_vitesse_cible_vehicule_precedent(t_voie* voie, t_vehicule* vehicule) //David
{
	double vitesse;

	if ()
	{

	}


	return vitesse;
}

double voie_vitesse_vehicule_suivant(t_voie* voie, t_vehicule* vehicule) //David
{
	return 0.0;
}

void voie_avance_vehicule(t_voie* voie, t_vehicule* vehicule, double distance) //David
{
}

void voie_avancer_vehicule(t_voie* voie, t_vehicule* vehicule, double distance)
{
}

int voie_nb_vehicules_sous_vitesse_cible(t_voie* voie)
{
	return 0;
}



int voie_insertion_valide(const t_voie* voie, const t_vehicule* vehicule, int indice, double distance_min)
{
	int indice = voie_position_insertion(voie, vehicule, distance_min);

	//si aucune position disponible ou nb_max de vehicule atteint
	if (indice == -1 || voie->nb_vehicules + 1 > MAX_VEHICULES_PAR_VOIE)
		return 0;

	//Condition qui verifie si le vehicule respecte la distance minimum
	int distance_devant_ok = (voie->vehicules[indice]->position + distance_min) < voie->vehicules[indice + 1]->position;
	int distance_arriere_ok = (voie->vehicules[indice]->position - distance_min) > (voie->vehicules[indice - 1]->position);
	if (distance_devant_ok && distance_arriere_ok)
		return 1;
	else
		return 0;
}
