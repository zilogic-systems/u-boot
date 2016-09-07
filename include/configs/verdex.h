/*
 * Gumstix Verdex Board Support
 *
 * Copyright (C) 2016 Zilogic Systems <code@zilogic.com>
 *
 * Based on Toradex Colibri PXA270 Support
 *
 * Copyright (C) 2010 Marek Vasut <marek.vasut@gmail.com>
 * Copyright (C) 2015 Marcel Ziswiler <marcel@ziswiler.com>
 *
 * SPDX-License-Identifier:	GPL-2.0+
 */

#ifndef	__CONFIG_H
#define	__CONFIG_H

/*
 * High Level Board Configuration Options
 */
#define	CONFIG_CPU_PXA27X		1	/* Marvell PXA270 CPU */
#define	CONFIG_SYS_TEXT_BASE		0x0

/* Avoid overwriting factory configuration block */
#define CONFIG_BOARD_SIZE_LIMIT		0x40000

/* We will never enable dcache because we have to setup MMU first */
#define CONFIG_SYS_DCACHE_OFF

/*
 * Environment settings
 */
#define	CONFIG_ENV_OVERWRITE
#define	CONFIG_SYS_MALLOC_LEN		(128 * 1024)
#define	CONFIG_ARCH_CPU_INIT
#define	CONFIG_BOOTCOMMAND						\
	"dhcp 0xa1000000 uImage;"               			\
	"tftp 0xa2000000 uRamdisk;"					\
	"tftp 0xa3000000 pxa27x-verdex.dtb;"					\
	"bootm 0xa1000000 0xa2000000 0xa3000000"
#define	CONFIG_BOOTARGS			"console=ttyS0,115200 root=/dev/ram0 ip=dhcp"
#define	CONFIG_TIMESTAMP
#define	CONFIG_CMDLINE_TAG
#define	CONFIG_SETUP_MEMORY_TAGS
#define	CONFIG_LZMA			/* LZMA compression support */

/*
 * Serial Console Configuration
 */
#define	CONFIG_PXA_SERIAL
#define	CONFIG_FFUART			1
#define CONFIG_CONS_INDEX		3
#define	CONFIG_BAUDRATE			115200

/*
 * Bootloader Components Configuration
 */
#define	CONFIG_CMD_ENV

/*
 * Networking Configuration
 */
#ifdef	CONFIG_CMD_NET

#define	CONFIG_SMC91111  		1
#define CONFIG_SMC91111_BASE		0x04000300
#define CONFIG_SMC91111_EXT_PHY
#define	CONFIG_NET_RETRY_COUNT		10

#define	CONFIG_BOOTP_BOOTFILESIZE
#define	CONFIG_BOOTP_BOOTPATH
#define	CONFIG_BOOTP_GATEWAY
#define	CONFIG_BOOTP_HOSTNAME
#endif

#undef	CONFIG_SYS_LONGHELP		/* Saves 10 KB */
#define	CONFIG_SYS_CBSIZE		256
#define	CONFIG_SYS_PBSIZE		\
	(CONFIG_SYS_CBSIZE+sizeof(CONFIG_SYS_PROMPT)+16)
#define	CONFIG_SYS_MAXARGS		16
#define	CONFIG_SYS_BARGSIZE		CONFIG_SYS_CBSIZE
#define	CONFIG_SYS_DEVICE_NULLDEV	1
#define	CONFIG_CMDLINE_EDITING		1
#define	CONFIG_AUTO_COMPLETE		1

/*
 * Clock Configuration
 */
#define	CONFIG_SYS_CPUSPEED		0x290		/* 520MHz */

/*
 * DRAM Map
 */
#define	CONFIG_NR_DRAM_BANKS		1		/* We have 1 bank of DRAM */
#define	PHYS_SDRAM_1			0xa0000000	/* SDRAM Bank #1 */
#define	PHYS_SDRAM_1_SIZE		0x08000000	/* 128 MB */

#define	CONFIG_SYS_DRAM_BASE		0xa0000000	/* CS0 */
#define	CONFIG_SYS_DRAM_SIZE		0x08000000	/* 128 MB DRAM */

#define CONFIG_SYS_MEMTEST_START	0xa0400000	/* memtest works on */
#define CONFIG_SYS_MEMTEST_END		0xa0800000	/* 4 ... 8 MB in DRAM */

#define	CONFIG_SYS_LOAD_ADDR		PHYS_SDRAM_1
#define CONFIG_SYS_SDRAM_BASE		PHYS_SDRAM_1
#define	CONFIG_SYS_INIT_SP_ADDR		0x5c010000

/*
 * NOR FLASH
 */
#ifdef	CONFIG_CMD_FLASH
#define	PHYS_FLASH_1			0x00000000	/* Flash Bank #1 */
#define	PHYS_FLASH_SIZE			0x02000000	/* 32 MB */
#define	CONFIG_SYS_FLASH_BASE		PHYS_FLASH_1

