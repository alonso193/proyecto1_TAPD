/*******************************************************************************
* File Name: ROW_PWM_PM.c
* Version 3.30
*
* Description:
*  This file provides the power management source code to API for the
*  PWM.
*
* Note:
*
********************************************************************************
* Copyright 2008-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "ROW_PWM.h"

static ROW_PWM_backupStruct ROW_PWM_backup;


/*******************************************************************************
* Function Name: ROW_PWM_SaveConfig
********************************************************************************
*
* Summary:
*  Saves the current user configuration of the component.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Global variables:
*  ROW_PWM_backup:  Variables of this global structure are modified to
*  store the values of non retention configuration registers when Sleep() API is
*  called.
*
*******************************************************************************/
void ROW_PWM_SaveConfig(void) 
{

    #if(!ROW_PWM_UsingFixedFunction)
        #if(!ROW_PWM_PWMModeIsCenterAligned)
            ROW_PWM_backup.PWMPeriod = ROW_PWM_ReadPeriod();
        #endif /* (!ROW_PWM_PWMModeIsCenterAligned) */
        ROW_PWM_backup.PWMUdb = ROW_PWM_ReadCounter();
        #if (ROW_PWM_UseStatus)
            ROW_PWM_backup.InterruptMaskValue = ROW_PWM_STATUS_MASK;
        #endif /* (ROW_PWM_UseStatus) */

        #if(ROW_PWM_DeadBandMode == ROW_PWM__B_PWM__DBM_256_CLOCKS || \
            ROW_PWM_DeadBandMode == ROW_PWM__B_PWM__DBM_2_4_CLOCKS)
            ROW_PWM_backup.PWMdeadBandValue = ROW_PWM_ReadDeadTime();
        #endif /*  deadband count is either 2-4 clocks or 256 clocks */

        #if(ROW_PWM_KillModeMinTime)
             ROW_PWM_backup.PWMKillCounterPeriod = ROW_PWM_ReadKillTime();
        #endif /* (ROW_PWM_KillModeMinTime) */

        #if(ROW_PWM_UseControl)
            ROW_PWM_backup.PWMControlRegister = ROW_PWM_ReadControlRegister();
        #endif /* (ROW_PWM_UseControl) */
    #endif  /* (!ROW_PWM_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: ROW_PWM_RestoreConfig
********************************************************************************
*
* Summary:
*  Restores the current user configuration of the component.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Global variables:
*  ROW_PWM_backup:  Variables of this global structure are used to
*  restore the values of non retention registers on wakeup from sleep mode.
*
*******************************************************************************/
void ROW_PWM_RestoreConfig(void) 
{
        #if(!ROW_PWM_UsingFixedFunction)
            #if(!ROW_PWM_PWMModeIsCenterAligned)
                ROW_PWM_WritePeriod(ROW_PWM_backup.PWMPeriod);
            #endif /* (!ROW_PWM_PWMModeIsCenterAligned) */

            ROW_PWM_WriteCounter(ROW_PWM_backup.PWMUdb);

            #if (ROW_PWM_UseStatus)
                ROW_PWM_STATUS_MASK = ROW_PWM_backup.InterruptMaskValue;
            #endif /* (ROW_PWM_UseStatus) */

            #if(ROW_PWM_DeadBandMode == ROW_PWM__B_PWM__DBM_256_CLOCKS || \
                ROW_PWM_DeadBandMode == ROW_PWM__B_PWM__DBM_2_4_CLOCKS)
                ROW_PWM_WriteDeadTime(ROW_PWM_backup.PWMdeadBandValue);
            #endif /* deadband count is either 2-4 clocks or 256 clocks */

            #if(ROW_PWM_KillModeMinTime)
                ROW_PWM_WriteKillTime(ROW_PWM_backup.PWMKillCounterPeriod);
            #endif /* (ROW_PWM_KillModeMinTime) */

            #if(ROW_PWM_UseControl)
                ROW_PWM_WriteControlRegister(ROW_PWM_backup.PWMControlRegister);
            #endif /* (ROW_PWM_UseControl) */
        #endif  /* (!ROW_PWM_UsingFixedFunction) */
    }


/*******************************************************************************
* Function Name: ROW_PWM_Sleep
********************************************************************************
*
* Summary:
*  Disables block's operation and saves the user configuration. Should be called
*  just prior to entering sleep.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Global variables:
*  ROW_PWM_backup.PWMEnableState:  Is modified depending on the enable
*  state of the block before entering sleep mode.
*
*******************************************************************************/
void ROW_PWM_Sleep(void) 
{
    #if(ROW_PWM_UseControl)
        if(ROW_PWM_CTRL_ENABLE == (ROW_PWM_CONTROL & ROW_PWM_CTRL_ENABLE))
        {
            /*Component is enabled */
            ROW_PWM_backup.PWMEnableState = 1u;
        }
        else
        {
            /* Component is disabled */
            ROW_PWM_backup.PWMEnableState = 0u;
        }
    #endif /* (ROW_PWM_UseControl) */

    /* Stop component */
    ROW_PWM_Stop();

    /* Save registers configuration */
    ROW_PWM_SaveConfig();
}


/*******************************************************************************
* Function Name: ROW_PWM_Wakeup
********************************************************************************
*
* Summary:
*  Restores and enables the user configuration. Should be called just after
*  awaking from sleep.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Global variables:
*  ROW_PWM_backup.pwmEnable:  Is used to restore the enable state of
*  block on wakeup from sleep mode.
*
*******************************************************************************/
void ROW_PWM_Wakeup(void) 
{
     /* Restore registers values */
    ROW_PWM_RestoreConfig();

    if(ROW_PWM_backup.PWMEnableState != 0u)
    {
        /* Enable component's operation */
        ROW_PWM_Enable();
    } /* Do nothing if component's block was disabled before */

}


/* [] END OF FILE */
