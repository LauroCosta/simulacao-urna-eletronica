#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>
#include <string.h>
#include <windows.h>
#include <math.h>
#include "vota.h"
#include "relato.h"


int novocpf[11];
char senha[30]="11111111111";
int sabe=0;
void cpf();

int vota(){
    system("color 0F");



    FILE *apurar,*apurarEstadual,*apurarFederal,*apurarSenador,*apurarGonvernador,*cpf_cad;

    apurar=fopen("apurar.txt","w");
    apurarEstadual=fopen("apurarEstadual.txt","w");
    apurarFederal=fopen("apurarFederal.txt","w");
    apurarSenador=fopen("apurarSenador.txt","w");
    apurarGonvernador=fopen("apurarGonvernador.txt","w");
    cpf_cad=fopen("cadastramentocpf.txt","w");

        fclose(apurar);
	    fclose(apurarEstadual);
	    fclose(apurarFederal);
	    fclose(apurarSenador);
	    fclose(apurarSenador);
	    fclose(apurarGonvernador);
	    fclose(cpf_cad);

		cpf();
	return 0;
//059.977.273-51
}

void cpf(){
    char cpf1[11];

    char cpfaux[11];
	system("cls");
	int cont=0;
	char c;
	int conta=0,i=0,soma1=0,soma2=0,s=0,digito_calculado,r,t,digito_usuario;
	int k;
	printf("Informe o CPF: ");

   	do{
        c=getch();
            if(isdigit(c)){
                if(i<11){

                cpf1[i]=c;
                i++;
                printf("%c",c);

                if(i==3 || i==6){
				    printf(".");
                }
				else if( i==9){
					printf("-");

                }
            }

                }else if(c==8&&i!=0){

					if (i==3||i==6 ||i==9){
                        printf("\b \b");
                        cpf1[i]='\0';
                        i--;
                        printf("\b \b");
                }
					else {
                        cpf1[i]='\0';
                        i--;
                        printf("\b \b");
                }
            }
	}while(c!=13);


        if(senha[0]==cpf1[0]&&senha[1]==cpf1[1]&&senha[2]==cpf1[2]&&senha[3]==cpf1[3]&&senha[4]==cpf1[4]&&senha[5]==cpf1[5]&&
           senha[6]==cpf1[6]&&senha[7]==cpf1[7]&&senha[8]==cpf1[8]&&senha[9]==cpf1[9]&&senha[10]==cpf1[10]){
if(sabe==1){
		printf("\nVOTACAO FINALIZADA\n");
		printf("\nENCERRCANDO A URNA....");

		_sleep(2000);

        system("cls");
		apurarrela();
		system("pause > NULL");

		//exit(1);
}else{

printf("\nVOTACAO FINALIZADA\n");
		printf("\nENCERRCANDO A URNA....");

		_sleep(2000);

        system("cls");
		printf("\nNAO E POSSIVEL GERAR RELATORIO\n");
		printf("\nPRESSIONE QUALQUER TECLA PARA CONTINUAR\n");
		system("pause > NULL");

		main();
		//exit(1);



}


	}
	conta=strlen(cpf1);
	printf("\n");
	for(i=0;i<conta;i++){
		if(cpf1[i] != '.' && cpf1[i] != '-'){
			novocpf[s]=cpf1[i]-48;
			s++;
		}
	}

	if(novocpf[0]==novocpf[1]&&
		novocpf[2]==novocpf[3]&&
		novocpf[4]==novocpf[5]&&
		novocpf[6]==novocpf[7]&&
		novocpf[8]==novocpf[9]&&
		novocpf[9]==novocpf[10]){

			printf("CPF INVALIDO");
			getchar();
			cpf();

		}

		else{

		//Verificando Digito 1:

		for(i=0;i<9;i++){
			soma1=soma1 + ((novocpf[i])*(10-i));
			soma2=soma2 + ((novocpf[i])*(11-i));
		}

		soma1=(soma1*10)%11;

		if(soma1>9){
			soma1=0;
		}

		//Verificando Digito 2:

		soma2=(soma2+(soma1*2))*10%11;
		if(soma2>9){
			soma2=0;
		}

		digito_calculado=(soma1*10)+soma2;
		r=novocpf[9];
		t=novocpf[10];
		digito_usuario=((r)*10)+(t);
        FILE *arq;
        char temp[11];
        int aux=0;
        char cpf3[11];
		if(digito_calculado==digito_usuario){
			printf("CPF Valido");
			for(k=0;k<11;k++){
                cpf3[k]=cpf1[k];

			}


			getchar();

            arq=fopen("cadastramentocpf.txt","r");
            if(arq==NULL){
                puts("\nerro");
                exit(1);
            }

            while(fscanf(arq,"%s",temp)!=EOF){

                if(cpf3[1]==temp[1]&&cpf3[2]==temp[2]&&cpf3[3]==temp[3]
                   &&cpf3[4]==temp[4]&&cpf3[5]==temp[5]&&cpf3[6]==temp[6]){
                    aux++;
                    break;
                }

            }
            fclose(arq);
            if(aux==0){
                puts("\nPODE VOTAR\n");



                arq=fopen("cadastramentocpf.txt","a");
                if(arq==NULL){
                    puts("\nerro");
                    exit(1);
                }
                for(k=0;k<11;k++)
                fprintf(arq,"%c",cpf1[k]);

                fprintf(arq,"\n");

                fclose(arq);

                votac();
                sabe=1;
               _sleep(2000);
                cpf();


            } else{
                puts("VOCE JA VOTOU\n");
                puts("DIGITE NOVAMENTE");
                getchar();
                cpf();

            }


        }else{
				printf("CPF INVALIDO\n");
                puts("\nDIGITE NOVAMENTE");
                getchar();
                cpf();
			}
		}
	}

