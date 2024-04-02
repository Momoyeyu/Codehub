// 
// Basic Alloction tracker designed by Cherno and modified by Momoyeyu
// 
// Introduction: 
// An easy way to track memory allocation is to rewrite the new operator and set a break point.
// That is the same for tracking freeing memory.
// With the these two override, we can make an alloction tracker.
// 
// Usage: include this header file somewhere in your code (eg. precompiled header), and then use like:
// 
// #include "Allocation.h"
// 
// ...
// AllocationMetrics::PrintMemoryUsage() // print the allocation before executed the below code
//     ...
//     (your code)
//     ...
// AllocationMetrics::PrintMemoryUsage() // print the allocation after executed the below code
// ...

#pragma once
#include <iostream>

#define __ALLOCATION_INFO__ 1 // set 1 to see more information
#if __ALLOCATION_INFO__
#define ALLOC_TRACK(size) std::cout << "[INFO]: Allocating " << (size) << " bytes\n"
#define FREE_TRACK(size) std::cout << "[INFO]: Freeing " << (size) << " bytes\n"
#else
#define ALLOC_TRACK(size)
#define FREE_TRACK(size)
#endif

class AllocationMetrics
{
public:
	AllocationMetrics(const AllocationMetrics&) = delete; // ban copy

	static AllocationMetrics& Get()
	{
		static AllocationMetrics instance; // singleton
		return instance;
	}

	static void PrintMemoryUsage()
	{
		Get().ImpPrintMemoryUsage();
	}

	static void MarkAlloc(size_t size)
	{
		return Get().ImpMarkAlloc(size);
	}

	static void MarkFree(size_t size)
	{
		return Get().ImpMarkFree(size);
	}

private:
	AllocationMetrics()
		: TotalAllocated(0), TotalFreed(0)
	{}
	void ImpMarkAlloc(size_t size) // Interface of MarkAlloc
	{
		Get().TotalAllocated += size;
	}

	void ImpMarkFree(size_t size) // Interface
	{
		Get().TotalFreed += size;
	}

	void ImpPrintMemoryUsage() // Interface
	{
		std::cout << "Memory Usage: " << Get().TotalAllocated - Get().TotalFreed << " bytes\n";
	}
	uint32_t TotalAllocated;
	uint32_t TotalFreed;
};

void* operator new(size_t size)
{
	ALLOC_TRACK(size); // INFO

	AllocationMetrics::MarkAlloc(size);

	return malloc(size); // Set a breakpoint at this line and run in debug mode to track
}

void operator delete(void* memory, size_t size)
{
	FREE_TRACK(size); // INFO

	AllocationMetrics::MarkFree(size);

	free(memory); // Set a breakpoint at this line and run in debug mode to track
}