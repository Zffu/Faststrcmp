/**
 * Benchmarking for faststrcmp.
 */

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include "../src/main.c"

#ifdef WIN32

#include <windows.h>
double get_time()
{
    LARGE_INTEGER t, f;
    QueryPerformanceCounter(&t);
    QueryPerformanceFrequency(&f);
    return ((double)t.QuadPart/(double)f.QuadPart) * 1000000000;
}

#else

#include <sys/time.h>
#include <sys/resource.h>

double get_time()
{
    struct timeval t;
    struct timezone tzp;
    gettimeofday(&t, &tzp);
    return t.tv_sec + t.tv_usec*1e-6;
}

#endif

char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";

void showBenchmarkInfo(char* benchName, double start, int length, int runs, int mask) {
	double taken = get_time() - start;
	double perRun = taken / runs;
	double perSec = 1000000000 / perRun;

	printf("Benchmark of %s took %.3fns with a collide mask of %d\n", benchName, taken, mask);
	printf("Calculated average per run: %.3fns\n", perRun);
	printf("Calculated estimated strings / sec with length = %d: %.3fns\n", length, perSec);
}

int main(int argc, char* argv[]) {
	if(argc < 2) {
		printf("Usage: bench <runs> [stringLength, default = 25]");
		return -1;
	}

	int length = 25;

	if(argc > 2) {
		length = atoi(argv[2]);
	}

	int runs = atoi(argv[1]);
	char* str = malloc(length + 1);
	char* str2 = malloc(length + 1); // Use two pointers instead of one to make the test more realistic.
	
	for(int i = 0; i < length; ++i) {
		str[i] = charset[rand() % 62];
	}	

	str[length] = '\0';
	
	memcpy(str2, str, length + 1);

	printf("Generated string: %s\n", str);
	printf("Second generated string: %s\n", str2);
	printf("Starting benches...\n");

	double start = get_time();
	int collide = 0;

	for(int i = 0; i < runs; ++i) {
		collide += strcmp(str, str2);
	}

	double took = get_time() - start;

	showBenchmarkInfo("strcmp", start, length, runs, collide);

	collide = 0;
	start = get_time();

	for(int i = 0; i < runs; ++i) {
		collide += faststrcmp(str, str2);
	}

	showBenchmarkInfo("faststrcmp (classic)", start, length, runs, collide);
}
