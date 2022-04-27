#include <iostream>
#include <cstdlib>
#include <ctime>
#include "lal.h"
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int i,j, row=3,col=3, row2=3, col2=3;
	int p=3,m=3;
	srand(time(NULL));
	
	double dizi[row*col];
	for(i=0; i<row*col; i++){
	dizi[i]=rand()%10;
	}
	
	double dizi2[row2*col2];
	for(i=0; i<row2*col2; i++){
	dizi2[i]=rand()%10;
	}
	cout <<"---M1---";
	Matrix m1(dizi,row,col);    //  M1 MATRÝSÝ OLUÞTURMA
	m1.print();
	cout <<"---M2---";
	Matrix m2(dizi2,row2,col2); //  M2 MATRÝSÝ OLUÞTURMA
	m2.print();	
	cout <<"---M1+M2---";
	Matrix m3=m1+m2;			//  M1+M2 OPERATOR OVERLOADING
	m3.print();
//	cout <<"---M1-M2---";
	Matrix m4=m1-m2;			//  M1-M2 OPERATOR OVERLOADING
	m4.print();
	
	Matrix m5;					//  M1*M2 OPERATOR OVERLOADING
	m5=m1 * m2;
	m5.print();
	
	cout <<"----------------------------"<< endl;
	Vector v;
	
	Vector *vectorArray;
	vectorArray = (Vector*)malloc(m * sizeof(Vector));
	double dizi3[p];
	for(i=0; i<m; i++){
		for(j=0; j<p; j++){
		dizi3[j]=rand()%10;
		}
	v.setRows(p);
	v.setEntries(dizi3);
	vectorArray[i]=v;
	vectorArray[i].print();
	cout<<" "<<endl;
	}
	cout<<"M1 M2 ESIT MI(== OVERLOADING)?"<<endl;
	bool ctrl=m1==m2;
	cout <<ctrl<< endl;
	cout<<"-------------"<<endl;
//----------------------------------------------//	
	
	double dizi4[5];
	for(i=0; i<5; i++){
	dizi4[i]=rand()%10;
}
	cout<<"V++ ve ++V OVERLOADING (V1)"<<endl;
	Vector v1(dizi4, 5);				// ++V VE V++ OVERLOADING
	v1.print();
	cout<<"-------------"<<endl;
	v1++;
	v1.print();
	cout<<"-------------"<<endl;
	++v1;
	v1.print();
	
//----------------------------------------------//	
	cout<<"-------------"<<endl;
	double dizi5[5];
	for(i=0; i<5; i++){
	dizi5[i]=rand()%10;
	}
	Vector v2(dizi5, 5);
	cout<<"---V1---"<<endl;
	v1.print();
	cout<<"-------------"<<endl;
	cout<<"---V2---"<<endl;
	v2.print();
	cout<<"-------------"<<endl;
	cout<<"VEKTOR TOPLAMI(V1+V2)"<<endl;
	Vector v3=v1+v2;
	v3.print();
	cout<<"VEKTOR CIKARMA(V1-V2)"<<endl;
	Vector v4=v1-v2;
	v4.print();
	cout<<"VEKTOR IC CARPIMI(V1*V2)"<<endl;
	int v5=v1*v2;
	cout<<v5<<endl;		
	cout<<"V1 V2 ESIT MI(== OVERLOADING)?"<<endl;
	bool ctrl1=v1==v2;
	cout <<ctrl1<< endl;
	cout<<"-------------"<<endl;
	cout<<"Matris vektor carpimi(M1*V1)"<<endl;
	Matrix m6=m1*v1;
	m6.print();
	return 0;
}
