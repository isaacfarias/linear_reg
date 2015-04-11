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
//h = multiply_matrix(transpose(thetas),x);

double hypothesis(matrix *thetas,matrix *x)
{
	double ret;
	matrix *aux_transpose;
	matrix *aux_multiply;
	aux_transpose = transpose(thetas);
	aux_multiply = multiply_matrix(aux_transpose,x);
	ret = get_matrix_value(0,0,aux_multiply);
	free(aux_transpose);
	free(aux_multiply);
	return ret;
}

// J(t0,t1,t2,...,tn) = 1/2m E (i=1->M) (h0(X(i)) - y(i))^2

double J(matrix* thetas,matrix *x,matrix *y)
{
	double ret=0,aux;
	int i;
	matrix* x_i,*trans;
	for(i =0;i<x->rows;i++)
	{
		x_i = get_row(i,x);
		trans= transpose(x_i);
		aux = hypothesis(thetas,trans) - get_matrix_value(i,0,y);
		aux = aux*aux;
		ret += aux;
	}
	return (ret/(2*x->rows));
}

#endif

