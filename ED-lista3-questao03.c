/*
 Função:
 Autor: Aderbal Ferreira da Silva Filho
 Data: 05/06/2024
 Observações: 
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {
    int dia;
    int mes;
    int ano;
} Data;

typedef struct {
    char nome_completo[80];
    char sexo;
    Data data_nascimento;
    char endereco[100];
    char telefone[15];
    float altura;
    float peso;
} Paciente;

int calcularIdade(Data data_nascimento) {
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);

    int idade = tm.tm_year + 1900 - data_nascimento.ano;

    if (tm.tm_mon + 1 < data_nascimento.mes || (tm.tm_mon + 1 == data_nascimento.mes && tm.tm_mday < data_nascimento.dia)) {
        idade--;
    }

    return idade;
}

float calcularIMC(float peso, float altura) {
    return peso / (altura * altura);
}

float calcularIGC(float peso, float altura, char sexo) {
    // Implemente o cálculo do Índice de Gordura Corporal (IGC) aqui
    return 0.0;
}

float calcularTMB(float peso, float altura, int idade, char sexo) {
    // Implemente o cálculo da Taxa Metabólica Basal (TMB) aqui
    return 0.0;
}

void Dados(Paciente *paciente) {
    printf("Digite o nome completo: ");
    getchar();
    fgets(paciente->nome_completo, sizeof(paciente->nome_completo), stdin);
    paciente->nome_completo[strcspn(paciente->nome_completo, "\n")] = '\0';

    printf("Digite o sexo (M/F): ");
    scanf(" %c", &paciente->sexo);

    printf("Digite a data de nascimento (digite um por vez): ");
    scanf("%d %d %d", &paciente->data_nascimento.dia, &paciente->data_nascimento.mes, &paciente->data_nascimento.ano);

    printf("Digite o endereço: ");
    getchar();
    fgets(paciente->endereco, sizeof(paciente->endereco), stdin);
    paciente->endereco[strcspn(paciente->endereco, "\n")] = '\0';

    printf("Digite o número de telefone: ");
    scanf("%s", paciente->telefone);

    printf("Digite a altura (em metros): ");
    scanf("%f", &paciente->altura);

    printf("Digite o peso (em kg): ");
    scanf("%f", &paciente->peso);
}

void exibirPerfil(Paciente paciente) {
    printf("\nPerfil do Paciente:\n");
    printf("Nome completo: %s\n", paciente.nome_completo);
    printf("Sexo: %c\n", paciente.sexo);
    printf("Data de nascimento: %02d/%02d/%04d\n", paciente.data_nascimento.dia, paciente.data_nascimento.mes, paciente.data_nascimento.ano);
    printf("Endereço: %s\n", paciente.endereco);
    printf("Telefone: %s\n", paciente.telefone);
    printf("Altura: %.2f metros\n", paciente.altura);
    printf("Peso: %.2f kg\n", paciente.peso);
}

int main() {
    int N;
    printf("Digite o número de pacientes a serem cadastrados: ");
    scanf("%d", &N);

    Paciente* pacientes = (Paciente*)malloc(N * sizeof(Paciente));

    for (int i = 0; i < N; i++) {
        printf("\nCadastrando o paciente %d:\n", i + 1);
        Dados(&pacientes[i]);
    }

    for (int i = 0; i < N; i++) {
        exibirPerfil(pacientes[i]);

        int idade = calcularIdade(pacientes[i].data_nascimento);
        float imc = calcularIMC(pacientes[i].peso, pacientes[i].altura);
        float igc = calcularIGC(pacientes[i].peso, pacientes[i].altura, pacientes[i].sexo);
        float tmb = calcularTMB(pacientes[i].peso, pacientes[i].altura, idade, pacientes[i].sexo);

        printf("Idade: %d anos\n", idade);
        printf("IMC: %.2f\n", imc);
        printf("IGC: %.2f\n", igc);
        printf("TMB: %.2f\n", tmb);
    }

    free(pacientes);

    return 0;
}
