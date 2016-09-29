#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct lista{
	char nome[50];
}Lista;

int ordena(const void *a, const void *b);

int main(void)

{
    char ganhadoras[50];
    int numElementos = 0;
    Lista listaNomes[820];
	int i = 0;
    
    FILE *arquivo;
    FILE *arquivoOrdenado;
    FILE *listaGanhadoras;
    
    arquivo         = fopen("nomes","r");
    arquivoOrdenado = fopen("nomes_ordenados", "w+");
    listaGanhadoras = fopen("listaGanhadoras.html", "w+");
    
    if(arquivo == NULL || arquivoOrdenado == NULL || listaGanhadoras == NULL)
			printf("Erro, nao foi possivel abrir o arquivo\n");
	else{
		int d = 0;
	    while( (fgets(listaNomes[d].nome, sizeof(ganhadoras), arquivo))!=NULL ){
			numElementos++;
			d++;
	    }
	    numElementos--;
	    qsort(listaNomes, numElementos, sizeof(Lista), ordena);
	    
		fseek(arquivo, 0, SEEK_SET);
		
		
		printf("Numero de Elementos: %d\n", numElementos);
	    
		fprintf(listaGanhadoras, "<h1>Lista de Ganhadoras</h1>\n");
		fprintf(listaGanhadoras, "<ul>\n");
		
		int i =0;
		for(i=0;i<820;i++){
	    	if(listaNomes[i].nome[0] == 'R' || listaNomes[i].nome[0] == 'r'){
	    		fprintf(listaGanhadoras, " <li> %s </li> \n", listaNomes[i].nome);
	  		}
		}
	   
	    fprintf(listaGanhadoras, "\n</ul>");
	}
	fclose(arquivo);
	fclose(arquivoOrdenado);
	fclose(listaGanhadoras);
	
	return 0;
}

int ordena(const void *a, const void *b){
	Lista *x = (Lista *) a;
	Lista *y = (Lista *) b;
	
	return strcmp(x->nome, y->nome);
}