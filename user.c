#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

int main() {
  int buffer, sum, fd;
  mkfifo("pipe", 0644);
  printf("input numbers to add");

  while (1) {
    fd = open("pipe", O_WRONLY);
    scanf("%d", &buffer);
    write(fd, &buffer, sizeof(buffer));
    close(fd);

    fd = open("pipe", O_RDONLY);
    read(fd, &sum, sizeof(sum));
    printf("sum: %d\n", sum);
    close(fd);
  }

  return 0;
}
