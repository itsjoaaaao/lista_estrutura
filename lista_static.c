//Aluno: João Paulo
#include <stdio.h>
#include <stdlib.h>
#include "edados.h"
#include <string.h>

struct lista{//struct lista
    int qtd;//variavel para contar posicoes da lista
    struct aluno dados[MAX];//vetor de struct para os dados
};

int main(){
	
	Lista *li;//declaração do ponteiro lista do tipo Lista
	int op, i, tam, pos, mat;
	struct aluno al;
	
	li = cria_lista();//criação da lista
	
	do{
		printf("-----ifba-----\n");
		printf("1 - cadastro no inicio\n");
		printf("2 - cadastro no meio\n");
		printf("3 - cadastro no fim\n");
		printf("4 - remover no inicio\n");
		printf("5 - remover no meio\n");
		printf("6 - remover no fim\n");
		printf("7 - consultar por matricula\n");
		printf("8 - consultar por posicao\n");
		printf("9 - tamanho da lista\n");
		printf("10 - imprimir\n");
		printf("11 - sair\n");
		scanf("%d", &op);
		
		switch(op){
			case 1:
				printf("Digite a mat:\n");
				scanf("%d", &al.matricula);
				printf("Digite o nome:\n");
				scanf("%s", al.nome);
				printf("Digite a primeira nota:\n");
				scanf("%f", &al.n1);
				printf("Digite a segunda nota:\n");
				scanf("%f", &al.n2);
				insere_lista_inicio(li, al);
			break;
			case 2:
				printf("Digite a mat:\n");
				scanf("%d", &al.matricula);
				printf("Digite o nome:\n");
				scanf("%s", al.nome);
				printf("Digite a primeira nota:\n");
				scanf("%f", &al.n1);
				printf("Digite a segunda nota:\n");
				scanf("%f", &al.n2);
				insere_lista_ordenada(li, al);
			break;
			case 3:
				printf("Digite a mat:\n");
				scanf("%d", &al.matricula);
				printf("Digite o nome:\n");
				scanf("%s", al.nome);
				printf("Digite a primeira nota:\n");
				scanf("%f", &al.n1);
				printf("Digite a segunda nota:\n");
				scanf("%f", &al.n2);
				insere_lista_final(li, al);
			break;
			case 4:
				if(lista_vazia(li)==1){
					printf("lista vazia!\n");
				}else{
					remove_lista_inicio(li);
					printf("removido com sucesso!\n");
				}
			break;
			case 5:
				if(lista_vazia(li)==1){
					printf("lista vazia!\n");
				}else{
					remove_lista(li,mat);
					printf("removido com sucesso!\n");
				}
			break;
			case 6:
				if(lista_vazia(li)==1){
					printf("lista vazia!\n");
				}else{
					remove_lista_final(li);
					printf("removido com sucesso!\n");
				}
			break;
			case 9:
				tam = tamanho_lista(li);
				if(tam){
					printf("tamanho da lista: %d\n", tam);
				}
			break;
			case 10:
				imprime_lista(li);
			break;
		}
		
	}while(op<=10);
	
	
	return 0;
}

Lista* cria_lista(){
    Lista *li;
    li = (Lista*) malloc(sizeof(struct lista));
    if(li != NULL)//verificacao se alocou a memoria da lista
        li->qtd = 0;//nenhuma posicao da lista ocupada
    return li;//retorna a lista
}

void libera_lista(Lista* li){
    free(li);//liberar memoria alocada da lista
}

int consulta_lista_pos(Lista* li, int pos, struct aluno *al){
    if(li == NULL || pos <= 0 ||  pos > li->qtd)//se a lista tiver nula ou a pos for menor que 0 ou a pos é maior q qtd
        return 0;//retorna 0
    *al = li->dados[pos-1];//pos-1 pq ele quer os elementos das pos maiores q 0, passa os dados para o ponteiro da struct
    return 1;
}

int consulta_lista_mat(Lista* li, int mat, struct aluno *al){
    if(li == NULL)
        return 0;
    int i = 0;
    while(i<li->qtd && li->dados[i].matricula != mat)//percorrer a lista até achar a matricula, enquanto i for menor q qtd e o dado cadastrado for diferente do dado informado
        i++;//quando achar ele incrementa
    if(i == li->qtd)//se i for igual a qtd então ele não achou
        return 0;//retorna 0

    *al = li->dados[i];//vai pegar o dado que está na pos i e passa para o ponteiro da struct
    return 1;
}

