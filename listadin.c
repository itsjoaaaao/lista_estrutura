#include <stdio.h>
#include <stdlib.h>
#include "listadin.h"

struct elemento{
	struct aluno dados;
	struct elemento *prox;
};
typedef struct elemento Elem;

int main(){
	
	Lista *li;
	int op, buscapos;
	struct aluno al;
	
	li = cria_lista();
	
	do{
		printf("1 - inserir no inicio\n");
		printf("2 - inserir no meio\n");
		printf("3 - inserir no final\n");
		printf("4 - remover no inicio\n");
		printf("5 - remover um elemento qualquer\n");
		printf("6 - remover no final\n");
		printf("7 - consultar por posicao\n");
		printf("8 - consultar por matricula\n");
		printf("9 - imprimir\n");
		scanf("%d", &op);
		
		
		switch(op){
			case 1:
				if(lista_cheia(li)==1){
					printf("lista cheia!!\n");
				}else{
					printf("Digite a matricula:\n");
					scanf("%d", &al.matricula);
					printf("Digite o nome:\n");
					scanf("%s", al.nome);
					printf("Digite a primeira nota:\n");
					scanf("%f", &al.n1);
					printf("Digite a segunda nota:\n");
					scanf("%f", &al.n2);
					insere_lista_inicio(li, al);
				}
				break;
				case 2:
					if(lista_cheia(li)==1){
					printf("lista cheia!!\n");
				}else{
					printf("Digite a matricula:\n");
					scanf("%d", &al.matricula);
					printf("Digite o nome:\n");
					scanf("%s", al.nome);
					printf("Digite a primeira nota:\n");
					scanf("%f", &al.n1);
					printf("Digite a segunda nota:\n");
					scanf("%f", &al.n2);
					insere_lista_ordenada(li, al);
				}
				break;
				case 3:
					if(lista_cheia(li)==1){
					printf("lista cheia!!\n");
				}else{
					printf("Digite a matricula:\n");
					scanf("%d", &al.matricula);
					printf("Digite o nome:\n");
					scanf("%s", al.nome);
					printf("Digite a primeira nota:\n");
					scanf("%f", &al.n1);
					printf("Digite a segunda nota:\n");
					scanf("%f", &al.n2);
					insere_lista_final(li, al);
				}
				case 4:
					if(lista_vazia(li)==1){
						printf("lista vazia!!\n");
					}else{
						int rem = remove_lista_inicio(li);
						if(rem){
							printf("removido do inicio!\n");
						}
					}
				break;
				case 5:
					if(lista_vazia(li)==1){
						printf("lista vazia!!\n");
					}else{
						int remmat;
						printf("digite a matricula que voce deseja remover:\n");
						scanf("%d, &remmat");
						remmat = remove_lista(li,mat);
					}
				break;
				case 6:
					if(lista_vazia(li)==1){
						printf("lista vazia!!\n");
					}else{
						int remfinal = remove_lista_final(li);
						if(remfinal){
							printf("removido do final!\n");
						}
					}
				break;
				case 7:
					printf("Digite a posicao que deseja consultar:\n");
					scanf("%d", &buscapos);
					buscapos = consulta_lista_pos(li,pos,&al);
					if(buscapos){
						printf("----Dados:----\n");
						printf("Mat: %d", al.matricula);
						printf("Nome: %s", al.nome);
						printf("Nota 1: %.1f, Nota 2: %.1f", al.n1, al.n2);
					}
				break;
				case 8:
					int busca;
					printf("Digite a mat que deseja consultar:\n");
					scanf("%d", &busca);
					busca = consulta_lista_matricula(li,mat,&al);
					if(busca){
						printf("----Dados:----\n");
						printf("Mat: %d", al.matricula);
						printf("Nome: %s", al.nome);
						printf("Nota 1: %.1f, Nota 2: %.1f", al.n1, al.n2);
					}
				break;
				case 9:
					imprimir_lista(li);
				break;
		}
		
	}while(op<=9);
	
	return 0;
}

Lista* cria_lista(){
	Lista *li;
	li = (Lista*) malloc(sizeof(Lista));
	if(li != NULL){
		*li = NULL;
	} 
	return li;
}

//libera lista
void libera_lista(Lista* li){
    if(li != NULL) {
        Elem *no;
        while((*li) != NULL){
            no = *li;
            *li = (*li)->prox;
            free(no);
        }
        free(li);
    }

}

