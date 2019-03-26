#pragma 
#ifndef PhysicsObject_H
#define PhysicsObject_H
#include "math3d.h"
#include "Shape.h"

class PhysicsObject {
   private:
	   Vector3f Postion;
	   Vector3f Velocity;
	   float Raduis;

   public:

	   PhysicsObject();
	   PhysicsObject(Vector3f postion, Vector3f velocity,float raduis);

	   Vector3f GetPostion();

	   Vector3f GetVelocity();

	   void Integrate(float alpha);
	   void SetVelocity(Vector3f vol);

	   float GetRaduis();
	   Shpere GetShpere() {
		   GLUquadric *NewQuadric = gluNewQuadric();

		   return Shpere(NewQuadric, Raduis, 32, 32, 0.4, 0.4, 0.4, 5.0, 5.0, 5.0, 5.0, Postion);
	   }



};




#endif // !PhysicsObject_H
