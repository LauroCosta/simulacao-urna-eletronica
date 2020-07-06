#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
//DUAS VARIÁVEIS GLOBAIS, SERVE COMO CONTROLE PARA SOBRESCREVER O ARQUIVO
int aconteceP=0;
int acontece=0;
char numerocontrole[10];
//------------------------------------------------------------------
//FIZ UMA STRUCTT COM NOME ID=NUMERO DO CANDIDATO, PARTIDO, VICE, E NOME
/*typedef struct{
	char nome[30];
	char vice[30];
	char sigla[10];
	int  num;


}CAND;*/
CAND eleito;
CAND castd;

char pedeNome(char nome[], int x);
//char nome(char *g, int x);
void menu1(char *me, int cand_menu);
void control_12(char *num, int cand_num1);

void control_data(char *d, int cand_num);
//------------------------------------------------
//FUNÇÃO PARA CADASTRO DO PRESIDENTE
int presidente(int sa, char p2[50]);
//FUNÇÃO PARA CADASTRO DOS DEMAIS CANDIDATOS
int cadastro (int sen,char p1[50],int dep_ef,int sdef);




int cade (){
int i=0,es_menu,def,escp;
char es_k;

            system("cls");
char p[50]="PRESIDENTE";
char g[50]="GOVERNADOR";
char s[50]="SENADOR";
char df[50]="DEPUTADO FEDERAL";
char de[50]="DEPUTADO ESTADUAL";

//-----------------------------------------------
//MENU


printf("\nCADASTRO DOS CANDIDATOS\n");
printf("\n1-PRESIDENTE");
printf("\n2-GOVERNADOR");
printf("\n3-SENADOR");
printf("\n4-DEPUTADO FEDERAL");
printf("\n5-DEPUTADO ESTADUAL");
printf("\n6-SAIR DO CADASTRO\n");
puts("");
printf("\nDIGITE:");
menu1(numerocontrole,1);
es_menu=atoi(numerocontrole);

switch (es_menu){
    case 1:
        //presindente

        presidente(i,p);

    break;

    case 2:

        //Governador
        escp=0;
        i=1;
        def=0;
        cadastro(i,g,def,escp);

    break;
    case 3:

            //Senador
            escp=1;
            i=0;
            def=0;
            cadastro(i,s,def,escp);
    break;
    case 4:
        //deputado federal
        escp=2;
        i=0;
        def=1;
        cadastro(i,df,def,escp);

    break;
    case 5:

        //deputado estadual
        escp=3;
        i=0;
        def=1;
        cadastro(i,de,def,escp);
    break;
    case 6:
        //sair
        printf("\nCADASTRADO FINALIZADO\n");
    break;

}
//ESCOLHE SE QUER CONTINUAR OU SAIR
system("cls");
printf("\nDESEJA CADASTRAR CANDIDATOS PARA OUTRO CARGO?\n");
printf("\n\nDIGITE -->S<-- PARA CADASTRAR O CANDIDATO,\n\nOU PRESSIONE QUALQUER TECLA FINALIZAR O CADASTRO:");
//menu2(numerocontrole,1);
//tem que desenvolver uma função de oontrole
scanf("%c",&es_k);
setbuf(stdin,NULL);

if(es_k=='s'||es_k=='S'){

    cade();
}




return(0);
}

