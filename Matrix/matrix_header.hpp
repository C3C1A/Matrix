#include <iostream>
using namespace std;

struct Matrix {
	int m;
	int n;
	double x[10][10];
};

struct Matrix Phi;

void Matrix_init(){
Phi.m = 0;
Phi.n = 0;
}

void Matrix_disp(struct Matrix A){
	for(int i = 0;i < A.m;i ++){
		cout << "[ ";
		for(int j = 0;j < A.n;j ++){
			if(A.x[i][j] >= 0 && A.x[i][j] < 10) cout << " ";
			cout << A.x[i][j] << " ";
		}
		cout << "]" << endl;
	}
	cout << endl;
}

struct Matrix Matrix_add(struct Matrix A, struct Matrix B){
	if(A.m != B.m || A.n != B.n) {
		cout << "Error!";
		return Phi;
	}
	struct Matrix C;
	C.m = A.m;
	C.n = A.n;
	for(int i = 0;i < A.m;i ++){
		for(int j = 0;j < A.n;j ++){
			C.x[i][j] = A.x[i][j] + B.x[i][j];
		}
	}
	return C;
}

struct Matrix Matrix_subt(struct Matrix A, struct Matrix B){
	if(A.m != B.m || A.n != B.n) {
		cout << "Error!";
		return Phi;
	}
	struct Matrix C;
	C.m = A.m;
	C.n = A.n;
	for(int i = 0;i < A.m;i ++){
		for(int j = 0;j < A.n;j ++){
			C.x[i][j] = A.x[i][j] - B.x[i][j];
		}
	}
	return C;
}

struct Matrix Matrix_scalar_mult(int k, struct Matrix A){
	struct Matrix C;
	C.m = A.m;
	C.n = A.n;
	for(int i = 0;i < A.m;i ++){
		for(int j = 0;j < A.n;j ++){
			C.x[i][j] = A.x[i][j] * k;
		}
	}
	return C;
}

struct Matrix Matrix_mult(struct Matrix A, struct Matrix B){
	if(A.n != B.m) {
		cout << "Error!";
		return Phi;
	}
	struct Matrix C;
	C.m = A.m;
	C.n = B.n;
	for(int i = 0; i < A.m; i ++){
		for(int j = 0;j < B.n;j ++){
			C.x[i][j] = 0;
			for(int k = 0;k < A.n;k ++){
				C.x[i][j] += (A.x[i][k] * B.x[k][j]);
			}
		}
	}
	return C;
}

struct Matrix Matrix_T(struct Matrix A){
	struct Matrix C;
	C.m = A.n;
	C.n = A.m;
	for(int i = 0;i < A.m;i ++){
		for(int j = 0;j < A.n;j ++){
			C.x[j][i] = A.x[i][j];
		}
	}
	return C;
}

double Matrix_det(struct Matrix A){
	if(A.m != A.n){
		cout << "Error!";
		return -999;
	}
	if(A.m == 1){
		return A.x[0][0];
	}
	double ret = 0;
	for(int k = 0;k < A.n;k ++){
		struct Matrix C;
		C.m = A.m - 1;
		C.n = A.n - 1;
		for(int i = 1;i < A.m;i ++){
			for(int j = 0;j < A.n;j ++){
				if(j == k) continue;
				if(j > k) C.x[i - 1][j - 1] = A.x[i][j];
				else C.x[i - 1][j] = A.x[i][j];
			}
		}
		/*
		cout << (k % 2 ? 1 : -1) * A.x[0][k] << " x " << endl;
		Matrix_disp(C);
		cout << "ret += : " << (k % 2 ? -1 : 1) * A.x[0][k] * Matrix_det(C) << endl;
		*/
		ret += (k % 2 ? -1 : 1) * A.x[0][k] * Matrix_det(C);
	}
	return ret;
}

double Matrix_minor (struct Matrix A, int pos_i, int pos_j){
	struct Matrix C;
	pos_i --;
	pos_j --;
	C.m = A.m - 1;
	C.n = A.n - 1;
	for(int i = 0;i < A.m;i ++){
		if(i == pos_i) continue;
		for(int j = 0;j < A.n;j ++){
			if(j == pos_j) continue;
			if(i > pos_i && j > pos_i) C.x[i - 1][j - 1] = A.x[i][j];
			else if(i > pos_i) C.x[i - 1][j] = A.x[i][j];
			else if(j > pos_j) C.x[i][j - 1] = A.x[i][j];
			else C.x[i][j] = A.x[i][j];
		}
	}
	return Matrix_det(C);
}

double Matrix_cofactor (struct Matrix A, int pos_i, int pos_j){
	if((pos_i + pos_j) % 2) return -Matrix_minor(A, pos_i, pos_j);
	return Matrix_minor(A, pos_i, pos_j);
}

struct Matrix Matrix_inv(struct Matrix A){
	if(A.m != A.n){
		cout << "Error!";
		return Phi;
	}
	struct Matrix C;
	C.m = A.m;
	C.n = A.n;
	for(int i = 0;i < C.m;i ++){
		for(int j = 0;j < C.n;j ++){
			C.x[i][j] = Matrix_cofactor(A, i + 1, j + 1) / Matrix_det(A);
		}
	}
	return Matrix_T(C);
}
