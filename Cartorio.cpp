#include <stdio.h>  // Biblioteca de comunicação com o usuário
#include <stdlib.h> // Biblioteca de alocação de espaço de memória
#include <string.h> // Biblioteca responsável por cuidar das strings
#include <ctype.h>  // Biblioteca para funções de caracteres, como isdigit
#include <locale.h> //Biblioteca para acentualçao

// Função para validar o CPF
int validarCPF(char cpf[]) 
{
    if (strlen(cpf) != 11)  // Verifica se o CPF tem exatamente 11 caracteres
	{
        printf("Erro: O CPF deve ter exatamente 11 dígitos!\n");
        return 0;
    }
    
    // Verifica se todos os caracteres são números
    for (int i = 0; i < 11; i++) 
	{
        if (!isdigit(cpf[i]))  // Certifica-se de que cada caractere é numérico
		{ 
            printf("Erro: O CPF deve conter apenas números!\n");
            return 0;
        }
    }

    return 1; // CPF válido
}

int registro() // Função responsável para cadastrar os usuários no sistema
{ 
    char arquivo[40];
    char cpf[12];  // CPF com 11 números + '\0' (terminador nulo)
    char nome[40];
    char sobrenome[40];
    char cargo[40];

    // Loop até o CPF ser válido
    while (1) {
        printf("Digite o CPF a ser cadastrado: ");
        scanf("%s", cpf); // Lê o CPF como string

        if (validarCPF(cpf)) {
            break; // Sai do loop se o CPF for válido
        }
    }
    
    strcpy(arquivo, cpf); // Copia o CPF para o nome do arquivo
    
    FILE *file; // Cria o arquivo
    file = fopen(arquivo, "w"); // Cria o arquivo e escreve
    fprintf(file, "CPF: ");
    fprintf(file, cpf); // Salva o valor da variável CPF
    fprintf(file, "\n");
    fclose(file); // Fecha o arquivo
    
    printf("Digite o nome a ser cadastrado: ");
    scanf("%s", nome); // Lê o nome
    
    file = fopen(arquivo, "a"); // Abre o arquivo para adicionar mais informações
    fprintf(file, "Nome: ");
    fprintf(file, nome); // Salva o valor do nome
    fprintf(file, "\n");
    fclose(file); // Fecha o arquivo
    
    printf("Digite o sobrenome a ser cadastrado: ");
    scanf("%s", sobrenome); // Lê o sobrenome
    
    file = fopen(arquivo, "a"); // Abre o arquivo para adicionar mais informações
    fprintf(file, "Sobrenome: ");
    fprintf(file, sobrenome); // Salva o valor do sobrenome
    fprintf(file, "\n");
    fclose(file); // Fecha o arquivo
    
    printf("Digite o cargo a ser cadastrado: ");
    scanf("%s", cargo); // Lê o cargo
    
    file = fopen(arquivo, "a"); // Abre o arquivo para adicionar mais informações
    fprintf(file, "Cargo: ");
    fprintf(file, cargo); // Salva o valor do cargo
    fprintf(file, "\n");
    fclose(file); // Fecha o arquivo
    
    system("pause");
}

int consulta() // Função responsável para consultar os usuários no sistema
{ 
    char cpf[12];  // CPF com 11 números + '\0' (terminador nulo)
    char conteudo[200];
    
    printf("Digite o CPF a ser consultado: ");
    scanf("%s", cpf); // Lê o CPF como string
    
    FILE *file; // Cria o arquivo
    file = fopen(cpf, "r");
    
    if (file == NULL) 
	{
        printf("Esse CPF não foi localizado!\n");
        system("pause");
    } 
	else 
	{
        printf("\nEssas são as informações do usuário: \n\n");
        while (fgets(conteudo, 200, file) != NULL) 
		{
            printf("%s", conteudo); // Exibe as informações
        }
        system("pause");
    }
}

int deletar() // Função responsável para deletar os usuários no sistema
{ 
    char cpf[12];  // CPF com 11 números + '\0' (terminador nulo)
    
    printf("Digite o CPF a ser deletado: ");
    scanf("%s", cpf); // Lê o CPF como string
    
    remove(cpf); // Deleta o arquivo com o nome do CPF
    
    FILE *file;
    file = fopen(cpf, "r");
    
    if (file == NULL) 
	{
        printf("CPF do usuário deletado!\n");
        system("pause");
    }
}

int main() 
{
    int opcao = 0; // Definindo variáveis
    int x = 1;
    
    for (x = 1; x == 1;) 
	{
        system("cls");
        
        setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
    
        printf("#### Cartório da Ebac ####\n\n"); // Início do menu
        printf("Escolha a opção desejada do menu:\n\n");
        printf("\t1- Registrar nomes\n ");
        printf("\t2- Consultar nomes\n ");
        printf("\t3- Deletar nomes\n ");
        printf("\t4- Sair\n\n");
        printf("Opção: ");
        
        scanf("%d", &opcao); // Armazena a escolha do usuário
        
        system("cls");
        
        switch(opcao) 
		{
            case 1:
                registro();
                break;
            
            case 2:
                consulta();
                break;
            
            case 3:
                deletar();
                break;
            
            case 4:
                printf("Obrigado por utilizar nosso sistema!\n");
                return 0;
                break;    
            
            default:
                printf("Essa opção não está disponível!\n");
                system("pause");
                break;        
        }
    }   
}
