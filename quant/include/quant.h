/*
 * Quantization
 *
 *    data           : 0.000000 0.699301 1.398601 2.097902 2.797203 3.496504 4.195804 4.895105 5.594406
 *    data (quant)   : 0.000000 0.699219 1.398438 2.097656 2.796875 3.496094 4.195312 4.894531 5.593750
 *    data (residual): 0.000000 0.000082 0.000163 0.000246 0.000328 0.000410 0.000492 0.000574 0.000656
 */

#ifndef QUANT_H
#define QUANT_H

#include <cmath>
#include <stdio.h>

/*
 */
template <typename dtype>
void fix_bits (dtype * data, const int n, unsigned int bitwidth, unsigned bitwidth_fraction)
{
	dtype intmax = pow(2, bitwidth - bitwidth_fraction - 1);
	
	for (int i = 0; i < n; ++i)
	{
		data[i] = (data[i] >= intmax) * intmax +
				(data[i] <= -intmax) * (-intmax) +
				(data[i] > -intmax && data[i] < intmax) *
				round(data[i] * pow(2, bitwidth_fraction)) / pow(2, bitwidth_fraction);
	}
}


template <typename dtype>
void fix_dynamic (dtype * data, const int n, unsigned int bitwidth)
{
	int bitwidth_fraction = (int)ceil(log2(bitwidth));
	printf("%d \n", bitwidth_fraction);
}


#endif