int cadastro (int sen, char p1[50], int dep_ef, int sdef) {
int errorr1;
int j;

int i=0;
CAND casdt;
int cont=1,cont1=0,quant,saber=0;
int sair=10;

CAND recebe;
do{//do-while
//sabe2=0;
sair=0;

    setbuf(stdin,NULL);

        system("cls");
        saber=0;
        cont1++;

    setbuf(stdin,NULL);
if(sen==0){
	//obtendo os dados
	//obtendo os dados
	printf("\nCANDIDATO A %s:",p1);
    setbuf(stdin,NULL);

	//fgets(casdt.nome,100,stdin);
	pedeNome(casdt.nome,30);


	setbuf(stdin,NULL);

	//printf("\nVICE:");

	//fgets(casdt.vice,100,stdin);
	//pedeNome(casdt.vice,30);
	setbuf(stdin,NULL);

	//converter para maiúsculo


	printf("\nPARTIDO:");
	//fgets(casdt.sigla,10,stdin);
	pedeNome(casdt.sigla,10);
	setbuf(stdin,NULL);
//	printf("\nOLHA: PARTIDO:%s, %s\n",casdt.sigla,p1);
  //  getchar();



	printf("\nNUMERO DO CANDIDATO:");

	if(sdef==1){


                control_data(numerocontrole,3);
                casdt.num=atoi(numerocontrole);


	}else if(sdef==2){

                control_data(numerocontrole,4);
                casdt.num=atoi(numerocontrole);



	}else if (sdef==3){

                control_data(numerocontrole,5);
                casdt.num=atoi(numerocontrole);



	}

            system("cls");

}else if(sen==1){

    //obtendo os dados
	printf("\nCANDIDATO A %s:",p1);
    setbuf(stdin,NULL);

	//fgets(casdt.nome,100,stdin);
	pedeNome(casdt.nome,30);


	setbuf(stdin,NULL);

	printf("\nVICE:");

	//fgets(casdt.vice,100,stdin);
	pedeNome(casdt.vice,30);
	setbuf(stdin,NULL);

	//converter para maiúsculo


	printf("\nPARTIDO:");
	//fgets(casdt.sigla,10,stdin);
	pedeNome(casdt.sigla,10);
	setbuf(stdin,NULL);
	//printf("\nOLHA: PARTIDO:%s, %s\n",casdt.sigla,p1);
    //getchar();

	printf("\nNUMERO DO CANDIDATO:");

	setbuf(stdin,NULL);
	control_data(numerocontrole,2);
    casdt.num=atoi(numerocontrole);

            system("cls");
}
	//criando arquivos
	FILE *dado_cand;
if(acontece==0){
        acontece++;


	dado_cand=fopen("cadastro.txt","w");//arquivo texto mesmo

		if(dado_cand==NULL){

			printf("\nErro nao e possível acessar o arquivo\n");

			exit(1);
		}else{

            //printf("\nAberto com susscesso\n");

		}
        fclose(dado_cand);
        }


    dado_cand=fopen("cadastro.txt","a+");

     if(dado_cand==NULL){

			printf("\nErro nao E possível acessar o arquivo\n");

			exit(1);
		}

            while(1){

                errorr1=fread(&recebe, sizeof(CAND),1,dado_cand);



             //   printf("\n%s\n\n%s\n\n%d\n",recebe.nome,recebe.sigla,recebe.num);
               // getchar();
                if(sen==0){

                        if(dep_ef==0){
                if(strcmp(recebe.nome,casdt.nome)==0 || strcmp(recebe.sigla,casdt.sigla)==0 || recebe.num==casdt.num ){

                    saber++;

                }



                }else if(dep_ef==1){

                if(strcmp(recebe.nome,casdt.nome)==0 || recebe.num==casdt.num ){

                    saber++;
                   // printf("\nolha\n");
                }


                }





                }else if(sen==1){
                    //caso o governador
                      if(strcmp(recebe.nome,casdt.nome)==0 || strcmp(recebe.vice,casdt.vice)==0 || strcmp(recebe.sigla,casdt.sigla)==0 || recebe.num==casdt.num ){

                    saber++;

                }




                }
                if(feof(dado_cand)){

                    break;
                }

            }



		if(saber==0){
            int error1;

           // printf("%s,%s,%s,%d",casdt.nome,casdt.vice,casdt.sigla, casdt.num);
           // getchar();
            error1=fwrite(&casdt,sizeof(CAND),1,dado_cand);
                if(error1==1){
                        //system("cls");
            system("clS");
                    printf("\nCADASTRADO COM SUCESSO\n");
                    fclose(dado_cand);

                    printf("\nDIGITE\n1 PARA SAIR DO CADASTRO DE %s\n2 PARA CONTINUAR\n",p1);
                    printf("\nDIGITE:");
                    control_12(numerocontrole,1);
                    sair=atoi(numerocontrole);

                            if(sair==1){
                                        system("cls");

                                 cont=0;

                            }else if (sair==2){
                                    system("cls");
                                printf("\nCONTINUANDO COM CADASTRO DE %s",p1);
                                printf("\nPRESSIONE QUALQUER TECLA PARA PROSSEGUIR\n");
                                getch();


                            }



                        }


                    } else{
                    system("cls");
                printf("\nERRO AO CADASTRAR: ALGUNS DADOS JA FORAM ADICIONADO EM OUTRO CANDIDATO\n");
                          printf("\nPRESSIONE QUALQUER TECLA PARA PROSSEGUIR\n");
                            getch();


    printf("\nDIGITE\n1 PARA SAIR DO CADASTRO DE %s\n2 PARA CONTINUAR\n",p1);
                    printf("\nDIGITE:");
                   control_12(numerocontrole,1);
                    sair=atoi(numerocontrole);


                            if(sair==1){
                                system("cls");


                                 cont=0;

                            }else if (sair==2){
                                system("cls");
                                printf("\nCONTINUANDO COM CADASTRO DE %s",p1);
                                printf("\nPRESSIONE QUALQUER TECLA PARA PROSSEGUIR\n");

                                getch();

                            }


}

                            }while(cont);


                return(0);


                }




