#include "../include/quant.h"

#include <stdio.h>
#include <stdlib.h>


template <typename dtype>
void data_init(dtype * data, unsigned int n)
{
	for (int i = 0; i < n; ++i) data[i] = i * 24 / 1.43;
}


template <typename dtype>
void data_print(dtype * data, unsigned int n)
{
	for (int i = 0; i < n; ++i) printf("%f ", data[i]);
	printf("\n");
}


template <typename dtype>
void test_fix_bits(dtype * data, unsigned int n)
{
	unsigned int bitwidth = 16;
	unsigned int bitwidth_fraction = 7;
	fix_bits(data, n, bitwidth, bitwidth_fraction);
	printf("data (fixed: bits): "); data_print(data, n);
}


template <typename dtype>
void test_fix_dynamic(dtype * data, unsigned int n)
{
	fix_dynamic(data, n);
	printf("data (fixed: dynamic): "); data_print(data, n);
}


int main(void)
{
	unsigned int n = 10;
	float * data = (float*)malloc(n*sizeof(float));
	data_init(data, n); printf("data: "); data_print(data, n);

	test_fix_bits(data, n);
	test_fix_dynamic(data, n);

	free(data);

	return 0;
}
