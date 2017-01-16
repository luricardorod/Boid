#include "Cboid.h"

void Cboid::Init() {
}
void Cboid::Destroy() {
}
void Cboid::Update(float delta) {
	if (Magnity(_velocity) > _maxSpeed)
	{
		_velocity = Normalize(_velocity) * _maxSpeed;
	}
	_position = _position + _velocity * delta;
}
void Cboid::Render() {
}

void Cboid::Seek(Ctarget &target) {
	Cvector4D attractionForce = target._position - _position;
	attractionForce = Normalize(attractionForce) * target._forceValue;
	_velocity = _velocity + attractionForce;
}
void Cboid::Flee(Ctarget &target) {
	Cvector4D deflectionForce = _position - target._position;
	deflectionForce = Normalize(deflectionForce) * target._forceValue;
	_velocity = _velocity + deflectionForce;
}
void Cboid::Arrive(Ctarget &target){
	Seek(target);
	Cvector4D distance = target._position - _position;
	if (Magnity(distance) < target._radiusOfForceApplication)
	{
		_velocity = _velocity * (distance / target._radiusOfForceApplication);
	}
}

Cboid::Cboid()
{
}


Cboid::~Cboid()
{
}
