#include <windows.h>

#include <GL/gl.h>
#include <GL/glut.h>
#include<math.h>>

# define PI           3.14159265358979323846

GLfloat position = 0.0f;
GLfloat speed = 1.0f;
GLfloat positionsun = 0.0f;
GLfloat speedsun = 0.10f;


void init()
{
    glLoadIdentity();
    gluOrtho2D(-115,120,-160,120);


}



GLfloat speed01 = 0.15f; //speed plane
GLfloat position01 = 0.0f; //position plane

void update01(int value) {  //plane

    if(position01 <-160){

        position01= 120.0f;}

    position01 -= speed01; //position=position-speed;1-.1=.9

	glutPostRedisplay();


	glutTimerFunc(100, update01, 0);
}


void update(int value) {  //cloud

    if(position <-160)
        position = 120.0f;

    position -= speed; //position=position-speed;1-.1=.9

	glutPostRedisplay();


	glutTimerFunc(100, update, 0);
}


void updatesun(int value) { //sun

    if(positionsun <-50)
        positionsun =120.0f;

    positionsun -= speedsun; //position=position-speed;1-.1=.9

	glutPostRedisplay();


	glutTimerFunc(100, updatesun, 0);
}


void circleSolid(float x, float y, float radius)
{
	int triangleAmount = 100; //# of triangles used to draw circle

	GLfloat twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); // center of circle
    for(int i = 0; i <= triangleAmount; i++)
        {
            glVertex2f(x + (radius * cos(i *  twicePi / triangleAmount)), y + (radius * sin(i * twicePi / triangleAmount)));
		}
    glEnd();
}







 void BackgroundDay(){

    glBegin(GL_QUADS); ///////////////////////bakground white////////////////////////////////////////////
    glColor3ub(255, 255, 128);
    glVertex2f(-115.0f,-5.0f);
    glVertex2f(120.0f,-5.0f);
    glVertex2f(120.0f,-160.0f);
    glVertex2f(-115.0f,-160.0f);
    glEnd();
 }


void SkyDay(){


     glBegin(GL_QUADS);
	glColor3ub(102, 224, 255);
	glVertex2f(-115.0f, 30.0f);
	glVertex2f(-115.0f, 60.0f);  //cloud 1
	glVertex2f(120.0f, 60.0f);
	glVertex2f(120.0f, 30.0f);
	glEnd();

	 glBegin(GL_QUADS);
	glColor3ub(51, 214, 255);
	glVertex2f(-115.0f, 60.0f);
	glVertex2f(-115.0f, 80.0f);  //cloud 2
	glVertex2f(120.0f, 80.0f);
	glVertex2f(120.0f, 60.0f);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub(0, 204, 255);
	glVertex2f(-115.0f, 80.0f);
	glVertex2f(-115.0f, 100.0f);  //cloud 3
	glVertex2f(120.0f, 100.0f);
	glVertex2f(120.0f, 80.0f);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub(0, 184, 230);
	glVertex2f(-115.0f, 100.0f);
	glVertex2f(-115.0f, 120.0f);  //cloud 4
	glVertex2f(120.0f, 120.0f);
	glVertex2f(120.0f, 100.0f);
	glEnd();
}

void sunDay()
{

	glPushMatrix();
    glTranslatef(position,position,0);
	glColor3ub(255,255, 0);
	circleSolid(95.0f,95.0f,10.0f);
	glPopMatrix();
}


	void plane()
	{

	    /* plane */
/* base */
glPushMatrix();
glTranslatef(position01,0,0);

    glBegin(GL_POLYGON);
    glColor3ub(245, 248, 252);
    glVertex2f(23.0f,91.0f);
    glVertex2f(40.0f,91.0f);
    glVertex2f(40.0f,87.0f);
    glVertex2f(21.0f,87.0f);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2f(21.0f,87.0f);
    glVertex2f(23.0f,83.0f);
    glVertex2f(40.0f,83.0f);
    glVertex2f(40.0f,87.0f);
    glEnd();

    /* down turbine*/
        glBegin(GL_POLYGON);
            glColor3ub(204, 255, 51);
    glVertex2f(25.0f,87.0f);
    glVertex2f(30.0f,87.0f);
    glVertex2f(32.0f,79.0f);
    glVertex2f(29.0f,79.0f);
    glEnd();
        /* up turbine*/
            glBegin(GL_POLYGON);
    glColor3ub(204, 255, 51);
    glVertex2f(26.0f,91.0f);
    glVertex2f(30.0f,91.0f);
    glVertex2f(32.0f,95.0f);
    glVertex2f(30.0f,95.0f);
    glEnd();
            /* back turbine*/
    glBegin(GL_POLYGON);
    glColor3ub(255, 255, 0);
    glVertex2f(35.0f,91.0f);
    glVertex2f(40.0f,91.0f);
    glVertex2f(40.0f, 97.0f);
    glVertex2f(38.0f,97.0f);
    glEnd();

    glPopMatrix();




	}

