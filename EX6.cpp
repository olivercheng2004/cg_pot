#include <stdio.h>
#include "Include/FreeGLUT/freeglut.h"
#include "Include/FreeGLUT/glui.h"

#define WORLD_AXES 10
#define LOCAL_AXES 1
#define EXITMENU 0
#define SIZE1 10
#define SIZE2 15
#define SIZE3 20
#define Red 'R'
#define Green 'G'
#define Blue 'B'
#define X "X"
#define Y "Y"
#define Z "Z"

#define Translation_X_Button "TransXButton"
#define tXButtonID 0
#define Translation_Y_Button "TransYButton"
#define tYButtonID 1
#define Translation_Z_Button "TransZButton"
#define tZButtonID 2
#define TResetButtonID 3

#define Scaling_X_Button "ScalXButton"
#define sXButtonID 10
#define Scaling_Y_Button "ScalYButton"
#define sYButtonID 11
#define Scaling_Z_Button "ScalZButton"
#define sZButtonID 12
#define scalUniformID 13
#define SResetButtonID 14

#define Rotation_Button 20
#define RResetButtonID 21

#define Rotation_ButtonX 40
#define Rotation_ButtonY 41
#define Rotation_ButtonZ 42

#define light_x_check 0
#define light_direct_x_check 1
#define light_spot_x_check 2
#define diffuse_x_Red 3
#define diffuse_x_Green 4
#define diffuse_x_Blue 5
#define specular_x_Red 6
#define specular_x_Green 7
#define specular_x_Blue 8
#define light_x_resetID 9
//Light_X
#define light_y_check 10
#define light_direct_y_check 11
#define light_spot_y_check 12
#define diffuse_y_Red 13
#define diffuse_y_Green 14
#define diffuse_y_Blue 15
#define specular_y_Red 16
#define specular_y_Green 17
#define specular_y_Blue 18
#define light_y_resetID 19
//Light_Y
#define light_z_check 20
#define light_direct_z_check 21
#define light_spot_z_check 22
#define diffuse_z_Red 23
#define diffuse_z_Green 24
#define diffuse_z_Blue 25
#define specular_z_Red 26
#define specular_z_Green 27
#define specular_z_Blue 28
#define light_z_resetID 29
//Light_Z
#define animatonID 0
#define materialID 1
#define emissionID 2
#define viewID 3
#define shadeID 4
#define objectID 5
#define materiaID 6
#define Shininess 7
#define ShineCheck 8


GLuint window;
int width = 1200;
int height = 650;
GLfloat teapotX = 0.0f;
GLfloat teapotY = 0.0f;
GLfloat teapotZ = 0.0f;
GLfloat scaleX = 1.0f;
GLfloat scaleY = 1.0f;
GLfloat scaleZ = 1.0f;
GLfloat aspect = 1;
GLfloat teapotsize = 1.0f;
GLclampf background = 0;
GLclampf oldback = 0;
unsigned int timer_interval = 32;
int clickx = 0;
char myColor = ' ';
GLfloat rotateAngle = 0;
GLfloat rotateSpeed = 0;
int matid = 2;

int main_window = 0;
GLUI* glui_subwindow;
int scalemode = 0;
int scalemode1 = 1;

GLfloat global_ambient[] = { 0.2f,  0.2f,  0.2f, 1.0f };
GLfloat ambient_teapot[] = { 0.23125f,  0.23125f,  0.23125f, 1.0f };
GLfloat diffuse_teapot[] = { 0.2775f,  0.2775f,  0.2775f, 1.0f };
GLfloat specular_teapot[] = { 0.773911f,  0.773911f,  0.773911f, 1.0f };
GLfloat emission_teapot[] = { 0.0f,  0.0f,  0.0f, 1.0f };
GLfloat shininess;

int light_x = 0;
int light_direct_x = 0;
int light_spot_x = 0;
int openx = 0;
GLUI_Spinner* diffuse_x_R;
GLUI_Spinner* diffuse_x_G;
GLUI_Spinner* diffuse_x_B;
GLUI_Spinner* specular_x_R;
GLUI_Spinner* specular_x_G;
GLUI_Spinner* specular_x_B;
GLfloat light0_ambient[] = { 0.2f,  0.2f,  0.2f, 1.0f };
GLfloat light0_diffuse[] = { 0.5f,  0.5f,  0.5f, 1.0f };
GLfloat light0_specular[] = { 0.5f,  0.3f,  0.2f, 1.0f };
GLfloat light0_position[] = { 4.0f,  0.0f,  0.0f, 0.0f };
GLfloat light0_dir[] = { -1.0f,  0.0f,  0.0f, };
GLfloat light0_dir_reset[] = { -1.0f,  0.0f,  0.0f, };
//LIght_X
int light_y = 0;
int light_direct_y = 0;
int light_spot_y = 0;
int openy = 0;
GLUI_Spinner* diffuse_y_R;
GLUI_Spinner* diffuse_y_G;
GLUI_Spinner* diffuse_y_B;
GLUI_Spinner* specular_y_R;
GLUI_Spinner* specular_y_G;
GLUI_Spinner* specular_y_B;
GLfloat light1_ambient[] = { 0.2f,  0.2f,  0.2f, 1.0f };
GLfloat light1_diffuse[] = { 0.5f,  0.5f,  0.5f, 1.0f };
GLfloat light1_specular[] = { 0.5f,  0.3f,  0.2f, 1.0f };
GLfloat light1_position[] = { 0.0f,  4.0f,  0.0f, 0.0f };
GLfloat light1_dir[] = { 0.0f,  -1.0f,  0.0f, };
GLfloat light1_dir_reset[] = { 0.0f,  -1.0f,  0.0f, };
//Light_Y
int light_z = 0;
int light_direct_z = 0;
int light_spot_z = 0;
int openz = 0;
GLUI_Spinner* diffuse_z_R;
GLUI_Spinner* diffuse_z_G;
GLUI_Spinner* diffuse_z_B;
GLUI_Spinner* specular_z_R;
GLUI_Spinner* specular_z_G;
GLUI_Spinner* specular_z_B;
GLfloat light2_ambient[] = { 0.2f,  0.2f,  0.2f, 1.0f };
GLfloat light2_diffuse[] = { 0.5f,  0.5f,  0.5f, 1.0f };
GLfloat light2_specular[] = { 0.5f,  0.3f,  0.2f, 1.0f };
GLfloat light2_position[] = { 0.0f,  0.0f,  4.0f, 0.0f };
GLfloat light2_dir[] = { 0.0f,  0.0f,  -1.0f, };
GLfloat light2_dir_reset[] = { 0.0f,  0.0f,  -1.0f, };
//Light_Z

