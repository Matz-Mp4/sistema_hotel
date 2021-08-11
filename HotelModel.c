#include "HotelModel.h"

void hospedagem(int nA[], int nQ[]){
    
    quartoEscolha(nA, nQ);

    while(nA[0]<=0 || nQ[0]<=0 || nQ[0]>=15 || nA[0]>=21){  //Proteção de dados, para delimitar o intervalo permito!
        printf("\n----------------------------------------------------------");
        printf("\n\tOPPSS!\n Voce dever ter digitado algo errado!\n");
        printf("Escolha um andar e um quarto(entre 20 andares e 14 quartos por andar)\n");
        printf("\nAndar: ");
        scanf("%d", &nA[0]);
        printf("Quarto: ");
        scanf("%d", &nQ[0]);
        printf("-----------------------------------------------------------\n"); 

    }   

}

void dados(int x[],int y[], tipoHospede hosp[20][14]){
    char op;

    printf("\n\t=--=--=--=--DADOS--=--=--=--=\n");//Entradas de dados 
    printf("\tInforme seu nome: ");
    while( (op = fgetc(stdin)) != EOF && op != '\n') {}
    fgets(hosp[x[0]-1][y[0]-1].nome,60,stdin);
    printf("\tInforme seu CPF: ");
    check_cpf(x,  y, hosp);
    printf("\t|Informe seu e-mail: ");
    scanf("%s", hosp[x[0]-1][y[0]-1].email);
    printf("\tInforme sua idade: ");
    scanf("%d", &hosp[x[0]-1][y[0]-1].idade);
    
    while((hosp[x[0]-1][y[0]-1].idade)<18){//Protecao contra menores de idade :D
        printf("\nALERTA: APENAS PESSOAS MAIORES DE 18 PODE FAZER CHECK-IN");
        printf("\nInforme sua idade: ");
        scanf("%d", &hosp[x[0]-1][y[0]-1].idade);
    }
    printf("\tInforme seu telefone: ");
    scanf("%s", hosp[x[0]-1][y[0]-1].telefone);
    printf("\tInforme seu Endereco: ");
    while( (op = fgetc(stdin)) != EOF && op != '\n') {}
    fgets(hosp[x[0]-1][y[0]-1].endereco,30,stdin);

}

void check_out(int nA[], int nQ[], tipoHospede hosp[20][14]){
    int quant;
    
    //LIMPANDO OS DADOS DO HOSPEDE
    printf("Digite quantidade de membros de familiares (ate 4 membros): ");
    scanf("%d", &quant);
    printf("Desfazendo chek-in.");
    hosp[nA[0]-1][nQ[0]-1].estado=0;
    strcpy(hosp[nA[0]-1][nQ[0]-1].nome,"0");
    strcpy(hosp[nA[0]-1][nQ[0]-1].cpf, "0");
    strcpy(hosp[nA[0]-1][nQ[0]-1].email, "0");
    strcpy(hosp[nA[0]-1][nQ[0]-1].telefone,"0");
    strcpy(hosp[nA[0]-1][nQ[0]-1].endereco, "0");
    hosp[nA[0]-1][nQ[0]-1].idade=0;
        
    //LIMPANDO OS DADOS DOS familiaRES
    for(int i=0; i<quant; i++){//familia
        strcpy(hosp[nA[0]-1][nQ[0]-1].members[i].nome,"0");
        strcpy(hosp[nA[0]-1][nQ[0]-1].members[i].email, "0");
        strcpy(hosp[nA[0]-1][nQ[0]-1].members[i].endereco, "0");
        hosp[nA[0]-1][nQ[0]-1].members[i].idade=0;
    }
}

void check_cpf(int x[], int y[], tipoHospede hosp[20][14]){
    int d[11];
    int k, Sentinela;
    int soma1, soma2, soma3;
    int d9, d10;
    float rest1, rest3;

    do{
    scanf("%s", hosp[x[0]-1][y[0]-1].cpf);

    for(k=0; k<11; k++){
        if(k < 9)
            d[k]=hosp[x[0]-1][y[0]-1].cpf[k]-48;
        else
            d[k]= hosp[x[0]-1][y[0]-1].cpf[k+1]-48;
    }

    soma1 = 10*d[0] + 9*d[1] + 8*d[2] + 7*d[3] + 6*d[4] + 5*d[5] + 4*d[6] + 3*d[7] + 2*d[8];
    rest1 = soma1%11;

    if (rest1 < 2) {
        d9 = 0;
    } 
    else {
        d9 = 11 - rest1;
    }

    soma2 = 11*d[0] + 10*d[1] + 9*d[2] + 8*d[3] + 7*d[4] + 6*d[5] + 5*d[6] + 4*d[7] + 3*d[8];
    soma3 = soma2 + 2*d9;
    rest3 = soma3 % 11;

    if (rest3<2) {
        d10 =0;
    } 
    else {
        d10 =11-rest3;
    }
    if ((d9 == d[9]) && (d10 == d[10])) {
        Sentinela=1;
    }
    else {
        Sentinela=0;
        printf("\nCPF INVALIDO DIGITE NOVAMENTE!!!!!\n");
        printf("\nInforme seu CPF: ");
    }

  } while(Sentinela==0);   
}

