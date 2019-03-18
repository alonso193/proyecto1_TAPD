/*******************************************************************************
* File Name: cyfitter.h
* 
* PSoC Creator  4.2
*
* Description:
* 
* This file is automatically generated by PSoC Creator.
*
********************************************************************************
* Copyright (c) 2007-2018 Cypress Semiconductor.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
********************************************************************************/

#ifndef INCLUDED_CYFITTER_H
#define INCLUDED_CYFITTER_H
#include "cydevice.h"
#include "cydevice_trm.h"

/* DMA */
#define DMA__DRQ_CTL CYREG_IDMUX_DRQ_CTL2
#define DMA__DRQ_NUMBER 10u
#define DMA__NUMBEROF_TDS 0u
#define DMA__PRIORITY 2u
#define DMA__TERMIN_EN 0u
#define DMA__TERMIN_SEL 0u
#define DMA__TERMOUT0_EN 0u
#define DMA__TERMOUT0_SEL 0u
#define DMA__TERMOUT1_EN 0u
#define DMA__TERMOUT1_SEL 0u
#define DMA_CHANNELS_USED__MASK0 0x00000403u

/* isr */
#define isr__INTC_CLR_EN_REG CYREG_NVIC_CLRENA0
#define isr__INTC_CLR_PD_REG CYREG_NVIC_CLRPEND0
#define isr__INTC_MASK 0x10000000u
#define isr__INTC_NUMBER 28u
#define isr__INTC_PRIOR_NUM 7u
#define isr__INTC_PRIOR_REG CYREG_NVIC_PRI_28
#define isr__INTC_SET_EN_REG CYREG_NVIC_SETENA0
#define isr__INTC_SET_PD_REG CYREG_NVIC_SETPEND0

/* P0_1 */
#define P0_1__0__INTTYPE CYREG_PICU0_INTTYPE1
#define P0_1__0__MASK 0x02u
#define P0_1__0__PC CYREG_PRT0_PC1
#define P0_1__0__PORT 0u
#define P0_1__0__SHIFT 1u
#define P0_1__AG CYREG_PRT0_AG
#define P0_1__AMUX CYREG_PRT0_AMUX
#define P0_1__BIE CYREG_PRT0_BIE
#define P0_1__BIT_MASK CYREG_PRT0_BIT_MASK
#define P0_1__BYP CYREG_PRT0_BYP
#define P0_1__CTL CYREG_PRT0_CTL
#define P0_1__DM0 CYREG_PRT0_DM0
#define P0_1__DM1 CYREG_PRT0_DM1
#define P0_1__DM2 CYREG_PRT0_DM2
#define P0_1__DR CYREG_PRT0_DR
#define P0_1__INP_DIS CYREG_PRT0_INP_DIS
#define P0_1__INTTYPE_BASE CYDEV_PICU_INTTYPE_PICU0_BASE
#define P0_1__LCD_COM_SEG CYREG_PRT0_LCD_COM_SEG
#define P0_1__LCD_EN CYREG_PRT0_LCD_EN
#define P0_1__MASK 0x02u
#define P0_1__PORT 0u
#define P0_1__PRT CYREG_PRT0_PRT
#define P0_1__PRTDSI__CAPS_SEL CYREG_PRT0_CAPS_SEL
#define P0_1__PRTDSI__DBL_SYNC_IN CYREG_PRT0_DBL_SYNC_IN
#define P0_1__PRTDSI__OE_SEL0 CYREG_PRT0_OE_SEL0
#define P0_1__PRTDSI__OE_SEL1 CYREG_PRT0_OE_SEL1
#define P0_1__PRTDSI__OUT_SEL0 CYREG_PRT0_OUT_SEL0
#define P0_1__PRTDSI__OUT_SEL1 CYREG_PRT0_OUT_SEL1
#define P0_1__PRTDSI__SYNC_OUT CYREG_PRT0_SYNC_OUT
#define P0_1__PS CYREG_PRT0_PS
#define P0_1__SHIFT 1u
#define P0_1__SLW CYREG_PRT0_SLW

/* P2_2 */
#define P2_2__0__INTTYPE CYREG_PICU2_INTTYPE2
#define P2_2__0__MASK 0x04u
#define P2_2__0__PC CYREG_PRT2_PC2
#define P2_2__0__PORT 2u
#define P2_2__0__SHIFT 2u
#define P2_2__AG CYREG_PRT2_AG
#define P2_2__AMUX CYREG_PRT2_AMUX
#define P2_2__BIE CYREG_PRT2_BIE
#define P2_2__BIT_MASK CYREG_PRT2_BIT_MASK
#define P2_2__BYP CYREG_PRT2_BYP
#define P2_2__CTL CYREG_PRT2_CTL
#define P2_2__DM0 CYREG_PRT2_DM0
#define P2_2__DM1 CYREG_PRT2_DM1
#define P2_2__DM2 CYREG_PRT2_DM2
#define P2_2__DR CYREG_PRT2_DR
#define P2_2__INP_DIS CYREG_PRT2_INP_DIS
#define P2_2__INTTYPE_BASE CYDEV_PICU_INTTYPE_PICU2_BASE
#define P2_2__LCD_COM_SEG CYREG_PRT2_LCD_COM_SEG
#define P2_2__LCD_EN CYREG_PRT2_LCD_EN
#define P2_2__MASK 0x04u
#define P2_2__PORT 2u
#define P2_2__PRT CYREG_PRT2_PRT
#define P2_2__PRTDSI__CAPS_SEL CYREG_PRT2_CAPS_SEL
#define P2_2__PRTDSI__DBL_SYNC_IN CYREG_PRT2_DBL_SYNC_IN
#define P2_2__PRTDSI__OE_SEL0 CYREG_PRT2_OE_SEL0
#define P2_2__PRTDSI__OE_SEL1 CYREG_PRT2_OE_SEL1
#define P2_2__PRTDSI__OUT_SEL0 CYREG_PRT2_OUT_SEL0
#define P2_2__PRTDSI__OUT_SEL1 CYREG_PRT2_OUT_SEL1
#define P2_2__PRTDSI__SYNC_OUT CYREG_PRT2_SYNC_OUT
#define P2_2__PS CYREG_PRT2_PS
#define P2_2__SHIFT 2u
#define P2_2__SLW CYREG_PRT2_SLW

/* Pin_1 */
#define Pin_1__0__INTTYPE CYREG_PICU0_INTTYPE0
#define Pin_1__0__MASK 0x01u
#define Pin_1__0__PC CYREG_PRT0_PC0
#define Pin_1__0__PORT 0u
#define Pin_1__0__SHIFT 0u
#define Pin_1__AG CYREG_PRT0_AG
#define Pin_1__AMUX CYREG_PRT0_AMUX
#define Pin_1__BIE CYREG_PRT0_BIE
#define Pin_1__BIT_MASK CYREG_PRT0_BIT_MASK
#define Pin_1__BYP CYREG_PRT0_BYP
#define Pin_1__CTL CYREG_PRT0_CTL
#define Pin_1__DM0 CYREG_PRT0_DM0
#define Pin_1__DM1 CYREG_PRT0_DM1
#define Pin_1__DM2 CYREG_PRT0_DM2
#define Pin_1__DR CYREG_PRT0_DR
#define Pin_1__INP_DIS CYREG_PRT0_INP_DIS
#define Pin_1__INTTYPE_BASE CYDEV_PICU_INTTYPE_PICU0_BASE
#define Pin_1__LCD_COM_SEG CYREG_PRT0_LCD_COM_SEG
#define Pin_1__LCD_EN CYREG_PRT0_LCD_EN
#define Pin_1__MASK 0x01u
#define Pin_1__PORT 0u
#define Pin_1__PRT CYREG_PRT0_PRT
#define Pin_1__PRTDSI__CAPS_SEL CYREG_PRT0_CAPS_SEL
#define Pin_1__PRTDSI__DBL_SYNC_IN CYREG_PRT0_DBL_SYNC_IN
#define Pin_1__PRTDSI__OE_SEL0 CYREG_PRT0_OE_SEL0
#define Pin_1__PRTDSI__OE_SEL1 CYREG_PRT0_OE_SEL1
#define Pin_1__PRTDSI__OUT_SEL0 CYREG_PRT0_OUT_SEL0
#define Pin_1__PRTDSI__OUT_SEL1 CYREG_PRT0_OUT_SEL1
#define Pin_1__PRTDSI__SYNC_OUT CYREG_PRT0_SYNC_OUT
#define Pin_1__PS CYREG_PRT0_PS
#define Pin_1__SHIFT 0u
#define Pin_1__SLW CYREG_PRT0_SLW

