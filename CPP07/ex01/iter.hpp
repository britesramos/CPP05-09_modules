#pragma once

#include <cstddef>

template <typename T1, typename T2, typename T3>
void iter(T1* array, T2 lenght, T3 function){
	for(T2 i = 0; i < lenght; ++i){
		function(array[i]);
	}
}
