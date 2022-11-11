#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{  pid_t  pid1,pid2;

	   if((pid1=fork()) == 0)
	   {
		      sleep(3);
			     printf("info1 from child process_1\n");
				    exit(0);
					   printf("info2 from child process_1\n"); 
	   }
	   else
	   {
		     if((pid2=fork()) == 0)
				   {
					        sleep(1);
							     printf("info1 from child process_2\n");
								      exit(0);
									    }
			   else
				     {
						      wait(NULL);
							       wait(NULL);
								        printf("info1 from parent process\n");
										     printf("info2 from parent process");
											      _exit(0);
												    }
	   }  
	   return 0;
}

