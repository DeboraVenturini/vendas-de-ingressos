#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

// Estrutura para armazenar os dados do ingresso
typedef struct {
    char nome[50];
    char cpf[15];
    int anoNascimento;
} Ingresso;

// Função para vender ingresso
void venderIngresso(Ingresso *ingressos, int *numIngressos) {
    Ingresso novoIngresso;
    
    printf("Nome: ");
    fflush(stdin);
    fgets(novoIngresso.nome, sizeof(novoIngresso.nome), stdin);
    novoIngresso.nome[strcspn(novoIngresso.nome, "\n")] = '\0'; // Remove o caractere de nova linha (\n)
    
    printf("CPF: ");
    fflush(stdin);
    fgets(novoIngresso.cpf, sizeof(novoIngresso.cpf), stdin);
    novoIngresso.cpf[strcspn(novoIngresso.cpf, "\n")] = '\0'; // Remove o caractere de nova linha (\n)
    
    printf("Ano de Nascimento: ");
    scanf("%d", &novoIngresso.anoNascimento);
    
    ingressos[*numIngressos] = novoIngresso;
    (*numIngressos)++;
    
    printf("Ingresso vendido com sucesso!\n");
    system("pause");
}

// Função para listar ingressos vendidos
void listarIngressos(Ingresso *ingressos, int numIngressos) {
    int i;
    
    for (i = 0; i < numIngressos; i++) {
        printf("===============================\n");
        printf("Nome: %s\n", ingressos[i].nome);
        printf("CPF: %s\n", ingressos[i].cpf);
        printf("Ano de Nascimento: %d\n", ingressos[i].anoNascimento);
    }
    
    if (numIngressos == 0) {
        printf("Nenhum ingresso vendido.\n");
    }
    
    printf("===============================\n");
    system("pause");
}

// Função para validar ingresso
void validarIngresso(Ingresso *ingressos, int numIngressos) {
    char cpf[15];
    int i;
    int ingressoEncontrado = 0;
    
    printf("Digite o CPF para validar o ingresso: ");
    fflush(stdin);
    fgets(cpf, sizeof(cpf), stdin);
    cpf[strcspn(cpf, "\n")] = '\0'; // Remove o caractere de nova linha (\n)
    
    for (i = 0; i < numIngressos; i++) {
        if (strcmp(ingressos[i].cpf, cpf) == 0) {
            printf("Ingresso válido. Aproveite o evento!\n");
            ingressoEncontrado = 1;
            break;
        }
    }
    
    if (!ingressoEncontrado) {
        printf("Ingresso inválido. CPF não encontrado.\n");
    }
    
    system("pause");
}

int main() {
    setlocale(LC_ALL, "Portuguese");
    
    Ingresso ingressos[100];
    int numIngressos = 0;
    char opcao;
    
    do {
        system("cls");
        printf("MENU\n");
        printf("----\n");
        printf("1) Vender ingresso\n");
        printf("2) Listar ingressos vendidos\n");
        printf("3) Validar ingresso\n");
        printf("4) Sair\n");
        printf("Escolha uma opção: ");
        fflush(stdin);
        scanf(" %c", &opcao);
        
        switch (opcao) {
            case '1':
                venderIngresso(ingressos, &numIngressos);
                break;
            case '2':
                listarIngressos(ingressos, numIngressos);
                break;
            case '3':
                validarIngresso(ingressos, numIngressos);
                break;
            case '4':
                printf("Saindo do programa...\n");
                break;
            default:
                printf("Opção inválida. Por favor, tente novamente.\n");
                system("pause");
                break;
        }
    } while (opcao != '4');
  
    return 0;
}
