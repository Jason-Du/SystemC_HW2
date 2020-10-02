#include <stdio.h>
#include <stdlib.h>

/*
1. Use void* malloc(size_t size); to allocate argv[1] bytes of  memory, i.e. argv[1] is the second input argument. 
Notice that you need to turn argv[1], a char* type data, into integer type to process.

2. Use char* and a for loop, assign to the block of memory, byte-by-byte,‘A’ to ‘Z’ then ‘1’ to ’9’ repeatedly, until the memory runs out.

3. Then use int* and a do-while loop, to print the memory content, in
list of integers. After the printing is done then for each integer accessed,subtract 1 from it.

4. In the integer process loop, you need to implement a guard to prevent
from segmentation fault.

*/
int main(int argc, char *argv[]) 
{
	int memory_byte;
	int i = 0;
	int j = 0;
	int *pointer2;
	
	char *pointer;
	char write_in_data='A';
	
	sscanf(argv[1], "%d",&memory_byte);
	//printf("%d\n",memory_byte);
	
    pointer = (char*)malloc(  sizeof(char) * (memory_byte)  ) ;
	pointer2 = (int*)malloc(  sizeof(int) * (memory_byte)  ) ;
	for (i=0;i<memory_byte;i++)
	{
		*(pointer+i)=write_in_data;
		write_in_data++;
		if (write_in_data==91)write_in_data=49;
		if (write_in_data==58)write_in_data=65;
		
		//printf("%c\n",*(pointer+i));
		
	}
	do
	{
		*(pointer2+j) = *(pointer+j);
		printf("%d\n",*(pointer2+j));
		j++;
	}
	while(j<memory_byte);
	return 0;
}