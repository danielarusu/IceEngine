#ifndef VECTOR3D_H
#define VECTOR3D_H

#include "global.includes.h"
#include "global.defines.h"

class Vector3D
{
public:
	Vector3D();
	Vector3D(GLfloat x, GLfloat y, GLfloat z);
	Vector3D(Vector3D& v);

	GLfloat getXcoord();
	GLfloat getYcoord();
	GLfloat getZcoord();
	Vector3D getVector();

	void setXcoord(GLfloat x);
	void setYcoord(GLfloat y);
	void setZcoord(GLfloat z);
	void setVector(Vector3D& v);

	Vector3D operator=(const Vector3D& v);
	Vector3D operator+(const Vector3D& v);
	Vector3D operator-(const Vector3D& v);
	Vector3D operator*(const Vector3D& v);
	Vector3D& operator+=(const Vector3D& v);
	Vector3D& operator*=(const Vector3D& v);

	Vector3D scalarMult(const GLfloat& a);
	Vector3D crossProdComponents(Vector3D& v);
	GLfloat dotProduct(const Vector3D& v);
	float theta(Vector3D& v);

	double magnitude();
	Vector3D normalise();
	double distance(Vector3D& v);

	float toDegrees(float rad);
	float toRadians(float deg);

	void printCoords(GLfloat x, GLfloat y, GLfloat z);
	void printVector(Vector3D& v);

	~Vector3D();

private:
	GLfloat xCoord, yCoord, zCoord;
};

#endif