#include<GL/glut.h>
#include<stdio.h>
#include<math.h>
#include <stdlib.h> 
#define wsx 1280 //Windows Size x-Axis
#define wsy 720 //Window Size y-Axis
#define PI 3.14

//Space for Global Varibles
GLfloat angle=0.0f;   // rotational angle of the shapes
int refreshms=30;     // refresh interval in milliseconds
GLint i=0,j=0;
float radius = 70;
float twoPI = 2 * PI;

//Initialize OpenGl Graphics. One time things
void init()
            {
    glClearColor(0.1,0.1,0.1,0.0);
    //glViewport(800,0,1280,720);
    //glColor3f(1.0,0.0,0.0);
    gluOrtho2D(-1000,24600,-6000,8440); 
    //glViewport(0,0,1280,720);   
                                    }
//Timer Function. Repeated Callbacks Occurs here
void timer(int value) 
                        {
   glutPostRedisplay();      // Post re-paint request to activate display()
   glutTimerFunc(refreshms, timer, 0); // next timer call milliseconds later
                                            }


//Ground on Earth
void ground(){
    // glBegin(GL_POLYGON);       //Ground on Earth  //quad or rectangnle is to be replaced with polygon 
    //     glColor3f(0.0,1.0,0.3);
    //     glVertex2i(0,0);
    //     glVertex2i(0,150);
    //     glVertex2i(2000,150);
    //     glVertex2i(2000,0);
    // glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3f(0.9,0.9,0.9);
    for (float t = 0; t <= 6.29; t += 0.001)
        glVertex2f(100+(sin(t)*2000),-2000+(cos(t)*2000));
    glEnd();


    glBegin(GL_POLYGON);
        glColor3f(1.0,1.0,1.0);
        glVertex2i(1920,200);
        glVertex2i(1920,250);
        glVertex2i(1950,250);
        glVertex2i(1950,200);
    glEnd(); 
    int m,n;
    // glBegin(GL_POINTS);
    // //glColor3f(0.5,0.5,0.5);
    // for (i = 0;i < 6.29;i += 0.001){ 
    //         m= 970+ 80 * cos(i); 
    //         n =400 +80 * sin(i); 
    //         glVertex2f(m,n); 
    // }
    // glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3f(0.9,0.9,0.9);
    for (float t = 0; t <= 6.29; t += 0.001)
        glVertex2f(19000+(sin(t)*2000),-2000+(cos(t)*2000));
    glEnd();
}

//our Rocket
void rocket(int x){
    glBegin(GL_TRIANGLE_FAN);
    glColor3f(0.0,1.0,0.0);
    for (float t = -1.57; t <= PI/2; t += 0.001)
        glVertex2f(970+(sin(t)*radius),x+450+(cos(t)*radius));
    glEnd();
    // glBegin(GL_TRIANGLES);      //The head
    //     glColor3f(1.0,1.0,1.0);
    //     glVertex2i(900,460+x);
    //     glVertex2i(1000,460+x);
    //     glVertex2i(950,610+x);
    // glEnd();
    //glPopMatrix(); 
    glBegin(GL_QUADS);         //The Rocket
        glColor3f(1.0,0.0,0.0);
        glVertex2i(900,200+x);
        glVertex2i(900,450+x);
        glVertex2i(1040,450+x);
        glVertex2i(1040,200+x);
    glEnd();
    glBegin(GL_QUADS);  //left Wing
        glColor3f(1.0,0.0,1.0);
        glVertex2i(900,200+x);
        glVertex2i(900,300+x);
        glVertex2i(825,265+x);
        glVertex2i(825,200+x);
    glEnd();
    glBegin(GL_QUADS);  //right Wing
        glColor3f(1.0,0.0,1.0);
        glVertex2i(1040,200+x);
        glVertex2i(1040,300+x);
        glVertex2i(1115,265+x);
        glVertex2i(1115,200+x);
    glEnd();
    glBegin(GL_QUADS);  //lower thrusters
        glColor3f(1.0,.0,0.5);
        glVertex2i(910,200+x);
        glVertex2i(880,180+x);
        glVertex2i(1060,180+x);
        glVertex2i(1030,200+x);
    glEnd();
    glBegin(GL_POLYGON); // fire
        glColor3f(((rand()%(101))/100),((rand()%(101))/100),0.0);
        glVertex2i(200,200+x);
        glVertex2i(300,200+x);
        glVertex2i(200,300+x);
        glVertex2i(300,300+x);
    glEnd();

    
            }
//The Stickman with 5 degrees of freedom
void stick(int x,int y){
    glLineWidth(5.0);
    glBegin(GL_LINES);         //Stickman Figure with 5 degrees of freedom  Top-down is being followed
        glColor3f(0.0,0.0,0.0);

        glVertex2i(200+x,230);        //torso
        glVertex2i(200+x,330);

        glVertex2i(200+x,310);        //Obvious left hand
        glVertex2i(150+y+x,230);

        glVertex2i(200+x,310);        //right hand
        glVertex2i(250-y+x,230);

        glVertex2i(200+x,230);        //Assumed left leg
        glVertex2i(150+y+x,150);

        glVertex2i(200+x,230);        //right leg
        glVertex2i(250-y+x,150);

    glEnd();
            }
