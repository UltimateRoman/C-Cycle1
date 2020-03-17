#include <stdio.h>
#include<stdint.h>
#include <stdlib.h>

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    // Checks number of arguments
    if (argc != 2)
    {
        printf("Usage: ./recover image\n");
        return 1;
    }
    char *filename = argv[1];
    // Open forensic image of the file in read mode
    FILE *file = fopen(filename, "r");
    if (file == NULL)
    {
        printf("File could not be opened.\n");
        return 1;
    }
    BYTE buffer[512];
    // Declare file out
    FILE *out = NULL;
    char file_name[8];
    int file_count = 0;
    // Reads into buffer
    while (fread(buffer, sizeof(buffer), 1, file))
    {
        // Checks whether a jpeg starts
        if ((buffer[0] == 0xff) && (buffer[1] == 0xd8) && (buffer[2] == 0xff) && ((buffer[3] & 0xf0) == 0xe0))
        {
            if (file_count > 0)
            {
                fclose(out);
            }
            sprintf(file_name, "%03i.jpg", file_count);
            out = fopen(file_name, "w"); // Opens output file in write mode
            file_count++ ; 
            fwrite(buffer, sizeof(buffer), 1, out);// Writes the output image
        }
        else
        {
            if (file_count > 0)
            {
                fwrite(buffer, sizeof(buffer), 1, out);
            }
        }
    }
    fclose(out);// Closes files
    fclose(file);
    return 0;
}
