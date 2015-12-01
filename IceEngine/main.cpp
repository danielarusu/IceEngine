#include "global.includes.h"
#include "obj.struct.h"
#include "global.utils.h"

#include "Object3D.h"
#include "RenderManager.h"
#include "Vector3D.h"
#include "CameraManager.h"

Camera g_Camera;
bool* keyStates = new bool[256];
int mainWindow;

void renderWindow(){
	glClearColor(0, 0, 0, 0);
}

void keyPressed(unsigned char key, int x, int y) {
	if (key == 'w' || key == 'W') { // If the 'w' key has been pressed  
		g_Camera.moveCamera(0.02);
		glTranslatef(g_Camera.c_vPosition.getXcoord(), g_Camera.c_vPosition.getYcoord(), g_Camera.c_vPosition.getZcoord());
		printf("camX = %f, camY = %f, camZ = %f\n", g_Camera.c_vPosition.getXcoord(), g_Camera.c_vPosition.getYcoord(), g_Camera.c_vPosition.getZcoord());
	}

	if (key == 's' || key == 'S') { // If the 's' key has been pressed  
		g_Camera.moveCamera(-0.02);
		glTranslatef(g_Camera.c_vPosition.getXcoord(), g_Camera.c_vPosition.getYcoord(), g_Camera.c_vPosition.getZcoord());
		printf("camX = %f, camY = %f, camZ = %f\n ", g_Camera.c_vPosition.getXcoord(), g_Camera.c_vPosition.getYcoord(), g_Camera.c_vPosition.getZcoord());
	}

	glutSetWindow(mainWindow);
	glutPostRedisplay();
}

void keyUp(unsigned char key, int x, int y) {
	if (key == 'w' || key == 'W') { // If the 'w' key has been pressed  
		g_Camera.moveCamera(NULL);
	}

	if (key == 's' || key == 'S') { // If the 's' key has been pressed  
		g_Camera.moveCamera(NULL);
	}
}

void CreateGrid(){
	int size = 5;
	int size_l = (2 * size + 1) * 2;
	int size_v = size_l * 2;

	LINE3D* l = (LINE3D*)malloc(sizeof(LINE3D)*size_l);

	int current_pos = -size;

	for (int i = 0; i < size_l / 2; i++){
		l[i].v1.x = -size;
		l[i].v1.y = 0;
		l[i].v1.z = current_pos;

		l[i].v2.x = size;
		l[i].v2.y = 0;
		l[i].v2.z = current_pos;
		current_pos++;
	}

	current_pos = -size;
	for (int i = size_l / 2; i < size_l; i++){
		l[i].v1.x = current_pos;
		l[i].v1.y = 0;
		l[i].v1.z = -size;

		l[i].v2.x = current_pos;
		l[i].v2.y = 0;
		l[i].v2.z = size;
		current_pos++;
	}

	Object3D *line = new Object3D(l, size_l);

	RenderManager *rmg = RenderManager::getInstance();
	rmg->RegisterObject(line);

	free(l);
}

void CreateGrid2() {
	int size = 10;
	int size_l = (2 * size + 1) * 2;
	int size_v = size_l * 2;
	
	VERTEX3D *v = (VERTEX3D*)malloc(sizeof(VERTEX3D)*size_v);
	LINE* l = (LINE*)malloc(sizeof(LINE)*(size_l));

	int current_pos = -size;

	for (int i = 0; i < size_l / 2; i++){

		v[i * 2].x = -size;
		v[i * 2].y = 0;
		v[i * 2].z = current_pos;

		v[i * 2 + 1].x = size;
		v[i * 2 + 1].y = 0;
		v[i * 2 + 1].z = current_pos;

		l[i].i = i * 2;
		l[i].j = i * 2 + 1;
		current_pos++;
	}

	current_pos = -size;

	for (int i = size_l / 2; i < size_l; i++){

		v[i * 2].x = current_pos;
		v[i * 2].y = 0;
		v[i * 2].z = -size;

		v[i * 2 + 1].x = current_pos;
		v[i * 2 + 1].y = 0;
		v[i * 2 + 1].z = size;

		l[i].i = i * 2;
		l[i].j = i * 2 + 1;
		current_pos++;
	}

	Object3D *line = new Object3D(v, l, size_v, size_l);

	RenderManager *rmg = RenderManager::getInstance();
	rmg->RegisterObject(line);

	free(v);
	free(l);
}

void Display() {
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glColor4f(0.75f, 0.75f, 0.75f, 1.0f);

	gluLookAt(
		g_Camera.c_vPosition.getXcoord(), g_Camera.c_vPosition.getYcoord(), g_Camera.c_vPosition.getZcoord(),
		g_Camera.c_vTarget.getXcoord(), g_Camera.c_vTarget.getYcoord(), g_Camera.c_vTarget.getZcoord(),
		g_Camera.c_vUpVector.getXcoord(), g_Camera.c_vUpVector.getYcoord(), g_Camera.c_vUpVector.getZcoord()
		);

	RenderManager::getInstance()->DrawList();
	CreateGrid();
	glutSwapBuffers();
}

void Reshape(int w, int h){

	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0, (GLdouble)w/(GLdouble)h, 1.0, 200.0);
	gluLookAt(
		g_Camera.c_vPosition.getXcoord(), g_Camera.c_vPosition.getYcoord(), g_Camera.c_vPosition.getZcoord(), 
		g_Camera.c_vTarget.getXcoord(), g_Camera.c_vTarget.getYcoord(), g_Camera.c_vTarget.getZcoord(),
		g_Camera.c_vUpVector.getXcoord(), g_Camera.c_vUpVector.getYcoord(), g_Camera.c_vUpVector.getZcoord()
		);
}

void main(int argc, char * argv[]){
	glutInit(&argc, argv);

	Vector3D *v1 = new Vector3D(2, 3, 5);
	Vector3D *v2 = new Vector3D(4, 2, 1);

	printf("Dot product: %f\n", v1->dotProduct(*v2));
	printf("Magnitude v1: %f\n", v1->magnitude());
	printf("Magnitude v2: %f\n", v2->magnitude());
	printf("Angle between: %f\n", v1->theta(*v2));
	VERTEX3D v[] = { { 0, 0, 0 }, { 1, 0, 0 }, { 0, 1, 0 } };
	LINE l[] = { { 0, 1 }, { 1, 2 }, { 0, 2 } };

	//Step 1: Initialize GLUT
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
	glutInitWindowSize(800, 600);

	//Step 2: Create window
	mainWindow = glutCreateWindow("3D Solar System");
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_BLEND);
	renderWindow();

	Object3D *cube = new Object3D(v, VECTOR_SIZE(v));
	Object3D *line = new Object3D(v, l, VECTOR_SIZE(v), VECTOR_SIZE(l));

	RenderManager *rmg = RenderManager::getInstance();

	rmg->RegisterObject(cube);
	rmg->RegisterObject(line);
	
	//Step 3: Handlers Functions
	
	glutDisplayFunc(Display);
	glutReshapeFunc(Reshape);
	glutIdleFunc(Display);

	glutKeyboardFunc(keyPressed); // Tell GLUT to use the method "keyPressed" for key presses 
	//glutKeyboardFunc(keyUp);
	glutMainLoop();
}