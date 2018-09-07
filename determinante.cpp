#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
typedef vector<vector<int>> matri;

void mostrar_matriz(matri matriz);
int determinante(matri matriz);
int cofactor(matri matriz, int fila, int columna);

int main()
{
   
   int orden;
   
   cout << "Ingresa el orden de la matriz: ";
   cin >> orden;
   matri matriz(orden,vector<int>(orden));
   cout << "\nIngrese los elementos de la matriz:\n\n";
   for (int i = 0; i < orden; i++) 
   {
      for (int j = 0; j < orden; j++) 
      {
         cin >> matriz[i][j];
      }
   }

   mostrar_matriz(matriz);
   
   cout << "\nEl determinante es: " << determinante(matriz) << endl;

   return 0;
}

void mostrar_matriz(matri matriz)
{
   int orden=matriz.size();
   for (int i = 0; i < orden; i++) {
      for (int j = 0; j < orden; j++) {
         cout << "\t" << matriz[i][j];
      }
      cout << "\n";
   }
}
int determinante(matri matriz)
{
   int det = 0.0;
   int orden=matriz.size();
   if (orden == 1) 
   {
      det = matriz[0][0];
   }
   else if(orden==2)
   {
      det = matriz[0][0]*matriz[1][1]-matriz[0][1]*matriz[1][0];
   } 
   else 
   {
      for (int j = 0; j < orden; j++) 
      {
         det = det + matriz[0][j] * cofactor(matriz, 0, j);
      }
   }
   
   return det;
}
int cofactor(matri matriz, int fila, int columna)
{
   int orden=matriz.size();
   matri submatriz(orden-1,vector<int>(orden-1));
   int n = matriz.size() - 1; 
   int x = 0,y = 0;
   for (int i = 0; i < orden; i++) {
      for (int j = 0; j < orden; j++) {
         if (i != fila && j != columna) {
            submatriz[x][y] = matriz[i][j];
            y++;
            if (y >= n) {
               x++;
               y = 0;
            }
         }
      }
   }
   
   return pow(-1.0, fila + columna) * determinante(submatriz);
}