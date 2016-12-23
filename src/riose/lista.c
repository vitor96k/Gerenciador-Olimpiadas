#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "lista.h"

struct elemento{
	struct Item dado;
	int prox;
};

struct no{
	int livre;
	struct elemento **nozinho;
	int inicio;
	int max;
};



Lista criar(int tamanho){
	Lista novo;
	novo=(Lista)malloc(sizeof(Lista));
	novo->inicio=-1;
	novo->livre=0;
	novo->max=tamanho;
	novo->nozinho=(struct elemento **)malloc(tamanho*sizeof(struct elemento));
	return novo;
}

void inserir(Lista *cabeca,struct Item conteudo){
	
	struct elemento *novo;
	novo=(struct elemento *)malloc(sizeof(struct elemento));

	novo->dado=conteudo;

	Lista cab=*cabeca;
	
	if(cab->livre<cab->max){
		
		if(cab->inicio==-1){		//INSERE NO COMECO				
			cab->nozinho[0]=novo;
			cab->nozinho[0]->prox=-1;
			cab->inicio=0;
										
		}else{			
			cab->nozinho[cab->livre]=novo;
			cab->nozinho[cab->livre]->prox=-1;	
			cab->nozinho[(cab->livre)-1]->prox=cab->livre;			
		}
		
		cab->livre=(cab->livre)+1;		
	}else{
		printf("\nLista Cheia");
		//system("PAUSE");
		
	}
}

void liberar(Lista acabar){
	int i;
	
	i=acabar->inicio;
	while(i!=-1){ 
		free(acabar->nozinho[i]);		
		i = acabar->nozinho[i]->prox;  
	}	

	
}

void printar(Lista *cabeca, char *s){
	int i;
	Lista aux=*cabeca;
	FILE *fingressos;
	strcat(s,"Ingressos.ing");
	fingressos=fopen(s,"w");
	
	struct valor3 *estrutura;
	estrutura=malloc(sizeof(struct valor3));
	
	
	

	i=aux->inicio;
	while(i!=-1){ 		
		estrutura=aux->nozinho[i]->dado.apontadados;		
		fprintf(fingressos,"RIO 2016 %s\nLOCAL: %s\nDATA: %s\n\nCOMPRADOR: %s",estrutura->evento->esporte,estrutura->evento->local,estrutura->evento->data,estrutura->pessoa->nome);
		fprintf(fingressos,"  %s",estrutura->pessoa->cpf);	
		fprintf(fingressos,"\n\nNUMERO DE SERIE: %d",i);
		fprintf(fingressos,"\nEm caso de extravio, solicitar segunda via do ingresso até o dia anterior ao do");
		fprintf(fingressos," evento no site https://sou.azarado.cob.br/perdi/meu/ingresso");		
		fprintf(fingressos,"\nVALOR DO INGRESSO: R$: %s,00",estrutura->evento->preco);			
		fprintf(fingressos,"\n------------------------------------------\n\n");
			
		
		i = aux->nozinho[i]->prox;  
	}	
}

void remover(Lista *cabeca,int i, int f){
	
	Lista cab=*cabeca;
	
	if(i>=0 && f<cab->max && i<=f){		
		if(i==0){
			cab->inicio=cab->nozinho[f]->prox;				
		}else{			
			cab->nozinho[i-1]->prox=cab->nozinho[f]->prox;						
		}	
	} else{		
		printf("\nERRO\ni < f ou f nao existe ou i negativo !!");		
	}
}

