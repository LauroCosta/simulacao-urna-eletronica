#include <stdio.h>
#include <string.h>
//estrutura
typedef struct{
    char nome[30];
    char vice[30];
    char sigla[10];
    int num;
}cand;

//fun��es para o cadastro autom�tico
void governador();
void presidente();
void senador();
void deputadofederal();
void deputadoestadual();

int main () {

presidente();
governador();
senador();
deputadofederal();
deputadoestadual();
printf("\nPRESSIONE QUALQUER TECLA PARA PROSSEGUIR\n");
getch();

return (0);
}
void presidente(){
int acontece=0;
int err;
FILE *pre;
 int aux=0;
cand test;
char d[100];
printf("\nIdentificar PRESIDENTE\n");
char h[]="presidente";
char g[]="-";
FILE *arq;
arq=fopen("candidatos.txt","r");
if(arq==NULL){

    printf("\nErro ao abrir o arquivo\n");

}
while(1){

    fscanf(arq,"%s",d);
  // printf("OLHA:\n%s\n",d);
    if(strcmp(d,h)==0){


    do{
             if(acontece==0){

                pre=fopen("pcadastro.txt","w");
                acontece++;
            }else {

            pre=fopen("pcadastro.txt","a");
            }

        aux++;
        fscanf(arq,"%s %s %s %d",test.nome, test.vice, test.sigla,&test.num);

       if(strcmp(test.nome,"-")==0){
        break;

       }
        strupr(test.nome);strupr(test.vice);strupr(test.sigla);
        printf("\nNOME:%s\nVICE:%s\nPARTIDO:%s\nNUMERO:%d\n",test.nome,test.vice,test.sigla,test.num);
           err=fwrite(&test,sizeof(cand),1,pre);
            if(err==1){

                printf("\nCADASTRADO COM SUCESSO\n");

            }
            fclose(pre);

    }while(strcmp(test.nome,"-")!=0);

    }

//getchar();

    if(feof(arq)){
        break;
    }
}
fclose(arq);

}
void governador(){

int aux=0;
FILE *pre1;
int err;
cand test;
char d[100];
printf("\nIdentificar GOVERNADOR\n");
char h[]="governador";
char g[]="-";
FILE *arq;
int acontece1=0;;
arq=fopen("candidatos.txt","r");
if(arq==NULL){

    printf("\nErro ao abrir o arquivo\n");

}
while(1){

    fscanf(arq,"%s",d);
    //printf("OLHA:\n%s\n",d);
    if(strcmp(d,h)==0){


    do{
            if(acontece1==0){

               pre1=fopen("cadastro.txt","w");
                acontece1++;
            }else{

                pre1=fopen("cadastro.txt","a");
            }

        aux++;
        fscanf(arq,"%s %s %s %d",test.nome, test.vice, test.sigla,&test.num);
       if(strcmp(test.nome,"-")==0){
        break;

       }
       strupr(test.nome);strupr(test.vice);strupr(test.sigla);
        printf("\nNOME:%s\nVICE:%s\nPARTIDO:%s\nNUMERO:%d\n",test.nome,test.vice,test.sigla,test.num);
            err=fwrite(&test,sizeof(cand),1,pre1);
            if(err==1){
                printf("\nCADASTRADO COM SUCESSO\n");

            }
            fclose(pre1);
    }while(strcmp(test.nome,"-")!=0);

    }

//getchar();

    if(feof(arq)){
        break;
    }
}
fclose(arq);

}
void senador (){
int aux=0;
cand test;
FILE *pre2;
int err;
char d[100];
printf("\nIdentificar SENADOR\n");
char h[]="senador";
char g[]="-";
FILE *arq;
arq=fopen("candidatos.txt","r");
if(arq==NULL){

    printf("\nErro ao abrir o arquivo\n");

}
while(1){

    fscanf(arq,"%s",d);
    //printf("OLHA:\n%s\n",d);
    if(strcmp(d,h)==0){

    do{
            pre2=fopen("cadastro.txt","a");

        aux++;
        fscanf(arq,"%s %s %d",test.nome,test.sigla,&test.num);
       if(strcmp(test.nome,"-")==0){
        break;

       }
       strupr(test.nome);strupr(test.sigla);

        printf("\nNOME:%s\nPARTIDO:%s\nNUMERO:%d\n",test.nome,test.sigla,test.num);
       err=fwrite(&test,sizeof(cand),1,pre2);
        if(err==1){
            printf("\nCADASTRADO COM SUCESSO\n");
        }
        fclose(pre2);

    }while(strcmp(test.nome,"-")!=0);

    }

//getchar();

    if(feof(arq)){

        break;
    }

}
fclose(arq);

}
void deputadofederal(){
int aux,err;
cand test;
FILE *pre3;
char d[100];
printf("\nIdentificar DEPUTADO FEDERAL\n");
char h[]="deputadofederal";
char g[]="-";
FILE *arq;
arq=fopen("candidatos.txt","r");
if(arq==NULL){

    printf("\nErro ao abrir o arquivo\n");

}
while(1){
int acontece=0;
    fscanf(arq,"%s",d);
    //printf("OLHA:\n%s\n",d);
    if(strcmp(d,h)==0){

    do{
            pre3=fopen("cadastro.txt","a");
        aux++;
        fscanf(arq,"%s %s %d",test.nome,test.sigla,&test.num);
       if(strcmp(test.nome,"-")==0){
        break;
        acontece++;
       }
       strupr(test.nome);strupr(test.sigla);
        printf("\nNOME:%s\nPARTIDO:%s\nNUMERO:%d\n",test.nome,test.sigla,test.num);
        err=fwrite(&test,sizeof(cand),1,pre3);
        if(err==1){
            printf("\nCADASTRADO COM SUCESSO\n");
        }
        fclose(pre3);
    }while(strcmp(test.nome,"-")!=0);

    }

//getchar();
    if(feof(arq)){

        break;
    }
    if(acontece!=0){
        break;
    }

}
fclose(arq);


}
void deputadoestadual(){
int err;
int aux=0;
cand test;
char d[100];
FILE *pre4;
printf("\nIdentificar DEPUTADO ESTADUAL\n");
char h[]="deputadoestadual";
char g[]="-";
FILE *arq;
arq=fopen("candidatos.txt","r");
if(arq==NULL){

    printf("\nErro ao abrir o arquivo\n");

}
while(1){

    fscanf(arq,"%s",d);
    //printf("OLHA:\n%s\n",d);
    if(strcmp(d,h)==0){

    do{
         pre4=fopen("cadastro.txt","a");

        aux++;
        fscanf(arq,"%s %s %d",test.nome,test.sigla,&test.num);
       if(strcmp(test.nome,"-")==0){
        break;

       }
       strupr(test.nome);strupr(test.sigla);
        printf("\nNOME:%s\nPARTIDO:%s\nNUMERO:%d\n",test.nome,test.sigla,test.num);
        err=fwrite(&test,sizeof(cand),1,pre4);
        if(err==1){
            printf("\nCADASTRADO COM SUCESSO\n");

        }
    }while(strcmp(test.nome,"-")!=0);

    }

//getchar();

    if(feof(arq)){

        break;
    }
}
fclose(arq);
}
