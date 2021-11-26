//
// Created by anis on 8/5/19.
//

#ifndef MOD_VOIE_H
#define MOD_VOIE_H

#include <math.h>
#include "mod_vehicule.h"

//Taille des voies la voie � l��cran en KM (i.e. circonf�rence du cercle)
#define LONGUEUR_VOIE_KM 10.0
//Nombre maximal de v�hicules sur une seule voie
#define MAX_VEHICULES_PAR_VOIE 300
//Distance minimale (en KM) entre les v�hicules
#define DISTANCE_MIN_ENTRE_VEHICULES 0.025
//Distance minimale (en KM) entre 2 v�hicules qui n�cessite un freinage d�urgence
#define DISTANCE_MIN_ENTRE_VEHICULES_FREINAGE 2*DISTANCE_MIN_ENTRE_VEHICULES
//Distance minimale (en KM) entre les v�hicules lors d'un d�passement
#define DISTANCE_MIN_ENTRE_VEHICULES_DEPASSEMENT 4*DISTANCE_MIN_ENTRE_VEHICULES
//Code d'erreur retourn� si un v�hicule est introuvable dans la voie
#define ERREUR_VEHICULE_INTROUVABLE -1
typedef struct vehicule t_vehicule; //R�p�tition du type pour la compilation
typedef struct voie t_voie;
//D�finit le type struct voie qui encapsule les v�hicules qui y circulent
struct voie {
	t_vehicule** vehicules; //Tableau dynamique ORDONN� de r�f�rences vers
	//des v�hicules (ordonn� par position sur la voie)
	int nb_vehicules; //Nombre effectif de v�hicules se trouvant dans la voie
	int max_vehicules; //Nombre max. de v�hicules qu'on peut ajouter � la voie
	double longueur_km; //Taille (en KM) de la voie � l'�cran
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

double calculer_distance_vehicules(const t_voie* voie, int pos1, int pos2);//pierre
/*Fonction priv�e du module � mod_voie � qui calcule la distance entre deux
v�hicules se trouvant sur la voie � voie �.Le premier v�hicule se trouve �
la position � pos1 � du tableau de v�hicules de la voie et le second se
trouve � la position � pos2 �.Dans cette fonction, vous assumez que le
v�hicule se trouvant � � pos1 � est derri�re le v�hicule � � pos2 �.
Note : n�oubliez pas que la voie est circulaire, lorsqu�on arrive � la fin
de la voie, on repart � la position 0.
*/
double voie_dist_vehicule_suivant(const t_voie* voie, const t_vehicule* vehicule);//pierre
/*Retourne la distance entre le v�hicule � vehicule � et le v�hicule suivant
sur la voie � voie �.
Si � vehicule � n�existe pas sur la voie, la fonction retourne une valeur
n�gative.
*/

double voie_dist_vehicule_precedent(const t_voie* voie, const t_vehicule* vehicule);//pierre
/*Retourne la distance entre le v�hicule � vehicule � et le v�hicule qui le
pr�c�de sur la voie � voie �.
Si � vehicule � n�existe pas sur la voie, la fonction retourne une valeur
n�gative.*/

double voie_vitesse_cible_vehicule_precedent(t_voie* voie, t_vehicule* vehicule); //David
/*Retourne la vitesse cible du v�hicule qui pr�c�de le v�hicule � vehicule �
sur la voie � voie �.
Si � vehicule � n�existe pas sur la voie, la fonction retourne une valeur
n�gative.*/

double voie_vitesse_vehicule_suivant(t_voie* voie, t_vehicule* vehicule); //David
/*Retourne la vitesse actuelle du v�hicule se trouvant apr�s le v�hicule
� vehicule � sur la voie � voie �.
Si � vehicule � n�existe pas sur la voie, la fonction retourne une valeur
n�gative.*/

void voie_avancer_vehicule(t_voie* voie, t_vehicule* vehicule, double distance); //David
/*Fait avancer le v�hicule � vehicule � sur la voie � voie � d�une distance
� distance �.La fonction doit mettre � jour la position du v�hicule ainsi
que la voie.
Si le v�hicule a effectu� un tour complet, sa position doit se mettre � jour
en repartant � 0. Par exemple, si le v�hicule �tait � la position 30.78km
sur une voie de longueur 30km, la position du v�hicule doit �tre modifi�e
pour la valeur 0.78km.
De plus, vous devez vous assurer que les v�hicules sur la voie soient
toujours ordonn�s par ordre croissant de leur position.*/

int voie_nb_vehicules_sous_vitesse_cible(t_voie* voie);

int voie_insertion_valide(const t_voie* voie, const t_vehicule* vehicule,
	int indice, double distance_min);
/*Fonction priv�e du module qui d�termine s�il est possible d�ins�rer le
v�hicule � vehicule � sur la voie � voie � � la position � indice � du
tableau, en pr�servant une distance minimale � distance_min � entre le
v�hicule pr�c�dent et le v�hicule suivant.
La fonction retourne une valeur vraie si c�est possible, ou une valeur
fausse sinon.
pierre
*/
#endif