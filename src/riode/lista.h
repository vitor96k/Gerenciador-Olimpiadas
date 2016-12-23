#ifndef LISTA_H
#define LISTA_H

typedef struct no *Lista;


struct valor{
	char *cod;
	char *esporte;
	char *data;
	char *local;
	char *preco;	
};

struct valor2{
	char *nome;
	char *cpf;
	char *endereco;
	char qntingre[50000][15];
	int cont;	
};

struct valor3{
	struct valor *evento;
	struct valor2 *pessoa;
};

struct Item{
	void *apontadados;
};


Lista Analisar(Lista *cabevento, Lista *cabsoli, char *s, char *c1, char *c2);

Lista criar(int tamanho);
void setarfinal(char *s);

void liberar(Lista acabar);

void inserir(Lista *cabeca,struct Item conteudo);
void printar(Lista *cabeca,char *s);
void remover(Lista *cabeca,int i, int f);


#endif

