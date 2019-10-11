#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define SIZE 100

void menu();
void input_fun();
void print_fun();
int search_fun();    
void modify_fun();   
void delete_fun();
void insert_fun();
void rank_fun();
void add_fun();

struct staff_type{
	char num[10];
	char name[10];       //����һ������Ա������ؼ����ؼ�绰ؼ��ַ�Ľṹ�� 
	char tel[15];
    char address[50];
};
struct staff_type staff[SIZE];

int main()
{
menu();	
}

void menu()
{
char choice;
printf("                                              \n");
printf(" \t\t\t\t|****************��ѡ��*****************|\n");
printf(" \t\t\t\t|             1.����Ա������            |    \n");
printf(" \t\t\t\t|             2.����Ա������            |    \n");
printf(" \t\t\t\t|             3.��ӡԱ������            |    \n");
printf(" \t\t\t\t|             4.�޸�Ա������            |    \n");
printf(" \t\t\t\t|             5.ɾ��Ա������            |    \n");
printf(" \t\t\t\t|             6.����Ա������            |    \n");
printf(" \t\t\t\t|             7.Ա����������            |    \n");
printf(" \t\t\t\t|             8.���Ա������            |   \n");
printf(" \t\t\t\t|             0.�˳�                    |\n");
printf(" \t\t\t\t|***************************************|\n");
printf("��ѡ��");

choice=getchar();getchar();


switch(choice)
{case '1':input_fun();break;
 case '2':search_fun();break;
 case '3':print_fun();break;
 case '4':modify_fun();break;
 case '5':delete_fun();break;   //����choice���ö�Ӧ�ĺ��� 
 case '6':insert_fun();break;
 case '7':rank_fun();break;
 case '8':add_fun();;break;
 case '0':exit(0);
 default :printf("\nѡ�����\n");
}


menu();//�ݹ����menu���� 
}


//����Ա����Ϣ 
void input_fun()
{  FILE *fp;
   int i=0; 
   char c;
  if((fp=fopen("staff.txt","w"))==NULL)
  {
  	printf("���ܴ��ļ�");         //ֻд���ļ� 
  	exit(0);
  } 
  
  printf("����������:\n");
   while(i<SIZE)
     {printf("������5λ����Ա������:\n");
      gets(staff[i].num);
      while(strlen(staff[i].num)!=5)
      {
      	printf("���������������������:\n");
      	gets(staff[i].num);
	  }
      printf("������Ա������:\n");
	  gets(staff[i].name);        //����Ա����Ϣ 
	  printf("������Ա���绰:\n");
	  gets(staff[i].tel);
	      while(strlen(staff[i].tel)!=11)
      {
      	printf("�绰���벻�Ϸ�������������:\n");
      	gets(staff[i].tel);
	  }
	  printf("������Ա��סַ:\n");
	  gets(staff[i].address); 
	  i++;
	  
	  printf("����n��������,������������\n");
	   	c=getchar();
	   	getchar();
	   	if(c=='n')                  //�ж��Ƿ�������� 
	   	  break;
	 }
	fwrite(staff,sizeof(staff[0]),i,fp);    //������д���ļ� 
	fclose(fp);
}

void print_fun()
{  FILE *fp;
   int n=0; 
   
	if((fp=fopen("staff.txt","r"))==NULL)
  {
  	printf("���ܴ��ļ�");         //ֻ�����ļ� 
  	exit(0);
  } 
	
	printf("����\t����\t�绰\t\tסַ\n");
	while(fread(&staff[n],sizeof(staff[n]),1,fp)==1)        //���ļ��������ݲ��������Ļ 
	{printf("%s\t%s\t%s\t%s\t\n",staff[n].num,staff[n].name,staff[n].tel,staff[n].address);  
	 n++;
	}
	 fclose(fp);
}

