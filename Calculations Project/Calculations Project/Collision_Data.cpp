#include"Collision_Data.h"

Collision_Data::Collision_Data()
{
	Distance = 0.0f;
	isCollision = false;
}
Collision_Data::Collision_Data(float Dis, bool is) {
	Distance = Dis;
	isCollision = is;
}
float Collision_Data::getDistance(){
	return Distance;
}
bool Collision_Data::getisCollision()
{
	return isCollision;
}
void Collision_Data::setDistance(float dist)
{
	Distance = dist;
}
void Collision_Data::setISCollision(bool IsCol)
{
	isCollision = IsCol;
}
