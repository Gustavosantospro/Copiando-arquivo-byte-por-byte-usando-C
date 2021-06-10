#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    // abrindo o arquivo: aqui, para exemplificação, chamaremos de source(fonte)
    FILE *source = fopen(argv[1], "r");
    
    // verificando se houve algum erro tipoo NULL
    if (source == NULL)
    {
        printf("Could not open %s\n", argv[1]);
        return 1;
    }
    FILE *destination = fopen(argv[2], "w");
    if (destination == NULL)
    {
        fclose(source);
        printf("Could not create %s\n", argv[2]);
        return 1;
    }
	
	// Definindo uma estrutura 
    BYTE buffer;
    while (fread(&buffer, sizeof(BYTE), 1, source))
    {
        fwrite(&buffer, sizeof(BYTE), 1, destination);
    }
    fclose(source);
    fclose(destination);
    return 0;
}
