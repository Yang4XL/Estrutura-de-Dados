#include <iostream>
#include <chrono>
#include <iomanip>

using namespace std;
using namespace std::chrono;

const int ARRAY_SIZE[] = {10, 100, 1000, 10000, 100000};
const int QTD_EXECUCAO = 5;

void arrayAletoria(int arr[], int posicao)
{
  for (int i = 0; i < ARRAY_SIZE[posicao]; i++)
  {
    arr[i] = (rand());
  }
}

void insertionSort(int arr[], int tamanhoArr)
{
  int i, key, j;

  for (i = 1; i < tamanhoArr; i++)
  {
    key = arr[i];
    j = i - 1;

    while (j >= 0 && arr[j] > key)
    {
      arr[j + 1] = arr[j];
      j = j - 1;
    }

    arr[j + 1] = key;
  }
}

void imprimirArray(int arr[], int tamanhoArr)
{
  int i;

  for (i = 0; i < tamanhoArr; i++)
    cout << arr[i] << " ";

  cout << endl;
}

int main()
{
  double tempoMedioAux = 0;
  for (int i = 0; i < QTD_EXECUCAO; i++)
  {
    tempoMedioAux = 0;

    for (int y = 0; y < QTD_EXECUCAO; y++)
    {
      auto start = high_resolution_clock::now();

      int arr[ARRAY_SIZE[i]];
      arrayAletoria(arr, i);
      int tamanhoArr = sizeof(arr) / sizeof(arr[0]);
      insertionSort(arr, tamanhoArr);
      cout << "Array após ordenação: \n";
      imprimirArray(arr, tamanhoArr);
      auto stop = high_resolution_clock::now();

      auto duration = duration_cast<milliseconds>(stop - start);
      tempoMedioAux = tempoMedioAux + duration.count();
    }

    cout << "O tempo médio em milissegundos para executar a ordenação de " + to_string(ARRAY_SIZE[i]) + " números: " << fixed
         << (tempoMedioAux / 5) << setprecision(15);
    cout << endl;
    cout << endl;
  }

  return 0;
}