#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <math.h>
double a=0;
double b=0;
double c=0;
double d=0;
double g=0;
double t=0;
void cuadricula(int xmin, int xmax, int ymin, int ymax){
	
	glColor3f (0, 0, 0);
	glLineWidth(1);
	
	glBegin(GL_LINES);
    
    glVertex2f(0,ymin);
    glVertex2f(0,ymax);
    
    glVertex2f(xmin,0);
    glVertex2f(xmax,0);
    
    for(int i=xmin; i<=xmax; i++){
		
		glVertex2f(i,0.1);
		glVertex2f(i,-0.1);
		
		}
		
	 for(int i=ymin; i<=ymax; i++){
		
		glVertex2f(-0.1,i);
		glVertex2f(0.1,i);
		
		}
    
    glEnd();
	
	}
	
void figura(void){
	
	//glColor3f (0.294, 0.568, 0.294);
	glColor3f (0, 0, 0);
    glLineWidth(3);
    
    glBegin(GL_QUADS);
    
    glVertex2f(5,2.5);
    glVertex2f(-5,2.5);
    glVertex2f(-5,-2.5);
    glVertex2f(5,-2.5);
    
    
    glEnd();
    
    glColor3f (1, 1, 1);
    glLineWidth(3);
    
    glBegin(GL_QUADS);
    
    glVertex2f(4.95,2.45);
    glVertex2f(-4.95,2.45);
    glVertex2f(-4.95,-2.45);
    glVertex2f(4.95,-2.45);
    
    
    glEnd();
    

    glPointSize(1);
    glBegin(GL_POINTS);
    
    //Ondas producidas en (-5,0) y en (5.0)
    for (double j=-2.5; j<2.5; j+=0.01){ // Se barren todas los puntos en vertical desde (i, -2.5) hasta (i, +2.5)
			    for (double i=-5; i<5; i+=0.01){ // Se barren todas los puntos en horizontal desde (-5, j) hasta (+5, j)
				b=sqrt(pow((i+5),2) + pow(j,2)); // Esto dará la distancia desde la fuente en 1 (-5,0) hasta (i,j)
				a = (sin(4*b+0.1*t)); // Ecuación de onda debido a la  en la forma sen (kr-wt), aquí arbitrariamente k = 4 y w = 0.1
				d=sqrt(pow((i-0.4978),2) + pow(j,2)); // Esto dará la distancia desde la fuente 2 en (+0.4978,0) hasta (i,j)
				c = (sin(4*d+0.1*t)); // Ecuación de onda en la forma sen (kr-wt), aquí arbitrariamente k = 4 y w = 0.1
				g = abs ((a+c)/2); // La interferencia de ondas está dada por la suma  a+c. Se divide entre dos y se saca el valor absoluto para usar los colores RGB en el siguiente paso
				glColor3f (g, 0, (1-g)); // Esto le da color al punto (i,j). Los máximos son azul puro para cancelación de ondas y rojo puro para interferencia constructiva máxima.
				glVertex2f(i,j); 
				}
				//glEnd(); 
		}
		glEnd();
		
		
	//Onda producida en (5,0)	
    /*for (double j=-2.5; j<2.5; j+=0.15){
			    for (double i=-5; i<5; i+=0.1){
				b=sqrt((i-5)*(i-5) + j*j);
				a = abs (cos(4*b));
				glColor3f (a, a, 1);
				glVertex2f(i,j);
				}
				//glEnd();
		}
		glEnd();*/

	}

void display(void)
{
	glClearColor(1, 1, 1, 1);
    glClear (GL_COLOR_BUFFER_BIT);
    
    //cuadricula(-25, 25, -10, 10);
    
    figura();
    
    glFlush ();

}

//-------------------------------------------->

void keyboard (unsigned char key, int x, int y)
{
switch (key) {   // x,X,y,Y,z,Z uses the glRotatef() function
    case 't': // Rotates screen on x axis 
    t -= 0.5f;
    
    
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
  
    break;
}
    glutPostRedisplay(); // Redraw the scene
}

// called on special key pressed
void specialKey(int key, int x, int y) { 

// The keys below are using the gluLookAt() function for navigation
// Check which key is pressed

switch(key) {
    case GLUT_KEY_LEFT : // Rotate on x axis
    t -= 0.1f;
    break;
    case GLUT_KEY_RIGHT : // Rotate on x axis (opposite)
    t += 0.1f;
    break;
    case GLUT_KEY_UP : // Rotate on y axis 
    t += 0.1f;
    break;
    case GLUT_KEY_DOWN : // Rotate on y axis (opposite)
    t -= 0.1f;
    break; 
    case GLUT_KEY_PAGE_UP: // Rotate on z axis
    t -= 0.1f;
    break;
    case GLUT_KEY_PAGE_DOWN:// Rotate on z axis (opposite)
    t += 0.1f;
    break;
}
    glutPostRedisplay(); // Redraw the scene
}










//--------------------------------------------->

void init (void)
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-10, 10, -10, 10, -10, 10);

}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize (900, 750);
    glutInitWindowPosition (100, 100);
    glutCreateWindow ("EJERCICIO 1");
    init ();
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard); // set window's key callback
    glutMainLoop();
    return 0;
}
