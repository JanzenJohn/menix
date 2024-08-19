# x86 platform settings

set(CMAKE_C_COMPILER_TARGET x86_64-none-elf)
set(CMAKE_ASM_COMPILER_TARGET x86_64-none-elf)
set(MENIX_BITS 64)
set(MENIX_ARCH_DIR x86)

add_compile_options(
	-mgeneral-regs-only
)

add_option(page_size NUMBER 0x1000)
