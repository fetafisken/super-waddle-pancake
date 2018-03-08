#include <iostream>

#include "utility.hh"

using namespace std;


int main(int argc, char const *argv[])
{
	cout << "Setup" << endl;
	int size = 11;
	int l1[11] = { 10, 234, 21, 23, 1, 12, 4, 3, 3425, 4, 1 };
	// int l2[size] = { 10, 234, 21, 23, 1, 12, 4, 3, 3425, 4, 1 };
	int* l2 = new int[size];
	int* l3 = new int[size];

	cout << endl << "Init" << endl;
	for (int i = 0; i < size; i++)
	{
		cout << l1[i] << (i + 1 == size ? "\n" : ", ");
		l2[i] = l1[i];
		l3[i] = l1[i];
	}

	util::selectionSort(l2, size);
	cout << endl << "Selection Sort" << endl;

	for (int i = 0; i < size; i++)
		cout << l1[i] << (i + 1 == size ? "\n" : ", ");
	for (int i = 0; i < size; i++)
		cout << l2[i] << (i + 1 == size ? "\n" : ", ");



	util::insertionSort(l3, size);
	cout << endl << "Insertion Sort" << endl;

	for (int i = 0; i < size; i++)
		cout << l1[i] << (i + 1 == size ? "\n" : ", ");
	for (int i = 0; i < size; i++)
		cout << l3[i] << (i + 1 == size ? "\n" : ", ");

	cout << endl << "Clean Up; Removing Lists" << endl;
	delete[] l2, l3;
	getchar();
	return 0;
}
