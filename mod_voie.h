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
//Distance minimale (en KM) entre les véhicules
#define DISTANCE_MIN_ENTRE_VEHICULES 0.025
//Distance minimale (en KM) entre les véhicules qui nécessite un freinage d'urgence
#define DISTANCE_MIN_ENTRE_VEHICULES_FREINAGE 2*DISTANCE_MIN_ENTRE_VEHICULES
//Distance minimale (en KM) entre les véhicules lors d'un dépassement
#define DISTANCE_MIN_ENTRE_VEHICULES_DEPASSEMENT 4*DISTANCE_MIN_ENTRE_VEHICULES
//Code d'erreur retourné si un véhicule est introuvable dans la voie
#define ERREUR_VEHICULE_INTROUVABLE -1

typedef struct t_voie t_voie;
typedef struct t_vehicule t_vehicule;

struct t_voie {
	t_vehicule** vehicules; //Tableau dynamique ORDONNÉ de références vers des véhicules
	int nb_vehicules; //Nombre effectif de vehicules se trouvant dans la voie
	int max_vehicules;  //Nombre maximal de vehicules qu'on peut ajouter à la voie.
	double longueur_km; //Taille (en KM) de la voie à l'écran.
};

/*
VOIE_INIT
Alloue une voie pouvant acceuillir un nombre maximal de véhicules déterminé
et ayant une taille en KM déterminée.
PARAMS:
- max_vehicules (int): Nombre maximal de véhicules que la voie peut acceuillir
- longueur_km: La longueur de la voie en km.
RETOUR: La référence vers la voie ayant été allouée.
*/
t_voie* voie_init(int max_vehicules, double longeur_km);

/*
VOIE_FREE
Détruit une voie en mémoire. La fonction libère la mémoire occupée
par chacun des véhicules se situant sur la voie.
PARAM:
- voie: La référence vers voie à détruire.
RETOUR: Aucun
*/
void voie_free(t_voie* voie);

/**
 * VOIE_AJOUT
 * Ajoute un vehicule dans la voie en préservant l'ordre des véhicules (en se
 * basant sur la position du véhicule).
 * Le véhicule ne doit pas être ajouté sur la voie si une des situations suivantes
 * se produit:
 * - Le nombre de véhicules dans la voie a déjà atteint MAX_VEHICULES_PAR_VOIE;
 * - Il y'a déjà un véhicule à la position spécifiée ou à moins d'une distance minimale spécifiée.
 *
 * PARAM:
 * voie: Référence vers la voie à laquelle on souhaite ajouter le véhicule
 * vehicule: Référence vers le véhicule à ajouter
 * distance_min: La distance minimale qu'on doit avoir entre deux véhicules successifs.
 * RETOUR:  Vrai si le véhicule a été ajouté, faux sinon.
 */
int voie_ajouter_vehicule(t_voie* voie, t_vehicule* vehicule, double distance_min);

/**
 * VOIE_RETIRER_VEHICULE
 * Retire un véhicule d'une voie donnée. Retourne une valeur fausse si le véhicule
 * ne se trouvait pas sur la voie.
 * PARAM:
 * voie: Référence vers la voie de laquelle le véhicule doit être retiré.
 * vehicule: Référence vers le véhicule devant être retiré de la voie.
 */
int voie_retirer_vehicule(t_voie* voie, const t_vehicule* vehicule);

/**
 * VOIE_CHANGEMENT_VOIE_POSSIBLE
 * Détermine si un véhicule (se trouvant sur une voie donnée) peut intégrer
 * la voie passée en paramètre. Le véhicule peut changer de voie si il n'y a
 * aucun autre véhicule sur la nouvelle voie à moins de
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