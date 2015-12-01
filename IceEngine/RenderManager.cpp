#include "RenderManager.h"

bool RenderManager::instaceMgr = false;
RenderManager* RenderManager::mgr = NULL;
RenderManager::RenderManager()
{
	obj_nr = 0;
}

RenderManager::~RenderManager()
{
	instaceMgr = false;
}

RenderManager* RenderManager::getInstance(){

	if (!instaceMgr){
		mgr = new RenderManager();
		instaceMgr = true;
		return mgr;
	}
	else{
		return mgr;
	}

}

void RenderManager::RegisterObject(Object3D* obj){

	obj_nr++;
	objList.push_back(obj);
	/**/
}

void RenderManager::DrawList()
{
	if (obj_nr != 0){
		for (vector<Object3D* >::iterator it = objList.begin(); it != objList.end(); ++it){
			(*it)->DrawObj();
		}
	}
}