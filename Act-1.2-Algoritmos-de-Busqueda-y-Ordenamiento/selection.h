
#ifndef SELECTION_H
#define SELECTION_H

#include <vector>

template <class T>
int selectionSort(T *arr, int size) {
	int pos;
	int counter{};

	for(int i = size - 1; i > 0; i--){
		pos = 0;
		for(int j = 1; j <= i; j++){
			if(arr[j] > arr[pos]){
				pos = j;
			}
		}

		if (pos != i){
			++counter;
			swap(arr, i, pos);
		}
	}
	return counter;
}

template <class T>
int selectionSort(std::vector<T> &v) {
	int pos;
	int counter{};

	for(int i = v.size() - 1; i > 0; i--){
		pos = 0;
		for(int j = 1; j <= i; j++){
			if(v[j] > v[pos]){
				pos = j;
			}
		}

		if (pos != i){
			++counter;
			swap(v, i, pos);
		}
	}
	return counter;
}

#endif /* SELECTION_H */
