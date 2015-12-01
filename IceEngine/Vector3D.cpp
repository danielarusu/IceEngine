#include "Vector3D.h"

Vector3D::Vector3D()
{
	this->xCoord = 0.0f;
	this->yCoord = 0.0f;
	this->zCoord = 0.0f;
}

Vector3D::Vector3D(GLfloat x, GLfloat y, GLfloat z)
{
	this->xCoord = x;
	this->yCoord = y;
	this->zCoord = z;
}

Vector3D::Vector3D(Vector3D& v)
{

	this->xCoord = v.xCoord;
	this->yCoord = v.yCoord;
	this->zCoord = v.zCoord;

}

Vector3D::~Vector3D()
{
}

GLfloat Vector3D::getXcoord()
{
	return this->xCoord;
}

GLfloat Vector3D::getYcoord()
{
	return this->yCoord;
}

GLfloat Vector3D::getZcoord()
{
	return this->zCoord;
}

void Vector3D::setXcoord(GLfloat x)
{
	this->xCoord = x;
}

void Vector3D::setYcoord(GLfloat y)
{
	this->yCoord = y;
}

void Vector3D::setZcoord(GLfloat z)
{
	this->zCoord = z;
}

Vector3D Vector3D::operator=(const Vector3D& v)
{
	xCoord = v.xCoord;
	yCoord = v.yCoord;
	zCoord = v.zCoord;

	return Vector3D(xCoord, yCoord, zCoord);
}

Vector3D Vector3D::operator + (const Vector3D& v)
{
	xCoord = xCoord + v.xCoord;
	yCoord = yCoord + v.yCoord;
	zCoord = zCoord + v.zCoord;

	return Vector3D(xCoord, yCoord, zCoord);
}

Vector3D Vector3D::operator * (const Vector3D& v)
{
	xCoord = xCoord * v.xCoord;
	yCoord = yCoord * v.yCoord;
	zCoord = zCoord * v.zCoord;

	return Vector3D(xCoord, yCoord, zCoord);
}

Vector3D& Vector3D::operator += (const Vector3D& v)
{
	this->xCoord += v.xCoord;
	this->yCoord += v.yCoord;
	this->zCoord += v.zCoord;

	return *this;
}

Vector3D& Vector3D::operator *= (const Vector3D& v)
{
	this->xCoord *= v.xCoord;
	this->yCoord *= v.yCoord;
	this->zCoord *= v.zCoord;

	return *this;
}

Vector3D Vector3D::scalarMult(const GLfloat& a)
{
	this->xCoord *= a;
	this->yCoord *= a;
	this->zCoord *= a;

	return *this;
}

GLfloat Vector3D::dotProduct(const Vector3D& v)
{
	return (
		(this->xCoord * v.xCoord) +
		(this->yCoord * v.yCoord) +
		(this->zCoord * v.zCoord)
		);
}

float Vector3D::theta(Vector3D& v)
{
	float t = acos(this->dotProduct(v) / (this->magnitude() * v.magnitude()));

	return t; // t is in radians
}

double Vector3D::magnitude()
{
	return sqrt(
		this->xCoord * this->xCoord +
		this->yCoord * this->yCoord +
		this->zCoord * this->zCoord
		);
}

Vector3D Vector3D::normalise()
{
	double l = this->magnitude();
	this->xCoord /= l;
	this->yCoord /= l;
	this->zCoord /= l;

	return *this;
}

double Vector3D::distance(Vector3D& v)
{
	return sqrt(
		(this->xCoord - v.xCoord) +
		(this->yCoord - v.yCoord) +
		(this->zCoord - v.zCoord)
		);
}

float Vector3D::toDegrees(float rad)
{
	return (rad * 180) / PI;
}

float Vector3D::toRadians(float deg)
{
	return (deg)* (PI / 180);
}

void Vector3D::printCoords(GLfloat x, GLfloat y, GLfloat z)
{
	std::printf("Coords: x = %f, y = %f, z = %f\n", x, y, z);
}

void Vector3D::printVector(Vector3D& v){
	std::printf("v = [%f, %f, %f]\n", v.xCoord, v.yCoord, v.zCoord);
}