# Driver subsystems (Not drivers themselves, see `/modules/`!)

target_sources(menix PUBLIC module.c)

add_subdirectory(acpi)
add_subdirectory(pci)
