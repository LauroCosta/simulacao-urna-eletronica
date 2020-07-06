#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
typedef struct{
    char nome[30];
    char vice[30];
    char sigla[10];
    int num;
}CAND;*/


int arqpartido(){

    CAND dados;
    FILE *cadastros, *partidos, *cadastrop;

    cadastrop=fopen("pcadastro.txt","r");
    if(cadastrop==NULL){

        printf("\nERRO 2\n");
    }


    cadastros=fopen("cadastro.txt","r");
    if(cadastros==NULL){
        printf("erro1");
        exit(1);

    }
    int a=0;
    if(a==0){
    a=1;
    partidos=fopen("partidoCadastrados.txt","w");
    if(partidos==NULL){
        printf("erro");
        exit(1);

    }


    }if(a==1){

     partidos=fopen("partidoCadastrados.txt","a+");
    if(partidos==NULL){
        printf("erro");
        exit(1);


    }
    }

//----------------parte para extrair do partido se é igual ou não
    char sigla[10];
    int aux=0;
    while(!feof(cadastros)){
        aux=0;
       // printf("\n%s",dados.sigla);
        fread(&dados,sizeof(CAND),1,cadastros);

        partidos=fopen("partidoCadastrados.txt","r");
        while(fscanf(partidos,"%s",sigla)!=EOF){

            if(strcmp(sigla,dados.sigla)==0){
                fclose(partidos);
                aux++;
                break;
            }
        }
    if(aux==0){
        partidos=fopen("partidoCadastrados.txt","a");
        fprintf(partidos,"\n%s",dados.sigla);
        fclose(partidos);
    }


    }
//-------------fim
//----------------parte para extrair do partido se é igual ou não

//----------------PARTE DO PRESIDENTE;
    char sigla2[10];
    int aux1=0;
    while(!feof(cadastrop)){
        aux1=0;
       // printf("\n%s",dados.sigla2);
        fread(&dados,sizeof(CAND),1,cadastrop);

        partidos=fopen("partidoCadastrados.txt","r");
        while(fscanf(partidos,"%s",sigla2)!=EOF){

            if(strcmp(sigla2,dados.sigla)==0){
                fclose(partidos);
                aux1++;
                break;
            }
        }
    if(aux1==0){
        partidos=fopen("partidoCadastrados.txt","a");
        fprintf(partidos,"\n%s",dados.sigla);
        fclose(partidos);
    }


    }
//-------------fim
    return 0;
}
