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

void trocarPosicao(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void bubbleSort(int arr[], int tamanhoArr)
{
    int i, j;

    for (i = 0; i < tamanhoArr - 1; i++)
        for (j = 0; j < tamanhoArr - i - 1; j++)
            if (arr[j] > arr[j + 1])
                trocarPosicao(&arr[j], &arr[j + 1]);
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
            bubbleSort(arr, tamanhoArr);
            cout << "Array após ordenação de " + to_string(ARRAY_SIZE[i]) + " números: " << endl;
            imprimirArray(arr, tamanhoArr);

            auto stop = high_resolution_clock::now();

            auto duration = duration_cast<seconds>(stop - start);
            tempoMedioAux = tempoMedioAux + duration.count();
        }

        cout << "O tempo médio em segundos para executar a ordenação de " + to_string(ARRAY_SIZE[i]) + " números: " << fixed
             << (tempoMedioAux / 5) << setprecision(15);
        cout << endl;
        cout << endl;
    }

    return 0;
}