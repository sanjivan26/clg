#include <stdio.h> 
#include <stdlib.h> 
#include <sys/types.h> 
#include <unistd.h> 
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

int main()
{
    char* buffer = (char*)calloc(100, sizeof(char));

    system("dir");

    int temp = creat("temp.txt", S_IRUSR | S_IWUSR);
    if (temp < 0) {
       perror("creat");
       exit(1);
    }
    close(temp);

    system("dir");

    int fd = open("temp.txt", O_WRONLY);
    if (fd < 0) 
    { 
        perror("open");
        exit(1); 
    } 

    size_t writeOut = write(fd, "Hulloo\n", strlen("Hulloo")); 

    fd = open("temp.txt", O_RDONLY);
    size_t readOut = read(fd, buffer, 10);
    buffer[readOut] = '\n';
    printf("The output read is %s", buffer);
    close(fd);

    free(buffer);
    exit(1);
} 
