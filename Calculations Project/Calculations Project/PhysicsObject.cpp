#include"PhysicsObject.h"


Vector3f PhysicsObject::GetPostion() {
	return Postion;
}

Vector3f PhysicsObject::GetVelocity() {
	return Velocity;
}

void PhysicsObject::Integrate(float alpha) {

	Postion += Velocity * alpha;

}

void PhysicsObject::SetVelocity(Vector3f vol) {
	Velocity = vol;
}

float PhysicsObject::GetRaduis() {
	return Raduis;
}
PhysicsObject::PhysicsObject() {
	Postion = 0;
	Velocity = 0;
}
PhysicsObject::PhysicsObject(Vector3f postion, Vector3f velocity, float raduis) {

	Postion = postion;
	Velocity = velocity;
	Raduis = raduis;
}
