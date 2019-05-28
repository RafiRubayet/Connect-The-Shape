#include <bits/stdc++.h>
#include <GL/glut.h>
#include <stdlib.h>
using namespace std;

#define nl endl
#define pb push_back
#define ff first
#define ss second
#define mkp make_pair

#define mem(a,v) memset(a,v,sizeof(a))

int x[5], y[5], m = 0, prev_point, level = 1, cnt_edge = 0;
vector < int > clicked;
GLint v[20][2];
bool one = 1, kb = 0;
bool graph[100][100];

char ans[20][100];

stack < GLint > record_of_moves;

GLfloat color[20][3];

int edge[20]; /// num of edge at level x
int node[20]; /// num of node at level x

void display(void);
void init_solution()
{
    strcpy(ans[1], "Solution is: 1 2 3 1");
    strcpy(ans[2], "Solution is: 4 2 3 4 6 7 2 1 3 5 6");
    strcpy(ans[3], "Solution is: 6 7 8 6 2 3 4 5 1 2 5 7");
    strcpy(ans[4], "Solution is: 6 7 8 9 7 5 6 2 1 4 3 2 8");
}

void level_four()
{

    char lnum[80];
    strcpy(lnum,"Level 4");
    int len;
    len = strlen(lnum);

    glColor3f(0, 0 , 1);
    glRasterPos2i(290, 430);
    for(int i = 0; i < len; i++)
    {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, lnum[i]);
    }

    v[1][0] = 200, v[1][1] = 70, v[2][0] = 320, v[2][1] = 380, v[3][0] = 440, v[3][1] = 70;
    v[4][0] = 320, v[4][1] = 120, v[5][0] = 150, v[5][1] = 150, v[6][0] = 240, v[6][1] = 320;
    v[7][0] = 320, v[7][1] = 190, v[8][0] = 400, v[8][1] = 320, v[9][0] = 490, v[9][1] = 150;

    color[1][0] = 1.0, color[1][1] = 1.0, color[1][2] = 1.0;
    color[2][0] = 0.4, color[2][1] = 1.0, color[2][2] = 0.4;
    color[3][0] = 0.3, color[3][1] = 0.2, color[3][2] = 1.0;
    color[4][0] = 0.8, color[4][1] = 0.5, color[4][2] = 1.0;
    color[5][0] = 0.0, color[5][1] = 0.0, color[5][2] = 1.0;
    color[6][0] = 0.3, color[6][1] = 0.5, color[6][2] = 0.5;
    color[7][0] = 0.6, color[7][1] = 0.2, color[7][2] = 0.2;
    color[8][0] = 0.4, color[8][1] = 0.6, color[8][2] = 0.4;
    color[9][0] = 0.5, color[9][1] = 0.6, color[9][2] = 0.3;


    graph[1][2] = 1; graph[2][3] = 1; graph[3][4] = 1; graph[4][1] = 1; graph[6][7] = 1; graph[7][5] = 1;
    graph[5][6] = 1; graph[7][8] = 1; graph[8][9] = 1; graph[9][7] = 1; graph[6][2] = 1; graph[2][8] = 1;

    graph[2][1] = 1; graph[3][2] = 1; graph[4][3] = 1; graph[1][4] = 1; graph[7][6] = 1; graph[5][7] = 1;
    graph[6][5] = 1; graph[8][7] = 1; graph[9][8] = 1; graph[7][9] = 1; graph[2][6] = 1; graph[8][2] = 1;

    glPointSize(20.0);
    glBegin(GL_POINTS);
        glColor3fv(color[1]);
        glVertex2iv(v[1]);
        glColor3fv(color[2]);
        glVertex2iv(v[2]);
        glColor3fv(color[3]);
        glVertex2iv(v[3]);
        glColor3fv(color[4]);
        glVertex2iv(v[4]);
        glColor3fv(color[5]);
        glVertex2iv(v[5]);
        glColor3fv(color[6]);
        glVertex2iv(v[6]);
        glColor3fv(color[7]);
        glVertex2iv(v[7]);
        glColor3fv(color[8]);
        glVertex2iv(v[8]);
        glColor3fv(color[9]);
        glVertex2iv(v[9]);
    glEnd();


     /// labeling points
    glColor3f(0, 0 , 1);

    glRasterPos2i(170, 62);
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, '1');

    glRasterPos2i(340, 375);
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, '2');

    glRasterPos2i(460, 62);
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, '3');

    glRasterPos2i(315, 90);
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, '4');

    glRasterPos2i(120, 145);
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, '5');


    glRasterPos2i(210, 315);
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, '6');

    glRasterPos2i(315, 160);
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, '7');

    glRasterPos2i(420, 315);
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, '8');

    glRasterPos2i(510, 145);
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, '9');



    glLineWidth(5);
    glBegin(GL_LINES);
        glColor3fv(color[1]);
        glVertex2iv(v[1]);
        glColor3fv(color[2]);
        glVertex2iv(v[2]);

        glColor3fv(color[2]);
        glVertex2iv(v[2]);
        glColor3fv(color[3]);
        glVertex2iv(v[3]);

        glColor3fv(color[3]);
        glVertex2iv(v[3]);
        glColor3fv(color[4]);
        glVertex2iv(v[4]);

        glColor3fv(color[4]);
        glVertex2iv(v[4]);
        glColor3fv(color[1]);
        glVertex2iv(v[1]);

        glColor3fv(color[6]);
        glVertex2iv(v[6]);
        glColor3fv(color[7]);
        glVertex2iv(v[7]);

        glColor3fv(color[7]);
        glVertex2iv(v[7]);
        glColor3fv(color[5]);
        glVertex2iv(v[5]);

        glColor3fv(color[5]);
        glVertex2iv(v[5]);
        glColor3fv(color[6]);
        glVertex2iv(v[6]);

        glColor3fv(color[7]);
        glVertex2iv(v[7]);
        glColor3fv(color[8]);
        glVertex2iv(v[8]);

        glColor3fv(color[8]);
        glVertex2iv(v[8]);
        glColor3fv(color[9]);
        glVertex2iv(v[9]);

        glColor3fv(color[9]);
        glVertex2iv(v[9]);
        glColor3fv(color[7]);
        glVertex2iv(v[7]);

        glColor3fv(color[6]);
        glVertex2iv(v[6]);
        glColor3fv(color[2]);
        glVertex2iv(v[2]);

        glColor3fv(color[2]);
        glVertex2iv(v[2]);
        glColor3fv(color[8]);
        glVertex2iv(v[8]);
    glEnd();


}