GLUI_Translation* tranX;
GLUI_Translation* tranY;
GLUI_Translation* tranZ;
GLUI_Translation* ScalX;
GLUI_Translation* ScalY;
GLUI_Translation* ScalZ;
GLUI_Button* resetrot;
GLUI_Rotation* rotation;

GLUI_Rollout* light_0;
GLUI_Button* light_x_rotation_reset;
GLUI_Rotation* light_x_rotation;
GLUI_Rollout* light_1;
GLUI_Button* light_y_rotation_reset;
GLUI_Rotation* light_y_rotation;
GLUI_Rollout* light_2;
GLUI_Button* light_z_rotation_reset;
GLUI_Rotation* light_z_rotation;

float rotatearray[16] = { 1.0,0.0,0.0,0.0,
                        0.0,1.0,0.0,0.0,
                        0.0,0.0,1.0,0.0,
                        0.0,0.0,0.0,1.0 };
float light_x_array[16] = { 1.0,0.0,0.0,0.0,
                        0.0,1.0,0.0,0.0,
                        0.0,0.0,1.0,0.0,
                        0.0,0.0,0.0,1.0 };
float light_y_array[16] = { 1.0,0.0,0.0,0.0,
                        0.0,1.0,0.0,0.0,
                        0.0,0.0,1.0,0.0,
                        0.0,0.0,0.0,1.0 };
float light_z_array[16] = { 1.0,0.0,0.0,0.0,
                        0.0,1.0,0.0,0.0,
                        0.0,0.0,1.0,0.0,
                        0.0,0.0,0.0,1.0 };


float resetarray[16] = { 1.0,0.0,0.0,0.0,
                        0.0,1.0,0.0,0.0,
                        0.0,0.0,1.0,0.0,
                        0.0,0.0,0.0,1.0 };
float oldscalx = 1.0f;
float oldscaly = 1.0f;
float oldscalz = 1.0f;
float newscalx = 1.0f;
float newscaly = 1.0f;
float newscalz = 1.0f;

int animation = 0;
int material1 = 0;
int emission = 0;
int view = 1;
int shade = 2;
int object = 0;
int material2 = 0;
int shine = 0;

int color_material = 0;

GLUI_RadioGroup* Material;
GLUI_Spinner* shiness;
#define COLORCUBE  2

GLfloat vertices[][3] = { {-1.0,-1.0,-1.0},{1.0,-1.0,-1.0},
    {1.0,1.0,-1.0},{-1.0,1.0,-1.0},{-1.0,-1.0,1.0},
    {1.0,-1.0,1.0},{1.0,1.0,1.0},{-1.0,1.0,1.0} };

GLfloat colors[][3] = { {0.0,0.0,0.0},{1.0,0.0,0.0},
    {1.0,1.0,0.0},{0.0,1.0,0.0},{0.0,0.0,1.0},
    {1.0,0.0,1.0},{1.0,1.0,1.0},{0.0,1.0,1.0} };

void Menu(int);
void Keyboard(unsigned char, int, int);
void SpecialKeys(int, int, int);
void Mouse(int, int, int, int);
void MouseMoving(int, int);
GLclampf clamp(GLclampf, GLfloat, GLfloat);
void Timer(int);

void Display();
void Reshape(int, int);
void init();
void light_UI();
void Transformation();
void Shading_Material_UI();
void Light();
void Transformation_callback(int);
void Other_callback(int);
void lightcontrol_x(int);
void lightcontrol_y(int);
void lightcontrol_z(int);
void polygon(int, int, int, int);

int main(int argc, char* argv[]) {
    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
    glutInit(&argc, argv);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(width, height);

    main_window = glutCreateWindow("U11116037 鄭允揚");

    glui_subwindow = GLUI_Master.create_glui_subwindow(main_window, GLUI_SUBWINDOW_RIGHT);
    glui_subwindow->set_main_gfx_window(main_window);

    Transformation();
    Shading_Material_UI();
    light_UI();
    init();

    glClearColor(background, background, background, 1.0f);

    GLUI_Master.set_glutDisplayFunc(Display);
    GLUI_Master.set_glutReshapeFunc(Reshape);
    GLUI_Master.set_glutKeyboardFunc(Keyboard);
    GLUI_Master.set_glutSpecialFunc(SpecialKeys);
    GLUI_Master.set_glutMouseFunc(Mouse);
    glutMotionFunc(MouseMoving);
    GLUI_Master.set_glutTimerFunc(timer_interval, Timer, 0);
    int menumain = glutCreateMenu(Menu);
    int menusub = glutCreateMenu(Menu);

    glutSetMenu(menumain);
    glutAddSubMenu("Teapot size", menusub);
    glutAddMenuEntry("Exit", EXITMENU);

    glutSetMenu(menusub);
    glutAddMenuEntry("1.0", SIZE1);
    glutAddMenuEntry("1.5", SIZE2);
    glutAddMenuEntry("2.0", SIZE3);

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

    glEnable(GL_LIGHTING);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    if (view==0) {
        glOrtho(-10.0, 10.0, -10.0, 10.0, -10.0, 10.0);
    }
    else if (view==1) {
        gluPerspective(60.0f, aspect, 0.1f, 10.0f);
    }
    glMatrixMode(GL_MODELVIEW);

    glLoadIdentity();

    glDisable(GL_LIGHTING);
    //glViewport(0, 0, width, height);      //茶壺在螢幕正中央的元凶
    gluLookAt(4.0, 2.0, 4.0,
        0.0, 0.0, 0.0,
        0.0, 1.0, 0.0);
    glCallList(WORLD_AXES);
    glColor3b(125, 0, 0);
    Light();
    glTranslatef(teapotX, teapotY, teapotZ);
    glRotatef(rotateAngle, 0.0f, 1.0f, 0.0f);
    glMultMatrixf(rotatearray);
    glCallList(LOCAL_AXES);
    glScalef(scaleX, scaleY, scaleZ);
    glEnable(GL_LIGHTING);

    if (myColor == Red) {
        glColor3b(125, 0, 0);
    }
    else if (myColor == Green) {
        glColor3b(0, 125, 0);
    }
    else if (myColor == Blue) {
        glColor3b(0, 0, 125);
    }

    if (shade == 0) {               //Wire shading
        glPolygonMode(GL_FRONT, GL_LINE);
        glPolygonMode(GL_BACK, GL_LINE);
    }
    else if (shade == 1) {          //Flat shading
        glPolygonMode(GL_FRONT, GL_FILL);
        glPolygonMode(GL_BACK, GL_FILL);
        glShadeModel(GL_FLAT);

    }
    else if (shade == 2) {          //Smooth shading
        glPolygonMode(GL_FRONT, GL_FILL);
        glPolygonMode(GL_BACK, GL_FILL);
        glShadeModel(GL_SMOOTH);
    }
    if (color_material == 1) {
        glEnable(GL_COLOR_MATERIAL);
    }
    else if (color_material == 0 && myColor == Red) {
        glDisable(GL_COLOR_MATERIAL);
    }
    else if (color_material == 0 && myColor == Green) {
        glDisable(GL_COLOR_MATERIAL);
    }
    else if (color_material == 0 && myColor == Blue) {
        glDisable(GL_COLOR_MATERIAL);
    }

    if (object == 0) {                  //Teapot
        glutSolidTeapot(teapotsize);
    }
    else if (object == 1) {             //ColorCube
        glCallList(COLORCUBE);
        glEnable(GL_COLOR_MATERIAL);
    }

    glutPostRedisplay();
    glutSwapBuffers();
}

