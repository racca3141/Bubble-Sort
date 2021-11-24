//Emerson Racca
//11/23/2021
//Lab 11a - Bubble Sort

/*
In the bubble sort algorithm larger values gradually "bubble" their way upward to the top of the array while the smaller values
sink to the bottom.  The bubble sort makes several passes through the array.  On each pass, successive pairs of elements are compared.
If a pair is in increasing order (or the values are identical), we leave the values as they are.  If a pair is not in order,
their values are swapped in the array.

a. Write a program that bubble sorts an array of 10 random integers from 0 - 50.  The bubble sort procedure should be performed
within a regular function.

b. Keep track of the number of swaps made to sort the array.

Part II:  Use the Law of Large Numbers (run the game 50,000 times).

c. Calculate the average number of swaps it takes to sort a 10-element array using the law of large numbers.

--- the answer: 22.05
*/

#include<iostream>
#include<cstdlib>
#include<cmath>

using namespace std;

void swapValues(int& x, int& y);
int bubbleSort(int arr[], const int s);
void printArray(int arr[], const int s);

int main(void) {
	srand((unsigned int)time(0));
	int swapCountTotal = 0;

	const int size = 10;
	int a[size];
	int loopAmt = 50000;

	cout << "Bubble Sort" << endl << endl;

	for (int gameLoop = 0; gameLoop < loopAmt; gameLoop++) {
		for (int i = 0; i < size; i++) {
			a[i] = rand() % 51; //random values range from 0 - 50
		}

		//printArray(a, size);
		swapCountTotal += bubbleSort(a, size);
		//cout << "Current swap count: " << swapCountTotal << endl;
	}

	cout << "Average number of swaps to sort a 10-element array for a game loop of " << loopAmt << ": " << 1.0 * swapCountTotal / loopAmt << endl;
	
	return 0;
}

//This function works the same as the swap() function, which "is a built-in function in the C++ Standard Template Library (STL)".
void swapValues(int& x, int& y) {
	int temp = x;
	x = y;
	y = temp;
}

int bubbleSort(int arr[], const int s) {
	int swapCount = 0;
	int i;
	for (int j = 0; j < s - 1; j++) {
		for (i = 0; i < s - 1 - j; i++) { //the j offset is to make sure the last element from the previous j loop is not tested again.
			if (arr[i] > arr[i + 1]) {
				swapValues(arr[i], arr[i + 1]);
				swapCount++;
			}
		}
	}
	return swapCount;
}

//print array
void printArray(int arr[], const int s) {
	for (int i = 0; i < s; i++)
		cout << arr[i] << endl;
}