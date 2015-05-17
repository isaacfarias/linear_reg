#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"
#include "linearegx.h"
#include "input_output.h"
//TODO change the fscanf to aply with all data_type types (float.. double ....)
//TODO check bounds of matrix
int** data_features;
 
int main(int argc, char** argv)
{
	data_set* data =(data_set*) malloc(sizeof(data_set));
	printf("Hola mundo\n");
	load_data("data.txt",data);
	
	print_matrix(data->thetas);
	int times = gradient_decent(data);
	print_matrix(data->thetas);
	printf("times :%d \ny = %lf + %lf(x) \n",times,get_matrix_value(0,0,data->thetas),get_matrix_value(1,0,data->thetas));
	//matrix *aux = transpose(get_row(3,data->data_features_x)); 
	//print_matrix(aux);
	//J(matrix* thetas,matrix *x,matrix *y,int derivate)
	//;
	return 0;
}
