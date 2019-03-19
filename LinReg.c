/**
 * Document: MaxCompiler Tutorial (maxcompiler-tutorial.pdf)
 * Chapter: 6      Example: 3      Name: Vectors
 * MaxFile name: Vectors
 * Summary:
 *    Streams a vector of integers to the dataflow engine and confirms that the
 *    returned stream contains the integers values doubled.
 */

#include <stdio.h>
#include <stdlib.h>
#include "Maxfiles.h"
#include <MaxSLiCInterface.h>

//
int check(int vectorSize, int streamSize, float *m, float *b, float *r){
    for (int i = 0; i< streamSize/vectorSize; i++){
        printf("Slope: %f, Intercept: %f, R-value: %f\n", m[i], b[i], r[i]);
    }
}


int main()
{
	const int vectorSize = Vectors_vectorSize;
	const int streamSize = 16;
	size_t sizeBytes = vectorSize * streamSize * sizeof(float);
	size_t sizeOut = streamSize * sizeof(float);
	float *x = malloc(sizeBytes);
	float *y = malloc(sizeBytes);
	float *m = malloc(sizeOut);
	float *b = malloc(sizeOut);
	float *r = malloc(sizeOut);

	for (int i = 0; i < vectorSize * streamSize; i++) {
		x[i] = 1.0 * i;
		y[i] = 1.5 * x[i] + 3;
	}

	printf("Running DFE.\n");
	Vectors(streamSize, x, y, m, b, r);

	int status = check(vectorSize, streamSize, m, b, r);

	return status;
}
