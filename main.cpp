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

void CorAleatoria (){
    float r = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
    float g = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
    float b = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);

    glColor3f(r, g, b);
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

void Circulo(float r, bool vazado) {
    glClear(GL_COLOR_BUFFER_BIT);
    CorAleatoria();
    if (vazado){
        glBegin(GL_LINE_LOOP);
    }else{
        glBegin(GL_POLYGON);
    }
    for(int i =0; i <= 360; i++){
        double angulo = 2 * 3.1415926f * i / 360; //recupera o angulo do laço atual
        double x = r * cosf(angulo);//calcula x
        double y = r * sinf(angulo);//calcula y
        glVertex2d(x+250,y+250);//desenha :v
    }
    glEnd();
}

void eventoMouse(int btn, int state, int x, int y){
    if ( btn == GLUT_LEFT_BUTTON && state == GLUT_DOWN){
        Circulo(250, true);
    }
    else if ( btn == GLUT_RIGHT_BUTTON && state == GLUT_DOWN){
        Circulo(250, false);
    }
}

int main(int argc,char **argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(wh,ww);
    glutCreateWindow("Círculo");
    glutDisplayFunc(desenha);
    //Circulo(0.7);
    Inicializa();
    glutMouseFunc(eventoMouse);
    glutMainLoop();
    return 0;
}


    /*
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
        glColor3f(1.0f, 0.0f, 0.0f);
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
        glutCreateWindow("Círculo");
        glutDisplayFunc(desenha);
        Circulo(0.7);
        Inicializa();
        glutMainLoop();
        return 0;
    }
*/
