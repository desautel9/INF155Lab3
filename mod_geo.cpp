//
// Créer par David Hill, Olivier Deshautels, Pierre Rayeroux
// Date remise : 2021-12-04
//

#include "mod_geo.h"
#define _CRT_SECURE_NO_WARNINGS


int geo_ajouter_tab_polygone(t_polygone* poly, t_point pts[], int nb_pts)
{
	for (size_t i = 0; i < nb_pts; i++)
	{
		int succes = geo_ajouter_point_polygone(poly, pts[i], i);
		if (!succes) //Erreur, certains points n'ont pas ete ajoute
			return 0;
	}
	return 1;
}

void geo_rotation_point(t_point* point, double angle)
{
	//Variables
	int x;

	//Formule permettant de calculer les nouvelles coordonnées
	x = point->x * cos(angle) - point->y * sin(angle);
	point->y = point->x * sin(angle) + point->y * cos(angle);
	point->x = x;
}

void geo_init_polygone(t_polygone* poly, int taille)
{
	if (taille > GEO_POLYGONE_MAX_PTS)
		taille = 0;
	poly->nb_points = taille;
	for (size_t i = 0; i < taille; i++)
	{
		t_point point;
		point.x = 0;
		point.y = 0;
		geo_ajouter_point_polygone(poly, point, i);
	}
}

int geo_ajouter_point_polygone(t_polygone* poly, t_point pt, int position)
{
	//Les positions doivent être entre 0 et le nombre de points du polygone - 1.
	if (position > 0 && position < poly->nb_points - 1) 
	{
		//Ajoute le point pt reçu en paramètre au tableau de points du polygone à la position position.
		poly->points[position] = pt;

		return 1; //Le point a bien ete ajoute
	}
	return 0; //Position non-valide
}

void geo_rotation_polygone(t_polygone* poly, double angle)
{
	for (size_t i = 0; i < poly->nb_points; i++)
	{
		geo_rotation_point(&poly->points[i], angle);
	}
}