void zoom(int x,int y){
    //int gh=50;
    //int h=glutGet(GLUT_ELAPSED_TIME)/100;
   // printf("the time Elsaped %d",h);
    //if(h>gh){
        //if()
    //glViewport(0,-2000,9000,7660);
    //glMatrixMode(GL_PROJECTION);glLoadIdentity();
    //glutSetWindow(0,1000,0,200);
    //glClear(GL_COLOR_BUFFER_BIT); 
    //gluPerspective(800,900,100,150);
    // gluOrtho2D(1200,2000,0,720);
    // glMatrixMode(GL_MODELVIEW); //Frustum(800,900,100,190,0.1,0.9);
    //}
} 
//The Main Display Functiom
void display()
              {
    glClear(GL_COLOR_BUFFER_BIT);     //Enabling the Color
    //glColor3f(1.0,0.0,0.0);          //Color RGB Red Green Blue
    glMatrixMode(GL_MODELVIEW);     // To operate on Model-View matrix
    //glLoadIdentity();               // Reset the model-view matrix
    //Space for Static Polygons eg. ground
    glPushMatrix();
    zoom(i,j);
    glPopMatrix();
    glPushMatrix();
    ground();

    glPopMatrix();  
    //Space For Moving Objects
    glPushMatrix();  // ground push

    rocket(i);
    glPopMatrix(); 

    glPushMatrix();  // rocket push
    stick(i,j);
    glPopMatrix();

    glPushMatrix();  // stick push

    // zoom(i,j);
    // glPopMatrix();
    // glPushMatrix(); // zoom push
    
    // glBegin(GL_POLYGON);
    //     glColor3f(1.0,0.0,0.5);
    //     glVertex2i(1920,200);
    //     glVertex2i(1920,250);
    //     glVertex2i(1950,250);
    //     glVertex2i(1950,200);
    // glEnd(); 
    // glPushMatrix(); // last polygon push
    glPopMatrix();
    //glPopMatrix();       //for head of the man
    // int i;
	// int triangleAmount = 20;
	// int x=200, y=410, radius=40;
	// GLfloat twicePi = 2.0f * 3.1416;

	// glBegin(GL_TRIANGLE_FAN);
	// 	glVertex2f(x, y);
	// 	for(i = 0; i <= triangleAmount;i++) {
	// 		glVertex2f(
	// 	            x + (radius * cos(i *  twicePi / triangleAmount)),
	// 		    y + (radius * sin(i * twicePi / triangleAmount))
	// 		);
	// 	}
	// glEnd();
	// glFlush();

	//for eyes of the man
	// int j;
	// int triangleAmount2 = 20;
	// int x2=185, y2=410, radius2=5;
	// GLfloat twicePi2 = 2.0f * 3.1416;
	// glColor3f(1.0,1.0,1.0);

	// glBegin(GL_TRIANGLE_FAN);
	// 	glVertex2f(x2, y2);
	// 	for(j = 0; j <= triangleAmount2;j++) {
	// 		glVertex2f(
	// 	            x2 + (radius2 * cos(j *  twicePi2 / triangleAmount2)),
	// 		    y2 + (radius2 * sin(j * twicePi2 / triangleAmount2))
	// 		);
	// 	}
	// glEnd();
	// glFlush();

	// int i3;
	// int triangleAmount3 = 20;
	// int x3=215, y3=410, radius3=5;
	// GLfloat twicePi3 = 2.0f * 3.1416;
	// glColor3f(1.0,1.0,1.0);

	// glBegin(GL_TRIANGLE_FAN);
	// 	glVertex2f(x3, y3);
	// 	for(i3 = 0; i3 <= triangleAmount3;i3++) {
	// 		glVertex2f(
	// 	            x3 + (radius3 * cos(i3 *  twicePi3 / triangleAmount3)),
	// 		    y3 + (radius3 * sin(i3 * twicePi3 / triangleAmount3))
	// 		);
	// 	}
	// glEnd();
    // int i4;
	// int triangleAmount4 = 20;
	// int x4=200, y4=390, radius4=10;
	// GLfloat twicePi4 = 1.0f * 3.1416;
	// glColor3f(1.0,1.0,1.0);

	// glBegin(GL_TRIANGLE_FAN);
	// 	glVertex2f(x4, y4);
	// 	for(i4 = 0; i4 <= triangleAmount4;i4++) {
	// 		glVertex2f(
	// 	            x4 - (radius3 * cos(i4 *  twicePi4 / triangleAmount4)),
	// 		    y4 - (radius4 * sin(i4 * twicePi4 / triangleAmount4))
	// 		);
	// 	}
	// glEnd();


    //The most imp place, animation variables updates here
    glutSwapBuffers();
    if(i<1500)
        i+=2;
    j+=2.5;
    if(j==100)
        j=0;

                            }
int main(int argc,char** argv)
                               { //The Main Function CAll
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB);
    glutInitWindowPosition(0,0);
    glutInitWindowSize(1280,720);
    glutCreateWindow("@title HERE");
    init();
    glutDisplayFunc(display); // Paints the Display
    glutTimerFunc(0, timer, 0);
    //glutFullScreen();
    glutMainLoop();
                    }
                  