void Reshape(int width, int height) {

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    int x = 0, y = 0;
    GLUI_Master.get_viewport_area(&x, &y, &width, &height);
    aspect = width * 1.0f / height;
    glui_subwindow->refresh();
    glViewport(x, y, width, height);
    gluPerspective(60.0f, aspect, 0.1f, 10.0f);
    glutSwapBuffers();
}

void Menu(int id) {
    if (id == SIZE1) {
        teapotsize = 1.0f;
    }
    else if (id == SIZE2) {
        teapotsize = 1.5f;
    }
    else if (id == SIZE3) {
        teapotsize = 2.0f;
    }
    else if (id == EXITMENU) {
        exit(0);
    }

    glutPostRedisplay();
}

void Timer(int val) {
    glutPostRedisplay();
    glutTimerFunc(timer_interval, Timer, val);
    rotateAngle += rotateSpeed * timer_interval * 0.001;
}

void Keyboard(unsigned char key, int x, int y) {
    if (key == 'w' || key == 'W') {
        teapotY += 0.05f;
    }
    else if (key == 's' || key == 'S') {
        teapotY -= 0.05f;
    }
    else if (key == 'a' || key == 'A') {
        teapotX -= 0.05f;
    }
    else if (key == 'd' || key == 'D') {
        teapotX += 0.05f;
    }
    else if (key == 'q' || key == 'Q') {
        rotateSpeed -= 2.0f;
    }
    else if (key == 'e' || key == 'E') {
        rotateSpeed += 2.0f;
    }
    glutPostRedisplay();
}

