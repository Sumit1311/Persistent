#include    <sys/types.h>
#include    <fcntl.h>

int
main(int argc, char *argv[])
{

    int     accmode, val;

    val = fcntl(atoi(argv[1]), F_GETFL, 0);

    accmode = val & O_ACCMODE;
    if      (accmode == O_RDONLY)   printf("read only");
    else if (accmode == O_WRONLY)   printf("write only");
    else if (accmode == O_RDWR)     printf("read write");

    if (val & O_APPEND)         printf(", append");
    if (val & O_NONBLOCK)       printf(", nonblocking");
#if !defined(_POSIX_SOURCE) && defined(O_SYNC)
    if (val & O_SYNC)           printf(", synchronous writes");
#endif
    putchar('\n');
    exit(0);
}
