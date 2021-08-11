#ifndef HOTELVIEW_H_
#define HOTELVIEW_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct familiares{
    char email[20],  nome[60], endereco[30]; 
    int estado, idade;
} familia;

typedef struct hospede{
    char cpf[13], email[20], telefone[15], nome[60], endereco[30]; 
    int estado, idade, quant;
    familia members[4];//estado do quarto onde  <-1> representa ocupado e <-2> representa reservado
} tipoHospede; // criando um novo tipo 

void cleanBuffer();
void familiares(int x[],int y[], tipoHospede hosp[20][14]);
void Reserva(int nA[], int nQ[], tipoHospede hosp[20][14]);
void check_out(int nA[], int nQ[], tipoHospede hosp[20][14]);
void dados(int x[],int y[], tipoHospede hosp[20][14]);
void hospedagem(int nA[], int nQ[]);
void check_cpf(int x[], int y[], tipoHospede hosp[20][14]);
void Inicializacao(tipoHospede hosp[20][14]);
void quartoEscolha(int nA[], int nQ[]);
int opcaoMenu(int opcao);
char obterOpcao();
void flush_in();




#endif









