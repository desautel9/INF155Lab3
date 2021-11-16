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

void geo_init_polygone(t_polygone* poly, int taille);
/*Initialise le polygone re�u par r�f�rence en lui assignant le nombre de
points d�finit par la taille re�ue.
Si le nombre de points demand� exc�de GEO_POLYGONE_MAX_PTS, vous devez
initialiser le nombre de points du polygone � 0.*/

int geo_ajouter_point_polygone(t_polygone* poly, t_point pt, int position);
/*Ajoute le point pt re�u en param�tre au tableau de points du polygone � la
position position.Les positions doivent �tre entre 0 et le nombre de points
du polygone - 1. Si une position invalide a �t� transmise, il ne faut pas
ajouter le point.
La fonction retourne une valeur vraie si le point a bien �t� ajout�, ou une
valeur fausse sinon(position non - valide).*/