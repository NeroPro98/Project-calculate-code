
#ifndef PhysicsEngineComponent_H
#define PhysicsEngineComponent_H
#pragma once
#include"PhysicsEngine.h"

class PhysicsEngineComponent {

private:
	PhysicsEngine Object;
public:

	PhysicsEngineComponent(PhysicsEngine object);
	void Update(float alpha);
	PhysicsEngine GetPhysicsEngine();

};




#endif // !PhysicsEngineComponent_H

