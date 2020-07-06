#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <conio.h>

typedef struct{
    char nome[30];
    char vice[30];
    char sigla[10];
    int num;
}CAND,cand;

void  votarEstadual();
void  votarFederal();
void  votarSenador();
void  votarGonvernador();
void  votarPresidente();

void nuloBranco(char *frase);

char pedeOpcao(char opcao);
int pedeNumero(char digita[],int tMax,int t);

int votac(){
    votarEstadual();
    votarFederal();
    votarSenador();
    votarGonvernador();
    votarPresidente();
    fim();
    return 0;
}
char pedeOpcao(char opcao){
    char c;
    int i=0;
    do{
        c=getch();
                if(c==13&&i){
                    opcao='\0';
                    i--;
                    printf("\b \b");
                }else if(c==67||c==99||c==82||c==114){
                    opcao=c;
                    i++;
                    printf("%c",c);
                    return c;
                }
            }while(c!=8);
}
int pedeNumero(char digita[],int tMax, int t){
    char c;
    int i=0;
    int num;
    do{
        c=getch();
        if(isdigit(c)!=0){
            digita[i]=c;
            i++;
            printf("%c",c);

        }else if(c==8&&i){
            digita[i]='\0';
            i--;
            printf("\b \b");
        }else if(c==66||c==98){

            return 1;
        }
    }while(i<t||c=='b');
    digita[i]='\0';
           num=atoi(digita);
            return num;
}

