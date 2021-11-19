//
// Créer par David Hill, Olivier Deshautels, Pierre Rayeroux
// Date remise : 2021-12-04
//

#include "mod_geo.h"
#define _CRT_SECURE_NO_WARNINGS


int geo_ajouter_tab_polygone(t_polygone* poly, t_point pts[], int nb_pts)
{
	return 0;
}

void geo_init_polygone(t_polygone* poly, int taille)
{
	if (taille > GEO_POLYGONE_MAX_PTS)
	{
		taille = 0;
		*t_polygone = taille;
	}
	else
	{
		*t_polygone = taille;
	}
}

int geo_ajouter_point_polygone(t_polygone* poly, t_point pt, int position)
{
	if (position >= 0 && position <= *poly->nb_points - 1)
	{
		*poly->points[position] += pt;

		return 1;
	}
	return 0;
}