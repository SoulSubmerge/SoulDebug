#ifndef _ELF_INFO_H
#define _ELF_INFO_H
#include "type_unit.h"

namespace sdbg
{
    const sdbg::uint32 ELF_IDENT_SIZE = 16;
    typedef struct _Elf32HeaderInfo
    {
        sdbg::uint8	    eIdent[sdbg::ELF_IDENT_SIZE];	/* Magic number and other info */
        sdbg::uint16	eType;			/* Object file type */
        sdbg::uint16	eMachine;		/* Architecture */
        sdbg::uint32	eVersion;		/* Object file version */
        sdbg::uint32	eEntry;		/* Entry point virtual address */
        sdbg::uint32	ePhoff;		/* Program header table file offset */
        sdbg::uint32	eShoff;		/* Section header table file offset */
        sdbg::uint32	eFlags;		/* Processor-specific flags */
        sdbg::uint16	eEhsize;		/* ELF header size in bytes */
        sdbg::uint16	ePhentsize;		/* Program header table entry size */
        sdbg::uint16	ePhnum;		/* Program header table entry count */
        sdbg::uint16	eShentsize;		/* Section header table entry size */
        sdbg::uint16	eShnum;		/* Section header table entry count */
        sdbg::uint16	eShstrndx;		/* Section header string table index */
    }Elf32HeaderInfo;

    typedef struct _Elf64HeaderInfo
    {
        sdbg::uint8	    eIdent[sdbg::ELF_IDENT_SIZE];	/* Magic number and other info */
        sdbg::uint16	eType;			/* Object file type */
        sdbg::uint16	eMachine;		/* Architecture */
        sdbg::uint32	eVersion;		/* Object file version */
        sdbg::uint64	eEntry;		/* Entry point virtual address */
        sdbg::uint64	ePhoff;		/* Program header table file offset */
        sdbg::uint64	eShoff;		/* Section header table file offset */
        sdbg::uint32	eFlags;		/* Processor-specific flags */
        sdbg::uint16	eEhsize;		/* ELF header size in bytes */
        sdbg::uint16	ePhentsize;		/* Program header table entry size */
        sdbg::uint16	ePhnum;		/* Program header table entry count */
        sdbg::uint16	eShentsize;		/* Section header table entry size */
        sdbg::uint16	eShnum;		/* Section header table entry count */
        sdbg::uint16	eShstrndx;		/* Section header string table index */
    }Elf64HeaderInfo;
}
#endif