/* Timer */
#define Timer_TimerHW__CAP0 CYREG_TMR0_CAP0
#define Timer_TimerHW__CAP1 CYREG_TMR0_CAP1
#define Timer_TimerHW__CFG0 CYREG_TMR0_CFG0
#define Timer_TimerHW__CFG1 CYREG_TMR0_CFG1
#define Timer_TimerHW__CFG2 CYREG_TMR0_CFG2
#define Timer_TimerHW__CNT_CMP0 CYREG_TMR0_CNT_CMP0
#define Timer_TimerHW__CNT_CMP1 CYREG_TMR0_CNT_CMP1
#define Timer_TimerHW__PER0 CYREG_TMR0_PER0
#define Timer_TimerHW__PER1 CYREG_TMR0_PER1
#define Timer_TimerHW__PM_ACT_CFG CYREG_PM_ACT_CFG3
#define Timer_TimerHW__PM_ACT_MSK 0x01u
#define Timer_TimerHW__PM_STBY_CFG CYREG_PM_STBY_CFG3
#define Timer_TimerHW__PM_STBY_MSK 0x01u
#define Timer_TimerHW__RT0 CYREG_TMR0_RT0
#define Timer_TimerHW__RT1 CYREG_TMR0_RT1
#define Timer_TimerHW__SR0 CYREG_TMR0_SR0

/* VDAC8 */
#define VDAC8_viDAC8__CR0 CYREG_DAC2_CR0
#define VDAC8_viDAC8__CR1 CYREG_DAC2_CR1
#define VDAC8_viDAC8__D CYREG_DAC2_D
#define VDAC8_viDAC8__PM_ACT_CFG CYREG_PM_ACT_CFG8
#define VDAC8_viDAC8__PM_ACT_MSK 0x04u
#define VDAC8_viDAC8__PM_STBY_CFG CYREG_PM_STBY_CFG8
#define VDAC8_viDAC8__PM_STBY_MSK 0x04u
#define VDAC8_viDAC8__STROBE CYREG_DAC2_STROBE
#define VDAC8_viDAC8__SW0 CYREG_DAC2_SW0
#define VDAC8_viDAC8__SW2 CYREG_DAC2_SW2
#define VDAC8_viDAC8__SW3 CYREG_DAC2_SW3
#define VDAC8_viDAC8__SW4 CYREG_DAC2_SW4
#define VDAC8_viDAC8__TR CYREG_DAC2_TR
#define VDAC8_viDAC8__TRIM__M1 CYREG_FLSHID_CUST_TABLES_DAC2_M1
#define VDAC8_viDAC8__TRIM__M2 CYREG_FLSHID_CUST_TABLES_DAC2_M2
#define VDAC8_viDAC8__TRIM__M3 CYREG_FLSHID_CUST_TABLES_DAC2_M3
#define VDAC8_viDAC8__TRIM__M4 CYREG_FLSHID_CUST_TABLES_DAC2_M4
#define VDAC8_viDAC8__TRIM__M5 CYREG_FLSHID_CUST_TABLES_DAC2_M5
#define VDAC8_viDAC8__TRIM__M6 CYREG_FLSHID_CUST_TABLES_DAC2_M6
#define VDAC8_viDAC8__TRIM__M7 CYREG_FLSHID_CUST_TABLES_DAC2_M7
#define VDAC8_viDAC8__TRIM__M8 CYREG_FLSHID_CUST_TABLES_DAC2_M8
#define VDAC8_viDAC8__TST CYREG_DAC2_TST

/* Filter */
#define Filter_DFB__ACU_SRAM_DATA CYREG_DFB0_ACU_SRAM_DATA_MBASE
#define Filter_DFB__COHER CYREG_DFB0_COHER
#define Filter_DFB__CR CYREG_DFB0_CR
#define Filter_DFB__CSA_SRAM_DATA CYREG_DFB0_CSA_SRAM_DATA_MBASE
#define Filter_DFB__CSB_SRAM_DATA CYREG_DFB0_CSB_SRAM_DATA_MBASE
#define Filter_DFB__DALIGN CYREG_DFB0_DALIGN
#define Filter_DFB__DMA_CTRL CYREG_DFB0_DMA_CTRL
#define Filter_DFB__DPA_SRAM_DATA CYREG_DFB0_DPA_SRAM_DATA_MBASE
#define Filter_DFB__DPB_SRAM_DATA CYREG_DFB0_DPB_SRAM_DATA_MBASE
#define Filter_DFB__DSI_CTRL CYREG_DFB0_DSI_CTRL
#define Filter_DFB__FSM_SRAM_DATA CYREG_DFB0_FSM_SRAM_DATA_MBASE
#define Filter_DFB__HOLDA CYREG_DFB0_HOLDA
#define Filter_DFB__HOLDAH CYREG_DFB0_HOLDAH
#define Filter_DFB__HOLDAM CYREG_DFB0_HOLDAM
#define Filter_DFB__HOLDAS CYREG_DFB0_HOLDAS
#define Filter_DFB__HOLDB CYREG_DFB0_HOLDB
#define Filter_DFB__HOLDBH CYREG_DFB0_HOLDBH
#define Filter_DFB__HOLDBM CYREG_DFB0_HOLDBM
#define Filter_DFB__HOLDBS CYREG_DFB0_HOLDBS
#define Filter_DFB__INT_CTRL CYREG_DFB0_INT_CTRL
#define Filter_DFB__PM_ACT_CFG CYREG_PM_ACT_CFG6
#define Filter_DFB__PM_ACT_MSK 0x10u
#define Filter_DFB__PM_STBY_CFG CYREG_PM_STBY_CFG6
#define Filter_DFB__PM_STBY_MSK 0x10u
#define Filter_DFB__RAM_DIR CYREG_DFB0_RAM_DIR
#define Filter_DFB__RAM_EN CYREG_DFB0_RAM_EN
#define Filter_DFB__SEMA CYREG_DFB0_SEMA
#define Filter_DFB__SR CYREG_DFB0_SR
#define Filter_DFB__STAGEA CYREG_DFB0_STAGEA
#define Filter_DFB__STAGEAH CYREG_DFB0_STAGEAH
#define Filter_DFB__STAGEAM CYREG_DFB0_STAGEAM
#define Filter_DFB__STAGEB CYREG_DFB0_STAGEB
#define Filter_DFB__STAGEBH CYREG_DFB0_STAGEBH
#define Filter_DFB__STAGEBM CYREG_DFB0_STAGEBM