//���Һ��� 
int search_fun()
{FILE *fp;
   int n=0,i; 
   char ch;
   char s[10];
   int flag=0;              //�ж��Ƿ��ҵ���Ϣ���ҵ�flag=1 
	if((fp=fopen("staff.txt","r"))==NULL)
  {
  	printf("���ܴ��ļ�");         //���ļ� 
  	exit(0);
  } 
	while(fread(&staff[n],sizeof(staff[n]),1,fp)==1)    
	n++;                                                 //���ļ��е����ݶ������ṹ���� 
	
	printf("����ͨ����һ�ַ�ʽ����\n");
	printf("1.����   2.����\n");
	ch=getchar();getchar();
	switch(ch)
	{ 
	   case '1':
	   	        printf("��������Ҫ����Ա��������:\n");
	   	        gets(s);
	   	           for(i=0;i<n;)
	   	              {
	   	              	if(strcmp(s,staff[i].name)==0)
	   	              	{                                    //�����ṹ�������ַ����ȽϺ���ʵ������ؼ���ŵĲ��� 
	   	              		 flag=1;
							 break;
						}
	   	              	i++;                      
					  }
					  break;
	   case '2':
	   	        printf("��������Ҫ����Ա���Ĺ���\n");
	   	        gets(s);
	   	           for(i=0;i<n;)
	   	              {
	   	              	if(strcmp(s,staff[i].num)==0)
	   	              	   {
	   	              	   	flag=1;
							break;
						   } 
	   	              	i++;
	   	              }
	   	              break;
	}
     if(flag==0)
       {
	   printf("û�ҵ���Ա����Ϣ\n");
	   return -1;
       }
     if(flag==1)
        {   printf("���ҵ�������Ϣ�ǣ�\n");          //����flag�ж��Ƿ��ҵ�����ִ�ж�Ӧ���� 
        	printf("����\t����\t�绰\t\tסַ\n");
	        printf("%s\t%s\t%s\t%s\t\n",staff[i].num,staff[i].name,staff[i].tel,staff[i].address);
     	}	
	
fclose(fp);
return i;
}

//�޸ĺ��� 
void modify_fun()
{
	FILE *fp;
	int n=0,i;
	char c,s[10];
	printf("��������޸�Ա����Ϣ,��������ҵ���\n\n");
	i=search_fun();
	if(i!=-1)         //���ݵ��ò��Һ�����ȡi��i=-1˵��û�ҵ�Ա����Ϣ
	                   //���Բ������ݽ����޸� 
{

 if((fp=fopen("staff.txt","r+"))==NULL)
  {
  	printf("���ܴ��ļ�");         //���ļ� 
  	exit(0);
  } 
	
	while(fread(&staff[n],sizeof(staff[n]),1,fp)==1)
	n++; 
	              
	printf("�����޸�ʲô��Ϣ\n");
	printf("1.����  2.����   3.�绰   4.��ַ\n");
	c=getchar();getchar();
	switch(c)
	{
		case '1':
			     printf("�������µ�����:\n");
			     gets(staff[i].name);
			     break;
		case '2':
		         printf("�������µĹ���:\n");   //����c��ָ�޸Ķ�ӦԱ������Ϣ 
				 gets(staff[i].num);
				 break;
		case '3':
		         printf("�������µĵ绰:\n");
				 gets(staff[i].tel);
				 break;
		case '4':
		         printf("�������µĵ�ַ:\n");	     
			     gets(staff[i].address);
			     break;
	}
    printf("\n���޸�\n"); 
	printf("����\t����\t�绰\t\tסַ\n");
	printf("%s\t%s\t%s\t%s\t\n",staff[i].num,staff[i].name,staff[i].tel,staff[i].address);
	rewind(fp);
	fwrite(staff,sizeof(staff[0]),n,fp);
	fclose(fp);
}
    else
    printf("û�д�Ա����Ϣ���޷��޸ģ��˳��˹���\n"); 

}

//ɾ������ 
void delete_fun()
{
	
	FILE *fp;
	int n=0,i;
	char c,s[10];
	printf("�������ɾ��Ա����Ϣ,��������ҵ���\n");
	i=search_fun();
	if(i!=-1)
{  printf("�Ƿ�ɾ����Ա������\t  1.��   2.��\n");
   c=getchar();getchar();
   if(c=='1')
   {
   
 if((fp=fopen("staff.txt","r+"))==NULL)
  {
  	printf("���ܴ��ļ�");         //���ļ� 
  	exit(0);
  } 
	
	while(fread(&staff[n],sizeof(staff[n]),1,fp)==1)
	n++;
	
	for(;i<n;i++)
	staff[i]=staff[i+1];     //�ú�����Ϣ����ǰ����Ϣʵ��ɾ�� 
	
	fp=fopen("staff.txt","w");
	fwrite(staff,sizeof(staff[0]),n-1,fp);   //���´��ļ���д������ 
	fclose(fp);
	printf("�Ѿ�ɾ����Ա����Ϣ");
}
else
printf("ȡ��ɾ��Ա����Ϣ");
}
   else
   printf("û�д�Ա����Ϣ\n");
}