void SpecialKeys(int key, int x, int y) {
    if (key == GLUT_KEY_F1) {
        if (color_material == 0) {
            color_material = 1;
        }
        else if (color_material == 1 && myColor == Red) {
            color_material = 0;
        }
        myColor = Red;
    }
    else if (key == GLUT_KEY_F2) {
        if (color_material == 0) {
            color_material = 1;
        }
        else if (color_material == 1 && myColor == Green) {
            color_material = 0;
        }
        myColor = Green;
    }
    else if (key == GLUT_KEY_F3) {
        if (color_material == 0) {
            color_material = 1;
        }
        else if (color_material == 1 && myColor == Blue) {
            color_material = 0;
        }
        myColor = Blue;
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

    glNewList(LOCAL_AXES, GL_COMPILE);
    glBegin(GL_LINES);
    glColor3f(1.0, 0.0, 0.0);
    glVertex3f(0.0, 0.0, 0.0);
    glVertex3f(2.0, 0.0, 0.0);
    glColor3f(0.0, 1.0, 0.0);
    glVertex3f(0.0, 0.0, 0.0);
    glVertex3f(0.0, 2.0, 0.0);
    glColor3f(0.0, 0.0, 1.0);
    glVertex3f(0.0, 0.0, 0.0);
    glVertex3f(0.0, 0.0, 2.0);
    glEnd();
    glEndList();

    glNewList(COLORCUBE, GL_COMPILE);   // color cube
    polygon(0, 3, 2, 1);
    polygon(2, 3, 7, 6);
    polygon(0, 4, 7, 3);
    polygon(1, 2, 6, 5);
    polygon(4, 5, 6, 7);
    polygon(0, 1, 5, 4);
    glEndList();
}

void Light() {
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, global_ambient);

    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambient_teapot);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diffuse_teapot);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, specular_teapot);
    glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION, emission_teapot);
    glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, shininess);

    glLightfv(GL_LIGHT0, GL_AMBIENT, light0_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light0_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light0_specular);
    glLightfv(GL_LIGHT0, GL_POSITION, light0_position);
    glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, light0_dir);
    glLightf(GL_LIGHT0, GL_SPOT_CUTOFF, 5.0f);
    //Light_X
    glLightfv(GL_LIGHT1, GL_AMBIENT, light1_ambient);
    glLightfv(GL_LIGHT1, GL_DIFFUSE, light1_diffuse);
    glLightfv(GL_LIGHT1, GL_SPECULAR, light1_specular);
    glLightfv(GL_LIGHT1, GL_POSITION, light1_position);
    glLightfv(GL_LIGHT1, GL_SPOT_DIRECTION, light1_dir);
    glLightf(GL_LIGHT1, GL_SPOT_CUTOFF, 5.0f);
    //Light_Y
    glLightfv(GL_LIGHT2, GL_AMBIENT, light2_ambient);
    glLightfv(GL_LIGHT2, GL_DIFFUSE, light2_diffuse);
    glLightfv(GL_LIGHT2, GL_SPECULAR, light2_specular);
    glLightfv(GL_LIGHT2, GL_POSITION, light2_position);
    glLightfv(GL_LIGHT2, GL_SPOT_DIRECTION, light2_dir);
    glLightf(GL_LIGHT2, GL_SPOT_CUTOFF, 5.0f);
    //Light_Z
}
void light_UI() {
    GLUI_Panel* light = glui_subwindow->add_panel("Lighting", GLUI_PANEL_EMBOSSED);
    GLUI_Panel* lightpanel = glui_subwindow->add_panel_to_panel(light, "TransArrow_Blank", GLUI_PANEL_RAISED);
    GLUI_Checkbox* light0 = glui_subwindow->add_checkbox_to_panel(lightpanel, "Light X", &light_x, light_x_check, lightcontrol_x);
    glui_subwindow->add_column_to_panel(lightpanel, false);
    GLUI_Checkbox* light1 = glui_subwindow->add_checkbox_to_panel(lightpanel, "Light Y", &light_y, light_y_check, lightcontrol_y);
    glui_subwindow->add_column_to_panel(lightpanel, false);
    GLUI_Checkbox* light2 = glui_subwindow->add_checkbox_to_panel(lightpanel, "Light Z", &light_z, light_z_check, lightcontrol_z);
    light_0 = glui_subwindow->add_rollout_to_panel(light, "Light X", openx);
    GLUI_Checkbox* direct_x = glui_subwindow->add_checkbox_to_panel(light_0, "Directional", &light_direct_x, light_direct_x_check, lightcontrol_x);
    GLUI_Checkbox* spot_x = glui_subwindow->add_checkbox_to_panel(light_0, "Spot", &light_spot_x, light_spot_x_check, lightcontrol_x);
    light_x_rotation = glui_subwindow->add_rotation_to_panel(light_0, "Rotate", light_x_array, Rotation_ButtonX, lightcontrol_x);
    light_x_rotation->get_float_array_val(light_x_array);
    light_x_rotation_reset = glui_subwindow->add_button_to_panel(light_0, "Reset", light_x_resetID, lightcontrol_x);

    glui_subwindow->add_column_to_panel(light_0, true);
    diffuse_x_R = glui_subwindow->add_spinner_to_panel(light_0, "Diffuse:Red", GLUI_SPINNER_FLOAT, &light0_diffuse[0], diffuse_x_Red, lightcontrol_x);
    diffuse_x_G = glui_subwindow->add_spinner_to_panel(light_0, "Diffuse:Green", GLUI_SPINNER_FLOAT, &light0_diffuse[1], diffuse_x_Green, lightcontrol_x);
    diffuse_x_B = glui_subwindow->add_spinner_to_panel(light_0, "Diffuse:Blue", GLUI_SPINNER_FLOAT, &light0_diffuse[2], diffuse_x_Blue, lightcontrol_x);
    specular_x_R = glui_subwindow->add_spinner_to_panel(light_0, "Diffuse:Red", GLUI_SPINNER_FLOAT, &light0_specular[0], specular_x_Red, lightcontrol_x);
    specular_x_G = glui_subwindow->add_spinner_to_panel(light_0, "Diffuse:Green", GLUI_SPINNER_FLOAT, &light0_specular[1], specular_x_Green, lightcontrol_x);
    specular_x_B = glui_subwindow->add_spinner_to_panel(light_0, "Diffuse:Blue", GLUI_SPINNER_FLOAT, &light0_specular[2], specular_x_Blue, lightcontrol_x);
    diffuse_x_R->set_float_limits(0.0f, 1.0f, GLUI_LIMIT_CLAMP);
    diffuse_x_G->set_float_limits(0.0f, 1.0f, GLUI_LIMIT_CLAMP);
    diffuse_x_B->set_float_limits(0.0f, 1.0f, GLUI_LIMIT_CLAMP);
    specular_x_R->set_float_limits(0.0f, 1.0f, GLUI_LIMIT_CLAMP);
    specular_x_G->set_float_limits(0.0f, 1.0f, GLUI_LIMIT_CLAMP);
    specular_x_B->set_float_limits(0.0f, 1.0f, GLUI_LIMIT_CLAMP);

    light_0->disable();
    light_x_rotation->disable();
    //Light_X
    light_1 = glui_subwindow->add_rollout_to_panel(light, "Light Y", openy);
    GLUI_Checkbox* direct_y = glui_subwindow->add_checkbox_to_panel(light_1, "Directional", &light_direct_y, light_direct_y_check, lightcontrol_y);
    GLUI_Checkbox* spot_y = glui_subwindow->add_checkbox_to_panel(light_1, "Spot", &light_spot_y, light_spot_y_check, lightcontrol_y);
    light_y_rotation = glui_subwindow->add_rotation_to_panel(light_1, "Rotate", light_y_array, Rotation_ButtonY, lightcontrol_y);
    light_y_rotation->get_float_array_val(light_y_array);
    light_y_rotation_reset = glui_subwindow->add_button_to_panel(light_1, "Reset", light_y_resetID, lightcontrol_y);

    glui_subwindow->add_column_to_panel(light_1, true);
    diffuse_y_R = glui_subwindow->add_spinner_to_panel(light_1, "Diffuse:Red", GLUI_SPINNER_FLOAT, &light1_diffuse[0], diffuse_y_Red, lightcontrol_y);
    diffuse_y_G = glui_subwindow->add_spinner_to_panel(light_1, "Diffuse:Green", GLUI_SPINNER_FLOAT, &light1_diffuse[1], diffuse_y_Green, lightcontrol_y);
    diffuse_y_B = glui_subwindow->add_spinner_to_panel(light_1, "Diffuse:Blue", GLUI_SPINNER_FLOAT, &light1_diffuse[2], diffuse_y_Blue, lightcontrol_y);
    specular_y_R = glui_subwindow->add_spinner_to_panel(light_1, "Diffuse:Red", GLUI_SPINNER_FLOAT, &light1_specular[0], specular_y_Red, lightcontrol_y);
    specular_y_G = glui_subwindow->add_spinner_to_panel(light_1, "Diffuse:Green", GLUI_SPINNER_FLOAT, &light1_specular[1], specular_y_Green, lightcontrol_y);
    specular_y_B = glui_subwindow->add_spinner_to_panel(light_1, "Diffuse:Blue", GLUI_SPINNER_FLOAT, &light1_specular[2], specular_y_Blue, lightcontrol_y);
    diffuse_y_R->set_float_limits(0.0f, 1.0f, GLUI_LIMIT_CLAMP);
    diffuse_y_G->set_float_limits(0.0f, 1.0f, GLUI_LIMIT_CLAMP);
    diffuse_y_B->set_float_limits(0.0f, 1.0f, GLUI_LIMIT_CLAMP);
    specular_y_R->set_float_limits(0.0f, 1.0f, GLUI_LIMIT_CLAMP);
    specular_y_G->set_float_limits(0.0f, 1.0f, GLUI_LIMIT_CLAMP);
    specular_y_B->set_float_limits(0.0f, 1.0f, GLUI_LIMIT_CLAMP);

    light_1->disable();
    light_y_rotation->disable();
    //Light_Y
    light_2 = glui_subwindow->add_rollout_to_panel(light, "Light Z", openz);
    GLUI_Checkbox* direct_z = glui_subwindow->add_checkbox_to_panel(light_2, "Directional", &light_direct_z, light_direct_z_check, lightcontrol_z);
    GLUI_Checkbox* spot_z = glui_subwindow->add_checkbox_to_panel(light_2, "Spot", &light_spot_z, light_spot_z_check, lightcontrol_z);
    light_z_rotation = glui_subwindow->add_rotation_to_panel(light_2, "Rotate", light_z_array, Rotation_ButtonZ, lightcontrol_z);
    light_z_rotation->get_float_array_val(light_x_array);
    light_z_rotation_reset = glui_subwindow->add_button_to_panel(light_2, "Reset", light_z_resetID, lightcontrol_z);

    glui_subwindow->add_column_to_panel(light_2, true);
    diffuse_z_R = glui_subwindow->add_spinner_to_panel(light_2, "Diffuse:Red", GLUI_SPINNER_FLOAT, &light2_diffuse[0], diffuse_z_Red, lightcontrol_z);
    diffuse_z_G = glui_subwindow->add_spinner_to_panel(light_2, "Diffuse:Green", GLUI_SPINNER_FLOAT, &light2_diffuse[1], diffuse_z_Green, lightcontrol_z);
    diffuse_z_B = glui_subwindow->add_spinner_to_panel(light_2, "Diffuse:Blue", GLUI_SPINNER_FLOAT, &light2_diffuse[2], diffuse_z_Blue, lightcontrol_z);
    specular_z_R = glui_subwindow->add_spinner_to_panel(light_2, "Diffuse:Red", GLUI_SPINNER_FLOAT, &light2_specular[0], specular_z_Red, lightcontrol_z);
    specular_z_G = glui_subwindow->add_spinner_to_panel(light_2, "Diffuse:Green", GLUI_SPINNER_FLOAT, &light2_specular[1], specular_z_Green, lightcontrol_z);
    specular_z_B = glui_subwindow->add_spinner_to_panel(light_2, "Diffuse:Blue", GLUI_SPINNER_FLOAT, &light2_specular[2], specular_z_Blue, lightcontrol_z);
    diffuse_z_R->set_float_limits(0.0f, 1.0f, GLUI_LIMIT_CLAMP);
    diffuse_z_G->set_float_limits(0.0f, 1.0f, GLUI_LIMIT_CLAMP);
    diffuse_z_B->set_float_limits(0.0f, 1.0f, GLUI_LIMIT_CLAMP);
    specular_z_R->set_float_limits(0.0f, 1.0f, GLUI_LIMIT_CLAMP);
    specular_z_G->set_float_limits(0.0f, 1.0f, GLUI_LIMIT_CLAMP);
    specular_z_B->set_float_limits(0.0f, 1.0f, GLUI_LIMIT_CLAMP);

    light_2->disable();
    light_z_rotation->disable();
    //Light_Z


}

