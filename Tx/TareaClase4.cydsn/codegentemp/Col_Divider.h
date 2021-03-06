/*******************************************************************************
* File Name: Col_Divider.h
* Version 3.30
*
* Description:
*  Contains the prototypes and constants for the functions available to the
*  PWM user module.
*
* Note:
*
********************************************************************************
* Copyright 2008-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
********************************************************************************/

#if !defined(CY_PWM_Col_Divider_H)
#define CY_PWM_Col_Divider_H

#include "cyfitter.h"
#include "cytypes.h"
#include "CyLib.h" /* For CyEnterCriticalSection() and CyExitCriticalSection() functions */

extern uint8 Col_Divider_initVar;


/***************************************
* Conditional Compilation Parameters
***************************************/
#define Col_Divider_Resolution                     (8u)
#define Col_Divider_UsingFixedFunction             (0u)
#define Col_Divider_DeadBandMode                   (0u)
#define Col_Divider_KillModeMinTime                (0u)
#define Col_Divider_KillMode                       (0u)
#define Col_Divider_PWMMode                        (0u)
#define Col_Divider_PWMModeIsCenterAligned         (0u)
#define Col_Divider_DeadBandUsed                   (0u)
#define Col_Divider_DeadBand2_4                    (0u)

#if !defined(Col_Divider_PWMUDB_genblk8_stsreg__REMOVED)
    #define Col_Divider_UseStatus                  (1u)
#else
    #define Col_Divider_UseStatus                  (0u)
#endif /* !defined(Col_Divider_PWMUDB_genblk8_stsreg__REMOVED) */

#if !defined(Col_Divider_PWMUDB_genblk1_ctrlreg__REMOVED)
    #define Col_Divider_UseControl                 (1u)
#else
    #define Col_Divider_UseControl                 (0u)
#endif /* !defined(Col_Divider_PWMUDB_genblk1_ctrlreg__REMOVED) */

#define Col_Divider_UseOneCompareMode              (1u)
#define Col_Divider_MinimumKillTime                (1u)
#define Col_Divider_EnableMode                     (0u)

#define Col_Divider_CompareMode1SW                 (0u)
#define Col_Divider_CompareMode2SW                 (0u)

/* Check to see if required defines such as CY_PSOC5LP are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5LP)
    #error Component PWM_v3_30 requires cy_boot v3.0 or later
#endif /* (CY_ PSOC5LP) */

/* Use Kill Mode Enumerated Types */
#define Col_Divider__B_PWM__DISABLED 0
#define Col_Divider__B_PWM__ASYNCHRONOUS 1
#define Col_Divider__B_PWM__SINGLECYCLE 2
#define Col_Divider__B_PWM__LATCHED 3
#define Col_Divider__B_PWM__MINTIME 4


/* Use Dead Band Mode Enumerated Types */
#define Col_Divider__B_PWM__DBMDISABLED 0
#define Col_Divider__B_PWM__DBM_2_4_CLOCKS 1
#define Col_Divider__B_PWM__DBM_256_CLOCKS 2


/* Used PWM Mode Enumerated Types */
#define Col_Divider__B_PWM__ONE_OUTPUT 0
#define Col_Divider__B_PWM__TWO_OUTPUTS 1
#define Col_Divider__B_PWM__DUAL_EDGE 2
#define Col_Divider__B_PWM__CENTER_ALIGN 3
#define Col_Divider__B_PWM__DITHER 5
#define Col_Divider__B_PWM__HARDWARESELECT 4


/* Used PWM Compare Mode Enumerated Types */
#define Col_Divider__B_PWM__LESS_THAN 1
#define Col_Divider__B_PWM__LESS_THAN_OR_EQUAL 2
#define Col_Divider__B_PWM__GREATER_THAN 3
#define Col_Divider__B_PWM__GREATER_THAN_OR_EQUAL_TO 4
#define Col_Divider__B_PWM__EQUAL 0
#define Col_Divider__B_PWM__FIRMWARE 5



/***************************************
* Data Struct Definition
***************************************/


/**************************************************************************
 * Sleep Wakeup Backup structure for PWM Component
 *************************************************************************/
