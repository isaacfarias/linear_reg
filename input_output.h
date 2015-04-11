#ifndef __INPUT_OUTPUT__
#define __INPUT_OUTPUT__

#include "matrix.h"
#include "linearegx.h"


int load_data(const char* file_name,data_set* data)
{
	FILE* file = fopen(file_name,"r");
	if(!file)
	{
		return 0;
	}
	//int rows,columns;
	data->data_features_x =(matrix*) malloc(sizeof(matrix));
	data->data_result_y =(matrix*) malloc(sizeof(matrix));
	data->thetas =(matrix*) malloc(sizeof(matrix)); 
	
	fscanf(file,"%d %d",&data->data_features_x->rows,&data->data_features_x->columns);
	data->data_result_y->rows = data->data_features_x->rows;
	data->data_result_y->columns = 1;
	data->thetas->rows = data->data_features_x->columns;
	data->thetas->columns = 1;
	
	//reserve memory for matrix 
	malloc_space_for_matrix(data->data_result_y);
	malloc_space_for_matrix(data->data_features_x);
	malloc_space_for_matrix(data->thetas);
	
	int idx = 0;
	int n_feature = 0;
	data_type aux_data;
	
	//Blucle to load the data set
	
	
	
	for(idx=0;idx<data->data_features_x->rows;idx++)
	{
		for(n_feature = 0;n_feature<data->data_features_x->columns;n_feature++)
		{
			//Read and storage data in fetures vector
			fscanf(file,"%lf",&aux_data);
			*(data->data_features_x->data +(idx * data->data_features_x->columns + n_feature)) = aux_data;
			//printf("%d ",aux_data);

		}
					
		//Read and storage data in y vector
		fscanf(file,"%lf",&aux_data);
		//printf("%d\n",aux_data);
		*(data->data_result_y->data + idx) = aux_data;
	}
	
	for(n_feature = 0;n_feature<data->data_features_x->columns;n_feature++)
		{
			//set the thetas to 1;
			//*(data->thetas->data + n_feature) = 1;
			set_matrix_value(1,n_feature,0,data->thetas);
		}
	
	
	fclose(file);
	return 1;
}


void print_matrix(matrix *m)
{
	int i,j;
	printf("%dX%d\n",m->rows,m->columns);
	for (i=0;i<m->rows;i++)
	{
		for(j=0;j<m->columns;j++)
		{
			printf("%.2lf\t",get_matrix_value(i,j,m));
		}
		printf("\n");
	}

}

#endif