/* UART_1 */
#define UART_1_BUART_sRX_RxBitCounter__16BIT_CONTROL_AUX_CTL_REG CYREG_B0_UDB09_10_ACTL
#define UART_1_BUART_sRX_RxBitCounter__16BIT_CONTROL_CONTROL_REG CYREG_B0_UDB09_10_CTL
#define UART_1_BUART_sRX_RxBitCounter__16BIT_CONTROL_COUNT_REG CYREG_B0_UDB09_10_CTL
#define UART_1_BUART_sRX_RxBitCounter__16BIT_COUNT_CONTROL_REG CYREG_B0_UDB09_10_CTL
#define UART_1_BUART_sRX_RxBitCounter__16BIT_COUNT_COUNT_REG CYREG_B0_UDB09_10_CTL
#define UART_1_BUART_sRX_RxBitCounter__16BIT_MASK_MASK_REG CYREG_B0_UDB09_10_MSK
#define UART_1_BUART_sRX_RxBitCounter__16BIT_MASK_PERIOD_REG CYREG_B0_UDB09_10_MSK
#define UART_1_BUART_sRX_RxBitCounter__16BIT_PERIOD_MASK_REG CYREG_B0_UDB09_10_MSK
#define UART_1_BUART_sRX_RxBitCounter__16BIT_PERIOD_PERIOD_REG CYREG_B0_UDB09_10_MSK
#define UART_1_BUART_sRX_RxBitCounter__CONTROL_AUX_CTL_REG CYREG_B0_UDB09_ACTL
#define UART_1_BUART_sRX_RxBitCounter__CONTROL_REG CYREG_B0_UDB09_CTL
#define UART_1_BUART_sRX_RxBitCounter__CONTROL_ST_REG CYREG_B0_UDB09_ST_CTL
#define UART_1_BUART_sRX_RxBitCounter__COUNT_REG CYREG_B0_UDB09_CTL
#define UART_1_BUART_sRX_RxBitCounter__COUNT_ST_REG CYREG_B0_UDB09_ST_CTL
#define UART_1_BUART_sRX_RxBitCounter__MASK_CTL_AUX_CTL_REG CYREG_B0_UDB09_MSK_ACTL
#define UART_1_BUART_sRX_RxBitCounter__PER_CTL_AUX_CTL_REG CYREG_B0_UDB09_MSK_ACTL
#define UART_1_BUART_sRX_RxBitCounter__PERIOD_REG CYREG_B0_UDB09_MSK
#define UART_1_BUART_sRX_RxBitCounter_ST__16BIT_STATUS_AUX_CTL_REG CYREG_B0_UDB09_10_ACTL
#define UART_1_BUART_sRX_RxBitCounter_ST__16BIT_STATUS_REG CYREG_B0_UDB09_10_ST
#define UART_1_BUART_sRX_RxBitCounter_ST__MASK_REG CYREG_B0_UDB09_MSK
#define UART_1_BUART_sRX_RxBitCounter_ST__MASK_ST_AUX_CTL_REG CYREG_B0_UDB09_MSK_ACTL
#define UART_1_BUART_sRX_RxBitCounter_ST__PER_ST_AUX_CTL_REG CYREG_B0_UDB09_MSK_ACTL
#define UART_1_BUART_sRX_RxBitCounter_ST__STATUS_AUX_CTL_REG CYREG_B0_UDB09_ACTL
#define UART_1_BUART_sRX_RxBitCounter_ST__STATUS_CNT_REG CYREG_B0_UDB09_ST_CTL
#define UART_1_BUART_sRX_RxBitCounter_ST__STATUS_CONTROL_REG CYREG_B0_UDB09_ST_CTL
#define UART_1_BUART_sRX_RxBitCounter_ST__STATUS_REG CYREG_B0_UDB09_ST
#define UART_1_BUART_sRX_RxShifter_u0__16BIT_A0_REG CYREG_B0_UDB09_10_A0
#define UART_1_BUART_sRX_RxShifter_u0__16BIT_A1_REG CYREG_B0_UDB09_10_A1
#define UART_1_BUART_sRX_RxShifter_u0__16BIT_D0_REG CYREG_B0_UDB09_10_D0
#define UART_1_BUART_sRX_RxShifter_u0__16BIT_D1_REG CYREG_B0_UDB09_10_D1
#define UART_1_BUART_sRX_RxShifter_u0__16BIT_DP_AUX_CTL_REG CYREG_B0_UDB09_10_ACTL
#define UART_1_BUART_sRX_RxShifter_u0__16BIT_F0_REG CYREG_B0_UDB09_10_F0
#define UART_1_BUART_sRX_RxShifter_u0__16BIT_F1_REG CYREG_B0_UDB09_10_F1
#define UART_1_BUART_sRX_RxShifter_u0__A0_A1_REG CYREG_B0_UDB09_A0_A1
#define UART_1_BUART_sRX_RxShifter_u0__A0_REG CYREG_B0_UDB09_A0
#define UART_1_BUART_sRX_RxShifter_u0__A1_REG CYREG_B0_UDB09_A1
#define UART_1_BUART_sRX_RxShifter_u0__D0_D1_REG CYREG_B0_UDB09_D0_D1
#define UART_1_BUART_sRX_RxShifter_u0__D0_REG CYREG_B0_UDB09_D0
#define UART_1_BUART_sRX_RxShifter_u0__D1_REG CYREG_B0_UDB09_D1
#define UART_1_BUART_sRX_RxShifter_u0__DP_AUX_CTL_REG CYREG_B0_UDB09_ACTL
#define UART_1_BUART_sRX_RxShifter_u0__F0_F1_REG CYREG_B0_UDB09_F0_F1
#define UART_1_BUART_sRX_RxShifter_u0__F0_REG CYREG_B0_UDB09_F0
#define UART_1_BUART_sRX_RxShifter_u0__F1_REG CYREG_B0_UDB09_F1
#define UART_1_BUART_sRX_RxShifter_u0__MSK_DP_AUX_CTL_REG CYREG_B0_UDB09_MSK_ACTL
#define UART_1_BUART_sRX_RxShifter_u0__PER_DP_AUX_CTL_REG CYREG_B0_UDB09_MSK_ACTL
#define UART_1_BUART_sRX_RxSts__16BIT_STATUS_AUX_CTL_REG CYREG_B1_UDB09_10_ACTL
#define UART_1_BUART_sRX_RxSts__16BIT_STATUS_REG CYREG_B1_UDB09_10_ST
#define UART_1_BUART_sRX_RxSts__3__MASK 0x08u
#define UART_1_BUART_sRX_RxSts__3__POS 3
#define UART_1_BUART_sRX_RxSts__4__MASK 0x10u
#define UART_1_BUART_sRX_RxSts__4__POS 4
#define UART_1_BUART_sRX_RxSts__5__MASK 0x20u
#define UART_1_BUART_sRX_RxSts__5__POS 5
#define UART_1_BUART_sRX_RxSts__MASK 0x38u
#define UART_1_BUART_sRX_RxSts__MASK_REG CYREG_B1_UDB09_MSK
#define UART_1_BUART_sRX_RxSts__STATUS_AUX_CTL_REG CYREG_B1_UDB09_ACTL
#define UART_1_BUART_sRX_RxSts__STATUS_REG CYREG_B1_UDB09_ST
#define UART_1_BUART_sTX_sCLOCK_TxBitClkGen__A0_A1_REG CYREG_B1_UDB11_A0_A1
#define UART_1_BUART_sTX_sCLOCK_TxBitClkGen__A0_REG CYREG_B1_UDB11_A0
#define UART_1_BUART_sTX_sCLOCK_TxBitClkGen__A1_REG CYREG_B1_UDB11_A1
#define UART_1_BUART_sTX_sCLOCK_TxBitClkGen__D0_D1_REG CYREG_B1_UDB11_D0_D1
#define UART_1_BUART_sTX_sCLOCK_TxBitClkGen__D0_REG CYREG_B1_UDB11_D0
#define UART_1_BUART_sTX_sCLOCK_TxBitClkGen__D1_REG CYREG_B1_UDB11_D1
#define UART_1_BUART_sTX_sCLOCK_TxBitClkGen__DP_AUX_CTL_REG CYREG_B1_UDB11_ACTL
#define UART_1_BUART_sTX_sCLOCK_TxBitClkGen__F0_F1_REG CYREG_B1_UDB11_F0_F1
#define UART_1_BUART_sTX_sCLOCK_TxBitClkGen__F0_REG CYREG_B1_UDB11_F0
#define UART_1_BUART_sTX_sCLOCK_TxBitClkGen__F1_REG CYREG_B1_UDB11_F1
#define UART_1_BUART_sTX_TxShifter_u0__16BIT_A0_REG CYREG_B1_UDB08_09_A0
#define UART_1_BUART_sTX_TxShifter_u0__16BIT_A1_REG CYREG_B1_UDB08_09_A1
#define UART_1_BUART_sTX_TxShifter_u0__16BIT_D0_REG CYREG_B1_UDB08_09_D0
#define UART_1_BUART_sTX_TxShifter_u0__16BIT_D1_REG CYREG_B1_UDB08_09_D1
#define UART_1_BUART_sTX_TxShifter_u0__16BIT_DP_AUX_CTL_REG CYREG_B1_UDB08_09_ACTL
#define UART_1_BUART_sTX_TxShifter_u0__16BIT_F0_REG CYREG_B1_UDB08_09_F0
#define UART_1_BUART_sTX_TxShifter_u0__16BIT_F1_REG CYREG_B1_UDB08_09_F1
#define UART_1_BUART_sTX_TxShifter_u0__A0_A1_REG CYREG_B1_UDB08_A0_A1
#define UART_1_BUART_sTX_TxShifter_u0__A0_REG CYREG_B1_UDB08_A0
#define UART_1_BUART_sTX_TxShifter_u0__A1_REG CYREG_B1_UDB08_A1
#define UART_1_BUART_sTX_TxShifter_u0__D0_D1_REG CYREG_B1_UDB08_D0_D1
#define UART_1_BUART_sTX_TxShifter_u0__D0_REG CYREG_B1_UDB08_D0
#define UART_1_BUART_sTX_TxShifter_u0__D1_REG CYREG_B1_UDB08_D1
#define UART_1_BUART_sTX_TxShifter_u0__DP_AUX_CTL_REG CYREG_B1_UDB08_ACTL
#define UART_1_BUART_sTX_TxShifter_u0__F0_F1_REG CYREG_B1_UDB08_F0_F1
#define UART_1_BUART_sTX_TxShifter_u0__F0_REG CYREG_B1_UDB08_F0
#define UART_1_BUART_sTX_TxShifter_u0__F1_REG CYREG_B1_UDB08_F1
#define UART_1_BUART_sTX_TxSts__0__MASK 0x01u
#define UART_1_BUART_sTX_TxSts__0__POS 0
#define UART_1_BUART_sTX_TxSts__1__MASK 0x02u
#define UART_1_BUART_sTX_TxSts__1__POS 1
#define UART_1_BUART_sTX_TxSts__2__MASK 0x04u
#define UART_1_BUART_sTX_TxSts__2__POS 2
#define UART_1_BUART_sTX_TxSts__3__MASK 0x08u
#define UART_1_BUART_sTX_TxSts__3__POS 3
#define UART_1_BUART_sTX_TxSts__MASK 0x0Fu
#define UART_1_BUART_sTX_TxSts__MASK_REG CYREG_B1_UDB11_MSK
#define UART_1_BUART_sTX_TxSts__STATUS_AUX_CTL_REG CYREG_B1_UDB11_ACTL
#define UART_1_BUART_sTX_TxSts__STATUS_REG CYREG_B1_UDB11_ST
#define UART_1_IntClock__CFG0 CYREG_CLKDIST_DCFG2_CFG0
#define UART_1_IntClock__CFG1 CYREG_CLKDIST_DCFG2_CFG1
#define UART_1_IntClock__CFG2 CYREG_CLKDIST_DCFG2_CFG2
#define UART_1_IntClock__CFG2_SRC_SEL_MASK 0x07u
#define UART_1_IntClock__INDEX 0x02u
#define UART_1_IntClock__PM_ACT_CFG CYREG_PM_ACT_CFG2
#define UART_1_IntClock__PM_ACT_MSK 0x04u
#define UART_1_IntClock__PM_STBY_CFG CYREG_PM_STBY_CFG2
#define UART_1_IntClock__PM_STBY_MSK 0x04u

