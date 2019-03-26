#include"PhysicsEngineComponent.h"


PhysicsEngineComponent::PhysicsEngineComponent(PhysicsEngine object) {

	Object = object;
}

void PhysicsEngineComponent::Update(float alpha) {

	Object.Simulate(alpha);

}

PhysicsEngine PhysicsEngineComponent::GetPhysicsEngine() {
	return Object;
}
