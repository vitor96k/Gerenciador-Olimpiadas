#include "lista.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <math.h>




int main(int argc, char *argv[]){	
	
	setlocale(LC_ALL, "Portuguese");	
	int i=1;
	

	FILE *fevento=NULL;
	FILE *fingressos=NULL;
	FILE *fcarta=NULL;
	char *dirEvento=NULL;	//DIRETORIO DO TXT EVENTOS;
	char *salvar=NULL;		//DIRETORIO ONDE SALVAR OS BOLETOS
	char afz[150];
	char *boleto1=NULL;		//NOME DO ARQUIVO DO BOLETO1
	char *boleto2=NULL;		//NOME DO ARQUIVO DO BOLETO2
	char *ingressos=NULL;   //DIRETORIO DO TXT DA SOLICITACAO DE INGRESSOS
	char *arq;
	char jogo;
	int i1,i2,f1,f2,cont=0;
	char andar[500];
	char s[50000][15];	
	char *resultado;
	char s1[100],s2[100],s3[100],s4[100],s5[100],s6[100];
	int aux=0;	
	int z;
	char salvar2[1000];		//BOLETO2
	char salvar3[1000];		//CARTA
	char salvar4[1000];		//INGRESSO
	char salvar5[1000];		//BOLETOS
	int tamanho2;
	int tamanho=0;
	
	
	
	if(argc==1){
		printf("\nNennhum Comando inserido !");	
		return 0;	
		
	}
	
	while(i<argc){			
		
		if(strcmp("-e",argv[i])==0){					
		 	//PEGAR DIRETORIO DO EVENTOS
			i++; 
			dirEvento = (char *)malloc((strlen(argv[i])+1)*sizeof(char));		
			strcpy(dirEvento,argv[i]);							//SALVOU O NOME DO DIRETORIO			
		}else{
			if(strcmp("-si",argv[i])==0){
				// PEGAR DIRETORIO DA SOLICITACAO DE INGRESSOS 
				i++;
				ingressos = (char *)malloc((strlen(argv[i])+1)*sizeof(char));			
				strcpy(ingressos,argv[i]);
			}else{
				if(strcmp("-b1",argv[i])==0){					
		 			//PEGAR O NOME DO ARQUIVO Q SERA SALVO BOLETO1
					i++; //PEGAR O DIRETORIO;
					boleto1 = (char *)malloc((strlen(argv[i])+1)*sizeof(char));		
					strcpy(boleto1,argv[i]);													
				}else{
					if(strcmp("-b2",argv[i])==0){					
		 				//PEGAR O NOME DO ARQUIVO Q SERA SALVO BOLETO2
						i++; 
						boleto2 = (char *)malloc((strlen(argv[i])+1)*sizeof(char));		
						strcpy(boleto2,argv[i]);
						strcpy(afz,argv[i]);									
					}else{
						if(strcmp("-o",argv[i])==0){					
		 					//PEGAR O DIRETORIO ONDE SERAO SALVO OS BOLETOS 
							i++; 
							salvar = (char *)malloc((strlen(argv[i])+2)*sizeof(char));									
							strcpy(salvar,argv[i]);	
							salvar[strlen(salvar)]='/';						
																		
						}else{
							if(strcmp("-rsi",argv[i])==0){					
		 					//REMOVER SOLIITACAO INGRESSO
							i++; 							
							i1=atoi(argv[i]);						
							i++;
							f1=atoi(argv[i]);														
																				
						}else{
							if(strcmp("-rig",argv[i])==0){					
		 					//REMOVER INGRESSOS
		 					i++; 							
							i2=atoi(argv[i]);						
							i++;
							f2=atoi(argv[i]);		
																				
							}
						}
							
						}
					}					
				}				
			}			
		}		
		i++;		
	}
	
	//strcpy(salvar2,salvar);
	strcpy(salvar3,salvar);
	strcpy(salvar4,salvar);	
//	strcpy(salvar5,salvar);
	

	
	// CODIGO ABAIXO: LER EVENTOS, E ARMAZENAR NA LISTA //	
		
	fevento=fopen(dirEvento,"r");
	if(fevento==0){
		printf("\nDIRETORIO EVENTOS INVALIDO");		
		return 0;
	}
	tamanho=0;
	for(resultado=fgets(andar,100,fevento);resultado!=0;resultado=fgets(andar,100,fevento)){
		if(resultado[0]=='=' || resultado[0]=='#'){
			tamanho++;					
		}	
	}
	
	Lista evento;

	evento=criar(tamanho);	
	
	fevento=fopen(dirEvento,"r");
	
	if(fevento==0){//
		printf("\nDIRETORIO EVENTOS INVALIDO");		
		return 0;
	}
	

	for(resultado=fgets(andar,100,fevento);resultado!=0;resultado=fgets(andar,100,fevento)){
		if(resultado[0]=='=' || resultado[0]=='#'){	
		
			struct valor *bruto;	
			bruto=malloc(sizeof(struct valor));	
				
			bruto->cod=(char *)malloc((strlen(s1)+1)*sizeof(char));
			bruto->esporte=(char *)malloc((strlen(s2)+1)*sizeof(char));
			bruto->local=(char *)malloc((strlen(s3)+1)*sizeof(char));
			bruto->data=(char *)malloc((strlen(s4)+1)*sizeof(char));
			bruto->preco=(char *)malloc((strlen(s5)+1)*sizeof(char));
			
			strcpy(bruto->cod,s1);
			strcpy(bruto->esporte,s2);
			strcpy(bruto->local,s3);
			strcpy(bruto->data,s4);
			strcpy(bruto->preco,s5);
			
			
			struct Item inserido;
			inserido.apontadados=bruto;
			
			inserir(&evento,inserido);				
								
		}else{	
				
			strcpy(s1,resultado);
			setarfinal(s1);			
			
			resultado=fgets(andar,100,fevento);
			strcpy(s2,resultado);
			setarfinal(s2);				
			
			resultado=fgets(andar,100,fevento);
			strcpy(s3,resultado);
			setarfinal(s3);	
			
			resultado=fgets(andar,100,fevento);
			strcpy(s4,resultado);
			setarfinal(s4);			
			
			resultado=fgets(andar,100,fevento);
			strcpy(s5,resultado);	
			setarfinal(s5);		
		}		
	}
	
//	fclose(fevento);
	
	//CODIGO ABAIXO LER SOLICITACOES E ARMAZENAR NA LISTA
	
	
	strcat(salvar3,"CARTA.ei");								
	fcarta=fopen(salvar3,"w");	
	
	
	fingressos=NULL;
	fingressos=fopen(ingressos,"r");
	
	if(fingressos==NULL){
		printf("\nDIRETORIO SOLICITACAO DE INGRESSO INVALIDO");	
		return 0;
	}
//	printar(&evento);
	
	
	resultado=fgets(andar,500,fingressos);		// PEGANDO O TAMANHO;
	setarfinal(resultado);	
	
	Lista soli;
	soli=criar(atoi(resultado));
	
	for(resultado=fgets(andar,1000,fingressos);resultado!=0;resultado=fgets(andar,100,fingressos)){
		if(resultado[0]=='=' || resultado[0]=='#'){			
		
						
		}else{					
			strcpy(s1,resultado);			// NOME
			setarfinal(s1);
						
			resultado=fgets(andar,100,fingressos);			
			strcpy(s2,resultado);			//CPF
			setarfinal(s2);
			
			resultado=fgets(andar,100,fingressos);			
			strcpy(s3,resultado);			//ENDERECO
			setarfinal(s3);
			
			resultado=fgets(andar,100,fingressos);
			//CONVITES:
			cont=0;
			
			while(resultado[0]!='='&& resultado[0]!='#'){				
				strcpy(s[cont],resultado);
				setarfinal(s[cont]);											
				resultado=fgets(andar,100,fingressos);				
				cont++;
			}			
			
			//DECIDIR QM RECEBE O INGRESSO... 1/3 NAO RECEBE
			if(aux%3!=0){
				struct valor2 *bruto=NULL;	
				bruto=malloc(sizeof(struct valor2));	
				
				bruto->cont=cont;
				bruto->nome=(char *)malloc((strlen(s1)+1)*sizeof(char));
				bruto->cpf=(char *)malloc((strlen(s2)+1)*sizeof(char));	
				bruto->endereco=(char *)malloc((strlen(s3)+1)*sizeof(char));
			
				strcpy(bruto->nome,s1);
				strcpy(bruto->cpf,s2);
				strcpy(bruto->endereco,s3);	
				
				
				for(z=0;z<cont;z++){
					strcpy(bruto->qntingre[z],s[z]);														
				}	
			
				struct Item inserido;
				inserido.apontadados=bruto;	
				
				inserir(&soli,inserido);			
			}else{	
			
								
				fprintf(fcarta,"%s\n%s\n\nCom pesar informamos que não será possível fornecer-lhe o(s) ingresso(s) solicitado(s). Desejamos-lhe melhor sorte na próxima Olimpíada e bom divertimento ao assistir os jogos pela televisão.\n\n",s1,s3);
				fprintf(fcarta,"Atenciosamente, \n\nComitê Olímpico Local\n");
				fprintf(fcarta,"\n----------------------------------------------------------------\n\n");
				strcpy(salvar3,salvar);
										
			}
			aux++;											
		}		
	}
	
	remover(&soli,i1,f1);
	
	Lista ingres;	
	ingres=Analisar(&evento,&soli,salvar,boleto1,boleto2);
	
	remover(&ingres,i2,f2);
	
	printar(&ingres,salvar4);
	
	
	liberar(evento);
	liberar(soli);
	liberar(ingres);
	
	
	free(evento);
	free(soli);
	free(ingres);
	
	evento=NULL;
	soli=NULL;
	ingres=NULL;
	
	
	
	return 1;
	
	
	
	
	

	
	
	
	
		

	
	

	

	
	
	
}

	
	
	

	
	



