// 
// Basic Alloction tracker designed by Cherno and updated by Momoyeyu
// 
// Introduction: 
// An easy way to track memory allocation is to rewrite the new operator and set a break point.
// That is the same for tracking freeing memory.
// With the these two override, we can make an alloction tracker.
// 
// Usage: include this header file somewhere in your code (eg. precompiled header), and then use like:
//


#pragma once
#include <iostream>



#define INFO 1
#if INFO
#define ALLOC_TRACK(size) std::cout << "[INFO]: Allocating " << size << " bytes\n"
#define FREE_TRACK(size) std::cout << "[INFO]: Freeing " << size << " bytes\n"
#else
#define ALLOC_TRACK(size)
#define FREE_TRACK(size)
#endif

struct AllocationMetrics
{
	uint32_t TotalAllocated = 0;
	uint32_t TotalFreed = 0;

	uint32_t CurrentUsage() { return TotalAllocated - TotalFreed; }
};

void* operator new(size_t size)
{
	ALLOC_TRACK(size); // INFO

	return malloc(size); // Marked: set a breakpoint at this line and run in debug mode
}

void operator delete(void* memory, size_t size)
{
	std::cout << "Freeing " << size << " bytes\n";

	free(memory);
}