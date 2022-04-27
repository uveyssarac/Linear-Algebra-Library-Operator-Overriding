#include <iostream>
#include "lal.h"
#include "math.h"

using namespace std;

Matrix::Matrix(double* dizi, int satir, int sutun) {
	entries = dizi;
	rows = satir;
	cols = sutun;
}
Matrix::Matrix(){}
Matrix::~Matrix(){} 

void Matrix::print() {
    for (int i = 0; i < this->rows * this->cols; i++) {
        if (i % cols == 0) {
            cout << endl;
        }
        cout << entries[i] << " ";
    }
    cout << endl;
}
	Matrix Matrix::operator+(const Matrix& m1) {
		int i;
		Matrix m;
		m.rows=m1.rows;
		m.cols=m1.cols;
		double dizi[m1.rows*m1.cols];
			
		if(rows==m1.rows && cols==m1.cols){

			for(i=0; i<m1.rows*m1.cols; i++){
				m.entries[i]=entries[i] + m1.entries[i];
		}
		return m;
		}else{
//			for(i=0; i<m1.rows*m1.cols; i++){
//				m.entries[i]=0;
//		}
		cout<<"islem gecersiz: boyut uyumsuzlugu!"<<endl;
		return m;
	}
//	return Matrix(m.entries, m.rows, m.cols);
	}
	Matrix Matrix::operator-(const Matrix& m1) {
		int i;
		Matrix m;
		m.rows=m1.rows;
		m.cols=m1.cols;
		double dizi[m1.rows*m1.cols];	
		if(rows==m1.rows && cols==m1.cols){

			for(i=0; i<m1.rows*m1.cols; i++){
				m.entries[i]=entries[i] - m1.entries[i];
		}
		}else{
			for(i=0; i<m1.rows*m1.cols; i++){
				m.entries[i]=0;
		}	
	}
	return Matrix(m.entries, m.rows, m.cols);
	}
	Matrix Matrix::operator*(const Matrix& m1) {
		int i,j,k,h ;
		Matrix m;
		m.rows=rows;
		m.cols=m1.cols;
		m.entries[m.rows*m.cols];
		if(cols==m1.rows){
			for (int i = 0; i < rows; i++) {
        		for (int j = 0; j < m1.cols; j++) {
            		int sum = 0;
            		for (int k = 0; k < m1.rows; k++)
                		sum = sum + entries[i * cols + k] * m1.entries[k * m1.cols + j];
			  			m.entries[i * m.cols + j] = sum;
        		}

    		}
    		return m;
		}else{
		cout<<"islem gecersiz: boyut uyumsuzlugu!"<<endl;
		return m;
			}
		
		
	}
	
	bool Matrix::operator==(const Matrix& m1)   {
		bool ctrl=true;
		int i;
		for(i=0; i<rows*cols;i++){
			if(rows==m1.rows && cols==m1.cols){
				if(entries[i]!=m1.entries[i]){
					ctrl=false;
					break;
				}
			}	
		}
		return ctrl;
	}

	Vector::Vector(double* dizi, int satir) {
    entries = dizi;
    rows = satir;
    cols=1;
    int toplam = 0;
    
    for (int i = 0; i < rows; i++){
	toplam =toplam + entries[i] * entries[i];
	} 
    this->l2norm=sqrt(toplam);
   
}
	Vector::Vector() {}
	Vector::~Vector() {}

	void Vector::print() {
    for (int i = 0; i < rows ; i++) {

        cout << entries[i] << endl;
   	}
}

	Vector Vector::operator+(const Vector& v1) {
		int i;
		Vector v;
		v.rows=v1.rows;
		double dizi[v.rows];
		for(i=0; i<v1.rows; i++){
		v.entries[i]=entries[i] + v1.entries[i];
		}
		return v;
	}
	
	Vector Vector::operator-(const Vector& v1) {
		int i;
		Vector v;
		v.rows=v1.rows;
		double dizi[v.rows];
		for(i=0; i<v1.rows; i++){
		v.entries[i]=entries[i] - v1.entries[i];
		}
		return v;
	}
	
	int Vector::operator*(const Vector& v1) {
		int iccarpim=rows*v1.rows;
		return iccarpim;
	}
	
	Vector& Vector::operator++(){   //PREFÝX
		int i;
    	for(i=0; i<rows; i++){
    		++entries[i];
		}
    	return *this;
	}
	
	Vector Vector::operator++(int){  //POSTFÝX
		int i;
    	Vector temp = *this;
    	for(i=0; i<rows; i++){
    		++(this->entries[i]);
		}
   		return temp;
	}
	
	void Vector::setEntries(double* entries){
		this->entries=entries;
		
	} 
	
	void Vector::setRows(int rows){
		this->rows=rows;
		
	}
