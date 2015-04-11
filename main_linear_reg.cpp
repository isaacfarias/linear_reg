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
	//print_matrix(data.data_features_x);
	//print_matrix(data.thetas);
	//print_matrix(transpose(data.thetas));
	//print_matrix(transpose(get_row(0,data.data_features_x)));
	print_matrix(data.data_result_y);
	printf("%.2lf\n",J(data.thetas,data.data_features_x,data.data_result_y));
	return 0;
}
