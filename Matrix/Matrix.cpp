#include <iostream>
#include <cstdlib>
#include <cmath>
#include "matrix_header.hpp"
#include <stdio.h>
using namespace std;

int main (){
	
	int size,i,j,z[3][3];
	cout << "Choose Size of Matrix (2 or 3) : ";
	cin >> size;
	cout << "You choose ";
	if(size==2){
	cout << "2 x 2" << endl;
	}
	if(size==3){
	cout << "3 x 3" << endl;
	}
	cout << "Insert Number";
	cout << endl;
	if(size==2){
		int A[2][2];
		for(i=0;i<2;i++){
			for(j=0;j<2;j++){
				cin >> A[i][j];
			}
		}
		cout << "---------------------";
		cout << endl;
		
		cout << "Matrix";
		cout << endl;
		for(i=0;i<2;i++){
			cout << "[ ";
			for(j=0;j<2;j++){
				printf("%3d   ",A[i][j]);
			}
			cout << "] ";
			cout << endl;
		}
		cout << endl;
		
	/*	cout << "transpose";
		cout << endl;
		for(i=0;i<2;i++){
			for(j=0;j<2;j++){
				cout << A[j][i];
				cout << " ";
			}
			cout << endl;
		}
		cout << endl;*/
		
		cout << "determinant : ";
		int det=0;
		det = (A[0][0]*A[1][1]) - (A[0][1]*A[1][0]);
		cout << det;
		cout << endl;
		cout << endl;
		
		cout << "Adjoint";
		cout << endl;
		int AD[2][2];
		AD[0][0] = A[1][1];
		AD[0][1] = -1*A[0][1];
		AD[1][0] = -1*A[1][0];
		AD[1][1] = A[0][0];
		for(i=0;i<2;i++){
			cout << "[ ";
			for(j=0;j<2;j++){
				printf("%3d   ",AD[i][j]);
			}
			cout << " ]";
			cout << endl;
		}
		cout << endl;
		
	}
	if(size==3){
		int A[3][3];
		for(i=0;i<3;i++){
			for(j=0;j<3;j++){
				cin >> A[i][j];
			}
		}
		cout << "---------------------";
		cout << endl;
		
		cout << "Matrix";
		cout << endl;
		for(i=0;i<3;i++){
			cout << "[ ";
			for(j=0;j<3;j++){
				printf("%3d   ",A[i][j]);
			}
			cout << " ]" << endl;
		}
		cout << endl;
		
		cout << "determinant : ";
		int det=0;
		det = (A[0][0]*A[1][1]*A[2][2]) + (A[0][1]*A[1][2]*A[2][0]) + (A[0][2]*A[1][0]*A[2][1]) - (A[2][0]*A[1][1]*A[0][2]) - (A[2][1]*A[1][2]*A[0][0]) - (A[2][2]*A[0][1]*A[1][0]);
		cout << det;
		cout << endl;
		cout << endl;
		
		cout << "Adjoint";
		cout << endl;
		struct Matrix M1;
		M1.m = 3;
		M1.n = 3;
		M1.x[0][0] =  A[0][0]; M1.x[0][1] =  A[0][1]; M1.x[0][2] = A[0][2];
		M1.x[1][0] =  A[1][0]; M1.x[1][1] =  A[1][1]; M1.x[1][2] = A[1][2];
		M1.x[2][0] =  A[2][0]; M1.x[2][1] =  A[2][1]; M1.x[2][2] = A[2][2];
		for(i=1;i<=3;i++){
			for(j=1;j<=3;j++){
				z[i-1][j-1] = Matrix_cofactor(M1, i, j);
			}
		}
		for(i=0;i<3;i++){
			cout << "[ ";
			for(j=0;j<3;j++){
				printf("%3d   ",z[j][i]);
			}
			cout << " ]";
			cout << endl;
		}
	}
	
	
	return 0;
}