void Transformation() {

    GLUI_Panel* Transform = glui_subwindow->add_panel("Instance Transformation", GLUI_PANEL_EMBOSSED);
    //Instance Transformation的panel
    GLUI_Panel* Transformation_blank = glui_subwindow->add_panel_to_panel(Transform, "TransArrow_Blank", GLUI_PANEL_RAISED);
    //translation and rotate的panel
    GLUI_Panel* Trans = glui_subwindow->add_panel_to_panel(Transformation_blank, "Translation", GLUI_PANEL_EMBOSSED);
    GLUI_Panel* TransArrow = glui_subwindow->add_panel_to_panel(Trans, "TransArrow", GLUI_PANEL_RAISED);
    tranX = glui_subwindow->add_translation_to_panel(TransArrow, X, GLUI_TRANSLATION_X, &teapotX, tXButtonID, Transformation_callback);
    tranX->set_speed(0.05f);
    glui_subwindow->add_column_to_panel(TransArrow, false);
    tranY = glui_subwindow->add_translation_to_panel(TransArrow, Y, GLUI_TRANSLATION_Y, &teapotY, tYButtonID, Transformation_callback);
    tranY->set_speed(0.05f);
    glui_subwindow->add_column_to_panel(TransArrow, false);
    tranZ = glui_subwindow->add_translation_to_panel(TransArrow, Z, GLUI_TRANSLATION_Z, &teapotZ, tZButtonID, Transformation_callback);
    tranZ->set_speed(0.05f);
    glui_subwindow->add_separator_to_panel(Trans);
    GLUI_Button* resettra = glui_subwindow->add_button_to_panel(Trans, "Reset Translation", TResetButtonID, Transformation_callback);
    //Translation
    glui_subwindow->add_column_to_panel(Transformation_blank, false);
    //Blank between trnaslation and rotate
    GLUI_Panel* Rotate = glui_subwindow->add_panel_to_panel(Transformation_blank, "Rotation", GLUI_PANEL_EMBOSSED);
    rotation = glui_subwindow->add_rotation_to_panel(Rotate, "Rotation", rotatearray, Rotation_Button, Transformation_callback);
    rotation->get_float_array_val(rotatearray);
    resetrot = glui_subwindow->add_button_to_panel(Rotate, "Reset Rotation", RResetButtonID, Transformation_callback);
    //Rotation
    GLUI_Panel* Scaling_Other = glui_subwindow->add_panel_to_panel(Transform, "TransArrow_Blank", GLUI_PANEL_RAISED);
    //Scaling and other functon
    GLUI_Panel* Scal = glui_subwindow->add_panel_to_panel(Scaling_Other, "Scaling", GLUI_PANEL_EMBOSSED);
    GLUI_Panel* ScalArrow = glui_subwindow->add_panel_to_panel(Scal, "ScalArrow", GLUI_PANEL_RAISED);
    ScalX = glui_subwindow->add_translation_to_panel(ScalArrow, X, GLUI_TRANSLATION_X, &scaleX, sXButtonID, Transformation_callback);
    ScalX->set_speed(0.05f);
    glui_subwindow->add_column_to_panel(ScalArrow, false);
    ScalY = glui_subwindow->add_translation_to_panel(ScalArrow, Y, GLUI_TRANSLATION_Y, &scaleY, sYButtonID, Transformation_callback);
    ScalY->set_speed(0.05f);
    glui_subwindow->add_column_to_panel(ScalArrow, false);
    ScalZ = glui_subwindow->add_translation_to_panel(ScalArrow, Z, GLUI_TRANSLATION_Z, &scaleZ, sZButtonID, Transformation_callback);
    ScalZ->set_speed(0.05f);
    GLUI_Checkbox* Uni_scale = glui_subwindow->add_checkbox_to_panel(Scal, "Uniform Scaling", &scalemode, scalUniformID, Transformation_callback);
    GLUI_Button* resetsca = glui_subwindow->add_button_to_panel(Scal, "Reset Scaling", SResetButtonID, Transformation_callback);
    //Scaling
    glui_subwindow->add_column_to_panel(Scaling_Other, false);
    GLUI_Panel* Animation = glui_subwindow->add_panel_to_panel(Scaling_Other, "Animation", GLUI_PANEL_EMBOSSED);
    GLUI_Checkbox* animate = glui_subwindow->add_checkbox_to_panel(Animation, "Animate", &animation, animatonID, Other_callback);
    //Animation
    GLUI_Panel* Mater = glui_subwindow->add_panel_to_panel(Scaling_Other, "Material", GLUI_PANEL_EMBOSSED);
    GLUI_Checkbox* mater = glui_subwindow->add_checkbox_to_panel(Mater, "material", &material1, materialID, Other_callback);
    GLUI_Checkbox* emis = glui_subwindow->add_checkbox_to_panel(Mater, "emission", &emission, emissionID, Other_callback);
    //Material
    GLUI_Panel* Viewing = glui_subwindow->add_panel_to_panel(Scaling_Other, "Viewing", GLUI_PANEL_EMBOSSED);
    GLUI_RadioGroup* View = glui_subwindow->add_radiogroup_to_panel(Viewing, &view, viewID, Other_callback);
    GLUI_RadioButton* orth = glui_subwindow->add_radiobutton_to_group(View, "Ortho");
    GLUI_RadioButton* pers = glui_subwindow->add_radiobutton_to_group(View, "Perspec");
    //Viewing
}

