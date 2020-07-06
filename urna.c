#include <stdio.h>
#include <time.h>
#include "cpfvota.h"
#include "cadastro.h"
#include "veripart.h"
#include "gerarpartido.h"

//#include "auto.h"
int achou=0;
   int supremasabe=0;
int main () {
    int d;
    int escolha;
/*
    FILE *arq1,*arq2;
    if(achou==0){

            achou=1;
    arq1=fopen("cadastro.txt","w");
    if(arq1==NULL){
        printf("\nERRO\n");

    }
    fclose(arq1);
    arq2=fopen("pcadastro.txt","w");
    if(arq2==NULL){

        printf("\nERRO\n");
    }
    fclose(arq2);
    }
*/

    system("cls");

    printf("\n===========>>>>ELEICOES<<<<===========\n");
    printf("\n\n===============CONFIGURACAO===============\n\n");
    printf("\n(1) cadastrar\n");
    printf("\n(2) votar\n");

    //tem que desenvolver uma função de controle
    setbuf(stdin,NULL);
    scanf("%d",&d);
    setbuf(stdin,NULL);
switch(d){

    case 1:
        system("cls");
        printf("\n->1<-CADASTRO MANUAL\n");
        printf("->2<- CADASTRO AUTOMATICO\n");

        puts("");

        printf("\nDigite:");

        scanf("%d",&escolha);


        setbuf(stdin,NULL);

        switch(escolha){
            case 1:
                cade ();
                system("cls");
                main();
                break;
            case 2:
               // autocadastro();
                system("cls");
                system("auto");
                main();

                break;
                }
    case 2:

            supremasabe=seraQexite();
            if(supremasabe==1){
                printf("\nERROR: NAO E POSSIVEL VOTAR SEM TODOS CANDIDATOS CADASTRADOS\n");
                    _sleep(5000);
                    system("cls");
                    main();
            }else if(supremasabe==5){
            arqpartido();
            vota();
            //votac ();

            }





    break;


}
return (0);
}