void votarEstadual(){
    int aux=0,num;
    char op;
    char *cargo,*colchetes;
    cargo="DEPUTADO ESTADUAL";
    colchetes="Numero: [ ][ ][ ][ ][ ]";
    char *nulo,*branco;
    nulo="DESEJA ANULAR O SEU VOTO ?";
    branco="DESEJA VOTAR EM BRANCO ?";


    CAND dados;// TIPO DE ESTRUTURA
//============ARQUIVO DOS CADASTROS==============================
    FILE* cadastro;
    cadastro=fopen("cadastro.txt","r");//MODO LEITURA
    if(cadastro==NULL){
        printf("Erro ao abrir arquivo");
        exit(1);
    }
//=================ABRE O ARQUIVO DE CONTABILIAR OS VOTOS========
    FILE* apurarEstadual;
    apurarEstadual=fopen("apurarEstadual.txt","a");//MODO ANEXAR
    if(apurarEstadual==NULL){
        printf("Erro ao abrir arquivo");
        exit(1);
    }
    char digitaNumero[5];
    char digitaOpcao;
    telaInicial(cargo,colchetes,15);//TELA LIMPA DE VOTAÇÃO
    num=(pedeNumero(digitaNumero,5,5));
    //scanf("%d",&num);
//===============VOTO EM BRANCO===========================
        if(num==1){
            nuloBranco(branco);  //CHAMA A TELA DE VOTO EM BRANCO
            setbuf(stdin,NULL);
            op=pedeOpcao(digitaOpcao);

            if(op=='r'||op=='R'){
                aux++;
                votarEstadual();
            }
            if(op=='c'||op=='C'){
                aux++;
                fprintf(apurarEstadual,"BRANCO\n");
                Beep(3300,250);
            }
//====================VOTO VALIDO===========================
        }else{
            while(!feof(cadastro)){
            fread(&dados,sizeof(CAND),1,cadastro);
                if(num==dados.num){ // SE O NUMERO DIGITADO FOR IGUAL A ALGO ESSE NUMERO EH DE UM CANDIDATO
                    aux++;
                    estadual2(dados);
                    setbuf(stdin,NULL);
                    op=pedeOpcao(digitaOpcao);

                if(op=='c'||op=='C'){//CONFIRMA O VOTO NO CANDIDATO ENCONTRADO
                    fprintf(apurarEstadual,"%d %s  %s\n",num,dados.nome,dados.sigla);
                    Beep(3300,250);//SOM DE CONFIRMAÇAO
                }

                if(op=='r'||op=='R')
                    votarEstadual();//RECURSAO OPÇAO CORRIGIR
            break;
                }
            }
        }
//=======================VOTO NULO======================================
        if(aux==0){
            nuloBranco(nulo);//CHAMA A TELA NULO
            setbuf(stdin,NULL);
            op=pedeOpcao(digitaOpcao);

            if(op=='c'||op=='C'){//CONFIRMA VOTO NULO
                fprintf(apurarEstadual,"NULO\n");
                Beep(3300,250);
            }
            if(op=='r'||op=='R')
                votarEstadual();
        }
    fclose(apurarEstadual);//FECHA ARQUIVO,
}
void votarFederal(){
    int aux=0,num;
    char op;
    char *cargo,*colchetes;
    cargo="DEPUTADO FEDERAL";
    colchetes="Numero: [ ][ ][ ][ ]";
    char *nulo,*branco;
    nulo="DESEJA ANULAR O SEU VOTO ?";
    branco="DESEJA VOTAR EM BRANCO ?";



    CAND dados;// TIPO DE ESTRUTURA
//============ARQUIVO DOS CADASTROS==============================
    FILE* cadastro;
    cadastro=fopen("cadastro.txt","r");//MODO LEITURA
    if(cadastro==NULL){
        printf("Erro ao abrir arquivo");
        exit(1);
    }
//=================ABRE O ARQUIVO DE CONTABILIAR OS VOTOS========
    FILE* apurarFederal;
    apurarFederal=fopen("apurarFederal.txt","a");//MODO ANEXAR
    if(apurarFederal==NULL){
        printf("Erro ao abrir arquivo");
        exit(1);
    }
    char digitaNumero[5];
    char digitaOpcao;
    telaInicial(cargo,colchetes,11);//TELA LIMPA DE VOTAÇÃO
    num=(pedeNumero(digitaNumero,5,4));
//===============VOTO EM BRANCO===========================
        if(num==1){
            nuloBranco(branco);  //CHAMA A TELA DE VOTO EM BRANCO
            setbuf(stdin,NULL);
            op=pedeOpcao(digitaOpcao);

            if(op=='r'||op=='R'){
                aux++;
                votarFederal();
            }
            if(op=='c'||op=='C'){
                aux++;
                fprintf(apurarFederal,"BRANCO\n");
                Beep(3300,250);
            }
//====================VOTO VALIDO===========================
        }else{
            while(!feof(cadastro)){
            fread(&dados,sizeof(CAND),1,cadastro);
                if(num==dados.num){ // SE O NUMERO DIGITADO FOR IGUAL A ALGO ESSE NUMERO EH DE UM CANDIDATO
                    aux++;
                    federal2(dados);
                    setbuf(stdin,NULL);
                    op=pedeOpcao(digitaOpcao);

                if(op=='c'||op=='C'){//CONFIRMA O VOTO NO CANDIDATO ENCONTRADO
                    fprintf(apurarFederal,"%d %s  %s\n",num,dados.nome,dados.sigla);
                    Beep(3300,250);//SOM DE CONFIRMAÇAO
                }

                if(op=='r'||op=='R')
                    votarFederal();//RECURSAO OPÇAO CORRIGIR
            break;
                }
            }
        }
//=======================VOTO NULO======================================
        if(aux==0){
            nuloBranco(nulo);//CHAMA A TELA NULO
            setbuf(stdin,NULL);
            op=pedeOpcao(digitaOpcao);

            if(op=='c'||op=='C'){//CONFIRMA VOTO NULO
                fprintf(apurarFederal,"NULO\n");
                Beep(3300,250);
            }
            if(op=='r'||op=='R')
                votarFederal();
        }
    fclose(apurarFederal);//FECHA ARQUIVO,
}
void votarSenador(){
    int aux=0,num;
    char op;
    char *cargo,*colchetes;
    cargo="SENADOR";
    colchetes="Numero: [ ][ ][ ]";
    char *nulo,*branco;
    nulo="DESEJA ANULAR O SEU VOTO ?";
    branco="DESEJA VOTAR EM BRANCO ?";


    CAND dados;// TIPO DE ESTRUTURA
//============ARQUIVO DOS CADASTROS==============================
    FILE* cadastro;
    cadastro=fopen("cadastro.txt","r");//MODO LEITURA
    if(cadastro==NULL){
        printf("Erro ao abrir arquivo");
        exit(1);
    }
//=================ABRE O ARQUIVO DE CONTABILIAR OS VOTOS========
    FILE* apurarSenador;
    apurarSenador=fopen("apurarSenador.txt","a");//MODO ANEXAR
    if(apurarSenador==NULL){
        printf("Erro ao abrir arquivo");
        exit(1);
    }
    char digitaNumero[5];
    char digitaOpcao;
    telaInicial(cargo,colchetes,16);//TELA LIMPA DE VOTAÇÃO
    num=(pedeNumero(digitaNumero,5,3));
//===============VOTO EM BRANCO===========================
        if(num==1){
          nuloBranco(branco);  //CHAMA A TELA DE VOTO EM BRANCO
            setbuf(stdin,NULL);
            op=pedeOpcao(digitaOpcao);

            if(op=='r'||op=='R'){
                aux++;
                votarSenador();
            }
            if(op=='c'||op=='C'){
                aux++;
                fprintf(apurarSenador,"BRANCO\n");
                Beep(3300,250);
            }
//====================VOTO VALIDO===========================
        }else{
            while(!feof(cadastro)){
            fread(&dados,sizeof(CAND),1,cadastro);
                if(num==dados.num){ // SE O NUMERO DIGITADO FOR IGUAL A ALGO ESSE NUMERO EH DE UM CANDIDATO
                    aux++;
                    senador2(dados);
                    setbuf(stdin,NULL);
                    op=pedeOpcao(digitaOpcao);

                if(op=='c'||op=='C'){//CONFIRMA O VOTO NO CANDIDATO ENCONTRADO
                    fprintf(apurarSenador,"%d %s  %s\n",num,dados.nome,dados.sigla);
                    Beep(3300,250);//SOM DE CONFIRMAÇAO
                }

                if(op=='r'||op=='R')
                    votarSenador();//RECURSAO OPÇAO CORRIGIR
            break;
                }
            }
        }
//=======================VOTO NULO======================================
        if(aux==0){
            nuloBranco(nulo);//CHAMA A TELA NULO
            setbuf(stdin,NULL);
            op=pedeOpcao(digitaOpcao);

            if(op=='c'||op=='C'){//CONFIRMA VOTO NULO
                fprintf(apurarSenador,"NULO\n");
                Beep(3300,250);
            }
            if(op=='r'||op=='R')
                votarSenador();
        }
    fclose(apurarSenador);//FECHA ARQUIVO,
}
void votarGonvernador(){
    int aux=0,num;
    char op;
    char *cargo,*colchetes;
    cargo="GONVERNADOR";
    colchetes="Numero: [ ][ ]";
    char *nulo,*branco;
    nulo="DESEJA ANULAR O SEU VOTO ?";
    branco="DESEJA VOTAR EM BRANCO ?";



    CAND dados;// TIPO DE ESTRUTURA
//============ARQUIVO DOS CADASTROS==============================
    FILE* cadastro;
    cadastro=fopen("cadastro.txt","r");//MODO LEITURA
    if(cadastro==NULL){
        printf("Erro ao abrir arquivo");
        exit(1);
    }
//=================ABRE O ARQUIVO DE CONTABILIAR OS VOTOS========
    FILE* apurarGonvernador;
    apurarGonvernador=fopen("apurarGonvernador.txt","a");//MODO ANEXAR
    if(apurarGonvernador==NULL){
        printf("Erro ao abrir arquivo");
        exit(1);
    }
    char digitaNumero[5];
    char digitaOpcao;
    telaInicial(cargo,colchetes,15);//TELA LIMPA DE VOTAÇÃO
    num=(pedeNumero(digitaNumero,5,2));
//===============VOTO EM BRANCO===========================
        if(num==1){
            nuloBranco(branco);  //CHAMA A TELA DE VOTO EM BRANCO
            setbuf(stdin,NULL);
            op=pedeOpcao(digitaOpcao);

            if(op=='r'||op=='R'){
                aux++;
                votarGonvernador();
            }
            if(op=='c'||op=='C'){
                aux++;
                fprintf(apurarGonvernador,"BRANCO\n");
                Beep(3300,250);
            }
//====================VOTO VALIDO===========================
        }else{
            while(!feof(cadastro)){
            fread(&dados,sizeof(CAND),1,cadastro);
                if(num==dados.num){ // SE O NUMERO DIGITADO FOR IGUAL A ALGO ESSE NUMERO EH DE UM CANDIDATO
                    aux++;
                    gonvernador2(dados);
                    setbuf(stdin,NULL);
                    op=pedeOpcao(digitaOpcao);

                if(op=='c'||op=='C'){//CONFIRMA O VOTO NO CANDIDATO ENCONTRADO
                    fprintf(apurarGonvernador,"%d %s  %s\n",num,dados.nome,dados.sigla);
                    Beep(3300,250);//SOM DE CONFIRMAÇAO
                }

                if(op=='r'||op=='R')
                    votarGonvernador();//RECURSAO OPÇAO CORRIGIR
            break;
                }
            }
        }
//=======================VOTO NULO======================================
        if(aux==0){
            nuloBranco(nulo);//CHAMA A TELA NULO
            setbuf(stdin,NULL);
            op=pedeOpcao(digitaOpcao);

            if(op=='c'||op=='C'){//CONFIRMA VOTO NULO
                fprintf(apurarGonvernador,"NULO\n");
                Beep(3300,250);
            }
            if(op=='r'||op=='R')
                votarGonvernador();
        }
    fclose(apurarGonvernador);//FECHA ARQUIVO,
}
void votarPresidente(){
    int aux=0,num;
    char op;
    char *cargo,*colchetes;
    cargo="PRESIDENTE";
    colchetes="Numero: [ ][ ]";
    char *nulo,*branco;
    nulo="DESEJA ANULAR O SEU VOTO ?";
    branco="DESEJA VOTAR EM BRANCO ?";


    CAND dados;// TIPO DE ESTRUTURA
//============ARQUIVO DOS CADASTROS==============================
    FILE* cadastro;
    cadastro=fopen("pcadastro.txt","r");//MODO LEITURA
    if(cadastro==NULL){
        printf("Erro ao abrir arquivo");
        exit(1);
    }
//=================ABRE O ARQUIVO DE CONTABILIAR OS VOTOS========
    FILE* apurar;
    apurar=fopen("apurar.txt","a");//MODO ANEXAR
    if(apurar==NULL){
        printf("Erro ao abrir arquivo");
        exit(1);
    }
    char digitaNumero[5];
    char digitaOpcao;
    telaInicial(cargo,colchetes,15);//TELA LIMPA DE VOTAÇÃO
    num=(pedeNumero(digitaNumero,5,2));
//===============VOTO EM BRANCO===========================
        if(num==1){
            nuloBranco(branco);  //CHAMA A TELA DE VOTO EM BRANCO
            setbuf(stdin,NULL);
            op=pedeOpcao(digitaOpcao);

            if(op=='r'||op=='R'){
                aux++;
                votarPresidente();
            }
            if(op=='c'||op=='C'){
                aux++;
                fprintf(apurar,"BRANCO\n");
                Beep(3300,250);
                 Beep(3300,250);
                  Beep(3300,250);
            }
//====================VOTO VALIDO===========================
        }else{
            while(!feof(cadastro)){
            fread(&dados,sizeof(CAND),1,cadastro);
                if(num==dados.num){ // SE O NUMERO DIGITADO FOR IGUAL A ALGO ESSE NUMERO EH DE UM CANDIDATO
                    aux++;
                    presidente2(dados);
                    setbuf(stdin,NULL);
                    op=pedeOpcao(digitaOpcao);

                if(op=='c'||op=='C'){//CONFIRMA O VOTO NO CANDIDATO ENCONTRADO
                    fprintf(apurar,"%d %s  %s\n",num,dados.nome,dados.sigla);
                    Beep(3300,250);
                     Beep(3300,250);
                      Beep(3300,250);//SOM DE CONFIRMAÇAO
                }

                if(op=='r'||op=='R')
                    votarPresidente();//RECURSAO OPÇAO CORRIGIR
            break;
                }
            }
        }
//=======================VOTO NULO======================================
        if(aux==0){
            nuloBranco(nulo);//CHAMA A TELA NULO
            setbuf(stdin,NULL);
            op=pedeOpcao(digitaOpcao);

            if(op=='c'||op=='C'){//CONFIRMA VOTO NULO
                fprintf(apurar,"NULO\n");
                Beep(3300,250);
                Beep(3300,250);
                Beep(3300,250);
                    Beep(3300,250);


            }
            if(op=='r'||op=='R')
                votarPresidente();
        }
    fclose(cadastro);//FECHA ARQUIVO,
    fclose(apurar);
}

