#include <stdio.h>
#include <stdlib.h>
#include "edados.h"

struct lista{
    int qtd;
    struct aluno dados[MAX];
};

int main(){
	
	Lista *li;
	int i, tam, pos, mat;
	struct aluno al;
	
	li = cria_lista();
	
	printf("Digite a mat:\n");
	scanf("%d", &al.matricula);
	printf("Digite o nome:\n");
	scanf("%s", al.nome);
	printf("Digite a primeira nota:\n");
	scanf("%f", &al.n1);
	printf("Digite a segunda nota:\n");
	scanf("%f", &al.n2);
	insere_lista_inicio(li, al);

	printf("Digite a mat:\n");
	scanf("%d", &al.matricula);
	printf("Digite o nome:\n");
	scanf("%s", al.nome);
	printf("Digite a primeira nota:\n");
	scanf("%f", &al.n1);
	printf("Digite a segunda nota:\n");
	scanf("%f", &al.n2);
	insere_lista_ordenada(li, al);
	
	printf("Digite a mat:\n");
	scanf("%d", &al.matricula);
	printf("Digite o nome:\n");
	scanf("%s", al.nome);
	printf("Digite a primeira nota:\n");
	scanf("%f", &al.n1);
	printf("Digite a segunda nota:\n");
	scanf("%f", &al.n2);
	insere_lista_final(li, al);
	
	
	tam = tamanho_lista(li);
	if(tam){
		printf("tamanho da lista: %d\n", tam);
	}
	
	imprime_lista(li);
	
	printf("Digite a posicao para consultar:\n");
	scanf("%d", &pos);
	pos = consulta_lista_pos(li,pos,&al);
	if(pos){
		printf("Mat: %d\n", al.matricula);
		printf("Nome: %s\n", al.nome);
	}
	
	printf("Digite a matricula para consultar:\n");
	scanf("%d", &pos);
	mat = consulta_lista_pos(li,mat,&al);
	if(mat){
		printf("Mat: %d\n", al.matricula);
		printf("Nome: %s\n", al.nome);
	}
	
	remove_lista_inicio(li);
	remove_lista(li, mat);
	remove_lista_final(li);
	
	
	return 0;
}

Lista* cria_lista(){
    Lista *li;
    li = (Lista*) malloc(sizeof(struct lista));
    if(li != NULL)
        li->qtd = 0;
    return li;
}

void libera_lista(Lista* li){
    free(li);
}

int consulta_lista_pos(Lista* li, int pos, struct aluno *al){
    if(li == NULL || pos <= 0 ||  pos > li->qtd)
        return 0;
    *al = li->dados[pos-1];
    return 1;
}

int consulta_lista_mat(Lista* li, int mat, struct aluno *al){
    if(li == NULL)
        return 0;
    int i = 0;
    while(i<li->qtd && li->dados[i].matricula != mat)
        i++;
    if(i == li->qtd)
        return 0;

    *al = li->dados[i];
    return 1;
}

int insere_lista_final(Lista* li, struct aluno al){
    if(li == NULL)
        return 0;
    if(li->qtd == MAX)
        return 0;
    li->dados[li->qtd] = al;
    li->qtd++;
    return 1;
}

int insere_lista_inicio(Lista* li, struct aluno al){
    if(li == NULL)
        return 0;
    if(li->qtd == MAX)
        return 0;
    int i;
    for(i=li->qtd-1; i>=0; i--)
        li->dados[i+1] = li->dados[i];
    li->dados[0] = al;
    li->qtd++;
    return 1;
}

int insere_lista_ordenada(Lista* li, struct aluno al){
    if(li == NULL)
        return 0;
    if(li->qtd == MAX)
        return 0;
    int k,i = 0;
    while(i<li->qtd && li->dados[i].matricula < al.matricula)
        i++;

    for(k=li->qtd-1; k >= i; k--)
        li->dados[k+1] = li->dados[k];

    li->dados[i] = al;
    li->qtd++;
    return 1;
}

int remove_lista(Lista* li, int mat){
    if(li == NULL)
        return 0;
    if(li->qtd == 0)
        return 0;
    int k,i = 0;
    while(i<li->qtd && li->dados[i].matricula != mat)
        i++;
    if(i == li->qtd)
        return 0;

    for(k=i; k< li->qtd-1; k++)
        li->dados[k] = li->dados[k+1];
    li->qtd--;
    return 1;
}

int remove_lista_inicio(Lista* li){
    if(li == NULL)
        return 0;
    if(li->qtd == 0)
        return 0;
    int k = 0;
    for(k=0; k< li->qtd-1; k++)
        li->dados[k] = li->dados[k+1];
    li->qtd--;
    return 1;
}

int remove_lista_final(Lista* li){
    if(li == NULL)
        return 0;
    if(li->qtd == 0)
        return 0;
    li->qtd--;
    return 1;
}

int tamanho_lista(Lista* li){
    if(li == NULL)
        return -1;
    else
        return li->qtd;
}

int lista_cheia(Lista* li){
    if(li == NULL)
        return -1;
    return (li->qtd == MAX);
}

int lista_vazia(Lista* li){
    if(li == NULL)
        return -1;
    return (li->qtd == 0);
}

void imprime_lista(Lista* li){
    if(li == NULL)
        return;
    int i;
    for(i=0; i< li->qtd; i++){
        printf("Matricula: %d\n",li->dados[i].matricula);
        printf("Nome: %s\n",li->dados[i].nome);
        printf("Notas: %.1f, %.1f\n",li->dados[i].n1, li->dados[i].n2);
        printf("-------------------------------\n");
    }
}
