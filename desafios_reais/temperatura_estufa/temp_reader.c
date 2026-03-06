#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    int count_temps = 0, error = 0;
    float temp, sum = 0, max_temp = -1000;
    char linha[20], char_temp[20];
    FILE *file;

    file = fopen("C:/Users/Computador/Documents/GitHub/estudo_de_listas_C/desafios_reais/temperatura_estufa/leitura_sensor.csv", "r");

    if (file == NULL)
    {
        printf("Impossible to read the file..\n");
        getchar();
        getchar();
        return 0;
    }
    else
        printf("Successfully Read!\nCalculating Results..");

    while (fgets(linha, sizeof(linha), file))
    {
        if (strlen(linha) < 7)
            continue;
        // cut the line to get only the temp field
        strcpy(char_temp, strtok(&linha[6], ","));
        // if isnt the "ERR" error
        if (strcmp(char_temp, "ERR") != 0)
        {
            // change to float and count in the average
            temp = atof(char_temp);
            count_temps++;
            sum += temp;

            // verify if is bigger than the current max
            if (temp >= max_temp)
                max_temp = temp;
        }
        else
            // count the errors
            error++;
    }
    fclose(file);
    if (count_temps >= 1)
        printf("\nHigher temperature: %.1f\nAverage of the temperatures: %.2f\nErrors finds: %d", max_temp, sum / count_temps, error);
    else
        printf("\n\nA temperature reading could not be successfuly obtained..\nErros finds: %d", error);
    getchar();
    getchar();
    return 0;
}