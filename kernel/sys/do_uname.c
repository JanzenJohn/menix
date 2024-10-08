// uname syscall

#include <menix/abi.h>
#include <menix/common.h>
#include <menix/sys/syscall.h>

#include <string.h>

SYSCALL_IMPL(uname, struct utsname* buffer)
{
	// If we have no buffer to write to, fail.
	if (buffer == NULL)
		return -1;

	fixed_strncpy(buffer->sysname, "menix");
	// TODO: Get actual network node.
	fixed_strncpy(buffer->nodename, "localhost");
	fixed_strncpy(buffer->release, CONFIG_release);
	fixed_strncpy(buffer->version, CONFIG_version);
	fixed_strncpy(buffer->machine, CONFIG_arch);

	return 0;
}
