//
// Cr�er par David Hill, Olivier Deshautels, Pierre Rayeroux
// Date remise : 2021-12-04
//

#include "mod_vehicule.h"
#define _CRT_SECURE_NO_WARNINGS





void vehicule_reset_geometrie(t_vehicule* vehicule)
/*R�initialise le polygone du v�hicule dont la r�f�rence est pass�e en
param�tre.Ensuite, la fonction doit d�finir les coordonn�es des points du
polygone en se basant sur VEHICULE_LONGUEUR et VEHICULE_LARGEUR.Le premier
point du polygone doit absolument se trouver aux coordonn�es(0, 0).*/{}double vehicule_calculer_deplacement(t_vehicule* vehicule, double delta_t)
/*Calcule et retourne la valeur du d�placement du v�hicule(pass� par
	r�f�rence) apr�s un temps delta_t en se basant sur sa vitesse.*/{}