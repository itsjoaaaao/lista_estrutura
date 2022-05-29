struct aluno{
	int matricula;
	char nome[20];
	float n1, n2;
};
typedef struct elemento* Lista;

//int contMat = 0;

Lista* cria_lista();
void libera_lista(Lista* li);
int tamanho_lista(Lista* li);
int lista_cheia(Lista* li);
int lista_vazia(Lista* li);
//inserir
int insere_lista_inicio(Lista* li, struct aluno al);
int insere_lista_final(Lista* li, struct aluno al);
int insere_lista_ordenada(Lista* li, struct aluno al);
//remover
int remove_lista_inicio(Lista* li);
int remove_lista_final(Lista* li);
int remove_lista(Lista* li, int mat);
//consultar
int consulta_lista_pos(Lista* li, int pos, struct aluno *al);
int consulta_lista_matricula(Lista* li, int mat, struct aluno *al);
//int ordenar_lista(Lista * li);

void imprimir_lista(Lista * li);
