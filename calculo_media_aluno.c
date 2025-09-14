
#include <stdio.h>
#include <string.h> 

// Função para limpar o buffer de entrada.
// Essencial após o uso de scanf para evitar problemas em leituras futuras.
void clean_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Função para solicitar e validar o nome do usuário.
// Usa fgets para evitar buffer overflow e remove o caractere de nova linha.
void insertName(char nome[]) {
    do {
        printf("Digite seu nome: ");
        fgets(nome, 50, stdin);
        // Remove o '\n' que o fgets adiciona no final da string.
        nome[strcspn(nome, "\n")] = 0;
        
        if (strlen(nome) == 0) {
            printf("===== Insira uma nome válido  =====\n");
        }
    } while (strlen(nome) == 0);
}

// Função para solicitar e validar a idade do usuário.
// Valida se a entrada é um número e se está no intervalo aceitável (1 a 100).
void insertAge(int *idade) {
    do{
        printf("Digite sua idade: ");
        scanf("%d", idade);
        
        if( *idade <= 0 || *idade > 100){
            printf("===== Insira uma idade válida =====\n");
            clean_buffer(); // Limpa o buffer para o próximo scanf.
        };
    } while ( *idade <= 0 || *idade > 100);
};

// Função para ler uma nota e garantir que ela seja válida (entre 0 e 10).
float readValidNote(int noteNumber) {
    float note;
    int inputStatus;

    do {
        printf("Digite a %dª nota (0 a 10): ", noteNumber);
        
        // Captura o status da leitura de scanf para verificar se a entrada foi um número.
        inputStatus = scanf("%f", &note);

        // Verifica se a leitura foi bem-sucedida e se a nota esta no intervalo valido
        if (inputStatus != 1 || note < 0 || note > 10) {
            printf("===== Erro: Insira um numero entre 0 e 10. =====\n");
            clean_buffer();
        }
    } while (inputStatus != 1 || note < 0 || note > 10);
    
    return note;
}    

// Função para calcular a média de um array de notas.
float calculateAverage(float note[], int count) {
    float sum = 0.0;
    for (int i = 0; i < count; i++) {
        sum += note[i];
    }
    return sum / count;
}

int main(){
   // Variáveis para armazenar os dados do aluno.
   int idade=0, i;
   float notas[3], media, tam;
   char nome[50];

   // Coleta de dados do aluno.
   insertName(nome);
   insertAge(&idade);
   
   //função para mostrar o comprimento do array notas[]
   tam = sizeof(notas) / sizeof(notas[0]);
   
   // Loop para ler as notas.
   for(i = 0; i < tam; i++){
       notas[i] = readValidNote(i + 1);
   }
   // Calcula a média das notas.
   media = calculateAverage(notas, tam);
   
   // Exibe o resultado aprovado ou reprovado do aluno
   if (media >= 9){
      printf("O aluno(a) %s foi aprovado com excelente desempenho com a média:  %.1f.\n", nome, media);
   } else if(media >= 7){
      printf("O aluno(a) %s foi aprovado com a média:  %.1f\n", nome, media);
   } else {
      printf("O aluno(a) %s foi reprovado com a média:  %.1f\n", nome, media);
   }
   return 0;
}