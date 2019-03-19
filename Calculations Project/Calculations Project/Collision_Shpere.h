#pragma once
#include "Shape.h"

Collision_Data Shpere::Collision(Shpere other) {


	float RaduisDistance = Radius + other.Radius;
	float CenterDistance = (other.getVec().Length() - Center.Length());
	float distance = CenterDistance-RaduisDistance ;

	if (CenterDistance < RaduisDistance) {

		return(Collision_Data(distance,true));
	}
	else if(CenterDistance == RaduisDistance){

		return(Collision_Data(distance, true));

	}
	else {
		return(Collision_Data(distance, false));
	}
		 
}
