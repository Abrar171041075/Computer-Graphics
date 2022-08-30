#include<windows.h>
#include<GL/glut.h>
#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#define PI 3.141592654
int window_width = 500, window_height=500;

void init()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(0, 0, 0, 0.0);
    glPointSize(1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, window_width, 0, window_height);
}

bool is_same_color(GLfloat color1[3],GLfloat color2[3])
{
    float threshold = 0.001;
    if(abs(color1[0]-color2[0])<threshold && abs(color1[1]-color2[1])<threshold && abs(color1[2]-color2[2])<threshold)
    {
        return true;
    }
    else
    {
        return false;
    }
}
void set_pixel_color(int x, int y, GLfloat color[4])
{
    glBegin(GL_POINTS);
    glColor3f(color[0],color[1],color[2]);
    glVertex2d(x,y);
    glEnd();

    glFlush();
}
void FloodFill(GLint x, GLint y,GLfloat fill_color[3],GLfloat original_color[3])
{
    GLfloat color[4];
    glReadPixels(x, y, 1, 1, GL_RGB, GL_FLOAT, &color);
    if(is_same_color(color,original_color))
    {
        glColor3f(1.0f, 0.0f, 0.0f);
        glBegin(GL_POINTS);
        glVertex2i(x, y);
        glEnd();
        glFlush();
        FloodFill(x+1, y,fill_color,original_color);
        FloodFill(x, y+1,fill_color,original_color);
        FloodFill(x-1, y,fill_color,original_color);
        FloodFill(x, y-1,fill_color,original_color);
    }
}
void draw_line(GLfloat x1,GLfloat y1,GLfloat x2,GLfloat y2)
{
    glColor3f(1,0,0);
    glBegin(GL_LINES);
    glVertex2f(x1,y1);
    glVertex2f(x2,y2);
    glEnd();

    glFlush();
}


void display(void)
{
    init();
    GLint x,y,len;
    x = 260;
    y = 210;
    len = 100;
//    draw_line(x,y,x+len,y);
//    draw_line(x,y,x,y+len);
//    draw_line(x,y+len,x+len,y+len);
//    draw_line(x+len,y,x+len,y+len);
    draw_line(150,100,300,300);
    draw_line(300,300,450,100);
    draw_line(150,100,450,100);
}

void on_mouse_click(int button, int state, int x, int y)
{
    GLfloat fill_color[3] = {1.0f,0.5f,0.0f};
    GLfloat original_color[3] = {0.0f,0.0f,0.0f};
    FloodFill(x,window_height-y,fill_color,original_color);
}
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(window_width, window_height);
    glutInitWindowPosition(200, 200);
    glutCreateWindow("Boundary Fill");
    init();
    glutDisplayFunc(display);
    glutMouseFunc(on_mouse_click);
    glutMainLoop();
    return 0;
}




