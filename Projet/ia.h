#pragma once
#include <iostream>
#include <GL/glut.h>
#include <GL/gl.h>
#include <math.h>
#include<GL/freeglut.h>
#include <time.h>
#include <stdlib.h>
#include <GL/glu.h>

#include "joueurs.h"

class Ia : public Joueurs {
public:
  Ia():Joueurs(){}
  void setiaX(int x){this->_posAleatoireX=x;}
  void setiaY(int y){this->_posAleatoireY=y;}
  void deplacement(int const i);
private:
  int _posAleatoireX;
  int _posAleatoireY;
};