int insere_lista_final(Lista* li, struct aluno al){
    if(li == NULL)//verifica se a lista for criada
        return 0;
    if(li->qtd == MAX)//verifica se a lista ta cheia
        return 0;
    li->dados[li->qtd] = al;//struct dados recebe os dados da struct aluno
    li->qtd++;//incrementa mais um no qtd
    return 1;
}

int insere_lista_inicio(Lista* li, struct aluno al){
    if(li == NULL)//verifica se a lista foi criada
        return 0;
    if(li->qtd == MAX)//verifica se a lista ta cheia
        return 0;
    int i;
    for(i=li->qtd-1; i>=0; i--)//loop começa no ultimo elemento inserido e ele percorre a lista ao contrario
        li->dados[i+1] = li->dados[i];//deslocamento do elemento para a posicao seguinte, posicao da frente recebe a anterior a ela
    li->dados[0] = al;//inserção do elemento na primeira posicao
    li->qtd++;//incrementa mais um no qtd
    return 1;
}

int insere_lista_ordenada(Lista* li, struct aluno al){
    if(li == NULL)
        return 0;
    if(li->qtd == MAX)
        return 0;
    int k,i = 0;//começa por zero para percorrer a lista
    while(i<li->qtd && li->dados[i].matricula < al.matricula)//enquanto a pos for menor que a quantidade e a matricula ja inclusa for menor q a nova matricula ele percorre
        i++;//quanto ele achar um numero maior ele para de percorrer

    for(k=li->qtd-1; k >= i; k--)//loop para até a pos i que ele achou anteriormente
        li->dados[k+1] = li->dados[k];//depois ele desloca os numeros maiores para frente

    li->dados[i] = al;//faz a inserção do novo dado na pos i
    li->qtd++;//incrementa o qtd
    return 1;
}

int remove_lista(Lista* li, int mat){
    if(li == NULL)
        return 0;
    if(li->qtd == 0)
        return 0;
    int k,i = 0;
    while(i<li->qtd && li->dados[i].matricula != mat)//enquanto i for menor q o qtd e a matricula que está inserirda for diferente q o usuario passar
		i++;//ele vai percorrendo a lista
    if(i == li->qtd)//se o i for igual a quantidade então ele não encontrou a matricula
        return 0;

    for(k=i; k< li->qtd-1; k++)//loop para percorrer a lista, começa do elemento encontrado até o final da lista
        li->dados[k] = li->dados[k+1];//descolamento dos dados diferente do i para esquerda
    li->qtd--;//decrementacao na quantidade
    return 1;
}

int remove_lista_inicio(Lista* li){
    if(li == NULL)
        return 0;
    if(li->qtd == 0)//verifica se a lista ta vazia
        return 0;
    int k = 0;
    for(k=0; k< li->qtd-1; k++)//faz um loop para percorrer a lista, começa no inicio e acaba no ultimo elemento
        li->dados[k] = li->dados[k+1];//ele desloca todos os elementos para a esquerda
    li->qtd--;//decrementa q quantidade
    return 1;
}

int remove_lista_final(Lista* li){
    if(li == NULL)
        return 0;
    if(li->qtd == 0)//verifica se a lista ta vazia
        return 0;
    li->qtd--;//apenas decrementa a quantidade
    return 1;
}

int tamanho_lista(Lista* li){
    if(li == NULL)//verifica se a lista é nula
        return -1;//retorna -1 se a lista nao existir
    else
        return li->qtd;//se nao retorna o qtd q mostra o numero de posicoes
}

int lista_cheia(Lista* li){
    if(li == NULL)//verifica se a lista eh nula
        return -1;
    return (li->qtd == MAX);//se a quantidade for igual o tamanho do vetor então ela esta cheia
}

int lista_vazia(Lista* li){
    if(li == NULL)//verifica se a lista eh nula
        return -1;
    return (li->qtd == 0);//se a quantidade for igual a 0 entao a lista esta vazia
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
