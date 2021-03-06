/*
 * Copyright (C) 2012 Atmel Corporation
 *
 * Configuation settings for the AT91SAM9X5EK board.
 *
 * SPDX-License-Identifier:	GPL-2.0+
 */

#ifndef __CONFIG_H__
#define __CONFIG_H__

#include <asm/hardware.h>

#define CONFIG_SYS_TEXT_BASE		0x26f00000
/* Enable the watchdog */
#define CONFIG_AT91SAM9_WATCHDOG
#define CONFIG_HW_WATCHDOG
#define CONFIG_USE_SPIFLASH
#define CONFIG_SPI_FLASH_MTD

#define CONFIG_SPLASHSCREEN
#define CONFIG_CMD_BMP
#define MTDIDS_DEFAULT "nor0=spi32766.0"
#define MTDPARTS_DEFAULT "mtdparts=spi32766.0:256k(bootstrap),512k(uboot),"		\
	"256k(env),256k(dtb),6M(kernel),58M(rootfs),20M(hach),2M(jail),-(var) " 


//default settings
#define CONFIG_ETHADDR     00:0e:1c:99:99:99
#define CONFIG_OVERWRITE_ETHADDR_ONCE 1
/* include version env variable */
#define CONFIG_VERSION_VARIABLE	1	
#define CONFIG_SERVERIP    192.168.1.1
#define CONFIG_IPADDR      192.168.1.2
#define CONFIG_NETMASK     255.255.255.0 
#define CONFIG_HOSTNAME    CM130
/* user-defined env variables */
//#define CONFIG_EXTRA_ENV_SETTINGS "ethact=macb0\0" "stderr=serial\0" "stdin=serial\0" "stdout=serial\0" "serial_num=00000001\0"

//#define CONFIG_OF_CONTROL
//#define CONFIG_FIT
//#define CONFIG_FIT_SIGNATURE
//#define CONFIG_RSA
//#define CONFIG_FIT_VERBOSE

/* ARM asynchronous clock */
#define CONFIG_SYS_AT91_SLOW_CLOCK	32768
#define CONFIG_SYS_AT91_MAIN_CLOCK	12000000	/* 12 MHz crystal */

#define CONFIG_AT91SAM9X5EK

#define CONFIG_CMDLINE_TAG		/* enable passing of ATAGs */
#define CONFIG_SETUP_MEMORY_TAGS
#define CONFIG_INITRD_TAG
#define CONFIG_SKIP_LOWLEVEL_INIT
#define CONFIG_BOARD_EARLY_INIT_F
#define CONFIG_DISPLAY_CPUINFO

#define CONFIG_CMD_BOOTZ
#define CONFIG_OF_LIBFDT

#define CONFIG_SYS_GENERIC_BOARD

/* general purpose I/O */
#define CONFIG_ATMEL_LEGACY		/* required until (g)pio is fixed */
#define CONFIG_AT91_GPIO

/* serial console */
#define CONFIG_ATMEL_USART
#define CONFIG_USART_BASE	ATMEL_BASE_DBGU
#define CONFIG_USART_ID		ATMEL_ID_SYS

/* LCD */
#define CONFIG_LCD
#define LCD_BPP			LCD_COLOR16
#define LCD_OUTPUT_BPP		24
//#define CONFIG_LCD_LOGO
//#define CONFIG_LCD_INFO
//#define CONFIG_LCD_INFO_BELOW_LOGO
//#define CONFIG_SYS_WHITE_ON_BLACK
#define CONFIG_ATMEL_HLCD
#define CONFIG_ATMEL_LCD_RGB565
#define CONFIG_SYS_CONSOLE_IS_IN_ENV

#define CONFIG_BOOTDELAY	3

/*
 * BOOTP options
 */
#define CONFIG_BOOTP_BOOTFILESIZE
#define CONFIG_BOOTP_BOOTPATH
#define CONFIG_BOOTP_GATEWAY
#define CONFIG_BOOTP_HOSTNAME

/* no NOR flash */
#define CONFIG_SYS_NO_FLASH

/*
 * Command line configuration.
 */
#include <config_cmd_default.h>
#undef CONFIG_CMD_FPGA
#undef CONFIG_CMD_IMI

#define CONFIG_CMD_PING
#define CONFIG_CMD_DHCP
#define CONFIG_CMD_NAND
#define CONFIG_CMD_SF
#define CONFIG_CMD_MMC
#define CONFIG_CMD_FAT
#define CONFIG_CMD_USB
#define CONFIG_CMD_JFFS2
#define CONFIG_SYS_JFFS2_FIRST_BANK 0
#define CONFIG SYS_JFFS2_FIRST_SECTOR 6

