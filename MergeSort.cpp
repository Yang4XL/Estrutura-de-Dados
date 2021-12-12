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

void merge(int arr[], int p, int q, int r)
{
  int n1 = q - p + 1;
  int n2 = r - q;

  int L[n1], M[n2];

  for (int i = 0; i < n1; i++)
    L[i] = arr[p + i];
  for (int j = 0; j < n2; j++)
    M[j] = arr[q + 1 + j];

  int i, j, k;
  i = 0;
  j = 0;
  k = p;

  while (i < n1 && j < n2)
  {
    if (L[i] <= M[j])
    {
      arr[k] = L[i];
      i++;
    }
    else
    {
      arr[k] = M[j];
      j++;
    }
    k++;
  }

  while (i < n1)
  {
    arr[k] = L[i];
    i++;
    k++;
  }

  while (j < n2)
  {
    arr[k] = M[j];
    j++;
    k++;
  }
}

void mergeSort(int arr[], int l, int r)
{
  if (l < r)
  {

    int m = l + (r - l) / 2;

    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);

    merge(arr, l, m, r);
  }
}

void imprimirArray(int arr[], int tamanhoArr)
{
  for (int i = 0; i < tamanhoArr; i++)
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
      mergeSort(arr, 0, tamanhoArr - 1);
      cout << "Array após ordenação de " + to_string(ARRAY_SIZE[i]) + " números: " << endl;
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