
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

	PhysicsEngine::PhysicsEngine() {

	}


	int PhysicsEngine::GetNumVector() {

		return (unsigned int)Objects.size();
	}

	PhysicsObject PhysicsEngine::GetPhysicsObject(unsigned int pos) {

		return Objects[pos];


	}

	void PhysicsEngine::AddObject(PhysicsObject obj) {

		Objects.push_back(obj);
	}

	void PhysicsEngine::Simulate(float alpha) {

		//for (unsigned int i = 0; i < Objects.size(); i++) {
			Objects[0].Integrate(alpha);
			Objects[1].Integrate(alpha);

	//	}
	}

	void PhysicsEngine::HandlerCollision() {

	//	for (unsigned int i = 0; i < Objects.size(); i++) {
			
	//		for (unsigned int j = i+1; j < Objects.size(); j++) {

				Collision_Data data = Objects[0].GetShpere().Collision(Objects[1].GetShpere());

				if (data.getisCollision()) {
					Objects[0].SetVelocity(Objects[0].GetVelocity()*-1);
					Objects[1].SetVelocity(Objects[1].GetVelocity()*-1);
				}
		//	}
		

	//	}

	}

	
#endif // !PhysicsEngine_H
	