#pragma 
#ifndef PhysicsObject_H
#define PhysicsObject_H
#include "math3d.h"

class PhysicsObject {
   private:
	   Vector3f Postion;
	   Vector3f Velocity;
	   float Raduis;

   public:

	   PhysicsObject();
	   PhysicsObject(Vector3f postion, Vector3f velocity,float raduis);

	   Vector3f GetPostion() {
		   return Postion;
	   }

	   Vector3f GetVelocity() {
		   return Velocity;
	   }

	   void Integrate(float alpha) {

		   Postion += Velocity * alpha;

	   }

	   void SetVelocity(Vector3f vol) {
		   Velocity = vol;
	   }

	   float GetRaduis() {
		   return Raduis;
	   }

	   Shpere GetShpere() {
		   GLUquadric *NewQuadric = gluNewQuadric();

		   return Shpere(NewQuadric, Raduis, 32, 32, 0.4, 0.4, 0.4, 5.0, 5.0, 5.0, 5.0, Postion);
	   }



};

PhysicsObject::PhysicsObject() {
	Postion = 0;
	Velocity = 0;
}
PhysicsObject::PhysicsObject(Vector3f postion, Vector3f velocity,float raduis) {

	Postion = postion;
	Velocity = velocity;
	Raduis = raduis;
}



#endif // !PhysicsObject_H
