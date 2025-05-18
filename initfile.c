#include<stdio.h>
#include<errno.h>
#include<string.h>
#define MAX_LENGTH 256
char buffer[MAX_LENGTH];
int main(int argc,char *argv[]){
	if(argc < 3) {
		fprintf(stderr,"usage :  <template> <filename> \n");
		fprintf(stderr,"example : initfile text.txt newtext.txt \n");
		return -1;
	}
	char *template_name = argv[1];
	char *newfile_name = argv[2];
	FILE *template,*newfile;
	if((template = fopen(template_name,"r")) == NULL) {
		printf("error : %s\n",strerror(errno));
		fprintf(stderr,"Template file Doesn't exist or Unable to open\n");
		return -1;
	}
	if(( newfile = fopen(newfile_name,"w+")) == NULL) {
		printf("error : %s\n",strerror(errno));
		fprintf(stderr,"can not create a new file\n");
		return -1;
	}

	while(fgets(buffer,MAX_LENGTH,template)){
		fprintf(newfile,"%s",buffer);	
	}
	fclose(template);
	fclose(newfile);
	return 0;
}