typedef struct
{

    uint8 PWMEnableState;

    #if(!Col_Divider_UsingFixedFunction)
        uint8 PWMUdb;               /* PWM Current Counter value  */
        #if(!Col_Divider_PWMModeIsCenterAligned)
            uint8 PWMPeriod;
        #endif /* (!Col_Divider_PWMModeIsCenterAligned) */
        #if (Col_Divider_UseStatus)
            uint8 InterruptMaskValue;   /* PWM Current Interrupt Mask */
        #endif /* (Col_Divider_UseStatus) */

        /* Backup for Deadband parameters */
        #if(Col_Divider_DeadBandMode == Col_Divider__B_PWM__DBM_256_CLOCKS || \
            Col_Divider_DeadBandMode == Col_Divider__B_PWM__DBM_2_4_CLOCKS)
            uint8 PWMdeadBandValue; /* Dead Band Counter Current Value */
        #endif /* deadband count is either 2-4 clocks or 256 clocks */

        /* Backup Kill Mode Counter*/
        #if(Col_Divider_KillModeMinTime)
            uint8 PWMKillCounterPeriod; /* Kill Mode period value */
        #endif /* (Col_Divider_KillModeMinTime) */

        /* Backup control register */
        #if(Col_Divider_UseControl)
            uint8 PWMControlRegister; /* PWM Control Register value */
        #endif /* (Col_Divider_UseControl) */

    #endif /* (!Col_Divider_UsingFixedFunction) */

}Col_Divider_backupStruct;


/***************************************
*        Function Prototypes
 **************************************/

void    Col_Divider_Start(void) ;
void    Col_Divider_Stop(void) ;

#if (Col_Divider_UseStatus || Col_Divider_UsingFixedFunction)
    void  Col_Divider_SetInterruptMode(uint8 interruptMode) ;
    uint8 Col_Divider_ReadStatusRegister(void) ;
#endif /* (Col_Divider_UseStatus || Col_Divider_UsingFixedFunction) */

#define Col_Divider_GetInterruptSource() Col_Divider_ReadStatusRegister()

#if (Col_Divider_UseControl)
    uint8 Col_Divider_ReadControlRegister(void) ;
    void  Col_Divider_WriteControlRegister(uint8 control)
          ;
#endif /* (Col_Divider_UseControl) */

#if (Col_Divider_UseOneCompareMode)
   #if (Col_Divider_CompareMode1SW)
       void    Col_Divider_SetCompareMode(uint8 comparemode)
               ;
   #endif /* (Col_Divider_CompareMode1SW) */
#else
    #if (Col_Divider_CompareMode1SW)
        void    Col_Divider_SetCompareMode1(uint8 comparemode)
                ;
    #endif /* (Col_Divider_CompareMode1SW) */
    #if (Col_Divider_CompareMode2SW)
        void    Col_Divider_SetCompareMode2(uint8 comparemode)
                ;
    #endif /* (Col_Divider_CompareMode2SW) */
#endif /* (Col_Divider_UseOneCompareMode) */

#if (!Col_Divider_UsingFixedFunction)
    uint8   Col_Divider_ReadCounter(void) ;
    uint8 Col_Divider_ReadCapture(void) ;

    #if (Col_Divider_UseStatus)
            void Col_Divider_ClearFIFO(void) ;
    #endif /* (Col_Divider_UseStatus) */

    void    Col_Divider_WriteCounter(uint8 counter)
            ;
#endif /* (!Col_Divider_UsingFixedFunction) */

void    Col_Divider_WritePeriod(uint8 period)
        ;
uint8 Col_Divider_ReadPeriod(void) ;

#if (Col_Divider_UseOneCompareMode)
    void    Col_Divider_WriteCompare(uint8 compare)
            ;
    uint8 Col_Divider_ReadCompare(void) ;
#else
    void    Col_Divider_WriteCompare1(uint8 compare)
            ;
    uint8 Col_Divider_ReadCompare1(void) ;
    void    Col_Divider_WriteCompare2(uint8 compare)
            ;
    uint8 Col_Divider_ReadCompare2(void) ;
#endif /* (Col_Divider_UseOneCompareMode) */


#if (Col_Divider_DeadBandUsed)
    void    Col_Divider_WriteDeadTime(uint8 deadtime) ;
    uint8   Col_Divider_ReadDeadTime(void) ;
#endif /* (Col_Divider_DeadBandUsed) */

#if ( Col_Divider_KillModeMinTime)
    void Col_Divider_WriteKillTime(uint8 killtime) ;
    uint8 Col_Divider_ReadKillTime(void) ;
#endif /* ( Col_Divider_KillModeMinTime) */

void Col_Divider_Init(void) ;
void Col_Divider_Enable(void) ;
void Col_Divider_Sleep(void) ;
void Col_Divider_Wakeup(void) ;
void Col_Divider_SaveConfig(void) ;
void Col_Divider_RestoreConfig(void) ;