void level_three()
{

    char lnum[80];
    strcpy(lnum,"Level 3");
    int len;
    len = strlen(lnum);

    glColor3f(0, 0 , 1);
    glRasterPos2i(280, 440);
    for(int i = 0; i < len; i++)
    {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, lnum[i]);
    }

    v[1][0] = 280, v[1][1] = 70, v[2][0] = 80, v[2][1] = 290, v[3][0] = 180, v[3][1] = 360;
    v[4][0] = 380, v[4][1] = 360, v[5][0] = 480, v[5][1] = 290, v[6][0] = 180, v[6][1] = 220;
    v[7][0] = 380, v[7][1] = 220, v[8][0] = 280, v[8][1] = 140;

    for(int i = 2; i <= 8; i++) v[i][1] += 30;
    for(int i = 1; i <= 8; i++) v[i][0] += 30;

    color[1][0] = 1.0, color[1][1] = 1.0, color[1][2] = 1.0;
    color[2][0] = 0.4, color[2][1] = 1.0, color[2][2] = 0.4;
    color[3][0] = 0.3, color[3][1] = 0.2, color[3][2] = 1.0;
    color[4][0] = 0.8, color[4][1] = 0.5, color[4][2] = 1.0;
    color[5][0] = 0.0, color[5][1] = 0.0, color[5][2] = 1.0;
    color[6][0] = 0.3, color[6][1] = 0.5, color[6][2] = 0.5;
    color[7][0] = 0.6, color[7][1] = 0.2, color[7][2] = 0.2;
    color[8][0] = 0.4, color[8][1] = 0.6, color[8][2] = 0.4;

    /// connectivity
    graph[1][2] = 1; graph[2][3] = 1; graph[3][4] = 1; graph[4][5] = 1; graph[5][1] = 1;
    graph[2][5] = 1; graph[2][6] = 1; graph[5][7] = 1; graph[6][7] = 1; graph[6][8] = 1; graph[7][8] = 1;

    graph[2][1] = 1; graph[3][2] = 1; graph[4][3] = 1; graph[5][4] = 1; graph[1][5] = 1;
    graph[5][2] = 1; graph[6][2] = 1; graph[7][5] = 1; graph[7][6] = 1; graph[8][6] = 1; graph[8][7] = 1;


    glPointSize(20.0);
    glBegin(GL_POINTS);
        glColor3fv(color[1]);
        glVertex2iv(v[1]);
        glColor3fv(color[2]);
        glVertex2iv(v[2]);
        glColor3fv(color[3]);
        glVertex2iv(v[3]);
        glColor3fv(color[4]);
        glVertex2iv(v[4]);
        glColor3fv(color[5]);
        glVertex2iv(v[5]);
        glColor3fv(color[6]);
        glVertex2iv(v[6]);
        glColor3fv(color[7]);
        glVertex2iv(v[7]);
        glColor3fv(color[8]);
        glVertex2iv(v[8]);
    glEnd();


     /// labeling points
    glColor3f(0, 0 , 1);

    glRasterPos2i(280, 60);
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, '1');

    glRasterPos2i(80, 315);
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, '2');

    glRasterPos2i(205, 355);
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, '3');

    glRasterPos2i(410, 355);
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, '4');

    glRasterPos2i(530, 315);
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, '5');


    glRasterPos2i(205, 220);
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, '6');

    glRasterPos2i(410, 220);
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, '7');

    glRasterPos2i(305, 140);
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, '8');


    glLineWidth(5);
    glBegin(GL_LINES);
        glColor3fv(color[1]);
        glVertex2iv(v[1]);
        glColor3fv(color[2]);
        glVertex2iv(v[2]);

        glColor3fv(color[2]);
        glVertex2iv(v[2]);
        glColor3fv(color[3]);
        glVertex2iv(v[3]);

        glColor3fv(color[3]);
        glVertex2iv(v[3]);
        glColor3fv(color[4]);
        glVertex2iv(v[4]);

        glColor3fv(color[4]);
        glVertex2iv(v[4]);
        glColor3fv(color[5]);
        glVertex2iv(v[5]);

        glColor3fv(color[5]);
        glVertex2iv(v[5]);
        glColor3fv(color[1]);
        glVertex2iv(v[1]);

        glColor3fv(color[2]);
        glVertex2iv(v[2]);
        glColor3fv(color[5]);
        glVertex2iv(v[5]);

        glColor3fv(color[5]);
        glVertex2iv(v[5]);
        glColor3fv(color[7]);
        glVertex2iv(v[7]);

        glColor3fv(color[2]);
        glVertex2iv(v[2]);
        glColor3fv(color[6]);
        glVertex2iv(v[6]);

        glColor3fv(color[6]);
        glVertex2iv(v[6]);
        glColor3fv(color[7]);
        glVertex2iv(v[7]);

        glColor3fv(color[6]);
        glVertex2iv(v[6]);
        glColor3fv(color[8]);
        glVertex2iv(v[8]);

        glColor3fv(color[7]);
        glVertex2iv(v[7]);
        glColor3fv(color[8]);
        glVertex2iv(v[8]);
    glEnd();

}


