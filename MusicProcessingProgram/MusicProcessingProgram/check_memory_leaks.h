#ifndef CHECK_MEMORY_LEAKS_H
#define CHECK_MEMORY_LEAKS_H

#define _CRTDBG_MAP_ALLOC

struct AtExit
{
	~AtExit() // automatically called after main
	{
		/* EXAMPLE OF MEMORY LEAKS TO TEST _CrtDumpMemoryLeaks() FUNCTION: */
		//int * leak;
		//leak = new int[5];

		_CrtDumpMemoryLeaks();
		// breakpoint to check memory leaks after main
	}
} doAtExit;

#endif 