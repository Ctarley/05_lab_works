#include <iostream>

#include <Windows.h>

using namespace std;

void mergeSort(int data[], int lenD);
void merge(int merged[], int lenD, int L[], int lenL, int R[], int lenR);

int main(int argc, char const *argv[])
{
	int size;
	int choise;
	int module;
	int action;

	cout << "Input size of array:";

	cin >> size;
	int *arr = new int[size];

	cout << "Choose the method of filling:" << endl;
	cout << "1.Random filling" << endl;
	cout << "2.Hand filling" << endl;
	cin >> choise;

	switch (choise)
	{
	case 1:
	{
		cout << "Choose the module:";
		cin >> module;

		for (int i = 0; i < size; ++i)
			arr[i] = rand() % module;
		break;
	}

	case 2:
	{
		for (int i = 0; i < size; ++i)
			cin >> arr[i];
		break;
	}

	case 3:
	{
		return 0;
	}
	}



	while (true)
	{
		cout << "Choose action:" << endl;
		cout << "1.Sort array" << endl;
		cout << "2.Print array" << endl;
		cout << "3.Exit" << endl;

		cin >> action;

		switch (action)
		{
		case 1:
		{
			unsigned int time = GetTickCount();
			mergeSort(arr, size);
			time = GetTickCount() - time;
			cout << time;
			break;
		}

		case 2:
		{
			for (auto i = 0; i < size; ++i)
				cout << arr[i] << ",";

			break;
		}

		case 3:
		{
			return 0;
		}
		}
	}

	return 0;
}


void mergeSort(int data[], int lenD)
{
	if (lenD>1) {
		int middle = lenD / 2;
		int rem = lenD - middle;
		int* L = new int[middle];
		int* R = new int[rem];
		for (int i = 0;i<lenD;i++) {
			if (i<middle) {
				L[i] = data[i];
			}
			else {
				R[i - middle] = data[i];
			}
		}
		mergeSort(L, middle);
		mergeSort(R, rem);
		merge(data, lenD, L, middle, R, rem);
	}
}

void merge(int merged[], int lenD, int L[], int lenL, int R[], int lenR) {
	int i = 0;
	int j = 0;
	while (i<lenL || j<lenR) {
		if (i<lenL & j<lenR) {
			if (L[i] <= R[j]) {
				merged[i + j] = L[i];
				i++;
			}
			else {
				merged[i + j] = R[j];
				j++;
			}
		}
		else if (i<lenL) {
			merged[i + j] = L[i];
			i++;
		}
		else if (j<lenR) {
			merged[i + j] = R[j];
			j++;
		}
	}
}
