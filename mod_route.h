#ifndef MOD_ROUTE_H
#define MOD_ROUTE_H

#include "mod_voie.h"

#define ROUTE_MAX_VOIES 10
#define DELTA_T_INTERATIONS_SECS 1.5 //Temps entre chaque boucle de simulation

typedef struct voie t_voie; //R�p�tition du type pour la compilation
typedef struct vehicule t_vehicule; //R�p�tition du type pour la compilation
typedef struct route t_route;

//D�finit le type struct route qui encapsule les voies
struct route {
	t_voie* voies[ROUTE_MAX_VOIES]; //Tableau statique de r�f�rences vers
	//des voies
	int nb_voies; //Le nombre de voies dans le tableau de voies
	double vitesse_max; //La vitesse maximale autoris�e sur la route
	double vitesse_min; //La vitesse minimale autoris�e sur la route
};

t_vehicule* vehicule_init(void);
//Alloue la m�moire pour un v�hicule et initialise la g�om�trie(polygone) du
//v�hicule.Le v�hicule sera positionn� � la position z�ro et aura une vitesse
//r�elle et une vitesse cible nulles.
//La fonction retourne une r�f�rence vers le v�hicule cr��.

void vehicule_liberer(t_vehicule* vehicule);
//Lib�re l�espace m�moire d�un v�hicule dont la r�f�rence est pass�e en
//param�tre.
//t_voie* voie_init(int max_vehicules, double longeur_km);
//Alloue une voie pouvant accueillir un nombre maximal de v�hicules d�termin�
//(max_vehicules) et ayant une taille en KM d�termin�e(longueur_km).
//La fonction retourne une r�f�rence vers la voie cr��e.

void voie_liberer(t_voie* voie);
//Lib�re l�espace occup� par une voie.La fonction doit notamment lib�rer
//l�espace m�moire occup� par tous ses v�hicules.
//t_route* route_init(int nb_voies, double vitesse_min,
//	double vitesse_max, double longueur_visible,
//	int max_vehicules_voie);
//Alloue l�espace m�moire pour une route et initialise ses champs aux valeurs
//des param�tres transmis.La fonction doit remplir le tableau de r�f�rences
//vers des voies en cr�ant de nouvelles voies.
//La fonction retourne la r�f�rence vers la route cr��e.

void route_liberer(t_route* route);
//Lib�re tout l�espace m�moire occup� par la route dont la r�f�rence est
//transmise en param�tre.Les voies et v�hicules contenus par la route doivent
//�galement �tre lib�r�es.
//int voie_insertion_valide(const t_voie* voie, const t_vehicule* vehicule,
//	int indice, double distance_min);
//Fonction priv�e du module qui d�termine s�il est possible d�ins�rer le
//v�hicule � vehicule � sur la voie � voie � � la position � indice � du
//tableau, en pr�servant une distance minimale � distance_min � entre le
//v�hicule pr�c�dent et le v�hicule suivant.
//La fonction retourne une valeur vraie si c�est possible, ou une valeur
//fausse sinon.

int voie_position_insertion(const t_voie* voie, const t_vehicule* vehicule, double distance_min);
//Fonction priv�e du module qui d�termine � quel indice le v�hicule
//� vehicule � devrait �tre ins�r� dans le tableau de v�hicules de la voie
//� voie �, de sorte que l�on pr�serve l�ordre croissant des v�hicules dans le
//tableau(par leur position). (MAJ : Cette fonction ne doit plus �tre priv�e)
//La fonction retourne l�indice de la position identifi�e s�il est possible
//d�ins�rer le v�hicule dans la voie, ou la valeur - 1 sinon.Vous devez vous
//assurer que la voie n�est pas d�j� pleine(auquel cas retourner - 1).

int voie_ajouter_vehicule(t_voie * voie, t_vehicule * vehicule, double distance_min);
//Ajoute le v�hicule � vehicule � � la voie � voie �.Le v�hicule doit �tre
//ajout� uniquement si c�est possible.Notamment, le v�hicule ne peut pas �tre
//ajout� si, en l�ajoutant, il se trouverait � moins que � distance_min � du
//v�hicule suivant ou pr�c�dent.Les fonctions priv�es pr�c�dentes devraient
//�tre utiles � cette fonction.
//La fonction retourne une valeur vraie si le v�hicule a bien �t� ajout�, ou
//une valeur fausse sinon.

int voie_trouver_vehicule(const t_voie* voie, const t_vehicule* vehicule);
//Fonction priv�e du module qui d�termine si le v�hicule � vehicule � se
//trouve sur la voie � voie �.Si le v�hicule s�y trouve, son indice dans le
//tableau de v�hicules de la voie est retourn�.Sinon, la fonction retourne la
//valeur - 1.

int voie_retirer_vehicule(t_voie * voie, const t_vehicule * vehicule);
//Supprime le v�hicule � vehicule � de la liste des v�hicules se trouvant sur
//la voie � voie �(s�il s�y trouve) et met � jour le nombre de v�hicules de
//la voie.
//Notez que le tableau de v�hicules doit �tre maintenu en ordre croissant de
//v�hicules et ne doit pas contenir de trous !
//La fonction retourne une valeur vraie si le v�hicule a bien supprim�, ou une
//valeur fausse sinon.

#endif