#include<windows.h>
#include<GL/glut.h>
#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#define PI 3.14159


void Koch_curve(float x,float y,float len,float alpha,int n){
    glBegin(GL_LINES);
    if(n>0){
        len = len/3;
        Koch_curve(x,y,len,alpha,n-1);
        x = x + len*cos(alpha);
        y = y + len*sin(alpha);
        Koch_curve(x,y,len,alpha-(60 * PI)/ 180,n-1);
        x = x + len*cos(alpha-(60 * PI)/ 180);
        y = y + len*sin(alpha-(60 * PI)/ 180);
        Koch_curve(x,y,len,alpha+(60 * PI)/ 180,n-1);
        x = x + len*cos(alpha+(60 * PI)/ 180);
        y = y + len*sin(alpha+(60 * PI)/ 180);
        Koch_curve(x,y,len,alpha,n-1);
    }
    else{
        glVertex2f(x,y);
        glVertex2f(x+len*cos(alpha),y+len*sin(alpha));
    }
    glEnd();
    glFlush();
}

void display(void){
    Koch_curve(50,-50,100,((180 * PI)/180),8);
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