/* Clock_1 */
#define Clock_1__CFG0 CYREG_CLKDIST_DCFG1_CFG0
#define Clock_1__CFG1 CYREG_CLKDIST_DCFG1_CFG1
#define Clock_1__CFG2 CYREG_CLKDIST_DCFG1_CFG2
#define Clock_1__CFG2_SRC_SEL_MASK 0x07u
#define Clock_1__INDEX 0x01u
#define Clock_1__PM_ACT_CFG CYREG_PM_ACT_CFG2
#define Clock_1__PM_ACT_MSK 0x02u
#define Clock_1__PM_STBY_CFG CYREG_PM_STBY_CFG2
#define Clock_1__PM_STBY_MSK 0x02u

/* Rx_12_6 */
#define Rx_12_6__0__INTTYPE CYREG_PICU12_INTTYPE6
#define Rx_12_6__0__MASK 0x40u
#define Rx_12_6__0__PC CYREG_PRT12_PC6
#define Rx_12_6__0__PORT 12u
#define Rx_12_6__0__SHIFT 6u
#define Rx_12_6__AG CYREG_PRT12_AG
#define Rx_12_6__BIE CYREG_PRT12_BIE
#define Rx_12_6__BIT_MASK CYREG_PRT12_BIT_MASK
#define Rx_12_6__BYP CYREG_PRT12_BYP
#define Rx_12_6__DM0 CYREG_PRT12_DM0
#define Rx_12_6__DM1 CYREG_PRT12_DM1
#define Rx_12_6__DM2 CYREG_PRT12_DM2
#define Rx_12_6__DR CYREG_PRT12_DR
#define Rx_12_6__INP_DIS CYREG_PRT12_INP_DIS
#define Rx_12_6__INTTYPE_BASE CYDEV_PICU_INTTYPE_PICU12_BASE
#define Rx_12_6__MASK 0x40u
#define Rx_12_6__PORT 12u
#define Rx_12_6__PRT CYREG_PRT12_PRT
#define Rx_12_6__PRTDSI__DBL_SYNC_IN CYREG_PRT12_DBL_SYNC_IN
#define Rx_12_6__PRTDSI__OE_SEL0 CYREG_PRT12_OE_SEL0
#define Rx_12_6__PRTDSI__OE_SEL1 CYREG_PRT12_OE_SEL1
#define Rx_12_6__PRTDSI__OUT_SEL0 CYREG_PRT12_OUT_SEL0
#define Rx_12_6__PRTDSI__OUT_SEL1 CYREG_PRT12_OUT_SEL1
#define Rx_12_6__PRTDSI__SYNC_OUT CYREG_PRT12_SYNC_OUT
#define Rx_12_6__PS CYREG_PRT12_PS
#define Rx_12_6__SHIFT 6u
#define Rx_12_6__SIO_CFG CYREG_PRT12_SIO_CFG
#define Rx_12_6__SIO_DIFF CYREG_PRT12_SIO_DIFF
#define Rx_12_6__SIO_HYST_EN CYREG_PRT12_SIO_HYST_EN
#define Rx_12_6__SIO_REG_HIFREQ CYREG_PRT12_SIO_REG_HIFREQ
#define Rx_12_6__SLW CYREG_PRT12_SLW

