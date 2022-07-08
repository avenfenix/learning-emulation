#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_INST 256
#define MAX_LINEINST 128

char *instructions[MAX_INST]; // Deberia guardar las instrucciones con numeros, no con strings.

void read_file(int, char **);

int main(int argc, char *argv[]){
    read_file(argc, argv);
    return 0;
}

void read_file(int c, char **v){
    FILE *archivo = fopen(v[1], "r");
    if (archivo == NULL){
        printf("Error in \'%s()\' function : ", __FUNCTION__);
        perror("");
        exit(-1);
    }
    char line[MAX_LINEINST];
    int maxCount = MAX_LINEINST;
    int i = 0;
    while (fgets(line, maxCount, archivo)!=NULL){
        instructions[i] = strdup(line);
        i++;
    }
    instructions[i]=NULL;
    for (int j = 0; j < i; j++){
        printf("%s\n", instructions[j]);
    }
    fclose(archivo);
}