void lk(){

    glBegin(GL_QUADS);
	glColor3ub(255, 102, 102);
	glVertex2f(-25.0f, 0.0f);
	glVertex2f(-25.0f, 44.0f);  // middle box
	glVertex2f(25.0f, 44.0f);
	glVertex2f(25.0f, 0.0f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(255,255,255);

	glVertex2f(-10.0f, 0.0f);
	glVertex2f(-10.0f, 25.0f);
	glVertex2f(0.0f, 30.0f);   // middle back door
	glVertex2f(10.0f, 25.0f);
	glVertex2f(10.0f, 0.0f);
	glEnd();












	glBegin(GL_QUADS);
	glColor3ub(255, 102, 102);

	glVertex2f(-25.0f, 0.0f);
	glVertex2f(-55.0f, 0.0f);
	glVertex2f(-55.0f, 40.0f);   // Left box
	glVertex2f(-25.0f, 40.0f);

	glEnd();


	glBegin(GL_QUADS);
	glColor3ub(255, 102, 102);

	glVertex2f(25.0f, 0.0f);
	glVertex2f(55.0f, 0.0f);
	glVertex2f(55.0f, 40.0f);   // Right box
	glVertex2f(25.0f, 40.0f);

	glEnd();


	glBegin(GL_POLYGON);
	glColor3ub(255,255,255);

	glVertex2f(-33.0f, 0.0f);
	glVertex2f(-47.0f, 0.0f);
	glVertex2f(-47.0f, 21.0f);
	glVertex2f(-40.0f, 25.0f);   // left back door
	glVertex2f(-33.0f, 21.0f);

	glEnd();



	glBegin(GL_POLYGON);
	glColor3ub(255,255,255);

	glVertex2f(33.0f, 0.0f);
	glVertex2f(47.0f, 0.0f);
	glVertex2f(47.0f, 21.0f);
	glVertex2f(40.0f, 25.0f);   // Right back door
	glVertex2f(33.0f, 21.0f);

	glEnd();


	glBegin(GL_POLYGON);
	glColor3ub(0,0,0);

	glVertex2f(-4.0f, 0.0f);
	glVertex2f(-4.0f, 15.0f);
	glVertex2f(0.0f, 18.0f);
	glVertex2f(4.0f, 15.0f);   // middle door
	glVertex2f(4.0f, 0.0f);

	glEnd();




	glBegin(GL_QUADS);
	glColor3ub(0, 0, 0);

	glVertex2f(-37.0f, 0.0f);
	glVertex2f(-43.0f, 0.0f);
	glVertex2f(-43.0f, 15.0f);   // left door
    glVertex2f(-37.0f, 15.0f);

	glEnd();

	    glBegin(GL_TRIANGLES);//
    glColor3ub(0, 0, 0);//    left door uper small triangle

    glVertex2f(-38.0f,17.0f);    // x, y
	glVertex2f(-42.0f,17.0f);
	glVertex2f(-40.0f, 20.0f);
	glEnd();



	glBegin(GL_QUADS);
	glColor3ub(0, 0, 0);

	glVertex2f(37.0f, 0.0f);
	glVertex2f(43.0f, 0.0f);
	glVertex2f(43.0f, 15.0f);   // Right door
    glVertex2f(37.0f, 15.0f);

	glEnd();


	 glBegin(GL_TRIANGLES);//
    glColor3ub(0, 0, 0);//    Right door uper small triangle

    glVertex2f(38.0f,17.0f);    // x, y
	glVertex2f(42.0f,17.0f);
	glVertex2f(40.0f, 20.0f);
	glEnd();



	glBegin(GL_QUADS);
	glColor3ub(255, 77, 77);

	glVertex2f(-55.0f, 0.0f);
	glVertex2f(-57.0f, -1.0f);
	glVertex2f(-57.0f, 41.0f);   // left gombuj //box 1
    glVertex2f(-55.0f, 40.0f);

	glEnd();


	glBegin(GL_QUADS);
	glColor3ub(255, 77, 77);

	glVertex2f(55.0f, 0.0f);
	glVertex2f(57.0f, -1.0f);
	glVertex2f(57.0f, 41.0f);   // Right gombuj //box 1
    glVertex2f(55.0f, 40.0f);

	glEnd();


		glBegin(GL_QUADS);
	glColor3ub(255, 102, 102);

	glVertex2f(-57.0f, -1.0f);
	glVertex2f(-63.0f, -1.0f);
	glVertex2f(-63.0f, 41.0f);   // left gombuj //box 2
    glVertex2f(-57.0f, 41.0f);

	glEnd();


	glBegin(GL_QUADS);
	glColor3ub(255, 102, 102);

	glVertex2f(57.0f, -1.0f);
	glVertex2f(63.0f, -1.0f);
	glVertex2f(63.0f, 41.0f);   // Right gombuj //box 2
    glVertex2f(57.0f, 41.0f);

	glEnd();


	glBegin(GL_QUADS);
	glColor3ub(255, 77, 77);


	glVertex2f(-63.0f, -1.0f);
	glVertex2f(-65.0f, 0.0f); // left gombuj //box 3
    glVertex2f(-65.0f, 40.0f);
    glVertex2f(-63.0f, 41.0f);

	glEnd();

	glBegin(GL_QUADS);
	glColor3ub(255, 77, 77);


	glVertex2f(63.0f, -1.0f);
	glVertex2f(65.0f, 0.0f); // Right gombuj //box 3
    glVertex2f(65.0f, 40.0f);
    glVertex2f(63.0f, 41.0f);

	glEnd();


	glBegin(GL_POLYGON);
	glColor3ub(198, 83, 83);

	glVertex2f(-57.0f, 41.0f);
	glVertex2f(-63.0f, 41.0f);
	glVertex2f(-55.0f, 40.0f);
	glVertex2f(-55.0f, 44.0f);
	glVertex2f(-65.0f, 44.0f);
	glVertex2f(-65.0f, 40.0f);   // left piller up 1



	glEnd();

	glBegin(GL_QUADS);
	glColor3ub(255, 77, 77);


	glVertex2f(-56.0f, 44.0f);
	glVertex2f(-64.0f, 44.0f); // left piller up 2
    glVertex2f(-64.0f, 50.0f);
    glVertex2f(-56.0f, 50.0f);

	glEnd();


	glBegin(GL_QUADS);
	glColor3ub(1,1,1);


	glVertex2f(-54.0f, 50.0f);
	glVertex2f(-66.0f, 50.0f); // left piller up 3
    glVertex2f(-66.0f, 51.0f);
    glVertex2f(-54.0f, 51.0f);

	glEnd();


	glBegin(GL_POLYGON);
	glColor3ub(198, 83, 83);

	glVertex2f(57.0f, 41.0f);
	glVertex2f(63.0f, 41.0f);
	glVertex2f(55.0f, 40.0f);
	glVertex2f(55.0f, 44.0f);
	glVertex2f(65.0f, 44.0f);
	glVertex2f(65.0f, 40.0f);   // right piller up 1



	glEnd();

	glBegin(GL_QUADS);
	glColor3ub(255, 77, 77);


	glVertex2f(56.0f, 44.0f);
	glVertex2f(64.0f, 44.0f); // right piller up 2
    glVertex2f(64.0f, 50.0f);
    glVertex2f(56.0f, 50.0f);

	glEnd();


	glBegin(GL_QUADS);
	glColor3ub(1,1,1);


	glVertex2f(54.0f, 50.0f);
	glVertex2f(66.0f, 50.0f); // right piller up 3
    glVertex2f(66.0f, 51.0f);
    glVertex2f(54.0f, 51.0f);

	glEnd();

	glBegin(GL_QUADS);
	glColor3ub(198, 83, 83);


	glVertex2f(-55.0f, 40.0f);
	glVertex2f(-55.0f, 44.0f); // left uper box
    glVertex2f(-25.0f, 44.0f);
    glVertex2f(-25.0f, 40.0f);

	glEnd();

	glBegin(GL_QUADS);
	glColor3ub(198, 83, 83);


	glVertex2f(-25.0f, 44.0f);
	glVertex2f(-29.0f, 44.0f); // left uper box 2
    glVertex2f(-29.0f, 50.0f);
    glVertex2f(-25.0f, 50.0f);

	glEnd();


	glBegin(GL_QUADS);
	glColor3ub(198, 83, 83);


	glVertex2f(-25.0f, 44.0f);
	glVertex2f(-25.0f, 50.0f); // middle box
    glVertex2f(25.0f, 50.0f);
    glVertex2f(25.0f, 44.0f);

	glEnd();

	glBegin(GL_QUADS);
	glColor3ub(198, 83, 83);


	glVertex2f(55.0f, 40.0f);
	glVertex2f(55.0f, 44.0f); // right uper box
    glVertex2f(25.0f, 44.0f);
    glVertex2f(25.0f, 40.0f);

	glEnd();

	glBegin(GL_QUADS);
	glColor3ub(198, 83, 83);


	glVertex2f(25.0f, 44.0f);
	glVertex2f(29.0f, 44.0f); // right uper box 2
    glVertex2f(29.0f, 50.0f);
    glVertex2f(25.0f, 50.0f);

	glEnd();




    glLineWidth(7.5);
	glBegin(GL_LINES);

	glColor3ub(102, 0, 0);
	glVertex2f(-55.0f, 40.0f);
    glVertex2f(-25.0f, 40.0f);

	glEnd();

	glLineWidth(7.5);
	glBegin(GL_LINES);

	glColor3ub(102, 0, 0);

    glVertex2f(-25.0f, 40.0f);
    glVertex2f(-25.0f, 44.0f);

	glEnd();

	glLineWidth(7.5);
	glBegin(GL_LINES);

	glColor3ub(102, 0, 0);

    glVertex2f(-25.0f, 44.0f);
    glVertex2f(25.0f, 44.0f);

	glEnd();

	glLineWidth(7.5);
	glBegin(GL_LINES);

	glColor3ub(102, 0, 0);

    glVertex2f(25.0f, 40.0f);
    glVertex2f(25.0f, 44.0f);

	glEnd();

	 glLineWidth(7.5);
	glBegin(GL_LINES);

	glColor3ub(102, 0, 0);
	glVertex2f(55.0f, 40.0f);
    glVertex2f(25.0f, 40.0f);

	glEnd();

	glBegin(GL_QUADS);
	glColor3ub(198, 83, 83);


	glVertex2f(21.0f, 0.0f);
	glVertex2f(23.0f, 0.0f); // right small pillar
    glVertex2f(23.0f, 53.0f);
    glVertex2f(21.0f, 53.0f);

	glEnd();

	glBegin(GL_QUADS);
	glColor3ub(198, 83, 83);


	glVertex2f(-21.0f, 0.0f);
	glVertex2f(-23.0f, 0.0f); // left small pillar
    glVertex2f(-23.0f, 53.0f);
    glVertex2f(-21.0f, 53.0f);

	glEnd();
////////////////////tupi//////////////////////
	glBegin(GL_TRIANGLES);//
    glColor3ub(0, 0, 0);//    tupi

    glVertex2f(-59.0f,55.0f);    // x, y
	glVertex2f(-61.0f,55.0f);
	glVertex2f(-60.0f, 60.0f);
	glEnd();

	glColor3ub(198, 83, 83);

     int i;

	GLfloat x=-60.0f; GLfloat y=51.0f; GLfloat radius =5.0f;
	int triangleAmount = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi = 1.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
/////////////////////tupi//////////////////////right
	glBegin(GL_TRIANGLES);//
    glColor3ub(0, 0, 0);//    tupi

    glVertex2f(59.0f,55.0f);    // x, y
	glVertex2f(61.0f,55.0f);
	glVertex2f(60.0f, 60.0f);
	glEnd();


glColor3ub(198, 83, 83);
	int j;

	 x=60.0f;  y=51.0f;  radius =5.0f;
	int triangleAmount1 = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	 twicePi = 1.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(j = 0; j <= triangleAmount;j++) {
			glVertex2f(
		            x + (radius * cos(j *  twicePi / triangleAmount)),
			    y + (radius * sin(j * twicePi / triangleAmount))
			);
		}
	glEnd();


////////////////////////middle tupi/////////////////////
glBegin(GL_TRIANGLES);//
    glColor3ub(0, 0, 0);//    tupi

    glVertex2f(-4.0f,63.0f);    // x, y
	glVertex2f(4.0f,63.0f);
	glVertex2f(0.0f, 72.0f);
	glEnd();
glColor3ub(153,0,0);
int k;

	 x=0.0f;  y=50.0f;  radius =15.0f;
	int triangleAmount3 = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	 twicePi = 1.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(k = 0; k <= triangleAmount;k++) {
			glVertex2f(
		            x + (radius * cos(k *  twicePi / triangleAmount)),
			    y + (radius * sin(k * twicePi / triangleAmount))
			);
		}
	glEnd();


	int l;

	 x=22.0f;  y=53.0f;  radius =1.50f;
	int triangleAmount4 = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	 twicePi = 1.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(l = 0; l <= triangleAmount;l++) {
			glVertex2f(
		            x + (radius * cos(l *  twicePi / triangleAmount)),
			    y + (radius * sin(l * twicePi / triangleAmount))
			);
		}
	glEnd();


	int m;

	 x=-22.0f;  y=53.0f;  radius =1.50f;
	int triangleAmount5 = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	 twicePi = 1.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(m = 0; m <= triangleAmount;m++) {
			glVertex2f(
		            x + (radius * cos(m *  twicePi / triangleAmount)),
			    y + (radius * sin(m * twicePi / triangleAmount))
			);
		}
	glEnd();


	glBegin(GL_QUADS);
	glColor3ub(0,0,0);


	glVertex2f(-55.0f, 0.0f);
	glVertex2f(-55.0f,-1.0f); // down border 1/////////
    glVertex2f(55.0f, -1.0f);
    glVertex2f(55.0f, 0.0f);

	glEnd();

	glBegin(GL_QUADS);
	glColor3ub(191, 64, 64);


	glVertex2f(-65.0f, -1.0f);
	glVertex2f(-65.0f,-5.0f); // down border 2/////////
    glVertex2f(65.0f, -5.0f);
    glVertex2f(65.0f, -1.0f);

	glEnd();
}

void grass()
{

    /* grass */
    glBegin(GL_QUADS);
    glColor3ub(0, 179, 0);
    glVertex2f(-15.0f, -5.0f);
    glVertex2f(-90.0f, -160.0f);
    glVertex2f(-115.0f, -160.0f);
    glVertex2f(-115.0f, -5.0f);
    glEnd();


    /* right  side */

        glBegin(GL_QUADS);
    glColor3ub(0, 179, 0);
    glVertex2f(15.0f, -5.0f);
    glVertex2f(90.0f, -160.0f);
    glVertex2f(120.0f, -160.0f);
    glVertex2f(120.0f, -5.0f);
    glEnd();
}
void view3d()
{

    glBegin(GL_TRIANGLES);//
    glColor3ub(203, 65, 84);//  // 3D view Left/////////
    glVertex2f(-15.0f, -5.0f);
    glVertex2f(-101.0f,-80.0f);
    glVertex2f(-90.0f, -160.0f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(102, 0, 0);
    glVertex2f(-15.0f, -5.0f);
    glVertex2f(-5.0f, -5.0f);
    glVertex2f(-62.0f, -160.0f);  // left 3st line //
    glVertex2f(-90.0f, -160.0f);
    glEnd();


    glBegin(GL_TRIANGLES);//
    glColor3ub(203, 65, 84);//  // 3D view Left/////////
    glVertex2f(15.0f, -5.0f);
    glVertex2f(101.0f,-80.0f);
    glVertex2f(90.0f, -160.0f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(102, 0, 0);
    glVertex2f(15.0f, -5.0f);
    glVertex2f(5.0f, -5.0f);
    glVertex2f(62.0f, -160.0f);  // left 3st line //
    glVertex2f(90.0f, -160.0f);
    glEnd();

}

void road()
{



	glBegin(GL_QUADS);
	glColor3ub(0,0,0);
	glVertex2f(-2.0f, -15.0f);
	glVertex2f(-2.0f, -19.0f); // road middle
    glVertex2f(2.0f, -19.0f);
    glVertex2f(2.0f, -15.0f);
	glEnd();




	glBegin(GL_QUADS);
	glColor3ub(0,0,0);
	glVertex2f(-2.0f, -23.0f);
	glVertex2f(-2.0f, -28.0f); // road 2 middle
    glVertex2f(2.0f, -28.0f);
    glVertex2f(2.0f, -23.0f);
	glEnd();


	glBegin(GL_QUADS);
	glColor3ub(0,0,0);
	glVertex2f(-2.0f, -34.0f);
	glVertex2f(-2.0f, -43.0f); // road 3 middle
    glVertex2f(2.0f, -43.0f);
    glVertex2f(2.0f, -34.0f);
	glEnd();


	glBegin(GL_QUADS);
	glColor3ub(0,0,0);
	glVertex2f(-2.0f, -54.0f);
	glVertex2f(-2.0f, -69.0f); // road 4 middle
    glVertex2f(2.0f, -69.0f);
    glVertex2f(2.0f, -54.0f);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub(0,0,0);
	glVertex2f(-2.0f, -85.0f);
	glVertex2f(-2.0f, -120.0f); // road 5 middle
    glVertex2f(2.0f, -120.0f);
    glVertex2f(2.0f, -85.0f);
	glEnd();
}

void right1stbuilding()
{

	glBegin(GL_QUADS);
	glColor3ub(107, 107, 71);
	glVertex2f(70.0f, 10.0f);
	glVertex2f(80.0f, 10.0f);
	glVertex2f(80.0f, 30.0f);   // Right building 1
	glVertex2f(70.0f, 30.0f);
	glEnd();




	glBegin(GL_QUADS);
	glColor3ub(255, 255, 255);

	glVertex2f(71.0f, 13.0f);
	glVertex2f(74.0f, 13.0f);
	glVertex2f(74.0f, 18.0f);   // Right building 1 window
	glVertex2f(71.0f, 18.0f);

	glEnd();

	glBegin(GL_QUADS);
	glColor3ub(255, 255, 255);

	glVertex2f(76.0f, 13.0f);
	glVertex2f(79.0f, 13.0f);
	glVertex2f(79.0f, 18.0f);   // Right building 1 window
	glVertex2f(76.0f, 18.0f);

	glEnd();


	glBegin(GL_QUADS);
	glColor3ub(255, 255, 255);

	glVertex2f(71.0f, 22.0f);
	glVertex2f(74.0f, 22.0f);
	glVertex2f(74.0f, 27.0f);   // Right building 2 window
	glVertex2f(71.0f, 27.0f);

	glEnd();


	glBegin(GL_QUADS);
	glColor3ub(255, 255, 255);

	glVertex2f(76.0f, 22.0f);
	glVertex2f(79.0f, 22.0f);
	glVertex2f(79.0f, 27.0f);   // Right building 2 window
	glVertex2f(76.0f, 27.0f);

	glEnd();


	glBegin(GL_QUADS);
	glColor3ub(1,1,1);

	glVertex2f(-70.0f, 10.0f);
	glVertex2f(-80.0f, 10.0f);
	glVertex2f(-80.0f, 30.0f);   // left building 1
	glVertex2f(-70.0f, 30.0f);

	glEnd();
}
 void left1stBuilding()
 {



	glBegin(GL_QUADS);
	glColor3ub(255, 255, 255);

	glVertex2f(-71.0f, 13.0f);
	glVertex2f(-74.0f, 13.0f);
	glVertex2f(-74.0f, 18.0f);   // left building 1 window
	glVertex2f(-71.0f, 18.0f);

	glEnd();

	glBegin(GL_QUADS);
	glColor3ub(255, 255, 255);

	glVertex2f(-76.0f, 13.0f);
	glVertex2f(-79.0f, 13.0f);
	glVertex2f(-79.0f, 18.0f);   // left building 1 window
	glVertex2f(-76.0f, 18.0f);

	glEnd();


	glBegin(GL_QUADS);
	glColor3ub(255, 255, 255);

	glVertex2f(-71.0f, 22.0f);
	glVertex2f(-74.0f, 22.0f);
	glVertex2f(-74.0f, 27.0f);   // left building 2 window
	glVertex2f(-71.0f, 27.0f);

	glEnd();


	glBegin(GL_QUADS);
	glColor3ub(255, 255, 255);

	glVertex2f(-76.0f, 22.0f);
	glVertex2f(-79.0f, 22.0f);
	glVertex2f(-79.0f, 27.0f);   // left building 2 window
	glVertex2f(-76.0f, 27.0f);

	glEnd();
 }
void right2ndbuilding()
{


/////////////////////building 2222222222222222222//////////////////////
	glBegin(GL_QUADS);
	glColor3ub(179, 0, 0);

	glVertex2f(82.0f, 10.0f);
	glVertex2f(95.0f, 10.0f);
	glVertex2f(95.0f, 40.0f);   // Right building 2
	glVertex2f(82.0f, 40.0f);

	glEnd();


	glBegin(GL_QUADS);
	glColor3ub(255, 255, 255);

	glVertex2f(83.0f, 13.0f);
	glVertex2f(87.0f, 13.0f);
	glVertex2f(87.0f, 18.0f);   // Right building 2 window
	glVertex2f(83.0f, 18.0f);

	glEnd();


	glBegin(GL_QUADS);
	glColor3ub(255, 255, 255);

	glVertex2f(90.0f, 13.0f);
	glVertex2f(94.0f, 13.0f);
	glVertex2f(94.0f, 18.0f);   // Right building 2 window
	glVertex2f(90.0f, 18.0f);

	glEnd();


	glBegin(GL_QUADS);
	glColor3ub(255, 255, 255);

	glVertex2f(83.0f, 22.0f);
	glVertex2f(87.0f, 22.0f);
	glVertex2f(87.0f, 27.0f);   // Right building 2 window
	glVertex2f(83.0f, 27.0f);

	glEnd();


	glBegin(GL_QUADS);
	glColor3ub(255, 255, 255);

	glVertex2f(90.0f, 22.0f);
	glVertex2f(94.0f, 22.0f);
	glVertex2f(94.0f, 27.0f);   // Right building 2 window
	glVertex2f(90.0f, 27.0f);

	glEnd();


	glBegin(GL_QUADS);
	glColor3ub(255, 255, 255);

	glVertex2f(83.0f, 31.0f);
	glVertex2f(87.0f, 31.0f);
	glVertex2f(87.0f, 36.0f);   // Right building 2 window   3 3 3
	glVertex2f(83.0f, 36.0f);

	glEnd();


	glBegin(GL_QUADS);
	glColor3ub(255, 255, 255);

	glVertex2f(90.0f, 31.0f);
	glVertex2f(94.0f, 31.0f);
	glVertex2f(94.0f, 36.0f);   // Right building 2 window
	glVertex2f(90.0f, 36.0f);

	glEnd();



	glLineWidth(3);
	glBegin(GL_LINES);

	glColor3ub(102, 0, 0);
	glVertex2f(88.5f, 11.0f);
    glVertex2f(88.5f, 38.0f);  // building line

	glEnd();
}

void left2ndBuilding()
{

	glBegin(GL_QUADS);
	glColor3ub(179, 0, 0);

	glVertex2f(-82.0f, 10.0f);
	glVertex2f(-95.0f, 10.0f);
	glVertex2f(-95.0f, 40.0f);   // left building 2
	glVertex2f(-82.0f, 40.0f);

	glEnd();


	glBegin(GL_QUADS);
	glColor3ub(255, 255, 255);

	glVertex2f(-83.0f, 13.0f);
	glVertex2f(-87.0f, 13.0f);
	glVertex2f(-87.0f, 18.0f);   // Right building 2 window
	glVertex2f(-83.0f, 18.0f);

	glEnd();


	glBegin(GL_QUADS);
	glColor3ub(255, 255, 255);

	glVertex2f(-90.0f, 13.0f);
	glVertex2f(-94.0f, 13.0f);
	glVertex2f(-94.0f, 18.0f);   // Right building 2 window
	glVertex2f(-90.0f, 18.0f);

	glEnd();


	glBegin(GL_QUADS);
	glColor3ub(255, 255, 255);

	glVertex2f(-83.0f, 22.0f);
	glVertex2f(-87.0f, 22.0f);
	glVertex2f(-87.0f, 27.0f);   // Right building 2 window
	glVertex2f(-83.0f, 27.0f);

	glEnd();


	glBegin(GL_QUADS);
	glColor3ub(255, 255, 255);

	glVertex2f(-90.0f, 22.0f);
	glVertex2f(-94.0f, 22.0f);
	glVertex2f(-94.0f, 27.0f);   // Right building 2 window
	glVertex2f(-90.0f, 27.0f);

	glEnd();


	glBegin(GL_QUADS);
	glColor3ub(255, 255, 255);

	glVertex2f(-83.0f, 31.0f);
	glVertex2f(-87.0f, 31.0f);
	glVertex2f(-87.0f, 36.0f);   // Right building 2 window   3 3 3
	glVertex2f(-83.0f, 36.0f);

	glEnd();


	glBegin(GL_QUADS);
	glColor3ub(255, 255, 255);

	glVertex2f(-90.0f, 31.0f);
	glVertex2f(-94.0f, 31.0f);
	glVertex2f(-94.0f, 36.0f);   // Right building 2 window
	glVertex2f(-90.0f, 36.0f);

	glEnd();


	glLineWidth(3);
	glBegin(GL_LINES);

	glColor3ub(102, 0, 0);
	glVertex2f(-88.5f, 11.0f);
    glVertex2f(-88.5f, 38.0f);  // building line

	glEnd();
}

void treeBoxRight()
{


	glBegin(GL_QUADS);
	glColor3ub(1,1,1);

	glVertex2f(-92.0f,-74.0f);
	glVertex2f(-95.0f,-74.0f);
	glVertex2f(-95.0f,-68.0f);   // tree box
	glVertex2f(-92.0f,-68.0f);

	glEnd();


	 glBegin(GL_TRIANGLES);//
    glColor3ub(0, 153, 0);//

   glVertex2f(-100.0f, -68.0f);
	glVertex2f(-86.0f,-68.0f);
	glVertex2f(-93.0f, -60.0f);
	glEnd();

	 glBegin(GL_TRIANGLES);//
    glColor3ub(0, 204, 0);//

   glVertex2f(-99.0f, -63.0f);
	glVertex2f(-87.0f,-63.0f);
	glVertex2f(-93.0f, -55.0f);
	glEnd();

	glBegin(GL_TRIANGLES);//
    glColor3ub(0, 204, 0);//

   glVertex2f(-98.0f, -57.0f);
	glVertex2f(-88.0f,-57.0f);
	glVertex2f(-93.0f, -50.0f);
	glEnd();





	glBegin(GL_QUADS);
	glColor3ub(1,1,1);

	glVertex2f(92.0f,-74.0f);
	glVertex2f(95.0f,-74.0f);
	glVertex2f(95.0f,-68.0f);   // tree box
	glVertex2f(92.0f,-68.0f);

	glEnd();


	 glBegin(GL_TRIANGLES);//
    glColor3ub(0, 153, 0);//

   glVertex2f(100.0f, -68.0f);
	glVertex2f(86.0f,-68.0f);
	glVertex2f(93.0f, -60.0f);
	glEnd();

	 glBegin(GL_TRIANGLES);//
    glColor3ub(0, 204, 0);//

   glVertex2f(99.0f, -63.0f);
	glVertex2f(87.0f,-63.0f);
	glVertex2f(93.0f, -55.0f);
	glEnd();

	glBegin(GL_TRIANGLES);//
    glColor3ub(0, 204, 0);//

   glVertex2f(98.0f, -57.0f);
	glVertex2f(88.0f,-57.0f);
	glVertex2f(93.0f, -50.0f);
	glEnd();


	/////////////////tree 22222222222222222222222222//


	glBegin(GL_QUADS);
	glColor3ub(1,1,1);

	glVertex2f(80.0f,-60.0f);
	glVertex2f(77.0f,-60.0f);
	glVertex2f(77.0f,-54.0f);   // tree box
	glVertex2f(80.0f,-54.0f);

	glEnd();


	 glBegin(GL_TRIANGLES);//
    glColor3ub(0, 153, 0);//

   glVertex2f(85.0f, -54.0f);
	glVertex2f(72.0f,-54.0f);
	glVertex2f(78.5f, -46.0f);
	glEnd();


	 glBegin(GL_TRIANGLES);//
    glColor3ub(0, 153, 0);//

   glVertex2f(84.0f, -48.0f);
	glVertex2f(73.0f,-48.0f);
	glVertex2f(78.5f, -40.0f);
	glEnd();
}

void treeboxLeft()
{

	glBegin(GL_QUADS);
	glColor3ub(1,1,1);

	glVertex2f(-80.0f,-60.0f);
	glVertex2f(-77.0f,-60.0f);
	glVertex2f(-77.0f,-54.0f);   // tree box
	glVertex2f(-80.0f,-54.0f);

	glEnd();


	 glBegin(GL_TRIANGLES);//
    glColor3ub(0, 153, 0);//

   glVertex2f(-85.0f, -54.0f);
	glVertex2f(-72.0f,-54.0f);
	glVertex2f(-78.5f, -46.0f);
	glEnd();


	 glBegin(GL_TRIANGLES);//
    glColor3ub(0, 153, 0);//

   glVertex2f(-84.0f, -48.0f);
	glVertex2f(-73.0f,-48.0f);
	glVertex2f(-78.5f, -40.0f);
	glEnd();
}

void  tower()
{




	////////////////mondir//////////

	glBegin(GL_QUADS);
	glColor3ub(1,1,1);

	glVertex2f(99.0f,10.0f);
	glVertex2f(106.0f,10.0f);
	glVertex2f(106.0f,35.0f);   // mondir
	glVertex2f(99.0f,35.0f);

	glEnd();

	glBegin(GL_QUADS);
	glColor3ub(1,1,1);

	glVertex2f(96.0f,35.0f);
	glVertex2f(96.0f,39.0f);
	glVertex2f(109.0f,39.0f);   // mondir box
	glVertex2f(109.0f,35.0f);

	glEnd();


	 glBegin(GL_TRIANGLES);//
    glColor3ub(0, 153, 0);//

   glVertex2f(98.0f, 39.0f);
	glVertex2f(102.0f,50.0f);
	glVertex2f(107.f, 39.0f);
	glEnd();
}
void leftLastBuilding()
{


	//////left last building//////


	glBegin(GL_QUADS);
	glColor3ub(1,1,1);

	glVertex2f(-96.0f,10.0f);
	glVertex2f(-96.0f,45.0f);
	glVertex2f(-108.0f,45.0f);
	glVertex2f(-108.0f,10.0f);

	glEnd();


	glBegin(GL_QUADS);
	glColor3ub(255,255,255);

	glVertex2f(-98.0f,13.0f);
	glVertex2f(-98.0f,17.0f);
	glVertex2f(-101.0f,17.0f);
	glVertex2f(-101.0f,13.0f);

	glEnd();


	glBegin(GL_QUADS);
	glColor3ub(255,255,255);

	glVertex2f(-98.0f,20.0f);
	glVertex2f(-98.0f,24.0f);
	glVertex2f(-101.0f,24.0f);
	glVertex2f(-101.0f,20.0f);

	glEnd();


	glBegin(GL_QUADS);
	glColor3ub(255,255,255);

	glVertex2f(-98.0f,27.0f);
	glVertex2f(-98.0f,31.0f);
	glVertex2f(-101.0f,31.0f);
	glVertex2f(-101.0f,27.0f);

	glEnd();

	glBegin(GL_QUADS);
	glColor3ub(255,255,255);

	glVertex2f(-98.0f,34.0f);
	glVertex2f(-98.0f,38.0f);
	glVertex2f(-101.0f,38.0f);
	glVertex2f(-101.0f,34.0f);

	glEnd();


	glBegin(GL_QUADS);
	glColor3ub(255,255,255);

	glVertex2f(-104.0f,13.0f);
	glVertex2f(-104.0f,17.0f);
	glVertex2f(-107.0f,17.0f);
	glVertex2f(-107.0f,13.0f);

	glEnd();


	glBegin(GL_QUADS);
	glColor3ub(255,255,255);

	glVertex2f(-104.0f,20.0f);
	glVertex2f(-104.0f,24.0f);
	glVertex2f(-107.0f,24.0f);
	glVertex2f(-107.0f,20.0f);

	glEnd();


	glBegin(GL_QUADS);
	glColor3ub(255,255,255);

	glVertex2f(-104.0f,27.0f);
	glVertex2f(-104.0f,31.0f);
	glVertex2f(-107.0f,31.0f);
	glVertex2f(-107.0f,27.0f);

	glEnd();

	glBegin(GL_QUADS);
	glColor3ub(255,255,255);

	glVertex2f(-104.0f,34.0f);
	glVertex2f(-104.0f,38.0f);
	glVertex2f(-107.0f,38.0f);
	glVertex2f(-107.0f,34.0f);

	glEnd();


	 glBegin(GL_TRIANGLES);//
    glColor3ub(255,255,255);//

   glVertex2f(-100.0f, 40.0f);
	glVertex2f(-102.5f,44.0f);
	glVertex2f(-105.0f, 40.0f);
	glEnd();
}


void cloud()
{


glPushMatrix();
glTranslatef(position,0,0);
	/////////////ssskkkkyyyyy///////
	circleSolid(65.0f,80.0f,5.0f);
	circleSolid(62.0f,80.0f,5.0f);
	circleSolid(63.5f,85.0f,2.5f);
	circleSolid(63.5f,75.0f,2.5f);
	////2nd cloud

	circleSolid(-65.0f,80.0f,5.0f);
	circleSolid(-62.0f,80.0f,5.0f);
	circleSolid(-63.5f,85.0f,2.5f);
	circleSolid(-63.5f,75.0f,2.5f);

	/////cloud 3
	circleSolid(-95.0f,90.0f,5.0f);
	circleSolid(-92.0f,90.0f,5.0f);
	circleSolid(-93.5f,95.0f,2.5f);
	circleSolid(-93.5f,85.0f,2.5f);


	circleSolid(-35.0f,80.0f,5.0f);
	circleSolid(-32.0f,80.0f,5.0f);
	circleSolid(-33.5f,85.0f,2.5f);
	circleSolid(-33.5f,75.0f,2.5f);

	circleSolid(2.0f,95.0f,5.0f);
	circleSolid(-1.0f,95.0f,5.0f);
	circleSolid(0.0f,100.0f,2.5f);
	circleSolid(0.0f,90.0f,2.5f);

	circleSolid(35.0f,80.0f,5.0f);
	circleSolid(32.0f,80.0f,5.0f);
	circleSolid(33.5f,85.0f,2.5f);
	circleSolid(33.5f,75.0f,2.5f);

	glPopMatrix();

}







void TreeBigLeft()
{




    /* tree  left */
    glBegin(GL_QUADS);
    glColor3ub(92, 92, 61);
    glVertex2f(-108.0f,-160.0f);
    glVertex2f(-103.0f,-160.0f);
    glVertex2f(-103.0f,-110.0f);
    glVertex2f(-108.0f,-110.0f);
    glEnd();

    glLineWidth(8);
    glBegin(GL_LINES);        //left
    glColor3ub(92, 92, 61);
    glVertex2f(-105.0f, -110.0f);
    glVertex2f(-100.0f, -107.0f);
    glEnd();
    glColor3ub(0, 77, 0);
    circleSolid(-98.0f, -105.f, 4);
    glColor3ub(0, 102, 0);
    circleSolid(-100.0f, -103.f, 4);
    glColor3ub(0, 128, 0);
    circleSolid(-100.0f, -100.f, 4);

    glLineWidth(8);
    glBegin(GL_LINES);        //middle
    glColor3ub(92, 92, 61);
    glVertex2f(-106.0f, -110.0f);
    glVertex2f(-106.0f, -91.0f);
    glEnd();

    glColor3ub(0, 77, 0);
    circleSolid(-106.0f, -91.0f, 4);
    glColor3ub(0, 102, 0);
    circleSolid(-103.0f, -90.0f, 3);
    glColor3ub(0, 128, 0);
    circleSolid(-108.0f, -88.0f, 5);

    glLineWidth(8);
    glBegin(GL_LINES);        //right
    glColor3ub(92, 92, 61);
    glVertex2f(-108.0f, -110.0f);
    glVertex2f(-115.0f, -104.0f);
    glEnd();

    glColor3ub(0, 77, 0);
    circleSolid(-115.0f, -104.0f, 4);
    glColor3ub(0, 128, 0);
    circleSolid(-113.0f, -102.0f, 2);

}

void TreeBigright()
{


    /* tree  right */
    glBegin(GL_QUADS);
    glColor3ub(92, 92, 61);
    glVertex2f(108.0f,-160.0f);
    glVertex2f(103.0f,-160.0f);
    glVertex2f(103.0f,-110.0f);
    glVertex2f(108.0f,-110.0f);
    glEnd();

    glLineWidth(8);
    glBegin(GL_LINES);        //left
    glColor3ub(92, 92, 61);
    glVertex2f(105.0f, -110.0f);
    glVertex2f(100.0f, -107.0f);
    glEnd();
    glColor3ub(0, 77, 0);
    circleSolid(98.0f, -105.f, 4);
    glColor3ub(0, 102, 0);
    circleSolid(100.0f, -103.f, 4);
    glColor3ub(0, 128, 0);
    circleSolid(100.0f, -100.f, 4);

    glLineWidth(8);
    glBegin(GL_LINES);        //middle
    glColor3ub(92, 92, 61);
    glVertex2f(106.0f, -110.0f);
    glVertex2f(106.0f, -91.0f);
    glEnd();

    glColor3ub(0, 77, 0);
    circleSolid(106.0f, -91.0f, 4);
    glColor3ub(0, 102, 0);
    circleSolid(103.0f, -90.0f, 3);
    glColor3ub(0, 128, 0);
    circleSolid(108.0f, -88.0f, 5);

    glLineWidth(8);
    glBegin(GL_LINES);        //right
    glColor3ub(92, 92, 61);
    glVertex2f(108.0f, -110.0f);
    glVertex2f(115.0f, -104.0f);
    glEnd();

    glColor3ub(0, 77, 0);
    circleSolid(115.0f, -104.0f, 4);
    glColor3ub(0, 128, 0);
    circleSolid(113.0f, -102.0f, 2);

}
 void BackgroundNight()
 {

    glBegin(GL_QUADS); ///////////////////////bakground white////////////////////////////////////////////
    glColor3ub(128, 102, 0);
    glVertex2f(-115.0f,-5.0f);
    glVertex2f(120.0f,-5.0f);
    glVertex2f(120.0f,-160.0f);
    glVertex2f(-115.0f,-160.0f);
    glEnd();
 }

void SkyNight()
{


     glBegin(GL_QUADS);
	glColor3ub(26, 26, 26);
	glVertex2f(-115.0f, -5.0f);
	glVertex2f(-115.0f, 60.0f);  //sky 1
	glVertex2f(120.0f, 60.0f);
	glVertex2f(120.0f, -5.0f);

	glEnd();

	 glBegin(GL_QUADS);
	glColor3ub(13, 13, 13);

	glVertex2f(-115.0f, 60.0f);
	glVertex2f(-115.0f, 80.0f);  //sky2
	glVertex2f(120.0f, 80.0f);
	glVertex2f(120.0f, 60.0f);

	glEnd();

	glBegin(GL_QUADS);
	glColor3ub(0, 0, 0);

	glVertex2f(-115.0f, 80.0f);
	glVertex2f(-115.0f, 100.0f);  //sky 3
	glVertex2f(120.0f, 100.0f);
	glVertex2f(120.0f, 80.0f);

	glEnd();

	glBegin(GL_QUADS);
	glColor3ub(0, 0, 0);

	glVertex2f(-115.0f, 100.0f);
	glVertex2f(-115.0f, 120.0f);  //sky 4
	glVertex2f(120.0f, 120.0f);
	glVertex2f(120.0f, 100.0f);

	glEnd();
}
 void lkNight()
 {



    glBegin(GL_QUADS);
	glColor3ub(255, 102, 102);

	glVertex2f(-25.0f, 0.0f);
	glVertex2f(-25.0f, 44.0f);  // middle box
	glVertex2f(25.0f, 44.0f);
	glVertex2f(25.0f, 0.0f);

	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(255,255,255);

	glVertex2f(-10.0f, 0.0f);
	glVertex2f(-10.0f, 25.0f);
	glVertex2f(0.0f, 30.0f);   // middle back door
	glVertex2f(10.0f, 25.0f);
	glVertex2f(10.0f, 0.0f);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub(255, 102, 102);
	glVertex2f(-25.0f, 0.0f);
	glVertex2f(-55.0f, 0.0f);
	glVertex2f(-55.0f, 40.0f);   // Left box
	glVertex2f(-25.0f, 40.0f);
	glEnd();


	glBegin(GL_QUADS);
	glColor3ub(255, 102, 102);
	glVertex2f(25.0f, 0.0f);
	glVertex2f(55.0f, 0.0f);
	glVertex2f(55.0f, 40.0f);   // Right box
	glVertex2f(25.0f, 40.0f);
	glEnd();


	glBegin(GL_POLYGON);
	glColor3ub(255,255,255);
	glVertex2f(-33.0f, 0.0f);
	glVertex2f(-47.0f, 0.0f);
	glVertex2f(-47.0f, 21.0f);
	glVertex2f(-40.0f, 25.0f);   // left back door
	glVertex2f(-33.0f, 21.0f);

	glEnd();



	glBegin(GL_POLYGON);
	glColor3ub(255,255,255);

	glVertex2f(33.0f, 0.0f);
	glVertex2f(47.0f, 0.0f);
	glVertex2f(47.0f, 21.0f);
	glVertex2f(40.0f, 25.0f);   // Right back door
	glVertex2f(33.0f, 21.0f);

	glEnd();


	glBegin(GL_POLYGON);
	glColor3ub(255, 153, 0);

	glVertex2f(-4.0f, 0.0f);
	glVertex2f(-4.0f, 15.0f);
	glVertex2f(0.0f, 18.0f);
	glVertex2f(4.0f, 15.0f);   // middle door
	glVertex2f(4.0f, 0.0f);

	glEnd();




	glBegin(GL_QUADS);
	glColor3ub(255, 153, 0);

	glVertex2f(-37.0f, 0.0f);
	glVertex2f(-43.0f, 0.0f);
	glVertex2f(-43.0f, 15.0f);   // left door
    glVertex2f(-37.0f, 15.0f);

	glEnd();

	    glBegin(GL_TRIANGLES);//
    glColor3ub(255, 153, 0);//    left door uper small triangle

    glVertex2f(-38.0f,17.0f);    // x, y
	glVertex2f(-42.0f,17.0f);
	glVertex2f(-40.0f, 20.0f);
	glEnd();



	glBegin(GL_QUADS);
	glColor3ub(255, 153, 0);

	glVertex2f(37.0f, 0.0f);
	glVertex2f(43.0f, 0.0f);
	glVertex2f(43.0f, 15.0f);   // Right door
    glVertex2f(37.0f, 15.0f);

	glEnd();


	 glBegin(GL_TRIANGLES);//
    glColor3ub(255, 153, 0);//    Right door uper small triangle

    glVertex2f(38.0f,17.0f);    // x, y
	glVertex2f(42.0f,17.0f);
	glVertex2f(40.0f, 20.0f);
	glEnd();



	glBegin(GL_QUADS);
	glColor3ub(255, 77, 77);

	glVertex2f(-55.0f, 0.0f);
	glVertex2f(-57.0f, -1.0f);
	glVertex2f(-57.0f, 41.0f);   // left gombuj //box 1
    glVertex2f(-55.0f, 40.0f);

	glEnd();


	glBegin(GL_QUADS);
	glColor3ub(255, 77, 77);

	glVertex2f(55.0f, 0.0f);
	glVertex2f(57.0f, -1.0f);
	glVertex2f(57.0f, 41.0f);   // Right gombuj //box 1
    glVertex2f(55.0f, 40.0f);

	glEnd();


		glBegin(GL_QUADS);
	glColor3ub(255, 102, 102);

	glVertex2f(-57.0f, -1.0f);
	glVertex2f(-63.0f, -1.0f);
	glVertex2f(-63.0f, 41.0f);   // left gombuj //box 2
    glVertex2f(-57.0f, 41.0f);

	glEnd();


	glBegin(GL_QUADS);
	glColor3ub(255, 102, 102);

	glVertex2f(57.0f, -1.0f);
	glVertex2f(63.0f, -1.0f);
	glVertex2f(63.0f, 41.0f);   // Right gombuj //box 2
    glVertex2f(57.0f, 41.0f);

	glEnd();


	glBegin(GL_QUADS);
	glColor3ub(255, 77, 77);


	glVertex2f(-63.0f, -1.0f);
	glVertex2f(-65.0f, 0.0f); // left gombuj //box 3
    glVertex2f(-65.0f, 40.0f);
    glVertex2f(-63.0f, 41.0f);

	glEnd();

	glBegin(GL_QUADS);
	glColor3ub(255, 77, 77);


	glVertex2f(63.0f, -1.0f);
	glVertex2f(65.0f, 0.0f); // Right gombuj //box 3
    glVertex2f(65.0f, 40.0f);
    glVertex2f(63.0f, 41.0f);

	glEnd();


	glBegin(GL_POLYGON);
	glColor3ub(198, 83, 83);

	glVertex2f(-57.0f, 41.0f);
	glVertex2f(-63.0f, 41.0f);
	glVertex2f(-55.0f, 40.0f);
	glVertex2f(-55.0f, 44.0f);
	glVertex2f(-65.0f, 44.0f);
	glVertex2f(-65.0f, 40.0f);   // left piller up 1



	glEnd();

	glBegin(GL_QUADS);
	glColor3ub(255, 77, 77);


	glVertex2f(-56.0f, 44.0f);
	glVertex2f(-64.0f, 44.0f); // left piller up 2
    glVertex2f(-64.0f, 50.0f);
    glVertex2f(-56.0f, 50.0f);

	glEnd();


	glBegin(GL_QUADS);
	glColor3ub(1,1,1);


	glVertex2f(-54.0f, 50.0f);
	glVertex2f(-66.0f, 50.0f); // left piller up 3
    glVertex2f(-66.0f, 51.0f);
    glVertex2f(-54.0f, 51.0f);

	glEnd();


	glBegin(GL_POLYGON);
	glColor3ub(198, 83, 83);

	glVertex2f(57.0f, 41.0f);
	glVertex2f(63.0f, 41.0f);
	glVertex2f(55.0f, 40.0f);
	glVertex2f(55.0f, 44.0f);
	glVertex2f(65.0f, 44.0f);
	glVertex2f(65.0f, 40.0f);   // right piller up 1



	glEnd();

	glBegin(GL_QUADS);
	glColor3ub(255, 77, 77);


	glVertex2f(56.0f, 44.0f);
	glVertex2f(64.0f, 44.0f); // right piller up 2
    glVertex2f(64.0f, 50.0f);
    glVertex2f(56.0f, 50.0f);

	glEnd();


	glBegin(GL_QUADS);
	glColor3ub(1,1,1);


	glVertex2f(54.0f, 50.0f);
	glVertex2f(66.0f, 50.0f); // right piller up 3
    glVertex2f(66.0f, 51.0f);
    glVertex2f(54.0f, 51.0f);

	glEnd();

	glBegin(GL_QUADS);
	glColor3ub(198, 83, 83);


	glVertex2f(-55.0f, 40.0f);
	glVertex2f(-55.0f, 44.0f); // left uper box
    glVertex2f(-25.0f, 44.0f);
    glVertex2f(-25.0f, 40.0f);

	glEnd();

	glBegin(GL_QUADS);
	glColor3ub(198, 83, 83);


	glVertex2f(-25.0f, 44.0f);
	glVertex2f(-29.0f, 44.0f); // left uper box 2
    glVertex2f(-29.0f, 50.0f);
    glVertex2f(-25.0f, 50.0f);

	glEnd();


	glBegin(GL_QUADS);
	glColor3ub(198, 83, 83);


	glVertex2f(-25.0f, 44.0f);
	glVertex2f(-25.0f, 50.0f); // middle box
    glVertex2f(25.0f, 50.0f);
    glVertex2f(25.0f, 44.0f);

	glEnd();

	glBegin(GL_QUADS);
	glColor3ub(198, 83, 83);


	glVertex2f(55.0f, 40.0f);
	glVertex2f(55.0f, 44.0f); // right uper box
    glVertex2f(25.0f, 44.0f);
    glVertex2f(25.0f, 40.0f);

	glEnd();

	glBegin(GL_QUADS);
	glColor3ub(198, 83, 83);


	glVertex2f(25.0f, 44.0f);
	glVertex2f(29.0f, 44.0f); // right uper box 2
    glVertex2f(29.0f, 50.0f);
    glVertex2f(25.0f, 50.0f);

	glEnd();




    glLineWidth(7.5);
	glBegin(GL_LINES);

	glColor3ub(102, 0, 0);
	glVertex2f(-55.0f, 40.0f);
    glVertex2f(-25.0f, 40.0f);

	glEnd();

	glLineWidth(7.5);
	glBegin(GL_LINES);

	glColor3ub(102, 0, 0);

    glVertex2f(-25.0f, 40.0f);
    glVertex2f(-25.0f, 44.0f);

	glEnd();

	glLineWidth(7.5);
	glBegin(GL_LINES);

	glColor3ub(102, 0, 0);

    glVertex2f(-25.0f, 44.0f);
    glVertex2f(25.0f, 44.0f);

	glEnd();

	glLineWidth(7.5);
	glBegin(GL_LINES);

	glColor3ub(102, 0, 0);

    glVertex2f(25.0f, 40.0f);
    glVertex2f(25.0f, 44.0f);

	glEnd();

	 glLineWidth(7.5);
	glBegin(GL_LINES);

	glColor3ub(102, 0, 0);
	glVertex2f(55.0f, 40.0f);
    glVertex2f(25.0f, 40.0f);

	glEnd();

	glBegin(GL_QUADS);
	glColor3ub(198, 83, 83);


	glVertex2f(21.0f, 0.0f);
	glVertex2f(23.0f, 0.0f); // right small pillar
    glVertex2f(23.0f, 53.0f);
    glVertex2f(21.0f, 53.0f);

	glEnd();

	glBegin(GL_QUADS);
	glColor3ub(198, 83, 83);


	glVertex2f(-21.0f, 0.0f);
	glVertex2f(-23.0f, 0.0f); // left small pillar
    glVertex2f(-23.0f, 53.0f);
    glVertex2f(-21.0f, 53.0f);

	glEnd();
////////////////////tupi//////////////////////
	glBegin(GL_TRIANGLES);//
    glColor3ub(0, 0, 0);//    tupi

    glVertex2f(-59.0f,55.0f);    // x, y
	glVertex2f(-61.0f,55.0f);
	glVertex2f(-60.0f, 60.0f);
	glEnd();

	glColor3ub(198, 83, 83);

     int i;

	GLfloat x=-60.0f; GLfloat y=51.0f; GLfloat radius =5.0f;
	int triangleAmount = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi = 1.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
/////////////////////tupi//////////////////////right
	glBegin(GL_TRIANGLES);//
    glColor3ub(0, 0, 0);//    tupi

    glVertex2f(59.0f,55.0f);    // x, y
	glVertex2f(61.0f,55.0f);
	glVertex2f(60.0f, 60.0f);
	glEnd();


glColor3ub(198, 83, 83);
	int j;

	 x=60.0f;  y=51.0f;  radius =5.0f;
	int triangleAmount1 = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	 twicePi = 1.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(j = 0; j <= triangleAmount;j++) {
			glVertex2f(
		            x + (radius * cos(j *  twicePi / triangleAmount)),
			    y + (radius * sin(j * twicePi / triangleAmount))
			);
		}
	glEnd();


////////////////////////middle tupi/////////////////////
glBegin(GL_TRIANGLES);//
    glColor3ub(0, 0, 0);//    tupi

    glVertex2f(-4.0f,63.0f);    // x, y
	glVertex2f(4.0f,63.0f);
	glVertex2f(0.0f, 72.0f);
	glEnd();
glColor3ub(153,0,0);
int k;

	 x=0.0f;  y=50.0f;  radius =15.0f;
	int triangleAmount3 = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	 twicePi = 1.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(k = 0; k <= triangleAmount;k++) {
			glVertex2f(
		            x + (radius * cos(k *  twicePi / triangleAmount)),
			    y + (radius * sin(k * twicePi / triangleAmount))
			);
		}
	glEnd();


	int l;

	 x=22.0f;  y=53.0f;  radius =1.50f;
	int triangleAmount4 = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	 twicePi = 1.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(l = 0; l <= triangleAmount;l++) {
			glVertex2f(
		            x + (radius * cos(l *  twicePi / triangleAmount)),
			    y + (radius * sin(l * twicePi / triangleAmount))
			);
		}
	glEnd();


	int m;

	 x=-22.0f;  y=53.0f;  radius =1.50f;
	int triangleAmount5 = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	 twicePi = 1.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(m = 0; m <= triangleAmount;m++) {
			glVertex2f(
		            x + (radius * cos(m *  twicePi / triangleAmount)),
			    y + (radius * sin(m * twicePi / triangleAmount))
			);
		}
	glEnd();


	glBegin(GL_QUADS);
	glColor3ub(0,0,0);


	glVertex2f(-55.0f, 0.0f);
	glVertex2f(-55.0f,-1.0f); // down border 1/////////
    glVertex2f(55.0f, -1.0f);
    glVertex2f(55.0f, 0.0f);

	glEnd();

	glBegin(GL_QUADS);
	glColor3ub(191, 64, 64);


	glVertex2f(-65.0f, -1.0f);
	glVertex2f(-65.0f,-5.0f); // down border 2/////////
    glVertex2f(65.0f, -5.0f);
    glVertex2f(65.0f, -1.0f);

	glEnd();
 }
 void grassNight()
 {


    /* grass */
    glBegin(GL_QUADS);
    glColor3ub(0, 77, 0);
    glVertex2f(-15.0f, -5.0f);
    glVertex2f(-90.0f, -160.0f);
    glVertex2f(-115.0f, -160.0f);
    glVertex2f(-115.0f, -5.0f);
    glEnd();


    /* right  side */

        glBegin(GL_QUADS);
    glColor3ub(0, 77, 0);
    glVertex2f(15.0f, -5.0f);
    glVertex2f(90.0f, -160.0f);
    glVertex2f(120.0f, -160.0f);
    glVertex2f(120.0f, -5.0f);
    glEnd();

 }






void RoadNight()
{



	glBegin(GL_QUADS);
	glColor3ub(0,0,0);
	glVertex2f(-2.0f, -15.0f);
	glVertex2f(-2.0f, -19.0f); // road middle
    glVertex2f(2.0f, -19.0f);
    glVertex2f(2.0f, -15.0f);
	glEnd();


	glBegin(GL_QUADS);
	glColor3ub(0,0,0);
	glVertex2f(-2.0f, -23.0f);
	glVertex2f(-2.0f, -28.0f); // road 2 middle
    glVertex2f(2.0f, -28.0f);
    glVertex2f(2.0f, -23.0f);
	glEnd();


	glBegin(GL_QUADS);
	glColor3ub(0,0,0);
	glVertex2f(-2.0f, -34.0f);
	glVertex2f(-2.0f, -43.0f); // road 3 middle
    glVertex2f(2.0f, -43.0f);
    glVertex2f(2.0f, -34.0f);
	glEnd();


	glBegin(GL_QUADS);
	glColor3ub(0,0,0);
	glVertex2f(-2.0f, -54.0f);
	glVertex2f(-2.0f, -69.0f); // road 4 middle
    glVertex2f(2.0f, -69.0f);
    glVertex2f(2.0f, -54.0f);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub(0,0,0);
	glVertex2f(-2.0f, -85.0f);
	glVertex2f(-2.0f, -120.0f); // road 5 middle
    glVertex2f(2.0f, -120.0f);
    glVertex2f(2.0f, -85.0f);
	glEnd();


	glBegin(GL_QUADS);
	glColor3ub(107, 107, 71);
	glVertex2f(70.0f, 10.0f);
	glVertex2f(80.0f, 10.0f);
	glVertex2f(80.0f, 30.0f);   // Right building 1
	glVertex2f(70.0f, 30.0f);
	glEnd();
}

void Right1stBuildingNiight()
{

glBegin(GL_QUADS);
	glColor3ub(255, 153, 0);

	glVertex2f(71.0f, 13.0f);
	glVertex2f(74.0f, 13.0f);
	glVertex2f(74.0f, 18.0f);   // Right building 1 window
	glVertex2f(71.0f, 18.0f);

	glEnd();

	glBegin(GL_QUADS);
	glColor3ub(255, 153, 0);

	glVertex2f(76.0f, 13.0f);
	glVertex2f(79.0f, 13.0f);
	glVertex2f(79.0f, 18.0f);   // Right building 1 window
	glVertex2f(76.0f, 18.0f);

	glEnd();
}




void left1stBuildingNight()
{


	glBegin(GL_QUADS);
	glColor3ub(1,1,1);

	glVertex2f(-70.0f, 10.0f);
	glVertex2f(-80.0f, 10.0f);
	glVertex2f(-80.0f, 30.0f);   // left building 1
	glVertex2f(-70.0f, 30.0f);

	glEnd();


	glBegin(GL_QUADS);
	glColor3ub(255, 153, 0);

	glVertex2f(-71.0f, 13.0f);
	glVertex2f(-74.0f, 13.0f);
	glVertex2f(-74.0f, 18.0f);   // left building 1 window
	glVertex2f(-71.0f, 18.0f);

	glEnd();

	glBegin(GL_QUADS);
	glColor3ub(255, 153, 0);

	glVertex2f(-76.0f, 13.0f);
	glVertex2f(-79.0f, 13.0f);
	glVertex2f(-79.0f, 18.0f);   // left building 1 window
	glVertex2f(-76.0f, 18.0f);

	glEnd();

}
void Left2ndBuildingNight()
{

	glBegin(GL_QUADS);
	glColor3ub(255, 153, 0);

	glVertex2f(-71.0f, 22.0f);
	glVertex2f(-74.0f, 22.0f);
	glVertex2f(-74.0f, 27.0f);   // left building 2 window
	glVertex2f(-71.0f, 27.0f);

	glEnd();


	glBegin(GL_QUADS);
	glColor3ub(255, 153, 0);

	glVertex2f(-76.0f, 22.0f);
	glVertex2f(-79.0f, 22.0f);
	glVertex2f(-79.0f, 27.0f);   // left building 2 window
	glVertex2f(-76.0f, 27.0f);

	glEnd();
}

void Right2ndBuildingNight()
{

    	glBegin(GL_QUADS);
	glColor3ub(255, 153, 0);

	glVertex2f(71.0f, 22.0f);
	glVertex2f(74.0f, 22.0f);
	glVertex2f(74.0f, 27.0f);   // Right building 2 window
	glVertex2f(71.0f, 27.0f);

	glEnd();


	glBegin(GL_QUADS);
	glColor3ub(255, 153, 0);

	glVertex2f(76.0f, 22.0f);
	glVertex2f(79.0f, 22.0f);
	glVertex2f(79.0f, 27.0f);   // Right building 2 window
	glVertex2f(76.0f, 27.0f);

	glEnd();

/////////////////////building 2222222222222222222//////////////////////
	glBegin(GL_QUADS);
	glColor3ub(179, 0, 0);

	glVertex2f(82.0f, 10.0f);
	glVertex2f(95.0f, 10.0f);
	glVertex2f(95.0f, 40.0f);   // Right building 2
	glVertex2f(82.0f, 40.0f);

	glEnd();


	glBegin(GL_QUADS);
	glColor3ub(255, 153, 0);

	glVertex2f(83.0f, 13.0f);
	glVertex2f(87.0f, 13.0f);
	glVertex2f(87.0f, 18.0f);   // Right building 2 window
	glVertex2f(83.0f, 18.0f);

	glEnd();


	glBegin(GL_QUADS);
	glColor3ub(255, 153, 0);

	glVertex2f(90.0f, 13.0f);
	glVertex2f(94.0f, 13.0f);
	glVertex2f(94.0f, 18.0f);   // Right building 2 window
	glVertex2f(90.0f, 18.0f);

	glEnd();


	glBegin(GL_QUADS);
	glColor3ub(255, 153, 0);

	glVertex2f(83.0f, 22.0f);
	glVertex2f(87.0f, 22.0f);
	glVertex2f(87.0f, 27.0f);   // Right building 2 window
	glVertex2f(83.0f, 27.0f);

	glEnd();


	glBegin(GL_QUADS);
	glColor3ub(255, 153, 0);

	glVertex2f(90.0f, 22.0f);
	glVertex2f(94.0f, 22.0f);
	glVertex2f(94.0f, 27.0f);   // Right building 2 window
	glVertex2f(90.0f, 27.0f);

	glEnd();


	glBegin(GL_QUADS);
	glColor3ub(255, 153, 0);

	glVertex2f(83.0f, 31.0f);
	glVertex2f(87.0f, 31.0f);
	glVertex2f(87.0f, 36.0f);   // Right building 2 window   3 3 3
	glVertex2f(83.0f, 36.0f);

	glEnd();


	glBegin(GL_QUADS);
	glColor3ub(255, 153, 0);

	glVertex2f(90.0f, 31.0f);
	glVertex2f(94.0f, 31.0f);
	glVertex2f(94.0f, 36.0f);   // Right building 2 window
	glVertex2f(90.0f, 36.0f);

	glEnd();


	glLineWidth(3);
	glBegin(GL_LINES);

	glColor3ub(102, 0, 0);
	glVertex2f(88.5f, 11.0f);
    glVertex2f(88.5f, 38.0f);  // building line

	glEnd();


	glBegin(GL_QUADS);
	glColor3ub(179, 0, 0);

	glVertex2f(-82.0f, 10.0f);
	glVertex2f(-95.0f, 10.0f);
	glVertex2f(-95.0f, 40.0f);   // left building 2
	glVertex2f(-82.0f, 40.0f);

	glEnd();


	glBegin(GL_QUADS);
	glColor3ub(255, 153, 0);

	glVertex2f(-83.0f, 13.0f);
	glVertex2f(-87.0f, 13.0f);
	glVertex2f(-87.0f, 18.0f);   // Right building 2 window
	glVertex2f(-83.0f, 18.0f);

	glEnd();


	glBegin(GL_QUADS);
	glColor3ub(255, 153, 0);

	glVertex2f(-90.0f, 13.0f);
	glVertex2f(-94.0f, 13.0f);
	glVertex2f(-94.0f, 18.0f);   // Right building 2 window
	glVertex2f(-90.0f, 18.0f);

	glEnd();


	glBegin(GL_QUADS);
	glColor3ub(255, 153, 0);

	glVertex2f(-83.0f, 22.0f);
	glVertex2f(-87.0f, 22.0f);
	glVertex2f(-87.0f, 27.0f);   // Right building 2 window
	glVertex2f(-83.0f, 27.0f);

	glEnd();


	glBegin(GL_QUADS);
	glColor3ub(255, 153, 0);

	glVertex2f(-90.0f, 22.0f);
	glVertex2f(-94.0f, 22.0f);
	glVertex2f(-94.0f, 27.0f);   // Right building 2 window
	glVertex2f(-90.0f, 27.0f);

	glEnd();


	glBegin(GL_QUADS);
	glColor3ub(255, 153, 0);

	glVertex2f(-83.0f, 31.0f);
	glVertex2f(-87.0f, 31.0f);
	glVertex2f(-87.0f, 36.0f);   // Right building 2 window   3 3 3
	glVertex2f(-83.0f, 36.0f);

	glEnd();


	glBegin(GL_QUADS);
	glColor3ub(255, 153, 0);

	glVertex2f(-90.0f, 31.0f);
	glVertex2f(-94.0f, 31.0f);
	glVertex2f(-94.0f, 36.0f);   // Right building 2 window
	glVertex2f(-90.0f, 36.0f);

	glEnd();


	glLineWidth(3);
	glBegin(GL_LINES);

	glColor3ub(102, 0, 0);
	glVertex2f(-88.5f, 11.0f);
    glVertex2f(-88.5f, 38.0f);  // building line

	glEnd();

}
	void towerNight()
	{


	////////////////mondir//////////

	glBegin(GL_QUADS);
	glColor3ub(1,1,1);

	glVertex2f(99.0f,10.0f);
	glVertex2f(106.0f,10.0f);
	glVertex2f(106.0f,35.0f);   // mondir
	glVertex2f(99.0f,35.0f);

	glEnd();

	glBegin(GL_QUADS);
	glColor3ub(1,1,1);

	glVertex2f(96.0f,35.0f);
	glVertex2f(96.0f,39.0f);
	glVertex2f(109.0f,39.0f);   // mondir box
	glVertex2f(109.0f,35.0f);

	glEnd();


	 glBegin(GL_TRIANGLES);//
    glColor3ub(255, 153, 0);//

   glVertex2f(98.0f, 39.0f);
	glVertex2f(102.0f,50.0f);
	glVertex2f(107.f, 39.0f);
	glEnd();

	//////left last building//////

	}
	void LeftLastbuilding()
	{




	glBegin(GL_QUADS);
	glColor3ub(1,1,1);

	glVertex2f(-96.0f,10.0f);
	glVertex2f(-96.0f,45.0f);
	glVertex2f(-108.0f,45.0f);
	glVertex2f(-108.0f,10.0f);

	glEnd();


	glBegin(GL_QUADS);
	glColor3ub(255, 153, 0);

	glVertex2f(-98.0f,13.0f);
	glVertex2f(-98.0f,17.0f);
	glVertex2f(-101.0f,17.0f);
	glVertex2f(-101.0f,13.0f);

	glEnd();


	glBegin(GL_QUADS);
	glColor3ub(255, 153, 0);

	glVertex2f(-98.0f,20.0f);
	glVertex2f(-98.0f,24.0f);
	glVertex2f(-101.0f,24.0f);
	glVertex2f(-101.0f,20.0f);

	glEnd();


	glBegin(GL_QUADS);
	glColor3ub(255, 153, 0);

	glVertex2f(-98.0f,27.0f);
	glVertex2f(-98.0f,31.0f);
	glVertex2f(-101.0f,31.0f);
	glVertex2f(-101.0f,27.0f);

	glEnd();

	glBegin(GL_QUADS);
	glColor3ub(255, 153, 0);

	glVertex2f(-98.0f,34.0f);
	glVertex2f(-98.0f,38.0f);
	glVertex2f(-101.0f,38.0f);
	glVertex2f(-101.0f,34.0f);

	glEnd();


	glBegin(GL_QUADS);
	glColor3ub(255, 153, 0);

	glVertex2f(-104.0f,13.0f);
	glVertex2f(-104.0f,17.0f);
	glVertex2f(-107.0f,17.0f);
	glVertex2f(-107.0f,13.0f);

	glEnd();


	glBegin(GL_QUADS);
	glColor3ub(255, 153, 0);

	glVertex2f(-104.0f,20.0f);
	glVertex2f(-104.0f,24.0f);
	glVertex2f(-107.0f,24.0f);
	glVertex2f(-107.0f,20.0f);

	glEnd();


	glBegin(GL_QUADS);
	glColor3ub(255, 153, 0);

	glVertex2f(-104.0f,27.0f);
	glVertex2f(-104.0f,31.0f);
	glVertex2f(-107.0f,31.0f);
	glVertex2f(-107.0f,27.0f);

	glEnd();

	glBegin(GL_QUADS);
	glColor3ub(255, 153, 0);

	glVertex2f(-104.0f,34.0f);
	glVertex2f(-104.0f,38.0f);
	glVertex2f(-107.0f,38.0f);
	glVertex2f(-107.0f,34.0f);

	glEnd();


	 glBegin(GL_TRIANGLES);//
    glColor3ub(255,255,255);//

   glVertex2f(-100.0f, 40.0f);
	glVertex2f(-102.5f,44.0f);
	glVertex2f(-105.0f, 40.0f);
	glEnd();

	}


void StarNight()
{



	/////////////ssskkkkyyyyy///////
	circleSolid(70.0f,80.0f,0.50f);
	circleSolid(52.0f,80.0f,0.50f);
	circleSolid(63.5f,100.0f,0.50f);
	circleSolid(63.5f,65.0f,0.50f);
	////2nd cloud

	circleSolid(-70.0f,80.0f,0.50f);
	circleSolid(-52.0f,80.0f,0.50f);
	circleSolid(-63.5f,100.0f,0.50f);
	circleSolid(-63.5f,65.0f,0.50f);

	/////cloud 3
	circleSolid(-110.0f,90.0f,0.50f);
	circleSolid(-77.0f,100.0f,0.50f);
	circleSolid(-93.5f,95.0f,0.50f);
	circleSolid(-93.5f,85.0f,0.50f);


	circleSolid(-45.0f,100.0f,0.50f);
	circleSolid(-22.0f,80.0f,0.50f);
	circleSolid(-13.5f,95.0f,0.50f);
	circleSolid(-33.5f,65.0f,0.50f);

	circleSolid(20.0f,105.0f,0.50f);
	circleSolid(-8.0f,75.0f,0.50f);
	circleSolid(0.0f,100.0f,0.50f);
	circleSolid(0.0f,90.0f,0.50f);

	circleSolid(95.0f,95.0f,10.0f);


	circleSolid(35.0f,80.0f,0.50f);
	circleSolid(10.0f,80.0f,0.50f);
	circleSolid(33.5f,95.0f,0.50f);
	circleSolid(33.5f,65.0f,0.50f);
}

void skyEvening()
{

     glBegin(GL_QUADS);
	glColor3ub(0, 92, 230);

	glVertex2f(-115.0f, -5.0f);
	glVertex2f(-115.0f, 60.0f);  //sky 1
	glVertex2f(120.0f, 60.0f);
	glVertex2f(120.0f, -5.0f);

	glEnd();

	 glBegin(GL_QUADS);
	glColor3ub(0, 82, 204);

	glVertex2f(-115.0f, 60.0f);
	glVertex2f(-115.0f, 80.0f);  //sky2
	glVertex2f(120.0f, 80.0f);
	glVertex2f(120.0f, 60.0f);

	glEnd();

	glBegin(GL_QUADS);
	glColor3ub(0, 71, 179);

	glVertex2f(-115.0f, 80.0f);
	glVertex2f(-115.0f, 100.0f);  //sky 3
	glVertex2f(120.0f, 100.0f);
	glVertex2f(120.0f, 80.0f);

	glEnd();

	glBegin(GL_QUADS);
	glColor3ub(0, 51, 128);

	glVertex2f(-115.0f, 100.0f);
	glVertex2f(-115.0f, 120.0f);  //sky 4
	glVertex2f(120.0f, 120.0f);
	glVertex2f(120.0f, 100.0f);

	glEnd();

}






void display() {
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
              glClear(GL_COLOR_BUFFER_BIT);
              init();

            //  glutPostRedisplay();
            BackgroundDay();
                        SkyDay();


                                  sunDay();
                                    lk();


            grass();
            view3d();
            road();
            right1stbuilding();
            left2ndBuilding();
            right2ndbuilding();
            left2ndBuilding();
            treeBoxRight();
            treeboxLeft();
            tower();
            LeftLastbuilding();
            cloud();
            TreeBigLeft();
            TreeBigright();



	glFlush();


}






void night()
{
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
              glClear(GL_COLOR_BUFFER_BIT);
             // glutPostRedisplay();

   init();
   BackgroundNight();
   SkyNight();
   lkNight();

   plane();
   RoadNight();
   grass();
   view3d();


   right1stbuilding();
   right2ndbuilding();
   towerNight();
   left1stBuildingNight();
   left2ndBuilding();
   LeftLastbuilding();
   StarNight();
   treeboxLeft();
   treeBoxRight();

            TreeBigLeft();
            TreeBigright();





	glFlush();
}

void evening()
{
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
              glClear(GL_COLOR_BUFFER_BIT);
             // glutPostRedisplay();


   init();
             skyEvening();
             BackgroundNight();

   lkNight();

   //plane();
   RoadNight();
   grass();
   view3d();


   right1stbuilding();
   right2ndbuilding();
   towerNight();
   left1stBuildingNight();
   left2ndBuilding();
   LeftLastbuilding();
   StarNight();
   treeboxLeft();
   treeBoxRight();

            TreeBigLeft();
            TreeBigright();

	glFlush();



}


void handleMouse(int button, int state, int x, int y) {
	if (button == GLUT_LEFT_BUTTON){
			speed01 += 0.8f;
			}
			if (button == GLUT_RIGHT_BUTTON)
	{speed01 -= 0.8f;
			}
	glutPostRedisplay();
	}

void handleKeypress(unsigned char key, int x, int y) {

	switch (key) {



case 'd':

         //glLoadIdentity();
         glutDisplayFunc(display);
         glutPostRedisplay();

    break;

case 'n':

        // glLoadIdentity();
         glutDisplayFunc(night);
         glutPostRedisplay();

    break;

    case 'e':

        // glLoadIdentity();
         glutDisplayFunc(evening);
         glutPostRedisplay();

    break;



	}
}






int main(int argc, char** argv) {

	glutInit(&argc, argv);
	glutCreateWindow("Test");
	glutInitWindowSize(320, 320);

	glutDisplayFunc(display);
	//automatic_all_control();
	//glutIdleFunc(Idle);

	glutMouseFunc(handleMouse);
glutKeyboardFunc(handleKeypress);
   glutTimerFunc(100, update, 0);
      glutTimerFunc(100, updatesun, 0);

      glutTimerFunc(100, update01, 0);
	glutMainLoop();

	return 0;
}
