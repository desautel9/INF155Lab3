#define GEO_POLYGONE_MAX_PTS 10
//Définit un point dans le plan
typedef struct {
	int x; //abscisse
	int y; //ordonnée
} t_point;
//Définit un polygone qui est un ensemble de points
typedef struct t_polygone {
	t_point points[GEO_POLYGONE_MAX_PTS]; //Tableau statique de points
	int nb_points; //Nombre de points dans le tableau
} t_polygone;