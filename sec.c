#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>



int isThereSpace(char arr[]){
  int i =0;
  int count =0;
  while (arr[i]!='\0') {
    if (arr[i]==' ' && arr[i+1]!= ' '){
      if(arr[i+1]!='\0'){count ++ ;}
    }
  i++;
  }
  return count;
}

int main(void)
{
	while(1==1)
	{
	    char name[100]={0};
	    char parse[10][100]={0};

	    char *args[10];
	    int ret ;
	    pid_t  child;

	    printf("SISH:>");
	    scanf (" %[^\n]s", name);

	    int i =0, j = 0,l=0;
	    int numofspace = isThereSpace(name);



	    if(numofspace>0)//parsing
	    {
	      	while(name[i]!='\0'){
		        if(name[i]==' ')
		        {
		            do{i++;}
		            while(name[i]==' ');
		            j++;l=0;
		        }
		        else{parse[j][l]=name[i];i++;l++;}
	      	}

			for(i=0;i<numofspace+1;i++)
			{
				// printf("%s\n",parse[i]);
				args[i] = parse[i];
			}
			args[i]=NULL;


			// for(i=0;i<numofspace+1;i++)
			// {
			// 	printf("%s\n",args[i]);
			// }
			child = fork();
			if (child == 0){ret = execvp("./main",args);}

			wait(NULL);
	    }

		else
		{
				args[0] = name;
				args[1] = NULL;
				// printf("%s\n", name);
				child = fork();
				if (child == 0)ret = execvp("./main",args);
				waitpid(child,NULL,0);

		}







	}
    return 0;
}