//Retorna tamanho da lista
int tamanho_lista(Lista* li){
    if(li == NULL)
        return 0;
    int count = 0;
    Elem* no = *li;
    while(no != NULL){
        count++;
        no = no->prox;
    }
    return count;
}

int lista_cheia(Lista* li){
    return 0;
}

// Checa lista vazia
int lista_vazia(Lista* li){
    if(li == NULL)
        return 1;
    if((*li) == NULL)
        return 1;

    return 0;
}

// Insere no inicio da lista
int insere_lista_inicio(Lista* li, struct aluno al){
    if(li == NULL)
        return 0;

    Elem* no = (Elem*) malloc(sizeof(Elem));

    if(no == NULL)
        return 0;

    no->dados = al;
    no->prox = (*li);
    *li = no;

    return 1;
}

// Insere no final da lista
int insere_lista_final(Lista* li, struct aluno al){
    if(li == NULL)
        return 0;
    Elem* no = (Elem*) malloc(sizeof(Elem));
    if(no == NULL)
        return 0;

    //gerando matricula automatica
    //al.matricula = contMat;

    no->dados = al;
    no->prox = NULL;

    if((*li) == NULL){
        *li = no;
    }else{
        Elem *aux = *li;
        while(aux->prox != NULL){
            aux = aux->prox;
        }
        aux->prox = no;
    }

    return 1;
}

//Insere na lista de forma ordenada
int insere_lista_ordenada(Lista* li, struct aluno al){
    if(li == NULL)
        return 0;
    Elem *no = (Elem*)malloc(sizeof(Elem));
    if(no == NULL)
        return 0;
    no->dados = al;
    if(lista_vazia(li)){ //insere inicio
        no->prox = (*li);
        *li = no;
        return 1;
    }else{
        Elem * ant, *atual = *li;
        while(atual != NULL && atual->dados.matricula < al.matricula){
            ant = atual;
            atual = atual->prox;
        }
        if(atual == *li){ //insere inicio
            no->prox = (*li);
            *li = no;
        }else{
            no->prox = atual->prox;
            ant->prox = no;
        }
        return 1;
    }
}

//Remove do inicio da lista
int remove_lista_inicio(Lista* li){
    if(li == NULL)
        return 0;
    if((*li) == NULL)
        return 0;

    Elem *no = *li;
    *li = no->prox;
    free(no);
    return 1;
}

//Remove do final da lista
int remove_lista_final(Lista* li){
    if(li == NULL)
        return 0;
    if((*li) == NULL)
        return 0;

    Elem *ant, *no = *li;
    while (no->prox != NULL){
        ant = no;
        no = no->prox;
    }
    if(no == (*li))
        *li = no->prox;
    else
        ant->prox = no->prox;
    free(no);

    return 1;
}

//Remove elemento de um lugar especifico da lista
int remove_lista(Lista* li, int mat){
    if(li == NULL)
        return 0;

    Elem *ant, *no = *li;
    while(no != NULL && no->dados.matricula != mat){
        ant = no;
        no = no->prox;
    }

    if(no == NULL)
        return 0;

    if(no == *li)
        *li = no->prox;
    else
        ant->prox = no->prox;

    free(no);

    return 1;
}

//Consultar elemento na lista por posiÁ„o
int consulta_lista_pos(Lista* li, int pos, struct aluno *al){
    if(li == NULL || pos <= 0)
        return 0;

    Elem *no = *li;
    int i =  1;
    while(no != NULL && i < pos){
        no = no->prox;
        i++;
    }
    if(no == NULL)
        return 0;
    else{
        *al = no->dados;
        return 1;
    }
}

int consulta_lista_matricula(Lista* li, int mat, struct aluno *al){

    if(li == NULL || mat <= 0)
        return 0;

    Elem *no = *li;

    while(no != NULL && no->dados.matricula != mat){
        no = no->prox;
    }

    if(no == NULL)
        return 0;
    else {
        *al = no->dados;
        return 1;
    }
}

// Q1 - Imprimir a lista
void imprimir_lista(Lista * li){

    Elem *no = *li;

    do{
        printf("Mat: %d\n", no->dados.matricula);
        printf("Nome: %s\n", no->dados.nome);
        printf("Nota 1: %.1f, Nota 2: %.1f", no->dados.n1, no->dados.n2);
        printf("------------------------\n");
        no = no->prox;
    }
    while(no->prox != NULL);
}
