#include "monty.h"

int main(int argc, char* argv[])
{
    FILE *my_file;
    char buffer[2048];
    stack_t *head_node = NULL;
    int line_number = 1, i;

    if (argc != 2)
    {
        fprintf(stderr, "USAGE: monty file\n");
        exit(1);
    }
    my_file = fopen(argv[1], "r");
    i = 0;
    while(fgets(buffer, sizeof(buffer), my_file) != NULL)
    {
        for (; i < line_number; i++)
        {
            check_function(buffer, &head_node);
        }
        line_number++;
    }
    fclose(my_file);
    free_stack(head_node);
    return (0);
}
