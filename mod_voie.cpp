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

	voie->vehicules = (t_vehicule**)malloc(sizeof(t_vehicule) * 10);
	voie->nb_vehicules = 0;
	return voie;
}

void voie_free(t_voie* voie)
{
	//Libère l’espace occupé par une voie.
	free(voie->vehicules); //Libérer l’espace mémoire occupe par tous ses véhicules.
	free(voie);
}

int voie_ajouter_vehicule(t_voie* voie, t_vehicule* vehicule, double distance_min)
{
	if (voie->nb_vehicules > 0)
	{
		int indice = voie_position_insertion(voie, vehicule, distance_min);
		if (voie_insertion_valide(voie, vehicule, indice, distance_min))
		{
			for (int i = voie->nb_vehicules - 1; i >= indice; i--)
			{
				voie->vehicules[i + 1] = voie->vehicules[i];
			}
			voie->vehicules[indice] = vehicule;
			voie->nb_vehicules++;
			voie_tri_vehicule(voie->vehicules, voie->nb_vehicules);//juste pour être sur que tout est en ordre

			return 1;
		}

		else
			return 0;
	}
	else //aucun vehicule
	{
		voie->vehicules[0] = vehicule;
		voie->nb_vehicules++;
	}
}

int voie_position_insertion(const t_voie* voie, const t_vehicule* vehicule, double distance_min)
{
	for (int i = 0; i < voie->nb_vehicules; i++)
	{
		if (vehicule->position >= voie->vehicules[i]->position)
			return i;
	}
	return 0;
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
		voie->vehicules[i] = voie->vehicules[i + 1];
	}

}

double calculer_distance_vehicules(const t_voie* voie, int pos1, int pos2)//pierre fait
{
	double distance = voie->vehicules[pos2]->position - voie->vehicules[pos1]->position;

	if (distance < 0.0)
	{
		distance = distance + LONGUEUR_VOIE_KM;
		return distance;
	}


	return distance;
}

double voie_dist_vehicule_suivant(const t_voie* voie, const t_vehicule* vehicule)//pierre fait
{
	int pos1, pos2;

	if (voie->nb_vehicules <= 1) // si un seul vehicule sur la voie 
	{
		return -1;
	}

	int indice = voie_trouver_vehicule(voie, vehicule);
	if (indice == voie->nb_vehicules - 1)// vehicule en derniere position
	{
		pos1 = indice;
		pos2 = 0;
	}
	else
	{
		pos1 = indice;
		pos2 = indice + 1;
	}




	return calculer_distance_vehicules(voie, pos1, pos2);//pierre fait
}

double voie_dist_vehicule_precedent(const t_voie* voie, const t_vehicule* vehicule)
{
	int pos1, pos2;

	if (voie->nb_vehicules <= 1) // si un seul vehicule sur la voie 
	{
		return -1;
	}

	int indice = voie_trouver_vehicule(voie, vehicule);
	if (indice == 0)// vehicule en premiere position
	{
		pos1 = indice;
		pos2 = voie->nb_vehicules - 1;
	}
	else
	{
		pos1 = indice;
		pos2 = indice - 1;
	}




	return calculer_distance_vehicules(voie, pos1, pos2);

}

double voie_vitesse_vehicule_precedent(t_voie* voie, t_vehicule* vehicule)
{
	if (voie->nb_vehicules >= 1) //Si il n'y a que 1 ou 0 véhicule sur la route
	{
		return -1;
	}
	//Pour avoir la position du vehicule
	int indice = voie_trouver_vehicule(voie, vehicule);
	//Si le véhicule se trouve a l'emplacement 0, on doit prendre le vehicule qui se trouve
	//la fin du tableau des position
	if (indice == 0)
	{
		int indice_precedent = voie->nb_vehicules - 1; //Position du vehicule precedent
		t_vehicule* vehicule_precedent = voie->vehicules[indice_precedent];
		double vitesse_cible = vehicule_precedent->vitesse_cible;
		return vitesse_cible;
	}
}

double voie_vitesse_vehicule_suivant(t_voie* voie, t_vehicule* vehicule) //David
{
	if (voie->nb_vehicules >= 1) //Si il n'y a que 1 ou 0 véhicule sur la route
	{
		return -1;
	}

	int indice = voie_trouver_vehicule(voie, vehicule); //Pour avoir la position du vehicule
	//Si le véhicule se trouve a l'emplacement 0, on doit prendre le véhicule suivant
	if (indice == voie->nb_vehicules - 1) 
	{
		int indice_suivant = voie->nb_vehicules + 1; //Position du vehicule suivant
		t_vehicule* vehicule_suivant = voie->vehicules[indice_suivant];
		double vitesse_cible = vehicule_suivant->vitesse_cible;
		return vitesse_cible;
	}
}

void voie_avance_vehicule(t_voie* voie, t_vehicule* vehicule, double distance)
{
	vehicule->position += distance; //Fait avancer le vehicule d'une distance

	if (vehicule->position > voie->longueur_km) //Si le vehicule fait un tour complet et plus
	{
		vehicule->position -= voie->longueur_km; //Position du vehicule modifié au restant de la longeur_km
	}

	voie_tri_vehicule(voie->vehicules, voie->nb_vehicules); //Tri pour ordonner par ordre croissant de leur position
}


int voie_nb_vehicules_sous_vitesse_cible(t_voie* voie)
{
	int i, nb_vehicule_lent=0;

	for (i = 0; i <= voie->nb_vehicules; ++i)
	{
		if (voie->vehicules[i]->vitesse < (voie->vehicules[i]->vitesse_cible*0.9))// vitesse vehicule inferieur de 10% de vitesse cible 
			++nb_vehicule_lent;
	}
	

	return nb_vehicule_lent;// retourne le total de vehicule lent sur la voie 
}



int voie_insertion_valide(const t_voie* voie, const t_vehicule* vehicule, int indice, double distance_min)
{
	//si aucune position disponible ou nb_max de vehicule atteint
	if (indice == -1 || voie->nb_vehicules + 1 > MAX_VEHICULES_PAR_VOIE)
		return 0;

	if (voie->nb_vehicules <= 1) //insertion possible si il n'y a qu'un vehicule
		return 1;

	//Conditions qui verifient si le vehicule respecte la distance minimum
	int distance_devant_ok = 1;
	int distance_arriere_ok = 1;

	if (voie->nb_vehicules - 1 > indice)
		distance_devant_ok = (voie->vehicules[indice]->position + distance_min) <= voie->vehicules[indice + 1]->position;

	if (indice > 0)
		distance_arriere_ok = (voie->vehicules[indice]->position - distance_min) >= (voie->vehicules[indice - 1]->position);

	if (distance_devant_ok && distance_arriere_ok)
		return 1;
	else
		return 0;
}

void voie_tri_vehicule(t_vehicule* tab[], int taille)
{
	for (int i = taille; i >= 1; i--)
	{
		for (int j = 0; j < i - 1; j++)
		{
			if (tab[j]->position > tab[j + 1]->position)
			{
				t_vehicule* temp = tab[j];
				tab[j] = tab[j + 1];
				tab[j + 1] = temp;
			}
		}
	}
}