/*
 * define CONFIG_USB_EHCI to enable USB Hi-Speed (aka 2.0)
 * NB: in this case, USB 1.1 devices won't be recognized.
 */


/* SDRAM */
#define CONFIG_NR_DRAM_BANKS		1
#define CONFIG_SYS_SDRAM_BASE		0x20000000
#define CONFIG_SYS_SDRAM_SIZE		0x08000000	/* 128 megs */

#define CONFIG_SYS_INIT_SP_ADDR \
	(CONFIG_SYS_SDRAM_BASE + 4 * 1024 - GENERATED_GBL_DATA_SIZE)

/* DataFlash */
#ifdef CONFIG_CMD_SF
#define CONFIG_ATMEL_SPI
#define CONFIG_SPI_FLASH
#define CONFIG_SPI_FLASH_ATMEL
#define CONFIG_SPI_FLASH_SPANSION
#define CONFIG_SPI_FLASH_STMICRO

#define CONFIG_SPI_FLASH_BAR
#define CONFIG_SF_DEFAULT_SPEED		50000000
#endif

/* NAND flash */
#ifdef CONFIG_CMD_NAND
#define CONFIG_NAND_ATMEL
#define CONFIG_SYS_MAX_NAND_DEVICE	1
#define CONFIG_SYS_NAND_BASE		0x40000000
#define CONFIG_SYS_NAND_DBW_8		1
/* our ALE is AD21 */
#define CONFIG_SYS_NAND_MASK_ALE	(1 << 21)
/* our CLE is AD22 */
#define CONFIG_SYS_NAND_MASK_CLE	(1 << 22)
#define CONFIG_SYS_NAND_ENABLE_PIN	AT91_PIN_PD4
#define CONFIG_SYS_NAND_READY_PIN	AT91_PIN_PD5

/* PMECC & PMERRLOC */
#define CONFIG_ATMEL_NAND_HWECC		1
#define CONFIG_ATMEL_NAND_HW_PMECC	1
#define CONFIG_PMECC_CAP		2
#define CONFIG_PMECC_SECTOR_SIZE	512

#define CONFIG_CMD_NAND_TRIMFFS

#define CONFIG_MTD_DEVICE
#define CONFIG_CMD_MTDPARTS
#define CONFIG_MTD_PARTITIONS
#define CONFIG_RBTREE
#define CONFIG_LZO
//#define CONFIG_CMD_UBI
//#define CONFIG_CMD_UBIFS
#endif

/* MMC */
#ifdef CONFIG_CMD_MMC
#define CONFIG_MMC
#define CONFIG_GENERIC_MMC
#define CONFIG_GENERIC_ATMEL_MCI
#endif

/* FAT */
#ifdef CONFIG_CMD_FAT
#define CONFIG_DOS_PARTITION
#endif

/* Ethernet */
#define CONFIG_MACB
#define CONFIG_RMII
#define CONFIG_NET_RETRY_COUNT		20
#define CONFIG_MACB_SEARCH_PHY
#define CONFIG_CMD_MII
//#define CONFIG_PHYLIB
//#define CONFIG_PHY_MICREL
/* USB */
#ifdef CONFIG_CMD_USB
#ifdef CONFIG_USB_EHCI
#define CONFIG_USB_EHCI_ATMEL
#define CONFIG_SYS_USB_EHCI_MAX_ROOT_PORTS	2
#else
#define CONFIG_USB_ATMEL
#define CONFIG_USB_ATMEL_CLK_SEL_UPLL
#define CONFIG_USB_OHCI_NEW
#define CONFIG_SYS_USB_OHCI_CPU_INIT
#define CONFIG_SYS_USB_OHCI_REGS_BASE		ATMEL_BASE_OHCI
#define CONFIG_SYS_USB_OHCI_SLOT_NAME		"at91sam9x5"
#define CONFIG_SYS_USB_OHCI_MAX_ROOT_PORTS	3
#endif
#define CONFIG_USB_STORAGE
#endif

#define CONFIG_SYS_LOAD_ADDR		0x22000000	/* load address */

#define CONFIG_SYS_MEMTEST_START	CONFIG_SYS_SDRAM_BASE
#define CONFIG_SYS_MEMTEST_END		0x26e00000

#ifdef CONFIG_SYS_USE_NANDFLASH
/* bootstrap + u-boot + env + linux in nandflash */
#define CONFIG_ENV_IS_IN_NAND
#define CONFIG_ENV_OFFSET		0xc0000
#define CONFIG_ENV_OFFSET_REDUND	0x100000
#define CONFIG_ENV_SIZE		0x20000		/* 1 sector = 128 kB */
#define CONFIG_BOOTCOMMAND	"nand read " \
				"0x21000000 0x180000 0x80000; " \
				"nand read " \
				"0x22000000 0x200000 0x600000; " \
				"bootz 0x22000000 - 0x21000000"
