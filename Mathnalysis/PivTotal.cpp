#include <cstdlib>
#include <iostream>
#include <vector>
#include <cfloat>

using namespace std;

vector<vector<double>> swapRows(vector<vector<double>> Ab, int filaMayor, int k){
  
    vector<double> aux = Ab[k];

    Ab[k]=Ab[filaMayor];
    Ab[filaMayor]=aux;

    return Ab;
}

vector<vector<double>> swapCol(vector<vector<double>> Ab, int colMayor, int k){
  int n= Ab.size();
  std::swap(Ab[colMayor], Ab[k]);

    return Ab;
}

vector<vector <double> > pivParcial (vector<vector<double>> &Ab, int n, int k){
  double mayor = 0;
  double filaMayor = k;
  double columnaMayor=k;
  for (int r=k;r<n;r++){
    for(int s=k+1;s<n; s++){
     if (abs(Ab[s][k]) > mayor){
       mayor=abs(Ab[r][s]);
       filaMayor=r;
       columnaMayor=s;
    }
   }
  }  
    if(mayor==0){
      cout << "El sistema no tiene solucion unica";
    } else {
      if(filaMayor != k){
        Ab=swapRows(Ab,filaMayor,k);
      }else if(columnaMayor != k){
	Ab=swapCol(Ab,columnaMayor,k);
	#marcas
      }
    

  
  return Ab;
}

vector<vector<double> > formaMatrizAumentada(vector<vector<double> > a, vector<double> b, int n){
    vector<vector<double> > aumentada(n, vector<double>(n+1, 0.0));
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            aumentada[i][j] = a[i][j];
        }
    }
    for(int i=0; i<n; i++){
        aumentada[i][n] = b[i];
    }

    return aumentada;
}

vector <double> EliminacionGauss(vector<vector<double>> &A, vector<double> b, int n){
  vector<double> x(n, 0.0);
  vector<vector<double> > Ab(n, vector<double>(n+1, 0.0));
  Ab = formaMatrizAumentada(A,b,n);

  }


vector<vector<double>> EliminacionGaussPivoteo(vector<vector<double> > &Ab,int n){
  for(int k =0; k<n-1; k++){
    Ab = pivParcial(Ab,n,k);
    double multiplicador;
    for(int i=k+1; i<n; i++){
      multiplicador = (Ab[i][k]/Ab[k][k]);
      for(int j=k; j<n+1; j++){
        Ab[i][j]=(Ab[i][j]-(multiplicador*Ab[k][j]));
      }
    }
  }
  return Ab;
}

  vector<double> sustitucionBackward(vector<vector<double> > Ab, int n) {
    vector<double> x(n, 0.0);
    x[n]= (Ab[n][n+1]/Ab[n][n]);
        for (int i = n - 1; i >= 0; i--) {
          double sum = 0;
          for (int j = i + 1; j < n; j++) {
            sum += sum+(Ab[i][j]*x[j]);
          }
double denominator = Ab[i][i];
          if (denominator == 0) {
            printf("ERROR");
          }
          else {
            x[i] = (Ab[i][n+1] - sum) / Ab[i][i];
          }
        }
        return x;
}


  void toStringIn(vector<vector<double> > &matriz, char name) {
        printf("%c matriz\n", name);

        for (unsigned int i = 0; i < matriz.size(); i++){
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
int main() {
  vector<vector<double> > l(2, vector<double>(2, 0.0));
  l[0][0] = 1;
  l[0][1] = 2;
  l[1][0] = 3;
  l[1][1] = 4;

  vector<double> m(2, 3.4);

  vector<vector<double> > a = formaMatrizAumentada(l,m,2);

  toStringIn(a,'a');

}
