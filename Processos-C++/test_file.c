#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
   
   FILE *fp, *fp2;
   
   int id = fork();

   if(id != 0) {
	   fp = fopen("test.txt", "w+");
	   if(fp != NULL) printf("O pai abriu\n");
	   else exit(-1);
	   fprintf(fp, "This is testing for fprintf...\n");
	   fputs("This is testing for fputs...\n", fp);
	   fclose(fp);
   } else {
		fp2 = fopen("test.txt", "w+");
		if(fp != NULL) printf("O filho abriu\n");
		else _exit(-1);
		fprintf(fp2, "2This is testing for fprintf...\n");
		fputs("2This is testing for fputs...\n", fp2);
		fclose(fp2);
		_exit(0);
   }
   exit(0);
}