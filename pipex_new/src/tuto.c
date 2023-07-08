/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iortega- <iortega-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 13:53:07 by iortega-          #+#    #+#             */
/*   Updated: 2023/05/20 14:47:26 by iortega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>

#define READ_END    0    /* index pipe extremo escritura */
#define WRITE_END   1    /* index pipe extremo lectura */

int	main(int argc, char **argv, char **envp)
{
    int fd1[2],fd2[2];
	char *ls[3], *grep[3], *wc[3];
    int status, pid;
	
	ls[0] = "ls";
	ls[1] = "-l";
	ls[2] = NULL;
	grep[0] = "grep";
	grep[1] = "u";
	grep[2] = NULL;
	wc[0] = "wc";
	wc[1] = "-l";
	wc[2] = NULL;
    pipe(fd1);                 /* comunica ls y grep */
	
    pid = fork();     

    if(pid == 0)              /* hijo 1*/
    {      		
        close(fd1[READ_END]);   /* cerrar extremo no necesario */
		
        dup2(fd1[WRITE_END], STDOUT_FILENO); 
	close(fd1[WRITE_END]);
		
        execve("/bin/ls", ls, NULL);
    }
    else                          /* padre */
    { 
	close(fd1[WRITE_END]);    /* extremo no necesario ya */
		
	pipe(fd2);		  /* comunica grep y wc */
        pid = fork();
        
    if(pid == 0)               /* hijo 2 */
       {
	  close(fd2[READ_END]);   /* cerrar extremo no necesario */
									
          dup2(fd1[READ_END], STDIN_FILENO);
	  close(fd1[READ_END]);
			
	  dup2(fd2[WRITE_END], STDOUT_FILENO);			
	  close(fd2[WRITE_END]);
			
          execve("/bin/grep",grep,NULL);
	}
	else /* padre */
	{
           close(fd1[READ_END]);      /* cerrar extremo no necesario */
           close(fd2[WRITE_END]);     /* cerrar extremo no necesario */
			
     	   pid = fork();
		
	   if(pid == 0) /* hijo 3*/
          {
	    dup2(fd2[READ_END], STDIN_FILENO);
	    close(fd2[READ_END]);
				
	    execve("/usr/bin/wc",wc,NULL);
	  }
        }		        
      }
    
    close(fd2[READ_END]);  /* cerrar extremo que queda abierto en el padre  */
	
   /* wait para cada hijo */
    wait(&status);   
    wait(&status);	
    wait(&status);
	
    return 0;
  	
}