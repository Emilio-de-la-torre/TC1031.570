#ifndef SEARCH_H
#define SEARCH_H

#include <vector>

template <class T>
std::pair<int, int> sequentialSearch(const std::vector<T> &v, T key) {
	int count{};
	for (int i = 0; i < v.size(); i++){
		++count;
		if (v[i] == key){
			return std::pair<int, int>(i, count);
		}
	}
	return std::pair<int, int>(-1, count);
}

template <class T>
std::pair<int, int> binarySearch(const std::vector<T> &v, T key) {
	int low, high, mid, count{};
	low = 0;
	high = v.size() - 1;
	while (low <= high){
		mid = low + ((high - low) / 2); // mid = (high + low) / 2;
		++count;
		if (key == v[mid]){
			return std::pair<int, int>(mid, count);
		}else if (key < v[mid]){
			high = mid - 1;
		}else{
			low = mid + 1;
		}
	}
	return std::pair<int, int>(-1, count);
}

template <class T>
int binaryRSearch(const std::vector<T> &v, int low, int high, T key) {
	int mid;
	if (low > high){
		return -1;
	}else{
		mid = low + ((high - low) / 2); // mid = (high + low) / 2;
		if (key == v[mid]){
			return mid;
		}else if (key < v[mid]){
			return binaryRSearch(v, low, mid - 1, key);
		}else{
			return binaryRSearch(v, mid + 1, high, key);
		}
	}
}

#endif /* SEARCH_H */
