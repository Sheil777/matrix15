#include "Header.h"
#include <random>

void setArr(double **arr, int size)
{
	for (int i = 0; i<size; i++)
		arr[i] = new double[size];

	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			arr[i][j] = rand() % 10;

}