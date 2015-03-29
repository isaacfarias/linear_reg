#include <stdio.h>
#include <stdlib.h>
//TODO change the fscanf to aply with all data_type types (float.. double ....)
int** data_features;

typedef int data_type;
struct data_set
{
	unsigned int number_of_data_features;
	unsigned int number_of_training_set;
	data_type* data_features_x;
	data_type* data_result_y;
};
typedef struct data_set data_set;

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
	fscanf(file,"%d %d",&data->number_of_data_features,&data->number_of_training_set);
	//Give a try to check if this function is working, just need to print the two readed values.
	printf("%d %d\n",data->number_of_data_features,data->number_of_training_set);
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
			printf("%d ",aux_data);
			//Read and storage data in y vector
			fscanf(file,"%d",&aux_data);
			printf("%d\n",aux_data);
			*(data->data_result_y + idx) = aux_data;
		}
	
	}
	fclose(file);
	return 1;
}


int main(int argc, char** argv)
{
	data_set data;
	printf("Hola mundo\n");
	load_data("data.txt",&data);
	printf(".%d",get_matrix_value(9,0,1,data.data_features_x));
	return 0;
}
