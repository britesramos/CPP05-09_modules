#pragma once

template <typename T>
void swap(T& a, T& b){
	T temp;
	temp = a;
	a = b;
	b = temp;
}

template <typename T>
T min(T a, T b){
	if (a == b)
		return b;
	return a < b ? a : b;
}

template <typename T>
T max(T a, T b){
	if (a == b)
		return b;
	return a > b ? a : b;
}