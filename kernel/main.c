// Kernel entry point

#include <menix/arch.h>
#include <menix/boot.h>
#include <menix/common.h>
#include <menix/drv/pci/pci.h>
#include <menix/fs/vfs.h>
#include <menix/io/terminal.h>
#include <menix/log.h>
#include <menix/module.h>
#include <menix/util/list.h>

#ifdef CONFIG_acpi
#include <menix/drv/acpi/acpi.h>
#include <menix/drv/pci/pci_acpi.h>
#endif

void kernel_main(BootInfo* info)
{
	// Say hello to the console.
	kmesg("menix v" CONFIG_version " (" CONFIG_arch ")\n");

	vfs_init();
#ifdef CONFIG_pci
	pci_init();
#endif
#ifdef CONFIG_acpi
	acpi_init(info->acpi_rsdp);
	// The PCI subsystem depends on ACPI. Now we can enable it.
#ifdef CONFIG_pci
	pci_init_acpi();
#endif
#endif

	// Initialize all modules.
	module_init(info);

	// TODO: Call init program.
	// exec("/usr/init");

	// Clean up all modules.
	module_fini();

#ifdef CONFIG_pci
	pci_fini();
#endif

	kmesg("shutdown\n");	// Say goodbye.
	arch_shutdown(info);	// Shut the system down safely.
	arch_stop(info);		// If we're still here, something went wrong. In that case, just try to stop.
}
