
#include <glut.h>
#include <math.h>
#define GL_PI 3.1415f
static GLfloat xRot = 0.0f;
static GLfloat yRot = 0.0f;
void RenderScene(void) {
GLfloat x, y, z, angle, r;
glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
glEnable(GL_DEPTH_TEST);
glPushMatrix();
/*glRotatef(65.0, 1.0f, 0.0f, 0.0f);
glRotatef(15.0, 0.0f, 1.0f, 0.0f);*/
glRotatef(xRot, 1.0f, 0.0f, 0.0f);
glRotatef(yRot, 0.0f, 1.0f, 0.0f);
z = -60.0;
r = 65.0;
for (int i = 0; i < 6; i++)
{
glPushMatrix();
glBegin(GL_LINE_LOOP);
for (angle = 0.0f; angle <= (2.0f*GL_PI); angle += GL_PI / 20.0)
{
x = r*sin(angle);
y = r*cos(angle);
glVertex3f(x, y, z);
}
glEnd();
z += 10;
r -= 12;
glPopMatrix();
}
z = 0.0;
r = 5.0;
for (int i = 0; i < 6; i++)
{
glPushMatrix();
glBegin(GL_LINE_LOOP);
for (angle = 0.0f; angle <= (2.0f*GL_PI); angle += GL_PI / 20.0)
{
x = r*sin(angle);
y = r*cos(angle);
glVertex3f(x, y, z);
}
glEnd();
z += 10;
r += 12;
glPopMatrix();
}
glPopMatrix();
glutSwapBuffers();
}
void SetupRC() {
glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
glColor3f(0.0f, 0.0f, 0.0f);
}
void ChangeSize(int w, int h) {
GLfloat nRange = 100.0;
if (h == 0) h = 1;
glViewport(0, 0, w, h);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
if (w <= h)
glOrtho(-nRange, nRange, -nRange*h / w, nRange*h / w, -nRange,
nRange);
else
glOrtho(-nRange*w / h, nRange*w / h, -nRange, nRange, -nRange,
nRange);
glMatrixMode(GL_MODELVIEW);
glLoadIdentity();
}
void SpecialKeys(int key, int x, int y) {
if (key == GLUT_KEY_UP) xRot -= 5.0f;
if (key == GLUT_KEY_DOWN) xRot += 5.0f;
if (key == GLUT_KEY_LEFT) yRot -= 5.0f;
if (key == GLUT_KEY_RIGHT) yRot += 5.0f;
if (xRot > 356.0f) xRot = 0.0f;
if (xRot < -1.0f) xRot = 355.0f;
if (yRot > 356.0f) yRot = 0.0f;
if (yRot < -1.0f) yRot = 355.0f;
glutPostRedisplay();
}
int main(int argc, char* argv[])
{
glutInit(&argc, argv);
glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
glutCreateWindow("Points Example");
glutReshapeFunc(ChangeSize);
glutSpecialFunc(SpecialKeys);
glutDisplayFunc(RenderScene);
SetupRC();
glutMainLoop();
return 0;
}