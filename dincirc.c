//Aluno: João Paulo
#include <stdio.h>
#include <stdlib.h>
#include "circulardadox.h" 

struct elemento{
    struct aluno dados;
    struct elemento *prox;
};
typedef struct elemento Elem;

int main(){
	
	Lista *li;
	struct aluno al;
	int op, mat, tam, pos, cons;
	
	li = cria_lista();
	
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
			case 7:
				printf("Digite a mat que deseja consultar:\n");
				scanf("%d", &mat);
				
				cons = consulta_lista_mat(li,mat,&al);
				if(cons == 1){
					printf("Mat: %d\n", al.matricula);
					printf("Nome: %s\n", al.nome);
					printf("Notas: %.1f, %.1f\n", al.n1, al.n2);
				}else{
					printf("nao encontrado!\n");
				}
			break;
			case 8:
				printf("Digite a possicao que deseja consultar:\n");
				scanf("%d", &pos);
				
				cons = consulta_lista_pos(li,pos,&al);
				if(cons == 1){
					printf("Mat: %d\n", al.matricula);
					printf("Nome: %s\n", al.nome);
					printf("Notas: %.1f, %.1f\n", al.n1, al.n2);
				}else{
					printf("nao encontrado!\n");
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
    Lista* li = (Lista*) malloc(sizeof(Lista));
    if(li != NULL)
        *li = NULL;
    return li;
}

void libera_lista(Lista* li){
    if(li != NULL && (*li) != NULL){//checando se a lista eh valida e o conteudo do inicio tb
        Elem *aux, *no = *li;//no recebe o primeiro elemento
        while((*li) != no->prox){//percorrendo a lista, enquanto o prox elemento for diferente do primeiro elemento
            aux = no;//aux recebe o no
            no = no->prox;//o no aponta para o prox
            free(aux);//libera o aux
        }
        free(no);//libera o no
        free(li);//libera a lista
    }
}

int consulta_lista_pos(Lista* li, int pos, struct aluno *al){
    if(li == NULL || (*li) == NULL || pos <= 0)
        return 0;
    Elem *no = *li;//no aponta para o inicio
    int i = 1;//igual a 1 pq as pos começa ppor 1
    while(no->prox != (*li) && i < pos){//percorre a lista enquanto for diferente do inicio e o i menor q a pos
        no = no->prox;//percorre
        i++;//incrementa no i
    }
    if(i != pos)//se nao achou a pos
        return 0;//retorna 0
    else{
        *al = no->dados;//o pont da struct recebe os dadox
        return 1;
    }
}

int consulta_lista_mat(Lista* li, int mat, struct aluno *al){
    if(li == NULL || (*li) == NULL)
        return 0;
    Elem *no = *li;//no aponta para o inicio
    while(no->prox != (*li) && no->dados.matricula != mat)//enqt no for diferente do inicio e mat esxistente for diferente da mat inserida
        no = no->prox;//percorre a lista
    if(no->dados.matricula != mat)//se nao achou a mat
        return 0;//retorna
    else{
        *al = no->dados;//se n o pont da struct recebe os dados
        return 1;
    }
}

int insere_lista_final(Lista* li, struct aluno al){
    if(li == NULL)
        return 0;
    Elem *no = (Elem*) malloc(sizeof(Elem));
    if(no == NULL)
        return 0;
    no->dados = al;//recebendo os dados da struct inserida
    if((*li) == NULL){//lista vazia: insere início
        *li = no;//o inicio aponta para o primeiro elemento
        no->prox = no;//e o primeiro elemento aponta para ele msm pq eh circular
    }else{
        Elem *aux = *li;//aux recebe o primeiro da lista
        while(aux->prox != (*li)){//percorrendo a lista até achar o ultimo elemento, enquando o aux for diferente do inicio
            aux = aux->prox;//percorrendo a lista
        }
        aux->prox = no;//o "ultimo elemento" aponta para o novo elemento
        no->prox = *li;//novo elemento aponta para o inicio
    }
    return 1;
}

int insere_lista_inicio(Lista* li, struct aluno al){
    if(li == NULL)
        return 0;
    Elem *no = (Elem*) malloc(sizeof(Elem));
    if(no == NULL)
        return 0;
    no->dados = al;//strcut dados recebe os dados da struct inserida
    if((*li) == NULL){//se a lista tiver vazia: insere início
        *li = no;//no recebe o inicio
        no->prox = no;//e o no recebe ele mesmo porque eh circular
    }else{//se houver elementos na lista
        Elem *aux = *li;//aux recebe o inicio da lista
        while(aux->prox != (*li)){//enquanto o prox aux for diferente do conteudo do inicio da lista ele percorre ate achar o ultimo elemento
            aux = aux->prox;//percorrendo a lista
        }
        aux->prox = no;//o elemento encontrado recebe o no da lista
        no->prox = *li;//novo elemento aponta para o "primeiro" elemento
        *li = no;//colocando ele como inicio da lista
    }
    return 1;
}

int insere_lista_ordenada(Lista* li, struct aluno al){//TERMINAR
    if(li == NULL)
        return 0;
    Elem *no = (Elem*) malloc(sizeof(Elem));
    if(no == NULL)
        return 0;
    no->dados = al;//copia os dados da struct inserida para a struct dados
    if((*li) == NULL){//insere início, se a lista tiver vazia
        *li = no;//o primeiro elemento recebe o inicio
        no->prox = no;//o elemento aponta para ele msm pq eh circular
        return 1;
    }
    else{//se houver dados na lista
        if((*li)->dados.matricula > al.matricula){//insere início, se a matricula ja existente for maior da inserida
            Elem *atual = *li;//atual recebe o inicio
            while(atual->prox != (*li))//procura o último elemento
                atual = atual->prox;//percorrendo a lista
            no->prox = *li;//novo elemento aponta para o "primeiro"
            atual->prox = no;//novo elemento recebe o no
            *li = no;//o inicio aponta para o primeiro elemento
            return 1;
        }
        Elem *ant = *li, *atual = (*li)->prox;//anterior recebe o conteudo da lista, atual recebe o prox elemento
        while(atual != (*li) && atual->dados.matricula < al.matricula){//enqt o atual for diferente do inicio da lista e dados da mat na pos atual menor da nova inserida
            ant = atual;//anterior passa a ser o atual
            atual = atual->prox;//atual aponta para o prox
        }
        ant->prox = no;//elemento anterior aponta para o novo
        no->prox = atual;//novo elemento aponta para o atual;
        return 1;
    }
}

int remove_lista_inicio(Lista* li){
    if(li == NULL)
        return 0;
    if((*li) == NULL)//lista vazia
        return 0;

    if((*li) == (*li)->prox){//checando se tem um unico elem
        free(*li);//libera a lista
        *li = NULL;//inicio aponta para null
        return 1;
    }
    Elem *atual = *li;//atual recebe o incio
    while(atual->prox != (*li))//enqt o prox atual for diferente do conteudo do inicio
        atual = atual->prox;//percorrendo a lista

    Elem *no = *li;//no aponta para o primeiro elemento, inicio
    atual->prox = no->prox;//ultimo elemento aponta para ele mesmo
    *li = no->prox;//inicio aponta para o ult elem
    free(no);//libera o primeiro elem
    return 1;
}

int remove_lista_final(Lista* li){
    if(li == NULL)
        return 0;
    if((*li) == NULL)//lista vazia
        return 0;

    if((*li) == (*li)->prox){//lista fica vaza
        free(*li);
        *li = NULL;
        return 1;
    }
    Elem *ant, *no = *li;//o no aponta para o primeiro elemento
    while(no->prox != (*li)){//procura o último elem
        ant = no;//elem ant passar ser o no
        no = no->prox;//no aponto pro prox
    }
    ant->prox = no->prox;//"ult" elem aponta para o primeiro
    free(no);//libera o no
    return 1;
}

int remove_lista(Lista* li, int mat){
    if(li == NULL)
        return 0;
    if((*li) == NULL)//lista vazia
        return 0;
    Elem *no = *li;
    if(no->dados.matricula == mat){//remover do início
        if(no == no->prox){//lista fica vaza
            free(no);
            *li = NULL;
            return 1;
        }else{
            Elem *ult = *li;
            while(ult->prox != (*li))//procura o último
                ult = ult->prox;
            ult->prox = (*li)->prox;
            *li = (*li)->prox;
            free(no);
            return 1;
        }
    }
    Elem *ant = no;
    no = no->prox;
    while(no != (*li) && no->dados.matricula != mat){
        ant = no;
        no = no->prox;
    }
    if(no == *li)//não encontrado
        return 0;

    ant->prox = no->prox;
    free(no);
    return 1;
}

int tamanho_lista(Lista* li){
    if(li == NULL || (*li) == NULL)//se a lista eh valida ou primeiro elemento eh nulo
        return 0;
    int cont = 0;//criacao do cont
    Elem* no = *li;//no recebe o inicio da lista
    do{
        cont++;//faz a contagem do elemento
        no = no->prox;//passa para o prox elemento
    }while(no != (*li));//enquanto no estiver dando voltas ate chegar o primeiro elemento 
    return cont;//retorna cont
}

int lista_cheia(Lista* li){
    return 0;//nao existe lista cheia na dinamica
}

int lista_vazia(Lista* li){
    if(li == NULL)//se a lista nao foi criada
        return 1;
    if(*li == NULL)//se o inicio da lista for nula
        return 1;
    return 0;
}

void imprime_lista(Lista* li){
    if(li == NULL || (*li) == NULL)
        return;
    Elem* no = *li;
    do{
        printf("Matricula: %d\n",no->dados.matricula);
        printf("Nome: %s\n",no->dados.nome);
        printf("Notas: %f, %f\n",no->dados.n1, no->dados.n2);
        printf("-------------------------------\n");
        no = no->prox;
    }while(no != (*li));
}

