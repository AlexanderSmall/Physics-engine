#pragma once
#include "precision.h"
#include <stdio.h>
#include <math.h>

using namespace PhyEng;

namespace PhyEng {

	// Vector class defines position in 3D space
	class Vector3D
	{

	private:

		real _x; // x position of vector 
		real _y; // y position of vector
		real _z; // z position of vector


	public:

		/*Default constructor*/
		Vector3D() {
			_x, _y, _z = 0;
		}

		/*Initialise vector with passed values*/
		Vector3D(const real x, const real y, const real z) {
			_x = x;
			_y = y;
			_z = z;
		}

		/* invert the vector */
		void invertVector3D()
		{
			_x = -_x;
			_y = -_y;
			_z = -_z;
		}

		/* return the magnitude of the vector */
		real magnitude() const
		{
			return sqrtf((_x * _x) + (_y * _y) + (_z * _z));
		}

		/* return the square of the magnitude of the vector */
		real sqaureMagnitude() const
		{
			return (_x * _x) + (_y * _y) + (_z * _z);
		}

		/*turns non-zero vector into a vector of unit length (unit vector)*/
		void normalise() 
		{
			real length = magnitude();
			if (length > 0) 
			{
				(*this) *= ((real)1)/length;  // r
			}
		}

		/* 
		Multiplies this vector by the passed scalar
		Overloads *= operator
		*/
		void operator*=(const real r)
		{
			_x *= r;
			_y *= r;
			_z *= r;
		}

		/*
		Returns copy of this vector scaled by the passed scalar
		Overloads * operator
		*/
		Vector3D operator*(const real r) const
		{
			return Vector3D(_x*r, _y*r, _z*r);
		}

		/*
		Adds the given vector to this
		Overloads += operator
		*/
		void operator+=(const Vector3D& v)
		{
			_x += v._x;
			_y += v._y;
			_z += v._z;
		}

		/*
		Subtracts the given vector to this
		Overloads -= operator
		*/
		void operator-=(const Vector3D& v)
		{
			_x -= v._x;
			_y -= v._y;
			_z -= v._z;
		}

		/*
		Returns subtraction of this vector and given vector
		Overloads - operator
		*/
		Vector3D operator-(const Vector3D& v)
		{
			return Vector3D(_x - v._x, _y - v._y, _z - v._z);
		}

		/*
		Adds this vector scaled by given vector
		*/
		void addScaledvector(const Vector3D& vector, real scaled)
		{
			_x += vector._x * scaled;
			_y += vector._y * scaled;
			_z += vector._z * scaled;

		}

		/*
		CAlculates component product of this vector and given vector
		*/
		Vector3D componentProduct(const Vector3D &v) const
		{
			return Vector3D(_x * v._x, _y * v._y, _z * v._z);
		}

		void componentProductUpdate(const Vector3D &v)
		{
			_x *= v._x;
			_y *= v._y;
			_z *= v._z;
		}

		/*
		Calculates the scalar product of this vector and passed vector
		Scalar / Dot product
		*/
		real scalarProduct(const Vector3D &v) const
		{
			return _x * v._x + _y * v._y + _z * v._z;
		}

		/*
		Calculates and returns the scalar product of this vector and the passed vector
		*/
		real operator *(const Vector3D &v) const
		{
			return _x * v._x + _y * v._y + _z * v._z;
		}

		/*
		Calculates and returns the vector product of this vector with passed vector
		Vector / Cross product
		*/
		Vector3D vectorProduct(const Vector3D &v) const
		{
			return Vector3D(_y*v._z - _z * v._y,
							_z*v._x - _x * v._z,
							_x*v._y - _y * v._x);
		}

		/*
		This vector becomes vector product of this vector and the passed vector
		*/
		void operator %=(const Vector3D &v)
		{
			*this = v.vectorProduct(v);
		}

		Vector3D operator %(const Vector3D &v) const
		{
			return Vector3D(_y*v._z - _z * v._y,
							_z*v._x - _x * v._z,
							_x*v._y - _y * v._x);
		}

	};

}