void Transformation_callback(int callbackid) {

    if (callbackid == TResetButtonID) {
        tranX->set_x(0.0f);
        tranY->set_y(0.0f);
        tranZ->set_z(0.0f);
    }
    if (callbackid == SResetButtonID) {
        ScalX->set_x(1.0f);
        ScalY->set_y(1.0f);
        ScalZ->set_z(1.0f);
    }
    if (callbackid == RResetButtonID) {
        rotation->set_float_array_val(resetarray);
    }
    if (callbackid == sXButtonID) {
        newscalx = ScalX->get_x();
        if (newscalx == 0) {
            ScalX->set_x(1.0f);
        }
    }
    else if (callbackid == sYButtonID) {
        newscaly = ScalY->get_x();
        if (newscaly == 0) {
            ScalY->set_y(1.0f);
        }
    }
    else if (callbackid == sZButtonID) {
        newscalz = ScalZ->get_x();
        if (newscalz == 0) {
            ScalZ->set_z(1.0f);
        }
    }

    if (scalemode1 == 1) {
        if (callbackid == scalUniformID) {
            scalemode1 = 0;
            ScalY->disable();
            ScalZ->disable();
            oldscalx = ScalX->get_x();
            oldscaly = ScalY->get_y();
            oldscalz = ScalZ->get_z();
        }
    }
    else if (scalemode1 == 0) {

        if (callbackid == SResetButtonID) {
            oldscalx = ScalX->get_x();
            oldscaly = ScalY->get_y();
            oldscalz = ScalZ->get_z();
        }
        if (callbackid == sXButtonID) {
            newscalx = ScalX->get_x();
            if (newscalx == 0) {
                ScalX->set_x(1.0f);
                newscalx = ScalX->get_x();
            }
            ScalY->set_y(oldscaly * newscalx / oldscalx);
            ScalZ->set_z(oldscalz * newscalx / oldscalx);
        }
        else if (callbackid == scalUniformID) {
            scalemode1 = 1;
            ScalY->enable();
            ScalZ->enable();
        }
    }
}

void Shading_Material_UI() {
    GLUI_Panel* Shading_and_Materials = glui_subwindow->add_panel("Shading and Materials", GLUI_PANEL_EMBOSSED);
    //Shading_and_Materials的panel
    GLUI_Panel* Shading_type = glui_subwindow->add_panel_to_panel(Shading_and_Materials, "Shading_type", GLUI_PANEL_RAISED);
    //Shading_type的panel
    GLUI_Panel* Shading = glui_subwindow->add_panel_to_panel(Shading_type, "Shading type", GLUI_PANEL_EMBOSSED);
    GLUI_RadioGroup* Shade = glui_subwindow->add_radiogroup_to_panel(Shading, &shade, shadeID, Other_callback);
    GLUI_RadioButton* wire = glui_subwindow->add_radiobutton_to_group(Shade, "Wire");
    GLUI_RadioButton* flat = glui_subwindow->add_radiobutton_to_group(Shade, "Flat");
    GLUI_RadioButton* smooth = glui_subwindow->add_radiobutton_to_group(Shade, "Smooth");
    //Shading的panel
    glui_subwindow->add_column_to_panel(Shading_type, false);
    GLUI_Panel* Object_type = glui_subwindow->add_panel_to_panel(Shading_type, "Object", GLUI_PANEL_EMBOSSED);
    GLUI_RadioGroup* Object = glui_subwindow->add_radiogroup_to_panel(Object_type, &object, objectID, Other_callback);
    GLUI_RadioButton* teapot = glui_subwindow->add_radiobutton_to_group(Object, "Teapot");
    GLUI_RadioButton* cube = glui_subwindow->add_radiobutton_to_group(Object, "ColorCube");
    //Object的panel
    GLUI_Checkbox* shinecheck = glui_subwindow->add_checkbox_to_panel(Shading_and_Materials, "Adjust Shiness", &shine, ShineCheck, Other_callback);
    shiness = glui_subwindow->add_spinner_to_panel(Shading_and_Materials, "Shiness", GLUI_SPINNER_FLOAT, &shininess, Shininess, Other_callback);
    shiness->set_float_limits(0.0f, 128.0f, GLUI_LIMIT_CLAMP);
    glui_subwindow->add_column_to_panel(Shading_and_Materials, false);
    GLUI_Panel* Material_type = glui_subwindow->add_panel_to_panel(Shading_and_Materials, "Material type", GLUI_PANEL_EMBOSSED);
    Material = glui_subwindow->add_radiogroup_to_panel(Material_type, &material2, materiaID, Other_callback);
    GLUI_RadioButton* gold = glui_subwindow->add_radiobutton_to_group(Material, "Gold");
    GLUI_RadioButton* pewter = glui_subwindow->add_radiobutton_to_group(Material, "Pewter");
    GLUI_RadioButton* silver = glui_subwindow->add_radiobutton_to_group(Material, "Silver");
    GLUI_RadioButton* copper = glui_subwindow->add_radiobutton_to_group(Material, "Copper");
    GLUI_RadioButton* chrome = glui_subwindow->add_radiobutton_to_group(Material, "Chrome");
    //Material_type的panel
    Material->disable();
    shiness->disable();
}

