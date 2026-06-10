#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
/* Code Launcher For Noobs */
int main(void)
{
	char buff[999];
	int counter;
	int choice2;
	char sav[10];
	char code[999];
	char name[999];
	int gide;
	int choice;
	char prog[999];
	printf("CLFN-hello user!!\n");
	rest:
	printf("enter you program:");
	fgets(prog,sizeof(prog),stdin);
	prog[strcspn(prog,"\n")]=0;
	if(strcmp(prog,"")==0){
		printf("ARE YOU IDIOT >:(  ,write name of program please!!\n");
		goto rest;
	}
	printf("you need gide?\n1)yes\n2)no\n");
	scanf("%d",&gide);
	fgets(sav,sizeof(sav),stdin);
	if(gide==1){
		printf("@-hello I you friend, lets start .\n now you need write code , when you need to end you need wtite CLFN.PROGRAM.END and write arguments for program. \n I hope you be cool guy and you understand how to use that program\n");
	}
	sprintf(name,"CLFN%d.clfn",(int)(time(NULL)/365));
	FILE *f=fopen(name,"w+");
	while(1){
		printf(">>");
		fgets(code,sizeof(code),stdin);
		if(strcmp(code,"CLFN.PROGRAM.END\n")==0){
			break;
		}else{
		fprintf(f,"%s",code);
		}
	}
	fclose(f);
	printf("You realy need to run that code?\n1)yes\n2)no");
	scanf("%d",&choice);
	if(choice==2){
		exit(0);
	}else{
		printf("custom run or normal run?\n 1)custom run\n2)normal run\n");
		scanf("%d",&choice2);
		fgets(sav,sizeof(sav),stdin);
		pid_t t=fork();
		if(choice2==2){
			if(t==0){
				execlp(prog,prog,name,NULL);
				perror("");
				remove(name);
			}
		}else if(choice2==1){
			if(t==0){
			printf("now write how much args you need");
			scanf("%d",&counter);
			fgets(sav,sizeof(sav),stdin);
			if(counter!=0){
			char *args[counter+3];
		    args[0]=prog;
			for(int i=1;i<counter+1;i++){
				printf("write the %d argumet , if you need the file  name write CLFN.FILE.NAME\n>>",i);
				fgets(buff,sizeof(buff),stdin);
				buff[strcspn(buff,"\n")]=0;
				if(strcmp(buff,"CLFN.FILE.NAME")==0){
					args[i]=name;
				}else{
					args[i]=strdup(buff);
				}
			}
			args[counter+1]=NULL;
			execvp(prog,args);
			perror("");
			
			
			
			}else{
				printf("Ok,I understand you I go out");
				exit(0);
			}
			}else{
				wait(NULL);
				remove(name);
			}
		}
	}
	return 0;
	
	
	
}