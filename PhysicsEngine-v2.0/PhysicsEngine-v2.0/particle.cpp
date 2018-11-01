#pragma once
#include <assert.h>
#include "particle.h"

using namespace PhyEng;

namespace PhyEng {

	void Particle::integrate(real duration)
	{
		assert(duration > 0.0);

		/*Update linear position*/
		position.addScaledvector(velocity, duration);

		/*Calculate acceleration using force*/
		Vector3D newAcc = acceleration;
		newAcc.addScaledvector(forceAccum, inverseMass);

		/*Update linear velocity from the acceleration*/
		velocity.addScaledvector(newAcc, duration);

		//impose drag
		velocity *= powf(damping, duration);
	}

	void Particle::setPosition(Vector3D pv) 
	{
		position = pv;
	}

	Vector3D Particle::getPosition()
	{
		return position;
	}

	void Particle::setVelocity(Vector3D vv)
	{
		velocity = vv;
	}

	Vector3D Particle::getVelocity()
	{
		return velocity;
	}

	void Particle::setMass(real m)
	{
		inverseMass = m;
	}

	real Particle::getMass()
	{
		return inverseMass;
	}

	void Particle::setAcceleration(Vector3D av)
	{
		acceleration = av;
	}

	Vector3D Particle::getAcceleration()
	{
		return acceleration;
	}
}
