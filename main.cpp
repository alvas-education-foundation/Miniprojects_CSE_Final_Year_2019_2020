#include<windows.h>
#include <stdio.h>
#include <GL/glut.h>
#include<math.h>
float b=0;
void display()
{
    b+=0.1;
    glLoadIdentity();
    glRotatef(120,1,0,0);
    glRotatef(b,0,0,1);
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    for(float x=-0.25,k=0.4;x<=0.25;x=x+0.25,k=k+0.2){
    for(float y=-0.25,l=0.4;y<=0.25;y=y+0.25,l=l+0.2){
    for(float z=0.25,m=0.4;z>=-0.25;z=z-0.25,m=m+0.2){
    glPushMatrix();
    glColor3f(k,l,m);
    glTranslatef(x,y,z);
    glutSolidCube(100);
    glPopMatrix();}}}
    glutSwapBuffers();
    glutPostRedisplay();
    glFlush();
}

void init(void)
{
   glClearColor(1,1,1,1);
   glOrtho(-700,700,-700,700,-700,700);
   glMatrixMode(GL_MODELVIEW);
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
}

int main()
{
    init();
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(600,600);
	glutCreateWindow("gasket");
	init();
	glutDisplayFunc(display);
	glutMainLoop();
}
