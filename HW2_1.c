#include <stdio.h>
#include<stdlib.h>
#define TEXT_SIZE 100
void calculate(char* filename)
{
	 int upper;
	 int lines;
	 int words;
	 int characters;
	 char ch;
	 FILE *file;
	characters = words = lines =upper= 0;
	 file = fopen(filename,"r");
	 
	 if (file==NULL) 
    { 
        printf("no such file.");
    }
	else
	{
		while (   (     ch = fgetc(file)   ) != EOF)
		{
			characters++;
			
			if (ch == '\n'|| ch == '\0')
				lines++;

		   
			if (ch == ' ' || ch == '\t' || ch == '\n'|| ch == '\0')
				words++;
			
			if (ch!= ' ')
			{
				if (ch>= 'A' && ch <= 'Z')
				 upper++;
			}
		}

		if (characters > 0)
		{
			words++;
			lines++;
		}

		printf("\n");
		printf("Total characters = %d\n", characters);
		printf("Total words      = %d\n", words);
		printf("Total lines      = %d\n", lines);
		printf("Uppercase Letters : %d\n", upper);

		fclose(file);
	}	
}

void makefile(char* filename)
{
	char s[TEXT_SIZE];
	char ch;
	int i;
	FILE *file;
	file = fopen(filename,"r");
	i=0;
	if (file==NULL) 
	{ 
        printf("no such file.");
    }

	else
	{
		while (   (     ch = fgetc(file)   ) != EOF)
		{
			//printf("%c\n",ch);
			if(ch!= ' ')
			{
				if (ch>= 'a' && ch <= 'z')
				{
					s[i]=ch-32;
					//printf("%c\n",s[i]);
				}
				else
					s[i]=ch;	
				i++;
			
			}
			else
			{
				s[i]=ch;
				i++;
			}
		}
		//printf("%s",s);
		fclose(file);
		file = fopen("UPPER","w");
		fprintf(file,"%s",s);
		fclose(file);
	
	}
}
 int main(int argc, char *argv[]) 
 {
	calculate(argv[1]);
	makefile(argv[1]);
	return 0;
	
 }