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
	data_set data;
	printf("Hola mundo\n");
	load_data("data.txt",&data);
	//printf("matrix size: %d %d\n",data.number_of_training_set, data.number_of_data_features);
	print_matrix(multiply_matrix(&data.data_features_x,&data.data_features_x));
	return 0;
}
