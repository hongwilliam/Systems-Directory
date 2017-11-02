#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <sys/stat.h>
#include <time.h>
#include <dirent.h>
#include <string.h>

int main(){
  //given directly from class notes
  DIR *d = opendir(".");
  struct dirent *entry; //pointer to directory entry
  int total_bytes = 0;

  if (d == NULL){
    printf("You cannot open current directory!");
  }
  else{
    printf("Statistics for directory:  \n");
    //this while loop works because readdir keeps returning a pointer
    //to next entry in a directory stream until it hits NULL
    while( (entry = readdir(d)) != NULL){
      printf("\n%s", entry->d_name);
      if (entry->d_type == 4){
        printf(" (this is a directory!)"); }
      struct stat sb;
      stat(entry->d_name, &sb);
      size_t size = sb.st_size;
      total_bytes += size; }
    }

  closedir(d); //frees the memory
  printf("\n\nTotal Directory Size: %d %s%lf %s%lf %s%lf %s", total_bytes, "bytes/", total_bytes/1000.0, "KB/", total_bytes/1000000.0, "MB/", total_bytes/1000000000.0, "GB\n");
}