void level_two()
{

    char lnum[80];
    strcpy(lnum,"Level 2");
    int len;
    len = strlen(lnum);

    glColor3f(0, 0 , 1);
    glRasterPos2i(270, 420);
    for(int i = 0; i < len; i++)
    {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, lnum[i]);
    }

    v[1][0] = 180, v[1][1] = 100, v[2][0] = 460, v[2][1] = 100, v[3][0] = 180, v[3][1] = 250;
    v[4][0] = 460, v[4][1] = 250, v[5][0] = 230, v[5][1] = 350, v[6][0] = 510, v[6][1] = 350;
    v[7][0] = 510, v[7][1] = 150;

    color[1][0] = 0.8, color[1][1] = 0.0, color[1][2] = 1.0;
    color[2][0] = 0.0, color[2][1] = 1.0, color[2][2] = 0.0;
    color[3][0] = 0.0, color[3][1] = 0.0, color[3][2] = 1.0;
    color[4][0] = 0.8, color[4][1] = 0.5, color[4][2] = 1.7;
    color[5][0] = 0.5, color[5][1] = 0.5, color[5][2] = 0.7;
    color[6][0] = 0.3, color[6][1] = 0.5, color[6][2] = 0.5;
    color[7][0] = 1.0, color[7][1] = 0.2, color[7][2] = 1.0;

    /// connectivity
    graph[1][2] = 1; graph[2][4] = 1; graph[4][3] = 1; graph[3][1] = 1; graph[3][2] = 1;
    graph[3][5] = 1; graph[5][6] = 1; graph[6][4] = 1; graph[6][7] = 1; graph[2][7] = 1;

    graph[2][1] = 1; graph[4][2] = 1; graph[3][4] = 1; graph[1][3] = 1; graph[2][3] = 1;
    graph[5][3] = 1; graph[6][5] = 1; graph[4][6] = 1; graph[7][6] = 1; graph[7][2] = 1;

    glPointSize(20.0);
    glBegin(GL_POINTS);
        glColor3fv(color[1]);
        glVertex2iv(v[1]);
        glColor3fv(color[2]);
        glVertex2iv(v[2]);
        glColor3fv(color[3]);
        glVertex2iv(v[3]);
        glColor3fv(color[4]);
        glVertex2iv(v[4]);
        glColor3fv(color[5]);
        glVertex2iv(v[5]);
        glColor3fv(color[6]);
        glVertex2iv(v[6]);
        glColor3fv(color[7]);
        glVertex2iv(v[7]);
    glEnd();

    /// labeling points
    glColor3f(0, 0 , 1);

    glRasterPos2i(150, 92);
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, '1');

    glRasterPos2i(480, 92);
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, '2');

    glRasterPos2i(150, 242);
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, '3');

    glRasterPos2i(440, 265);
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, '4');

    glRasterPos2i(205, 355);
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, '5');

    glRasterPos2i(525, 350);
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, '6');

    glRasterPos2i(525, 143);
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, '7');


    glLineWidth(5);
    glBegin(GL_LINES);
        glColor3fv(color[1]);
        glVertex2iv(v[1]);
        glColor3fv(color[2]);
        glVertex2iv(v[2]);

        glColor3fv(color[2]);
        glVertex2iv(v[2]);
        glColor3fv(color[4]);
        glVertex2iv(v[4]);

        glColor3fv(color[4]);
        glVertex2iv(v[4]);
        glColor3fv(color[3]);
        glVertex2iv(v[3]);

        glColor3fv(color[3]);
        glVertex2iv(v[3]);
        glColor3fv(color[1]);
        glVertex2iv(v[1]);

        glColor3fv(color[3]);
        glVertex2iv(v[3]);
        glColor3fv(color[2]);
        glVertex2iv(v[2]);

        glColor3fv(color[3]);
        glVertex2iv(v[3]);
        glColor3fv(color[5]);
        glVertex2iv(v[5]);

        glColor3fv(color[5]);
        glVertex2iv(v[5]);
        glColor3fv(color[6]);
        glVertex2iv(v[6]);

        glColor3fv(color[6]);
        glVertex2iv(v[6]);
        glColor3fv(color[7]);
        glVertex2iv(v[7]);

        glColor3fv(color[4]);
        glVertex2iv(v[4]);
        glColor3fv(color[6]);
        glVertex2iv(v[6]);

        glColor3fv(color[2]);
        glVertex2iv(v[2]);
        glColor3fv(color[7]);
        glVertex2iv(v[7]);
    glEnd();

}

