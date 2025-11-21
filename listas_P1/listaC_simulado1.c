#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

//=================================================================================================//
//==================================[ EXERCICIO 1 -> VALIDAR CPF ]=================================//
//=================================================================================================//

int validarCPF(char *cpf_str)
{
    int cpf[11], count = 0, todos_iguais = 1, dig10 = 0, dig11 = 0;

    // CRIANDO VETOR DE INTEIROS
    for (int i = 0; i < 14; i++)
    {
        if (isdigit(cpf_str[i]))
        {
            cpf[count] = cpf_str[i] - '0';
            count += 1;
        }
    }

    // VERIFICACAO 1
    if (count != 11)
    {
        printf("SEM NUMEROS O SUFICIENTE, APENAS %d INTEIROS!\n", count);
        return 0;
    }

    // VERIFICACAO 2
    for (int i = 0; i < 10; i++)
        if (cpf[i] != cpf[i + 1])
        {
            todos_iguais = 0;
            break;
        }
    if (todos_iguais)
    {
        printf("TODOS OS NUMEROS IGUAIS A %d!\n", cpf[0]);
        return 0;
    }

    // VERIFICACAO 3
    for (int i = 0; i < 9; i++)
        dig10 += cpf[i] * (10 - i);
    dig10 = dig10 % 11;
    if (dig10 != 0 && dig10 != 1)
        dig10 = 11 - dig10;

    if (dig10 != cpf[9])
    {
        printf("DIGITO 10 DEVERIA SER %d, MAS FOI ENCONTRADO %d!\n", dig10, cpf[9]);
        return 0;
    }

    // VERIFICACAO 4
    for (int i = 0; i < 10; i++)
        dig11 += cpf[i] * (11 - i);
    dig11 = dig11 % 11;
    if (dig11 != 0 && dig11 != 1)
        dig11 = 11 - dig11;

    if (dig11 != cpf[10])
    {
        printf("DIGITO 11 DEVERIA SER %d, MAS FOI ENCONTRADO %d!\n", dig11, cpf[10]);
        return 0;
    }

    // SE PASSAR EM TODAS AS VERIFICACOES
    printf("PASSOU EM TODAS AS VERIFICACOES!\n");
    return 1;
}

int main_of_exercise1()
{
    char cpf_str[15];
    printf("Type the full CPF: ");
    scanf(" %s", cpf_str);
    if (validarCPF(cpf_str))
        printf("CPF VALIDO!\n");
    else
        printf("CPF INVALIDO!\n");
}

//=================================================================================================//
//===============================[ EXERCICIO 2 -> MODA EM UM VETOR ]===============================//
//=================================================================================================//

void fillVector(int N, int *vet)
{
    for (int i = 0; i < N; i++)
    {
        printf("Type the %dth element: ", i + 1);
        scanf("%d", &vet[i]);
    }
}

int elemMaisFreq(int N, int *vet)
{
    int freq, mais_freq = 0, num;
    for (int i = 0; i < N; i++)
    {
        freq = 0;
        for (int j = 0; j < N; j++)
            if (vet[i] == vet[j])
                freq += 1;
        if (freq >= mais_freq)
        {
            mais_freq = freq;
            num = vet[i];
        }
    }
    return num;
}

int main_of_exercise2()
{
    int N;
    printf("Type the size of the vector: ");
    scanf("%d", &N);

    int *vet = malloc(sizeof(int) * N);
    fillVector(N, vet);

    printf("Element more frequent = %d\n", elemMaisFreq(N, vet));
}
int main()
{
    // main_of_exercise1();
    // main_of_exercise2();

    getchar();
    getchar();
}