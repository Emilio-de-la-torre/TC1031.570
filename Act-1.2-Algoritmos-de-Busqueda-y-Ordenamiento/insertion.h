#ifndef INSERTION_H
#define INSERTION_H

#include <vector>


template <class T>
int insertionSort(T *arr, int size) {
	int counter{};
	for(int i = 1; i < size; i++){
		for(int j = i; j > 0 && arr[j] < arr[j - 1]; j--){
			swap(arr, j, j - 1);
			++counter;
		}
	}
	return counter;
}

template <class T>
int insertionSort(std::vector<T> &v) {
	int counter{};
	for(int i = 1; i < v.size(); i++){
		for(int j = i; j > 0 && v[j] < v[j - 1]; j--){
			swap(v, j, j - 1);
			++counter;
		}
	}
	return counter;
}

#endif /* INSERTION_H */
