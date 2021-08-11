#include "HotelController.h"
#include <stdbool.h>

void HotelController() {
    int i , j;
    tipoHospede Hosp[20][14];

    Inicializacao(Hosp);

    int escolha, menu;
    char op, opcao;
    bool rep=true; //Serve para indicar a saída do programa
    int nA[1], nQ[1]; //nA = Andar nQ = Quartos
    float porcen, iteracao,tot1=0, tot3=0, pessoas=0;//tot1=quantas vezes ele passou pelo check-in, tot3=quantas vezes ele passou pela reserva.

    //menu   
    while(rep==true){
       

       interfaceMenu();
       menu=opcaoMenu(escolha);
    //switch para separar as opçoes do menu
        switch(menu){

            case 1: //checkin
                hospedagem(nA, nQ);
    
                if(Hosp[nA[0]-1][nQ[0]-1].estado==-1 || Hosp[nA[0]-1][nQ[0]-1].estado==-2){
                    printf("O quarto ja esta ocupado ou reservado!");
                }else{
                    printf("O quarto %d no andar %d foi alocado!!!.\n", nQ[0], nA[0]);
                    Hosp[nA[0]-1][nQ[0]-1].estado=-1;
                    dados(nA,nQ, Hosp);
                    tot1++;

                    printf("\nVoce gostaria de visualizar as informacoes de seus familiares ?");
                    printf("\n<y> ou <n>: ");
                    opcao=obterOpcao();

                    if(opcao=='y' || opcao=='Y'){
                        system("cls");
                        familiares(nA, nQ, Hosp);
                        pessoas=Hosp[nA[0]-1][nQ[0]-1].quant+pessoas;
                    }
                }
                cleanBuffer();
              break;

            case 2: //checkout    
                hospedagem(nA, nQ);
    
                if(Hosp[nA[0]-1][nQ[0]-1].estado==-1){
                    check_out(nA, nQ, Hosp);
                    pessoas=pessoas-Hosp[nA[0]-1][nQ[0]-1].quant;//Retirando familiares do total  
                    tot1--;
                    Hosp[nA[0]-1][nQ[0]-1].quant=0;//Atualizando dados da quant. de familiares neste quarto
                }else{
                    printf("\nO quarto digitado nao se encontra ocupado");
                }
                cleanBuffer();
            break;

            case 3: //porcentagem ocupado
                porcentagem(pessoas, tot1,tot3, Hosp);
                cleanBuffer();
            break;

            case 4: //lista de apartamentos OCUPADOS
                lista(Hosp);
                cleanBuffer();
              break;

            case 5:
                rep=false; //Saida
              break;
            
            case 6://info de quartos
                info(nA, nQ, Hosp);
                cleanBuffer();
              break;

            case 7://reserva
                hospedagem(nA, nQ);
                if(Hosp[nA[0]-1][nQ[0]-1].estado==-1){
                    printf("O quarto ja esta ocupado.");
                }else if(Hosp[nA[0]-1][nQ[0]-1].estado==-2){
                    printf("O quarto ja esta reservado.");
                }else{
                    Reserva(nA, nQ, Hosp);
                    tot3++;

                    printf("\nVoce gostaria de visualizar as informacoes de seus familiares ?");
                    printf("\n<y> ou <n>: ");
                    opcao=obterOpcao();

                    if(opcao=='y' || opcao=='Y') {
                        printf("\nDigite a quantidade de familiares: ");
                        scanf("%d", &Hosp[nA[0]-1][nQ[0]-1].quant);
                        //ALOCANDO RESERVA PARA OS familiaRES
                        for(int i=0; i<Hosp[nA[i]-1][nQ[i]-1].quant; i++) {
                            Hosp[nA[i]-1][nQ[i]-1].members[i].estado=-2;
                        }
                        pessoas=pessoas+Hosp[nA[0]-1][nQ[0]-1].quant;//Quantidades de familiares alocadas na variavek pessoa 
                    }
                }
               cleanBuffer();
            break;

            case 8:
                map(Hosp);
                cleanBuffer();
                system("cls");
            break;

            case 9://Retirando a reserva
                hospedagem(nA, nQ);

                //RETIRANDO RESERVA SOMENTE PARA QUARTOS LIVRES 
                if(Hosp[nA[0]-1][nQ[0]-1].estado==-2){
                    Hosp[nA[0]-1][nQ[0]-1].estado=0;
                    for(int i=0; i<Hosp[nA[0]-1][nQ[0]-1].quant; i++){
                        Hosp[nA[0]-1][nQ[0]-1].members[i].estado=0;//
                    }
                    printf("O quarto %d no andar %d não esta mais reservado!!!.\n", nQ[0], nA[0]);
                    pessoas=+pessoas-Hosp[nA[0]-1][nQ[0]-1].quant;
                    tot3--;
                    Hosp[nA[0]-1][nQ[0]-1].quant=0;//Atualizando dados da quant. de familiares neste quarto
                }else{
                    printf("O quarto %d no andar %d esta ocupado ou não esta reservado!!!.\n", nQ[0], nA[0]);
                }
                cleanBuffer();
            break;

            case 10:
                listaMembers(nA, nQ, Hosp);
                cleanBuffer();
            break;

           default:
                printf("\n\tOPPSS! Voce deve ter digitado algo errado!\n");
        }
    }
}