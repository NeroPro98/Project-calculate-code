#ifndef PLANE_H
#define PLANE_H
#pragma once
#include "math3d.h"
#include "Shape.h"


class Plane {

private:
	Vector3f Normal;
	float Distance;

public:
	Plane() {
		Normal = 0.0f;
		Distance = 0.0f;
	}
	Plane(Vector3f normal, float distance)
	{
		Normal = normal;
		Distance = distance;
	}

	Vector3f GetNormal(){return Normal;}

	float GetDistance(){
		return Distance;
	}

	Plane Normalized(); /*{

		float magnitude = Normal.Length();

		return Plane(Normal / magnitude, Distance / magnitude);
	}*/

		Collision_Data Collision_Shpere_Plane(Shpere s); /*{

		//Normal.Dot(s.getVec()): to calculate the distance betwen Normal and the center of shpere
		//Normal.Dot(s.getVec()) + Distance: it give us the distance between the center of shpere and plane
		float distanceCentertoPlane = fabs(Normal.Dot(s.getVec()) + Distance);
		float distanceShperetoplane = distanceCentertoPlane - s.getRadius();

		return Collision_Data(distanceShperetoplane, distanceShperetoplane < 0);
	}*/


};



#endif 