/***************************************
*         Initialization Values
**************************************/
#define Col_Divider_INIT_PERIOD_VALUE          (179u)
#define Col_Divider_INIT_COMPARE_VALUE1        (127u)
#define Col_Divider_INIT_COMPARE_VALUE2        (63u)
#define Col_Divider_INIT_INTERRUPTS_MODE       (uint8)(((uint8)(0u <<   \
                                                    Col_Divider_STATUS_TC_INT_EN_MASK_SHIFT)) | \
                                                    (uint8)((uint8)(0u <<  \
                                                    Col_Divider_STATUS_CMP2_INT_EN_MASK_SHIFT)) | \
                                                    (uint8)((uint8)(0u <<  \
                                                    Col_Divider_STATUS_CMP1_INT_EN_MASK_SHIFT )) | \
                                                    (uint8)((uint8)(0u <<  \
                                                    Col_Divider_STATUS_KILL_INT_EN_MASK_SHIFT )))
#define Col_Divider_DEFAULT_COMPARE2_MODE      (uint8)((uint8)1u <<  Col_Divider_CTRL_CMPMODE2_SHIFT)
#define Col_Divider_DEFAULT_COMPARE1_MODE      (uint8)((uint8)1u <<  Col_Divider_CTRL_CMPMODE1_SHIFT)
#define Col_Divider_INIT_DEAD_TIME             (1u)


/********************************
*         Registers
******************************** */

#if (Col_Divider_UsingFixedFunction)
   #define Col_Divider_PERIOD_LSB              (*(reg16 *) Col_Divider_PWMHW__PER0)
   #define Col_Divider_PERIOD_LSB_PTR          ( (reg16 *) Col_Divider_PWMHW__PER0)
   #define Col_Divider_COMPARE1_LSB            (*(reg16 *) Col_Divider_PWMHW__CNT_CMP0)
   #define Col_Divider_COMPARE1_LSB_PTR        ( (reg16 *) Col_Divider_PWMHW__CNT_CMP0)
   #define Col_Divider_COMPARE2_LSB            (0x00u)
   #define Col_Divider_COMPARE2_LSB_PTR        (0x00u)
   #define Col_Divider_COUNTER_LSB             (*(reg16 *) Col_Divider_PWMHW__CNT_CMP0)
   #define Col_Divider_COUNTER_LSB_PTR         ( (reg16 *) Col_Divider_PWMHW__CNT_CMP0)
   #define Col_Divider_CAPTURE_LSB             (*(reg16 *) Col_Divider_PWMHW__CAP0)
   #define Col_Divider_CAPTURE_LSB_PTR         ( (reg16 *) Col_Divider_PWMHW__CAP0)
   #define Col_Divider_RT1                     (*(reg8 *)  Col_Divider_PWMHW__RT1)
   #define Col_Divider_RT1_PTR                 ( (reg8 *)  Col_Divider_PWMHW__RT1)