void familiares(int x[],int y[], tipoHospede hosp[20][14]){
    int opcao, quant,  posicao;
    char op,  alteraDados;
    

    do{
        printf("\n\n/==========================\\");
        printf(" \n(1)....Dados");
        printf(" \n(2)....Modificar os dados");
        printf(" \n(3)....Saida");
        printf("\n\\==========================/");
        printf("\nOpcao: ");
        scanf("%d", &opcao);

        switch(opcao){
            case 1:
                printf("Digite quantidade de membros de familiares (ate 4 membros): ");
                scanf("%d", &hosp[x[0]-1][y[0]-1].quant);

                for(int i=0; i<hosp[x[0]-1][y[0]-1].quant; i++){
                    hosp[x[0]-1][y[0]-1].members[i].estado=-1;//Colocando ocupado(-1) em cada hospede
                    printf("\n\t=--=--=--=--MEMBRO(%d)--=--=--=--=\n", i+1);
                    printf("\tInforme o nome: ");
                    while( (op = fgetc(stdin)) != EOF && op != '\n') {}
                    fgets(hosp[x[0]-1][y[0]-1].members[i].nome,60,stdin);
                    printf("\t|Informe o e-mail: ");
                    fgets(hosp[x[0]-1][y[0]-1].members[i].email,30,stdin);
                    printf("\tInforme a idade: ");
                    scanf("%d", &hosp[x[0]-1][y[0]-1].members[i].idade);
                    printf("\tInforme seu Endereco: ");
                    while( (op = fgetc(stdin)) != EOF && op != '\n') {}
                    fgets(hosp[x[0]-1][y[0]-1].members[i].endereco,30,stdin);
                    printf("\t=--=--=--=--=--=--=--=--=--=--=\n");
                }
            break;

            case 2:
                printf("\n\tQual dado voce dejesa alterar ?");
                printf("\n\t/==========================\\");
                printf(" \n\t(N)....Nome");
                printf(" \n\t(A)....Endereco");
                printf(" \n\t(I)....Idade");
                printf(" \n\t(E)....E-mail");
                printf("\n\t\\==========================/");
                printf("\nOpcao: ");
                alteraDados=obterOpcao();
                printf("\n\tInforme a posicao da pessoa: ");
                scanf("%d", &posicao);
                
                //Caso queira alterar alguma informação de um membro da familia
                switch(alteraDados){
                    case 'N':
                        printf("\tInforme o nome: ");
                        while( (op = fgetc(stdin)) != EOF && op != '\n') {}
                        fgets(hosp[x[0]-1][y[0]-1].members[posicao-1].nome,60,stdin);
                    break;

                    case 'A':
                        printf("\tInforme o Endereco: ");
                        while( (op = fgetc(stdin)) != EOF && op != '\n') {}
                        fgets(hosp[x[0]-1][y[0]-1].members[posicao-1].endereco,30,stdin);
                    break;

                    case 'I':
                        printf("\tInforme a idade: ");
                        scanf("%d", &hosp[x[0]-1][y[0]-1].members[posicao-1].idade);
                    break;

                    case 'E':
                        printf("\tInforme o e-mail: ");
                        fgets(hosp[x[0]-1][y[0]-1].members[posicao-1].email,30,stdin);
                    break;

                    default:
                        printf("\nOppss!Voce deve ter digitado algo errado!!!");
                }

            break;

            default:
                printf("\nOppss!Voce deve ter digitado algo errado!!!");
        }
    }while(opcao!=3);
}

void Reserva(int nA[], int nQ[], tipoHospede hosp[20][14]){
    //ALOCANDO RESERVA PARA O HOSPEDE
    char op;

    if(hosp[nA[0]-1][nQ[0]-1].estado==-1){
        printf("O quarto ja esta ocupado.");
    }else if(hosp[nA[0]-1][nQ[0]-1].estado==-2){
         printf("O quarto ja esta reservado.");
    }else{
        printf("O quarto %d no andar %d foi reservado!!!.\n", nQ[0], nA[0]);
        hosp[nA[0]-1][nQ[0]-1].estado=-2;
    }

    
}

void Inicializacao(tipoHospede hosp[20][14]) {
    for(int i=0; i<20; i++)
        for(int j = 0;j <14; j++){
            hosp[i][j].estado=0;//Colando estado em 0 em todos os hospedes para retirar lixo de memoria!!
            hosp[i][j].quant=0;
        }
}

void quartoEscolha(int nA[], int nQ[]) {
    printf("Escolha um andar e um quarto(entre 20 andares e 14 quartos por andar)\n");//Entradas
    printf("\nAndar: ");
    scanf("%d", &nA[0]);
    printf("Quarto: ");
    scanf("%d", &nQ[0]);
}

int opcaoMenu(int opcao){
    printf("\n\n\tInsira o numero: ");
    scanf("%d", &opcao);

    return opcao;

}

char obterOpcao() {
	char opcao;
    
	opcao = getchar();
	flush_in();
	return opcao;
}

void flush_in(){
    int ch;
    while( (ch = fgetc(stdin)) != EOF && ch != '\n' ){}
}

