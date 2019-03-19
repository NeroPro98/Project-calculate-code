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

};





Collision_Data::Collision_Data() {

	Distance = 0.0f;
	isCollision = false;
}




Collision_Data::Collision_Data(float Dis,bool is) {

	Distance = Dis;
	isCollision = is;
}



bool Collision_Data::getisCollision() {

	return isCollision;
}

float Collision_Data::getDistance() {

	return Distance;
}