#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./recover image\n");
        return 1;
    }
    
    FILE *file = fopen(argv[1], "rb");
    
    if (file == NULL)
    {
        printf("Error reading the file\n");
        return 1;
    }
    
    char filename[8];
    filename[7] = '\0';
    FILE *outputfile = NULL;
    uint8_t buffer[512];
    int jpga = 0;
    bool check = false;

    while (fread(buffer, 1, sizeof(buffer), file) == sizeof(buffer))
    {
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            if (jpga == 0)
            {
                sprintf(filename, "%03d.jpg", jpga);
                outputfile = fopen(filename, "wb");
                fwrite(buffer, 1, sizeof(buffer), outputfile);
                check = true;
                jpga++;
            }
            else if (jpga != 0)
            {
                fclose(outputfile);
                check = false;
                sprintf(filename, "%03d.jpg", jpga);
                outputfile = fopen(filename, "wb");
                fwrite(buffer, 1, sizeof(buffer), outputfile);
                check = true;
                jpga++;
            }
        }
        else if (check == true)
        {
            fwrite(buffer, 1, sizeof(buffer), outputfile);
        }
        else if (jpga != 0 && check == false)
        {
            fwrite(buffer, 1, sizeof(buffer), outputfile);
        }
    }

    fclose(file);
    fclose(outputfile);
    return 0;
}