#elif defined(CONFIG_SYS_USE_SPIFLASH)
/* bootstrap + u-boot + env + linux in spi flash */
#define CONFIG_ENV_IS_IN_SPI_FLASH
#define CONFIG_ENV_OFFSET	0x4200
#define CONFIG_ENV_SIZE		0x4200
//doesn't support backup env block - ry
//#define CONFIG_ENV_OFFSET_REDUND 0x8000
#define CONFIG_ENV_SECT_SIZE	0x1000
#define CONFIG_ENV_SPI_MAX_HZ	30000000
#define CONFIG_BOOTCOMMAND	"sf probe 0; " \
				"sf read 0x22000000 0x100000 0x300000; " \
				"bootm 0x22000000"
#elif defined(CONFIG_SYS_USE_DATAFLASH)
/* bootstrap + u-boot + env + linux in data flash */
#define CONFIG_ENV_IS_IN_SPI_FLASH
#define CONFIG_ENV_OFFSET	0xC0000
#define CONFIG_ENV_SIZE		0x40000
//doesn't support backup env block - ry
//#define CONFIG_ENV_OFFSET_REDUND 0x8000
#define CONFIG_ENV_SECT_SIZE	0x40000
#define CONFIG_ENV_SPI_MAX_HZ	66000000
#define CONFIG_BOOTCOMMAND	"sf probe 0; " \
				"sf read 0x22000000 0x140000 0x600000; sf read 0x21000000 0x100000 0x40000;" \
				"bootz 0x22000000 - 0x21000000"
#else /* CONFIG_SYS_USE_MMC */
/* bootstrap + u-boot + env + linux in mmc */
#define CONFIG_ENV_IS_IN_FAT
#define CONFIG_FAT_WRITE
#define FAT_ENV_INTERFACE	"mmc"
#define FAT_ENV_FILE		"uboot.env"
#define FAT_ENV_DEVICE_AND_PART	"0"
#define CONFIG_ENV_SIZE		0x40000
#define CONFIG_BOOTCOMMAND      "fatload mmc 0 0x21000000 at91sam9g35ek.dtb; fatload mmc 0 0x22000000 zImage; bootz 0x22000000 - 0x21000000"
#endif

#ifdef CONFIG_SYS_USE_MMC
#define CONFIG_BOOTARGS		"mem=128M console=ttyS0,115200 " \
				"mtdparts=spi32766.0:256k(bootstrap),512k(uboot),"		\
				"256k(env),256k(dtb),6M(kernel),58M(rootfs),20M(hach),2M(jail),-(var) "  \
				"root=/dev/mmcblk0p2 " \
				"rw rootfstype=ext4 rootwait"

#elif defined(CONFIG_SYS_USE_DATAFLASH)
#define CONFIG_BOOTARGS							\
	"console=ttyS0,115200 earlyprintk "				\
	"mtdparts=spi32766.0:256k(bootstrap),512k(uboot),"		\
	"256k(env),256k(dtb),6M(kernel),58M(rootfs),20M(hach),2M(jail),-(var) " \
	"rootfstype=squashfs  root=/dev/mtdblock5"
#else
#define CONFIG_BOOTARGS							\
	"console=ttyS0,115200 earlyprintk "				\
	"mtdparts=atmel_nand:256k(bootstrap),512k(uboot),"		\
	"256k(env),256k(env_redundant),256k(spare),"			\
	"512k(dtb),6M(kernel),-(rootfs) "				\
	"rootfstype=ubifs ubi.mtd=7 root=ubi0:rootfs rw"
#endif

#define CONFIG_BAUDRATE		115200

#define CONFIG_SYS_PROMPT	"U-Boot> "
#define CONFIG_SYS_CBSIZE	256
#define CONFIG_SYS_MAXARGS	16
#define CONFIG_SYS_PBSIZE	(CONFIG_SYS_CBSIZE + sizeof(CONFIG_SYS_PROMPT) \
					+ 16)
#define CONFIG_SYS_LONGHELP
#define CONFIG_CMDLINE_EDITING
#define CONFIG_AUTO_COMPLETE
#define CONFIG_SYS_HUSH_PARSER


/*
 * Size of malloc() pool
 */
#define CONFIG_SYS_MALLOC_LEN		(512 * 1024 + 0x1000)

#endif
