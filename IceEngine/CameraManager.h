#ifndef CAMERAMANAGER_H
#define CAMERAMANAGER_H

#include "global.includes.h"
#include "obj.struct.h"
#include "Vector3D.h"

class Camera
{
public:

	Vector3D c_vPosition;
	Vector3D c_vTarget;
	Vector3D c_vDirection;
	
	Vector3D c_vUpVector;
	Vector3D c_vRightVector;	
	
	Camera();
	~Camera();

	void positionCamera(GLfloat pos_X, GLfloat pos_Y, GLfloat pos_Z,
		GLfloat eye_X, GLfloat eye_Y, GLfloat eye_Z,
		GLfloat upVec_x, GLfloat upVec_Y, GLfloat upVec_Z);
	void moveCamera(GLfloat direction);
private:

};


#endif