void Other_callback(int callbackid) {
    if (material1==0) {             //材質模式關
        Material->disable();
        for (int i = 0; i < 3; i++) {
            ambient_teapot[i] = 0.23125f;
            diffuse_teapot[i] = 0.2775f;
            specular_teapot[i] = 0.773911f;
        }
    }
    else if (material1==1) {        //材質模式開
        Material->enable();
        if (material2 == 0) {             //材質Gold
            ambient_teapot[0] = 0.24725f;
            ambient_teapot[1] = 0.1995f;
            ambient_teapot[2] = 0.0745f;
            diffuse_teapot[0] = 0.75164f;
            diffuse_teapot[1] = 0.60648f;
            diffuse_teapot[2] = 0.22648f;
            specular_teapot[0] = 0.628281f;
            specular_teapot[1] = 0.555802f;
            specular_teapot[2] = 0.366065f;
        }
        else if (material2 == 1) {       //材質Pewter
            ambient_teapot[0] = 0.10588f;
            ambient_teapot[1] = 0.058824f;
            ambient_teapot[2] = 0.113725f;
            diffuse_teapot[0] = 0.427451f;
            diffuse_teapot[1] = 0.470588f;
            diffuse_teapot[2] = 0.541176f;
            specular_teapot[0] = 0.3333f;
            specular_teapot[1] = 0.3333f;
            specular_teapot[2] = 0.521569f;
        }
        else if (material2 == 2) {     //材質Silver
            for (int i = 0; i < 3; i++) {
                ambient_teapot[i] = 0.19225f;
                diffuse_teapot[i] = 0.50754f;
                specular_teapot[i] = 0.508273f;
            }
        }
        else if (material2 == 3) {     //材質Copper
            ambient_teapot[0] = 0.19125f;
            ambient_teapot[1] = 0.0735f;
            ambient_teapot[2] = 0.0225f;
            diffuse_teapot[0] = 0.7038f;
            diffuse_teapot[1] = 0.270048f;
            diffuse_teapot[2] = 0.0828f;
            specular_teapot[0] = 0.256777f;
            specular_teapot[1] = 0.137622f;
            specular_teapot[2] = 0.086014f;
        }
        else if (material2 == 4) {     //材質Chrome
            for (int i = 0; i < 3; i++) {
                ambient_teapot[i] = 0.25f;
                diffuse_teapot[i] = 0.4f;
                specular_teapot[i] = 0.774597f;
            }
        }
    }
    if (animation==0) {             //旋轉模式關
        rotateSpeed = 0.0f;
    }
    else if (animation==1) {        //旋轉模式開
        rotateSpeed = 20.0f;
    }
    if (emission == 0) {
        for (int i = 0; i < 3; i++) {
            emission_teapot[i] = 0.0f;
        }
    }
    else if (emission == 1) {
        for (int i = 0; i < 3; i++) {
            emission_teapot[i] = diffuse_teapot[i];
        }
    }
    if (shine==0) {
        shiness->disable();
    }
    else if (shine==1) {
        shiness->enable();
    }
}

