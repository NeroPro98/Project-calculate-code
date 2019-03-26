/*#include "AxisAlignBounding_Data.h"
Collision_Data AxisAlignBounding::Is_CollisionAxis(AxisAlignBounding& other) {


	//Here we Get the max vector point of the down shape and mines it from the min vector point of the up shape
	Vector3f Distance1 = other.GetMinVectorAxis() - Max_Vector;
	//same of the top talk but here if we swap the shapes so the points must swap
	Vector3f Distance2 = Min_Vector - other.GetMaxVectorAxis();

	Vector3f Result = Vector3f(Distance1.Max(Distance2));

	float DistFinal = Result.Max();

	bool Is = false;

	if (DistFinal <= 0)
	{
		Is = true;
	}
	else {
		Is = false;
	}
	
	return Collision_Data(Is, DistFinal);
}*/
