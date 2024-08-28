# x86 platform settings

set(CMAKE_C_COMPILER_TARGET x86_64-none-elf)
set(CMAKE_ASM_COMPILER_TARGET x86_64-none-elf)
set(MENIX_BITS 64)
set(MENIX_ARCH_DIR x86)
set(MENIX_ARCH_NAME x86_64)

add_compile_options(
	-mgeneral-regs-only
	-mno-red-zone
	-mcmodel=kernel
)
