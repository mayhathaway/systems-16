#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

int main() {
  int buffer, sum, fd;
  sum = 0;
  mkfifo("pipe", 0644);

  while (1) {
    fd = open("pipe", O_RDONLY);
    read(fd, &buffer, sizeof(buffer));
    close(fd);
    sum += buffer;

    fd = open ("pipe", O_WRONLY);
    write(fd, &sum, sizeof(sum));
    close(fd);
  }

  return 0;
}
