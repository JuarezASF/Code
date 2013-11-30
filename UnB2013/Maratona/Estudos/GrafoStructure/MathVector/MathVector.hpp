/*
 * MathVector.cpp
 *
 *  Created on: Nov 6, 2013
 *      Author: juarez
 */


template <typename T>
void MathVector<T>::initialize(int size){
	if(size >= 0)
		{
		this->size = size;
		if(size == 0)
			this->v = 0;
		else{
			this->v = new T[size];
			MemoryControl::pedeMemoria();
			}


		for(int i = 0; i < size; i++)
			set(i, 0);
		}
	else
		throw ArrayException("Argumento inválido recebido por initialize(int)!");
}

template <typename T>
void MathVector<T>::initialize(int size, T *data){
	if(size >= 0)
		{
		this->size = size;
		if(size == 0)
			this->v = 0;
		else
			{
			this->v = new T[size];
			MemoryControl::pedeMemoria();
			}
		for(int i = 0; i < size; i++)
			set(i, data[i]);
		}
	else
		throw ArrayException("Argumento inválido recebido por MathVector(int, *T)!");

	}

template <typename T>
MathVector<T>::MathVector(){
	this->initialize(0);
}

template <typename T>
MathVector<T>::MathVector( int size){
	this->initialize(size);
}

template <typename T>
MathVector<T>::MathVector(int size,T *data){
	this->initialize(size, data);
}

template <typename T>
MathVector<T>::MathVector(const MathVector<T> &V){
	/**
	 * este é o construtor de cópia,
	 * ele é chamado quando:
	 * -When instantiating one object and initializing it with values from another object (as in the example above).
	 *	-When passing an object by value.
	 *	-When an object is returned from a function by value.*/
	this->size = V.getSize();

	if(V.getArray()){
		this->v = new T[size];
		MemoryControl::pedeMemoria();

		for(int i = 0; i < size; i++)
			this->set(i, V.get(i));
	}
}

template <typename T>
MathVector<T> MathVector<T>::array2MathVector(int size, T* data){
	MathVector<T> V(size, data);
	return V;
}

template <typename T>
MathVector<T>::~MathVector(){

	delete[] this->v;
	MemoryControl::liberaMemoria();
}

template <typename T>
void MathVector<T>::set(int element, T value){
	if(element >= 0 && element < this->size)
		this->v[element] = value;

	else
		throw ArrayException("Argumento inválido recebido por set(int, T)!");
}

template <typename T>
void MathVector<T>::setX(T value){
		this->set(0, value);
	}
template <typename T>
void MathVector<T>::setY(T value){
			this->set(1, value);
	}
template <typename T>
T MathVector<T>::get(int element) const{
	if(element < this->size && element >= 0)
		return this->v[element];
	else
		throw ArrayException("Argumento inválido recebido por get(int)!");
}

template <typename T>
T MathVector<T>::getX() const{
	return this->get(0);
}

template <typename T>
T MathVector<T>::getY() const{
	return this->get(1);
}

template <typename T>
T MathVector<T>::getZ() const{
	return this->get(2);
}

template <typename T>
double MathVector<T>::mod(){
	T sum = 0;
	for(int i =0; i < this->size; i++)
		sum += pow(this->get(i), 2);
	return sqrt(sum);
}

template <typename T>
void MathVector<T>::makeUnit(){
	T mod = this->mod();
	for(int i = 0; i < this->size; i++)
		this->set(i, this->get(i)/mod);
	return;
}

template <typename T>
std::ostream& operator<< (std::ostream &out, MathVector<T> V){
	out << "[" ;
	int i;
	for(i = 0; i < V.getSize() - 1; i++)
		out << V.get(i) << " " ;
	out << V.get(i) << "]" ;

	return out;
}

