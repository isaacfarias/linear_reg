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
//h = multiply_matrix(thetas,transpose(x))
//h = multiply_matrix both matrixes must be nx1 and nx1

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


double cost_function(matrix* thetas,matrix *x,matrix *y)
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
		free(x_i);
		free(trans);
	}
	return (ret/(2*x->rows));
}

// J(t0,t1,t2,...,tn) = 1/2m E (i=1->M) (h0(X(i)) - y(i))^2

double J(matrix* thetas,matrix *x,matrix *y,int derivate)
{
	double ret=0,aux;
	int i;
	matrix* x_i,*trans;
	for(i =0;i<x->rows;i++)
	{
		x_i = get_row(i,x);
		trans= transpose(x_i);
		aux = hypothesis(thetas,trans) - get_matrix_value(i,0,y);
		aux=aux*get_matrix_value(i,derivate,x);
		ret += aux;
		
		//TODO Free mallocs
	}
	return (ret/(x->rows));
}

int gradient_decent(data_set *data)
{
	data_type *aux_thetas=(data_type*) malloc(sizeof(data_type) * data->thetas->rows);
	int cont,cont_thetas;
	data_type aux_val,cost_value;
	unsigned char stop = 0;
	
	for(cont = 0; !stop ;cont++)
	{	
		cost_value = cost_function(data->thetas,data->data_features_x,data->data_result_y);
		//Calculate thetas
		for (cont_thetas = 0;cont_thetas<data->thetas->rows;cont_thetas++)
		{
			aux_thetas[cont_thetas] = J(data->thetas,data->data_features_x,data->data_result_y,cont_thetas);
		}
		//Update simultaneously thetas
		for (cont_thetas = 0;cont_thetas<data->thetas->rows;cont_thetas++)
		{
			aux_val = get_matrix_value(cont_thetas,0,data->thetas) - ((0.01) * aux_thetas[cont_thetas]/data->data_features_x->rows);
			 set_matrix_value(aux_val,cont_thetas,0,data->thetas);
		}
		printf("cost_function: %lf\n",cost_value);
		if (cost_value<cost_function(data->thetas,data->data_features_x,data->data_result_y))
			stop = 1;
		
	}
	return cont;
}

#endif

