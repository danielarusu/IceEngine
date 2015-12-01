#ifndef OBJECT3D_H
#define OBJECT3D_H

#include "global.includes.h"
#include "global.defines.h"
#include "obj.struct.h"

class Object3D
{
public:
	Object3D();
	Object3D(VERTEX3D* v, int size);
	Object3D(VERTEX3D* v, LINE* l, int size_v, int size_l);
	Object3D(LINE3D* l, int size_l);
	Object3D(VERTEX3D* v, TRI* t, int size_v, int size_t);

	void DrawVertexType();
	void DrawLineType();
	void DrawTriangleType();
	void DrawObj();
	~Object3D();

	int obj_type;
private:
	vector<VERTEX3D*> mesh;
	vector<LINE*> lines;
	vector<TRI*> triangles;
	VERTEX3D* v_copy;
	LINE* l_copy;
	enum types { POINT_TYPE = 0, LINE_TYPE, TRIANGLE_TYPE };
};

#endif