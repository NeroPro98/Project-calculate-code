#ifndef SHAPE_INCLUDE_H
#define SHAPE_INCLUDE_H

#pragma once
#include <windows.h>		// Header File For Windows
#include <gl.h>			// Header File For The OpenGL32 Library
#include <glu.h>			// Header File For The GLu32 Library
#include <glaux.h>		// Header File For The Glaux Library
#include <cmath>





//#include <math3d.h>
#include "math3d.h"

#include "Collision_Data.h"


//Abstruct Class for shapes
class Shapes
{
public:

	
	//TODO:the main paramitives
	float Coordinates1;
	float Coordinates2;
	float Coordinates3;

	//TODO:the color paramitives (RGB)
	float Color1;
	float Color2;
	float Color3;

	//TODO:the paramivites for move
	float Accelerates;  // the value of increased of speed
	float Speed;
	float Time;
	float Mass;


public:
	Shapes();
	Shapes(float Coordinates1, float Coordinates2, float Coordinates3, float Color1, float Color2, float Color3);


	//TODO:To draw 2D shapes
	virtual void draw_2D(int x, int y) = 0;

	//TODO:To draw 3D shapes
	virtual void draw_3D(int x, int y, int z) = 0;

	//TODO:To move the Shapes
	virtual float Move_Shape( float S, float T, float M) = 0;

	//TODO:To Collision
	virtual void Collision2() = 0;


};

class Quad : public Shapes {

private:
	int NumRib;   //TODO: The number of The Ribs

public:

	Quad();
	Quad(float H, float L, float W, float C1, float C2, float C3, int NumRib);



	//TODO:The Virtual Function you must reDefine it in The subclass 

	void draw_2D(int x, int y) = 0;


	void draw_3D(int x, int y, int z) {


	}


	float Move_Shape(float S, float T, float M);

	void Collision2() {

	}




};





//TODO:Class to draw Shpere
class Shpere : public Shapes {

private:
	GLUquadric *quadric1;
	float Radius;
	int Longitudes;
	int Latitudes;
	Vector3f Center ;

public:
	Shpere();
	Shpere(GLUquadric *quadric, int x, int y, int z, float C1, float C2, float C3, float S, float T, float A, float M, Vector3f c);
	void Draw_Shpere();

	//TODO:The Virtual Function you must reDefine it in The subclass 
	void draw_2D(int x, int y) { }

	void draw_3D(int x, int y, int z) { }




	float Move_Shape(float S, float T, float M);

	Vector3f getVec();
	float getRadius();

	
	Collision_Data Collision(Shpere other);
	void Collision2() {

	}




};

//TODO: The Defult Constructor 


//TODO: The Constructor With Value



class Cube : public Shapes {

private:
	GLUquadric *quadric1 = gluNewQuadric();
	float RadiusBase;
	float RadiusTop;
	float Height;
	int Longitudes;
	int Latitudes;

public:
	Cube(); 
	Cube(GLUquadric *quadric, float r1, float r2, float h, int L1, int L2, float C1, float C2, float C3);

	//TODO:The Virtual Function you must reDefine it in The subclass 
	void draw_2D(int x, int y) { }

	void draw_3D(int x, int y, int z) { }


	//TODO: To draw Cube
	void Draw_Cube();

	float Move_Shape(float S, float T, float M);
	

	void Collision2() {

	}



};

//TODO:The Defulte Constructor of Cube


//TODO:The  Constructor By Value of Cube

#endif // !1