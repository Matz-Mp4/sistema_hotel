#include "HotelModel.h"

void listaMembers(int nA[], int nQ[], tipoHospede hosp[20][14]){
    
    quartoEscolha(nA, nQ);

    //Lista de dados de familiares
    if(hosp[nA[0]-1][nQ[0]-1].estado==-1){//Dados apenas dos quartos reservados, pois nao ha entrada de dados na reserva
        for(int i=0; i<hosp[nA[0]-1][nQ[0]-1].quant; i++){
            if(hosp[nA[0]-1][nQ[0]-1].members[i].estado==-1 || hosp[nA[0]-1][nQ[0]-1].members[i].estado==-2){
                printf("\n=--=--=--=--MEMBRO(%d)--=--=--=--=\n", i+1);
                printf("\tEndereco: %s", hosp[nA[0]-1][nQ[0]-1].members[i].endereco);
                printf("\tE-MAIL: %s", hosp[nA[0]-1][nQ[0]-1].members[i].email);
                printf("\tNOME: %s", hosp[nA[0]-1][nQ[0]-1].members[i].nome);
                printf("\tIDADE  : %d", hosp[nA[0]-1][nQ[0]-1].members[i].idade);
                printf("\n=--=--=--=--=--=--=--=--=--=--=--=\n\n");
            }
        }
    }else if(hosp[nA[0]-1][nQ[0]-1].estado==-2 || hosp[nA[0]-1][nQ[0]-1].estado==0)
        printf("O quarto se encontra vazio ou reservado  ");

}

void porcentagem(float pessoas, float tot1, float tot3, tipoHospede hosp[20][14]){
    float porcen, iteracao;//Iteracao=Hospedes e pessoas=membros familiares de cada hospede
    int i, j;
    iteracao=tot1+tot3;//tot1=quantas vezes passou pelo check-in e tot3=quantas vezes passou pela reserva 
    porcen= iteracao*100/280;
    
    puts("\n");
    printf("/======================PORCENTAGEM====================\\\n");
    printf("  A porcentagem de ocupacao de quartos esta em %.3f%%\n", porcen);
    printf("  Quartos livres: %.0f\n  Quartos reservados: %.0f\n  Quartos de ocupados: %.0f",  280-(tot1+tot3), tot3, tot1);  
    printf("\n  Quantidade de hospedes: %.0f", iteracao+pessoas);//HospedeS+familiar de cada hospede
    printf("\n\\=====================================================/\n");
}

void info(int nA[], int nQ[], tipoHospede hosp[20][14]){
    int posicao;
    char opcao;
    
    quartoEscolha(nA, nQ);

    printf("\n\n/==============INFORMACOES===============\\");
    printf("\n\tEndereco: %s", hosp[nA[0]-1][nQ[0]-1].endereco);
    printf("\tCPF: %s\n", hosp[nA[0]-1][nQ[0]-1].cpf);
    printf("\tE-MAIL: %s\n", hosp[nA[0]-1][nQ[0]-1].email);
    printf("\tNOME: %s", hosp[nA[0]-1][nQ[0]-1].nome);
    printf("\tTELEFONE: %s\n", hosp[nA[0]-1][nQ[0]-1].telefone);
    printf("\tIDADE: %d", hosp[nA[0]-1][nQ[0]-1].idade);
    printf("\n|-------LEGENDA------|");
    printf("\n| Desocupado:  <0>   |");
    printf("\n| Ocupado: !=  <0>   |");
    printf("\n|--------------------|");
    printf("\n\\=========================================/\n\n");

    printf("\nVoce gostaria de visualizar as informacoes de seus familiares ?");
    printf("\n<y> ou <n>: ");
    
    opcao=obterOpcao();


    if(opcao=='y'|| opcao=='Y'){
        printf("\nDigite a posicao do membro: ");
        scanf("%d", &posicao);
        printf("\n\n/============MEMBRO(%d)=============\\", posicao);
        printf("\n\tEndereco: %s", hosp[nA[0]-1][nQ[0]-1].members[posicao-1].endereco);
        printf("\tE-MAIL: %s", hosp[nA[0]-1][nQ[0]-1].members[posicao-1].email);
        printf("\n\tNOME: %s", hosp[nA[0]-1][nQ[0]-1].members[posicao-1].nome);
        printf("\n\tIDADE: %d", hosp[nA[0]-1][nQ[0]-1].members[posicao-1].idade);
        printf("\n\\====================================/\n\n");

    }
}

void map(tipoHospede hosp[20][14]){
    int j, i;
    //Busca pelos ocupados=-1 e pelos reservados=-2 dentro do array hosp[20][14]
    printf("\n<Andar>\tAp-1\tAp-2\tAp-3\tAp-4\tAp-5\tAp-6\tAp-7\tAp-8\tAp-9\tAp-10\tAp-11\tAp-12\tAp-13\tAp-14");
    for(i=0; i<20;  i++){
        printf("\n |%d|", i+1);
        for(j=0; j<14; j++){
            if( hosp[i][j].estado == -1){
                printf("\t| X |");//OCUPADO
            }else if(hosp[i][j].estado == -2){
                printf("\t| R |");//RESERVADO
            }else
                printf("\t ");
            }
    }           
                printf("\n|-------LEGENDA--------|");
                printf("\n|  Desocupado: \"  \"    |");
                printf("\n|  Ocupado:     | X |  |");
                printf("\n|  Reservado:   | R |  |");
                printf("\n|----------------------|");
}

void lista(tipoHospede hosp[20][14]){
    int i, j;
    printf("\n\n/===================LISTA===================\\");
    for (i=0; i<20; i++){
        for (j=0; j<14; j++){
            if (hosp[i][j].estado==-1){
                printf("\n    O quarto %d no andar %d esta ocupado!", i+1, j+1);
            }
            if(hosp[i][j].estado==-2){
                printf("\n    O quarto %d no andar %d esta reservado!", i+1, j+1);
            }
        }
    }
    printf("\n\\===========================================/\n\n");
}
void cleanBuffer(){
    char op;
    printf("\n\n................Digite <ENTER> para continuar...................");
    while( (op = fgetc(stdin)) != EOF && op != '\n') {}
    getchar( );
    system("clear");
}

void interfaceMenu() {
    
    printf("\n/============================================================\\\n");
    printf("\tDigite <1> para fazer o check-in\n\tDigite <2> para fazer o check-out \n");
    printf("\tDigite <3> para porcentagem de ocupacao \n\tDigite <4> para lista de quartos ocupados\n");
    printf("\tDigite <5> para saida!\n\tDigite <6> para informacoes de um quarto!\n");
    printf("\tDigite <7> para fazer uma reserva!\n\tDigite <8> para visualizar o mapa!\n");
    printf("\tDigite <9> para desfazer uma reserva!\n\tDigite <10> para lista de membros familiares!\n");
    printf("\n\\============================================================/\n");

}



