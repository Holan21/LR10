#include <Windows.h>
#include <iostream>
#include <math.h>

using namespace std;

//шаблони функції

int* generate_array(int length);
int* get_from_user_array(int length);
void show_array(int arr[],int length);
void task(int* arr, int length, int p);

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int length, p;

	printf("Введіть length,p через пробіл:");
	scanf_s("%i %i", &length, &p);

	printf("\n--------------------Генериючи массив--------------------\n");
	int* arr = generate_array(length);
	
	show_array(arr, length);
	task(arr, length, p);
	delete[] arr;

	printf("\n--------------------Отримування массива з користувача--------------------\n");
	arr = get_from_user_array(length);
	show_array(arr, length);
	task(arr, length, p);
	delete[] arr;

	system("pause");
	return 0;
}

int* generate_array(int length) {
	srand(time(0));
	int* arr = new int[length];

	int num_max, num_min, p;

	printf("\nВведіть num_max, num_min через пробіл:");
	scanf_s("%i %i", &num_max, &num_min);

	for (int i = 0; i < length; i++)
		arr[i] = num_min+ rand() % (num_max + 1 - num_min);
	
	return arr;
}

int* get_from_user_array(int length) {
	int* arr = new int[length];

	printf("\nВведіть масив:");

	for (int i = 0; i < length; i++) 
		scanf_s("%i", &arr[i]);
	
	return arr;
}

void show_array(int arr[], int length) {
	printf("Массив:");
	for (int i = 0; i < length; i++)
		printf("%i ", arr[i]);

	printf("\n");
} 

void task(int *arr,int length, int p) {
	printf("Завдача:");
	int counter = 0;
	for (int i = 0; i < length; i++) {
		if (arr[i] > p) {
			printf("%i ", arr[i]);
			++counter;
		}
	}

	printf("\nКількість:%i\n", counter);
}