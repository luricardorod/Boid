#include "Cvector4D.h"
#include <cmath>
Cvector4D::Cvector4D()
{
}

Cvector4D::Cvector4D(const Cvector4D& V)
{
	x = V.x;
	y = V.y;
	z = V.z;
	w = V.w;
}
Cvector4D::Cvector4D(const float fx, const float fy, const float fz, const float fw)
{
	x = fx;
	y = fy;
	z = fz;
	w = fw;
}

Cvector4D::~Cvector4D()
{
}
Cvector4D operator* (const Cvector4D  &A, const Cvector4D &B)
{
	return Cvector4D(A.x*B.x, A.y*B.y, A.z*B.z, A.w*B.w);
}
Cvector4D operator* (float s, const Cvector4D &A)
{
	return Cvector4D(A.x*s, A.y*s, A.z*s, A.w*s);
}
Cvector4D operator* (const Cvector4D &A, float s)
{
	return s*A;
}
Cvector4D operator/ (const Cvector4D &A, float s)
{
	return A*(1 / s);
}
Cvector4D operator+(const Cvector4D& A, const Cvector4D& B)
{
	return Cvector4D(A.x + B.x, A.y + B.y, A.z + B.z, A.w + B.w);
}
Cvector4D operator-(const Cvector4D& A, const Cvector4D& B)
{
	return Cvector4D(A.x - B.x, A.y - B.y, A.z - B.z, A.w - B.w);

}
float Dot(const Cvector4D &A, const Cvector4D &B)
{
	return A.x*B.x + A.y*B.y + A.z*B.z + A.w*B.w;
}
Cvector4D Cross3(const Cvector4D& A, const Cvector4D& B)
{
	return Cvector4D(
		A.y*B.z - A.z*B.y,
		A.z*B.x - A.x*B.z,
		A.x*B.y - A.y*B.x, 0);
}
float Magnity(const Cvector4D& A)
{
	return std::sqrt(Dot(A, A));
}
Cvector4D Normalize(const Cvector4D& A)
{
	return A / Magnity(A);
}

bool RayCastOnPlane(Cvector4D& RayOrigin, Cvector4D& RayDir,
	Cvector4D& Plane, Cvector4D& Intersection)
{
	float d = Dot(Plane, RayDir);
	if (fabsf(d) < 0.001f) return false;
	float n = -Dot(Plane, RayOrigin);
	float u = n / d;
	if (u < 0.0f) return false;
	Intersection = RayOrigin + RayDir*u;
	return true;
}
bool PtInTriangle(Cvector4D& V0, Cvector4D& V1, Cvector4D& V2, Cvector4D& P, float& w1, float& w2)
{
	Cvector4D D0 = V1 - V0;
	Cvector4D D1 = V2 - V0;
	float A = Dot(P - V0, D0);
	float B = Dot(D0, D0);
	float C = Dot(D1, D0);
	float D = Dot(P - V0, D1);
	//float E = C;
	float F = Dot(D1, D1);
	float det = B*F - C*C;
	if (fabsf(det) < 0.00001f) return false;
	det = 1 / det;
	w1 = (F*A - C*D)*det;
	w2 = (B*D - C*A)*det;
	return (w1 + w2 <= 1.0f) && (w1 >= 0.0f) && (w2 >= 0.0f);
}