#include<stdio.h>
#include<stdlib.h>
 

  
static int table[1000]; 
  
void hashInsertion(int num)
{
	int probe = (num)%1000;                                  
    while (table[probe]!=0)
	{   
		if (table[probe]==num)
		{
			printf("duplicate\n");
			return;
		}
        probe = (probe+1)%1000;                 
    }
    table[probe] = num;
	printf("inserted \n");
}
void hashSearch(int num)
{
	int probe = num%1000;                                 
    int i;
    for(i=0;i<1000;i++)
	{                              
        if(table[probe]==num)
		{
			printf("present \n");
			return;
		}
                                              
        probe = (probe+1)%1000; 
    }
	printf("absent \n");
    return; 
}
   
int main(int argc, char** argv)
{
	FILE *fp;
	if (!(fp = fopen(argv[1],"r")))
	{
		printf("error\n");
		return 0;
	}

	char ser[]="s";
	char in[]="i";
	
	char key[10];
	char num[10];
	while( fscanf(fp, "%s", key) != EOF && fscanf(fp, "%s", num) != EOF)        
		{     
		
			
			if (strcmp(&in,&key)==0)
			{
				int temp=atoi(num);
				hashInsertion(temp);
			}
			else if (strcmp(&ser,&key)==0)
			{
				int temp=atoi(num);
				hashSearch(temp);
			}
			else 
			{
				printf("error \n");
				
				
			}
			      
		}                     

	fclose(fp);

	return 0;
	
}


