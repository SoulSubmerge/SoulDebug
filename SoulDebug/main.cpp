#include <iostream>
#include "ExELF/elf_info.h"

int main()
{
    sdbg::Elf64HeaderInfo aaa;
    aaa.eFlags = 64;
    std::cout << aaa.eFlags << std::endl;
    return 0;
}