int presidente(int sa, char p2[50]){
int j;

int errorr1;
    //int cadastro (candidato casdt, char cand1[20],int sen);
int i=0;
CAND casdt;
int cont=1,cont1=0,quant,saber=0;
int sair=10;

CAND recebe;
do{//do-while

sair=0;


        system("cls");
        saber=0;
        cont1++;

    setbuf(stdin,NULL);

	//obtendo os dados
	printf("\nCANDIDATO A %s:",p2);
    setbuf(stdin,NULL);

	//fgets(casdt.nome,100,stdin);
	pedeNome(casdt.nome,30);

	setbuf(stdin,NULL);



	printf("\nVICE:");

	//fgets(casdt.vice,100,stdin);
	pedeNome(casdt.vice,30);
	setbuf(stdin,NULL);



	printf("\nPARTIDO:");
	//fgets(casdt.partido,100,stdin);
	pedeNome(casdt.sigla,10);
	setbuf(stdin,NULL);



	printf("\nNUMERO DO CANDIDATO:");
        control_data(numerocontrole,2);
        casdt.num=atoi(numerocontrole);


	//criando arquivos
	FILE *dado_cand;
if(aconteceP==0){
        aconteceP++;


	dado_cand=fopen("pcadastro.txt","w");//arquivo texto mesmo

		if(dado_cand==NULL){

			printf("\nErro não é possível acessar o arquivo\n");

			exit(1);
		}else{

            //printf("\nAberto com susscesso\n");

		}
        fclose(dado_cand);
        }


    dado_cand=fopen("pcadastro.txt","a+");

     if(dado_cand==NULL){

			printf("\nErro não é possível acessar o arquivo\n");

			exit(1);
		}

            while(1){

                errorr1=fread(&recebe, sizeof(CAND),1,dado_cand);



                //printf("\n%s\n\n%s\n\n%d\n",recebe.nome,recebe.partido,recebe.id);
                if(strcmp(recebe.nome,casdt.nome)==0 ||strcmp(recebe.vice,casdt.vice)==0||strcmp(recebe.sigla,casdt.sigla)==0 || recebe.num==casdt.num ){

                    saber++;

                }
                if(feof(dado_cand)){
                        //printf("\nFIM\n");
                    break;
                }

            }



		if(saber==0){
            int error1;
            error1=fwrite(&casdt,sizeof(CAND),1,dado_cand);
                if(error1==1){
                        system("cls");
                    printf("\nCADASTRADO COM SUCESSO\n");
                    fclose(dado_cand);

                    printf("\nDIGITE\n1 PARA SAIR DO CADASTRO DE %s\n2 PARA CONTINUAR\n",p2);
                    printf("\nDIGITE:");
                    control_12(numerocontrole,1);
                    sair=atoi(numerocontrole);

                    getchar();


                            if(sair==1){
                                system("cls");

                                cont=0;




                            }else if (sair==2){
                                system("cls");
                                printf("\nCONTINUANDO COM CADASTRO DE %s",p2);
                                printf("\nPRESSIONE QUALQUER TECLA PARA PROSSEGUIR\n");
                                getch();

                            }



                        }


                    }

                //pertence a do
                  else{
                    system("cls");
                    printf("\nERRO AO CADASTRAR: ALGUNS DADOS JA FORAM ADICIONADO EM OUTRO CANDIDATO\n");
                    printf("\nPRESSIONE QUALQUER TECLA PARA PROSSEGUIR\n");
                    getch();

    printf("\nDIGITE\n1 PARA SAIR DO CADASTRO DE %s\n2 PARA CONTINUAR\n",p2);
                    printf("\nDIGITE:");

                    control_12(numerocontrole,1);
                    sair=atoi(numerocontrole);


                            if(sair==1){
                                system("cls");

                                cont=0;




                            }else if (sair==2){
                                system("cls");
                                printf("\nCONTINUANDO COM CADASTRO DE %s",p2);
                                printf("\nPRESSIONE QUALQUER TECLA PROSSEGUIR\n");

                                getch();

                            }




                            }




                }while(cont);


                return(0);




}

