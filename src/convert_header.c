#include "../includes/asm.h"

void    convert_name(char *name, int fd, int name_size)
{
    int     n;
    int     i;

    i = 0;
    while (name[i] && i < name_size)
    {
        n = name[i];
        write(fd, &n, 1);
        i++;
    }
    while (i < name_size)
    {
        n = 0;
        write(fd, &n, 1);
        i++;
    }
}

void    convert_comment(char *comment, int fd, int comment_size)
{
    int     n;
    int     i;

    i = 0;
    if (comment)
    {
        while (comment[i] && i < comment_size)
        {
            n = comment[i];
            write(fd, &n, 1);
            i++;
        }
    }
    while (i < comment_size)
    {
        n = 0;
        write(fd, &n, 1);
        i++;
    }
}

void        convert_header(t_asm *asm_main, int fd)
{
    long long       n;

    n = asm_main->header->magic;
    n = clean_value(n);
    // printf("magic no = %lld\n", n);
    store_core_int_4(n, fd);
    // printf("%s len = %lu\n", asm_main->header->prog_name, ft_strlen(asm_main->header->prog_name));
    // printf("%s len = %lu\n", asm_main->header->comment, ft_strlen(asm_main->header->comment));
    convert_name(asm_main->header->prog_name, fd, PROG_NAME_LENGTH);
    printf("prog_size = %i\n", asm_main->header->prog_size);
    n = asm_main->header->prog_size;
    printf("prog size = %lli\n", n);
    store_core_int_4(n, fd);
    convert_comment(asm_main->header->comment, fd, COMMENT_LENGTH);
}