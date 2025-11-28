#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    int src, dest;
    char buffer[1024];
    ssize_t bytesRead;

    src = open("result.txt", O_RDONLY);
    if (src < 0) {
        perror("Error opening result.txt");
        return 1;
    }

    dest = open("copyresult.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (dest < 0) {
        perror("Error creating copyresult.txt");
        close(src);
        return 1;
    }

    while ((bytesRead = read(src, buffer, sizeof(buffer))) > 0) {
        write(dest, buffer, bytesRead);
    }

    close(src);
    close(dest);

    return 0;
}
