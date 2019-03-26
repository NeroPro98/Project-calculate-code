
#ifndef PhysicsEngine_H
#define PhysicsEngine_H
#pragma once
#include <vector>
#include "PhysicsObject.h"
#include "Shape.h"
using namespace std;

class PhysicsEngine {
private:
	vector<PhysicsObject> Objects;

public:
	PhysicsEngine();

	int GetNumVector();

	PhysicsObject GetPhysicsObject(unsigned int pos);

	void AddObject(PhysicsObject obj);

	void Simulate(float alpha);
	
	void HandlerCollision();


	};

#endif // !PhysicsEngine_H
	