/* Tx_12_7 */
#define Tx_12_7__0__INTTYPE CYREG_PICU12_INTTYPE7
#define Tx_12_7__0__MASK 0x80u
#define Tx_12_7__0__PC CYREG_PRT12_PC7
#define Tx_12_7__0__PORT 12u
#define Tx_12_7__0__SHIFT 7u
#define Tx_12_7__AG CYREG_PRT12_AG
#define Tx_12_7__BIE CYREG_PRT12_BIE
#define Tx_12_7__BIT_MASK CYREG_PRT12_BIT_MASK
#define Tx_12_7__BYP CYREG_PRT12_BYP
#define Tx_12_7__DM0 CYREG_PRT12_DM0
#define Tx_12_7__DM1 CYREG_PRT12_DM1
#define Tx_12_7__DM2 CYREG_PRT12_DM2
#define Tx_12_7__DR CYREG_PRT12_DR
#define Tx_12_7__INP_DIS CYREG_PRT12_INP_DIS
#define Tx_12_7__INTTYPE_BASE CYDEV_PICU_INTTYPE_PICU12_BASE
#define Tx_12_7__MASK 0x80u
#define Tx_12_7__PORT 12u
#define Tx_12_7__PRT CYREG_PRT12_PRT
#define Tx_12_7__PRTDSI__DBL_SYNC_IN CYREG_PRT12_DBL_SYNC_IN
#define Tx_12_7__PRTDSI__OE_SEL0 CYREG_PRT12_OE_SEL0
#define Tx_12_7__PRTDSI__OE_SEL1 CYREG_PRT12_OE_SEL1
#define Tx_12_7__PRTDSI__OUT_SEL0 CYREG_PRT12_OUT_SEL0
#define Tx_12_7__PRTDSI__OUT_SEL1 CYREG_PRT12_OUT_SEL1
#define Tx_12_7__PRTDSI__SYNC_OUT CYREG_PRT12_SYNC_OUT
#define Tx_12_7__PS CYREG_PRT12_PS
#define Tx_12_7__SHIFT 7u
#define Tx_12_7__SIO_CFG CYREG_PRT12_SIO_CFG
#define Tx_12_7__SIO_DIFF CYREG_PRT12_SIO_DIFF
#define Tx_12_7__SIO_HYST_EN CYREG_PRT12_SIO_HYST_EN
#define Tx_12_7__SIO_REG_HIFREQ CYREG_PRT12_SIO_REG_HIFREQ
#define Tx_12_7__SLW CYREG_PRT12_SLW

/* WaveDAC8 */
#define WaveDAC8_DacClk__CFG0 CYREG_CLKDIST_DCFG3_CFG0
#define WaveDAC8_DacClk__CFG1 CYREG_CLKDIST_DCFG3_CFG1
#define WaveDAC8_DacClk__CFG2 CYREG_CLKDIST_DCFG3_CFG2
#define WaveDAC8_DacClk__CFG2_SRC_SEL_MASK 0x07u
#define WaveDAC8_DacClk__INDEX 0x03u
#define WaveDAC8_DacClk__PM_ACT_CFG CYREG_PM_ACT_CFG2
#define WaveDAC8_DacClk__PM_ACT_MSK 0x08u
#define WaveDAC8_DacClk__PM_STBY_CFG CYREG_PM_STBY_CFG2
#define WaveDAC8_DacClk__PM_STBY_MSK 0x08u
#define WaveDAC8_VDAC8_viDAC8__CR0 CYREG_DAC3_CR0
#define WaveDAC8_VDAC8_viDAC8__CR1 CYREG_DAC3_CR1
#define WaveDAC8_VDAC8_viDAC8__D CYREG_DAC3_D
#define WaveDAC8_VDAC8_viDAC8__PM_ACT_CFG CYREG_PM_ACT_CFG8
#define WaveDAC8_VDAC8_viDAC8__PM_ACT_MSK 0x08u
#define WaveDAC8_VDAC8_viDAC8__PM_STBY_CFG CYREG_PM_STBY_CFG8
#define WaveDAC8_VDAC8_viDAC8__PM_STBY_MSK 0x08u
#define WaveDAC8_VDAC8_viDAC8__STROBE CYREG_DAC3_STROBE
#define WaveDAC8_VDAC8_viDAC8__SW0 CYREG_DAC3_SW0
#define WaveDAC8_VDAC8_viDAC8__SW2 CYREG_DAC3_SW2
#define WaveDAC8_VDAC8_viDAC8__SW3 CYREG_DAC3_SW3
#define WaveDAC8_VDAC8_viDAC8__SW4 CYREG_DAC3_SW4
#define WaveDAC8_VDAC8_viDAC8__TR CYREG_DAC3_TR
#define WaveDAC8_VDAC8_viDAC8__TRIM__M1 CYREG_FLSHID_CUST_TABLES_DAC3_M1
#define WaveDAC8_VDAC8_viDAC8__TRIM__M2 CYREG_FLSHID_CUST_TABLES_DAC3_M2
#define WaveDAC8_VDAC8_viDAC8__TRIM__M3 CYREG_FLSHID_CUST_TABLES_DAC3_M3
#define WaveDAC8_VDAC8_viDAC8__TRIM__M4 CYREG_FLSHID_CUST_TABLES_DAC3_M4
#define WaveDAC8_VDAC8_viDAC8__TRIM__M5 CYREG_FLSHID_CUST_TABLES_DAC3_M5
#define WaveDAC8_VDAC8_viDAC8__TRIM__M6 CYREG_FLSHID_CUST_TABLES_DAC3_M6
#define WaveDAC8_VDAC8_viDAC8__TRIM__M7 CYREG_FLSHID_CUST_TABLES_DAC3_M7
#define WaveDAC8_VDAC8_viDAC8__TRIM__M8 CYREG_FLSHID_CUST_TABLES_DAC3_M8
#define WaveDAC8_VDAC8_viDAC8__TST CYREG_DAC3_TST
#define WaveDAC8_Wave1_DMA__DRQ_CTL CYREG_IDMUX_DRQ_CTL0
#define WaveDAC8_Wave1_DMA__DRQ_NUMBER 0u
#define WaveDAC8_Wave1_DMA__NUMBEROF_TDS 0u
#define WaveDAC8_Wave1_DMA__PRIORITY 2u
#define WaveDAC8_Wave1_DMA__TERMIN_EN 0u
#define WaveDAC8_Wave1_DMA__TERMIN_SEL 0u
#define WaveDAC8_Wave1_DMA__TERMOUT0_EN 0u
#define WaveDAC8_Wave1_DMA__TERMOUT0_SEL 0u
#define WaveDAC8_Wave1_DMA__TERMOUT1_EN 0u
#define WaveDAC8_Wave1_DMA__TERMOUT1_SEL 0u
#define WaveDAC8_Wave2_DMA__DRQ_CTL CYREG_IDMUX_DRQ_CTL0
#define WaveDAC8_Wave2_DMA__DRQ_NUMBER 1u
#define WaveDAC8_Wave2_DMA__NUMBEROF_TDS 0u
#define WaveDAC8_Wave2_DMA__PRIORITY 2u
#define WaveDAC8_Wave2_DMA__TERMIN_EN 0u
#define WaveDAC8_Wave2_DMA__TERMIN_SEL 0u
#define WaveDAC8_Wave2_DMA__TERMOUT0_EN 0u
#define WaveDAC8_Wave2_DMA__TERMOUT0_SEL 0u
#define WaveDAC8_Wave2_DMA__TERMOUT1_EN 0u
#define WaveDAC8_Wave2_DMA__TERMOUT1_SEL 0u

