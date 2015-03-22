#include <stdio.h>
#include <stdlib.h>

int** data_features;

typedef int data_type;
struct data_set
{
	unsigned int number_of_data_features;
	unsigned int number_of_training_set;
	data_type* data_features;
	data_type* data_result;
};
typedef struct data_set data_set;

int load_data(char* file_name,data_set* data)
{
	FILE* file = fopen(file_name,"r");
	if(!file)
	{
		return 0;
	}
	fscanf(file,"%d %d",&data->number_of_data_features,&data->number_of_training_set);
	//TODO Give a try to check if this function is working, just need to print the two readed values.
	//TODO create a bucle to load all the training set.
	fclose(file);
	return 1;
}


int main(int argc, char** argv)
{
	printf("Hola mundo\n");
	
	return 0;
}