void nuloBranco(char *frase){
    int i,j;
    system("cls");
    printf("\n\n");
    for(i=0;i<21;i++){
        printf("  ");
        for(j=0;j<65;j++){
 //==============IMPRESSAO DOS TEXTOS===================================
            if(i==1&&j==48){
                printf("JUSTI%cA",128);
                j+=7;}
            if(i==2&&j==47){
                printf("ELEITORAL");
                j+=9;}

            if(i==8&&j==8){
                printf("%s",frase);
                j+=strlen(frase);}

            if(i==17&&j==6){
                printf("(R)CORRIGIR");
                j+=11;}
            if(i==16&&j==6){
                printf("TECLE:");
                j+=6;}
            if(i==18&&j==6){
                printf("(C)CONFIRMAR");
                j+=12;}
//==============BOTOES BRANCO CORRIGE CONFRMA===========================
            if(i==17&&j==42){
                printf("BRNCO%cCRRGE%cCNFRMA",176,176);
                j+=18;
            }
            if(i==18&&j==42){
                printf("     %c     %c      ",176,176);
                j+=18;
            }
//==================BOTOES NUMERICOS====================================
            if(i==5&&j==44){
                printf(" 1  %c 2  %c 3  ",176,176);
                j+=14;}
            if(i==6&&j==44){
                printf("    %c    %c    ",176,176);
                j+=14;}

            if(i==8&&j==44){
                printf(" 4  %c 5  %c 6  ",176,176);
                j+=14;}
            if(i==9&&j==44){
                printf("    %c    %c    ",176,176);
                j+=14;}

            if(i==11&&j==44){
                printf(" 7  %c 8  %c 9  ",176,176);
                j+=14;}
            if(i==12&&j==44){
                printf("    %c    %c    ",176,176);
                j+=14;}

            if(i==14&&j==49){
                printf(" 0  ");
                j+=4;}
            if(i==15&&j==49){
                printf("    ");
                j+=4;}
//===================IMPRESAO DA URNA===========================

          if(i==15&&j>=5&&j<=35)
                printf("=");
          else if(i>=1&&i<=2&&j>=40&&j<=61)
                    printf("%c",177);
               else if(i>=2&&i<=18&&j>=5&&j<=35)
                        printf(" ");
                    else
                        if(i>=4&&i<=19&&j>=40&&j<=61)
                            printf("%c",176);
                        else
                            printf("%c",219);
//==============================================================
        }
    puts("");
    }
}

