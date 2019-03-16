/*******************************************************************************
* File Name: COL_PWM_PM.c
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

#include "COL_PWM.h"

static COL_PWM_backupStruct COL_PWM_backup;


/*******************************************************************************
* Function Name: COL_PWM_SaveConfig
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
*  COL_PWM_backup:  Variables of this global structure are modified to
*  store the values of non retention configuration registers when Sleep() API is
*  called.
*
*******************************************************************************/
void COL_PWM_SaveConfig(void) 
{

    #if(!COL_PWM_UsingFixedFunction)
        #if(!COL_PWM_PWMModeIsCenterAligned)
            COL_PWM_backup.PWMPeriod = COL_PWM_ReadPeriod();
        #endif /* (!COL_PWM_PWMModeIsCenterAligned) */
        COL_PWM_backup.PWMUdb = COL_PWM_ReadCounter();
        #if (COL_PWM_UseStatus)
            COL_PWM_backup.InterruptMaskValue = COL_PWM_STATUS_MASK;
        #endif /* (COL_PWM_UseStatus) */

        #if(COL_PWM_DeadBandMode == COL_PWM__B_PWM__DBM_256_CLOCKS || \
            COL_PWM_DeadBandMode == COL_PWM__B_PWM__DBM_2_4_CLOCKS)
            COL_PWM_backup.PWMdeadBandValue = COL_PWM_ReadDeadTime();
        #endif /*  deadband count is either 2-4 clocks or 256 clocks */

        #if(COL_PWM_KillModeMinTime)
             COL_PWM_backup.PWMKillCounterPeriod = COL_PWM_ReadKillTime();
        #endif /* (COL_PWM_KillModeMinTime) */

        #if(COL_PWM_UseControl)
            COL_PWM_backup.PWMControlRegister = COL_PWM_ReadControlRegister();
        #endif /* (COL_PWM_UseControl) */
    #endif  /* (!COL_PWM_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: COL_PWM_RestoreConfig
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
*  COL_PWM_backup:  Variables of this global structure are used to
*  restore the values of non retention registers on wakeup from sleep mode.
*
*******************************************************************************/
void COL_PWM_RestoreConfig(void) 
{
        #if(!COL_PWM_UsingFixedFunction)
            #if(!COL_PWM_PWMModeIsCenterAligned)
                COL_PWM_WritePeriod(COL_PWM_backup.PWMPeriod);
            #endif /* (!COL_PWM_PWMModeIsCenterAligned) */

            COL_PWM_WriteCounter(COL_PWM_backup.PWMUdb);

            #if (COL_PWM_UseStatus)
                COL_PWM_STATUS_MASK = COL_PWM_backup.InterruptMaskValue;
            #endif /* (COL_PWM_UseStatus) */

            #if(COL_PWM_DeadBandMode == COL_PWM__B_PWM__DBM_256_CLOCKS || \
                COL_PWM_DeadBandMode == COL_PWM__B_PWM__DBM_2_4_CLOCKS)
                COL_PWM_WriteDeadTime(COL_PWM_backup.PWMdeadBandValue);
            #endif /* deadband count is either 2-4 clocks or 256 clocks */

            #if(COL_PWM_KillModeMinTime)
                COL_PWM_WriteKillTime(COL_PWM_backup.PWMKillCounterPeriod);
            #endif /* (COL_PWM_KillModeMinTime) */

            #if(COL_PWM_UseControl)
                COL_PWM_WriteControlRegister(COL_PWM_backup.PWMControlRegister);
            #endif /* (COL_PWM_UseControl) */
        #endif  /* (!COL_PWM_UsingFixedFunction) */
    }


/*******************************************************************************
* Function Name: COL_PWM_Sleep
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
*  COL_PWM_backup.PWMEnableState:  Is modified depending on the enable
*  state of the block before entering sleep mode.
*
*******************************************************************************/
void COL_PWM_Sleep(void) 
{
    #if(COL_PWM_UseControl)
        if(COL_PWM_CTRL_ENABLE == (COL_PWM_CONTROL & COL_PWM_CTRL_ENABLE))
        {
            /*Component is enabled */
            COL_PWM_backup.PWMEnableState = 1u;
        }
        else
        {
            /* Component is disabled */
            COL_PWM_backup.PWMEnableState = 0u;
        }
    #endif /* (COL_PWM_UseControl) */

    /* Stop component */
    COL_PWM_Stop();

    /* Save registers configuration */
    COL_PWM_SaveConfig();
}


/*******************************************************************************
* Function Name: COL_PWM_Wakeup
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
*  COL_PWM_backup.pwmEnable:  Is used to restore the enable state of
*  block on wakeup from sleep mode.
*
*******************************************************************************/
void COL_PWM_Wakeup(void) 
{
     /* Restore registers values */
    COL_PWM_RestoreConfig();

    if(COL_PWM_backup.PWMEnableState != 0u)
    {
        /* Enable component's operation */
        COL_PWM_Enable();
    } /* Do nothing if component's block was disabled before */

}


/* [] END OF FILE */