/* isrTimer */
#define isrTimer__INTC_CLR_EN_REG CYREG_NVIC_CLRENA0
#define isrTimer__INTC_CLR_PD_REG CYREG_NVIC_CLRPEND0
#define isrTimer__INTC_MASK 0x01u
#define isrTimer__INTC_NUMBER 0u
#define isrTimer__INTC_PRIOR_NUM 7u
#define isrTimer__INTC_PRIOR_REG CYREG_NVIC_PRI_0
#define isrTimer__INTC_SET_EN_REG CYREG_NVIC_SETENA0
#define isrTimer__INTC_SET_PD_REG CYREG_NVIC_SETPEND0

/* ADC_DelSig */
#define ADC_DelSig_DEC__COHER CYREG_DEC_COHER
#define ADC_DelSig_DEC__CR CYREG_DEC_CR
#define ADC_DelSig_DEC__DR1 CYREG_DEC_DR1
#define ADC_DelSig_DEC__DR2 CYREG_DEC_DR2
#define ADC_DelSig_DEC__DR2H CYREG_DEC_DR2H
#define ADC_DelSig_DEC__GCOR CYREG_DEC_GCOR
#define ADC_DelSig_DEC__GCORH CYREG_DEC_GCORH
#define ADC_DelSig_DEC__GVAL CYREG_DEC_GVAL
#define ADC_DelSig_DEC__OCOR CYREG_DEC_OCOR
#define ADC_DelSig_DEC__OCORH CYREG_DEC_OCORH
#define ADC_DelSig_DEC__OCORM CYREG_DEC_OCORM
#define ADC_DelSig_DEC__OUTSAMP CYREG_DEC_OUTSAMP
#define ADC_DelSig_DEC__OUTSAMPH CYREG_DEC_OUTSAMPH
#define ADC_DelSig_DEC__OUTSAMPM CYREG_DEC_OUTSAMPM
#define ADC_DelSig_DEC__OUTSAMPS CYREG_DEC_OUTSAMPS
#define ADC_DelSig_DEC__PM_ACT_CFG CYREG_PM_ACT_CFG10
#define ADC_DelSig_DEC__PM_ACT_MSK 0x01u
#define ADC_DelSig_DEC__PM_STBY_CFG CYREG_PM_STBY_CFG10
#define ADC_DelSig_DEC__PM_STBY_MSK 0x01u
#define ADC_DelSig_DEC__SHIFT1 CYREG_DEC_SHIFT1
#define ADC_DelSig_DEC__SHIFT2 CYREG_DEC_SHIFT2
#define ADC_DelSig_DEC__SR CYREG_DEC_SR
#define ADC_DelSig_DEC__TRIM__M1 CYREG_FLSHID_CUST_TABLES_DEC_M1
#define ADC_DelSig_DEC__TRIM__M2 CYREG_FLSHID_CUST_TABLES_DEC_M2
#define ADC_DelSig_DEC__TRIM__M3 CYREG_FLSHID_CUST_TABLES_DEC_M3
#define ADC_DelSig_DEC__TRIM__M4 CYREG_FLSHID_CUST_TABLES_DEC_M4
#define ADC_DelSig_DEC__TRIM__M5 CYREG_FLSHID_CUST_TABLES_DEC_M5
#define ADC_DelSig_DEC__TRIM__M6 CYREG_FLSHID_CUST_TABLES_DEC_M6
#define ADC_DelSig_DEC__TRIM__M7 CYREG_FLSHID_CUST_TABLES_DEC_M7
#define ADC_DelSig_DEC__TRIM__M8 CYREG_FLSHID_CUST_TABLES_DEC_M8
#define ADC_DelSig_DSM__BUF0 CYREG_DSM0_BUF0
#define ADC_DelSig_DSM__BUF1 CYREG_DSM0_BUF1
#define ADC_DelSig_DSM__BUF2 CYREG_DSM0_BUF2
#define ADC_DelSig_DSM__BUF3 CYREG_DSM0_BUF3
#define ADC_DelSig_DSM__CLK CYREG_DSM0_CLK
#define ADC_DelSig_DSM__CR0 CYREG_DSM0_CR0
#define ADC_DelSig_DSM__CR1 CYREG_DSM0_CR1
#define ADC_DelSig_DSM__CR10 CYREG_DSM0_CR10
#define ADC_DelSig_DSM__CR11 CYREG_DSM0_CR11
#define ADC_DelSig_DSM__CR12 CYREG_DSM0_CR12
#define ADC_DelSig_DSM__CR13 CYREG_DSM0_CR13
#define ADC_DelSig_DSM__CR14 CYREG_DSM0_CR14
#define ADC_DelSig_DSM__CR15 CYREG_DSM0_CR15
#define ADC_DelSig_DSM__CR16 CYREG_DSM0_CR16
#define ADC_DelSig_DSM__CR17 CYREG_DSM0_CR17
#define ADC_DelSig_DSM__CR2 CYREG_DSM0_CR2
#define ADC_DelSig_DSM__CR3 CYREG_DSM0_CR3
#define ADC_DelSig_DSM__CR4 CYREG_DSM0_CR4
#define ADC_DelSig_DSM__CR5 CYREG_DSM0_CR5
#define ADC_DelSig_DSM__CR6 CYREG_DSM0_CR6
#define ADC_DelSig_DSM__CR7 CYREG_DSM0_CR7
#define ADC_DelSig_DSM__CR8 CYREG_DSM0_CR8
#define ADC_DelSig_DSM__CR9 CYREG_DSM0_CR9
#define ADC_DelSig_DSM__DEM0 CYREG_DSM0_DEM0
#define ADC_DelSig_DSM__DEM1 CYREG_DSM0_DEM1
#define ADC_DelSig_DSM__MISC CYREG_DSM0_MISC
#define ADC_DelSig_DSM__OUT0 CYREG_DSM0_OUT0
#define ADC_DelSig_DSM__OUT1 CYREG_DSM0_OUT1
#define ADC_DelSig_DSM__REF0 CYREG_DSM0_REF0
#define ADC_DelSig_DSM__REF1 CYREG_DSM0_REF1
#define ADC_DelSig_DSM__REF2 CYREG_DSM0_REF2
#define ADC_DelSig_DSM__REF3 CYREG_DSM0_REF3
#define ADC_DelSig_DSM__RSVD1 CYREG_DSM0_RSVD1
#define ADC_DelSig_DSM__SW0 CYREG_DSM0_SW0
#define ADC_DelSig_DSM__SW2 CYREG_DSM0_SW2
#define ADC_DelSig_DSM__SW3 CYREG_DSM0_SW3
#define ADC_DelSig_DSM__SW4 CYREG_DSM0_SW4
#define ADC_DelSig_DSM__SW6 CYREG_DSM0_SW6
#define ADC_DelSig_DSM__TR0 CYREG_NPUMP_DSM_TR0
#define ADC_DelSig_DSM__TST0 CYREG_DSM0_TST0
#define ADC_DelSig_DSM__TST1 CYREG_DSM0_TST1
#define ADC_DelSig_Ext_CP_Clk__CFG0 CYREG_CLKDIST_DCFG0_CFG0
#define ADC_DelSig_Ext_CP_Clk__CFG1 CYREG_CLKDIST_DCFG0_CFG1
#define ADC_DelSig_Ext_CP_Clk__CFG2 CYREG_CLKDIST_DCFG0_CFG2
#define ADC_DelSig_Ext_CP_Clk__CFG2_SRC_SEL_MASK 0x07u
#define ADC_DelSig_Ext_CP_Clk__INDEX 0x00u
#define ADC_DelSig_Ext_CP_Clk__PM_ACT_CFG CYREG_PM_ACT_CFG2
#define ADC_DelSig_Ext_CP_Clk__PM_ACT_MSK 0x01u
#define ADC_DelSig_Ext_CP_Clk__PM_STBY_CFG CYREG_PM_STBY_CFG2
#define ADC_DelSig_Ext_CP_Clk__PM_STBY_MSK 0x01u
#define ADC_DelSig_IRQ__INTC_CLR_EN_REG CYREG_NVIC_CLRENA0
#define ADC_DelSig_IRQ__INTC_CLR_PD_REG CYREG_NVIC_CLRPEND0
#define ADC_DelSig_IRQ__INTC_MASK 0x20000000u
#define ADC_DelSig_IRQ__INTC_NUMBER 29u
#define ADC_DelSig_IRQ__INTC_PRIOR_NUM 7u
#define ADC_DelSig_IRQ__INTC_PRIOR_REG CYREG_NVIC_PRI_29
#define ADC_DelSig_IRQ__INTC_SET_EN_REG CYREG_NVIC_SETENA0
#define ADC_DelSig_IRQ__INTC_SET_PD_REG CYREG_NVIC_SETPEND0
#define ADC_DelSig_theACLK__CFG0 CYREG_CLKDIST_ACFG0_CFG0
#define ADC_DelSig_theACLK__CFG1 CYREG_CLKDIST_ACFG0_CFG1
#define ADC_DelSig_theACLK__CFG2 CYREG_CLKDIST_ACFG0_CFG2
#define ADC_DelSig_theACLK__CFG2_SRC_SEL_MASK 0x07u
#define ADC_DelSig_theACLK__CFG3 CYREG_CLKDIST_ACFG0_CFG3
#define ADC_DelSig_theACLK__CFG3_PHASE_DLY_MASK 0x0Fu
#define ADC_DelSig_theACLK__INDEX 0x00u
#define ADC_DelSig_theACLK__PM_ACT_CFG CYREG_PM_ACT_CFG1
#define ADC_DelSig_theACLK__PM_ACT_MSK 0x01u
#define ADC_DelSig_theACLK__PM_STBY_CFG CYREG_PM_STBY_CFG1
#define ADC_DelSig_theACLK__PM_STBY_MSK 0x01u

