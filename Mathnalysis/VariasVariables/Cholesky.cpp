#include <cstdlib>
#include <iostream>
#include <vector>
#include <cfloat>
#include <math.h>

using namespace std;

void toStringMatrixCR(vector<vector<double> > &matrix)
{
	for (unsigned int i = 0; i < matrix.size(); i++)
	{
		for (unsigned int j = 0; j < matrix[0].size(); j++)
		{
			printf("%f ", matrix[i][j]);
		}
		cout << endl;
	}
	printf("\n");
}


void toStringIn(vector<vector<double> > &matriz, char name) {
	printf("%c matriz\n", name);

	for (unsigned int i = 0; i < matriz.size(); i++) {
		for (unsigned int j = 0; j < matriz[0].size(); j++) {
			if (matriz[i][j] == DBL_MAX) {
				printf("%6c%d%d ", name, j + 1, i + 1);
			}
			else {
				printf("%.6f ", matriz[i][j]);
			}
		}
		cout << endl;
	}
	printf("\n");
}


void inicializar(vector<vector<double> >& L, vector<vector<double> >& U) {
	int N = L.size();
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (i < j) {
				U[i][j] = DBL_MAX;
				L[i][j] = 0;
			}
			else if (i > j) {
				L[i][j] = DBL_MAX;
				U[i][j] = 0;
			}
			else if (i == j) {
				U[i][j] = DBL_MAX;
				L[i][j] = U[i][j];
			}
		}
	}
}

void factorizacionLU(vector<vector<double> >& A, vector<vector<double> >& L, vector<vector<double> >& U, int N) {
	for (int k = 1; k < N + 1; k++) {
		printf("Phase %d\n\n", k);
		toStringIn(L, 'L');
		toStringIn(U, 'U');
		double sum = 0;
		for (int p = 0; p < k - 1; p++) {
			sum += L[k - 1][p] * U[p][k - 1];
		}
		L[k - 1][k - 1] = sqrt(A[k - 1][k - 1] - sum);
		U[k-1][k-1]= L[k-1][k-1];
		for (int i = k + 1; i < N + 1; i++) {
			sum = 0;
			for (int p = 0; p < k - 1; p++) {
				sum += L[i - 1][p] * U[p][k - 1];
			}
			double denominator = U[k - 1][k - 1];
			if (denominator == 0) {
			  //throw div0Exception();
			}
			else {
				L[i - 1][k - 1] = (A[i - 1][k - 1] - sum) / L[k - 1][k - 1];
			}
		}
		for (int j = k + 1; j < N + 1; j++) {
			sum = 0;
			for (int p = 0; p < k - 1; p++) {
				sum += L[k - 1][p] * U[p][j - 1];
			}
			double denominator = L[k - 1][k - 1];
			if (denominator == 0) {
			  //throw div0Exception();
			}
			else {
				U[k - 1][j - 1] = (A[k - 1][j - 1] - sum) / L[k - 1][k - 1];
			}
		}
	}
}

vector<double> sustitucionForward(vector<vector<double> > &L, vector<double> &b) {
	int N = L.size();
	std::vector<double> x(N, 0.0);
	for (int i = 1; i < N + 1; i++)
	{
		double sum = 0;
		for (int p = i - 1; p > 0; p--)
		{
			sum += (L[i - 1][p - 1] * x[p - 1]);
		}
		double denominator = L[i - 1][i - 1];
		if (denominator == 0)
		{
		  //throw div0Exception();
		}
		else
		{
			x[i - 1] = (b[i - 1] - sum) / L[i - 1][i - 1];
		}
	}
	return x;
}

vector<double> sustitucionBackward(vector<vector<double> > &U, vector<double> &z) {
	int N = U.size();
	vector<double> x(N, 0.0);
	for (int i = N - 1; i >= 0; i--) {
		double sum = 0;
		for (int j = i + 1; j < N; j++) {
			sum += U[i][j] * x[j];
		}
		double denominator = U[i][i];
		if (denominator == 0) {
		  //throw div0Exception();
		}
		else {
			x[i] = (z[i] - sum) / U[i][i];
		}
	}
	return x;
}



vector <double> metodoCholesky(vector<vector<double> > A, vector<double> b) {
	int N = A.size();
	vector<double> results;
	vector<vector<double> > L(N, vector<double>(N, 0.0));
	vector<vector<double> > U(N, vector<double>(N, 0.0));
	inicializar(L, U);

	
		factorizacionLU(A, L, U, N);
		printf("Final L matrix\n");
		toStringMatrixCR(L);
		printf("Final U matrix\n");
		toStringMatrixCR(U);
		vector<double> Z = sustitucionForward(L, b);
		printf("z vector\n");
		for (double e : Z) {
			printf("%f ", e);
		}
		printf("\n\n");
		results = sustitucionBackward(U, Z);
	
	return results;
}

/*int main(){
 vector<vector<double> > l(4, vector<double>(4, 0.0));
  l[0][0] = 20;
  l[0][1] = -1;
  l[0][2] = 3;
  l[0][3] = 4;
  l[1][0] = 6;
  l[1][1] = 23;
  l[1][2] = 4;
  l[1][3] = 3;
  l[2][0] = 7;
  l[2][1] = 21;
  l[2][2] = 46;
  l[2][3] = 9;
  l[3][0] = -3;
  l[3][1] = -9;
  l[3][2] = 12;
  l[3][3] = 38;

  
  
  vector<double> m={30.0,-10.0,20.0,-14.0};
  
  vector<double> x=metodoCholesky(l,m);

  for(int i =0; i<4; i++){
    cout << "x" << i << "= " << x[i] << endl;
  }
  
  //toStringIn(a,'a');


  }*/
