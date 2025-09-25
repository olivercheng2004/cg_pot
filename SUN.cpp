#include <stdio.h>
#include "Include/FreeGLUT/freeglut.h"
#define _USE_MATH_DEFINES
#include <cmath>

#define WORLD_AXES 10
#define EXITMENU 0


GLuint window;
int width = 1200;
int height = 600;
GLfloat teapotX = 0;
GLfloat teapotY = 0;
GLfloat aspect = 1;
GLfloat teapotsize = 1.0f;
GLclampf background = 0;
GLclampf oldback = 0;
unsigned int timer_interval = 32;
int clickx = 0;
int myColor = 100;
GLfloat rotateAngle = 0;
GLfloat rotateSpeed = 5.0f;
int matid = 2;

void Menu(int);
void Keyboard(unsigned char, int, int);
void Mouse(int, int, int, int);
void MouseMoving(int, int);
void Timer(int);
void Display();
void Reshape(int, int);
void init();

struct Planet {
    float distance;
    float radius;
    float speed;
    float angle;
};

Planet sun = { 0.0, 0.7, 0.0, 0.0 };
Planet mercury = { 1.2, 0.15, 1.0, 0.0 };
Planet venus = { 1.6, 0.2, 0.8, 0.0 };
Planet earth = { 2.4, 0.3, 0.5, 0.0 };
Planet mars = { 3.0, 0.22, 0.7, 0.0 };

void drawPlanet(Planet planet) {
    glPushMatrix();
    glRotatef(planet.angle, 0.0, 1.0, 0.0);
    glTranslatef(planet.distance, 0.0, 0.0);
    glutWireSphere(planet.radius, 20, 16);
    glPopMatrix();
}

void drawOrbit(Planet planet) {
    glBegin(GL_LINE_LOOP);
    glColor3f(0.5, 0.5, 0.5);
    for (int i = 0; i < 360; i++) {
        float radians = i * (M_PI / 180.0);
        float x = planet.distance * cos(radians);
        float z = planet.distance * sin(radians);
        glVertex3f(x, 0.0, z);
    }
    glEnd();
}

void update(int value) {
    sun.angle += sun.speed;
    mercury.angle += mercury.speed;
    venus.angle += venus.speed;
    earth.angle += earth.speed;
    mars.angle += mars.speed;

    glutPostRedisplay();
    glutTimerFunc(16, update, 0);
}



int main(int argc, char* argv[]) {
    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
    glutInit(&argc, argv);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(width, height);

    glutCreateWindow("U11116037 鄭允揚");
    glClearColor(background, background, background, 1.0f);

    init();

    glutDisplayFunc(Display);
    glutReshapeFunc(Reshape);

    glutMouseFunc(Mouse);
    glutMotionFunc(MouseMoving);
    glutTimerFunc(timer_interval, update, 0);
    int menumain = glutCreateMenu(Menu);
    int menusub = glutCreateMenu(Menu);

    glutSetMenu(menumain);
    glutAddMenuEntry("Exit", EXITMENU);



    glutSetMenu(menumain);
    glutAttachMenu(GLUT_RIGHT_BUTTON);

#ifdef _MSC_VER
    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
#else
    glutInitDisplayMode(GLUT_3_2_CORE_PROFILE | GLUT_RGBA |
        GLUT_DOUBLE | GLUT_DEPTH);
#endif

    glutMainLoop();

    return 0;
}


void Display() {
    width = glutGet(GLUT_WINDOW_WIDTH);
    height = glutGet(GLUT_WINDOW_HEIGHT);
    aspect = (GLfloat)width / (GLfloat)height;

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glClearColor(background, background, background, 1.0f);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60.0f, aspect, 0.1f, 20.0f);
    glMatrixMode(GL_MODELVIEW);

    glLoadIdentity();
    glViewport(0, 0, width, height);
    gluLookAt(5.0, 5.0, 5.0,
        0.0, 0.0, 0.0,
        0.0, 1.0, 0.0);
    glCallList(WORLD_AXES);
    // 畫太陽
    glPushMatrix();
    glColor3f(1.0, 0.0, 0.0);
    glRotatef(0.0, 0.0, 1.0, 0.0);
    glTranslatef(0.0, 0.0, 0.0);
    glutSolidSphere(0.7, 20, 16);
    glPopMatrix();


    // 畫軌道
    drawOrbit(mercury);
    drawOrbit(venus);
    drawOrbit(earth);
    drawOrbit(mars);

    // 畫行星
    glColor3f(1.0, 1.0, 1.0);
    drawPlanet(mercury);
    glColor3f(1.0, 1.0, 0.0);
    drawPlanet(venus);
    glColor3f(0.0, 0.1, 1.0);
    drawPlanet(earth);
    glColor3f(1.0, 0.5, 0.0);
    drawPlanet(mars);

    glutSwapBuffers();
}

void Reshape(int width, int height) {
    aspect = width * 1.0f / height;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glViewport(0, 0, width, height);

    gluPerspective(60.0f, aspect, 0.1f, 10.0f);
}

void Menu(int id) {
     if (id == EXITMENU) {
        exit(0);
    }
    glutPostRedisplay();
}


void Mouse(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        oldback = background;
        clickx = x;
    }
}

void MouseMoving(int x, int y) {
    background = (x - clickx) * 0.005f + oldback;
    if (background >= 1.0f) {
        background = 1.0f;
    }
    else if (background <= 0.0f) {
        background = 0.0f;
    }
}

void init(void) {

    glEnable(GL_DEPTH_TEST);
    glClearColor(0.2, 0.2, 0.2, 0.0);

    glNewList(WORLD_AXES, GL_COMPILE);
    glBegin(GL_LINES);
    glColor3f(1.0, 0.0, 0.0);
    glVertex3f(0.0, 0.0, 0.0);
    glVertex3f(100, 0.0, 0.0);
    glColor3f(0.0, 1.0, 0.0);
    glVertex3f(0.0, 0.0, 0.0);
    glVertex3f(0.0, 100, 0.0);
    glColor3f(0.0, 0.0, 1.0);
    glVertex3f(0.0, 0.0, 0.0);
    glVertex3f(0.0, 0.0, 100);
    glEnd();
    glEndList();

}