void level_one()
{

    char lnum[80];
    strcpy(lnum,"Level 1");
    int len;
    len = strlen(lnum);

    glColor3f(0, 0 , 1);
    glRasterPos2i(260, 420);
    for(int i = 0; i < len; i++)
    {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, lnum[i]);
    }

    v[1][0] = 285, v[1][1] = 300; v[2][0] = 410, v[2][1] = 100, v[3][0] = 160, v[3][1] = 100;

    //color[1] = {0.8,0.0,1.0};

    color[1][0] = 0.8, color[1][1] = 0.0, color[1][2] = 1.0;
    color[2][0] = 0.0, color[2][1] = 1.0, color[2][2] = 0.0;
    color[3][0] = 0.0, color[3][1] = 0.0, color[3][2] = 1.0;

    /// connectivity
    graph[1][2] = 1; graph[2][3] = 1; graph[3][1] = 1;
    graph[2][1] = 1; graph[3][2] = 1; graph[1][3] = 1;

    glPointSize(20.0);
    glBegin(GL_POINTS);
        glColor3fv(color[1]);
        glVertex2iv(v[1]);
        glColor3fv(color[2]);
        glVertex2iv(v[2]);
        glColor3fv(color[3]);
        glVertex2iv(v[3]);
    glEnd();



    glRasterPos2i(280, 315);
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, '1');

    glRasterPos2i(425, 92);
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, '2');

    glRasterPos2i(135, 92);
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, '3');


    glLineWidth(5);
    glBegin(GL_LINES);
        glColor3fv(color[1]);
        glVertex2iv(v[1]);
        glColor3fv(color[2]);
        glVertex2iv(v[2]);

        glVertex2iv(v[2]);
        glColor3fv(color[3]);
        glVertex2iv(v[3]);

        glVertex2iv(v[3]);
        glColor3fv(color[1]);
        glVertex2iv(v[1]);
    glEnd();

}


