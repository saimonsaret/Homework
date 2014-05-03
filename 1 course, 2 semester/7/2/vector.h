#pragma once

template<int dimension>
class Vector {
	public:
		Vector() {
			coordinates = new double[dimension];
			for (int i = 0; i < dimension; i++)
				coordinates[i] = 0;
		}
		Vector(const double input[dimension]) {
			coordinates = new double[dimension];
			for (int i = 0; i < dimension; i++)
				coordinates[i] = input[i];
		}
		Vector(Vector<dimension> const &vect) {
			coordinates = new double[dimension];
			for (int i = 0; i < dimension; i++)
				coordinates[i] = vect.coordinates[i];
		}
		Vector<dimension> &operator+(Vector<dimension> const &vect) {
			Vector<dimension> *newVect = new Vector<dimension>;
			for (int i = 0; i < dimension; i++)
				newVect->coordinates[i] = this->coordinates[i] + vect.coordinates[i];
			return *newVect;
		}
		Vector<dimension> &operator-(Vector<dimension> const &vect) {
			Vector<dimension> *newVect = new Vector<dimension>;
			for (int i = 0; i < dimension; i++)
				newVect->coordinates[i] = this->coordinates[i] - vect.coordinates[i];
			return *newVect;
		}
		bool operator==(Vector<dimension> const &vect) const {
			for (int i = 0; i < dimension; i++)
				if (this->coordinates[i] != vect.coordinates[i])
					return false;
			return true;
		}
		static double scalarMult(Vector<dimension> const &first, Vector<dimension> const &second) {
			double res = 0;
			for (int i = 0; i < dimension; i++)
				res += first.coordinates[i] * second.coordinates[i];
			return res;
		}
		bool isNull() {
			Vector<dimension> nullVect;
			return (*this == nullVect);
		}
		~Vector() {
		}

	private:
		double *coordinates;
};
