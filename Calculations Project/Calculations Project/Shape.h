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
class Shapes {
protected:

	
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


//TODO:The Default Constructor of Shapes
Shapes::Shapes() {
	this->Coordinates1 = 0;
	this->Coordinates2 = 0;
	this->Coordinates3 = 0;
	this->Color1 = 0.0f;
	this->Color2 = 0.0f;
	this->Color3 = 0.0f;
	this->Accelerates = 0.0f;
	this->Mass = 0.0f;
	this->Time = 0.0f;
	this->Speed = 0.0f;

}

//TODO:The  Constructor By Value of Shapes
Shapes::Shapes(float Coordinates1, float Coordinates2, float Coordinates3, float Color1, float Color2, float Color3) {
	this->Coordinates1 = Coordinates1;
	this->Coordinates2 = Coordinates2;
	this->Coordinates3 = Coordinates3;
	this->Color1 = Color1;
	this->Color2 = Color2;
	this->Color3 = Color3;
}





//TODO:Class for Draw Quad
class Quad : public Shapes {

private:
	int NumRib;   //TODO: The number of The Ribs

public:

	Quad();
	Quad(float H, float L, float W, float Color1, float Color2, float Color3, int NumRib);




	//TODO:The Virtual Function you must reDefine it in The subclass 

	void draw_2D(int x, int y) {
		glColor3d(Color1, Color2, Color3);
		glBegin(GL_QUADS);
		{
			glVertex2d(x, y);
			glVertex2d(-x, y);
			glVertex2d(-x, y + 2);
			glVertex2d(x, y + 2);
		}glEnd();

	}


	void draw_3D(int x, int y, int z) {


	}


	float Move_Shape(float S, float T, float M) {

		//A += S / T;

		return Accelerates;
	}

	void Collision2() {

	}




};

//TODO:The Defulet Constructor of Quad
Quad::Quad() {

	this->Coordinates1 = 0;
	this->Coordinates2 = 0;
	this->Coordinates3 = 0;
	Color1 = 1.0f;
	Color2 = 1.0f;
	Color3 = 1.0f;
	NumRib = 0;

}


//TODO:The  Constructor By Value of Quad
Quad::Quad(float H, float L, float W, float C1, float C2, float C3, int N) {


	this->Coordinates1 = H;
	this->Coordinates2 = L;
	this->Coordinates3 = W;
	Color1 = C1;
	Color2 = C2;
	Color3 = C3;
	NumRib = N;


}




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
	Shpere(GLUquadric *quadric, int x, int y, int z, float C1, float C2, float C3, float S, float T, float A, float M,Vector3f c);
	
	void Draw_Shpere() {

		glPushMatrix();
		{
			glColor3d(Color1, Color2, Color3);
			glTranslatef(Center[0],Center[1],Center[2]);
			gluSphere(quadric1, Radius, Longitudes, Latitudes);

		}
		glPopMatrix();
	}

	//TODO:The Virtual Function you must reDefine it in The subclass 
	void draw_2D(int x, int y) { }

	void draw_3D(int x, int y, int z) { }




	float Move_Shape( float S, float T, float M) {


		Speed = S;
		Time = T;
		Mass = M;
		Accelerates += Speed / Time;

		return Accelerates;

	}

	Vector3f getVec(){
		


		return Center;

	}

	float getRadius() {

		return Radius;
	}

	
	Collision_Data Collision(Shpere other);


	void Collision2() {

	}




};

//TODO: The Defult Constructor 
Shpere::Shpere() {

	this->Coordinates1 = 0;
	this->Coordinates2 = 0;
	this->Coordinates3 = 0;
	Radius = 4;
	Longitudes = 32;
	Latitudes = 32;
	Color1 = 1;
	Color2 = 1;
	Color3 = 1;
	quadric1 = gluNewQuadric();
	Center = 0;

}

//TODO: The Constructor With Value
Shpere::Shpere(GLUquadric *quadric, int x, int y, int z, float C1, float C2, float C3, float S, float T, float A, float M, Vector3f c) {

	Coordinates1 = 0;
	Coordinates2 = 0;
	Coordinates3 = 0;
	Color1 = C1;
	Color2 = C2;
	Color3 = C3;
	Radius = x;
	Longitudes = y;
	Latitudes = z;
	quadric1 = quadric;
	Accelerates = A;
	Speed = S;
	Mass = M;
	Time = T;
	//Center[0] = c[0];
	//Center[1] = c[1];
	//Center[2] = c[2];
	Center = c;
}


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
	void Draw_Cube() {
		glColor3d(Color1, Color2, Color3);
		gluCylinder(quadric1, RadiusBase, RadiusTop, Height, Longitudes, Latitudes);

	}

	float Move_Shape(float S, float T, float M) {

		Speed = S;
		Time = T;
		Mass = M;
		Accelerates += Speed / Time;
		return Accelerates;



	}


	void Collision2() {

	}



};

//TODO:The Defulte Constructor of Cube
Cube::Cube() {
	quadric1 = gluNewQuadric();
	RadiusBase = 2;
	RadiusTop = 2;
	Height = 2;
	Longitudes = 32;
	Latitudes = 32;
	Color1 = 1;
	Color2 = 1;
	Color3 = 1;

}


//TODO:The  Constructor By Value of Cube
Cube::Cube(GLUquadric *quadric, float r1, float r2, float h, int L1, int L2, float C1, float C2, float C3) {
	quadric1 = quadric;
	RadiusBase = r1;
	RadiusTop = r2;
	Height = h;
	Longitudes = L1;
	Latitudes = L2;
	Color1 = C1;
	Color2 = C2;
	Color3 = C3;
}