void estadual2(CAND dados){
    int i,j;
    system("cls");
    printf("\n\n");
    for(i=0;i<21;i++){
        printf("  ");
        for(j=0;j<65;j++){
 //==============IMPRESSAO DOS TEXTOS===================================
            if(i==1&&j==48){
                printf("JUSTI%cA",128);
                j+=7;}
            if(i==2&&j==47){
                printf("ELEITORAL");
                j+=9;}
            if(i==2&&j==6){
                printf("SEU VOTO PARA:");
                j+=14;}
            if(i==5&&j==11){
                printf("DEPUTADO ESTADUAL");
                j+=17;}

            if(i==9&&j==6){

                printf("Nome: %s",dados.nome);
                j+=6+ strlen(dados.nome);}
            if(i==11&&j==6){
                printf("Partido: %s",dados.sigla);
                j+=9+strlen(dados.sigla);}

            if(i==7&&j==6){
                printf("N%cmero: [%d][%d][%d][%d][%d]",233,dados.num/10000
                                                      ,(dados.num/1000)%10
                                                      ,(dados.num/100)%10
                                                      ,(dados.num/10)%10
                                                      , dados.num%10);
                j+=23;}
            if(i==17&&j==6){
                printf("(R)CORRIGIR");
                j+=11;}
            if(i==16&&j==6){
                printf("TECLE:");
                j+=6;}
            if(i==18&&j==6){
                printf("(C)CONFIRMAR");
                j+=12;}
//==============BOTOES BRANCO CORRIGE CONFRMA===========================
            if(i==17&&j==42){
                printf("BRNCO%cCRRGE%cCNFRMA",176,176);
                j+=18;
            }
            if(i==18&&j==42){
                printf("     %c     %c      ",176,176);
                j+=18;
            }
//==================BOTOES NUMERICOS====================================
            if(i==5&&j==44){
                printf(" 1  %c 2  %c 3  ",176,176);
                j+=14;}
            if(i==6&&j==44){
                printf("    %c    %c    ",176,176);
                j+=14;}

            if(i==8&&j==44){
                printf(" 4  %c 5  %c 6  ",176,176);
                j+=14;}
            if(i==9&&j==44){
                printf("    %c    %c    ",176,176);
                j+=14;}

            if(i==11&&j==44){
                printf(" 7  %c 8  %c 9  ",176,176);
                j+=14;}
            if(i==12&&j==44){
                printf("    %c    %c    ",176,176);
                j+=14;}

            if(i==14&&j==49){
                printf(" 0  ");
                j+=4;}
            if(i==15&&j==49){
                printf("    ");
                j+=4;}
//===================IMPRESAO DA URNA===========================

          if(i==15&&j>=5&&j<=35)
                printf("=");
          else if(i>=1&&i<=2&&j>=40&&j<=61)
                    printf("%c",177);
               else if(i>=2&&i<=18&&j>=5&&j<=35)
                        printf(" ");
                    else
                        if(i>=4&&i<=19&&j>=40&&j<=61)
                            printf("%c",176);
                        else
                            printf("%c",219);
//==============================================================
        }
    puts("");
    }


}
void federal2(CAND dados){
    int i,j;
    system("cls");
    printf("\n\n");
    for(i=0;i<21;i++){
        printf("  ");
        for(j=0;j<65;j++){
 //==============IMPRESSAO DOS TEXTOS===================================
            if(i==1&&j==48){
                printf("JUSTI%cA",128);
                j+=7;}
            if(i==2&&j==47){
                printf("ELEITORAL");
                j+=9;}
            if(i==2&&j==6){
                printf("SEU VOTO PARA:");
                j+=14;}
            if(i==5&&j==11){
                printf("DEPUTADO FEDERAL");
                j+=16;}

            if(i==9&&j==6){

                printf("Nome: %s",dados.nome);
                j+=6+ strlen(dados.nome);}
            if(i==11&&j==6){
                printf("Partido: %s",dados.sigla);
                j+=9+strlen(dados.sigla);}

            if(i==7&&j==6){
                printf("N%cmero: [%d][%d][%d][%d]",233,dados.num/1000
                                                      ,(dados.num/100)%10
                                                      ,(dados.num/10)%10
                                                      ,(dados.num/1)%10);

                j+=20;}
            if(i==17&&j==6){
                printf("(R)CORRIGIR");
                j+=11;}
            if(i==16&&j==6){
                printf("TECLE:");
                j+=6;}
            if(i==18&&j==6){
                printf("(C)CONFIRMAR");
                j+=12;}
//==============BOTOES BRANCO CORRIGE CONFRMA===========================
            if(i==17&&j==42){
                printf("BRNCO%cCRRGE%cCNFRMA",176,176);
                j+=18;
            }
            if(i==18&&j==42){
                printf("     %c     %c      ",176,176);
                j+=18;
            }
//==================BOTOES NUMERICOS====================================
            if(i==5&&j==44){
                printf(" 1  %c 2  %c 3  ",176,176);
                j+=14;}
            if(i==6&&j==44){
                printf("    %c    %c    ",176,176);
                j+=14;}

            if(i==8&&j==44){
                printf(" 4  %c 5  %c 6  ",176,176);
                j+=14;}
            if(i==9&&j==44){
                printf("    %c    %c    ",176,176);
                j+=14;}

            if(i==11&&j==44){
                printf(" 7  %c 8  %c 9  ",176,176);
                j+=14;}
            if(i==12&&j==44){
                printf("    %c    %c    ",176,176);
                j+=14;}

            if(i==14&&j==49){
                printf(" 0  ");
                j+=4;}
            if(i==15&&j==49){
                printf("    ");
                j+=4;}
//===================IMPRESAO DA URNA===========================

          if(i==15&&j>=5&&j<=35)
                printf("=");
          else if(i>=1&&i<=2&&j>=40&&j<=61)
                    printf("%c",177);
               else if(i>=2&&i<=18&&j>=5&&j<=35)
                        printf(" ");
                    else
                        if(i>=4&&i<=19&&j>=40&&j<=61)
                            printf("%c",176);
                        else
                            printf("%c",219);
//==============================================================
        }
    puts("");
    }


}
void senador2(CAND dados){
    int i,j;
    system("cls");
    printf("\n\n");
    for(i=0;i<21;i++){
        printf("  ");
        for(j=0;j<65;j++){
 //==============IMPRESSAO DOS TEXTOS===================================
            if(i==1&&j==48){
                printf("JUSTI%cA",128);
                j+=7;}
            if(i==2&&j==47){
                printf("ELEITORAL");
                j+=9;}
            if(i==2&&j==6){
                printf("SEU VOTO PARA:");
                j+=14;}
            if(i==5&&j==15){
                printf("SENADOR");
                j+=7;}

            if(i==9&&j==6){

                printf("Nome: %s",dados.nome);
                j+=6+ strlen(dados.nome);}
            if(i==11&&j==6){
                printf("Partido: %s",dados.sigla);
                j+=9+strlen(dados.sigla);}

            if(i==7&&j==6){
                printf("N%cmero: [%d][%d][%d]",233,dados.num/100
                                                      ,(dados.num/10)%10
                                                      ,(dados.num/1)%10);


                j+=17;}
            if(i==17&&j==6){
                printf("(R)CORRIGIR");
                j+=11;}
            if(i==16&&j==6){
                printf("TECLE:");
                j+=6;}
            if(i==18&&j==6){
                printf("(C)CONFIRMAR");
                j+=12;}
//==============BOTOES BRANCO CORRIGE CONFRMA===========================
            if(i==17&&j==42){
                printf("BRNCO%cCRRGE%cCNFRMA",176,176);
                j+=18;
            }
            if(i==18&&j==42){
                printf("     %c     %c      ",176,176);
                j+=18;
            }
//==================BOTOES NUMERICOS====================================
            if(i==5&&j==44){
                printf(" 1  %c 2  %c 3  ",176,176);
                j+=14;}
            if(i==6&&j==44){
                printf("    %c    %c    ",176,176);
                j+=14;}

            if(i==8&&j==44){
                printf(" 4  %c 5  %c 6  ",176,176);
                j+=14;}
            if(i==9&&j==44){
                printf("    %c    %c    ",176,176);
                j+=14;}

            if(i==11&&j==44){
                printf(" 7  %c 8  %c 9  ",176,176);
                j+=14;}
            if(i==12&&j==44){
                printf("    %c    %c    ",176,176);
                j+=14;}

            if(i==14&&j==49){
                printf(" 0  ");
                j+=4;}
            if(i==15&&j==49){
                printf("    ");
                j+=4;}
//===================IMPRESAO DA URNA===========================

          if(i==15&&j>=5&&j<=35)
                printf("=");
          else if(i>=1&&i<=2&&j>=40&&j<=61)
                    printf("%c",177);
               else if(i>=2&&i<=18&&j>=5&&j<=35)
                        printf(" ");
                    else
                        if(i>=4&&i<=19&&j>=40&&j<=61)
                            printf("%c",176);
                        else
                            printf("%c",219);
//==============================================================
        }
    puts("");
    }


}
void gonvernador2(CAND dados){
    int i,j;
    system("cls");
    printf("\n\n");
    for(i=0;i<21;i++){
        printf("  ");
        for(j=0;j<65;j++){
 //==============IMPRESSAO DOS TEXTOS===================================
            if(i==1&&j==48){
                printf("JUSTI%cA",128);
                j+=7;}
            if(i==2&&j==47){
                printf("ELEITORAL");
                j+=9;}
            if(i==2&&j==6){
                printf("SEU VOTO PARA:");
                j+=14;}
            if(i==5&&j==15){
                printf("GONVERNADOR");
                j+=11;}

            if(i==9&&j==6){

                printf("Nome: %s",dados.nome);
                j+=6+ strlen(dados.nome);}
            if(i==11&&j==6){
                printf("Partido: %s",dados.sigla);
                j+=9+strlen(dados.sigla);}
            if(i==13&&j==6){
                printf("Vice: %s",dados.vice);
                j+=6+strlen(dados.vice);}
            if(i==7&&j==6){
                printf("N%cmero: [%d][%d]",233,dados.num/10,dados.num%10);
                j+=14;}
            if(i==17&&j==6){
                printf("(R)CORRIGIR");
                j+=11;}
            if(i==16&&j==6){
                printf("TECLE:");
                j+=6;}
            if(i==18&&j==6){
                printf("(C)CONFIRMAR");
                j+=12;}
//==============BOTOES BRANCO CORRIGE CONFRMA===========================
            if(i==17&&j==42){
                printf("BRNCO%cCRRGE%cCNFRMA",176,176);
                j+=18;
            }
            if(i==18&&j==42){
                printf("     %c     %c      ",176,176);
                j+=18;
            }
//==================BOTOES NUMERICOS====================================
            if(i==5&&j==44){
                printf(" 1  %c 2  %c 3  ",176,176);
                j+=14;}
            if(i==6&&j==44){
                printf("    %c    %c    ",176,176);
                j+=14;}

            if(i==8&&j==44){
                printf(" 4  %c 5  %c 6  ",176,176);
                j+=14;}
            if(i==9&&j==44){
                printf("    %c    %c    ",176,176);
                j+=14;}

            if(i==11&&j==44){
                printf(" 7  %c 8  %c 9  ",176,176);
                j+=14;}
            if(i==12&&j==44){
                printf("    %c    %c    ",176,176);
                j+=14;}

            if(i==14&&j==49){
                printf(" 0  ");
                j+=4;}
            if(i==15&&j==49){
                printf("    ");
                j+=4;}
//===================IMPRESAO DA URNA===========================

          if(i==15&&j>=5&&j<=35)
                printf("=");
          else if(i>=1&&i<=2&&j>=40&&j<=61)
                    printf("%c",177);
               else if(i>=2&&i<=18&&j>=5&&j<=35)
                        printf(" ");
                    else
                        if(i>=4&&i<=19&&j>=40&&j<=61)
                            printf("%c",176);
                        else
                            printf("%c",219);
//==============================================================
        }
    puts("");
    }


}
void presidente2(CAND dados){
    int i,j;
    system("cls");
    printf("\n\n");
    for(i=0;i<21;i++){
        printf("  ");
        for(j=0;j<65;j++){
 //==============IMPRESSAO DOS TEXTOS===================================
            if(i==1&&j==48){
                printf("JUSTI%cA",128);
                j+=7;}
            if(i==2&&j==47){
                printf("ELEITORAL");
                j+=9;}
            if(i==2&&j==6){
                printf("SEU VOTO PARA:");
                j+=14;}
            if(i==5&&j==15){
                printf("PRESIDENTE");
                j+=10;}

            if(i==9&&j==6){

                printf("Nome: %s",dados.nome);
                j+=6+ strlen(dados.nome);}
            if(i==11&&j==6){
                printf("Partido: %s",dados.sigla);
                j+=9+strlen(dados.sigla);}
            if(i==13&&j==6){
                printf("Vice: %s",dados.vice);
                j+=6+strlen(dados.vice);}
            if(i==7&&j==6){
                printf("N%cmero: [%d][%d]",233,dados.num/10,dados.num%10);
                j+=14;}
            if(i==17&&j==6){
                printf("(R)CORRIGIR");
                j+=11;}
            if(i==16&&j==6){
                printf("TECLE:");
                j+=6;}
            if(i==18&&j==6){
                printf("(C)CONFIRMAR");
                j+=12;}
//==============BOTOES BRANCO CORRIGE CONFRMA===========================
            if(i==17&&j==42){
                printf("BRNCO%cCRRGE%cCNFRMA",176,176);
                j+=18;
            }
            if(i==18&&j==42){
                printf("     %c     %c      ",176,176);
                j+=18;
            }
//==================BOTOES NUMERICOS====================================
            if(i==5&&j==44){
                printf(" 1  %c 2  %c 3  ",176,176);
                j+=14;}
            if(i==6&&j==44){
                printf("    %c    %c    ",176,176);
                j+=14;}

            if(i==8&&j==44){
                printf(" 4  %c 5  %c 6  ",176,176);
                j+=14;}
            if(i==9&&j==44){
                printf("    %c    %c    ",176,176);
                j+=14;}

            if(i==11&&j==44){
                printf(" 7  %c 8  %c 9  ",176,176);
                j+=14;}
            if(i==12&&j==44){
                printf("    %c    %c    ",176,176);
                j+=14;}

            if(i==14&&j==49){
                printf(" 0  ");
                j+=4;}
            if(i==15&&j==49){
                printf("    ");
                j+=4;}
//===================IMPRESAO DA URNA===========================

          if(i==15&&j>=5&&j<=35)
                printf("=");
          else if(i>=1&&i<=2&&j>=40&&j<=61)
                    printf("%c",177);
               else if(i>=2&&i<=18&&j>=5&&j<=35)
                        printf(" ");
                    else
                        if(i>=4&&i<=19&&j>=40&&j<=61)
                            printf("%c",176);
                        else
                            printf("%c",219);
//==============================================================
        }
    puts("");
    }


}


