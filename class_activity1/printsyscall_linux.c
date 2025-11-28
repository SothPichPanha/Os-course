#include <unistd.h>

int main() {
    const char *message = "Hello from Linux system call!\n";
    write(1, message, 31); // stdout = file descriptor 1
    return 0;
}
