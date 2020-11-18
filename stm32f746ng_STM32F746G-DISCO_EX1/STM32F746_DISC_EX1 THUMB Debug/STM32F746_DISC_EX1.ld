MEMORY
{
  UNPLACED_SECTIONS (wx) : ORIGIN = 0x100000000, LENGTH = 0
  ITCM (wx) : ORIGIN = 0x00000000, LENGTH = 0x00004000
  ITCM_FLASH (rx) : ORIGIN = 0x00200000, LENGTH = 0x00100000
  FLASH (rx) : ORIGIN = 0x08000000, LENGTH = 0x00100000
  SYSTEM (wx) : ORIGIN = 0x1ff00000, LENGTH = 0x0000edc0
  OTP (wx) : ORIGIN = 0x1ff0f000, LENGTH = 0x00000420
  OPTION (wx) : ORIGIN = 0x1fff0000, LENGTH = 0x00000020
  RAM (wx) : ORIGIN = 0x20000000, LENGTH = 0x00050000
  DTCM (wx) : ORIGIN = 0x20000000, LENGTH = 0x00010000
  SRAM1 (wx) : ORIGIN = 0x20010000, LENGTH = 0x0003c000
  SRAM2 (wx) : ORIGIN = 0x2004c000, LENGTH = 0x00004000
  APB1 (wx) : ORIGIN = 0x40000000, LENGTH = 0x00008000
  APB2 (wx) : ORIGIN = 0x40010000, LENGTH = 0x00006c00
  AHB1 (wx) : ORIGIN = 0x40020000, LENGTH = 0x00060000
  AHB2 (wx) : ORIGIN = 0x50000000, LENGTH = 0x00060c00
  NOR_PSRAM1 (wx) : ORIGIN = 0x60000000, LENGTH = 0x00000000
  NOR_PSRAM2 (wx) : ORIGIN = 0x64000000, LENGTH = 0x00000000
  NOR_PSRAM3 (wx) : ORIGIN = 0x68000000, LENGTH = 0x00000000
  NOR_PSRAM4 (wx) : ORIGIN = 0x6c000000, LENGTH = 0x00000000
  NAND (rx) : ORIGIN = 0x80000000, LENGTH = 0x00000000
  QUADSPI_FLASH (rx) : ORIGIN = 0x90000000, LENGTH = 0x00000000
  FMC (wx) : ORIGIN = 0xa0000000, LENGTH = 0x00001000
  QUADSPI (wx) : ORIGIN = 0xa0001000, LENGTH = 0x00000400
  SDRAM1 (wx) : ORIGIN = 0xc0000000, LENGTH = 0x00000000
  SDRAM2 (wx) : ORIGIN = 0xd0000000, LENGTH = 0x00000000
  PPB (wx) : ORIGIN = 0xe0000000, LENGTH = 0x00100000
  DBG (wx) : ORIGIN = 0xe0042000, LENGTH = 0x00000010
}

