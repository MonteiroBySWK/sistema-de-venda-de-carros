#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int qtdCliente = 0;

struct fichaCliente {
  char nome[20];
  int cpf;
  int senha;
} cliente[200];

void registrarCliente() {
  printf("--- REGISTRO DE CLIENTE ---\n");
  printf("Digite seu nome: ");
  scanf("%s", cliente[qtdCliente].nome);
  printf("Digite seu CPF (Apenas números)");
  scanf("%d", &cliente[qtdCliente].cpf);
  system("cls")
  printf("Escolha uma senha de 6 digitos: ");
  scanf("%d", &cliente[qtdCliente].senha);
  system("cls");
  do {
    printf("Confirme a senha: ")
    int senhaConf;
    int sair;
    scanf("%d", &senhaConf);
    if (senhaConf == cliente[qtdCliente].senha) {
      printf("Senha confirmada\n");
      sair = 1;
    } else {
      printf("Senha inválida! Tente novamente!\n");
      sair = 0;
    }
  } while (sair);
  printf("\nCadastro finalizado!\n");
  QtdCliente ++;

void depositar() {
  
}

void saque() {

}

void verSaldo() {
  
}

int main () {
  int sair;
  do {
    int opcao;
    switch (opcao) {
      case 1:
          registrarCliente();
          break;
      case 2:
          depositar();
          break;
      case 3:
          saque();
          break;
      case 4:
          verSaldo();
          break;
      default:
          printf("Esta opção não existe!");
          break;
    }
  } while (sair)
  return 0;
}
