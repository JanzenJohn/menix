# x86 platform settings

set(CMAKE_C_COMPILER_TARGET x86_64-none-elf)
set(CMAKE_ASM_COMPILER_TARGET x86_64-none-elf)
set(MENIX_BITS 64)
set(MENIX_ARCH_DIR x86)
set(MENIX_ARCH_NAME x86_64)

target_compile_options(common INTERFACE
	-mgeneral-regs-only
	-mno-red-zone
)

target_compile_options(common_kernel INTERFACE
	-mcmodel=kernel
)
