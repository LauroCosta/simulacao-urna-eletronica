#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char nome[30];
    char vice[30];
    char sigla[10];
    int num;
}tes;
//int gerapart();
int seraQexite () {

  FILE *arq_saber;
    FILE *arq_p;

   tes pegar;

   int saber[5];
   int sabedosabe=0;
   int i;

   for(i=0; i<5; i++){

        saber[i]=0;
   }

//------------------------------saber se existe arquivo--------------------------
        arq_saber=fopen("cadastro.txt","r");
        if(arq_saber==NULL){

           // printf("\nERRO:CADASTRE TODOS OS CANDIDATOS\n");
            return 1;
        }

//----------------------------------saber se existe arquivo-----------------------
        arq_p=fopen("pcadastro.txt","r");

        if(arq_p==NULL){

              //  printf("\nERRO: CADASTRE TODOS OS CANDIDATOS\n");
                return 1;
        }

//-------------------------presidente-------------------------
        while(1){
            fread(&pegar,sizeof(tes),1,arq_p);

                if(pegar.num>9&&pegar.num<100){
                    //presidente
                    saber[0]=1;

                }


            if(feof(arq_p)){

                break;

            }

        }
        fclose(arq_p);
//--------------------governadores,senadores,deputados estaduais e federais----------------------------------

        while(1){
            fread(&pegar,sizeof(tes),1,arq_saber);

                if(pegar.num>9&&pegar.num<100){
                    //governador
                    saber[1]=2;

                }
                if(pegar.num>99&&pegar.num<1000){
                    //senador
                        saber[2]=3;
                }
                if(pegar.num>999&&pegar.num<10000){
                    //deputadofederal
                    saber[3]=4;

                }
                if(pegar.num>9999&&pegar.num<100000){
                    //deputadoestadual
                    saber[4]=5;
                }



            if(feof(arq_saber)){

                break;

            }

        }
        fclose(arq_saber);

    if(saber[0]==0){
        sabedosabe++;
        printf("\nFALTA OS CANDIDATOS A PRESIDENCIA\n");
    }
    if(saber[1]==0){
        sabedosabe++;
        printf("\nFALTA OS CANDIDATOS AO GOVERNO\n");
    }
    if(saber[2]==0){
            sabedosabe++;
        printf("\nFALTA OS CANDIDATOS AO SENADO ");

    }if(saber[3]==0){
        sabedosabe++;
        printf("\nFALTA OS CANDIDATOS A DEPUTADO FEDERAL\n");
    }if(saber[4]==0){
        sabedosabe++;
        printf("\nFALTA OS CANDIDATOS A DEPUTADO ESTADUAL\n");
    }

if(sabedosabe!=0){
        //serve como controle para não voltar sem candidatos na urna
    return 1;

}





return 5;
}


