#include <iostream>
#include <algorithm> //Biblioteca necessária para usar a função swap()
#include <vector>    // Biblioteca para usar vetores dinâmicos
#include <cstdlib>   // Biblioteca para gerar números aleatórios (rand)
#include <ctime>     // Biblioteca que atualiza a semente dos números aleatórios (time)
using namespace std; 

// FUNÇÃO BUBBLE SORT (ORDENAÇÃO)
void bubble_sort(vector<int>& list) {
    int tam = list.size(); // Descobre o tamanho atual da lista   
    // O primeiro loop controla as rodadas de ordenação
    for(int i = 0; i < tam - 1; i++) {
        // O segundo loop compara os elementos vizinhos lado a lado
        for(int j = 0; j < tam - i - 1; j++) {
            // Se o número da esquerda for maior que o da direita, troca eles de lugar
            if (list[j] > list[j+1]) {         
              swap(list[j], list[j+1]); } }
    }
}
// FUNÇÃO 2 PREENCHIMENTO DA LISTA
// Recebe o vetor (value) e o tamanho (tam) como parâmetros para conseguir mexer neles.
void preencher_lista(vector<int>& value, int tam) {
 int opcao;   
 cout << "COMO A LISTA SERA PREENCHIDA?\n";
 cout << "1)MANUAL\n2)ALEATORIA\n";
 cin >> opcao;    

 if (opcao == 1) {
    cout << "\nDigite os " << tam << " elementos:\n";
    for(int i = 0; i < tam; i++) {
      cout << "Elemento " << i + 1 << ": ";
      cin >> value[i]; // Guarda o número digitado na posição 'i' do vetor
      cout<< "DIGITE APENAS NUMEROS!\n"; 
            }
        }
    } 
    else if (opcao == 2) { 
      srand(time(0)); //Inicializa o gerador de n° aleatórios com o relógio do computador
        cout << "\nGERANDO N° ALEATORIOS ENTRE 1 E 1000...\n";       
        for(int i = 0; i < tam; i++){
            value[i] = rand() % 1000 + 1; // Gera um número aleatório de 1 a 1000 e guarda 
        }
    } 
    // Caso digite uma opção inválida
    else {
        cout << "DIGITE APENAS AS OPCOES DISPONIVEIS\n";
    }
}
// FUNÇÃO PRINCIPAL (MAIN)
int main() {
    int tam;   
    cout << "\nDIGITE O N° DE ELEMENTOS QUE DESEJA NA LISTA: ";
    cin >> tam; // Lê o tamanho que o usuário quer   
    // Validação para garantir que o usuário não digite valores negativos ou zero
    if (tam <= 0) {
        cout << "DIGITE APENAS NUMEROS E VALORES POSITIVOS!\n";
        return 0; // Encerra o programa se o tamanho for inválido
        
    }
    // Cria o vetor chamado 'value' já com o tamanho exato definido pelo usuário
    vector<int> value(tam);
    // Chama a função para preencher a lista
    preencher_lista(value, tam);
    // Mostra a lista original (como o usuário digitou ou gerou antes de ordenar)
    cout << "\nLista original: ";
    for(int i = 0; i < tam; i++) {
        cout << value[i] << " ";
    }
    cout << endl;
    // Chama a função bubble_sort para ordenar o vetor
    bubble_sort(value);
    // Mostra a lista agora totalmente ordenada
    cout << "Lista ordenada: ";
    for(int i = 0; i < tam; i++) {
        cout << value[i] << " ";
    }
    cout << endl;
    return 0; 
}



