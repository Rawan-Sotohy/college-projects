#include <glut.h>
#include <math.h>

#define GL_PI 3.1415

GLfloat xRot = 45.0;
GLfloat yRot = 45.0;
GLfloat angle = 45;

void timer(int value) {
  glutPostRedisplay();
  glutTimerFunc(1, timer, 0);
}

void specialKeys(int key, int x, int y) {
  if (key == GLUT_KEY_UP)
    xRot -= 5.0;
  if (key == GLUT_KEY_DOWN)
    xRot += 5.0;
  if (key == GLUT_KEY_RIGHT)
    yRot += 5.0;
  if (key == GLUT_KEY_LEFT)
    yRot -= 5.0;
  if (xRot > 356.0)
    xRot = 0.0;
  if (xRot < -1.0)
    xRot = 355.0;
  if (yRot > 356)
    yRot = 0.0;
  if (yRot < -1)
    yRot = 355.0;

  glutPostRedisplay();
}



void setBG() {
  glClearColor(1, 1, 1, 1);
  glOrtho(-200, 200, -200, 200, 200, -200);
  glShadeModel(GL_FLAT);
}
void diamond()
{
  glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);
  glEnable(GL_DEPTH_TEST);
  glPushMatrix();
  glRotatef(angle, 1, 1, 1);
  //glRotatef(xRot, 1, 0, 0);
  //glRotatef(yRot, 0, 1, 0);

  glColor3f(0, 0.98, 0.89);
  glBegin(GL_TRIANGLE_FAN);
  glVertex3f(0, 100, 0);
  glVertex3f(100, 0, 0);
  glVertex3f(0, 0, 100);
  glColor3f(0, 0.9, 0.9);
  glVertex3f(-100, 0, 0);
  glColor3f(0, 1.2, 0.9);
  glVertex3f(0, 0, -100);
  glColor3f(0, 0.9, 1);
  glVertex3f(100, 0, 0);

  //glRotatef(60,0,1, 0);
  glEnd();
  glColor3f(0, 1, 1);
  glBegin(GL_TRIANGLE_FAN);
  glVertex3f(0, -100, 0);
  glVertex3f(100, 0, 0);
  glVertex3f(0, 0, 100);
  glColor3f(0, 0.95, 0.95);
  glVertex3f(-100, 0, 0);
  glColor3f(0, 0.85, 0.9);
  glVertex3f(0, 0, -100);
  glColor3f(0, 0.9, 0.85);
  glVertex3f(100, 0, 0);
  glEnd();

  glPopMatrix();

  glFlush();
  angle += 0.5;




}

int main(int argc, char* argv[]) {
  glutInit(&argc, argv);
  glutInitWindowSize(500, 500);
  glutCreateWindow("project");
  glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH | GLUT_DOUBLE);

  setBG();
  glutDisplayFunc(diamond);
  glutTimerFunc(0, timer, 0);
  //glutSpecialFunc(specialKeys);
  glutMainLoop();
  return 0;
}