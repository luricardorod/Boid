#pragma once

class Cvector4D
{
public:
	union
	{
		struct
		{
			float x, y, z, w;
		};
		struct
		{
			float r, g, b, a;
		};
		struct
		{
			unsigned long ulx, uly, ulz, ulw;
		};
		struct
		{
			long lx, ly, lz, lw;
		};
		float v[4];
		unsigned long ul[4];
		long l[4];
	};
	Cvector4D();
	Cvector4D(const Cvector4D& V);
	Cvector4D(const float fx, const  float fy, const  float fz, const float fw);
	~Cvector4D();
};
Cvector4D operator* (const Cvector4D  &A, const Cvector4D &B);
Cvector4D operator* (float s, const Cvector4D &A);
Cvector4D operator* (const Cvector4D &A, float s);
Cvector4D operator/ (const Cvector4D &A, float s);
Cvector4D operator+(const Cvector4D& A, const Cvector4D& B);
Cvector4D operator-(const Cvector4D& A, const Cvector4D& B);
float Dot(const Cvector4D &A, const Cvector4D &B);
Cvector4D Cross3(const Cvector4D& A, const Cvector4D& B);
float Magnity(const Cvector4D& A);
Cvector4D Normalize(const Cvector4D& A);

bool RayCastOnPlane(Cvector4D& RayOrigin, Cvector4D& RayDir,
	Cvector4D& Plane, Cvector4D& Intersection);
bool PtInTriangle(Cvector4D& V0, Cvector4D& V1, Cvector4D& V2, Cvector4D& P,
	float& w1, float& w2);



