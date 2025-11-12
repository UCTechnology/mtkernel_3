/*
 *----------------------------------------------------------------------
 *    micro T-Kernel 3.00.08.B1
 *
 *    Copyright (C) 2006-2025 by Ken Sakamura.
 *    This software is distributed under the T-License 2.2.
 *----------------------------------------------------------------------
 *
 *    Released by TRON Forum(http://www.tron.org) at 2025/11.
 *
 *----------------------------------------------------------------------
 */

/*
 *	sysdef.h
 *
 *	System dependencies definition (NUCLEO-STM32N657 depended)
 *	Included also from assembler program.
 */

#ifndef __SYS_SYSDEF_DEPEND_H__
#define __SYS_SYSDEF_DEPEND_H__

/* TrustZone defined */
#define TRUSTZONE_ENABLE	(CNF_TZ_ENABLE)				// TrustZone Enabled
#define TRUSTZONE_SECURE	(CNF_TZ_ENABLE && CNF_TZ_STATE)		// OS in Secure status
#define TRUSTZONE_NONSECURE	(CNF_TZ_ENABLE && !CNF_TZ_STATE)	// OS in Non-Secure status

// Enable Secure Calls from Tasks
#define TRUSTZONE_SCALL	(TRUSTZONE_NONSECURE && CNF_TZ_SCALL)

/* ------------------------------------------------------------------------ */
/* Clock frequency
 */
#ifndef _in_asm_source_
IMPORT UW knl_sysclk;	// System clock

#define	SYSCLK			knl_sysclk		// System clock

#define SYST_CLK_SRC		0x00000000	/* Use Systick clock (75MHz) */

#define TMCLK			(75)		/* System timer clock input (MHz) */
#define TMCLK_KHz		(TMCLK * 1000)	/* System timer clock input (kHz) */

#endif

/* CPU-dependent definition */
#include "../cpu/stm32n6/sysdef.h"

#endif /* __SYS_SYSDEF_DEPEND_H__ */
