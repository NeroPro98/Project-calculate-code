#include"Shape.h"


Shapes::Shapes() {
	Coordinates1 = 0;
	Coordinates2 = 0;
	Coordinates3 = 0;
	Color1 = 0.0f;
	Color2 = 0.0f;
	Color3 = 0.0f;
	Accelerates = 0.0f;
	Mass = 0.0f;
	Time = 0.0f;
	Speed = 0.0f;
}
Shapes::Shapes(float Coordinates1, float Coordinates2, float Coordinates3, float Color1, float Color2, float Color3) 
{
	this->Coordinates1 = Coordinates1;
	this->Coordinates2 = Coordinates2;
	this->Coordinates3 = Coordinates3;
	this->Color1 = Color1;
	this->Color2 = Color2;
	this->Color3 = Color3;
}

Quad::Quad() {
	Coordinates1 = 0;
    Coordinates2 = 0;
    Coordinates3 = 0;
	Color1 = 1.0f;
	Color2 = 1.0f;
	Color3 = 1.0f;
	NumRib = 0;
}
Quad::Quad(float H, float L, float W, float C1, float C2, float C3, int NumRib) {

	this->Coordinates1 = H;
	this->Coordinates2 = L;
	this->Coordinates3 = W;
	Color1 = C1;
	Color2 = C2;
	Color3 = C3;
	NumRib = NumRib;

}
void Quad::draw_2D(int x, int y) {
	glColor3d(Color1, Color2, Color3);
	glBegin(GL_QUADS);
	{
		glVertex2d(x, y);
		glVertex2d(-x, y);
		glVertex2d(-x, y + 2);
		glVertex2d(x, y + 2);
	}glEnd();

}
float Quad:: Move_Shape(float S, float T, float M) {

	//A += S / T;
	return Accelerates;
}
Shpere::Shpere()
{
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
void Shpere::Draw_Shpere() {
	glPushMatrix();
	{
		glColor3d(Color1, Color2, Color3);
		glTranslatef(Center[0], Center[1], Center[2]);
		gluSphere(quadric1, Radius, Longitudes, Latitudes);

	}
	glPopMatrix();
}
float Shpere::Move_Shape(float S, float T, float M) {
	Speed = S;
	Time = T;
	Mass = M;
	Accelerates += Speed / Time;
	return Accelerates;
}
Vector3f Shpere::getVec()
{
	return Center;
}
float Shpere::getRadius()
{
	return Radius;
}

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

void Cube::Draw_Cube() {
	glColor3d(Color1, Color2, Color3);
	gluCylinder(quadric1, RadiusBase, RadiusTop, Height, Longitudes, Latitudes);

}

float Cube :: Move_Shape(float S, float T, float M) {
	Speed = S;
	Time = T;
	Mass = M;
	Accelerates += Speed / Time;
	return Accelerates;
}

