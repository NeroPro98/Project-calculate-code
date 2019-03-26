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
	Plane();
	Plane(Vector3f normal, float distance);
	Vector3f GetNormal();

	float GetDistance();
	Plane Normalized(); 
	Collision_Data Collision_Shpere_Plane(Shpere s); 

};



#endif 
