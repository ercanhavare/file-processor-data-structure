#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
void createFile();
void copyFile();
void copyWithoutFile();
void mergeFiles();
void countChar();
FILE *fp1,*fp2,*fp3;
char fName[20],fdestName[20],fdestName2[20];
char read;
int main(int argc, char *argv[]) {
	int exit=0,i,f;
	char num[1];
	while(exit<=1){
		
	printf("\t\tFILE PROCESSOR\n");
	printf("====================================================\n\n");
	printf("1 - Create File\n");
	printf("2 - Copy File\n");
	printf("3 - Copy Without Spaces\n");
	printf("4 - Merge Files\n");
	printf("5 - Count Number Of Characters\n");
	printf("6 - Quit\n\n");
	
	printf("Please enter your choose number : ");
	scanf("%s",num);
	//printf("char : %s",num);//==> bug control
	for(i=0;i<num[i]!='\0';i++){ // check the num , digit or not-digit
  		if(!isdigit(num[i])>0){ // if num will not digit display warning !
  			printf("\nPlease enter number between [1 - 6] !\n");
		  }
	  }
	// describe f for pointer num , take the ascii code for control method
	  //printf("%d",*num); //==> bug control
	
	
	
		if(*num==49){
			createFile();
			system("pause");
			system("cls");
			
		}else if(*num==50){
			copyFile();
			system("pause");
			system("cls");
			
		}else if(*num==51){
			copyWithoutFile();
			system("pause");
			system("cls");
			
		}else if(*num==52){
			mergeFiles();
			system("pause");
			system("cls");
			
		}else if(*num==53){
			countChar();
			system("pause");
			system("cls");
			
		}else if(*num==54){
			printf("Goodbye :) \n");
			system("pause");
			return -1;
			
		}else{
			printf("Please enter number again!\n");
			system("pause");
			system("cls");
		}
		
	}// while end

	return 0;
}

void createFile(){
	int x;
	printf("Please enter file name : ");
	scanf("%s",&fName);
	strcat(fName,".txt");
	fp1=fopen(fName,"w");
	x=fprintf(fp1,"%s","Information was writed.");
	if(x) printf("File was created.\n");
	fclose(fp1);
}//end Create File


void copyFile(){
	int x;
	printf("Please enter copy name of the file : ");
	scanf("%s",fdestName);
	strcat(fdestName,".txt");
	fp1=fopen(fName,"r");
	fp2=fopen(fdestName,"w");
	
	while(!feof(fp1)){
		fscanf(fp1,"%c",&read);
		x=fprintf(fp2,"%c",read);
	}
	if(x) printf("All of the file was copied.\n");
	fclose(fp2);
	fclose(fp1);
}//end Copy File

void copyWithoutFile(){
	int x;
	printf("Please enter copy without file of name : ");
	scanf("%s",&fdestName2);
	strcat(fdestName2,".txt");
	fp1=fopen(fName,"r");
	fp3=fopen(fdestName2,"w");
	
	
	while(!feof(fp1)){
		fscanf(fp1,"%c",&read);
			if(!isspace(read)>0)
				x=fprintf(fp3,"%c",read);
		
	
	}
	if(x) printf("All of the file was copied.\n");
	fclose(fp3);
	fclose(fp1);
	
	
}//end Copy Without File

void mergeFiles(){
	int x;
	fp1=fopen(fName,"a");
	fp2=fopen(fdestName,"r");
	
	while(!feof(fp2)){
		fscanf(fp2,"%c",&read);
		x=fprintf(fp1,"%c",read);
	}
	if(x) printf("All of the file was copied.\n");
	fclose(fp2);
	fclose(fp1);
}//end Merge Files

void countChar(){
	int num=0;
	fp1=fopen(fName,"r");
	
	while(fscanf(fp1,"%c",&read)!=EOF){
		num++;
	}
	printf("count number of characters : %d\n\n",num);
	fclose(fp1);
	
}//end Count Numbers Of Characters


