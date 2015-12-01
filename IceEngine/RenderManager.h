#ifndef RENDERMANAGER_H
#define RENDERMANAGER_H

#include "global.includes.h"
#include "Object3D.h"

class RenderManager
{
public:
	static RenderManager *getInstance();
	void RegisterObject(Object3D* obj);
	void DrawList();
	~RenderManager();
	
private:
	static RenderManager *mgr;
	RenderManager();
	static bool instaceMgr;
	vector<Object3D*> objList;
	int obj_nr;
};

#endif