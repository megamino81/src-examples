#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

int
syncDir(const char *pathStr) {
    printf("%s, %s\n", __func__, pathStr);
    int ret = -1;
    //if (access(pathStr, F_OK) == 0) {
        struct stat s;
        if (stat(pathStr, &s) == 0) {
            ret = 0;
            int fd;
            if (s.st_mode & S_IFDIR) {
                printf("%s, path is directory\n", __func__);
                fd = open(pathStr, O_RDONLY);
            } else {
                printf("%s, path is file\n", __func__);
                char dirPath[256];
                char *s = strrchr(pathStr, '/');
                int len = s - pathStr;
                strncpy(dirPath, pathStr, len);
                dirPath[len] = 0;
                printf("%s, dirPath=%s\n", __func__, dirPath);
                fd = open(dirPath, O_RDONLY);
            }
            fsync(fd);
            close(fd);
        //}
        } else {
        printf("There is no such file.\n");
        }

    return ret;
}

int
main(int argc, char *argv[]) {
    printf("%d\n\n", syncDir("/home/mjung0/test/aa"));
    printf("%d\n\n", syncDir("/home/mjung0/test/aaa"));
    printf("%d\n\n", syncDir("/home/mjung0/test"));
    return 0;
}
