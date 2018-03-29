#include<stdlib.h>
#include<gl/glut.h>
#include <math.h>
#include<iostream>

    using namespace std;

    GLsizei wh=500,ww=500;
    GLfloat size=30.0;
    int quadradoCount = 0;

    void desenha()
    {
        glFlush();
    }

    void Inicializa()
    {
        glViewport(0,0,ww,wh);
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        gluOrtho2D(0.0,(GLdouble)ww,0.0,(GLdouble)wh);
        glMatrixMode(GL_MODELVIEW);
        glClearColor(0.0,0.0,0.0,1.0);
     }

    void Circulo(float r) {
        glBegin(GL_LINE_LOOP);
        for(int i =0; i <= 300; i++){
            double angulo = 2 * 3.1415926f * i / 300; //recupera o angulo do laço atual
            double x = r * cosf(angulo);//calcula x
            double y = r * sinf(angulo);//calcula y
            glVertex2d(x,y);//desenha :v
        }
        glEnd();
    }

    int main(int argc,char **argv)
    {
        glutInit(&argc,argv);
        glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
        glutInitWindowSize(wh,ww);
        glutCreateWindow("Hierarchical Menus to Draw Squares");
        glutDisplayFunc(desenha);
        Circulo(0.7);
        Inicializa();
        glutMainLoop();
        return 0;
    }
