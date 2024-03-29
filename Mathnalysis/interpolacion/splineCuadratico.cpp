#include <cstdlib>
#include <iostream> 
#include <vector>
#include <cmath>
#include "splineCuadratico.h"
#include "..\VariasVariables\PivParcial.h"
#include <string>

using namespace std;


void toStringdcuadratico(vector<vector<double> > &matrix) {
  for (unsigned int i = 0; i < matrix.size(); i++)
	{
		for (unsigned int j = 0; j < matrix[0].size(); j++)
		{
			try{
				printf("%f ", matrix[i][j]);
			}catch(exception e){
				cout << e.what() << endl;
			}	
		}
		cout << endl;
	}
	printf("\n");
}

void interpCuadratica(vector<double> &xn, vector<double> &fxn){
  string output = "";
  int n = (xn.size() - 1) * 3;
  vector<vector<double> > Ab(n, vector<double>(n+1,0.0));
  int i = 0;
  for (int j = 0; j < xn.size() - 1; j++) {
    Ab[i][(j * 3)] = pow(xn[j], 2);
    Ab[i][(j * 3) + 1] = xn[j];
    Ab[i][(j * 3) + 2] = 1;
    Ab[i][n] = fxn[j];
    i++;
  }
  for (int j = 1; j < xn.size(); j++) {
    j--;
    Ab[i][(j * 3) ] = pow(xn[(j+1)], 2);
    Ab[i][(j * 3) + 1] = xn[j+1];
    Ab[i][(j * 3) + 2] = 1;
    j++;
    Ab[i][n] = fxn[j];
    i++;
  }

  for (int j = 1; j < xn.size() - 1; j ++) {
    j--;
    Ab[i][(j * 3)] = 2 * xn[(j+1)];
    Ab[i][(j * 3) + 1] = 1;
    Ab[i][(j * 3) + 3] = -2 * xn[(j+1)];
    Ab[i][(j * 3) + 4] = -1;
    j++;
    i++;
  }
  Ab[i][0] = 2 * xn[0];
  Ab[i][1] = 1;

  toStringdcuadratico(Ab);

  string ecuaciones = "Sistema de ecuaciones Ab\n";
  vector<vector<double> > A(n,vector<double>(n,0.0));
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      A[i][j] = Ab[i][j];
    }
  }
  vector<double> b(n, 0.0);
  for(int i=0; i<n; i++){
    b[i] = Ab[i][n];
  }
  vector<double> rVector = EliminacionGauss(Ab, b, n);
  n = xn.size();

  for (int j = 0; j < n -1; j++) {
    ecuaciones += std::to_string((float) rVector[j*3]) + " x^2 ";
    ecuaciones += std::to_string((float)rVector[j*3+1]) + " x ";
    ecuaciones += std::to_string((float)rVector[j*3+2]);
    ecuaciones += ", " + std::to_string(xn[(j)]) + "<= x <= " + std::to_string(xn[j+1]) + " \n";
  }
  cout << ecuaciones << endl;
}




