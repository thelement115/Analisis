
// Cholesky Decomposition 
#include <bits/stdc++.h> 
using namespace std; 
  
const int MAX = 100; 
  
void Cholesky(int matrix[][MAX],  
                                      int n) 
{ 
    int lower[n][n]; 
    memset(lower, 0, sizeof(lower)); 
  
    // volver la matriz triangular
    for (int i = 0; i < n; i++) { 
        for (int j = 0; j <= i; j++) { 
            int sum = 0; 
  
            if (j == i) // sumar diagonales 
            { 
                for (int k = 0; k < j; k++) 
                    sum += pow(lower[j][k], 2); 
                lower[j][j] = sqrt(matrix[j][j] - 
                                        sum); 
            } else { 
  
                 
                for (int k = 0; k < j; k++) 
                    sum += (lower[i][k] * lower[j][k]); 
                lower[i][j] = (matrix[i][j] - sum) / 
                                      lower[j][j]; 
            } 
        } 
    } 
  
     
    cout << setw(6) << " Lower Triangular"  
         << setw(30) << "Transpose" << endl; 
    for (int i = 0; i < n; i++) { 
          
         
        for (int j = 0; j < n; j++) 
            cout << setw(6) << lower[i][j] << "\t"; 
        cout << "\t"; 
          
         
        for (int j = 0; j < n; j++) 
            cout << setw(6) << lower[j][i] << "\t"; 
        cout << endl; 
    } 
} 
  
 
int main() 
{ 
    int n = 3; 
    int matrix[][MAX] = { { 1, -3, 0 }, 
                        { -3, 27, 15 }, 
                        { 0, 15, 17 } }; 
    Cholesky(matrix, n); 
    return 0; 
} 