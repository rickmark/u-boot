/* SPDX-License-Identifier: GPL-2.0+ */
/*
 * Common header file for U-Boot
 *
 * This file still includes quite a few headers that should be included
 * individually as needed. Patches to remove things are welcome.
 *
 * (C) Copyright 2000-2009
 * Wolfgang Denk, DENX Software Engineering, wd@denx.de.
 */

#ifndef __COMMON_H_
#define __COMMON_H_	1

#ifndef __ASSEMBLY__		/* put C only stuff in this section */
#include <config.h>
#include <errno.h>
#include <time.h>
#include <linux/types.h>
#include <linux/printk.h>
#include <linux/string.h>
#include <stdarg.h>
#include <stdio.h>
#include <linux/kernel.h>
#include <asm/u-boot.h> /* boot information for Linux kernel */
#include <display_options.h>
#include <vsprintf.h>
#endif	/* __ASSEMBLY__ */

#ifndef CONFIG_ENV_IS_DYNAMIC
#if defined(CONFIG_ENV_IS_IN_NAND)
#define env_init		env_nand_init
#define env_saveenv		env_nand_saveenv
#define readenv			env_nand_readenv
#define env_relocate_spec	env_nand_relocate_spec

#elif defined(CONFIG_ENV_IS_IN_SPI_FLASH)
#define env_init 		env_sf_init
#define env_saveenv 		env_sf_saveenv
#define env_relocate_spec	env_sf_relocate_spec

#elif defined(CONFIG_ENV_IS_NOWHERE)
#define env_init 		env_nowhere_init
#define env_relocate_spec	env_nowhere_relocate_spec

#endif

#endif /* CONFIG_ENV_IS_DYNAMIC */


/* Pull in stuff for the build system */
#ifdef DO_DEPS_ONLY
# include <env_internal.h>
#endif

#endif	/* __COMMON_H_ */
