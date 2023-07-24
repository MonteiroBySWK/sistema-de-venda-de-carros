#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int qtdCarros, qtdClientes, qtdVendas = 0;
int saldoCarros = 0;

struct fichaCarro {
    int codigoCarro;
    char modelo[20];
    char marca[10];
    char autoMan;
    int anoFab;
    char cor[7];
    float preco;
} carro[200];

struct fichaCliente {
    int codigoCliente;
    char nomeCliente[20];
    char sobrenomeCliente[20];
    int telefoneDDD;
    int telefoneID;
    int codigoCompra;
} cliente[200];

typedef struct fichaCarro  FCA;
typedef struct fichaCliente FCL;

struct fichaVenda {
    int codigoVenda;
    FCA carro;
    FCL cliente;
} venda[200];

void menu() {
    printf("------------------------------------------------\n");
    printf("Aluno: Gabriel Silva Monteiro\n");
    printf("Curso: Engenahria de Computaçao\n");
    printf("Disciplina: Algoritmos\n");
    printf("Beta V.001\n");
    printf("----------------------------------------------\n\n\n");

    printf("----------CONTROLE DE VENDAS DE CARRO-----------\n");
    printf("(1) - Inserir Carro\n");
    printf("(2) - Buscar Carro\n");
    printf("(3) - Exibir Cliente\n");
    printf("(4) - Vender Carro\n");
    printf("(5) - Exibir Estoque\n");
    printf("(6) - Consultar Venda\n");
    printf("(7) - Cadastar Cliente\n");
    printf("(8) - Sair\n");
    printf("Digite sua escolha: ");
}

void exibirFichaCarro(int* i) {
    printf("\n-----------------------------------------------\n");
    printf("Codigo do carro .......\t%d", carro[(*i)].codigoCarro);
    printf("\n-----------------------------------------------\n");
    printf("Marca .................\t%s \n", carro[(*i)].marca);
    printf("Modelo ................\t%s \n", carro[(*i)].modelo);
    printf("Automatico ............\t%c \n", carro[(*i)].autoMan);
    printf("Ano de fabricaçao .....\t%d \n", carro[(*i)].anoFab);
    printf("Cor ...................\t%s \n", carro[(*i)].cor);
    printf("Preço .................\t%.2f \n", carro[(*i)].preco);
    printf("------------------------------------------------\n");
}

void exibirFichaCliente(int* i) {
    printf("\n-----------------------------------------------\n");
    printf("Codigo do Cliente .....\t%d", cliente[(*i)].codigoCliente);
    printf("\n-----------------------------------------------\n");
    printf("Nome do Cliente .......\t%s %s \n", cliente[(*i)].nomeCliente, cliente[(*i)].sobrenomeCliente);
    printf("Telefone ..............\t(%d)%d \n", cliente[(*i)].telefoneDDD, cliente[(*i)].telefoneID);
    printf("------------------------------------------------\n");
}

void exibirFichaVenda(int* i) {
    printf("\n-----------------------------------------------\n");
    printf("Codigo de Venda .......\t%d\n", venda[(*i)].codigoVenda);
    printf("Codigo do Cliente .....\t%d", venda[(*i)].cliente.codigoCliente);
    printf("\n-----------------------------------------------\n");
    printf("Nome do Cliente .......\t%s %s \n", venda[(*i)].cliente.nomeCliente, venda[(*i)].cliente.sobrenomeCliente);
    printf("Telefone ..............\t(%d)%d \n", venda[(*i)].cliente.telefoneDDD, venda[(*i)].cliente.telefoneID);
    printf("Marca .................\t%s \n", venda[(*i)].carro.marca);
    printf("Modelo ................\t%s \n", venda[(*i)].carro.modelo);
    printf("Automatico ............\t%c \n", venda[(*i)].carro.autoMan);
    printf("Ano de fabricaçao .....\t%d \n", venda[(*i)].carro.anoFab);
    printf("Cor ...................\t%s \n", venda[(*i)].carro.cor);
    printf("Preço .................\t%.2f \n", venda[(*i)].carro.preco);
    printf("-----------------------------------------------\n\n");

}

void repetir(int* i) {
    (*i) = 1;
    printf("(1) - Repetir?\n");
    printf("(2) - Voltar\n");
    printf("Escolha: ");
    scanf("%d", &(*i));
    fflush(stdin);

    if ((*i) == 1) {
        printf("\n");
    } else {
        (*i) = 0;
    }
}

