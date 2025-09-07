#include <iostream>
using namespace std;

// definição de tipo
struct NO {
    int valor;
    NO* prox;
    NO* ant;
};

NO* primeiro = NULL;

// headers
void menu();
void inicializar();
void exibirQuantidadeElementos();
void exibirElementos();
void inserirElemento();
void excluirElemento();
void buscarElemento();
NO* posicaoElemento(int numero);
//--------------------------


int main()
{
    menu();
}

void menu()
{
    int op = 0;
    while (op != 7) {
        system("cls"); // somente no windows
        cout << "Menu Lista Ligada";
        cout << endl << endl;
        cout << "1 - Inicializar Lista \n";
        cout << "2 - Exibir quantidade de elementos \n";
        cout << "3 - Exibir elementos \n";
        cout << "4 - Buscar elemento \n";
        cout << "5 - Inserir elemento \n";
        cout << "6 - Excluir elemento \n";
        cout << "7 - Sair \n\n";

        cout << "Opcao: ";
        cin >> op;

        switch (op)
        {
        case 1: inicializar();
            break;
        case 2: exibirQuantidadeElementos();
            break;
        case 3: exibirElementos();
            break;
        case 4: buscarElemento();
            break;
        case 5: inserirElemento();
            break;
        case 6: excluirElemento();
            break;

        case 7:
            return;
        default:
            break;
        }

        system("pause"); // somente no windows
    }
}

void inicializar()
{

    // se a lista já possuir elementos
    // libera a memoria ocupada
    NO* aux = primeiro;
    while (aux != NULL) {
        NO* paraExcluir = aux;
        aux = aux->prox;
        free(paraExcluir);
    }

    primeiro = NULL;
    cout << "Lista inicializada \n";

}

void exibirQuantidadeElementos() {

    int nElementos = 0;
    NO* aux = primeiro;
    while (aux != NULL) {
        nElementos++;
        aux = aux->prox;
    }
    cout << "Quantidade de elementos: " << nElementos << endl;

}

void exibirElementos()
{
    if (primeiro == NULL) {
        cout << "Lista vazia \n";
        return;
    }
    else {
        cout << "Elementos: \n";
        NO* aux = primeiro;
        while (aux != NULL) {
            cout << aux->valor << endl;
            aux = aux->prox;
        }
    }
}

void inserirElemento()
{
    // aloca memoria dinamicamente para o novo elemento
    NO* novo = (NO*)malloc(sizeof(NO));
    if (novo == NULL)
    {
        return;
    }

    cout << "Digite o elemento: ";
    cin >> novo->valor;
    novo->prox = NULL;
    novo->ant = NULL;

    if (primeiro == NULL)
    {
        primeiro = novo;
    }
    else {
        if (posicaoElemento(novo->valor) != NULL) {
            cout << "O numero ja existe" << endl;
            return;
        }
        // Insere no final da lista
        NO* aux = primeiro;
        while (aux->prox != NULL) {
            aux = aux->prox;
        }
        aux->prox = novo;
        novo->ant = aux;
    }
}

void excluirElemento()
{
    int valor;
    cout << "Digite o valor a ser excluido: ";
    cin >> valor;

    // Busca o elemento
    //Aqui ele ta pegando o valor e colocando pra ver se ta no nó
    NO* nmdel = posicaoElemento(valor);
    //se for nulo ele fala q n tem
    if (nmdel == NULL) {
        cout << "Coloca um numero que existe pra inicio de conversa" << endl;
        return;
    }

    // Se for o único elemento (primeiro e último são o mesmo)
    //vai ver se o anterior e o porximo é nulo
    if (nmdel->ant == NULL  && nmdel->prox == NULL) {
        //define o primeiro como nulo e limpa tudo
        primeiro = NULL;
        free(nmdel);
        cout << "A-PA-GA-DO" << endl;
        return;
    }

    // Se for o primeiro nó
    //vai ver so o anterior é alguem
    if (nmdel->ant == NULL) {
    //o primeiro vira o numero seguinte
        primeiro = nmdel->prox;
        nmdel->prox->ant = NULL;
        free(nmdel);
        cout << "A-PA-GA-DO" << endl;
        return;
    }

    // Se for o último nó
    //ver se o ultimo é realmente o ultimo
    if (nmdel->prox == NULL) {
    //vai fazer o antes dele ser NULL
        nmdel->ant->prox = NULL;
        free(nmdel);
        cout << "A-PA-GA-DO" << endl;
        return;
    }

    // Se for um nó do meio
    //o proximo vai pro proximo e o anterior mantem antes
    nmdel->ant->prox = nmdel->prox;
    nmdel->prox->ant = nmdel->ant;
    //aqui ja mata
    free(nmdel);
    cout << "A-PA-GA-DO" << endl;
    
}

void buscarElemento()
{
    int b;
    cout << "Digite o numero a ser buscado: ";
    cin >> b;

    NO* elemento = posicaoElemento(b);
    if (elemento != NULL) {
     
    }
    else {
        cout << "nem tem esse numero" << endl;
    }
}



// retorna um ponteiro para o elemento buscado
// ou NULL se o elemento não estiver na lista
NO* posicaoElemento(int numero)
{
    NO* aux = primeiro;
    while (aux != NULL) {
        if (aux->valor == numero) {
            return aux;
        }
        aux = aux->prox;
    }
    return NULL;
}