void control_data(char *d, int cand_num){
    int descobre=0;
    int j;
    j=0;
    char k;

    do{
       k=getch();

            if(isdigit(k)!=0&&j<cand_num){


                    descobre++;
                    d[j]=k;
                    j++;
                    printf("%c",k);
                }else if(j<cand_num&&k==13){


                    d[j]=='\0';
                    k=getch;

                }else if(k==8&&j){

                    d[j]='\0';
                    j--;
                    printf("\b \b");

                }







    }while(k!=13);

    d[j]='\0';

    //if(descobre==0){

       // control_data(d,cand_num);

   // }


}

void control_12(char *num, int cand_num1){
int i,descobre=0;
i=0;
char u;
do{
        u=getch();
    if(u=='1'||u=='2'){

        if(i<cand_num1){
                descobre++;
                num[i]=u;
                i++;
                printf("%c",u);

        }


        }else if(u==8&&i){
            num[i]='\0';
            i--;
            printf("\b \b");
        }






}while(u!=13);

num[i]='\0';
if(descobre==0){
    control_12(num,cand_num1);

}


}

void menu1(char *me, int cand_num2){
int i,descobre=0;
i=0;
char u;
do{
        u=getch();


        if(u=='1'||u=='2'||u=='3'||u=='4'||u=='5'||u=='6'){
                if(i<cand_num2){
                            descobre++;
                            me[i]=u;
                            i++;
                            printf("%c",u);

                }

        }else if(u==8&&i){
            me[i]='\0';
            i--;
            printf("\b \b");
        }





}while(u!=13);

me[i]='\0';

if(descobre==0){
    menu1(me,cand_num2);

}





}


char pedeNome(char nome[], int x){
    char c;
    int i=0;
    do{
        c=getch();
                if(c==8&&i){
                    nome[i]='\0';
                    i--;
                    printf("\b \b");
                }else if(c==32||c>64&&c<92||c>96&&c<124){
                            nome[i]=c;
                            i++;
                            printf("%c",c);
                }
            }while(c!=13);
            nome[i]='\0';

            return strupr(nome);

}

void menu2(char *me, int cand_num2){
int i,descobre=0;
i=0;
char u;
do{
        u=getch();


        if(u=='s'||u=='S'){
                if(i<cand_num2){
                            descobre++;
                            me[i]=u;
                            i++;
                            printf("%c",u);

                }

        }else if(u==8&&i){
            me[i]='\0';
            i--;
            printf("\b \b");
        }





}while(u!=13);

me[i]='\0';



}










