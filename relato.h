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

int gVotosValidos[4];

int apurarrela(){

apurarVotosValidos();
relatoriosVotosCandidatos();
relatorioPartido();



return 0;
}
int apurarVotosValidos(){
    FILE *relatorio2;
    relatorio2=fopen("relatoriovotos.txt","w");
    if(relatorio2==NULL){
        puts("Erro ao abrir arquivoR");
    }

    char *estadual="apurarEstadual.txt";
    char *federal="apurarFederal.txt";
    char *senador="apurarSenador.txt";
    char *gonvernador="apurarGonvernador.txt";
    char *presidente="apurar.txt";

    printf("====================================\n");
    printf("     RELATORIO DE VOTOS VALIDOS\n");
    printf("====================================\n");

        fprintf(relatorio2,"====================================\n");
        fprintf(relatorio2,"     RELATORIO DE VOTOS VALIDOS\n");
        fprintf(relatorio2,"====================================\n");
    fclose(relatorio2);

    apurarVotos(estadual,"==========DEPUTADO ESTADUAL=========",0);
    apurarVotos(federal, "==========DEPUTADO FEDERAL==========",1);
    apurarVotos(senador, "===============SENADOR==============",2);
    apurarVotos(gonvernador,"=============GONVERNADOR============",3);
    apurarVotos(presidente,"==============PRESIDENTE============",4);

fclose(relatorio2);


return 0;
}
void apurarVotos(char *cargo, char *cargoCabecalho, int p){
    char c;
    char nuloBranco[10];
    int cont=0,totalVotos,branco,nulo;

    FILE *apurar,*relatorio2;
    relatorio2=fopen("relatoriovotos.txt","a");
    apurar=fopen(cargo,"r");
    if(apurar==NULL){
        puts("Erro ao abrir arquivo de apuração");
        exit(1);
    }
//============TOTAL DE VOTOS===============
    while(!feof(apurar)){
        fscanf(apurar,"%c",&c);
        if(c=='\n')
            cont++;
    }
    if(cont==0)
        totalVotos=cont;
    else
 	totalVotos=cont-1;
    fclose(apurar);
//===========VOTOS NULOS===================
    cont=0;

 apurar=fopen(cargo,"r");

    while(fscanf(apurar,"%s",nuloBranco) != EOF){

        if(strcmp(nuloBranco,"NULO")==0)
            cont++;
    }
    fclose(apurar);
    nulo=cont;
//==============VOTO BRANCO=====================
    cont=0;
  apurar=fopen(cargo,"r");

   while(fscanf(apurar,"%s",nuloBranco) != EOF){

	 if(strcmp(nuloBranco,"BRANCO")==0)
            cont++;
    }
    branco=cont;

    int valido=0;
    valido=(totalVotos-branco)-nulo;
    gVotosValidos[p]=valido;

    printf("\n%s\n",cargoCabecalho);
    printf("------------------------------------\n");
    printf("VOTOS           QUANT:         PORC.\n");
    printf("------------------------------------");
    printf("\nVALIDOS:           %3d        %5.1f%%\n",valido,(float)((valido*100)/totalVotos));
    printf("BRANCOS:           %3d        %5.1f%%\n",branco,(float)((branco*100)/totalVotos));
    printf("NULOS:             %3d        %5.1f%%\n",nulo,(float)((nulo*100)/totalVotos));
    printf("------------------------------------\n");
    printf("TOTAL:             %3d          %3.f%%\n",totalVotos,100.0);

        fprintf(relatorio2,"\n%s\n",cargoCabecalho);
        fprintf(relatorio2,"------------------------------------\n");
        fprintf(relatorio2,"VOTOS           QUANT:         PORC.\n");
        fprintf(relatorio2,"------------------------------------");
        fprintf(relatorio2,"\nVALIDOS:           %3d        %5.1f%%\n",valido,(float)((valido*100)/totalVotos));
        fprintf(relatorio2,"BRANCOS:           %3d        %5.1f%%\n",branco,(float)((branco*100)/totalVotos));
        fprintf(relatorio2,"NULOS:             %3d        %5.1f%%\n",nulo,(float)((nulo*100)/totalVotos));
        fprintf(relatorio2,"------------------------------------\n");
        fprintf(relatorio2,"TOTAL:             %3d          %3.f%%\n",totalVotos,100.0);

    fclose(relatorio2);

}
int relatoriosVotosCandidatos(){

//gambiarra pra limpar o relatorio anterior=======
    FILE *relatorio1;
    relatorio1=fopen("relatoriovotos.txt","a");


    printf("====================================\n\n");
    printf("\n====================================\n");
    printf("  RELATORIO DE VOTOS POR CANDIDATO\n");
    printf("====================================");
        fprintf(relatorio1,"====================================\n\n");
        fprintf(relatorio1,"\n====================================\n");
        fprintf(relatorio1,"  RELATORIO DE VOTOS POR CANDIDATO\n");
        fprintf(relatorio1,"====================================");

    fclose(relatorio1);

    char *nomeRelatorio1,*nomeRelatorio2,*nomeRelatorio3,*nomeRelatorio4;

    nomeRelatorio1="\n=========DEPUTADO  ESTADUAL=========";
    nomeRelatorio2="\n==========DEPUTADO FEDERAL==========";
    nomeRelatorio3="\n===============SENADOR==============";
    nomeRelatorio4="\n=============GONVERNADOR============";
//nome arquivo, cabe relatorio, tamanho em alg, indice variavel global votos validos


    relatorio("apurarEstadual.txt",nomeRelatorio1,9999,100000,0);
    relatorio("apurarFederal.txt",nomeRelatorio2,999,10000,1);
    relatorio("apurarSenador.txt",nomeRelatorio3,99,1000,2);
    relatorio("apurarGonvernador.txt",nomeRelatorio4,9,100,3);

    puts("");
    relatorioPresidente();



return 0;
}
void relatorio(char *arquivo,char *nomeRelatorio,int condnum,int condnum2, int p){
    CAND dados;//tipo de estrutura

    CAND apoio;//esse variavel concerta um bug da variavel dados
    //o bug que acontecia com dados acontece com apoio
    //entao dados fica livre para trabalhar

    int num,cont,k;
    char aux[5];

    int maior=0,eleito,v,guarda;

    int temp=1;

    FILE *cadastro,*apurar,*relatorio;

    cadastro=fopen("cadastro.txt","r");
    apurar=fopen(arquivo,"r");
    relatorio=fopen("relatoriovotos.txt","a");

    if(cadastro==NULL){
        puts("Erro ao abrir arquivo cadastro");
        exit(1);
    }
    if(apurar==NULL){
        puts("Erro ao abrir arquivo apurar");
        exit(1);
    }

    //imprime cabeçalho, os cargos sao passados por referencia,
    //essa mesma funcao serve pra varios cargos
    printf("\n%s\n",nomeRelatorio);
    printf("------------------------------------");
    printf("\nCANDIDATO:     NUMERO:  VOTOS: PORC.\n");
    printf("------------------------------------");
        //salva em arquivo
        fprintf(relatorio,"\n%s\n",nomeRelatorio);
        fprintf(relatorio,"------------------------------------");
        fprintf(relatorio,"\nCANDIDATO:     NUMERO:  VOTOS: PORC.\n");
        fprintf(relatorio,"------------------------------------");
    FILE *teste;
    teste=fopen("teste.txt","w");

    int maior2=0,eleito2=0;
    char nome[16];
    char nome2[16];

    while(!feof(cadastro)){
    cont=0;
        fread(&dados,sizeof(CAND),1,cadastro);
        apurar=fopen(arquivo,"r");
        apoio=dados;

            while(!feof(apurar)){

                fscanf(apurar,"%s",&aux);
                num=atoi(aux);

                if(dados.num==num){
                    cont++;
                }
            }
        fclose(apurar);

//aqui pega o maior contador e o numero a qual ele esta relacionado

        if(cont>maior){
            maior2=maior;
            maior=cont;
            eleito2=eleito;
            eleito=dados.num;


            for(v=0;v<strlen(dados.nome)+1;v++)
                nome2[v]=nome[v];

            for(v=0;v<strlen(dados.nome)+1;v++)
                nome[v]=dados.nome[v];

        }else if(cont>maior2){
                maior2=cont;
                eleito2=dados.num;
                for(v=0;v<strlen(dados.nome)+1;v++)
                    nome2[v]=dados.nome[v];

              }





//temp  eh pra nao imprimir o numero duas vezes,
//estava imprimindo o mesmo  candidato duas vezes
    if(dados.num!=temp){
//esses condnum determina o tamanho do numero assim sabe qul eh o cargo
            if(dados.num>condnum&&dados.num<condnum2){
                puts("");
                fprintf(relatorio,"\n");

// esse for eh apenas pra alinhar o relatorio
                for(k=0;k<36;k++){
                    if(k==0){
                       //imprime na tela e no arquivo
                        printf("%s-%s",dados.nome,dados.sigla);
                            fprintf(relatorio,"%s-%s",dados.nome,dados.sigla);


                        //isso eh o desconto do k questao de alinhamento
                        k+=1+strlen(dados.nome)+strlen(dados.sigla);
                    }else if(k==18){
                            printf("%5d ",dados.num);
                                fprintf(relatorio,"%5d ",dados.num);
                            k+=5;
                           }else if(k==25){
                                //aqui entra a quantidade de votos e porcentagem
                                  printf("%5d %5.1f%%",cont,(float)(cont*100)/gVotosValidos[p]);
                                    fprintf(relatorio,"%5d %5.1f%%",cont,(float)(cont*100)/gVotosValidos[p]);

                                  k+=11;
                                 }else{
                                    //imprime o espaço para alinhar o relatorio
                                    printf(" ");
                                        fprintf(relatorio," ");
                                 }
                }
            }

    }
    //alguns candidatos imprime duas vezes
    //pra concertar precisei criar uma variavel
    temp=dados.num;


    }


    if(maior==0&&maior2==0){



        printf("\nNiguem foi eleito");
    }else if(eleito>999&&maior2!=0){
            printf("\n\n=========CANDIDATOS ELEITOS=========\n");
                fprintf(relatorio,"\n\n=========CANDIDATOS ELEITOS=========\n");


            printf("\n%s COM %d VOTOS",nome, maior);
            printf("\n%s COM %d VOTOS",nome2, maior2);
                fprintf(relatorio,"\n%s COM %d VOTOS",nome, maior);
                fprintf(relatorio,"\n%s COM %d VOTOS",nome2, maior2);

         }else{

            printf("\n\n==========CANDIDATO ELEITO==========\n");
            fprintf(relatorio,"\n\n==========CANDIDATO ELEITO==========\n");

            printf("\n%s COM %d VOTOS",nome, maior);
                fprintf(relatorio,"\n%s COM %d VOTOS",nome, maior);
         }
        maior=0;

        fclose(relatorio);
}
void relatorioPresidente(){
    CAND dados;
    CAND apoio;
    int num,cont,k,v;
    char aux[5];
    int temp,eleito,maior=0;
    FILE *pcadastro,*apurar,*prelatorio;

    char nome[20];

    pcadastro=fopen("pcadastro.txt","r");
    apurar=fopen("apurar.txt","r");
    prelatorio=fopen("relatoriovotos.txt","a");

    if(pcadastro==NULL){
        puts("Erro ao abrir arquivo cadastro");
        exit(1);
    }
    if(apurar==NULL){
        puts("Erro ao abrir arquivo apurar");
        exit(1);
    }
    if(prelatorio==NULL){
        puts("Erro ao abrir relatorio");
        exit(1);
    }
    printf("\n\n=============PRESIDENTE=============\n");
    printf("------------------------------------");
    printf("\nCANDIDATO:     NUMERO:  VOTOS: PORC.\n");
    printf("------------------------------------");
        fprintf(prelatorio,"\n\n=============PRESIDENTE=============\n");
        fprintf(prelatorio,"------------------------------------");
        fprintf(prelatorio,"\nCANDIDATO:     NUMERO:  VOTOS: PORC.\n");
        fprintf(prelatorio,"------------------------------------");


    while(!feof(pcadastro)){
    cont=0;
        fread(&dados,sizeof(CAND),1,pcadastro);
        apurar=fopen("apurar.txt","r");
        if(apurar==NULL){
            puts("Erro");
            exit(1);

        }
        apoio=dados;
            while(fscanf(apurar,"%s",&aux)!=EOF){
                num=atoi(aux);
                if(dados.num==num){
                    cont++;
                }
            }
        fclose(apurar);

    if(cont>maior){
        maior=cont;
        eleito=dados.num;

        for(v=0;v<strlen(dados.nome)+1;v++)
            nome[v]=dados.nome[v];
    }

    if(dados.num!=temp){
            if(dados.num>9&&dados.num<100){
            puts("");
            fprintf(prelatorio,"\n");
            for(k=0;k<36;k++){
                if(k==0){
                    printf("%s-%s",dados.nome,dados.sigla);
                    fprintf(prelatorio,"%s-%s",dados.nome,dados.sigla);
                    k+=1+strlen(dados.nome)+strlen(dados.sigla);
                }else if(k==18){
                        printf("%5d",dados.num);

                        fprintf(prelatorio,"%5d",dados.num);
                        k+=6;
                       }else if(k==26){
                              printf("%5d %5.1f%%",cont,(float)(cont*100)/gVotosValidos[4]);
                                fprintf(prelatorio,"%5d %5.1f%%",cont,(float)(cont*100)/gVotosValidos[4]);
                              k+=11;
                             }else{
                             printf(" ");
                             fprintf(prelatorio," ");
                             }

            }
        }
    }
    temp=dados.num;
    }
    printf("\n\n==========CANDIDATO ELEITO==========\n");
        fprintf(prelatorio,"\n\n==========CANDIDATO ELEITO==========\n");

    printf("\n%s COM %d VOTOS\n",nome, maior);
        fprintf(prelatorio,"\n%s COM %d VOTOS\n",nome, maior);


        maior=0;
        eleito=0;

    printf("\n====================================");
    fprintf(prelatorio,"\n====================================");

    fclose(prelatorio);

}
int relatorioPartido(){
    char c;
    int cont=0,totalVotos,k;

    FILE *apurar,*cadastroPartidos,*relatorio;
    apurar=fopen("apPartido.txt","r");
    if(apurar==NULL){
        printf("erro");
        exit(1);
    }
    relatorio=fopen("relatoriovotos.txt","a");
    if(relatorio==NULL){
        printf("erro");
        exit(1);
    }
//============TOTAL DE VOTOS===============
    while(!feof(apurar)){
        fscanf(apurar,"%c",&c);
        if(c=='\n')
            cont++;
    }
    if(cont==0)
        totalVotos=cont;
    else
 	totalVotos=cont-1;

    fclose(apurar);
    char sigla[10],aux[10];

    cont=0;

    cadastroPartidos=fopen("partidoCadastrados.txt","r");
    if(cadastroPartidos==NULL){
        puts("erro no arquivo de cadastros dos partidos");
        exit(1);
    }

    printf("\n====================================\n");
    printf("   RELATORIO DE VOTOS POR PARTIDO\n");
    printf("====================================\n");
    printf("------------------------------------");
    printf("\nPARTIDO:         VOTOS:        PORC.");
    printf("\n------------------------------------");

        fprintf(relatorio,"\n====================================\n");
        fprintf(relatorio,"   RELATORIO DE VOTOS POR PARTIDO\n");
        fprintf(relatorio,"====================================\n");
        fprintf(relatorio,"------------------------------------");
        fprintf(relatorio,"\nPARTIDO:         VOTOS:        PORC.");
        fprintf(relatorio,"\n------------------------------------");

   while(fscanf(cadastroPartidos,"%s",sigla)!=EOF){

        apurar=fopen("apPartido.txt","r");
        if(apurar==NULL){
            printf("erro");
            exit(1);
        }

        while(fscanf(apurar,"%s",aux)!= EOF){

            if(strcmp(sigla,aux)==0){
                cont++;
            }

        }
        fclose(apurar);

        printf("\n");
        fprintf(relatorio,"\n");
        int i;
        for(i=0;i<36;i++){
            if(i==0){
                printf("%s",sigla);
                fprintf(relatorio,"%s",sigla);
                i+=strlen(sigla);
            }else if(i==18){
                  printf(" %4d",cont);
                  fprintf(relatorio,"%4d",cont);
                  i+=6;

            }else if(i==32){
                    printf(" %5.1f%%",(float)(cont*100)/totalVotos);
                    fprintf(relatorio,"%5.1f%%",(float)(cont*100)/totalVotos);
                  }else
                    printf(" ");
                    fprintf(relatorio," ");
        }

        cont=0;
    }
    printf("\n------------------------------------");
    printf("\nTOTAL:           %5d        100.0%%",totalVotos);
    printf("\n------------------------------------");
    printf("\n=============#ForaTemer=============\n");

            fprintf(relatorio,"\n------------------------------------");
            fprintf(relatorio,"\nTOTAL:           %5d        100.0%%",totalVotos);
            fprintf(relatorio,"\n------------------------------------");
            fprintf(relatorio,"\n=============#ForaTemer=============\n");

    fclose(relatorio);
return 0;
 }
