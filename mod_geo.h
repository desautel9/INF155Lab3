#define GEO_POLYGONE_MAX_PTS 10
//D�finit un point dans le plan
typedef struct {
	int x; //abscisse
	int y; //ordonn�e//
} t_point;
//D�finit un polygone qui est un ensemble de points
typedef struct t_polygone {
	t_point points[GEO_POLYGONE_MAX_PTS]; //Tableau statique de points
	int nb_points; //Nombre de points dans le tableau
} t_polygone;

/*
Ajoute les nb_pts points se trouvant dans le tableau pts au polygone poly.
Les points sont ajout�s dans le polygone � partir de la position 0.
La fonction renvoie une valeur vraie si tous les points du tableau ont pu
�tre ajout�s au polygone, ou valeur fausse sinon.
*/
int geo_ajouter_tab_polygone(t_polygone* poly, t_point pts[], int nb_pts);

/*
Re�oit une r�f�rence vers un point point et un angle angle. La fonction
effectue la rotation du point par rapport � l�origine. En supposant que le
point se trouve aux coordonn�es (x,y) et que ses coordonn�es apr�s la
rotation sont (x�, y�), la formule permettant de calculer les nouvelles
coordonn�es est la suivante :
x� = x.cos(angle) - y.sin(angle)
y� = x.sin(angle) + y.cos(angle) 
*/
void geo_rotation_point(t_point* point, double angle);