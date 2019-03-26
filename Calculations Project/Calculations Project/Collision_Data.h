#ifndef COLLISION_DATA_INCLUDE_H
#define COLLISION_DATA_INCLUDE_H

#pragma once


class Collision_Data {

protected:
	float Distance;
	bool isCollision;
	

public:
	Collision_Data();
	Collision_Data(float Dis, bool is);
	bool getisCollision();
	float getDistance();

	void setDistance(float dist);
	void setISCollision(bool isCol);
}






#endif // !1
