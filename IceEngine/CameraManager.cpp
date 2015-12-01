#include "CameraManager.h"

Camera::Camera()
{
	c_vPosition = Vector3D(2.0f, 2.0f, 20.0f);
	c_vTarget = Vector3D(0.0f, 0.0f, 0.0f);

	c_vDirection = c_vPosition - c_vTarget;
	c_vDirection.normalise();

	c_vUpVector = Vector3D(0.0f, 2.0f, 0.0f);

	c_vRightVector = c_vDirection.crossProdComponents(c_vUpVector);
	c_vRightVector.normalise();
}

Camera::~Camera()
{
}

void Camera::moveCamera(GLfloat d)
{
	if (d == NULL) return;

	/*Vector3D vDirection = c_vPosition - c_vTarget;
	c_vPosition.setXcoord(c_vPosition.getXcoord() + vDirection.getXcoord()*d);
	c_vPosition.setZcoord(c_vPosition.getZcoord() + vDirection.getZcoord()*d);

	c_vTarget.setXcoord(c_vTarget.getXcoord() + vDirection.getXcoord()*d);
	c_vTarget.setZcoord(c_vTarget.getZcoord() + vDirection.getZcoord()*d);*/
	c_vPosition.setXcoord(c_vPosition.getXcoord() - c_vPosition.getXcoord()*d);
	c_vPosition.setZcoord(c_vPosition.getZcoord() - c_vPosition.getZcoord()*d);
}