//���뺯�� 
void insert_fun()
{
	FILE *fp;
	int n=0,i,j;
	printf("����������Ա����Ϣ,�����ҵ���Ҫ����֮ǰ��λ��\n");
	i=search_fun();
	if(i!=-1)
	{
 if((fp=fopen("staff.txt","r+"))==NULL)
  {
  	printf("���ܴ��ļ�");         //���ļ� 
  	exit(0);
  } 
	
	while(fread(&staff[n],sizeof(staff[n]),1,fp)==1)
	n++;

	for(j=n-1;j>i-1;j--)
	staff[j+1]=staff[j];   //��Ա������������һ�� 
	
	printf("�������µ�Ա������\n");
      gets(staff[i].num);
      printf("������Ա������\n");
	  gets(staff[i].name);        //����Ա����Ϣ 
	  printf("�������µ�Ա���绰\n");
	  gets(staff[i].tel);
	  printf("�������µ�Ա��סַ\n");
	  gets(staff[i].address); 
	  printf("\n�Ѳ���\n");
	  rewind(fp);
	  fwrite(staff,sizeof(staff[0]),n+1,fp);//д��Ա����Ϣ 
      fclose(fp);
    }
else
printf("û�ҵ�����λ��");
    
}

//������ 
void rank_fun()
{   char c;
    int n=0,j,k;
	FILE *fp;
	int i;
	struct staff_type temp; //�����м�������������� 
	
	 if((fp=fopen("staff.txt","r+"))==NULL)
  {
  	printf("���ܴ��ļ�");         //���ļ� 
  	exit(0);
  } 
	
		while(fread(&staff[n],sizeof(staff[n]),1,fp)==1)
     	n++;
     	
     printf("����ͨ�����ַ�ʽ��������\n");
	 printf("1.����   2.����\n");
	 	c=getchar();getchar();
	 	if(c=='1')
	 	{
	 		for(i=0;i<n-1;i++)
	 		  { int k=i;
				for(j=i+1;j<n;j++)
	 		      if(strcmp(staff[j].name,staff[k].name)<0)
	 		        {
	 		        	k=j;
					}
					if(i!=k)
					{
						temp=staff[i];
	 		         staff[i]=staff[k];
	 		         staff[k]=temp;	
					}
	 		 	}
		}                                  //����ð�ݷ����� 
		if(c=='2')
		{
		for(i=0;i<n-1;i++)
	 		  { int k=i;
				for(j=i+1;j<n;j++)
	 		      if(strcmp(staff[j].num,staff[k].num)<0)
	 		        {
	 		        	k=j;
					}
					if(i!=k)
					{
						temp=staff[i];
	 		         staff[i]=staff[k];
	 		         staff[k]=temp;	
					}
	 		 	}	
		}    		    
	  rewind(fp);
	  fwrite(staff,sizeof(staff[0]),n,fp);
      fclose(fp);
      printf("������\n");
      print_fun(); 
}

//��Ӻ��� 
void add_fun()
{   FILE *fp;
    int n=0;
	if((fp=fopen("staff.txt","a"))==NULL)
  {
  	printf("���ܴ��ļ�");         //��׷����ʽ���ļ� 
  	exit(0);
  } 
	
		while(fread(&staff[n],sizeof(staff[n]),1,fp)==1)
     	n++;
    fclose(fp); 	
    if((fp=fopen("staff.txt","a"))==NULL)
  {
  	printf("���ܴ��ļ�");         //��׷����ʽ���ļ� 
  	exit(0);
  } 
	  printf("�������µ�Ա������\n");
      gets(staff[n].num);
      printf("������Ա������\n");
	  gets(staff[n].name);        //����Ա����Ϣ 
	  printf("�������µ�Ա���绰\n");
	  gets(staff[n].tel);
	  printf("�������µ�Ա��סַ\n");
	  gets(staff[n].address); 
	  printf("�����\n");
	 fwrite(staff,sizeof(staff[0]),1,fp);
     fclose(fp);
	
}