#else
   #if (Col_Divider_Resolution == 8u) /* 8bit - PWM */

       #if(Col_Divider_PWMModeIsCenterAligned)
           #define Col_Divider_PERIOD_LSB      (*(reg8 *)  Col_Divider_PWMUDB_sP8_pwmdp_u0__D1_REG)
           #define Col_Divider_PERIOD_LSB_PTR  ((reg8 *)   Col_Divider_PWMUDB_sP8_pwmdp_u0__D1_REG)
       #else
           #define Col_Divider_PERIOD_LSB      (*(reg8 *)  Col_Divider_PWMUDB_sP8_pwmdp_u0__F0_REG)
           #define Col_Divider_PERIOD_LSB_PTR  ((reg8 *)   Col_Divider_PWMUDB_sP8_pwmdp_u0__F0_REG)
       #endif /* (Col_Divider_PWMModeIsCenterAligned) */

       #define Col_Divider_COMPARE1_LSB        (*(reg8 *)  Col_Divider_PWMUDB_sP8_pwmdp_u0__D0_REG)
       #define Col_Divider_COMPARE1_LSB_PTR    ((reg8 *)   Col_Divider_PWMUDB_sP8_pwmdp_u0__D0_REG)
       #define Col_Divider_COMPARE2_LSB        (*(reg8 *)  Col_Divider_PWMUDB_sP8_pwmdp_u0__D1_REG)
       #define Col_Divider_COMPARE2_LSB_PTR    ((reg8 *)   Col_Divider_PWMUDB_sP8_pwmdp_u0__D1_REG)
       #define Col_Divider_COUNTERCAP_LSB      (*(reg8 *)  Col_Divider_PWMUDB_sP8_pwmdp_u0__A1_REG)
       #define Col_Divider_COUNTERCAP_LSB_PTR  ((reg8 *)   Col_Divider_PWMUDB_sP8_pwmdp_u0__A1_REG)
       #define Col_Divider_COUNTER_LSB         (*(reg8 *)  Col_Divider_PWMUDB_sP8_pwmdp_u0__A0_REG)
       #define Col_Divider_COUNTER_LSB_PTR     ((reg8 *)   Col_Divider_PWMUDB_sP8_pwmdp_u0__A0_REG)
       #define Col_Divider_CAPTURE_LSB         (*(reg8 *)  Col_Divider_PWMUDB_sP8_pwmdp_u0__F1_REG)
       #define Col_Divider_CAPTURE_LSB_PTR     ((reg8 *)   Col_Divider_PWMUDB_sP8_pwmdp_u0__F1_REG)

   #else
        #if(CY_PSOC3) /* 8-bit address space */
            #if(Col_Divider_PWMModeIsCenterAligned)
               #define Col_Divider_PERIOD_LSB      (*(reg16 *) Col_Divider_PWMUDB_sP8_pwmdp_u0__D1_REG)
               #define Col_Divider_PERIOD_LSB_PTR  ((reg16 *)  Col_Divider_PWMUDB_sP8_pwmdp_u0__D1_REG)
            #else
               #define Col_Divider_PERIOD_LSB      (*(reg16 *) Col_Divider_PWMUDB_sP8_pwmdp_u0__F0_REG)
               #define Col_Divider_PERIOD_LSB_PTR  ((reg16 *)  Col_Divider_PWMUDB_sP8_pwmdp_u0__F0_REG)
            #endif /* (Col_Divider_PWMModeIsCenterAligned) */

            #define Col_Divider_COMPARE1_LSB       (*(reg16 *) Col_Divider_PWMUDB_sP8_pwmdp_u0__D0_REG)
            #define Col_Divider_COMPARE1_LSB_PTR   ((reg16 *)  Col_Divider_PWMUDB_sP8_pwmdp_u0__D0_REG)
            #define Col_Divider_COMPARE2_LSB       (*(reg16 *) Col_Divider_PWMUDB_sP8_pwmdp_u0__D1_REG)
            #define Col_Divider_COMPARE2_LSB_PTR   ((reg16 *)  Col_Divider_PWMUDB_sP8_pwmdp_u0__D1_REG)
            #define Col_Divider_COUNTERCAP_LSB     (*(reg16 *) Col_Divider_PWMUDB_sP8_pwmdp_u0__A1_REG)
            #define Col_Divider_COUNTERCAP_LSB_PTR ((reg16 *)  Col_Divider_PWMUDB_sP8_pwmdp_u0__A1_REG)
            #define Col_Divider_COUNTER_LSB        (*(reg16 *) Col_Divider_PWMUDB_sP8_pwmdp_u0__A0_REG)
            #define Col_Divider_COUNTER_LSB_PTR    ((reg16 *)  Col_Divider_PWMUDB_sP8_pwmdp_u0__A0_REG)
            #define Col_Divider_CAPTURE_LSB        (*(reg16 *) Col_Divider_PWMUDB_sP8_pwmdp_u0__F1_REG)
            #define Col_Divider_CAPTURE_LSB_PTR    ((reg16 *)  Col_Divider_PWMUDB_sP8_pwmdp_u0__F1_REG)
        #else
            #if(Col_Divider_PWMModeIsCenterAligned)
               #define Col_Divider_PERIOD_LSB      (*(reg16 *) Col_Divider_PWMUDB_sP8_pwmdp_u0__16BIT_D1_REG)
               #define Col_Divider_PERIOD_LSB_PTR  ((reg16 *)  Col_Divider_PWMUDB_sP8_pwmdp_u0__16BIT_D1_REG)
            #else
               #define Col_Divider_PERIOD_LSB      (*(reg16 *) Col_Divider_PWMUDB_sP8_pwmdp_u0__16BIT_F0_REG)
               #define Col_Divider_PERIOD_LSB_PTR  ((reg16 *)  Col_Divider_PWMUDB_sP8_pwmdp_u0__16BIT_F0_REG)
            #endif /* (Col_Divider_PWMModeIsCenterAligned) */

            #define Col_Divider_COMPARE1_LSB       (*(reg16 *) Col_Divider_PWMUDB_sP8_pwmdp_u0__16BIT_D0_REG)
            #define Col_Divider_COMPARE1_LSB_PTR   ((reg16 *)  Col_Divider_PWMUDB_sP8_pwmdp_u0__16BIT_D0_REG)
            #define Col_Divider_COMPARE2_LSB       (*(reg16 *) Col_Divider_PWMUDB_sP8_pwmdp_u0__16BIT_D1_REG)
            #define Col_Divider_COMPARE2_LSB_PTR   ((reg16 *)  Col_Divider_PWMUDB_sP8_pwmdp_u0__16BIT_D1_REG)
            #define Col_Divider_COUNTERCAP_LSB     (*(reg16 *) Col_Divider_PWMUDB_sP8_pwmdp_u0__16BIT_A1_REG)
            #define Col_Divider_COUNTERCAP_LSB_PTR ((reg16 *)  Col_Divider_PWMUDB_sP8_pwmdp_u0__16BIT_A1_REG)
            #define Col_Divider_COUNTER_LSB        (*(reg16 *) Col_Divider_PWMUDB_sP8_pwmdp_u0__16BIT_A0_REG)
            #define Col_Divider_COUNTER_LSB_PTR    ((reg16 *)  Col_Divider_PWMUDB_sP8_pwmdp_u0__16BIT_A0_REG)
            #define Col_Divider_CAPTURE_LSB        (*(reg16 *) Col_Divider_PWMUDB_sP8_pwmdp_u0__16BIT_F1_REG)
            #define Col_Divider_CAPTURE_LSB_PTR    ((reg16 *)  Col_Divider_PWMUDB_sP8_pwmdp_u0__16BIT_F1_REG)
        #endif /* (CY_PSOC3) */

       #define Col_Divider_AUX_CONTROLDP1          (*(reg8 *)  Col_Divider_PWMUDB_sP8_pwmdp_u1__DP_AUX_CTL_REG)
       #define Col_Divider_AUX_CONTROLDP1_PTR      ((reg8 *)   Col_Divider_PWMUDB_sP8_pwmdp_u1__DP_AUX_CTL_REG)

   #endif /* (Col_Divider_Resolution == 8) */

   #define Col_Divider_COUNTERCAP_LSB_PTR_8BIT ( (reg8 *)  Col_Divider_PWMUDB_sP8_pwmdp_u0__A1_REG)
   #define Col_Divider_AUX_CONTROLDP0          (*(reg8 *)  Col_Divider_PWMUDB_sP8_pwmdp_u0__DP_AUX_CTL_REG)
   #define Col_Divider_AUX_CONTROLDP0_PTR      ((reg8 *)   Col_Divider_PWMUDB_sP8_pwmdp_u0__DP_AUX_CTL_REG)

