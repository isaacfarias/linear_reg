#ifndef _MATRIX_H
#define _MATRIX_H

#include <stdio.h>
#include <stdlib.h>
//TODO implement a free function to return memory to the OS
typedef int data_type;

typedef struct matrix 
{
	int rows;
	int columns;
	data_type *data;	
} matrix;

//return the value of row and column of a data_matrix
data_type get_matrix_value(unsigned int row,unsigned int column,matrix* m)
{
	return *(m->data + (row*m->columns +column ));
}

//Set a value into a matrix row and column
void set_matrix_value(data_type val,unsigned int row,unsigned int column,matrix* m)
{
	*(m->data + (row*m->columns +column ))=val;
}

//Multiply two matrix and return a new matrix with the resul
matrix* multiply_matrix(matrix* m1,matrix* m2)
{
	if(m1->columns != m2->rows)
	{
		printf("Error: can not multiply matrix");
		return NULL;
	}
	matrix* ret = (matrix*) malloc(sizeof(matrix));
	ret->rows = m1->rows;
	ret->columns = m2->columns;
	ret->data = (data_type*) malloc(sizeof(data_type)*ret->columns*ret->rows);

	int row_,column_,aux,idx;
	for(row_ = 0;row_<ret->rows;row_++)
	{
		
		for(column_=0;column_<ret->columns;column_++)
		{
			aux=0;
			for(idx =0;idx<ret->rows;idx++)
			{
				aux+=get_matrix_value(row_,idx,m1)*get_matrix_value(idx,column_,m2);
			}
			set_matrix_value(aux,row_,column_,ret);
			
		}
	}
	return ret;
}


unsigned int malloc_space_for_matrix(matrix *data)
{
	
	data->data = (data_type*) malloc(data->rows*data->columns*sizeof(data_type));
}





#define ROW 1
#define COLUMN 2 
matrix* get_vector(unsigned int l,unsigned int number,matrix *m)
{
	matrix* ret = (matrix*) malloc(sizeof(matrix));
	
	if(l==COLUMN)
	{
		ret->rows = m->rows;
		ret->columns = 1;
	}
	else
	{
		ret->rows = 1;
		ret->columns = m->columns;	
	}
	
	malloc_space_for_matrix(ret);
	
	int idx;
	int top;
	if(l==COLUMN)
	{
		top = ret->rows;
	}
	else
	{
		top = ret->columns;
	}
	for(idx=0;idx<top;idx++)
	{
		if(l==COLUMN)
			*(ret->data+idx)=get_matrix_value(idx,number,m);
		else
			*(ret->data+idx)=get_matrix_value(number,idx,m);
	}
	return ret;

}

matrix* get_column(unsigned int col,matrix *m)
{
	return get_vector(COLUMN,col,m);
}

matrix* get_row(unsigned int row,matrix *m)
{
	return get_vector(ROW,row,m);
}

matrix* transpose(matrix* m)
{
	matrix* ret =(matrix *) malloc(sizeof(matrix));
	ret->rows = m->columns;
	ret->columns = m->rows;
	
	malloc_space_for_matrix(ret);
	
	int i,j;
	
	for(i=0;i<m->rows;i++)
	{
		for(j=0;j<m->columns;j++)
		{
			set_matrix_value(get_matrix_value(i,j,m),j,i,ret);
		}
	}
	return ret;
}


#endif