int clicked_on(int x, int y)
{
    int mn = INT_MAX, c;
    for(int i = 1; i <= node[level] ; i++)
    {
        int d = abs(v[i][0] - x) + abs(v[i][1] - y);

        if(d < mn)
        {
            c = i;
            mn = d;
        }
    }

    return c;
}


void mouse(int button, int state, int mousex, int mousey)
{
    if(button==GLUT_LEFT_BUTTON && state==GLUT_UP)
    {
        ++m;
        int p, q;
        p = mousex;
        q = 480 - mousey;

        int x = clicked_on(p, q);
        clicked.pb(x);

        if(cnt_edge > 0)
        {
            if(prev_point != clicked[0])
            {
                if(m == 2) m = 0, clicked.clear();
            }

        }

        if(m == 2)
        {
            if(graph[clicked[0]][clicked[1]])
            {
                graph[clicked[0]][clicked[1]] = false;
                graph[clicked[1]][clicked[0]] = false;
            }

            else m = 0, clicked.clear();

            if(clicked[0] == clicked[1]) m = 0, clicked.clear();
        }

    }

}

void mykey(unsigned char key,int x,int y)
{
    if(key=='r')
    {
        int c = 0, last_move[3];

        while(!record_of_moves.empty() && c <= 1)
        {
            ++c;
            last_move[c] = record_of_moves.top();
            record_of_moves.pop();
        }

        if(c == 2)
        {
            /// draw previous line
            glLineWidth(5);
            glBegin(GL_LINES);
            glColor3fv(color[last_move[1]]);
            glVertex2iv(v[last_move[1]]);
            glColor3fv(color[last_move[2]]);
            glVertex2iv(v[last_move[2]]);
            glEnd();
            glFlush();

            /// adjusting variables
            --cnt_edge; c = 0; clicked.clear(); m = 0;
            prev_point = last_move[2];
            if(cnt_edge == 0) prev_point = 0;
            graph[last_move[1]][last_move[2]] = true;
            graph[last_move[2]][last_move[1]] = true;
        }

    }

    else if(key == 's')
    {
        kb = 1;
        display();

    }
}


