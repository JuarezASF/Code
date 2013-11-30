/*
 * MathVector.h
 *
 *  Created on: Nov 6, 2013
 *      Author: juarez
 */

#ifndef MathVector_H_
#define MathVector_H_

#include <cmath>
#include <iostream>
#include <cassert> // for assert()
#include "./Exceptions/ArrayException.h"
#include "MemoryControl/MemoryControl.h"


template <typename T>
class MathVector{
	private:
		T *v;
		int size;

		void initialize( int size);

		void initialize(int size,T *data);

	public:
		MathVector<T>();

		MathVector<T>(int size);

		MathVector<T>(int size,T *data);

		MathVector<T>(const MathVector<T> &V);

		~MathVector<T>();

		int getSize() const{
			return size;
		}

		T* getArray() const{
			return v;
		}

		void set(int element, T value);

		void setX(T value);

		void setY(T value);

		T get(int element) const;

		T getX() const;

		T getY() const;

		T getZ() const;

		double mod();
		//retorna módulo de um vetor

		void makeUnit();
		//transforma o vetor pedido em unitario(sem criar mais espaço)

		template<class Y>
		friend std::ostream& operator<<(std::ostream &out, MathVector<Y> V);

		template<class Y>
		friend MathVector<Y> operator+(MathVector<Y> A, MathVector<Y> B);
		//soma other em main

		template<class Y>
		friend MathVector<Y> operator-(MathVector<Y> A, MathVector<Y> B);

		template<class Y>
		friend MathVector<Y> operator*(MathVector<Y> v, Y a);
		//retorna v*a

		template<class Y>
		friend MathVector<Y> operator*(Y a, MathVector<Y> v);
		//retorna v*a
		MathVector<T>& operator=(const MathVector<T> &v);

		T& operator[] (const int index);

		T& x();

		T& y();

		T& z();

		T dot(MathVector<T> &V) const;

		static MathVector<T> polar(double mod, double angRad);

		static MathVector<T> ones(int size);

		static MathVector<T> zeros(int size);

		static MathVector<T> constant(int size, T value);

		static MathVector<T> array2MathVector(int size, T* data);


		void make3D();

		MathVector<T> cross(MathVector<T> &V) const;
};

#include "MathVector.hpp"
//ao usar templates não podemos separar com um .cpp
#endif /* MathVector_H_ */
