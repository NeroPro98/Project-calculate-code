
#include "Plane.h"
Plane::Plane()
{
	Normal = 0.0f;
	Distance = 0.0f;
}
Plane::Plane(Vector3f normal, float distance)
{
	Normal = normal;
	Distance = distance;
}
Vector3f Plane::GetNormal()
{
	return Normal; 
}
float Plane::GetDistance(){
	return Distance;
}

Plane Plane::Normalized() {
	float magnitude = Normal.Length();

	return Plane(Normal / magnitude, Distance / magnitude);

}

Collision_Data Plane::Collision_Shpere_Plane(Shpere s) {

	float distanceCentertoPlane = fabs(Normal.Dot(s.getVec()) + Distance);
	float distanceShperetoplane = distanceCentertoPlane - s.getRadius();

		return Collision_Data(distanceShperetoplane, distanceShperetoplane < 0);

}