void clr()
{
    ++level;
    cnt_edge = 0;
    one = true;
    glClearColor(0,0,0,0);
    glClear(GL_COLOR_BUFFER_BIT);
    clicked.clear();
    mem(graph, false);
    mem(v, 0);
    mem(color, 0.0);
    while(!record_of_moves.empty()) record_of_moves.pop();
}

void display(void)
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
    gluOrtho2D(0, 640.0, 0, 480.0);


    if(kb == true)
    {
        kb = false;
        int len;
        len = strlen(ans[level]);
        glColor3f(0, 1 , 0);
        glRasterPos2i(0, 20);
        for(int j = 0; j < len; j++)
        {
            glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, ans[level][j]);
        }
    }

	if(level == 1 && one == true){
        one = false;
        level_one();
	}

	if(m > 0 && m == 2)
    {
        glColor3f(1, 0.2, 0.2);
        glLineWidth(5);
        glBegin(GL_LINES);
        glVertex2iv(v[clicked[0]]);
        glVertex2iv(v[clicked[1]]);
        glEnd();

        prev_point = clicked[1];

        record_of_moves.push(clicked[0]);
        record_of_moves.push(clicked[1]);

        m = 0;
        ++cnt_edge;
        if(level == 1)
        {
            if(cnt_edge == edge[level])
            {
                clr();
                level_two();
            }
        }

        else if(level == 2)
        {
            if(cnt_edge == edge[level])
            {
                clr();
                level_three();
            }
        }

        else if(level == 3)
        {
            if(cnt_edge == edge[level])
            {
                clr();
                level_four();
            }
        }

        else if(level == 4)
        {
            if(cnt_edge == edge[level])
            {
                clr();
                exit(0);
            }
        }

        clicked.clear();

    }

	glFlush();
}


int main(int argc,char** argv)
{
    edge[1] = 3; edge[2] = 10;  edge[3] = 11; edge[4] = 12;
    node[1] = 3; node[2] = 7; node[3] = 8; node[4] = 9;


    cout << "\t\t\t\tConnect the Shape Game\n\n\n";
    cout << "Rules are as follows - \n\n";
    cout << "\t1. For each move TWO connectd points must be clicked to cover the edge between them.\n";
    cout << "\t2. You CAN NOT go through an edge you already covered once\n";
    cout << "\t3. As a first move, click on ANY two points connected by an edge\n";
    cout << "\t4. Click on the point you clicked LAST and any point CONNECTED to that point\n";
    cout << "\t5. Repeat untill ALL the edges of the shape are covered.\n";

    cout << "\t6. To revert each move press \'r\' (without quotes)\n";
    cout << "\t7. Press \'S\' (without quotes) to see the solution.\n\n";

    init_solution();
	glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE);
   	glutInitWindowSize(640, 480);
    glutCreateWindow("graphics project");
    glClearColor(0,0,0,0);
	glClear(GL_COLOR_BUFFER_BIT);


 	glutDisplayFunc(display);
	glutKeyboardFunc(mykey);
	glutMouseFunc(mouse);
   	glutMainLoop();
}
