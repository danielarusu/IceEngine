#include "Object3D.h"

Object3D::Object3D()
{
	obj_type = 1;
}

Object3D::Object3D(VERTEX3D* v, int size){
	
	obj_type = Object3D::POINT_TYPE;
	mesh.clear();

	for (int i = 0; i < size; i++) {
		mesh.push_back(&v[i]);
	};
}

Object3D::Object3D(VERTEX3D* v, LINE* l, int size_v, int size_l){
	
	obj_type = Object3D::LINE_TYPE;
	mesh.clear();
	lines.clear();

	v_copy = (VERTEX3D*)(malloc(sizeof(VERTEX3D)*size_v));
	l_copy = (LINE*)(malloc(sizeof(LINE)*size_l));

	memcpy(v_copy, v, size_v * sizeof(VERTEX3D));
	memcpy(l_copy, l, size_l * sizeof(LINE));

	for (int i = 0; i < size_v; i++) {
		mesh.push_back(&v_copy[i]);
	};

	for (int i = 0; i < size_l; i++) {
		lines.push_back(&l_copy[i]);
	};	
}

Object3D::Object3D(LINE3D* l, int size_l) {
	obj_type = Object3D::LINE_TYPE;
	mesh.clear();
	lines.clear();

	v_copy = (VERTEX3D*)(malloc(sizeof(VERTEX3D)*(2 * size_l)));
	l_copy = (LINE*)(malloc(sizeof(LINE)*size_l));

	for (int i = 0; i < size_l; i++){
		v_copy[i * 2] = l[i].v1;
		v_copy[i * 2 + 1] = l[i].v2;

		l_copy[i].i = i*2;
		l_copy[i].j = i * 2 + 1;
	}

	for (int i = 0; i < 2*size_l; i++) {
		mesh.push_back(&v_copy[i]);
	};

	for (int i = 0; i < size_l; i++) {
		lines.push_back(&l_copy[i]);
	};
}

Object3D::~Object3D()
{
	free(v_copy);
	free(l_copy);
}

void Object3D::DrawVertexType(){
	if (mesh.size() != NULL){
		for (vector<VERTEX3D*>::iterator it = mesh.begin(); it != mesh.end(); ++it){
			glVertex3f(
				(*it)->x,
				(*it)->y,
				(*it)->z
			);
		}
	};
}

void Object3D::DrawLineType(){
	if (lines.size() != NULL){
		for (vector<LINE*>::iterator it = lines.begin(); it != lines.end(); ++it){
			glVertex3f(
				mesh[(*it)->i]->x,
				mesh[(*it)->i]->y,
				mesh[(*it)->i]->z
			);
			glVertex3f(
				mesh[(*it)->j]->x,
				mesh[(*it)->j]->y,
				mesh[(*it)->j]->z
			);
		}
	}
}

void Object3D::DrawTriangleType(){

}

void Object3D::DrawObj(){

	switch (obj_type)
	{
	case Object3D::POINT_TYPE:
		glBegin(GL_POINTS);
			DrawVertexType();
		glEnd();
		break;
	case Object3D::LINE_TYPE:
		glBegin(GL_LINES);
			DrawLineType();
		glEnd();
		break;
	case Object3D::TRIANGLE_TYPE:
		glBegin(GL_TRIANGLES);
			DrawTriangleType();
		glEnd();
		break;
	default:
		break;
	}
}