#define	CONFIG_SYS_FLASH_CFI
#define	CONFIG_FLASH_CFI_DRIVER		1
#define	CONFIG_SYS_FLASH_CFI_WIDTH      FLASH_CFI_16BIT

#define	CONFIG_SYS_MAX_FLASH_SECT	(4 + 255)
#define	CONFIG_SYS_MAX_FLASH_BANKS	1

#define	CONFIG_SYS_FLASH_ERASE_TOUT	(25 * CONFIG_SYS_HZ)
#define	CONFIG_SYS_FLASH_WRITE_TOUT	(25 * CONFIG_SYS_HZ)
#define	CONFIG_SYS_FLASH_LOCK_TOUT	(25 * CONFIG_SYS_HZ)
#define	CONFIG_SYS_FLASH_UNLOCK_TOUT	(25 * CONFIG_SYS_HZ)

#define	CONFIG_SYS_FLASH_USE_BUFFER_WRITE	1
#define	CONFIG_SYS_FLASH_PROTECTION		1

#define CONFIG_ENV_IS_IN_FLASH		1

#else	/* No flash */
#define	CONFIG_SYS_NO_FLASH
#define	CONFIG_ENV_IS_NOWHERE
#endif

#define	CONFIG_SYS_MONITOR_BASE		0x0
#define	CONFIG_SYS_MONITOR_LEN		0x40000

/* Skip factory configuration block */
#define	CONFIG_ENV_ADDR			\
			(CONFIG_SYS_MONITOR_BASE + CONFIG_SYS_MONITOR_LEN + 0x40000)
#define	CONFIG_ENV_SIZE			0x40000
#define	CONFIG_ENV_SECT_SIZE		0x40000

/*
 * GPIO settings
 */
#define	CONFIG_SYS_GPSR0_VAL	0x00000000
#define	CONFIG_SYS_GPSR1_VAL	0x00020000
#define	CONFIG_SYS_GPSR2_VAL	0x0002c000
#define	CONFIG_SYS_GPSR3_VAL	0x00000000

#define	CONFIG_SYS_GPCR0_VAL	0x00000000
#define	CONFIG_SYS_GPCR1_VAL	0x00000000
#define	CONFIG_SYS_GPCR2_VAL	0x00000000
#define	CONFIG_SYS_GPCR3_VAL	0x00000000

#define	CONFIG_SYS_GPDR0_VAL	0x00000000
#define	CONFIG_SYS_GPDR1_VAL	0x00008000
#define	CONFIG_SYS_GPDR2_VAL	0x00000000
#define	CONFIG_SYS_GPDR3_VAL	0x00000000

#define	CONFIG_SYS_GAFR0_L_VAL	0x00000000
#define	CONFIG_SYS_GAFR0_U_VAL	0x00000000
#define	CONFIG_SYS_GAFR1_L_VAL	0x10000000
#define	CONFIG_SYS_GAFR1_U_VAL	0x00000000
#define	CONFIG_SYS_GAFR2_L_VAL	0x00000000
#define	CONFIG_SYS_GAFR2_U_VAL	0x00000000
#define	CONFIG_SYS_GAFR3_L_VAL	0x00000000
#define	CONFIG_SYS_GAFR3_U_VAL	0x00000000

#define	CONFIG_SYS_PSSR_VAL	0x30

/*
 * Clock settings
 */
#define	CONFIG_SYS_CKEN		0x00500240
#define	CONFIG_SYS_CCCR		0x02000290

/*
 * Memory settings
 */
#define	CONFIG_SYS_MSC0_VAL	0x9ee1c5f2
#define	CONFIG_SYS_MSC1_VAL	0x9ee1f994
#define	CONFIG_SYS_MSC2_VAL	0x9ee19ee1
#define	CONFIG_SYS_MDCNFG_VAL	0x090009c9
#define	CONFIG_SYS_MDREFR_VAL	0x2003a031
#define	CONFIG_SYS_MDMRS_VAL	0x00220022
#define	CONFIG_SYS_FLYCNFG_VAL	0x00010001
#define	CONFIG_SYS_SXCNFG_VAL	0x40044004

/*
 * FIXME: Check if this required.
 * PCMCIA and CF Interfaces
 */
#define	CONFIG_SYS_MECR_VAL	0x00000000
#define	CONFIG_SYS_MCMEM0_VAL	0x00028307
#define	CONFIG_SYS_MCMEM1_VAL	0x00014307
#define	CONFIG_SYS_MCATT0_VAL	0x00038787
#define	CONFIG_SYS_MCATT1_VAL	0x0001c787
#define	CONFIG_SYS_MCIO0_VAL	0x0002830f
#define	CONFIG_SYS_MCIO1_VAL	0x0001430f

#include "pxa-common.h"

#endif /* __CONFIG_H */
