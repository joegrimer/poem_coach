#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CHARS 3000
#define MAX_LINES 100
#define POEM_CHUNK_SIZE 3

void println(char* line) {
    char *temp_ptr = line;
    do printf("%c", *temp_ptr == '>' ? '\n' : *temp_ptr);
    while(*((temp_ptr++)+1) != '\n');
//        printf("\n");
}

int main(int argc, char *argv[]) {
    
    if(argc != 2) { // parameters passed
        printf("usage: poem_coach FILE");
        return 1;
    }

//    printf("filename %s\n", argv[1]);
    FILE *fp;
    fp = fopen(argv[1], "r");

    char poem_buffer[MAX_CHARS]; // buffer
    char *buffer_pointer = poem_buffer;
    int c, buffer_i;
    while ((c = getc(fp)) != EOF) {
        //printf("%c", c);
        buffer_i++;
        *buffer_pointer++ = c;
        if (buffer_i >= MAX_CHARS-2) {
            printf("error. buffer length exceeded");
            return 2;
        }
    }
    buffer_pointer = '\0'; // end of buffer
//    printf("buffer len %d\n", buffer_i);
    
    char* lines[MAX_LINES];
    char** lines_ptr = lines;
    buffer_pointer = poem_buffer;
    int no_of_lines = 0;
    *lines_ptr = buffer_pointer-1; lines_ptr++;
    while (*buffer_pointer++ != '\0') {
        if(*buffer_pointer == '\n') {
            *lines_ptr++ = (buffer_pointer+1);
            no_of_lines++;
            if (*(buffer_pointer+1) == '\n') *(buffer_pointer+1) = '>';
//            printf("found %c", **(lines_ptr-1));
        }
    }
    *lines_ptr = '\0'; // end
//    no_of_lines -= POEM_CHUNK_SIZE;
//
//    do {
//        int random_no = rand()+clock();
//        int random_line_no = random_no % no_of_lines;
//        char* random_line = lines[random_line_no];
//        char* random_line_2 = lines[random_line_no+1];
//        char* random_line_3 = lines[random_line_no+2];
//        println(random_line);
//        println(random_line_2);
//        if (getchar())
//            println(random_line_3);
//        printf("\n------------------\n");
//    } while(getchar());

    for(int i=0;i<no_of_lines;i++) { //  && getchar()
        println(lines[i]);
    }

    fclose(fp);
//    printf("\n%s", poem_buffer);
    return 0;
}