void anykey() {
    char anykey;
    printf("\nDigite qualquer tecla para voltar: ");
    fflush(stdin);
    scanf(" %c", &anykey);
    printf("\n");
}

int pesquisaCarro() {
    char marcaBusca[10];
    char modeloBusca[20];
    int resultados = 0;
    printf("Marca: ");
    fflush(stdin);
    scanf("%s", marcaBusca);
    printf("Modelo: ");
    fflush(stdin);
    scanf("%s", modeloBusca);
    printf("\n");
    for (int i = 0; i <= qtdCarros-1; i++) {
        if (strcmp(marcaBusca, carro[i].marca) == 0 || strcmp(modeloBusca, carro[i].modelo) == 0) {
            exibirFichaCarro(&i);
            resultados++;
        }
    }
    int crash;
    if (resultados == 0) {
        printf("Este Carro nao esta em estoque!\n\n");
        crash = 0;
    } else {
        printf("\n%d Resultados Encontrados\n\n", resultados);
        crash = 1;
    }
    return crash;
}

int pesquisaCliente() {
    char nomeBusca[20];
    char sobrenomeBusca[20];
    int resultados = 0;
    printf("Primeiro Nome: ");
    scanf("%s", nomeBusca);
    fflush(stdin);
    printf("Sobrenome : ");
    scanf("%s", sobrenomeBusca);
    fflush(stdin);
    for(int i = 0; i <= qtdClientes-1; i++) {
        if (strcmp(nomeBusca, cliente[i].nomeCliente) == 0 || strcmp(sobrenomeBusca, cliente[i].sobrenomeCliente) == 0) {
            exibirFichaCliente(&i);
            resultados++;
        }
    }
    int crash;
    if (resultados == 0) {
        printf("\nEste usuario nao esta cadastrado!\n\n");
        crash = 0;
    } else {
        printf("\n%d Resultados Encontrados\n\n", resultados);
        crash = 1;
    }
    return crash;
}

void registrarCarro() {
    int maisCarro;
    do {
        printf("---------------REGISTRO DE CARRO---------------\n\n");
        printf("Marca: ");
        scanf("%s",carro[qtdCarros].marca);
        fflush(stdin);
        
        printf("Modelo: ");
        scanf("%s", carro[qtdCarros].modelo);
        fflush(stdin);
        
        printf("Automatico (S/N): ");
        scanf(" %c", &carro[qtdCarros].autoMan);
        fflush(stdin);
        
        printf("Ano de fabricaçao: ");
        scanf("%d", &carro[qtdCarros].anoFab);
        fflush(stdin);

        printf("Cor: ");
        scanf("%s", carro[qtdCarros].cor);
        fflush(stdin);

        printf("Preço : ");
        scanf("%f", &carro[qtdCarros].preco);
        fflush(stdin);

        printf("\n");
        printf("Carro registrado!\n\n");

        carro[qtdCarros].codigoCarro = qtdCarros + 1;
        qtdCarros++;
        saldoCarros++;

        repetir(&maisCarro);
    } while (maisCarro);
}

void buscarCarro() {
    int maisBusca;
    do {
        printf("----------------BUSCA DE CARRO-----------------\n\n");
        if (qtdCarros == 0) {
            printf("Nao ha carros em estoque, registre carros!\n");
            anykey();
            break;
        } else {
        pesquisaCarro();
        repetir(&maisBusca);
        }
    } while (maisBusca);
}

void exibirCliente() {
    int maisBusca;
    do {
        printf("----------------BUSCA DE CLIENTE----------------\n");
        if (qtdClientes == 0) {
            printf("\nNao ha clientes cadastrados!\n");
            anykey();
            break;
        } else {
            pesquisaCliente();
            repetir(&maisBusca);
        }
    } while (maisBusca);
}

