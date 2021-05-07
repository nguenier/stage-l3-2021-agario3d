#include "actions.h"
#include <stdio.h>


extern GLfloat xrot_camera;
extern GLfloat yrot_camera;

extern GLfloat xrot_objet;
extern GLfloat yrot_objet;
extern GLfloat zrot_objet;

extern GLfloat x_objet;
extern GLfloat z_objet;

extern GLfloat x_cam;
extern GLfloat y_cam;
extern GLfloat z_cam;

extern GLfloat z;
extern Joueur J;
extern joueur Player;

void touche_pressee(unsigned char key, int x, int y)
{
	usleep(100);

	switch (key) {
	case ESCAPE:
		exit(1);
		break;
	case 'z':
		if(z_objet>-10){
			z_objet=z_objet-0.1;
			z_cam=z_cam-0.1;
		}
		break;
	case 's':
		if(z_objet<10){
			z_objet=z_objet+0.1;
			z_cam=z_cam+0.1;
		}
		break;
	case 'q':
		if(x_objet>-10){
			x_objet=x_objet-0.1;
			x_cam=x_cam-0.1;
		}
		break;
	case 'd':
		if(x_objet<10){
			x_objet=x_objet+0.1;
			x_cam=x_cam+0.1;
		}
		break;
	}

}
void touche_speciale_pressee(int key, int x, int y)
{

	usleep(100);

	switch (key) {
	case GLUT_KEY_UP:
		xrot_camera +=5.0f;
	break;

	case GLUT_KEY_DOWN:
		xrot_camera -=5.0f;
	break;

	case GLUT_KEY_LEFT:
		yrot_camera -=2.0f;
	break;

	case GLUT_KEY_RIGHT:
		yrot_camera +=2.0f;
	break;

	default:
	break;
	}
}

void souris (int x, int y){
	J.setsourisX(x);
	J.setsourisY(y);
}

void Joueur::deplacement (){
	float width=glutGet(GLUT_WINDOW_WIDTH);
	float height=glutGet(GLUT_WINDOW_HEIGHT);
	float coeffdirecteur=0.0;
	if(_posSourisX!=width/2){
		coeffdirecteur= (_posSourisY-height/2)/(_posSourisX-width/2);
	}
	printf("Souris a: %d %d %f %f %f %f %f \n",_posSourisX,_posSourisY, x_objet,z_objet, coeffdirecteur, width, height);
	//float tangente=(coeffdirecteur-0.0)/(1.0+coeffdirecteur*0.0);

	float angle=atan(coeffdirecteur);
	printf("angle: %f \n", angle);
	float test=cos(angle);
	float test2=sin(angle);
	printf("angle: %f %f \n", test, test2);
	if(angle>0){
		if((width/2>_posSourisX) && (Player.getX()>-10+0.5) && (Player.getZ()>-10+0.5)) {
			Player.setX(Player.getX()-0.1*(cos(angle)));
			x_cam=x_cam-0.1*(cos(angle));
			Player.setZ(Player.getZ()-0.1*(sin(angle)));
			z_cam=z_cam-0.1*(sin(angle));
		}
		else if((width/2<_posSourisX) && (Player.getX()<10-0.5) && (Player.getZ()<10-0.5)){
			Player.setX(Player.getX()+0.1*(cos(angle)));
			x_cam=x_cam+0.1*(cos(angle));
			Player.setZ(Player.getZ()+0.1*(sin(angle)));
			z_cam=z_cam+0.1*(sin(angle));
		}
	}
	if(angle<0){
		if((width/2>_posSourisX) && (Player.getX()>-10+0.5) && (Player.getZ()<10-0.5)) {
			Player.setX(Player.getX()-0.1*(cos(angle)));
			x_cam=x_cam-0.1*(cos(angle));
			Player.setZ(Player.getZ()-0.1*(sin(angle)));
			z_cam=z_cam-0.1*(sin(angle));
		}
		else if((width/2<_posSourisX) && (Player.getX()<10-0.5) && (Player.getZ()>-10+0.5)){
			Player.setX(Player.getX()+0.1*(cos(angle)));
			x_cam=x_cam+0.1*(cos(angle));
			Player.setZ(Player.getZ()+0.1*(sin(angle)));
			z_cam=z_cam+0.1*(sin(angle));
		}
	}
	// lorsque la souris est dans l'axe vertical ou horizontal
	if(angle==0){
		if((width/2>_posSourisX) && (Player.getX()>-10+0.5)){
			Player.setX(Player.getX()-0.1*(cos(angle)));
			x_cam=x_cam-0.1*(cos(angle));
		}
		else if((width/2<_posSourisX) && (Player.getX()<10-0.5)){
			Player.setX(Player.getX()+0.1*(cos(angle)));
			x_cam=x_cam+0.1*(cos(angle));
		}
		else if((height/2>_posSourisY) && (Player.getZ()>-10+0.5)){
			Player.setZ(Player.getZ()-0.1*(cos(angle)));
			z_cam=z_cam-0.1*(cos(angle));
		}
		else if((height/2<_posSourisY) && (Player.getZ()<10-0.5)){
			Player.setZ(Player.getZ()+0.1*(cos(angle)));
			z_cam=z_cam+0.1*(cos(angle));
		}
	}
}