#endif /* (Col_Divider_UsingFixedFunction) */

#if(Col_Divider_KillModeMinTime )
    #define Col_Divider_KILLMODEMINTIME        (*(reg8 *)  Col_Divider_PWMUDB_sKM_killmodecounterdp_u0__D0_REG)
    #define Col_Divider_KILLMODEMINTIME_PTR    ((reg8 *)   Col_Divider_PWMUDB_sKM_killmodecounterdp_u0__D0_REG)
    /* Fixed Function Block has no Kill Mode parameters because it is Asynchronous only */
#endif /* (Col_Divider_KillModeMinTime ) */

#if(Col_Divider_DeadBandMode == Col_Divider__B_PWM__DBM_256_CLOCKS)
    #define Col_Divider_DEADBAND_COUNT         (*(reg8 *)  Col_Divider_PWMUDB_sDB255_deadbandcounterdp_u0__D0_REG)
    #define Col_Divider_DEADBAND_COUNT_PTR     ((reg8 *)   Col_Divider_PWMUDB_sDB255_deadbandcounterdp_u0__D0_REG)
    #define Col_Divider_DEADBAND_LSB_PTR       ((reg8 *)   Col_Divider_PWMUDB_sDB255_deadbandcounterdp_u0__A0_REG)
    #define Col_Divider_DEADBAND_LSB           (*(reg8 *)  Col_Divider_PWMUDB_sDB255_deadbandcounterdp_u0__A0_REG)
