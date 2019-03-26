#ifndef COLLISION_DATA_INCLUDE_H
#define COLLISION_DATA_INCLUDE_H

#pragma once


class Collision_Data {

protected:
	float Distance;
	bool isCollision;
	

public:
	Collision_Data(){
		Distance = 0.0f;
		isCollision = false;
	}
	Collision_Data(float Dis, bool is){
		Distance = Dis;
		isCollision = is;
	}

	bool getisCollision(){ return isCollision; }


	float getDistance(){
		return Distance;
	}

};





#endif // !1
