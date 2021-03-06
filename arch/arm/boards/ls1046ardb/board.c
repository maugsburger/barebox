// SPDX-License-Identifier: GPL-2.0+

#include <common.h>
#include <init.h>
#include <envfs.h>
#include <asm/memory.h>
#include <linux/sizes.h>
#include <linux/clk.h>
#include <linux/clkdev.h>
#include <asm/system.h>

static int rdb_mem_init(void)
{
	if (!of_machine_is_compatible("fsl,ls1046a-rdb"))
		return 0;

	arm_add_mem_device("ram0", 0x80000000, 0x80000000);
	arm_add_mem_device("ram1", 0x880000000, 3ULL * SZ_2G);

	printf("Current EL: %d\n", current_el());

	return 0;
}
mem_initcall(rdb_mem_init);

static int rdb_postcore_init(void)
{
	if (!of_machine_is_compatible("fsl,ls1046a-rdb"))
		return 0;

	defaultenv_append_directory(defaultenv_ls1046ardb);

	return 0;
}

postcore_initcall(rdb_postcore_init);
