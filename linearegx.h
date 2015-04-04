#ifndef __LINEAREGX__
#define __LINEAREGX__

#include "matrix.h"


typedef struct data_set
{
	matrix *thetas;
	matrix *data_features_x;
	matrix *data_result_y;
} data_set;


//h = t0*x0 + t1*x1 + ... +tn*xn 

double hypothesis(matrix *v1,matrix *v2)
{
	double ret = 0;
	int idx;
	if((v1->columns == v2->columns) && (v1->rows == 1) &&(v2->rows == v1->rows))
		for (idx = 0;idx<v1->columns;idx++)
			{
				ret+=get_matrix_value(0,idx,v1)*get_matrix_value(0,idx,v2);
			}
	return ret;
}

#endif

