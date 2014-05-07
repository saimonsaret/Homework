#pragma once

template<int dimension>
class Vector {
	public:
		Vector();
		Vector(const double input[dimension]);
		Vector(Vector<dimension> const &vect);
		Vector<dimension> operator+(Vector<dimension> const &vect);
		Vector<dimension> operator-(Vector<dimension> const &vect);
		bool operator==(Vector<dimension> const &vect) const;

		static double scalarMult(Vector<dimension> const &first, Vector<dimension> const &second);
		bool isNull() {
			Vector<dimension> nullVect;
			return (*this == nullVect);
		}
		~Vector() {
			delete coordinates;
		}

	private:
		double *coordinates;
};



template<int dimension>
Vector<dimension>::Vector() {
	coordinates = new double[dimension];
	for (int i = 0; i < dimension; i++)
		coordinates[i] = 0;
}

///Coordinates constructor
template<int dimension>
Vector<dimension>::Vector(const double input[dimension]) {
	coordinates = new double[dimension];
	for (int i = 0; i < dimension; i++)
		coordinates[i] = input[i];
}

///Copy constructor
template<int dimension>
Vector<dimension>::Vector(Vector<dimension> const &vect) {
	coordinates = new double[dimension];
	for (int i = 0; i < dimension; i++)
		coordinates[i] = vect.coordinates[i];
}

template<int dimension>
Vector<dimension> Vector<dimension>::operator+(Vector<dimension> const &vect) {
	Vector<dimension> newVect;
	for (int i = 0; i < dimension; i++)
		newVect.coordinates[i] = this->coordinates[i] + vect.coordinates[i];
	return newVect;
}

template<int dimension>
Vector<dimension> Vector<dimension>::operator-(Vector<dimension> const &vect) {
	Vector<dimension> newVect;
	for (int i = 0; i < dimension; i++)
		newVect.coordinates[i] = this->coordinates[i] - vect.coordinates[i];
	return newVect;
}

template<int dimension>
bool Vector<dimension>::operator==(Vector<dimension> const &vect) const {
	for (int i = 0; i < dimension; i++)
		if (this->coordinates[i] != vect.coordinates[i])
			return false;
	return true;
}

template<int dimension>
double Vector<dimension>::scalarMult(Vector<dimension> const &first, Vector<dimension> const &second) {
	double res = 0;
	for (int i = 0; i < dimension; i++)
		res += first.coordinates[i] * second.coordinates[i];
	return res;
}
