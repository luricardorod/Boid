#pragma once
#include "Cvector4D.h";

struct Ctarget {
	Cvector4D _position;
	float _forceValue;
	float _radiusOfForceApplication;
};
class Cboid
{
private:
	Cvector4D _position;
	Cvector4D _velocity;
	float _maxSpeed;

public:
	void Init();
	void Destroy();
	void Update(float delta);
	void Render();
	void Seek(Ctarget &target);
	void Flee(Ctarget &target);
	void Arrive(Ctarget &target);
	Cboid();
	~Cboid();
};

