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

t_voie* voie_init(int max_vehicules, double longeur_km);
/*
VOIE_INIT
Alloue une voie pouvant acceuillir un nombre maximal de véhicules déterminé
et ayant une taille en KM déterminée.
PARAMS:
- max_vehicules (int): Nombre maximal de véhicules que la voie peut acceuillir
- longueur_km: La longueur de la voie en km.
RETOUR: La référence vers la voie ayant été allouée.
*/

void voie_free(t_voie* voie);
/*
VOIE_FREE
Détruit une voie en mémoire. La fonction libère la mémoire occupée
par chacun des véhicules se situant sur la voie.
PARAM:
- voie: La référence vers voie à détruire.
RETOUR: Aucun
*/

int voie_ajouter_vehicule(t_voie* voie, t_vehicule* vehicule, double distance_min);
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

int voie_retirer_vehicule(t_voie* voie, const t_vehicule* vehicule);
/**
 * VOIE_RETIRER_VEHICULE
 * Retire un véhicule d'une voie donnée. Retourne une valeur fausse si le véhicule
 * ne se trouvait pas sur la voie.
 * PARAM:
 * voie: Référence vers la voie de laquelle le véhicule doit être retiré.
 * vehicule: Référence vers le véhicule devant être retiré de la voie.
 */

int voie_changement_voie_possible(const t_voie* nouvelle_voie, const t_vehicule* vehicule); 
/**
 * VOIE_CHANGEMENT_VOIE_POSSIBLE
 * Détermine si un véhicule (se trouvant sur une voie donnée) peut intégrer
 * la voie passée en paramètre. Le véhicule peut changer de voie si il n'y a
 * aucun autre véhicule sur la nouvelle voie à moins de
 */

void voie_liberer(t_voie* voie);  
/*Libère l’espace occupé par une voie. La fonction doit notamment libérer
l’espace mémoire occupé par tous ses véhicules.
t_route* route_init(int nb_voies, double vitesse_min,
	double vitesse_max, double longueur_visible,
	int max_vehicules_voie);
Alloue l’espace mémoire pour une route et initialise ses champs aux valeurs
des paramètres transmis.La fonction doit remplir le tableau de références
vers des voies en créant de nouvelles voies.
La fonction retourne la référence vers la route créée.
*/

int voie_position_insertion(const t_voie* voie, const t_vehicule* vehicule, double distance_min);  
/*Fonction privée du module qui détermine à quel indice le véhicule
« vehicule » devrait être inséré dans le tableau de véhicules de la voie
« voie », de sorte que l’on préserve l’ordre croissant des véhicules dans le
tableau(par leur position). (MAJ : Cette fonction ne doit plus être privée)
La fonction retourne l’indice de la position identifiée s’il est possible
d’insérer le véhicule dans la voie, ou la valeur - 1 sinon.Vous devez vous
assurer que la voie n’est pas déjà pleine(auquel cas retourner - 1).
*/

int voie_ajouter_vehicule(t_voie* voie, t_vehicule* vehicule, double distance_min); 
/*Ajoute le véhicule « vehicule » à la voie « voie ».Le véhicule doit être
ajouté uniquement si c’est possible.Notamment, le véhicule ne peut pas être
ajouté si, en l’ajoutant, il se trouverait à moins que « distance_min » du
véhicule suivant ou précédent.Les fonctions privées précédentes devraient
être utiles à cette fonction.
La fonction retourne une valeur vraie si le véhicule a bien été ajouté, ou
une valeur fausse sinon.
*/

int voie_trouver_vehicule(const t_voie* voie, const t_vehicule* vehicule); 
/*Fonction privée du module qui détermine si le véhicule « vehicule » se
trouve sur la voie « voie ».Si le véhicule s’y trouve, son indice dans le
tableau de véhicules de la voie est retourné.Sinon, la fonction retourne la
valeur - 1.
*/

int voie_retirer_vehicule(t_voie* voie, const t_vehicule* vehicule); 
/*Supprime le véhicule « vehicule » de la liste des véhicules se trouvant sur
la voie « voie »(s’il s’y trouve) et met à jour le nombre de véhicules de
la voie.
Notez que le tableau de véhicules doit être maintenu en ordre croissant de
véhicules et ne doit pas contenir de trous !
La fonction retourne une valeur vraie si le véhicule a bien supprimé, ou une
valeur fausse sinon.
*/


void voie_afficher_console(t_voie* voie);

int voie_trouver_vehicule(const t_voie* voie, const t_vehicule* vehicule);

double voie_dist_vehicule_suivant(const t_voie* voie, const t_vehicule* vehicule);

double voie_dist_vehicule_precedent(const t_voie* voie, const t_vehicule* vehicule);

double voie_vitesse_cible_vehicule_precedent(t_voie* voie, t_vehicule* vehicule);

double voie_vitesse_vehicule_suivant(t_voie* voie, t_vehicule* vehicule);

void voie_avance_vehicule(t_voie* voie, t_vehicule* vehicule, double distance);

void voie_avancer_vehicule(t_voie* voie, t_vehicule* vehicule, double distance);

int voie_nb_vehicules_sous_vitesse_cible(t_voie* voie);

#endif