#elif(Col_Divider_DeadBandMode == Col_Divider__B_PWM__DBM_2_4_CLOCKS)
    
    /* In Fixed Function Block these bits are in the control blocks control register */
    #if (Col_Divider_UsingFixedFunction)
        #define Col_Divider_DEADBAND_COUNT         (*(reg8 *)  Col_Divider_PWMHW__CFG0)
        #define Col_Divider_DEADBAND_COUNT_PTR     ((reg8 *)   Col_Divider_PWMHW__CFG0)
        #define Col_Divider_DEADBAND_COUNT_MASK    (uint8)((uint8)0x03u << Col_Divider_DEADBAND_COUNT_SHIFT)

        /* As defined by the Register Map as DEADBAND_PERIOD[1:0] in CFG0 */
        #define Col_Divider_DEADBAND_COUNT_SHIFT   (0x06u)
    #else
        /* Lower two bits of the added control register define the count 1-3 */
        #define Col_Divider_DEADBAND_COUNT         (*(reg8 *)  Col_Divider_PWMUDB_genblk7_dbctrlreg__CONTROL_REG)
        #define Col_Divider_DEADBAND_COUNT_PTR     ((reg8 *)   Col_Divider_PWMUDB_genblk7_dbctrlreg__CONTROL_REG)
        #define Col_Divider_DEADBAND_COUNT_MASK    (uint8)((uint8)0x03u << Col_Divider_DEADBAND_COUNT_SHIFT)

        /* As defined by the verilog implementation of the Control Register */
        #define Col_Divider_DEADBAND_COUNT_SHIFT   (0x00u)
    #endif /* (Col_Divider_UsingFixedFunction) */
#endif /* (Col_Divider_DeadBandMode == Col_Divider__B_PWM__DBM_256_CLOCKS) */



#if (Col_Divider_UsingFixedFunction)
    #define Col_Divider_STATUS                 (*(reg8 *) Col_Divider_PWMHW__SR0)
    #define Col_Divider_STATUS_PTR             ((reg8 *) Col_Divider_PWMHW__SR0)
    #define Col_Divider_STATUS_MASK            (*(reg8 *) Col_Divider_PWMHW__SR0)
    #define Col_Divider_STATUS_MASK_PTR        ((reg8 *) Col_Divider_PWMHW__SR0)
    #define Col_Divider_CONTROL                (*(reg8 *) Col_Divider_PWMHW__CFG0)
    #define Col_Divider_CONTROL_PTR            ((reg8 *) Col_Divider_PWMHW__CFG0)
    #define Col_Divider_CONTROL2               (*(reg8 *) Col_Divider_PWMHW__CFG1)
    #define Col_Divider_CONTROL3               (*(reg8 *) Col_Divider_PWMHW__CFG2)
    #define Col_Divider_GLOBAL_ENABLE          (*(reg8 *) Col_Divider_PWMHW__PM_ACT_CFG)
    #define Col_Divider_GLOBAL_ENABLE_PTR      ( (reg8 *) Col_Divider_PWMHW__PM_ACT_CFG)
    #define Col_Divider_GLOBAL_STBY_ENABLE     (*(reg8 *) Col_Divider_PWMHW__PM_STBY_CFG)
    #define Col_Divider_GLOBAL_STBY_ENABLE_PTR ( (reg8 *) Col_Divider_PWMHW__PM_STBY_CFG)


    /***********************************
    *          Constants
    ***********************************/

    /* Fixed Function Block Chosen */
    #define Col_Divider_BLOCK_EN_MASK          (Col_Divider_PWMHW__PM_ACT_MSK)
    #define Col_Divider_BLOCK_STBY_EN_MASK     (Col_Divider_PWMHW__PM_STBY_MSK)
    
    /* Control Register definitions */
    #define Col_Divider_CTRL_ENABLE_SHIFT      (0x00u)

    /* As defined by Register map as MODE_CFG bits in CFG2*/
    #define Col_Divider_CTRL_CMPMODE1_SHIFT    (0x04u)

    /* As defined by Register map */
    #define Col_Divider_CTRL_DEAD_TIME_SHIFT   (0x06u)  

    /* Fixed Function Block Only CFG register bit definitions */
    /*  Set to compare mode */
    #define Col_Divider_CFG0_MODE              (0x02u)   

    /* Enable the block to run */
    #define Col_Divider_CFG0_ENABLE            (0x01u)   
    
    /* As defined by Register map as DB bit in CFG0 */
    #define Col_Divider_CFG0_DB                (0x20u)   

    /* Control Register Bit Masks */
    #define Col_Divider_CTRL_ENABLE            (uint8)((uint8)0x01u << Col_Divider_CTRL_ENABLE_SHIFT)
    #define Col_Divider_CTRL_RESET             (uint8)((uint8)0x01u << Col_Divider_CTRL_RESET_SHIFT)
    #define Col_Divider_CTRL_CMPMODE2_MASK     (uint8)((uint8)0x07u << Col_Divider_CTRL_CMPMODE2_SHIFT)
    #define Col_Divider_CTRL_CMPMODE1_MASK     (uint8)((uint8)0x07u << Col_Divider_CTRL_CMPMODE1_SHIFT)

    /* Control2 Register Bit Masks */
    /* As defined in Register Map, Part of the TMRX_CFG1 register */
    #define Col_Divider_CTRL2_IRQ_SEL_SHIFT    (0x00u)
    #define Col_Divider_CTRL2_IRQ_SEL          (uint8)((uint8)0x01u << Col_Divider_CTRL2_IRQ_SEL_SHIFT)

    /* Status Register Bit Locations */
    /* As defined by Register map as TC in SR0 */
    #define Col_Divider_STATUS_TC_SHIFT        (0x07u)   
    
    /* As defined by the Register map as CAP_CMP in SR0 */
    #define Col_Divider_STATUS_CMP1_SHIFT      (0x06u)   

    /* Status Register Interrupt Enable Bit Locations */
    #define Col_Divider_STATUS_KILL_INT_EN_MASK_SHIFT          (0x00u)
    #define Col_Divider_STATUS_TC_INT_EN_MASK_SHIFT            (Col_Divider_STATUS_TC_SHIFT - 4u)
    #define Col_Divider_STATUS_CMP2_INT_EN_MASK_SHIFT          (0x00u)
    #define Col_Divider_STATUS_CMP1_INT_EN_MASK_SHIFT          (Col_Divider_STATUS_CMP1_SHIFT - 4u)

    /* Status Register Bit Masks */
    #define Col_Divider_STATUS_TC              (uint8)((uint8)0x01u << Col_Divider_STATUS_TC_SHIFT)
    #define Col_Divider_STATUS_CMP1            (uint8)((uint8)0x01u << Col_Divider_STATUS_CMP1_SHIFT)

    /* Status Register Interrupt Bit Masks */
    #define Col_Divider_STATUS_TC_INT_EN_MASK              (uint8)((uint8)Col_Divider_STATUS_TC >> 4u)
    #define Col_Divider_STATUS_CMP1_INT_EN_MASK            (uint8)((uint8)Col_Divider_STATUS_CMP1 >> 4u)

    /*RT1 Synch Constants */
    #define Col_Divider_RT1_SHIFT             (0x04u)

    /* Sync TC and CMP bit masks */
    #define Col_Divider_RT1_MASK              (uint8)((uint8)0x03u << Col_Divider_RT1_SHIFT)
    #define Col_Divider_SYNC                  (uint8)((uint8)0x03u << Col_Divider_RT1_SHIFT)
    #define Col_Divider_SYNCDSI_SHIFT         (0x00u)

    /* Sync all DSI inputs */
    #define Col_Divider_SYNCDSI_MASK          (uint8)((uint8)0x0Fu << Col_Divider_SYNCDSI_SHIFT)

    /* Sync all DSI inputs */
    #define Col_Divider_SYNCDSI_EN            (uint8)((uint8)0x0Fu << Col_Divider_SYNCDSI_SHIFT)


