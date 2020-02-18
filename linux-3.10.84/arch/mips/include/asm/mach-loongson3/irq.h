#ifndef __ASM_MACH_LOONGSON3_IRQ_H_
#define __ASM_MACH_LOONGSON3_IRQ_H_

#include <boot_param.h>

/* cpu core interrupt numbers */
#define MIPS_CPU_IRQ_BASE 56

#ifdef CONFIG_CPU_LOONGSON3

#define LOONGSON_UART_IRQ   (MIPS_CPU_IRQ_BASE + 2) /* uart */
#define LOONGSON_I8259_IRQ  (MIPS_CPU_IRQ_BASE + 3) /* i8259 */
#define LOONGSON_TIMER_IRQ  (MIPS_CPU_IRQ_BASE + 7) /* cpu timer */

#define LOONGSON_HT1_CFG_BASE		ht_control_base
#define LOONGSON_HT1_INT_VECTOR_BASE	LOONGSON_HT1_CFG_BASE + 0x80
#define LOONGSON_HT1_INT_EN_BASE	LOONGSON_HT1_CFG_BASE + 0xa0
#define LOONGSON_HT1_INT_VECTOR(n)	LOONGSON3_REG32(LOONGSON_HT1_INT_VECTOR_BASE, 4 * n)
#define LOONGSON_HT1_INTN_EN(n)		LOONGSON3_REG32(LOONGSON_HT1_INT_EN_BASE, 4 * n)

#define LOONGSON_INT_ROUTER_OFFSET	0x1400
#define LOONGSON_INT_ROUTER_INTEN	LOONGSON3_REG32(LOONGSON3_REG_BASE, LOONGSON_INT_ROUTER_OFFSET + 0x24)
#define LOONGSON_INT_ROUTER_INTENSET	LOONGSON3_REG32(LOONGSON3_REG_BASE, LOONGSON_INT_ROUTER_OFFSET + 0x28)
#define LOONGSON_INT_ROUTER_INTENCLR	LOONGSON3_REG32(LOONGSON3_REG_BASE, LOONGSON_INT_ROUTER_OFFSET + 0x2c)
#define LOONGSON_INT_ROUTER_ENTRY(n)	LOONGSON3_REG8(LOONGSON3_REG_BASE, LOONGSON_INT_ROUTER_OFFSET + n)
#define LOONGSON_INT_ROUTER_LPC		LOONGSON_INT_ROUTER_ENTRY(0x0b)
#define LOONGSON_INT_ROUTER_HT1(n)	LOONGSON_INT_ROUTER_ENTRY(n + 0x18)

#define LOONGSON_INT_CORE0_INT0		0x11 /* route to int 0 of core 0 */
#define LOONGSON_INT_CORE0_INT1		0x21 /* route to int 1 of core 0 */

#define LOONGSON_INT_COREx_INTy(x, y)	(1<<(x) | 1<<(y+4))	/* route to int y of core x */

#define LOCAL_IO_BASE			0x1fe00000
#define LS3_LPC_INT_CTRL_REG	*(volatile unsigned int *)CKSEG1ADDR(LOCAL_IO_BASE + 0x0200)
#define LS3_LPC_INT_ENA_REG	*(volatile unsigned int *)CKSEG1ADDR(LOCAL_IO_BASE + 0x0204)
#define LS3_LPC_INT_STATUS_REG	*(volatile unsigned int *)CKSEG1ADDR(LOCAL_IO_BASE + 0x0208)
#define LS3_LPC_INT_CLE_REG	*(volatile unsigned int *)CKSEG1ADDR(LOCAL_IO_BASE + 0x020c)
#endif

#include_next <irq.h>
#endif /* __ASM_MACH_LOONGSON3_IRQ_H_ */