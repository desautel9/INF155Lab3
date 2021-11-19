#ifndef MOD_ROUTE_H
#define MOD_ROUTE_H

#include "mod_voie.h"

#define ROUTE_MAX_VOIES 10
#define DELTA_T_INTERATIONS_SECS 1.5 //Temps entre chaque boucle de simulation

typedef struct voie t_voie; //Répétition du type pour la compilation
typedef struct vehicule t_vehicule; //Répétition du type pour la compilation
typedef struct route t_route;

//Définit le type struct route qui encapsule les voies
struct route {
	t_voie* voies[ROUTE_MAX_VOIES]; //Tableau statique de références vers
	//des voies
	int nb_voies; //Le nombre de voies dans le tableau de voies
	double vitesse_max; //La vitesse maximale autorisée sur la route
	double vitesse_min; //La vitesse minimale autorisée sur la route
};

t_vehicule* vehicule_init(void);
//Alloue la mémoire pour un véhicule et initialise la géométrie(polygone) du
//véhicule.Le véhicule sera positionné à la position zéro et aura une vitesse
//réelle et une vitesse cible nulles.
//La fonction retourne une référence vers le véhicule créé.

void vehicule_liberer(t_vehicule* vehicule);
//Libère l’espace mémoire d’un véhicule dont la référence est passée en
//paramètre.
//t_voie* voie_init(int max_vehicules, double longeur_km);
//Alloue une voie pouvant accueillir un nombre maximal de véhicules déterminé
//(max_vehicules) et ayant une taille en KM déterminée(longueur_km).
//La fonction retourne une référence vers la voie créée.

void voie_liberer(t_voie* voie);
//Libère l’espace occupé par une voie.La fonction doit notamment libérer
//l’espace mémoire occupé par tous ses véhicules.
//t_route* route_init(int nb_voies, double vitesse_min,
//	double vitesse_max, double longueur_visible,
//	int max_vehicules_voie);
//Alloue l’espace mémoire pour une route et initialise ses champs aux valeurs
//des paramètres transmis.La fonction doit remplir le tableau de références
//vers des voies en créant de nouvelles voies.
//La fonction retourne la référence vers la route créée.

void route_liberer(t_route* route);
//Libère tout l’espace mémoire occupé par la route dont la référence est
//transmise en paramètre.Les voies et véhicules contenus par la route doivent
//également être libérées.
//int voie_insertion_valide(const t_voie* voie, const t_vehicule* vehicule,
//	int indice, double distance_min);
//Fonction privée du module qui détermine s’il est possible d’insérer le
//véhicule « vehicule » sur la voie « voie » à la position « indice » du
//tableau, en préservant une distance minimale « distance_min » entre le
//véhicule précédent et le véhicule suivant.
//La fonction retourne une valeur vraie si c’est possible, ou une valeur
//fausse sinon.

int voie_position_insertion(const t_voie* voie, const t_vehicule* vehicule, double distance_min);
//Fonction privée du module qui détermine à quel indice le véhicule
//« vehicule » devrait être inséré dans le tableau de véhicules de la voie
//« voie », de sorte que l’on préserve l’ordre croissant des véhicules dans le
//tableau(par leur position). (MAJ : Cette fonction ne doit plus être privée)
//La fonction retourne l’indice de la position identifiée s’il est possible
//d’insérer le véhicule dans la voie, ou la valeur - 1 sinon.Vous devez vous
//assurer que la voie n’est pas déjà pleine(auquel cas retourner - 1).

int voie_ajouter_vehicule(t_voie * voie, t_vehicule * vehicule, double distance_min);
//Ajoute le véhicule « vehicule » à la voie « voie ».Le véhicule doit être
//ajouté uniquement si c’est possible.Notamment, le véhicule ne peut pas être
//ajouté si, en l’ajoutant, il se trouverait à moins que « distance_min » du
//véhicule suivant ou précédent.Les fonctions privées précédentes devraient
//être utiles à cette fonction.
//La fonction retourne une valeur vraie si le véhicule a bien été ajouté, ou
//une valeur fausse sinon.

int voie_trouver_vehicule(const t_voie* voie, const t_vehicule* vehicule);
//Fonction privée du module qui détermine si le véhicule « vehicule » se
//trouve sur la voie « voie ».Si le véhicule s’y trouve, son indice dans le
//tableau de véhicules de la voie est retourné.Sinon, la fonction retourne la
//valeur - 1.

int voie_retirer_vehicule(t_voie * voie, const t_vehicule * vehicule);
//Supprime le véhicule « vehicule » de la liste des véhicules se trouvant sur
//la voie « voie »(s’il s’y trouve) et met à jour le nombre de véhicules de
//la voie.
//Notez que le tableau de véhicules doit être maintenu en ordre croissant de
//véhicules et ne doit pas contenir de trous !
//La fonction retourne une valeur vraie si le véhicule a bien supprimé, ou une
//valeur fausse sinon.

#endif