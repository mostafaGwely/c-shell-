# c-shell-
#tutorial video 
  https://www.youtube.com/watch?v=YioMMzP9C5A&feature=youtu.be
or simply run file.sh 

umask
When ever you create a new file in linux, you need premissions to read or write them. The umask command specifies this processes permissions. This is a complicated one to dig into. You can read more in the reference page.

setsid
setsid is otherwise short for Set Session Id. Because we have fork-ed our process we need to give our new process its own unique process-id, therefore we run this function to determine a new process-id.
run it in new session 
prog will have no controlling in the terminal 


dup2 
dup2 is a system call similar to dup in that it duplicates one file descriptor, making them aliases, and then deleting the old file descriptor. This becomes very useful when attempting to redirect output, as it automatically takes care of closing the old file descriptor, performing the redirection in one elegant command. For example, if you wanted to redirect standard output to a file, then you would simply call dup2, providing the open file descriptor for the file as the first command and 1 (standard output) as the second command.
