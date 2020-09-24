#include <stdio.h>
#include <float.h>

double veci (double* p, double* limit, double max) {
	if (p >= limit) {
	    return max;
	} 
	if (*p > max) {
	    max = *p;
	} 
	p++;
	return veci(p, limit, max);
}

double parallel_max(double* prvi, double* zadnji) {
	double max=-DBL_MAX;
	double* p=(prvi+(zadnji - prvi)/2);
	double max1 = veci(prvi, p, max);
	double max2 = veci(p, zadnji, max);
	if(max1>max2) {
	    return max1;
	}
	else {
	    return max2;
	} 
}

int main() {
	return 0;
}