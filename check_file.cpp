#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <magic.h>



void check_file(char * path)
{
    struct stat stats;
    

    if (stat(path, &stats) < 0)
        {
            printf("Unable to get file properties.\n");
            printf("Please check whether '%s' file exists.\n", path);
        }    
    else
        {
            struct tm dt;

            // File permissions
            printf("\nFile access: ");
            if (stats.st_mode & R_OK)
                printf("read ");
            if (stats.st_mode & W_OK)
                printf("write ");
            if (stats.st_mode & X_OK)
                printf("execute");

            // File size
            printf("\nFile size: %d", stats.st_size);

            // Get file creation time in seconds and 
            // convert seconds to date and time format
            dt = *(gmtime(&stats.st_ctime));
            printf("\nCreated on: %d-%d-%d %d:%d:%d", dt.tm_mday, dt.tm_mon, dt.tm_year + 1900, 
                                                      dt.tm_hour, dt.tm_min, dt.tm_sec);

            // File modification time
            dt = *(gmtime(&stats.st_mtime));
            printf("\nModified on: %d-%d-%d %d:%d:%d", dt.tm_mday, dt.tm_mon, dt.tm_year + 1900, 
                                                      dt.tm_hour, dt.tm_min, dt.tm_sec);

        }


    const char *mime;
    magic_t magic;

    printf("\n\nGetting magic from %s\n", path);

    magic = magic_open(MAGIC_MIME_TYPE); 
    magic_load(magic, NULL);
    magic_compile(magic, NULL);
    mime = magic_file(magic, path);

    printf("%s\n", mime);
    magic_close(magic);
      
}


