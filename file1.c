
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <syslog.h>
#include <string.h>

int main(int argc , char *argv[]) {
    //char intval4jf;

        /* Our process ID and Session ID */
        pid_t pid, sid;
        //int i  =1 ;
       // char *name[10]={0};
        // while(i<argc){

        //     name[i-1] = argv[i];

        // i++;
        // }
       // name[i] = '\0';
       // i = 0;
        // while(name[i]){
        //     printf("%s_______\n",name[i]);
        //     i++;
        // }
         //  i=0;
        // while(argv[i]){
        // 	printf("%s\n", argv[i]);i++;
        // }


        /* Fork off the parent process */
        pid = fork();


 if (pid == 0){
            printf("i'm the child and the pid is %d\n",getpid());

        }
        if (pid < 0) {
                exit(EXIT_FAILURE);
        }
//
        if (pid > 0) {
                exit(EXIT_SUCCESS);
        }
//
////
//        /* Change the file mode mask */
       umask(0);
//
//        /* Open any logs here */
//
//        /* Create a new SID for the child process */
        sid = setsid();
        if (sid < 0) {
                /* Log the failure */
                exit(EXIT_FAILURE);
        }
////
////
////        /* Close out the standard file descriptors */
        close(STDIN_FILENO);
        close(STDOUT_FILENO);
        close(STDERR_FILENO);
////
        /* Daemon-specific initialization goes here */

        /* The Big Loop */
           /* Do some task here ... */

     

        execvp(argv[0],argv);
//
 exit(EXIT_SUCCESS);
}