SECTIONS
{
  __ITCM_segment_start__ = 0x00000000;
  __ITCM_segment_end__ = 0x00004000;
  __ITCM_segment_size__ = 0x00004000;
  __ITCM_FLASH_segment_start__ = 0x00200000;
  __ITCM_FLASH_segment_end__ = 0x00300000;
  __ITCM_FLASH_segment_size__ = 0x00100000;
  __FLASH_segment_start__ = 0x08000000;
  __FLASH_segment_end__ = 0x08100000;
  __FLASH_segment_size__ = 0x00100000;
  __SYSTEM_segment_start__ = 0x1ff00000;
  __SYSTEM_segment_end__ = 0x1ff0edc0;
  __SYSTEM_segment_size__ = 0x0000edc0;
  __OTP_segment_start__ = 0x1ff0f000;
  __OTP_segment_end__ = 0x1ff0f420;
  __OTP_segment_size__ = 0x00000420;
  __OPTION_segment_start__ = 0x1fff0000;
  __OPTION_segment_end__ = 0x1fff0020;
  __OPTION_segment_size__ = 0x00000020;
  __RAM_segment_start__ = 0x20000000;
  __RAM_segment_end__ = 0x20050000;
  __RAM_segment_size__ = 0x00050000;
  __DTCM_segment_start__ = 0x20000000;
  __DTCM_segment_end__ = 0x20010000;
  __DTCM_segment_size__ = 0x00010000;
  __SRAM1_segment_start__ = 0x20010000;
  __SRAM1_segment_end__ = 0x2004c000;
  __SRAM1_segment_size__ = 0x0003c000;
  __SRAM2_segment_start__ = 0x2004c000;
  __SRAM2_segment_end__ = 0x20050000;
  __SRAM2_segment_size__ = 0x00004000;
  __APB1_segment_start__ = 0x40000000;
  __APB1_segment_end__ = 0x40008000;
  __APB1_segment_size__ = 0x00008000;
  __APB2_segment_start__ = 0x40010000;
  __APB2_segment_end__ = 0x40016c00;
  __APB2_segment_size__ = 0x00006c00;
  __AHB1_segment_start__ = 0x40020000;
  __AHB1_segment_end__ = 0x40080000;
  __AHB1_segment_size__ = 0x00060000;
  __AHB2_segment_start__ = 0x50000000;
  __AHB2_segment_end__ = 0x50060c00;
  __AHB2_segment_size__ = 0x00060c00;
  __NOR_PSRAM1_segment_start__ = 0x60000000;
  __NOR_PSRAM1_segment_end__ = 0x60000000;
  __NOR_PSRAM1_segment_size__ = 0x00000000;
  __NOR_PSRAM2_segment_start__ = 0x64000000;
  __NOR_PSRAM2_segment_end__ = 0x64000000;
  __NOR_PSRAM2_segment_size__ = 0x00000000;
  __NOR_PSRAM3_segment_start__ = 0x68000000;
  __NOR_PSRAM3_segment_end__ = 0x68000000;
  __NOR_PSRAM3_segment_size__ = 0x00000000;
  __NOR_PSRAM4_segment_start__ = 0x6c000000;
  __NOR_PSRAM4_segment_end__ = 0x6c000000;
  __NOR_PSRAM4_segment_size__ = 0x00000000;
  __NAND_segment_start__ = 0x80000000;
  __NAND_segment_end__ = 0x80000000;
  __NAND_segment_size__ = 0x00000000;
  __QUADSPI_FLASH_segment_start__ = 0x90000000;
  __QUADSPI_FLASH_segment_end__ = 0x90000000;
  __QUADSPI_FLASH_segment_size__ = 0x00000000;
  __FMC_segment_start__ = 0xa0000000;
  __FMC_segment_end__ = 0xa0001000;
  __FMC_segment_size__ = 0x00001000;
  __QUADSPI_segment_start__ = 0xa0001000;
  __QUADSPI_segment_end__ = 0xa0001400;
  __QUADSPI_segment_size__ = 0x00000400;
  __SDRAM1_segment_start__ = 0xc0000000;
  __SDRAM1_segment_end__ = 0xc0000000;
  __SDRAM1_segment_size__ = 0x00000000;
  __SDRAM2_segment_start__ = 0xd0000000;
  __SDRAM2_segment_end__ = 0xd0000000;
  __SDRAM2_segment_size__ = 0x00000000;
  __PPB_segment_start__ = 0xe0000000;
  __PPB_segment_end__ = 0xe0100000;
  __PPB_segment_size__ = 0x00100000;
  __DBG_segment_start__ = 0xe0042000;
  __DBG_segment_end__ = 0xe0042010;
  __DBG_segment_size__ = 0x00000010;

  __HEAPSIZE__ = 0;
  __STACKSIZE_ABT__ = 0;
  __STACKSIZE_FIQ__ = 0;
  __STACKSIZE_IRQ__ = 0;
  __STACKSIZE_PROCESS__ = 4096;
  __STACKSIZE_SVC__ = 0;
  __STACKSIZE_UND__ = 0;
  __STACKSIZE__ = 4096;

  __qspi_load_start__ = ALIGN(__QUADSPI_FLASH_segment_start__ , 4);
  .qspi ALIGN(__QUADSPI_FLASH_segment_start__ , 4) : AT(ALIGN(__QUADSPI_FLASH_segment_start__ , 4))
  {
    __qspi_start__ = .;
    *(.qspi .qspi.*)
  }
  __qspi_end__ = __qspi_start__ + SIZEOF(.qspi);
  __qspi_size__ = SIZEOF(.qspi);
  __qspi_load_end__ = __qspi_end__;

  __QUADSPI_FLASH_segment_used_end__ = ALIGN(__QUADSPI_FLASH_segment_start__ , 4) + SIZEOF(.qspi);
  __QUADSPI_FLASH_segment_used_size__ = __QUADSPI_FLASH_segment_used_end__ - __QUADSPI_FLASH_segment_start__;

  . = ASSERT(__qspi_start__ == __qspi_end__ || (__qspi_end__ - __QUADSPI_FLASH_segment_start__) <= __QUADSPI_FLASH_segment_size__ , "error: .qspi is too large to fit in QUADSPI_FLASH memory segment");

  __vectors_ram_load_start__ = ALIGN(__RAM_segment_start__ , 256);
  .vectors_ram ALIGN(__RAM_segment_start__ , 256) (NOLOAD) : AT(ALIGN(__RAM_segment_start__ , 256))
  {
    __vectors_ram_start__ = .;
    *(.vectors_ram .vectors_ram.*)
  }
  __vectors_ram_end__ = __vectors_ram_start__ + SIZEOF(.vectors_ram);
  __vectors_ram_size__ = SIZEOF(.vectors_ram);
  __vectors_ram_load_end__ = __vectors_ram_end__;

  . = ASSERT(__vectors_ram_start__ == __vectors_ram_end__ || (__vectors_ram_end__ - __RAM_segment_start__) <= __RAM_segment_size__ , "error: .vectors_ram is too large to fit in RAM memory segment");

  __vectors_load_start__ = ALIGN(__FLASH_segment_start__ , 256);
  .vectors ALIGN(__FLASH_segment_start__ , 256) : AT(ALIGN(__FLASH_segment_start__ , 256))
  {
    __vectors_start__ = .;
    *(.vectors .vectors.*)
  }
  __vectors_end__ = __vectors_start__ + SIZEOF(.vectors);
  __vectors_size__ = SIZEOF(.vectors);
  __vectors_load_end__ = __vectors_end__;

  . = ASSERT(__vectors_start__ == __vectors_end__ || (__vectors_end__ - __FLASH_segment_start__) <= __FLASH_segment_size__ , "error: .vectors is too large to fit in FLASH memory segment");

  __init_load_start__ = ALIGN(__vectors_end__ , 4);
  .init ALIGN(__vectors_end__ , 4) : AT(ALIGN(__vectors_end__ , 4))
  {
    __init_start__ = .;
    *(.init .init.*)
  }
  __init_end__ = __init_start__ + SIZEOF(.init);
  __init_size__ = SIZEOF(.init);
  __init_load_end__ = __init_end__;

  . = ASSERT(__init_start__ == __init_end__ || (__init_end__ - __FLASH_segment_start__) <= __FLASH_segment_size__ , "error: .init is too large to fit in FLASH memory segment");

  __init_rodata_load_start__ = ALIGN(__init_end__ , 4);
  .init_rodata ALIGN(__init_end__ , 4) : AT(ALIGN(__init_end__ , 4))
  {
    __init_rodata_start__ = .;
    *(.init_rodata .init_rodata.*)
  }
  __init_rodata_end__ = __init_rodata_start__ + SIZEOF(.init_rodata);
  __init_rodata_size__ = SIZEOF(.init_rodata);
  __init_rodata_load_end__ = __init_rodata_end__;

  . = ASSERT(__init_rodata_start__ == __init_rodata_end__ || (__init_rodata_end__ - __FLASH_segment_start__) <= __FLASH_segment_size__ , "error: .init_rodata is too large to fit in FLASH memory segment");

  __text_load_start__ = ALIGN(__init_rodata_end__ , 4);
  .text ALIGN(__init_rodata_end__ , 4) : AT(ALIGN(__init_rodata_end__ , 4))
  {
    __text_start__ = .;
    *(.text .text.* .glue_7t .glue_7 .gnu.linkonce.t.* .gcc_except_table .ARM.extab* .gnu.linkonce.armextab.*)
  }
  __text_end__ = __text_start__ + SIZEOF(.text);
  __text_size__ = SIZEOF(.text);
  __text_load_end__ = __text_end__;

  . = ASSERT(__text_start__ == __text_end__ || (__text_end__ - __FLASH_segment_start__) <= __FLASH_segment_size__ , "error: .text is too large to fit in FLASH memory segment");

  __dtors_load_start__ = ALIGN(__text_end__ , 4);
  .dtors ALIGN(__text_end__ , 4) : AT(ALIGN(__text_end__ , 4))
  {
    __dtors_start__ = .;
    KEEP (*(SORT(.dtors.*))) KEEP (*(.dtors)) KEEP (*(.fini_array)) KEEP (*(SORT(.fini_array.*)))
  }
  __dtors_end__ = __dtors_start__ + SIZEOF(.dtors);
  __dtors_size__ = SIZEOF(.dtors);
  __dtors_load_end__ = __dtors_end__;

  . = ASSERT(__dtors_start__ == __dtors_end__ || (__dtors_end__ - __FLASH_segment_start__) <= __FLASH_segment_size__ , "error: .dtors is too large to fit in FLASH memory segment");

  __ctors_load_start__ = ALIGN(__dtors_end__ , 4);
  .ctors ALIGN(__dtors_end__ , 4) : AT(ALIGN(__dtors_end__ , 4))
  {
    __ctors_start__ = .;
    KEEP (*(SORT(.ctors.*))) KEEP (*(.ctors)) KEEP (*(.init_array)) KEEP (*(SORT(.init_array.*)))
  }
  __ctors_end__ = __ctors_start__ + SIZEOF(.ctors);
  __ctors_size__ = SIZEOF(.ctors);
  __ctors_load_end__ = __ctors_end__;

  . = ASSERT(__ctors_start__ == __ctors_end__ || (__ctors_end__ - __FLASH_segment_start__) <= __FLASH_segment_size__ , "error: .ctors is too large to fit in FLASH memory segment");

  __rodata_load_start__ = ALIGN(__ctors_end__ , 4);
  .rodata ALIGN(__ctors_end__ , 4) : AT(ALIGN(__ctors_end__ , 4))
  {
    __rodata_start__ = .;
    *(.rodata .rodata.* .gnu.linkonce.r.*)
  }
  __rodata_end__ = __rodata_start__ + SIZEOF(.rodata);
  __rodata_size__ = SIZEOF(.rodata);
  __rodata_load_end__ = __rodata_end__;

  . = ASSERT(__rodata_start__ == __rodata_end__ || (__rodata_end__ - __FLASH_segment_start__) <= __FLASH_segment_size__ , "error: .rodata is too large to fit in FLASH memory segment");

  __ARM.exidx_load_start__ = ALIGN(__rodata_end__ , 4);
  .ARM.exidx ALIGN(__rodata_end__ , 4) : AT(ALIGN(__rodata_end__ , 4))
  {
    __ARM.exidx_start__ = .;
    __exidx_start =   __ARM.exidx_start__;
    *(.ARM.exidx .ARM.exidx.*)
  }
  __ARM.exidx_end__ = __ARM.exidx_start__ + SIZEOF(.ARM.exidx);
  __ARM.exidx_size__ = SIZEOF(.ARM.exidx);
  __exidx_end =   __ARM.exidx_end__;
  __ARM.exidx_load_end__ = __ARM.exidx_end__;

  . = ASSERT(__ARM.exidx_start__ == __ARM.exidx_end__ || (__ARM.exidx_end__ - __FLASH_segment_start__) <= __FLASH_segment_size__ , "error: .ARM.exidx is too large to fit in FLASH memory segment");

  __fast_load_start__ = ALIGN(__ARM.exidx_end__ , 4);
  .fast ALIGN(__vectors_ram_end__ , 4) : AT(ALIGN(__ARM.exidx_end__ , 4))
  {
    __fast_start__ = .;
    *(.fast .fast.*)
  }
  __fast_end__ = __fast_start__ + SIZEOF(.fast);
  __fast_size__ = SIZEOF(.fast);
  __fast_load_end__ = __fast_load_start__ + SIZEOF(.fast);

  . = ASSERT(__fast_load_start__ == __fast_load_end__ || (__fast_load_end__ - __FLASH_segment_start__) <=  __FLASH_segment_size__ , "error: .fast is too large to fit in FLASH memory segment");

  .fast_run ALIGN(__vectors_ram_end__ , 4) (NOLOAD) :
  {
    __fast_run_start__ = .;
    . = MAX(__fast_run_start__ + SIZEOF(.fast), .);
  }
  __fast_run_end__ = __fast_run_start__ + SIZEOF(.fast_run);
  __fast_run_size__ = SIZEOF(.fast_run);
  __fast_run_load_end__ = __fast_run_end__;

  . = ASSERT(__fast_run_start__ == __fast_run_end__ || (__fast_run_end__ - __RAM_segment_start__) <= __RAM_segment_size__ , "error: .fast_run is too large to fit in RAM memory segment");

  __data_load_start__ = ALIGN(__fast_load_start__ + SIZEOF(.fast) , 4);
  .data ALIGN(__fast_run_end__ , 4) : AT(ALIGN(__fast_load_start__ + SIZEOF(.fast) , 4))
  {
    __data_start__ = .;
    *(.data .data.* .gnu.linkonce.d.*)
  }
  __data_end__ = __data_start__ + SIZEOF(.data);
  __data_size__ = SIZEOF(.data);
  __data_load_end__ = __data_load_start__ + SIZEOF(.data);

  . = ASSERT(__data_load_start__ == __data_load_end__ || (__data_load_end__ - __FLASH_segment_start__) <=  __FLASH_segment_size__ , "error: .data is too large to fit in FLASH memory segment");

  .data_run ALIGN(__fast_run_end__ , 4) (NOLOAD) :
  {
    __data_run_start__ = .;
    . = MAX(__data_run_start__ + SIZEOF(.data), .);
  }
  __data_run_end__ = __data_run_start__ + SIZEOF(.data_run);
  __data_run_size__ = SIZEOF(.data_run);
  __data_run_load_end__ = __data_run_end__;

  . = ASSERT(__data_run_start__ == __data_run_end__ || (__data_run_end__ - __RAM_segment_start__) <= __RAM_segment_size__ , "error: .data_run is too large to fit in RAM memory segment");

  __bss_load_start__ = ALIGN(__data_run_end__ , 4);
  .bss ALIGN(__data_run_end__ , 4) (NOLOAD) : AT(ALIGN(__data_run_end__ , 4))
  {
    __bss_start__ = .;
    *(.bss .bss.* .gnu.linkonce.b.*) *(COMMON)
  }
  __bss_end__ = __bss_start__ + SIZEOF(.bss);
  __bss_size__ = SIZEOF(.bss);
  __bss_load_end__ = __bss_end__;

  . = ASSERT(__bss_start__ == __bss_end__ || (__bss_end__ - __RAM_segment_start__) <= __RAM_segment_size__ , "error: .bss is too large to fit in RAM memory segment");

  __tbss_load_start__ = ALIGN(__bss_end__ , 4);
  .tbss ALIGN(__bss_end__ , 4) (NOLOAD) : AT(ALIGN(__bss_end__ , 4))
  {
    __tbss_start__ = .;
    *(.tbss .tbss.*)
  }
  __tbss_end__ = __tbss_start__ + SIZEOF(.tbss);
  __tbss_size__ = SIZEOF(.tbss);
  __tbss_load_end__ = __tbss_end__;

  . = ASSERT(__tbss_start__ == __tbss_end__ || (__tbss_end__ - __RAM_segment_start__) <= __RAM_segment_size__ , "error: .tbss is too large to fit in RAM memory segment");

  __tdata_load_start__ = ALIGN(__data_load_start__ + SIZEOF(.data) , 4);
  .tdata ALIGN(__tbss_end__ , 4) : AT(ALIGN(__data_load_start__ + SIZEOF(.data) , 4))
  {
    __tdata_start__ = .;
    *(.tdata .tdata.*)
  }
  __tdata_end__ = __tdata_start__ + SIZEOF(.tdata);
  __tdata_size__ = SIZEOF(.tdata);
  __tdata_load_end__ = __tdata_load_start__ + SIZEOF(.tdata);

  __FLASH_segment_used_end__ = ALIGN(__data_load_start__ + SIZEOF(.data) , 4) + SIZEOF(.tdata);
  __FLASH_segment_used_size__ = __FLASH_segment_used_end__ - __FLASH_segment_start__;

  . = ASSERT(__tdata_load_start__ == __tdata_load_end__ || (__tdata_load_end__ - __FLASH_segment_start__) <=  __FLASH_segment_size__ , "error: .tdata is too large to fit in FLASH memory segment");

  .tdata_run ALIGN(__tbss_end__ , 4) (NOLOAD) :
  {
    __tdata_run_start__ = .;
    . = MAX(__tdata_run_start__ + SIZEOF(.tdata), .);
  }
  __tdata_run_end__ = __tdata_run_start__ + SIZEOF(.tdata_run);
  __tdata_run_size__ = SIZEOF(.tdata_run);
  __tdata_run_load_end__ = __tdata_run_end__;

  . = ASSERT(__tdata_run_start__ == __tdata_run_end__ || (__tdata_run_end__ - __RAM_segment_start__) <= __RAM_segment_size__ , "error: .tdata_run is too large to fit in RAM memory segment");

  __non_init_load_start__ = ALIGN(__tdata_run_end__ , 4);
  .non_init ALIGN(__tdata_run_end__ , 4) (NOLOAD) : AT(ALIGN(__tdata_run_end__ , 4))
  {
    __non_init_start__ = .;
    *(.non_init .non_init.*)
  }
  __non_init_end__ = __non_init_start__ + SIZEOF(.non_init);
  __non_init_size__ = SIZEOF(.non_init);
  __non_init_load_end__ = __non_init_end__;

  . = ASSERT(__non_init_start__ == __non_init_end__ || (__non_init_end__ - __RAM_segment_start__) <= __RAM_segment_size__ , "error: .non_init is too large to fit in RAM memory segment");

  __heap_load_start__ = ALIGN(__non_init_end__ , 4);
  .heap ALIGN(__non_init_end__ , 4) (NOLOAD) : AT(ALIGN(__non_init_end__ , 4))
  {
    __heap_start__ = .;
    *(.heap .heap.*)
    . = ALIGN(MAX(__heap_start__ + __HEAPSIZE__ , .), 4);
  }
  __heap_end__ = __heap_start__ + SIZEOF(.heap);
  __heap_size__ = SIZEOF(.heap);
  __heap_load_end__ = __heap_end__;

  . = ASSERT(__heap_start__ == __heap_end__ || (__heap_end__ - __RAM_segment_start__) <= __RAM_segment_size__ , "error: .heap is too large to fit in RAM memory segment");

  __stack_load_start__ = ALIGN(__heap_end__ , 8);
  .stack ALIGN(__heap_end__ , 8) (NOLOAD) : AT(ALIGN(__heap_end__ , 8))
  {
    __stack_start__ = .;
    *(.stack .stack.*)
    . = ALIGN(MAX(__stack_start__ + __STACKSIZE__ , .), 8);
  }
  __stack_end__ = __stack_start__ + SIZEOF(.stack);
  __stack_size__ = SIZEOF(.stack);
  __stack_load_end__ = __stack_end__;

  . = ASSERT(__stack_start__ == __stack_end__ || (__stack_end__ - __RAM_segment_start__) <= __RAM_segment_size__ , "error: .stack is too large to fit in RAM memory segment");

  __stack_process_load_start__ = ALIGN(__stack_end__ , 8);
  .stack_process ALIGN(__stack_end__ , 8) (NOLOAD) : AT(ALIGN(__stack_end__ , 8))
  {
    __stack_process_start__ = .;
    *(.stack_process .stack_process.*)
    . = ALIGN(MAX(__stack_process_start__ + __STACKSIZE_PROCESS__ , .), 8);
  }
  __stack_process_end__ = __stack_process_start__ + SIZEOF(.stack_process);
  __stack_process_size__ = SIZEOF(.stack_process);
  __stack_process_load_end__ = __stack_process_end__;

  __RAM_segment_used_end__ = ALIGN(__stack_end__ , 8) + SIZEOF(.stack_process);
  __RAM_segment_used_size__ = __RAM_segment_used_end__ - __RAM_segment_start__;

  . = ASSERT(__stack_process_start__ == __stack_process_end__ || (__stack_process_end__ - __RAM_segment_start__) <= __RAM_segment_size__ , "error: .stack_process is too large to fit in RAM memory segment");

}

