/*
** EPITECH PROJECT, 2019
** RSD64
** File description:
** obj.c
*/

#include <elf.h>
#include <stdio.h>
#include <string.h>

char *elf_check_supported(Elf32_Ehdr *hdr) {
static int i = 1;
	if(i == 1 && hdr->e_ident[EI_CLASS] != ELFCLASS32) {
        i++;
        return ("elf64-x86-64");
	}
    if(i == 2 && hdr->e_machine == EM_X86_64) {
        i++;
        return ("i386:x86-64");
	}
}

void obj(char *av)
{
    Elf32_Ehdr hdr;
    fread(&hdr, 1, sizeof hdr, fopen(av, "r+"));
    printf("\n%s:     file format %s\n",av, elf_check_supported(&hdr));
    printf("architecture: %s, flags \n",elf_check_supported(&hdr));
}
