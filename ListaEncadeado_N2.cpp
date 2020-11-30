#include <stdio.h>
#include <stdlib.h>		  // exit; malloc; system
#include <string.h>	  	  // strcmp
#include <time.h>
#include <locale.h>       // setlocale

#define True 1


typedef struct {          // registro para uma pessoa
       int  codigo;
       char nome[30];
} INFORMACAO;
       
typedef struct LISTA {
       INFORMACAO info;   // dados do registro
       struct LISTA* prox; // ponteiro para o pr�ximo registro
}NODO; 


//DECLARA��O DAS FUN��ES
void    entrada_dados  ( NODO *aux ); // leitura dos dados de entrada
void    imprime_lista  ( NODO *aux ); // visualiza��o da lista em tela
void    cria_lista     ( NODO* *l );  // inicializa lista com NULL
void    inclui_fim     ( NODO* *l );  // inclui um novo registro no final da lista
void    inclui_inicio  ( NODO* *l );  // inclui um novo registro no inicio da lista
NODO*   procura_nodo   ( NODO* l, int cod ); // procura na lista por um c�digo
void    exclui_nodo    ( NODO* *l );  // exclui um regitro por c�digo 
void    ordena_lista   ( NODO* *l );  // ordena lista por c�digo
void    consulta_nome  ( NODO* l );   // consulta por um nome


//In�cio do programa Principal
int main( void )
{
    int op;          // op��o do menu                               
    NODO* l;         // declara��o da lista - ponteiro
    setlocale(LC_ALL, "Portuguese");	// alterar idioma para portugu�s
    
    cria_lista( &l );	// rotina cria lista  
    while( True ){
         printf( "\n /----------------------------------------------------/" );  // menu
         printf( "\n Programa de cadastro - Menu                           " );
         printf( "\n [1 ]  Inclui registro no final da lista               " );
         printf( "\n [2 ]  Inclui registro no in�cio da lista              " );
         printf( "\n [3 ]  Exclui registro                                 " );
         printf( "\n [4 ]  Ordena lista                                    " );
         printf( "\n [5 ]  Consulta nome                                   " );         
         printf( "\n [6 ]  Imprime lista                                   " );  
         printf( "\n [0 ]  Para sair do programa                           " );
         printf( "\n /----------------------------------------------------/" );      
         printf( "\n Op��o: " );
         fflush( stdin );
         scanf("%d", &op); // tecla de op��o do menu
         

         switch( op ) {
            case 1: // rotina inclui registro no final da lista    
                    inclui_fim( &l ); 
                    break;
                                
            case 2: // rotina inclui registro no in�cio da lista
                    inclui_inicio( &l );
                    break;
          
            case 3: // rotina exclui registro da lista
                    exclui_nodo( &l );
                    break;
                
            case 4: // rotina exclui registro da lista
        			ordena_lista( &l );
                    break;
                  
            case 5: // rotina ordena lista
              		consulta_nome( l ); 
                    break;

            case 6: // rotina imprime lista  
              		imprime_lista( l ); 
                    break;
                                                                                                           
            case 0: // t�rmino do programa                                                 
                    exit( True ); 
                    break;
                
            default : 
                    printf( "\n Digite uma opcao!" ); // n�o foi digitado uma op��o v�lida
                    break;
         } 
 
        printf( "\n\n" );
        system( "pause" ); // pausar programa
        system( "cls" ); // limpar tela
     } // fim do while( 1 )
} // fim do programa principal


void entrada_dados( NODO *aux ){
      
    printf( "\n\n Digite a c�digo: " ); 
    fflush( stdin );                                     // limpa buffer do teclado, funciona junto com entrada de dados
    scanf("%d", &aux->info.codigo);

    printf( "\n Digite o nome: " );
    fflush( stdin );     
    gets( aux->info.nome );
  
    aux->prox = NULL;                                    // n�o aponta
}


void imprime_lista( NODO *aux ){
     
    if( aux == NULL )
        printf( "\n Lista vazia!" );
	else{
	    printf("\n\n ---- Relat�rio Geral ---- ");
        while( aux != NULL ){                            // ponteiro auxiliar para a lista
               //printf( "\n Nome..: %s", aux->info.nome );
               printf( "\n C�digo: %d", aux->info.codigo );
               aux = aux->prox;                          // aponta para o proximo registro da lista
		 } // fim while( aux != NULL )
	} // fim if( aux == NULL )
}


void cria_lista( NODO* *l ){
     
    *l = NULL;                                           // lista criada, inicio nao aponta
}


void inclui_fim( NODO* *l ){
     
    NODO *no = ( NODO * ) malloc( sizeof( NODO ) ); // Alocar mem�ria para novo registro
    if( no == NULL )
        printf( "\n Lista cheia!" );
    else{
        entrada_dados( no );             // L� dados do novo registro a ser inserido na lista
		if( *l == NULL )                 // Lista vazia
		    *l= no;                      // Novo registro inserido na lista
		else{
			NODO *p= *l;                 // p = ponteiro auxiliar para caminhar pela lista, inici no l
			while( p->prox != NULL )     // Enquanto p for diferente de final de lista, anda pela lista
		           p= p->prox;            
				   p->prox= no;                 // Novo registro foi inserido na lista    	
		}    
    	printf( "\n Registro foi inserido!" );
    	
	}
	    
  
}


void inclui_inicio( NODO* *l ){
  		NODO *no = ( NODO * ) malloc( sizeof( NODO ) ); // Alocar mem�ria para novo registro
   		if( no == NULL )
        printf( "\n Lista cheia!" );
    	else{
        entrada_dados( no );             // L� dados do novo registro a ser inserido na lista
			if( *l == NULL )   *l= no;              // Lista vazia
		    else { 
				no->prox = *l;
				*l = no;
				}         
			}
}


NODO* procura_nodo( NODO* p, int cod){
    printf("\n Insira o n�mero do c�digo:\n");
    
	scanf("%d", & cod);
    
	NODO *p= *l;
     	while( p->prox != NULL )  {   // Enquanto p for diferente de final de lista, anda pela lista
	        p= p->prox;            
	        p->prox= no;
		}

}


void exclui_nodo( NODO** l, int cod){
     
    printf("\n Insira o n�mero do c�digo:\n");
    
	scanf("%d", & cod);
    
	NODO *p = *l;
	
	NODO *aux = *l;
        	while(p->prox != NULL )  {   // Enquanto p for diferente de final de lista, anda pela lista
		           
				   p= p->prox;            
				   p->prox= no;
				   
				   if(p->info.codigo == cod){
				   		aux = p->prox;
				   		
							
				   	
				   }
				   
			}
}

void ordena_lista( NODO** l ){
     
 
}


void consulta_nome( NODO* l ){
 
}
