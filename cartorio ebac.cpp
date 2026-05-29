#include <stdio.h> //biblioteca comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória com o usuário
#include <locale.h> //biblioteca de alocações de texto por região 
#include <string.h> //biblioteca string

int registro()//Função responsavel por cadastrasr os usuários no sistema
{
	 //inicio criação de variáveis/string
	 char arquivo[40];
     char cpf[40];
     char nome[60];
     char sobrenome[40];
     char cargo[40];
     //Final da criação de variáveis/string
     
    printf("Digite o cpf a ser cadastrado:");//coletando informação do usuário 
    scanf("%s", cpf);//%s refere-se as strings
    
    strcpy(arquivo, cpf); //responsavel por criar valor das string
    
    FILE *file; // cria o arquivo
    file = fopen(arquivo, "w"); //cria o arquivo e o w significa escrever
    fprintf (file,cpf); // salvo o valor da variavel
    fclose(file); // fecho o arquivo
    
    file = fopen(arquivo, "a");//cria o arquivo
    fprintf (file, ",");//cria o valor da variavel
    fclose(file);//fecha o arquivo
    
    printf("Diegite o nome a ser cadastrado:");//coletando informação do usuário
    scanf("%s",nome);//%s refere-se as strings
    
    file = fopen(arquivo, "a");//cria o arquivo
    fprintf(file,nome);//salva o valor da variavel
    fclose(file);//fecha o arquivo
    
    file = fopen(arquivo, "a");//cria o arquivo
    fprintf(file, ",");//cria o valor da variavel
    fclose(file);//fecha o arquivo
    
    printf("Digite o sobrenome a ser cadastrado:");//coletando informação do usuário
    scanf("%s", sobrenome);//%s refere-se as strings
    
    file = fopen(arquivo,  "a");//cria o arquivo
    fprintf(file, sobrenome);//cria o valor da variavel
    fclose(file);//fecha o arquivo
    
    file = fopen(arquivo, "a");//cria o arquivo
    fprintf (file, ",");//cria o valor da variavel
    fclose(file);//fecha o arquivo
    
    printf("Digite o cargo a ser cadastrado:");//coletando informação do usuário
    scanf("%s",cargo);//%s refere-se as strings
    
    file = fopen(arquivo,"a" );//cria o arquivo
    fprintf(file, cargo);//cria o valor da variavel
    fclose(file);//fecha o arquivo
    
    system("pause");//



}

int consulta()
{
	setlocale(LC_ALL, "Portuguese");
	
    char cpf[40];
    char conteudo[200];
    
    printf("Digite o cpf a ser consultado:");
    scanf("%s",cpf);
    
    FILE *file;
    file = fopen(cpf,"r");
    
    if(file == NULL)
    {
    	printf("Não foi possivel abrir o arquivo, não localizado!.\n");
	}
	
        while(fgets(conteudo, 200, file) != NULL)
    {
       printf("\nEssas são as informações do usuário: ");
       printf("%s", conteudo);
       printf("\n\n");
       
    }
	
    system("pause");
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF do usuário a ser deletado:");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file== NULL)
{
	
	printf("O usuário não se encontra no sistema!.\n");
	system("pause");
			}
	
	
	
}
int sair()
{
	printf("Saindo do sistema...\n");
	system("pause");
} 
    
int main()
{
    int opcao = 0;//definindo variaveis
    int laco = 1;

    for(laco = 1; laco == 1;)
    {
    system("cls");//responsavel por limpar
    
    setlocale(LC_ALL, "Portuguese");//definindo linguagem
    
    printf("## Cartorio da EBAC ##\n\n");
    printf("Escolha a opcao desejada do menu abaixo\n");
    printf("\t1 - Registrar nomes\n");
    printf("\t2 - Consultar nomes\n");
    printf("\t3 - Deletar nomes\n");
    printf("\t4 - Sair\n\n");
    printf("Opcao: ");

    scanf("%d", &opcao);//armazenando a escolha do usuário 

    system("cls");//responsavel por limpar a tela
        
    switch(opcao)//inicio da seleção do menu
    {
    case 1:
    registro();//chamada de funções
    printf("\nEsse software foi feito por Thiago Henrique Campos de Souza Giuliani\n\n");
    system("pause");
    system("cls");
    break;
            
    case 2:
    consulta();//chamada de funções
    printf("\nEsse software foi feito por Thiago Henrique Campos de Souza Giuliani\n\n");
    system("pause");
    system("cls");
    break;
            
    case 3:
    deletar();//chamada de funções
    printf("\nEsse software foi feito por Thiago Henrique Campos de Souza Giuliani\n\n");
    system("pause");
    system("cls");
    break;
    
    case 4:
    sair();
    printf("\nEsse software foi feito por Thiago Henrique Campos de Souza Giuliani\n\n");
    laco = 0;
    system("pause");
    system("cls");
    break;
    
    default:
    printf("Essa opcao esta indisponivel!\n");
    printf("\nEsse software foi feito por Thiago Henrique Campos de Souza Giuliani\n\n");
    system("pause");
    system("cls");
    break;

    }
    }

    return 0;
    }