void vender() {
    int codigoCarro;
    int codigoCliente;
    int maisVenda;
    int crash = 1;
    do {
        printf("----------------VENDA DE CARRO-----------------\n\n");
        if (qtdClientes == 0) {
            printf("Nao ha clientes cadastrados!\n");
            anykey();
            break;
        } else if (qtdCarros == 0) {
            printf("Nao ha carros em estoque, registre carros!\n");
            anykey();
            break;
        } 

        printf("Pesquise o cliente: \n");
        crash = pesquisaCliente();

        if (crash == 0) {
            printf("Cadastre este cliente antes de efetuar a venda!\n\n");
            anykey();
            break;
        }

        int sair = 1;
        do {
            printf("Digite o codigo do cliente que ira comprar: ");
            scanf("%d", &codigoCliente);
            fflush(stdin);
            if (codigoCliente>qtdClientes || codigoCliente == 0) {
                printf("Codigo Invalido!\n\n");
                sair = 1;
            } else {
                sair = 0;
            }
        } while (sair);

        printf("Pesquise o carro desejado: \n");
        crash = pesquisaCarro();

        if (crash == 0) {
            anykey();
            break;
        }

        sair = 1;
        do {
            printf("Digite o codigo do carro que sera comprado: ");
            scanf("%d", &codigoCarro);
            fflush(stdin);
            if (codigoCarro>saldoCarros || codigoCarro == 0) {
                printf("Codigo Invalido!\n\n");
                sair = 1;
            } else {
                sair = 0;
            }
        } while (sair);

        int efetuar;
        printf("\n(1) - Efetuar a compra");
        printf("\n(2) - Cancelar compra\n");
        printf("Escolha: ");
        scanf("%d", &efetuar);

        if (efetuar == 1) {
            venda[qtdVendas].cliente = cliente[codigoCliente-1];
            venda[qtdVendas].carro = carro[codigoCarro-1];

            venda[qtdVendas].codigoVenda = qtdVendas + 1;
            qtdVendas++;
            
            printf("\nCompra Finalizada!\n\n");

            for (int i = codigoCarro; i <= qtdCarros; i++) {
                carro[i-1] = carro[i];
            }

            qtdCarros--;
        } else {
            printf("\nCompra cancelada!\n\n");
            anykey();
        }
        repetir(&maisVenda);
    } while (maisVenda);
    
}

void exibirEstoque() {
    printf("---------------ESTOQUE DE CARROS----------------\n");
    if (qtdCarros == 0) {
        printf("\nNao ha carros em estoque, registre carros!\n");
        anykey();
    } else {
        for(int i = 0; i <= qtdCarros-1; i++) {
            exibirFichaCarro(&i);
        }
        anykey();
    }
    
}

void exibirVenda() {
    printf("--------------REGISTRO DE VENDAS---------------\n\n");
    if (qtdVendas == 0) {
        printf("Nao ha vendas registradas!\n");
        anykey();
    } else {
        for(int i = 0; i <= qtdVendas-1; i++) {
            exibirFichaVenda(&i);
        }
        anykey();
    }
}

void registrarCliente() {
    printf("--------------REGISTRO DE CLIENTE--------------\n\n");
    int maisCliente;
    do {
        printf("Primeiro Nome: ");
        scanf("%s", cliente[qtdClientes].nomeCliente);
        fflush(stdin);
        printf("Sobrenome : ");
        scanf("%s", cliente[qtdClientes].sobrenomeCliente);
        fflush(stdin);
        printf("Numero para contato:\n");
        printf("\tDDD: ");
        scanf("%d", &cliente[qtdClientes].telefoneDDD);
        fflush(stdin);
        printf("\tNumero: ");
        scanf("%d", &cliente[qtdClientes].telefoneID);
        fflush(stdin);

        cliente[qtdClientes].codigoCliente = qtdClientes + 1;
        qtdClientes++;

        repetir(&maisCliente);

    } while (maisCliente);
}

int main() {
    int sair = 1;
    do {
        system("clear");   //Para Linux
        system("cls");     //Para Windows
        menu();
        int opcao;
        scanf("%d", &opcao);
        fflush(stdin);
        printf("\n");
        switch (opcao) {
            case 1:
                registrarCarro();
                break;
            case 2:
                buscarCarro();
                break;
            case 3:
                exibirCliente();
                break;
            case 4:
                vender();
                break;
            case 5:
                exibirEstoque();
                break;
            case 6:
                exibirVenda();
                break; 
            case 7:
                registrarCliente();
                break;
            case 8:
                sair = 0;
                break;
            default:
                printf("Esta opcao nao existe!\n");
                anykey();
                break;
        }
    } while (sair);
    return 1;
}