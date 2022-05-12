#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// pointers
FILE *input, *output;
void (*func)(char);


void printHex(char* buffer, int len) {
    char* p = buffer;
    for(int i=1; i<=len; i++) {
        fprintf(output, "%02X ", (unsigned char)*p);
        p++;
    }
}

void saveToBuffer(char* buffer) {
    char c;
    while((c = getc(input)) != EOF) {
        *buffer = c;
        buffer++;
    }
}

int main(int argc, char *argv[]) {
    // setting pointers to Default settings
    input = fopen("exampleFile.txt", "r");;
    output = stdout;

    size_t pos = ftell(input);          // Current position
    fseek(input, 0, SEEK_END);      // Go to end
    size_t length = ftell(input);       // read the position which is the size
    fseek(input, pos, SEEK_SET);        // restore original position

    printf("lenght of file is: %ld \n", length);

    char *buffer = malloc( length * sizeof(char));
    char *p = buffer;
    saveToBuffer(buffer);
    printHex(p, length);

    printf("%s", "\n");
    free(buffer);
    fclose(input);
    fclose(output);
    return 0;
}