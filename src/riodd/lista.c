#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "lista.h"


struct no{
	struct Item dado;
	struct no *prox;
	struct no *ant;
};

Lista criar(int tamanho){
	Lista novo;
	novo=(Lista)malloc(sizeof(Lista));
	novo=0;
	return novo;
}

void inserir(Lista *cabeca,struct Item conteudo){
	
	Lista novo;
	novo=(Lista)malloc(sizeof(struct no));
	novo->prox=0;	
	novo->dado=conteudo;
	
	Lista aux=*cabeca;
	Lista anterior;
	if(aux==0){		
		*cabeca=novo;
		novo->ant=0;
	}else{
		
		while(aux->prox!=0){
			anterior=aux;
			aux=aux->prox;
		}
		aux->prox=novo;
		novo->ant=anterior;
	}
}
Lista Analisar(Lista *cabevento, Lista *cabsoli, char *s, char *c1,char *c2){
	
	Lista andarsoli=*cabsoli;	
	Lista andarevs=*cabevento;
	Lista ings=NULL;
	ings=criar(0);
	int i,t,u,b=0;
	char cod[150];
	char qnt[50];
	char bol1[150];
	char bol2[150];
	int valor=0;
	FILE *fbol,*fb1,*fb2;
	int soma=0;
	
	
	
	strcpy(bol1,s);
	strcpy(bol2,s);
	
	strcat(bol1,c1);
	fb1=fopen(bol1,"w");
	strcat(bol2,c2);
	fb2=fopen(bol2,"w");
	strcat(s,"boletos.bol");
	fbol=fopen(s,"w");
	int selecionar;
	struct valor *estrutura;
	estrutura=malloc(sizeof(struct valor));
	
	struct valor2 *estrutura2=NULL;
	estrutura2=malloc(sizeof(struct valor2));
	
	while(andarsoli!=0){									//ANALISAR DE TOODAS AS PESSOAS
		estrutura2=andarsoli->dado.apontadados;
		fprintf(fbol, "Data do vencimento: 21/08/15\nEventos solicitados:\n"); 
		soma=0;
		
		
		i=0;		
		while(strcmp(estrutura2->qntingre[i],"")!=0){			//ANALISAR TODOS DE TAL PESSOA TIPO ga05 9
			
			for(t=0;estrutura2->qntingre[i][t]!=':';t++){
				cod[t]=estrutura2->qntingre[i][t];					
			}
			
			cod[t]='\0';
			//printf("\nAcha cod %s de tamanho %zu",cod,strlen(cod));			
			
			t++;
			for(u=0;estrutura2->qntingre[i][t]!='\0';u++){
				qnt[u]=estrutura2->qntingre[i][t];
				t++;
			}
			
			qnt[u]='\0';
			
			valor=atoi(qnt);
			
			//printf("\n%s  %d",cod,valor);
			
			
			
			
			
			andarevs=*cabevento;
			estrutura=andarevs->dado.apontadados;	
				
			char auxs[50];
			
			while(andarevs->prox!=0 && strcmp(estrutura->cod,cod)!=0){
				
				//printf("\ncod: %s",estrutura->cod);
				//printf("\nAchar %zu",strlen(estrutura->cod));
				
				puts(auxs);
				//printf(" com tam de %zu",strlen(estrutura->cod));	
				andarevs=andarevs->prox;				
				estrutura=andarevs->dado.apontadados;				
			}
			
			if(strcmp(estrutura->cod,cod)!=0){
				//printf("\nNao encontrou");				
			}else{
				//printf("\nEncontrou");
				//rintf("\nACHOU"); 
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
				
				fprintf(fbol,"%d (%s)/%s %s\n",valor,estrutura->esporte,estrutura->local,estrutura->data);
						
			}	
			
			i++;		
		}	
		
		fprintf(fbol,"\nSacado:\n%s\n%s\n%s\nVALOR TOTAL: R$: %d,00\n",estrutura2->nome,estrutura2->cpf,estrutura2->endereco,soma);	
		fprintf(fbol, "\nATENCAO: caso este boleto não seja pago até a data de vencimento, poderá ser pago ate 05/09/15 com multa de 30%%\n");	
		fprintf(fbol, "-----------------------\n");
		andarsoli=andarsoli->prox;
		
		if(selecionar%2==0){
			fprintf(fb1,"%s\n",estrutura2->cpf);
		} else fprintf(fb2,"%s\n",estrutura2->cpf);
		selecionar++;
	}
	
	return ings;
	
	
}


void setarfinal(char *s){
	s[strlen(s)-2]= '\0';	
}

void printar(Lista *cabeca, char *s){
	int i=0;
	Lista aux=*cabeca;
	FILE *fingressos=0;
	fingressos=fopen(s,"w");
	
	
	struct valor3 *estrutura;
	estrutura=malloc(sizeof(struct valor3));

	while(aux!=0){
		estrutura=aux->dado.apontadados;
		fprintf(fingressos,"RIO 2016 %s\nLOCAL: %s\nDATA: %s\n\nCOMPRADOR: %s",estrutura->evento->esporte,estrutura->evento->local,estrutura->evento->data,estrutura->pessoa->nome);
		fprintf(fingressos,"  %s",estrutura->pessoa->cpf);	
		fprintf(fingressos,"\n\nNUMERO DE SERIE: %d",i);
		fprintf(fingressos,"\nEm caso de extravio, solicitar segunda via do ingresso até o dia anterior ao do");
		fprintf(fingressos," evento no site https://sou.azarado.cob.br/perdi/meu/ingresso");		
		fprintf(fingressos,"\nVALOR DO INGRESSO: R$: %s,00",estrutura->evento->preco);			
		fprintf(fingressos,"\n------------------------------------------\n\n");
					
		i++;
		aux=aux->prox;
	}			
}

void remover(Lista *cabeca,int i, int f){
	Lista andar=*cabeca;
	Lista andar2;
	int z;
	for(z=0;z<i-1 && andar!=0;z++){
		
		andar=andar->prox;
	}
	andar2=andar;
	while(z<=f && andar2!=0){		
		andar2=andar2->prox;
		z++;
	}
	
	if(i==0){
		*cabeca=andar2;
		andar2->ant=0;
		
	}else{
		andar->prox=andar2;
		andar2->ant=andar;
		
	}	
	
}







