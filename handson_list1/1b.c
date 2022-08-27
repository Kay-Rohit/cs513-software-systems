
/* Name:Kantimahanty Rohit, Roll no. MT2022149 */
//hard link (link system call)

#include<fcntl.h>
#include<stdio.h>
#include<unistd.h>

int main(){
	char fn[]="test.file";
	char hln[]="test.hardlinnk";
	if(creat(fn, O_RDWR) == -1) printf("/n Error creating file with name %s", fn);
	if(!link(fn, hln)) printf("/n link creation success");
	else printf("/n unable to create hard link");

return 0;
}
