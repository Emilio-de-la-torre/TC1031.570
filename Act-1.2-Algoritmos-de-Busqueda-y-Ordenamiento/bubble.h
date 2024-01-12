#ifndef BUBBLE_H
#define BUBBLE_H

#include <vector>

template <class T>
int bubbleSort(T *arr, int size) {
	int counter{};
	for(int i = size - 1; i > 0; i--){
		for(int j = 0; j < i; j++){
			++counter;
			if(arr[j] > arr[j + 1]){
				swap(arr, j, j + 1);
			}
		}
	}
	return counter;
}

template <class T>
int bubbleSort(std::vector<T> &v) {
	int counter{};
	for(int i = v.size() - 1; i > 0; i--){
		for(int j = 0; j < i; j++){
			if(v[j] > v[j + 1]){
				swap(v, j, j + 1);
				++counter;
			}
		}
	}
	return counter;
}

#endif /* BUBBLE_H */
