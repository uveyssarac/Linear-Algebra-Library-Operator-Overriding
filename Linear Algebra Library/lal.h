#include <iostream>
#define LAL_H_


using namespace std;

class Matrix {
protected:
    double* entries;
    int rows;
    int cols;

public:
    Matrix();
    Matrix(double*, int, int);
    ~Matrix();
    void print();
    Matrix operator+(const Matrix&);
	Matrix operator-(const Matrix&);
	Matrix operator*(const Matrix&);
	bool operator==(const Matrix&);
	
	
};

class Vector : public Matrix {
double l2norm;
public:
    Vector(double*, int);
    Vector();
    ~Vector();
    void print();
    Vector operator+(const Vector&);
    Vector operator-(const Vector&);
	int operator*(const Vector&);
	Vector& operator++();       // prefix 
    Vector operator++(int);		// postfix
    void setEntries(double*);
    void setRows(int);
};

