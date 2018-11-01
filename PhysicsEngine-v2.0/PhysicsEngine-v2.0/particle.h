#pragma once
#include "vector.h"
#include <stdio.h>
#include <math.h>

using namespace PhyEng;

namespace PhyEng {

	class Particle
	{

	public:

		Vector3D position;			/*Holds position of particle in 3D space as a 3D vector*/
		Vector3D velocity;			/*Holds velcoity of particle*/
		Vector3D acceleration;		/*Holds acceleration of particle*/

		real damping;				/*damping*/

		real inverseMass;			/*Holds inverse mass, can't have particle with 0 mass*/

		Vector3D forceAccum;

		void integrate(real duration);

		void clearForceAccum();

		void setPosition(Vector3D);
		Vector3D getPosition();
		
		void setVelocity(Vector3D);
		Vector3D getVelocity();

		void setMass(real);
		real getMass();

		void setAcceleration(Vector3D);
		Vector3D getAcceleration();

	};
}