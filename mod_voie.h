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

t_voie* voie_init(int max_vehicules, double longeur_km);
/*
VOIE_INIT
Alloue une voie pouvant acceuillir un nombre maximal de v�hicules d�termin�
et ayant une taille en KM d�termin�e.
PARAMS:
- max_vehicules (int): Nombre maximal de v�hicules que la voie peut acceuillir
- longueur_km: La longueur de la voie en km.
RETOUR: La r�f�rence vers la voie ayant �t� allou�e.
*/

void voie_free(t_voie* voie);
/*
VOIE_FREE
D�truit une voie en m�moire. La fonction lib�re la m�moire occup�e
par chacun des v�hicules se situant sur la voie.
PARAM:
- voie: La r�f�rence vers voie � d�truire.
RETOUR: Aucun
*/

int voie_ajouter_vehicule(t_voie* voie, t_vehicule* vehicule, double distance_min);
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

int voie_retirer_vehicule(t_voie* voie, const t_vehicule* vehicule);
/**
 * VOIE_RETIRER_VEHICULE
 * Retire un v�hicule d'une voie donn�e. Retourne une valeur fausse si le v�hicule
 * ne se trouvait pas sur la voie.
 * PARAM:
 * voie: R�f�rence vers la voie de laquelle le v�hicule doit �tre retir�.
 * vehicule: R�f�rence vers le v�hicule devant �tre retir� de la voie.
 */

int voie_changement_voie_possible(const t_voie* nouvelle_voie, const t_vehicule* vehicule); 
/**
 * VOIE_CHANGEMENT_VOIE_POSSIBLE
 * D�termine si un v�hicule (se trouvant sur une voie donn�e) peut int�grer
 * la voie pass�e en param�tre. Le v�hicule peut changer de voie si il n'y a
 * aucun autre v�hicule sur la nouvelle voie � moins de
 */

void voie_liberer(t_voie* voie);  
/*Lib�re l�espace occup� par une voie. La fonction doit notamment lib�rer
l�espace m�moire occup� par tous ses v�hicules.
t_route* route_init(int nb_voies, double vitesse_min,
	double vitesse_max, double longueur_visible,
	int max_vehicules_voie);
Alloue l�espace m�moire pour une route et initialise ses champs aux valeurs
des param�tres transmis.La fonction doit remplir le tableau de r�f�rences
vers des voies en cr�ant de nouvelles voies.
La fonction retourne la r�f�rence vers la route cr��e.
*/

int voie_position_insertion(const t_voie* voie, const t_vehicule* vehicule, double distance_min);  
/*Fonction priv�e du module qui d�termine � quel indice le v�hicule
� vehicule � devrait �tre ins�r� dans le tableau de v�hicules de la voie
� voie �, de sorte que l�on pr�serve l�ordre croissant des v�hicules dans le
tableau(par leur position). (MAJ : Cette fonction ne doit plus �tre priv�e)
La fonction retourne l�indice de la position identifi�e s�il est possible
d�ins�rer le v�hicule dans la voie, ou la valeur - 1 sinon.Vous devez vous
assurer que la voie n�est pas d�j� pleine(auquel cas retourner - 1).
*/

int voie_ajouter_vehicule(t_voie* voie, t_vehicule* vehicule, double distance_min); 
/*Ajoute le v�hicule � vehicule � � la voie � voie �.Le v�hicule doit �tre
ajout� uniquement si c�est possible.Notamment, le v�hicule ne peut pas �tre
ajout� si, en l�ajoutant, il se trouverait � moins que � distance_min � du
v�hicule suivant ou pr�c�dent.Les fonctions priv�es pr�c�dentes devraient
�tre utiles � cette fonction.
La fonction retourne une valeur vraie si le v�hicule a bien �t� ajout�, ou
une valeur fausse sinon.
*/

int voie_trouver_vehicule(const t_voie* voie, const t_vehicule* vehicule); 
/*Fonction priv�e du module qui d�termine si le v�hicule � vehicule � se
trouve sur la voie � voie �.Si le v�hicule s�y trouve, son indice dans le
tableau de v�hicules de la voie est retourn�.Sinon, la fonction retourne la
valeur - 1.
*/

int voie_retirer_vehicule(t_voie* voie, const t_vehicule* vehicule); 
/*Supprime le v�hicule � vehicule � de la liste des v�hicules se trouvant sur
la voie � voie �(s�il s�y trouve) et met � jour le nombre de v�hicules de
la voie.
Notez que le tableau de v�hicules doit �tre maintenu en ordre croissant de
v�hicules et ne doit pas contenir de trous !
La fonction retourne une valeur vraie si le v�hicule a bien supprim�, ou une
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