template <typename T>
MathVector<T> operator+(MathVector<T> A, MathVector<T> B){
	if(A.getSize() == B.getSize()){
		T *data;
		data = new T[A.getSize()];
		MemoryControl::pedeMemoria();
		for(int i = 0; i < A.getSize(); i++)
			data[i] = A.get(i) + B.get(i);
		MathVector<T> sum(A.getSize(), data);

		delete[] data;
		MemoryControl::liberaMemoria();
		return sum;
	}
	else
		throw ArrayException
		("Argumento inválido recebido por operator+(MathVector, MathVector)!");
}

template <typename T>
MathVector<T> operator*(MathVector<T> V, T a){
	T *data;
	data = new T[V.getSize()];
	MemoryControl::pedeMemoria();

	for(int i = 0; i < V.getSize(); i++)
		data[i] = V.get(i)*a;
	MathVector<T> product(V.getSize(), data);

	delete[] data;
	MemoryControl::liberaMemoria();
	return product;
}

template <typename T>
MathVector<T> operator*(T a, MathVector<T> V){
	return V*a;
}

template <typename T>
MathVector<T> operator-(MathVector<T> A, MathVector<T> B){
	return A + (-1.0*B);
}

template <typename T>
MathVector<T>& MathVector<T>::operator=(const MathVector<T> &V){
	/**
	 * esse é o operador de igualdade
	 * ele é chamado quando o objeto não precisa ser criado
	 * isto é, supomos que já um objeto alocado*/
	if(this == &V)
		return *this;

	if(this->getSize() > 0){
		delete[] this->v;
		MemoryControl::liberaMemoria();
	}

	this->size = V.getSize();

	if(V.getArray()){

		this->v = new T[size];
		MemoryControl::pedeMemoria();

		for(int i = 0; i < size; i++)
			set(i, V.get(i));

	}

	else
		this->v = NULL;

	return *this;
}

template <typename T>
T& MathVector<T>::operator[] (const int index)
{
	assert(index < getSize());
	assert(index >= 0);
	return v[index];
}

template <typename T>
T& MathVector<T>::x()
{
	return (*this)[0];
}

template <typename T>
T& MathVector<T>::y()
{
	return (*this)[1];
}

template <typename T>
T& MathVector<T>::z()
{
	return (*this)[2];
}

template <typename T>
T MathVector<T>::dot(MathVector<T> &V) const{
	T dot = 0;
	for(int i = 0; i < V.getSize(); i++)
		dot += this->get(i)*V[i];
	return dot;
}

template <typename T>
MathVector<T> MathVector<T>::polar(double mod, double angRad){
	MathVector<T> V(2);
	V.setX(mod*cos(angRad));
	V.setY(mod*sin(angRad));

	return V;
}

template <typename T>
MathVector<T> MathVector<T>::ones(int size){
	MathVector<T> V(size);
	for(int i = 0; i < size; i++)
		V.set(i, 1);
	return V;
}

template <typename T>
MathVector<T> MathVector<T>::zeros(int size){
	MathVector<T> V(size);
		for(int i = 0; i < size; i++)
			V.set(i, 0);
		return V;
}

template <typename T>
MathVector<T> MathVector<T>::constant(int size, T value){
	MathVector<T> V(size);
		for(int i = 0; i < size; i++)
			V.set(i, value);
		return V;
}

template <typename T>
void MathVector<T>::make3D(){
	//transforma um 2d em 3d
	assert(this->size == 2);
	MathVector<T> new3D(3);
	for(int i = 0; i < 2; i++)
		new3D[i] = this->get(i);
	new3D[2] = 0;
	*this = new3D;
}

template <typename T>
MathVector<T> MathVector<T>::cross(MathVector<T> &V) const{
	assert((this->size == 3 || this->size == 2) && this->size == V.getSize());
	MathVector<T> W(*this), cross(3);
	if(this->size == 2){
		W.make3D();
		V.make3D();
	}
	cross[0] = W.getY()*V.getZ() - W.getZ()*V.getY();
	cross[1] = -1*(W.getX()*V.getZ() - W.getZ()*V.getX());
	cross[2] = W.getX()*V.getY() - W.getY()*V.getX();

	return cross;
}

