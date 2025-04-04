#include <stdio.h>  // Biblioteca de comunica��o com o usu�rio
#include <stdlib.h> // Biblioteca de aloca��o de espa�o de mem�ria
#include <string.h> // Biblioteca respons�vel por cuidar das strings
#include <ctype.h>  // Biblioteca para fun��es de caracteres, como isdigit
#include <locale.h> //Biblioteca para acentual�ao

// Fun��o para validar o CPF
int validarCPF(char cpf[]) 
{
    if (strlen(cpf) != 11)  // Verifica se o CPF tem exatamente 11 caracteres
	{
        printf("Erro: O CPF deve ter exatamente 11 d�gitos!\n");
        return 0;
    }
    
    // Verifica se todos os caracteres s�o n�meros
    for (int i = 0; i < 11; i++) 
	{
        if (!isdigit(cpf[i]))  // Certifica-se de que cada caractere � num�rico
		{ 
            printf("Erro: O CPF deve conter apenas n�meros!\n");
            return 0;
        }
    }

    return 1; // CPF v�lido
}

int registro() // Fun��o respons�vel para cadastrar os usu�rios no sistema
{ 
    char arquivo[40];
    char cpf[12];  // CPF com 11 n�meros + '\0' (terminador nulo)
    char nome[40];
    char sobrenome[40];
    char cargo[40];

    // Loop at� o CPF ser v�lido
    while (1) {
        printf("Digite o CPF a ser cadastrado: ");
        scanf("%s", cpf); // L� o CPF como string

        if (validarCPF(cpf)) {
            break; // Sai do loop se o CPF for v�lido
        }
    }
    
    strcpy(arquivo, cpf); // Copia o CPF para o nome do arquivo
    
    FILE *file; // Cria o arquivo
    file = fopen(arquivo, "w"); // Cria o arquivo e escreve
    fprintf(file, "CPF: ");
    fprintf(file, cpf); // Salva o valor da vari�vel CPF
    fprintf(file, "\n");
    fclose(file); // Fecha o arquivo
    
    printf("Digite o nome a ser cadastrado: ");
    scanf("%s", nome); // L� o nome
    
    file = fopen(arquivo, "a"); // Abre o arquivo para adicionar mais informa��es
    fprintf(file, "Nome: ");
    fprintf(file, nome); // Salva o valor do nome
    fprintf(file, "\n");
    fclose(file); // Fecha o arquivo
    
    printf("Digite o sobrenome a ser cadastrado: ");
    scanf("%s", sobrenome); // L� o sobrenome
    
    file = fopen(arquivo, "a"); // Abre o arquivo para adicionar mais informa��es
    fprintf(file, "Sobrenome: ");
    fprintf(file, sobrenome); // Salva o valor do sobrenome
    fprintf(file, "\n");
    fclose(file); // Fecha o arquivo
    
    printf("Digite o cargo a ser cadastrado: ");
    scanf("%s", cargo); // L� o cargo
    
    file = fopen(arquivo, "a"); // Abre o arquivo para adicionar mais informa��es
    fprintf(file, "Cargo: ");
    fprintf(file, cargo); // Salva o valor do cargo
    fprintf(file, "\n");
    fclose(file); // Fecha o arquivo
    
    system("pause");
}

int consulta() // Fun��o respons�vel para consultar os usu�rios no sistema
{ 
    char cpf[12];  // CPF com 11 n�meros + '\0' (terminador nulo)
    char conteudo[200];
    
    printf("Digite o CPF a ser consultado: ");
    scanf("%s", cpf); // L� o CPF como string
    
    FILE *file; // Cria o arquivo
    file = fopen(cpf, "r");
    
    if (file == NULL) 
	{
        printf("Esse CPF n�o foi localizado!\n");
        system("pause");
    } 
	else 
	{
        printf("\nEssas s�o as informa��es do usu�rio: \n\n");
        while (fgets(conteudo, 200, file) != NULL) 
		{
            printf("%s", conteudo); // Exibe as informa��es
        }
        system("pause");
    }
}

int deletar() // Fun��o respons�vel para deletar os usu�rios no sistema
{ 
    char cpf[12];  // CPF com 11 n�meros + '\0' (terminador nulo)
    
    printf("Digite o CPF a ser deletado: ");
    scanf("%s", cpf); // L� o CPF como string
    
    remove(cpf); // Deleta o arquivo com o nome do CPF
    
    FILE *file;
    file = fopen(cpf, "r");
    
    if (file == NULL) 
	{
        printf("CPF do usu�rio deletado!\n");
        system("pause");
    }
}

int main() 
{
    int opcao = 0; // Definindo vari�veis
    int x = 1;
    
    for (x = 1; x == 1;) 
	{
        system("cls");
        
        setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
    
        printf("#### Cart�rio da Ebac ####\n\n"); // In�cio do menu
        printf("Escolha a op��o desejada do menu:\n\n");
        printf("\t1- Registrar nomes\n ");
        printf("\t2- Consultar nomes\n ");
        printf("\t3- Deletar nomes\n ");
        printf("\t4- Sair\n\n");
        printf("Op��o: ");
        
        scanf("%d", &opcao); // Armazena a escolha do usu�rio
        
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
                printf("Essa op��o n�o est� dispon�vel!\n");
                system("pause");
                break;        
        }
    }   
}
