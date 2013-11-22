int memoria_pedida   = 0;
int memoria_liberada = 0;

enum boolean{ FALSE , TRUE};//false = 0 e true =1. !lembrar de declarar como enum boolean

void *aloca(int tamanho){
	memoria_pedida ++;
	return((void *)malloc(tamanho));
	}

void libera(void *adeus){

	memoria_liberada++;
	free(adeus);
	}
	
typedef struct noLista {							//o nó da pilha contem uma referencia para o elemento e um ponteiro para o proximo elemento
float 	value;
int 	frequencia;
struct 	noLista *prox;
struct 	noLista *anterior;

}noLista;

typedef struct Lista{								//a pilha em si é um ponteiro para o primeiro elemento da pilha e o numero da dimensão que seus elementos guardam
struct  noLista *primeiro;	
}Lista;

//-------------------cria_lista: cria uma lista de partículas--------------

Lista *cria_lista(){
  Lista *new;
  new            = (Lista *)aloca(sizeof(Lista));
  new -> primeiro = NULL;
						
return(new);									
}

//-------------------tamanho_lista-------------------------- -----------
int tamanho_lista(Lista *lista){
	
	noLista *aux;
	int i = 0;
	aux = lista->primeiro;
	while(aux){
		i++;
		aux = aux->prox;
		}
	return(i);	
	
	}


//-------------------lista vazia: retorna verdadeiro se sim-----------
int lista_vazia(Lista *lista){
	if(tamanho_lista(lista) == 0) return(1);
	return(0);
	}

//-------------------insere_na_lista: insere uma partícula -----------

void insere_na_Lista(Lista *lista, int new_value){
 noLista *aux, *new_node;

 
    if(lista->primeiro){ 
		aux = lista->primeiro;
		while(aux->prox)
			aux = aux->prox;
			//quando saimos do laço aux estará apontando para o último
			
		new_node = (noLista *)aloca(sizeof(noLista));
    	new_node->prox     = NULL;						//o ultimo elemento da lista aponta para o proximo null
		new_node->anterior = aux;
		new_node->value        = new_value;						//inserimos o novo ponto 
		aux->prox          = new_node;						//o antigo ultimo(aux) aponta para new_node
		}
	else{
		new_node = (noLista *)aloca(sizeof(noLista)); 
		new_node->prox     = NULL;						
		new_node->anterior = NULL;
		new_node->value        = new_value;	
		lista->primeiro    = new_node;
		}
		
return;

}


//-------------------busca_na_lista ------------------------------
noLista *busca_na_lista(float value, Lista *lista){
	noLista *aux;
	
	aux = lista->primeiro;
	while(aux){
	if(aux->value == value) break;
	aux = aux->prox;
	}
	return(aux);//retorna um ponteiro para o nó da lista em que se encontra o elemento procurado
				//retorna um ponteiro NULL se não achar 
}

//-------------------remove_no_da_lista ------------------------------
void remove_no_da_lista(noLista *no, Lista *lista){
	if(no){
		if(no->anterior){
			no->anterior->prox = no->prox;
			if(no->prox)	no->prox->anterior = no->anterior;
			}
		
		else{
			if(no->prox) no->prox->anterior = NULL;
			lista->primeiro = no->prox;}
		libera(no);
	}
}

//-------------------limpa_lista:retira todos os elementos--------------
void limpa_lista(Lista *lista){//apaga a lista e espero que não apague as partículas
	while(!(lista_vazia(lista)))
		remove_no_da_lista(lista->primeiro, lista);
		
}

//----------------apaga_lista: libera toda a memoria alocada------------
void apaga_lista(Lista *lista){
	limpa_lista(lista);
	libera(lista);
	}