#else
    #define Col_Divider_STATUS                (*(reg8 *)   Col_Divider_PWMUDB_genblk8_stsreg__STATUS_REG )
    #define Col_Divider_STATUS_PTR            ((reg8 *)    Col_Divider_PWMUDB_genblk8_stsreg__STATUS_REG )
    #define Col_Divider_STATUS_MASK           (*(reg8 *)   Col_Divider_PWMUDB_genblk8_stsreg__MASK_REG)
    #define Col_Divider_STATUS_MASK_PTR       ((reg8 *)    Col_Divider_PWMUDB_genblk8_stsreg__MASK_REG)
    #define Col_Divider_STATUS_AUX_CTRL       (*(reg8 *)   Col_Divider_PWMUDB_genblk8_stsreg__STATUS_AUX_CTL_REG)
    #define Col_Divider_CONTROL               (*(reg8 *)   Col_Divider_PWMUDB_genblk1_ctrlreg__CONTROL_REG)
    #define Col_Divider_CONTROL_PTR           ((reg8 *)    Col_Divider_PWMUDB_genblk1_ctrlreg__CONTROL_REG)


    /***********************************
    *          Constants
    ***********************************/

    /* Control Register bit definitions */
    #define Col_Divider_CTRL_ENABLE_SHIFT      (0x07u)
    #define Col_Divider_CTRL_RESET_SHIFT       (0x06u)
    #define Col_Divider_CTRL_CMPMODE2_SHIFT    (0x03u)
    #define Col_Divider_CTRL_CMPMODE1_SHIFT    (0x00u)
    #define Col_Divider_CTRL_DEAD_TIME_SHIFT   (0x00u)   /* No Shift Needed for UDB block */
    
    /* Control Register Bit Masks */
    #define Col_Divider_CTRL_ENABLE            (uint8)((uint8)0x01u << Col_Divider_CTRL_ENABLE_SHIFT)
    #define Col_Divider_CTRL_RESET             (uint8)((uint8)0x01u << Col_Divider_CTRL_RESET_SHIFT)
    #define Col_Divider_CTRL_CMPMODE2_MASK     (uint8)((uint8)0x07u << Col_Divider_CTRL_CMPMODE2_SHIFT)
    #define Col_Divider_CTRL_CMPMODE1_MASK     (uint8)((uint8)0x07u << Col_Divider_CTRL_CMPMODE1_SHIFT)

    /* Status Register Bit Locations */
    #define Col_Divider_STATUS_KILL_SHIFT          (0x05u)
    #define Col_Divider_STATUS_FIFONEMPTY_SHIFT    (0x04u)
    #define Col_Divider_STATUS_FIFOFULL_SHIFT      (0x03u)
    #define Col_Divider_STATUS_TC_SHIFT            (0x02u)
    #define Col_Divider_STATUS_CMP2_SHIFT          (0x01u)
    #define Col_Divider_STATUS_CMP1_SHIFT          (0x00u)

    /* Status Register Interrupt Enable Bit Locations - UDB Status Interrupt Mask match Status Bit Locations*/
    #define Col_Divider_STATUS_KILL_INT_EN_MASK_SHIFT          (Col_Divider_STATUS_KILL_SHIFT)
    #define Col_Divider_STATUS_FIFONEMPTY_INT_EN_MASK_SHIFT    (Col_Divider_STATUS_FIFONEMPTY_SHIFT)
    #define Col_Divider_STATUS_FIFOFULL_INT_EN_MASK_SHIFT      (Col_Divider_STATUS_FIFOFULL_SHIFT)
    #define Col_Divider_STATUS_TC_INT_EN_MASK_SHIFT            (Col_Divider_STATUS_TC_SHIFT)
    #define Col_Divider_STATUS_CMP2_INT_EN_MASK_SHIFT          (Col_Divider_STATUS_CMP2_SHIFT)
    #define Col_Divider_STATUS_CMP1_INT_EN_MASK_SHIFT          (Col_Divider_STATUS_CMP1_SHIFT)

    /* Status Register Bit Masks */
    #define Col_Divider_STATUS_KILL            (uint8)((uint8)0x00u << Col_Divider_STATUS_KILL_SHIFT )
    #define Col_Divider_STATUS_FIFOFULL        (uint8)((uint8)0x01u << Col_Divider_STATUS_FIFOFULL_SHIFT)
    #define Col_Divider_STATUS_FIFONEMPTY      (uint8)((uint8)0x01u << Col_Divider_STATUS_FIFONEMPTY_SHIFT)
    #define Col_Divider_STATUS_TC              (uint8)((uint8)0x01u << Col_Divider_STATUS_TC_SHIFT)
    #define Col_Divider_STATUS_CMP2            (uint8)((uint8)0x01u << Col_Divider_STATUS_CMP2_SHIFT)
    #define Col_Divider_STATUS_CMP1            (uint8)((uint8)0x01u << Col_Divider_STATUS_CMP1_SHIFT)

    /* Status Register Interrupt Bit Masks  - UDB Status Interrupt Mask match Status Bit Locations */
    #define Col_Divider_STATUS_KILL_INT_EN_MASK            (Col_Divider_STATUS_KILL)
    #define Col_Divider_STATUS_FIFOFULL_INT_EN_MASK        (Col_Divider_STATUS_FIFOFULL)
    #define Col_Divider_STATUS_FIFONEMPTY_INT_EN_MASK      (Col_Divider_STATUS_FIFONEMPTY)
    #define Col_Divider_STATUS_TC_INT_EN_MASK              (Col_Divider_STATUS_TC)
    #define Col_Divider_STATUS_CMP2_INT_EN_MASK            (Col_Divider_STATUS_CMP2)
    #define Col_Divider_STATUS_CMP1_INT_EN_MASK            (Col_Divider_STATUS_CMP1)

    /* Datapath Auxillary Control Register bit definitions */
    #define Col_Divider_AUX_CTRL_FIFO0_CLR         (0x01u)
    #define Col_Divider_AUX_CTRL_FIFO1_CLR         (0x02u)
    #define Col_Divider_AUX_CTRL_FIFO0_LVL         (0x04u)
    #define Col_Divider_AUX_CTRL_FIFO1_LVL         (0x08u)
    #define Col_Divider_STATUS_ACTL_INT_EN_MASK    (0x10u) /* As defined for the ACTL Register */
#endif /* Col_Divider_UsingFixedFunction */

#endif  /* CY_PWM_Col_Divider_H */


/* [] END OF FILE */
