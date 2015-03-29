#ifndef _MATRIX_H
#define _MATRIX_H

#include <stdio.h>
#include <stdlib.h>


//TODO change the structs to complience with matrix struct definition

typedef int data_type;
struct data_set
{
	unsigned int number_of_data_features;
	unsigned int number_of_training_set;
	data_type* data_features_x;
	data_type* data_result_y;
};
typedef struct data_set data_set;

typedef struct matrix 
{
	int rows;
	int columns;
	data_type *data;	
} matrix;

matrix* multiply_matrix(matrix m1,matrix m2)
{
	if(m1.columns != m2.rows)
	{
		return NULL;
	}
	matrix* ret = (matrix*) malloc(sizeof(matrix));
	ret->rows = m1.rows;
	ret->columns = m2.columns;
	ret->data = (data_type*) malloc(sizeof(data_type)*ret->columns*ret->rows);

	//TODO extract columns and rows to multiply it and sum of inner elements of a vector
}


unsigned int malloc_space_for_data_set(data_set* data)
{
	
	data->data_features_x = (data_type*) malloc(data->number_of_training_set*data->number_of_data_features*sizeof(data_type));
	data->data_result_y = (data_type*)  malloc(data->number_of_training_set*sizeof(data_type));
}
//return the value of row and column of a data_matrix
data_type get_matrix_value(unsigned int fil,unsigned int col,unsigned int n_cols,data_type* data_matrix)
{
	//need to know column number
	return *(data_matrix + (fil*n_cols +col ));
}


int load_data(const char* file_name,data_set* data)
{
	FILE* file = fopen(file_name,"r");
	if(!file)
	{
		return 0;
	}
	fscanf(file,"%d %d",&data->number_of_training_set,&data->number_of_data_features);
	malloc_space_for_data_set(data);
	
	int idx = 0;
	int n_feature = 0;
	data_type aux_data;
	
	//Blucle to load the data set
	for(idx=0;idx<data->number_of_training_set;idx++)
	{
		for(n_feature = 0;n_feature<data->number_of_data_features;n_feature++)
		{
			//Read and storage data in fetures vector
			fscanf(file,"%d",&aux_data);
			*(data->data_features_x +(idx * data->number_of_data_features + n_feature)) = aux_data;
			//printf("%d ",aux_data);
			//Read and storage data in y vector
			fscanf(file,"%d",&aux_data);
			//printf("%d\n",aux_data);
			*(data->data_result_y + idx) = aux_data;
		}
	
	}
	fclose(file);
	return 1;
}


void print_matrix(unsigned int rows,unsigned int columns, data_type* matrix)
{
	int i,j;
	for (i=0;i<rows;i++)
	{
		for(j=0;j<columns;j++)
		{
			printf("%d ",get_matrix_value(i,j,columns,matrix));
		}
		printf("\n");
	}

}


#endif
