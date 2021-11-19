//
// Created by anis on 8/5/19.
//

#ifndef MOD_VOIE_H
#define MOD_VOIE_H

#include <math.h>
#include "mod_vehicule.h"

//Taille de la voie
#define LONGUEUR_VOIE_KM 5.0
//Nombre maximal de vehicules sur une seule voie
#define MAX_VEHICULES_PAR_VOIE 300
//Distance minimale (en KM) entre les v�hicules
#define DISTANCE_MIN_ENTRE_VEHICULES 0.025
//Distance minimale (en KM) entre les v�hicules qui n�cessite un freinage d'urgence
#define DISTANCE_MIN_ENTRE_VEHICULES_FREINAGE 2*DISTANCE_MIN_ENTRE_VEHICULES
//Distance minimale (en KM) entre les v�hicules lors d'un d�passement
#define DISTANCE_MIN_ENTRE_VEHICULES_DEPASSEMENT 4*DISTANCE_MIN_ENTRE_VEHICULES
//Code d'erreur retourn� si un v�hicule est introuvable dans la voie
#define ERREUR_VEHICULE_INTROUVABLE -1

typedef struct t_voie t_voie;
typedef struct t_vehicule t_vehicule;

struct t_voie {
	t_vehicule** vehicules; //Tableau dynamique ORDONN� de r�f�rences vers des v�hicules
	int nb_vehicules; //Nombre effectif de vehicules se trouvant dans la voie
	int max_vehicules;  //Nombre maximal de vehicules qu'on peut ajouter � la voie.
	double longueur_km; //Taille (en KM) de la voie � l'�cran.
};

/*
VOIE_INIT
Alloue une voie pouvant acceuillir un nombre maximal de v�hicules d�termin�
et ayant une taille en KM d�termin�e.
PARAMS:
- max_vehicules (int): Nombre maximal de v�hicules que la voie peut acceuillir
- longueur_km: La longueur de la voie en km.
RETOUR: La r�f�rence vers la voie ayant �t� allou�e.
*/
t_voie* voie_init(int max_vehicules, double longeur_km);

/*
VOIE_FREE
D�truit une voie en m�moire. La fonction lib�re la m�moire occup�e
par chacun des v�hicules se situant sur la voie.
PARAM:
- voie: La r�f�rence vers voie � d�truire.
RETOUR: Aucun
*/
void voie_free(t_voie* voie);

/**
 * VOIE_AJOUT
 * Ajoute un vehicule dans la voie en pr�servant l'ordre des v�hicules (en se
 * basant sur la position du v�hicule).
 * Le v�hicule ne doit pas �tre ajout� sur la voie si une des situations suivantes
 * se produit:
 * - Le nombre de v�hicules dans la voie a d�j� atteint MAX_VEHICULES_PAR_VOIE;
 * - Il y'a d�j� un v�hicule � la position sp�cifi�e ou � moins d'une distance minimale sp�cifi�e.
 *
 * PARAM:
 * voie: R�f�rence vers la voie � laquelle on souhaite ajouter le v�hicule
 * vehicule: R�f�rence vers le v�hicule � ajouter
 * distance_min: La distance minimale qu'on doit avoir entre deux v�hicules successifs.
 * RETOUR:  Vrai si le v�hicule a �t� ajout�, faux sinon.
 */
int voie_ajouter_vehicule(t_voie* voie, t_vehicule* vehicule, double distance_min);

/**
 * VOIE_RETIRER_VEHICULE
 * Retire un v�hicule d'une voie donn�e. Retourne une valeur fausse si le v�hicule
 * ne se trouvait pas sur la voie.
 * PARAM:
 * voie: R�f�rence vers la voie de laquelle le v�hicule doit �tre retir�.
 * vehicule: R�f�rence vers le v�hicule devant �tre retir� de la voie.
 */
int voie_retirer_vehicule(t_voie* voie, const t_vehicule* vehicule);

/**
 * VOIE_CHANGEMENT_VOIE_POSSIBLE
 * D�termine si un v�hicule (se trouvant sur une voie donn�e) peut int�grer
 * la voie pass�e en param�tre. Le v�hicule peut changer de voie si il n'y a
 * aucun autre v�hicule sur la nouvelle voie � moins de
 */
int voie_changement_voie_possible(const t_voie* nouvelle_voie, const t_vehicule* vehicule);

void voie_afficher_console(t_voie* voie);

int voie_trouver_vehicule(const t_voie* voie, const t_vehicule* vehicule);

double voie_dist_vehicule_suivant(const t_voie* voie, const t_vehicule* vehicule);

double voie_dist_vehicule_precedent(const t_voie* voie, const t_vehicule* vehicule);

double voie_vitesse_cible_vehicule_precedent(t_voie* voie, t_vehicule* vehicule);

double voie_vitesse_vehicule_suivant(t_voie* voie, t_vehicule* vehicule);

void voie_avance_vehicule(t_voie* voie, t_vehicule* vehicule, double distance);

void voie_avancer_vehicule(t_voie* voie, t_vehicule* vehicule, double distance);

int voie_nb_vehicules_sous_vitesse_cible(t_voie* voie);

#endif //INF155_20193_TP3_MOD_VOIE_H