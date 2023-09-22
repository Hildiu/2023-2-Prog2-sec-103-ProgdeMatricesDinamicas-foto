/*---------------------------------------
 * Dato de Entrada: filas, col (int)
 * Dato de Salida: segunda matriz (char)
 -----------------------------------------*/

#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
  int filas, col;

  cout << "Filas : ";
  cin >> filas;
  cout << "Columnas: ";
  cin >> col;

  int **pM1 = new int*[filas];
  for(int f=0; f<filas; f++)
      pM1[f] = new int[col];
  //----- llenamos datos a la matriz-----
  for(int f=0; f<filas; f++)
      for(int c=0; c<col; c++)
          pM1[f][c] = rand() % 10;
  //---- imprimimos la matriz-----
  cout << "\n";
  for(int f=0; f<filas; f++)
  {
      for(int c=0; c<col; c++)
          cout << setw(3) << pM1[f][c];
      cout << "\n";
  }
  //---- formamos la segunda  matriz---
  char **pCar = new char*[filas];
  for(int f=0; f<filas; f++)
      pCar[f] = new char[col];
  //------llenar la matriz de caracteres ----
    for(int f=0; f<filas; f++)
        for(int c=0; c<col; c++) {
            if (pM1[f][c] == 0)
                pCar[f][c] = '.';
            if (pM1[f][c] == 1 or pM1[f][c] == 2 or pM1[f][c] == 3)
                pCar[f][c] = '-';
            if (pM1[f][c] == 4 or pM1[f][c] == 5 or pM1[f][c] == 6)
                pCar[f][c] = '#';
            if (pM1[f][c] == 7 or pM1[f][c] == 8 or pM1[f][c] == 9)
                pCar[f][c] = '*';
        }
    //--- imprimimos la segunda matriz-----
    cout << "\n";
    for(int f=0; f<filas; f++)
    {
        for(int c=0; c<col; c++)
            cout << setw(3) << pCar[f][c];
        cout << "\n";
    }
    //---- liberamos memoria de la primera matriz
    for(int f=0; f<filas; f++)
        delete []pM1[f];
    delete []pM1;
    pM1 = nullptr;
    //---- liberamos la segunda matriz
    for(int f=0; f<filas; f++)
        delete []pCar[f];
    delete []pCar;
    pCar = nullptr;
    return 0;
}
