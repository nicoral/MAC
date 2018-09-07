#include <iostream>
#include <cmath>
#include <time.h>
#include <vector>
using namespace std;
typedef vector<vector<int>> matri;

void mostrar_matriz(matri &matriz);
int determinante(matri &matriz);
int cofactor(matri &matriz, int fila, int columna);
void cramer(matri &matriz,matri &res);
void llenar_matriz(matri &matriz);


int main()
{
   
   int orden;
   cout << "Ingresa el orden de la matriz: ";
   cin >> orden;
   matri matr(orden,vector<int>(orden));
   llenar_matriz(matr);
   mostrar_matriz(matr);
   
   cout << "\nEl determinante es: " << determinante(matr) << endl;
   matri res(orden,vector<int>(1));
   llenar_matriz(res);
   mostrar_matriz(res);
   cramer(matr,res);
   return 0;
}
void llenar_matriz(matri &matriz)
{
   int filas=matriz.size();
   int columnas=matriz[0].size();
   srand(time(NULL));
   int rando;
   cout << "\nIngrese los elementos de la matriz:\n\n";
   for (int i = 0; i < filas; i++) 
   {
      for (int j = 0; j < columnas; j++) 
      {
         rando = 1 + rand()%(30)-10;
         matriz[i][j]=rando;
         //cin >> matriz[i][j];
      }
   }
}
void mostrar_matriz(matri &matriz)
{
   int filas=matriz.size();
   int columnas=matriz[0].size();
   for (int i = 0; i < filas; i++) {
      for (int j = 0; j < columnas; j++) {
         cout << "\t" << matriz[i][j];
      }
      cout << "\n";
   }
   cout << "\n";
}
int determinante(matri &matriz)
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
int cofactor(matri &matriz, int fila, int columna)
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
void cramer(matri &matriz,matri &res)
{
   int filas=matriz.size();
   int columnas=matriz[0].size();
   double *respuestas=new double[filas];
   double detMA=determinante(matriz);
   if(detMA!=0)
   {
      cout<<"\t\t Metodo Cramer \n\n";
      int x=0,y=0;
      matri aux;
      for(int i=0;i<filas;i++)
      {
         aux=matriz;
         for(int j=0;j<filas;j++)
         {
            aux[j][x]=res[y][0];
            y++;
         }
         respuestas[i]=determinante(aux)/detMA;
         x++;
         y=0;
         mostrar_matriz(aux);

      }
      for(int i=0;i<filas;i++)
      {
         cout<<"X"<<i<<"= "<<respuestas[i]<<"\n";
      }
   }
   else
      cout<<"La determinante es 0 por lo que el Metodo Cramer no funcionaria. \n";

}