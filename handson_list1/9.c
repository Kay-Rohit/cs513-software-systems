/* Name:Kantimahanty Rohit, Roll no. MT2022149 */
/*9. Write a program to print the following information about a given file.
 a. inode
 b. number of hard links
 c. uid
 d. gid
 e. size
 f. block size
 g. number of blocks
 h. time of last access
 i. time of last modification
 j. time of last change*/


#include<stdio.h>
#include<time.h>
#include<sys/stat.h>
#include<unistd.h>
#include<errno.h>

//input files are taken from command line argument
//give file names(with extention) as command line arguments while executing the program

int main(int argc, char * argv[])
{
struct stat fileS;
int i;
if(argc!=2)
  printf("No arrgument provided ! \n");
for(i=0;i<argc-1;i++)
{
	if(stat(argv[i], &fileS) == -1)
		printf("Cannot read file!! \n");
	else
	{
		printf("\n\nPrinting data for %s ...\n", argv[i]);
		printf("Inode Number : %lu \n", fileS.st_ino);
		printf("Number of hard links : %lu \n", fileS.st_nlink);
		printf("UID : %d \n", fileS.st_uid);
		printf("GID : %d \n", fileS.st_gid);
		printf("Size : %lu \n", fileS.st_size);
		printf("Bloack Size : %lu \n", fileS.st_blksize);
		printf("Number of blocks : %lu \n", fileS.st_blocks);
		printf("last accessed : %s \n", ctime(&fileS.st_atime));
		printf("last Modifies : %s \n", ctime(&fileS.st_mtime));
		printf("last change : %s \n", ctime(&fileS.st_ctime));
	}
}
return 0;
}
