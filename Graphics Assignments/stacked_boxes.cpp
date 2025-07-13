
#include <glut.h>
#include <math.h>
#define GL_PI 3.1415f
static GLfloat xRot = 0.0f;
static GLfloat yRot = 0.0f;
GLfloat a[] = { -50,30,-50 },
b[] = { 50,30,-50 },
c[] = { 50,-30,-50 },
d[] = { -50,-30,-50 },
e[] = { 50,30,50 },
f[] = { 50,-30,50 },
g[] = { -50,-30,50 },
h[] = { -50,30,50 };
void draw()
{
glBegin(GL_QUADS);
glColor3f(0.25f, 0.25f, 0.25f);
glVertex3fv(a);
glVertex3fv(b);
glVertex3fv(c);
glVertex3fv(d);
glColor3f(0.1f, 0.1f, 0.1f);
glVertex3fv(b);
glVertex3fv(e);
glVertex3fv(f);
glVertex3fv(c);
glColor3f(0.15f, 0.15f, 0.15f);
glVertex3fv(a);
glVertex3fv(b);
glVertex3fv(e);
glVertex3fv(h);
glColor3f(0.25f, 0.25f, 0.25f);
glVertex3fv(e);
glVertex3fv(h);
glVertex3fv(g);
glVertex3fv(f);
glColor3f(0.1f, 0.1f, 0.1f);
glVertex3fv(a);
glVertex3fv(h);
glVertex3fv(g);
glVertex3fv(d);
glColor3f(0.15f, 0.15f, 0.15f);
glVertex3fv(g);
glVertex3fv(f);
glVertex3fv(c);
glVertex3fv(d);
glEnd();
}
void RenderScene(void) {
GLfloat x, y, z;
glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
glEnable(GL_DEPTH_TEST);
glPushMatrix();
glRotatef(15, 1.0f, 0.0f, 0.0f);
glRotatef(-20, 0.0f, 1.0f, 0.0f);
glRotatef(-15, 0.0f, 0.0f, 1.0f);
glRotatef(xRot, 1.0f, 0.0f, 0.0f);
glRotatef(yRot, 0.0f, 1.0f, 0.0f);
for (int i = 0; i <20; i++)
{
glTranslatef(0, 54, 0);
glScalef(0.8, 0.8, 0.8);
draw();
}
glPopMatrix();
glutSwapBuffers();
}
void SetupRC() {
glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
glShadeModel(GL_FLAT);
}
void ChangeSize(int w, int h) {
GLfloat nRange = 250.0;
if (h == 0) h = 1;
glViewport(0, 0, w, h);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
if (w <= h)
glOrtho(-nRange, nRange, -15 * h / w, nRange*h / w, -nRange, nRange);
else
glOrtho(-nRange*w / h, nRange*w / h, -15, nRange, -nRange, nRange);
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
glutCreateWindow("9");
glutInitWindowSize(500.0, 500.0);
glutReshapeFunc(ChangeSize);
glutSpecialFunc(SpecialKeys);
glutDisplayFunc(RenderScene);
SetupRC();
glutMainLoop();
return 0;
}