void telaInicial(char *cargo, char *colchetes,int posicaoString){

    int i,j;
    system("cls");
    printf("\n\n");
    for(i=0;i<21;i++){
        printf("  ");
        for(j=0;j<65;j++){
 //==============IMPRESSAO DOS TEXTOS===================================
            if(i==1&&j==48){
                printf("JUSTI%cA",128);
                j+=7;}
            if(i==2&&j==47){
                printf("ELEITORAL");
                j+=9;}
            if(i==2&&j==6){
                printf("SEU VOTO PARA:");
                j+=14;}
            if(i==5&&j==posicaoString){
                printf("%s",cargo);
                j+=strlen(cargo);}
            if(i==7&&j==6){
                printf("%s",colchetes);
                j+=strlen(colchetes);}
            if(i==17&&j==6){
                printf("(B)BRANCO");
                j+=9;}
            if(i==16&&j==6){
                printf("TECLE:");
                j+=6;}

//==============BOTOES BRANCO CORRIGE CONFRMA===========================
            if(i==17&&j==42){
                printf("BRNCO%cCRRGE%cCNFRMA",176,176);
                j+=18;
            }
            if(i==18&&j==42){
                printf("     %c     %c      ",176,176);
                j+=18;
            }
//==================BOTOES NUMERICOS====================================
            if(i==5&&j==44){
                printf(" 1  %c 2  %c 3  ",176,176);
                j+=14;}
            if(i==6&&j==44){
                printf("    %c    %c    ",176,176);
                j+=14;}

            if(i==8&&j==44){
                printf(" 4  %c 5  %c 6  ",176,176);
                j+=14;}
            if(i==9&&j==44){
                printf("    %c    %c    ",176,176);
                j+=14;}

            if(i==11&&j==44){
                printf(" 7  %c 8  %c 9  ",176,176);
                j+=14;}
            if(i==12&&j==44){
                printf("    %c    %c    ",176,176);
                j+=14;}

            if(i==14&&j==49){
                printf(" 0  ");
                j+=4;}
            if(i==15&&j==49){
                printf("    ");
                j+=4;}
//===================IMPRESAO DA URNA===========================

          if(i==15&&j>=5&&j<=35)
                printf("=");
          else if(i>=1&&i<=2&&j>=40&&j<=61)
                    printf("%c",177);
               else if(i>=2&&i<=18&&j>=5&&j<=35)
                        printf(" ");
                    else
                        if(i>=4&&i<=19&&j>=40&&j<=61)
                            printf("%c",176);
                        else
                            printf("%c",219);
//==============================================================
        }
    puts("");
    }

}
void fim(){

    int i,j;
    system("cls");
    printf("\n\n");
    for(i=0;i<21;i++){
        printf("  ");
        for(j=0;j<65;j++){
 //==============IMPRESSAO DOS TEXTOS===================================
            if(i==1&&j==48){
                printf("JUSTI%cA",128);
                j+=7;}
            if(i==2&&j==47){
                printf("ELEITORAL");
                j+=9;}

            if(i==9&&j==19){
                printf("FIM");
                j+=3;}

//==============BOTOES BRANCO CORRIGE CONFRMA===========================
            if(i==17&&j==42){
                printf("BRNCO%cCRRGE%cCNFRMA",176,176);
                j+=18;
            }
            if(i==18&&j==42){
                printf("     %c     %c      ",176,176);
                j+=18;
            }
//==================BOTOES NUMERICOS====================================
            if(i==5&&j==44){
                printf(" 1  %c 2  %c 3  ",176,176);
                j+=14;}
            if(i==6&&j==44){
                printf("    %c    %c    ",176,176);
                j+=14;}

            if(i==8&&j==44){
                printf(" 4  %c 5  %c 6  ",176,176);
                j+=14;}
            if(i==9&&j==44){
                printf("    %c    %c    ",176,176);
                j+=14;}

            if(i==11&&j==44){
                printf(" 7  %c 8  %c 9  ",176,176);
                j+=14;}
            if(i==12&&j==44){
                printf("    %c    %c    ",176,176);
                j+=14;}

            if(i==14&&j==49){
                printf(" 0  ");
                j+=4;}
            if(i==15&&j==49){
                printf("    ");
                j+=4;}
//===================IMPRESAO DA URNA===========================

            if(i>=1&&i<=2&&j>=40&&j<=61)
                    printf("%c",177);
               else if(i>=2&&i<=18&&j>=5&&j<=35)
                        printf(" ");
                    else
                        if(i>=4&&i<=19&&j>=40&&j<=61)
                            printf("%c",176);
                        else
                            printf("%c",219);
//==============================================================
        }
    puts("");
    }
}




