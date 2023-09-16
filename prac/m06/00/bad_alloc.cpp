#include <iostream>
#include <stdexcept>
#include <exception>
#include <cstring>

void	allocateMemoryinHeap(long long size)
{
    try
    {
        int* arr = new int[size]; 
		// new에 내부적으로 구현된 bad_alloc으로의 throw()
        delete[] arr;
        std::cout << "Memory allocation and deallocation successful!" << std::endl;
    }
    catch (const std::bad_alloc& ex)
    {
        std::cout << "Memory allocation failed: " << ex.what() << std::endl;
    }
}

void	allocateMemoryinStack(long long size)
{
	try {
		int		arr[size];	// 지역 변수 할당에 실패하면?
		throw	std::bad_alloc(); // bad alloc에 throw()
		std::memset(arr, 0, sizeof(arr));
	}
	catch (const std::bad_alloc& ex) {
		std::cout<<"Stack initialization failed: "<<ex.what()<<std::endl;	
	}

}

int main()
{
    long long size;
    std::cout << "Enter the size of the array: ";
    std::cin >> size;
	std::cout<<size<<'\n';

	// allocate memory in heap
	allocateMemoryinHeap(static_cast<long long>(size));

	// allocate memory in stack
	allocateMemoryinStack(static_cast<long long>(size));
	
	return 0;
}
