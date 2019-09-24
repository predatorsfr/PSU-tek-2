/*
** EPITECH PROJECT, 2019
** RSD64
** File description:
** main.c
*/
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <elf.h>
int main(int argc, char **argv) {
 /* Open the file and get its size: */
 int fd = open(argv[1], O_RDONLY);
 size_t len = lseek(fd, 0, SEEK_END);
 /* Map the whole file into memory: */
 void *p = mmap(NULL, len, PROT_READ, MAP_PRIVATE, fd, 0);
 Elf64_Ehdr *ehdr = (Elf64_Ehdr *)p;
 if ((ehdr->e_ident[0] != 0x7F) || (ehdr->e_ident[1] != 'E')
 || (ehdr->e_ident[2] != 'L') || (ehdr->e_ident[3] != 'F'))
 printf("not an ELF file!\n");
 switch (ehdr->e_type) {
 case ET_REL: printf("object\n"); break;
 case ET_EXEC: printf("executable\n"); break;
 case ET_DYN: printf("shared library\n"); break;
}
 Elf64_Shdr *shdrs = (void*)ehdr+ehdr->e_shoff;
char *strs = (void*)ehdr+shdrs[ehdr->e_shstrndx].sh_offset;
int i;
for (i = 0; i < ehdr->e_shnum; i++) {
 printf("%s\n", strs + shdrs[i].sh_name);
}
 return 0;
}
