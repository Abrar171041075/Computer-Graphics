#include<windows.h>
#include<GL/glut.h>
#include<stdlib.h>
#include<stdio.h>
#include<bits/stdc++.h>
int  width=500, height=500;
float  point_size = 3.0;
float x1,y1,x2,y2;

void input()
{
    printf("Enter the First Point : ");
    scanf("%f %f",&x1,&y1);
    printf("Enter the Second Point : ");
    scanf("%f %f",&x2,&y2);
}

void re_init()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(0,0,0,0);
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    float aspect = (float)width / (float)height;
    glOrtho(-aspect, aspect, -1, 1, -1, 1);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void draw_line(float xs,float ys, float xe, float ye)
{
    float dx = xe - xs;
    float dy = ye - ys;

    float x=xs;
    float y=ys;
    float m = dy/dx;
if(m<1)
{


    while(1)
    {
        glBegin(GL_POINTS);
        if( (ceil(y)-y)<=0.5)
        {
            glVertex2f(x,ceil(y));
        }
        else
        {
            glVertex2f(x,floor(y));
        }


        glEnd();

        if(x == xe)
        {
            break;
        }

        y=y+m;

        x++;
    }
    glFlush();
}
if(m>1)
{


    while(1)
    {
        glBegin(GL_POINTS);
        if( (ceil(x)-x)<=0.5)
        {
           glVertex2f(ceil(x),y);
        }
        else
        {
           glVertex2f(floor(x),y);
        }


        glEnd();
         if(y == ye)
         {

            break;
         }
        x=x+(1/m);
        y++;

    }
    glFlush();
}

if(m == 1){

    while(1)
    {
        glBegin(GL_POINTS);


           glVertex2f(x,y);




        glEnd();
         if(y == ye || x == xe)
         {

            break;
         }
        x++;
        y++;

    }
    glFlush();

}
}
void display(void)
{
    re_init();

    draw_line(x1,y1,x2,y2);

}

void init(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(0,0,0,0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-100,100,-100,100);
}
int main(int argc, char** argv)
{

    input();
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(width,height);
    glutInitWindowPosition(100,100);
    glutCreateWindow("DDA’s Line Algorithm");
    init();
    glEnable(GL_POINT_SMOOTH);
    glPointSize(point_size);
    glutDisplayFunc(display);
    glutMainLoop();


    return 0;
}

