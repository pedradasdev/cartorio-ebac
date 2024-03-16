#include <stdio.h> //biblioteca de comunica√ß√£o com o usu√°rio
#include <stdlib.h> //biblioteca de aloca√ß√£o de espa√ßo em mem√≥ria
#include <locale.h> //biblioteca de aloca√ß√µes de texto por regi√£o
#include <string.h> //biblioteca respons√°vel por cuidar das string
		
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
	
	 printf("Digite o CPF a ser consultado: ");
	 scanf("%s", cpf);
	
	   FILE *file;
	   file = fopen (cpf,"r");
	   
	   if(file == NULL)
	   {
	   	printf("n„o foi possivel abrir o arquivo, n„o localizado!.\n");
	   }
	   
	   while(fgets(conteudo, 200, file)!= NULL)
	   {
	   	printf("\nEssas s„o as informaÁıes do usuario: ");
		printf("%s", conteudo);
		printf("\n\n");
	   }
	   
	   system("pause");
	   	  
    }

int deletar()
{
  char cpf[40];
  
  printf ("Digite o CPF do usuario a ser deletado: ");
  scanf("%s",cpf);
  
  remove (cpf);
  
  FILE*file;
  file = fopen(cpf,"r");
  
  if(file == NULL)
  {
     printf("O usuario n„o se encontra no sistema!./n");
     system("pause");
  }
    	
}


	
int main()
	{
	int opcao=0; //Definindo vari√°veis
	int laco=1;
	char senhadigitada[]="a";
	int comparacao;
	
	printf("### CARTORIO DA EBAC ###\n");
	printf("Login de administrador!\n\n DIGITE SUA SENHA:");
	scanf("%s", senhadigitada);
	
	comparacao = strcmp(senhadigitada, "admin");
	
	if(comparacao == 0)
	{
	
		
	    system ("cls");
     	for(laco=1;laco=1;)
 	    {

		    system("cls");

	    	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
			
	    	printf("### CART”RIO DA EBAC ###\n\n"); //inicio do menu
		    printf("Escolha a opÁ„o desejada no menu!\n\n");
	    	printf("\t1 - Registrar nomes\n");
		    printf("\t2 - Consultar nomes\n");
		    printf("\t3 - Deletar nomes\n");
		    printf("\t4 - Sair do sistema\n"); 
		    printf("OpÁ„o: ");//fim do menu
				
		    scanf("%d", &opcao); //armazenando a escolha do usu√°rio
		
		    system("cls");
	
     		switch(opcao) //inicio da sele√ß√£o
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
		    	printf("Essa opÁ„o n„o est· disponivÈl!\n");
		    	system("pause");
		    	break;
		    } //fim da sele√ß√£o
			
	    }	
    }
    else 
        printf("senha incorreta!");
}
