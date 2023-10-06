ENTRY(reset_handler)

MEMORY
{
  FLASH (rx) : ORIGIN = 0x08000000, LENGTH = 128K
  RAM (rwx) : ORIGIN = 0x20000000, LENGTH = 20K
}

SECTIONS
{
	_kernel_start = ORIGIN(FLASH) + .;

  .text :
  {
		_text_start = .;
    _isr_vector_start = .;
    KEEP(*(.isr_vector))
    _isr_vector_end = .;
    *(.text)
    *(.text.*)
    *(.rodata)
		_text_end = .;
    _init_data_start = .;
  } >FLASH

  .data : AT(_init_data_start)
  {
    _data_start = .;
    *(.data)
    *(.data*)
    _data_end = .;
  } >RAM

  .bss :
  {
    _bss_start = .;
    *(.bss)
    _bss_end = .;
  } >RAM

  _kernel_end = .;
  _stack_end = ORIGIN(RAM) + LENGTH(RAM);
}
