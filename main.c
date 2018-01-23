#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h> 
#include <string.h>
#include <sys/stat.h>
#include <errno.h>
#include <syslog.h>
#include <string.h>


#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <syslog.h>
#include <string.h>



int a,b,c =0;

int back(char *arr[],int argc ){
	int i =0 ;
	while(i<argc){
		//printf("%s\n", arr[i]);
		if(strcmp(arr[i],"&")==0){
			return 1;
		}

	i++;
	}
	return 0 ;
}




int compstr(char *argv, char arr[]){
	 int s =0;
	while (*(argv+s)!='\0') {
		s++;
	}
	int i  = 0 ;
	while(i<4){
        if(arr[i] == *(argv+i)){
            i++;
        }
        else{
            return 0;
        }

    }

		   if(s>4){
				 printf("do you mean exit [y/n] default [n] :");
				 char ans;
				 scanf("%c",&ans);
				 if (ans == 'y'){
					 return 1;
				 }
				 else{
					 return 0 ;
				 }

            }
            else{
            return 1;
            }
	}

int chOption0(int argc , char* argv[]){
	int s = 0 ,i=0 ; 
	while(i<argc){
		if ((strcmp(argv[i],">")==0) || (strcmp(argv[i],"<")==0) || (strcmp(argv[i],"|")==0) || (strcmp(argv[i],";")==0)){
    		s++;
    	}
    	i++;
    }
    return s;
}
int chOption(int argc , char* argv[]){
	int i = 0 ;
    while(i<argc){
    	if (strcmp(argv[i],">")==0){
    		a = 1;
    		return i ;

    	}
    	if (strcmp(argv[i],"<")==0){
    		b = 1;
    		return i ;
    	}
    	if (strcmp(argv[i],"|")==0){
    		c = 1;
    		return i ;
    	}
    	i++;
    }
}


void pipeHandle(char *argv[],char *temp[],char *pipargs[],int pipefd[],int option){
	pid_t child;
	int i;
	child = fork();



	if (child == 0){
		dup2(pipefd[1],1);
		close(pipefd[0]);
		execvp(argv[0],temp);
	}
	else{
		dup2(pipefd[0],0);
		close(pipefd[1]);
		execvp(argv[option+1],pipargs);
	}




}
int   main(int argc,char *argv[]){
	char arr[5] = "exit";char buffer[300];
    int r = compstr(argv[0],arr) ;
    int b = back(argv,argc);
    //printf("this is the result %d\n",b );
    if(b){
    	pid_t pid2; 
    	pid2 = fork();
    	if (pid2==0){
    		printf("starting of back ground \n");
    		argv[argc-1]='\0';
    		execvp("./file1",argv);

    	}
    	else{
    		wait(NULL);
    		printf("end of the backgourn \n");
    	}
    }else{



    
    if (r == 1){ kill(getppid(), SIGKILL);}//kill the parent
    
    else{


    		char *temp[10]={0};
    		char *pipargs[10]={0};
    		int pipefd[2];
    		pipe(pipefd);

    		int option ; 
    		int option0;
    		option0 = chOption0(argc,argv);
    		if (option0 ==1 ){
    				    		option = chOption(argc,argv);
    		pid_t child;
    		int i = 1;
    		int fd;
    		

    		if(a==1){
    			temp[0] = " ";
    			while(i<option){
    				temp[i] = argv[i];
    				i++;
    			}
    			temp[i] = '\0';
    			a = 0;
    			child = fork();
    			if (child==0){
    				fd = open(argv[option+1],O_RDWR|O_CREAT,0777);
    				dup2(fd,1);
    				execvp(argv[0],temp);
    				close(fd);

    			}
    			else{
    				wait(NULL);
    			}

    		}
    		if(c == 1){


	    			temp[0] = " ";
	    			while(i<option){
	    				temp[i] = argv[i];
	    				i++;
	    			}
	    			temp[i] = '\0';
	    			c = 0;

					int j = 1;
					i++;i++;
	    			pipargs[0] = " ";
	    			while(argv[i] != '\0'){
	    				pipargs[j] = argv[i];
	    				i++;j++;
	    			}
	    			pipargs[j] = '\0';


	    			pipeHandle(argv,temp,pipargs,pipefd,option);
	    				

							    			
							    			


								}
    			
    		}
    		else{

		    	char cmd[1024];
		    	sprintf(cmd,"%s ",argv[0]);
		    	int index = 1 ;
		    	while(index<argc)
		    	{
		    			sprintf(cmd+strlen(cmd),"%s ",argv[index]);
		    			index ++ ; }
		
		    	 int i ;
		    	 //for(i=0;i<argc;i++){   
					    FILE   *stream = popen(cmd, "r");
					    while (fgets(buffer, 300, stream) != NULL)
					        printf("%s", buffer);
					    pclose(stream);


    		}


    }



}

return 0;
}