/* Miscellaneous */
#define BCLK__BUS_CLK__HZ 24000000U
#define BCLK__BUS_CLK__KHZ 24000U
#define BCLK__BUS_CLK__MHZ 24U
#define CY_PROJECT_NAME "TareaClase4"
#define CY_VERSION "PSoC Creator  4.2"
#define CYDEV_CHIP_DIE_LEOPARD 1u
#define CYDEV_CHIP_DIE_PSOC4A 18u
#define CYDEV_CHIP_DIE_PSOC5LP 2u
#define CYDEV_CHIP_DIE_PSOC5TM 3u
#define CYDEV_CHIP_DIE_TMA4 4u
#define CYDEV_CHIP_DIE_UNKNOWN 0u
#define CYDEV_CHIP_FAMILY_FM0P 5u
#define CYDEV_CHIP_FAMILY_FM3 6u
#define CYDEV_CHIP_FAMILY_FM4 7u
#define CYDEV_CHIP_FAMILY_PSOC3 1u
#define CYDEV_CHIP_FAMILY_PSOC4 2u
#define CYDEV_CHIP_FAMILY_PSOC5 3u
#define CYDEV_CHIP_FAMILY_PSOC6 4u
#define CYDEV_CHIP_FAMILY_UNKNOWN 0u
#define CYDEV_CHIP_FAMILY_USED CYDEV_CHIP_FAMILY_PSOC5
#define CYDEV_CHIP_JTAG_ID 0x2E161069u
#define CYDEV_CHIP_MEMBER_3A 1u
#define CYDEV_CHIP_MEMBER_4A 18u
#define CYDEV_CHIP_MEMBER_4D 13u
#define CYDEV_CHIP_MEMBER_4E 6u
#define CYDEV_CHIP_MEMBER_4F 19u
#define CYDEV_CHIP_MEMBER_4G 4u
#define CYDEV_CHIP_MEMBER_4H 17u
#define CYDEV_CHIP_MEMBER_4I 23u
#define CYDEV_CHIP_MEMBER_4J 14u
#define CYDEV_CHIP_MEMBER_4K 15u
#define CYDEV_CHIP_MEMBER_4L 22u
#define CYDEV_CHIP_MEMBER_4M 21u
#define CYDEV_CHIP_MEMBER_4N 10u
#define CYDEV_CHIP_MEMBER_4O 7u
#define CYDEV_CHIP_MEMBER_4P 20u
#define CYDEV_CHIP_MEMBER_4Q 12u
#define CYDEV_CHIP_MEMBER_4R 8u
#define CYDEV_CHIP_MEMBER_4S 11u
#define CYDEV_CHIP_MEMBER_4T 9u
#define CYDEV_CHIP_MEMBER_4U 5u
#define CYDEV_CHIP_MEMBER_4V 16u
#define CYDEV_CHIP_MEMBER_5A 3u
#define CYDEV_CHIP_MEMBER_5B 2u
#define CYDEV_CHIP_MEMBER_6A 24u
#define CYDEV_CHIP_MEMBER_FM3 28u
#define CYDEV_CHIP_MEMBER_FM4 29u
#define CYDEV_CHIP_MEMBER_PDL_FM0P_TYPE1 25u
#define CYDEV_CHIP_MEMBER_PDL_FM0P_TYPE2 26u
#define CYDEV_CHIP_MEMBER_PDL_FM0P_TYPE3 27u
#define CYDEV_CHIP_MEMBER_UNKNOWN 0u
#define CYDEV_CHIP_MEMBER_USED CYDEV_CHIP_MEMBER_5B
#define CYDEV_CHIP_DIE_EXPECT CYDEV_CHIP_MEMBER_USED
#define CYDEV_CHIP_DIE_ACTUAL CYDEV_CHIP_DIE_EXPECT
#define CYDEV_CHIP_REV_LEOPARD_ES1 0u
#define CYDEV_CHIP_REV_LEOPARD_ES2 1u
#define CYDEV_CHIP_REV_LEOPARD_ES3 3u
#define CYDEV_CHIP_REV_LEOPARD_PRODUCTION 3u
#define CYDEV_CHIP_REV_PSOC4A_ES0 17u
#define CYDEV_CHIP_REV_PSOC4A_PRODUCTION 17u
#define CYDEV_CHIP_REV_PSOC5LP_ES0 0u
#define CYDEV_CHIP_REV_PSOC5LP_PRODUCTION 0u
#define CYDEV_CHIP_REV_PSOC5TM_ES0 0u
#define CYDEV_CHIP_REV_PSOC5TM_ES1 1u
#define CYDEV_CHIP_REV_PSOC5TM_PRODUCTION 1u
#define CYDEV_CHIP_REV_TMA4_ES 17u
#define CYDEV_CHIP_REV_TMA4_ES2 33u
#define CYDEV_CHIP_REV_TMA4_PRODUCTION 17u
#define CYDEV_CHIP_REVISION_3A_ES1 0u
#define CYDEV_CHIP_REVISION_3A_ES2 1u
#define CYDEV_CHIP_REVISION_3A_ES3 3u
#define CYDEV_CHIP_REVISION_3A_PRODUCTION 3u
#define CYDEV_CHIP_REVISION_4A_ES0 17u
#define CYDEV_CHIP_REVISION_4A_PRODUCTION 17u
#define CYDEV_CHIP_REVISION_4D_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4E_CCG2_NO_USBPD 0u
#define CYDEV_CHIP_REVISION_4E_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4F_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4F_PRODUCTION_256DMA 0u
#define CYDEV_CHIP_REVISION_4F_PRODUCTION_256K 0u
#define CYDEV_CHIP_REVISION_4G_ES 17u
#define CYDEV_CHIP_REVISION_4G_ES2 33u
#define CYDEV_CHIP_REVISION_4G_PRODUCTION 17u
#define CYDEV_CHIP_REVISION_4H_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4I_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4J_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4K_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4L_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4M_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4N_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4O_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4P_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4Q_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4R_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4S_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4T_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4U_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4V_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_5A_ES0 0u
#define CYDEV_CHIP_REVISION_5A_ES1 1u
#define CYDEV_CHIP_REVISION_5A_PRODUCTION 1u
#define CYDEV_CHIP_REVISION_5B_ES0 0u
#define CYDEV_CHIP_REVISION_5B_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_6A_ES 17u
#define CYDEV_CHIP_REVISION_6A_NO_UDB 33u
#define CYDEV_CHIP_REVISION_6A_PRODUCTION 33u
#define CYDEV_CHIP_REVISION_FM3_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_FM4_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_PDL_FM0P_TYPE1_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_PDL_FM0P_TYPE2_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_PDL_FM0P_TYPE3_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_USED CYDEV_CHIP_REVISION_5B_PRODUCTION
#define CYDEV_CHIP_REV_EXPECT CYDEV_CHIP_REVISION_USED
#define CYDEV_CONFIG_FASTBOOT_ENABLED 0
#define CYDEV_CONFIG_UNUSED_IO_AllowButWarn 0
#define CYDEV_CONFIG_UNUSED_IO CYDEV_CONFIG_UNUSED_IO_AllowButWarn
#define CYDEV_CONFIG_UNUSED_IO_AllowWithInfo 1
#define CYDEV_CONFIG_UNUSED_IO_Disallowed 2
#define CYDEV_CONFIGURATION_COMPRESSED 0
#define CYDEV_CONFIGURATION_DMA 1
#define CYDEV_CONFIGURATION_ECC 1
#define CYDEV_CONFIGURATION_IMOENABLED CYDEV_CONFIG_FASTBOOT_ENABLED
#define CYDEV_CONFIGURATION_MODE_COMPRESSED 0
#define CYDEV_CONFIGURATION_MODE_DMA 2
#define CYDEV_CONFIGURATION_MODE CYDEV_CONFIGURATION_MODE_DMA
#define CYDEV_CONFIGURATION_MODE_UNCOMPRESSED 1
#define CYDEV_DEBUG_ENABLE_MASK 0x20u
#define CYDEV_DEBUG_ENABLE_REGISTER CYREG_MLOGIC_DEBUG
#define CYDEV_DEBUGGING_DPS_Disable 3
#define CYDEV_DEBUGGING_DPS_JTAG_4 1
#define CYDEV_DEBUGGING_DPS_JTAG_5 0
#define CYDEV_DEBUGGING_DPS_SWD 2
#define CYDEV_DEBUGGING_DPS_SWD_SWV 6
#define CYDEV_DEBUGGING_DPS CYDEV_DEBUGGING_DPS_SWD_SWV
#define CYDEV_DEBUGGING_ENABLE 1
#define CYDEV_DEBUGGING_XRES 0
#define CYDEV_DMA_CHANNELS_AVAILABLE 24u
#define CYDEV_ECC_ENABLE 0
#define CYDEV_HEAP_SIZE 0x80
#define CYDEV_INSTRUCT_CACHE_ENABLED 1
#define CYDEV_INTR_RISING 0x00000001u
#define CYDEV_IS_EXPORTING_CODE 0
#define CYDEV_IS_IMPORTING_CODE 0
#define CYDEV_PROJ_TYPE 0
#define CYDEV_PROJ_TYPE_BOOTLOADER 1
#define CYDEV_PROJ_TYPE_LAUNCHER 5
#define CYDEV_PROJ_TYPE_LOADABLE 2
#define CYDEV_PROJ_TYPE_LOADABLEANDBOOTLOADER 4
#define CYDEV_PROJ_TYPE_MULTIAPPBOOTLOADER 3
#define CYDEV_PROJ_TYPE_STANDARD 0
#define CYDEV_PROTECTION_ENABLE 0
#define CYDEV_STACK_SIZE 0x0800
#define CYDEV_USE_BUNDLED_CMSIS 1
#define CYDEV_VARIABLE_VDDA 0
#define CYDEV_VDDA 5.0
#define CYDEV_VDDA_MV 5000
#define CYDEV_VDDD 5.0
#define CYDEV_VDDD_MV 5000
#define CYDEV_VDDIO0 5.0
#define CYDEV_VDDIO0_MV 5000
#define CYDEV_VDDIO1 5.0
#define CYDEV_VDDIO1_MV 5000
#define CYDEV_VDDIO2 5.0
#define CYDEV_VDDIO2_MV 5000
#define CYDEV_VDDIO3 5.0
#define CYDEV_VDDIO3_MV 5000
#define CYDEV_VIO0 5.0
#define CYDEV_VIO0_MV 5000
#define CYDEV_VIO1 5.0
#define CYDEV_VIO1_MV 5000
#define CYDEV_VIO2 5.0
#define CYDEV_VIO2_MV 5000
#define CYDEV_VIO3 5.0
#define CYDEV_VIO3_MV 5000
#define CYIPBLOCK_ARM_CM3_VERSION 0
#define CYIPBLOCK_P3_ANAIF_VERSION 0
#define CYIPBLOCK_P3_CAN_VERSION 0
#define CYIPBLOCK_P3_CAPSENSE_VERSION 0
#define CYIPBLOCK_P3_COMP_VERSION 0
#define CYIPBLOCK_P3_DECIMATOR_VERSION 0
#define CYIPBLOCK_P3_DFB_VERSION 0
#define CYIPBLOCK_P3_DMA_VERSION 0
#define CYIPBLOCK_P3_DRQ_VERSION 0
#define CYIPBLOCK_P3_DSM_VERSION 0
#define CYIPBLOCK_P3_EMIF_VERSION 0
#define CYIPBLOCK_P3_I2C_VERSION 0
#define CYIPBLOCK_P3_LCD_VERSION 0
#define CYIPBLOCK_P3_LPF_VERSION 0
#define CYIPBLOCK_P3_OPAMP_VERSION 0
#define CYIPBLOCK_P3_PM_VERSION 0
#define CYIPBLOCK_P3_SCCT_VERSION 0
#define CYIPBLOCK_P3_TIMER_VERSION 0
#define CYIPBLOCK_P3_USB_VERSION 0
#define CYIPBLOCK_P3_VIDAC_VERSION 0
#define CYIPBLOCK_P3_VREF_VERSION 0
#define CYIPBLOCK_S8_GPIO_VERSION 0
#define CYIPBLOCK_S8_IRQ_VERSION 0
#define CYIPBLOCK_S8_SAR_VERSION 0
#define CYIPBLOCK_S8_SIO_VERSION 0
#define CYIPBLOCK_S8_UDB_VERSION 0
#define CYDEV_BOOTLOADER_ENABLE 0

#endif /* INCLUDED_CYFITTER_H */