Lista Analisar(Lista *cabevento, Lista *cabsoli, char *s, char *c1, char *c2){

	
	Lista andarsoli=*cabsoli;	
	Lista andarevs=*cabevento;
	FILE *fbol,*fb1,*fb2;
	
	int certo=0;

	int i,t,u,b,mega;
	char cod[150];
	char qnt[50];
	char bol1[150];
	char bol2[150];
	int valor;
	int selecionar=0;

	int soma;
	int t2=0;
	
	
	strcpy(bol1,s);
	strcpy(bol2,s);
	strcat(bol1,c1);
	fb1=fopen(bol1,"w");
	strcat(bol2,c2);
	fb2=fopen(bol2,"w");
	strcat(s,"boletos.bol");
	fbol=fopen(s,"w");

	

	struct valor *estrutura;
	estrutura=malloc(sizeof(struct valor));
	
	struct valor2 *estrutura2;
	estrutura2=malloc(sizeof(struct valor2));
	
	int k=andarsoli->inicio;
	
	//PERCORRER LISTA DE SOLITICAO PARA SABER O TAMANHO DA LISTA DE INGRESSOS !
	
	////////////////////////////////////////////////////
	
	k=andarsoli->inicio;
	t=0;
	while(k!=-1){												
		estrutura2=andarsoli->nozinho[k]->dado.apontadados;		
		soma=0;		
		i=0;	
		
		while(strcmp(estrutura2->qntingre[i],"")!=0){			
			
			for(t=0;estrutura2->qntingre[i][t]!=':';t++){
				cod[t]=estrutura2->qntingre[i][t];					
			}
			
			cod[t]='\0';			
			
			t++;
			for(u=0;estrutura2->qntingre[i][t]!='\0';u++){
				qnt[u]=estrutura2->qntingre[i][t];
				t++;
			}
			
			qnt[u]='\0';
			valor=atoi(qnt);	
			
		
			andarevs=*cabevento;
			mega=andarevs->inicio;
			estrutura=andarevs->nozinho[mega]->dado.apontadados;			
			while(mega!=-1 && strcmp(estrutura->cod,cod)!=0){
				estrutura=andarevs->nozinho[mega]->dado.apontadados;				
				mega = andarevs->nozinho[mega]->prox; 	
						
			}		
						
			if(strcmp(estrutura->cod,cod)==0){
				t2=t2+valor;			
			}
				
						
			i++;		
		}
		k=andarsoli->nozinho[k]->prox;	
		
	}
	
	//printf("\nLista de tamanho %d",t2);
	Lista ings=criar(t2);
	
	///////////////////////////////////////////////////
	


	k=andarsoli->inicio;
	t=0;
	while(k!=-1){												//ANALISAR DE TOODAS AS PESSOAS
		estrutura2=andarsoli->nozinho[k]->dado.apontadados;
		
		fprintf(fbol, "Data do vencimento: 21/08/15\nEventos solicitados:\n"); 
		soma=0;		
		i=0;
		
		
		while(strcmp(estrutura2->qntingre[i],"")!=0){			//ANALISAR TODOS DE TAL PESSOA TIPO ga05 9
			
			for(t=0;estrutura2->qntingre[i][t]!=':';t++){
				cod[t]=estrutura2->qntingre[i][t];					
			}
			
			cod[t]='\0';			
			
			t++;
			for(u=0;estrutura2->qntingre[i][t]!='\0';u++){
				qnt[u]=estrutura2->qntingre[i][t];
				t++;
			}
			
			qnt[u]='\0';
			valor=atoi(qnt);	
			
		
			andarevs=*cabevento;
			mega=andarevs->inicio;
			estrutura=andarevs->nozinho[mega]->dado.apontadados;			
			while(mega!=-1 && strcmp(estrutura->cod,cod)!=0){
				estrutura=andarevs->nozinho[mega]->dado.apontadados;				
				mega = andarevs->nozinho[mega]->prox; 	
						
			}		
		
						
			if(strcmp(estrutura->cod,cod)!=0){
			//	printf("\nNao encontrou");				
			}else{
			//	printf("\nEncontrou");
				for(b=0;b<valor;b++){				
					struct valor3 *bruto;
					bruto=malloc(sizeof(struct valor3));
					bruto->evento=estrutura;
					bruto->pessoa=estrutura2;
					soma=soma+atoi((estrutura->preco));
					
				
					struct Item inserido;
					inserido.apontadados=bruto;	
								
					inserir(&ings,inserido);
					
				}
				fprintf(fbol,"%d (%s) %s / %s %s\n",valor,estrutura->cod,estrutura->esporte,estrutura->local,estrutura->data);
						
			}	
			
			i++;		
		}
		
		fprintf(fbol,"\nSacado:\n%s\n%s\n%s\nVALOR TOTAL: R$: %d,00\n",estrutura2->nome,estrutura2->cpf,estrutura2->endereco,soma);	
		fprintf(fbol, "\nATENÇÃO: caso este boleto não seja pago até a data de vencimento, poderá ser pago até 05/09/15 com multa de 30%%\n");	
		fprintf(fbol, "-----------------------\n");
		
		
		if(selecionar%2==0){
			fprintf(fb1,"%s\n",estrutura2->cpf);
		} else fprintf(fb2,"%s\n",estrutura2->cpf);
		
		selecionar++;
		
	
	
		k=andarsoli->nozinho[k]->prox;	
		
	}
	
	
	return ings;

}






void setarfinal(char *s){
	s[strlen(s)-2]= '\0';	
}








