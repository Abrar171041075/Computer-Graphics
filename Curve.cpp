#include<windows.h>
#include<GL/glut.h>
#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#define PI 3.14159

void C_curve(float x, float y, float len, float alpha,int n){

    if(n>0){
        len = len/sqrt(2.0);
        C_curve(x,y,len,alpha+(45*PI)/180,n-1);
        x = x + len*cos(alpha+(45*PI)/180);
        y = y + len*sin(alpha+(45*PI)/180);
        C_curve(x,y,len,alpha-(45*PI)/180,n-1);
    }
    else{
        glBegin(GL_LINES);
        glVertex2f(x,y);
        glVertex2f(x+len*cos(alpha),y+len*sin(alpha));
    }
    glEnd();
    glFlush();
}

void display(void){
//    int n;
//    scanf("%d", &n);
    C_curve(0,0,60,((90*PI)/180),10);
}

void init(void){
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(0,0,0,0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-100,100,-100,100);
}

int main(int argc, char** argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500,500);
    glutInitWindowPosition(100,100);
    glutCreateWindow("");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
