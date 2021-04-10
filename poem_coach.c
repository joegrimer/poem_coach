#include <stdio.h>

#define BUFFER_SIZE 3000

int main(int argc, char *argv[]) {
    
    if(argc != 2) { // parameters passed
        printf("usage: poem_coach FILE");
        return 1;
    }

    printf("filename %s\n", argv[1]);
    FILE *fp;
    fp = fopen(argv[1], "r");

    int poem_buffer[BUFFER_SIZE]; // buffer
    int c, buffer_i=0;
    while ((c = getc(fp)) != EOF) {
        //printf("%c", c);
        poem_buffer[buffer_i] = c;
        buffer_i++;
        if (buffer_i >= BUFFER_SIZE-2) {
            printf("error. buffer length exceeded");
            return 2;
        }
    }
    printf("\n\nbuffer len %d\n", buffer_i);
    fclose(fp);
    return 0;
}