void lightcontrol_x(int callbackid) {
    if (callbackid == Rotation_ButtonX) {
        /*for (int i = 0; i < 4; i++) {
            light0_dir[i] = 0;
            for (int j = 0; j < 4; j++) {
                light0_dir[i]+= light0_dir_reset[i]* light_x_array[4*i+j];
            }
        }*/
        light0_dir[1] = light_x_array[6];
        light0_dir[2] = light_x_array[8];
    }
    if (light_x == 1) {
        light_0->enable();
        glEnable(GL_LIGHT0);
        if (light_direct_x == 1) {
            light_x_rotation->enable();
        }
        else if (light_direct_x == 0) {
            light_x_rotation->disable();
        }
    }
    else if (light_x == 0) {
        light_0->disable();
        glDisable(GL_LIGHT0);
    }
    if (light_direct_x == 1) {
        light_x_rotation->enable();
        light0_position[3] = 1.0f;
        //light0_dir[3] = 1.0f;
        glLightf(GL_LIGHT0, GL_SPOT_EXPONENT, 10.0f);
        if (light_spot_x == 1) {
            light0_position[3] = 1.0f;
            //light0_dir[3] = 1.0f;
            glLightf(GL_LIGHT0, GL_SPOT_EXPONENT, 80.0f);
        }
    }
    else if (light_direct_x == 0) {
        light_x_rotation->disable();
        light0_position[3] = 0.0f;
        //light0_dir[3] = 0.0f;
        glLightf(GL_LIGHT0, GL_SPOT_EXPONENT, 0.0f);
        if (light_spot_x == 1) {
            light0_position[3] = 1.0f;
            //light0_dir[3] = 1.0f;
            glLightf(GL_LIGHT0, GL_SPOT_EXPONENT, 80.0f);
        }
    }
    if (light_spot_x == 1) {
        if (callbackid == light_spot_x_check) {
            light0_position[3] = 1.0f;
            //light0_dir[3] = 1.0f;
            glLightf(GL_LIGHT0, GL_SPOT_EXPONENT, 80.0f);
        }
    }
    else if (light_spot_x == 0) {
        if (callbackid == light_spot_x_check) {
            light0_position[3] = 0.0f;
            //light0_dir[3] = 0.0f;
            glLightf(GL_LIGHT0, GL_SPOT_EXPONENT, 0.0f);
        }
        if (light_direct_x == 1) {
            light_x_rotation->enable();
            light0_position[3] = 1.0f;
            //light0_dir[3] = 1.0f;
            glLightf(GL_LIGHT0, GL_SPOT_EXPONENT, 10.0f);
        }
    }

    if (callbackid == light_x_resetID) {
        light_x_rotation->set_float_array_val(resetarray);
        for (int i = 0; i < 3; i++) {
            light0_dir[i] = light0_dir_reset[i];
        }
    }
}
void lightcontrol_y(int callbackid) {
    if (callbackid == Rotation_ButtonY) {
        /*for (int i = 0; i < 4; i++) {
            light0_dir[i] = 0;
            for (int j = 0; j < 4; j++) {
                light0_dir[i]+= light0_dir_reset[i]* light_x_array[4*i+j];
            }
        }*/
        light1_dir[0] = light_y_array[6];
        light1_dir[2] = light_y_array[8];
    }
    if (light_y == 1) {
        light_1->enable();
        glEnable(GL_LIGHT1);
        if (light_direct_y == 1) {
            light_y_rotation->enable();
        }
        else if (light_direct_y == 0) {
            light_y_rotation->disable();
        }
    }
    else if (light_y == 0) {
        light_1->disable();
        glDisable(GL_LIGHT1);
    }
    if (light_direct_y == 1) {
        light_y_rotation->enable();
        light1_position[3] = 1.0f;
        //light0_dir[3] = 1.0f;
        glLightf(GL_LIGHT1, GL_SPOT_EXPONENT, 10.0f);
        if (light_spot_y == 1) {
            light1_position[3] = 1.0f;
            //light0_dir[3] = 1.0f;
            glLightf(GL_LIGHT1, GL_SPOT_EXPONENT, 80.0f);
        }
    }
    else if (light_direct_y == 0) {
        light_y_rotation->disable();
        light1_position[3] = 0.0f;
        //light0_dir[3] = 0.0f;
        glLightf(GL_LIGHT1, GL_SPOT_EXPONENT, 0.0f);
        if (light_spot_y == 1) {
            light1_position[3] = 1.0f;
            //light0_dir[3] = 1.0f;
            glLightf(GL_LIGHT1, GL_SPOT_EXPONENT, 80.0f);
        }
    }
    if (light_spot_y == 1) {
        if (callbackid == light_spot_y_check) {
            light1_position[3] = 1.0f;
            //light0_dir[3] = 1.0f;
            glLightf(GL_LIGHT1, GL_SPOT_EXPONENT, 80.0f);
        }
    }
    else if (light_spot_y == 0) {
        if (callbackid == light_spot_y_check) {
            light1_position[3] = 0.0f;
            //light0_dir[3] = 0.0f;
            glLightf(GL_LIGHT1, GL_SPOT_EXPONENT, 0.0f);
        }
        if (light_direct_y == 1) {
            light_y_rotation->enable();
            light1_position[3] = 1.0f;
            //light0_dir[3] = 1.0f;
            glLightf(GL_LIGHT1, GL_SPOT_EXPONENT, 10.0f);
        }
    }

    if (callbackid == light_y_resetID) {
        light_y_rotation->set_float_array_val(resetarray);
        for (int i = 0; i < 3; i++) {
            light1_dir[i] = light1_dir_reset[i];
        }
    }
}
void lightcontrol_z(int callbackid) {
    if (callbackid == Rotation_ButtonZ) {
        /*for (int i = 0; i < 4; i++) {
            light0_dir[i] = 0;
            for (int j = 0; j < 4; j++) {
                light0_dir[i]+= light0_dir_reset[i]* light_x_array[4*i+j];
            }
        }*/
        light2_dir[0] = light_z_array[8];
        light2_dir[1] = light_z_array[6];
    }
    if (light_z == 1) {
        light_2->enable();
        glEnable(GL_LIGHT2);
        if (light_direct_z == 1) {
            light_z_rotation->enable();
        }
        else if (light_direct_z == 0) {
            light_z_rotation->disable();
        }
    }
    else if (light_z == 0) {
        light_2->disable();
        glDisable(GL_LIGHT2);
    }
    if (light_direct_z == 1) {
        light_z_rotation->enable();
        light2_position[3] = 1.0f;
        //light0_dir[3] = 1.0f;
        glLightf(GL_LIGHT2, GL_SPOT_EXPONENT, 10.0f);
        if (light_spot_x == 1) {
            light2_position[3] = 1.0f;
            //light0_dir[3] = 1.0f;
            glLightf(GL_LIGHT2, GL_SPOT_EXPONENT, 80.0f);
        }
    }
    else if (light_direct_z == 0) {
        light_z_rotation->disable();
        light2_position[3] = 0.0f;
        //light0_dir[3] = 0.0f;
        glLightf(GL_LIGHT2, GL_SPOT_EXPONENT, 0.0f);
        if (light_spot_z == 1) {
            light2_position[3] = 1.0f;
            //light0_dir[3] = 1.0f;
            glLightf(GL_LIGHT2, GL_SPOT_EXPONENT, 80.0f);
        }
    }
    if (light_spot_z == 1) {
        if (callbackid == light_spot_z_check) {
            light2_position[3] = 1.0f;
            //light0_dir[3] = 1.0f;
            glLightf(GL_LIGHT2, GL_SPOT_EXPONENT, 80.0f);
        }
    }
    else if (light_spot_z == 0) {
        if (callbackid == light_spot_z_check) {
            light2_position[3] = 0.0f;
            //light0_dir[3] = 0.0f;
            glLightf(GL_LIGHT2, GL_SPOT_EXPONENT, 0.0f);
        }
        if (light_direct_z == 1) {
            light_z_rotation->enable();
            light2_position[3] = 1.0f;
            //light0_dir[3] = 1.0f;
            glLightf(GL_LIGHT2, GL_SPOT_EXPONENT, 10.0f);
        }
    }

    if (callbackid == light_z_resetID) {
        light_z_rotation->set_float_array_val(resetarray);
        for (int i = 0; i < 3; i++) {
            light2_dir[i] = light2_dir_reset[i];
        }
    }
}

void polygon(int a, int b, int c, int  d)
{
    /*draw a polygon via list of vertices*/
    glBegin(GL_POLYGON);
    glColor3fv(colors[a]);
    glVertex3fv(vertices[a]);
    glNormal3fv(vertices[a]);
    glColor3fv(colors[b]);
    glVertex3fv(vertices[b]);
    glNormal3fv(vertices[b]);
    glColor3fv(colors[c]);
    glVertex3fv(vertices[c]);
    glNormal3fv(vertices[c]);
    glColor3fv(colors[d]);
    glVertex3fv(vertices[d]);
    glNormal3fv(vertices[d]);
    glEnd();
}