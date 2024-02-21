#include <stdio.h> //biblioteca de comunicaÃ§Ã£o com o usuÃ¡rio
#include <stdlib.h> //biblioteca de alocaÃ§Ã£o de espaÃ§o em memÃ³ria
#include <locale.h> //biblioteca de alocaÃ§Ãµes de texto por regiÃ£o
#include <string.h> //biblioteca responsÃ¡vel por cuidar das string
		
int registro()
{
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	printf("Digite o CPF a ser cadastrado: ");
	scanf("%s", cpf);
	
	strcpy(arquivo, cpf); //Responsavel por copiar os valores das string
	
	FILE *file; // cria o arquivo
	file = fopen(arquivo, "w"); // cria o arquivo
	fprintf(file,cpf); // salvo o valor da variavel
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s",nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);	
	
    system("pause");

}

int consulta()
{
	
	 setlocale(LC_ALL, "Portuguese");
	
	 char cpf [40];
	 char conteudo [200];
	
	 printf("Digite o CPF a ser consultado");
	 scanf("%s", cpf);
	
	   FILE *file;
	   file = fopen (cpf,"r");
	   
	   if(file == NULL)
	   {
	   	printf("não foi possivel abrir o arquivo, não localizado!.\n");
	   }
	   
	   while(fgets(conteudo, 200, file)!= NULL)
	   {
	   	printf("\nEssas são as informações do usuario: ");
		printf("%s", conteudo);
		printf("\n\n");
	   }
	   
	   system("pause");
	   	  
         
}

int deletar()
{
	printf("VocÃª escolheu deletar nomes!\n");
	system("pause");	
}


	
int main()
	{
	int opcao=0; //Definindo variÃ¡veis
	int laco=1;
	
	for(laco=1;laco=1;)
	{

		system("cls");

		setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
			
		printf("### CARTÓRIO DA EBAC ###\n\n"); //inicio do menu
		printf("Escolha a opção desejada no menu!\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n");
		printf("\t4 - Sair do sistema\n"); 
		printf("Opção: ");//fim do menu
				
		scanf("%d", &opcao); //armazenando a escolha do usuÃ¡rio
		
		system("cls");
	
		switch(opcao) //inicio da seleÃ§Ã£o
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
			printf("Obrigado por utilizar o sistema!\n");
			return 0;
			break;	
		
			default:
			printf("Essa opÃ§Ã£o nÃ£o estÃ¡ disponivel!\n");
			system("pause");
			break;
		} //fim da seleÃ§Ã£o
			
	}	
}
