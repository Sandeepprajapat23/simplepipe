 #include <unistd.h>
 #include <stdio.h>
 #define BUFF_SIZE 1024

 int main()
 {
     
     int id;
    pid_t pfd[2];
    pipe(pfd);
    unsigned char buffer[BUFF_SIZE];

   // int pipe(pfd[2]);

    id=fork();

    if(0==id)
    {
        close(pfd[1]);
        read(pfd[0],buffer,BUFF_SIZE);
        printf("%s",buffer);
        printf("\nchild Received Message from Parent ");
        
    }
    else{
        write(pfd[1],"hello",5);
        close(pfd[0]);
        printf("\nMessage sent from parent to child\n ");

    }
    return 0;
 }