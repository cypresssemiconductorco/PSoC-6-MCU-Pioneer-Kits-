/******************************************************************************
* File Name: main_cm4.c
*
* Version: 1.10
*
* Description: This project demonstrates connectivity between the PSoC 6 BLE and 
*              CySmart BLE host Emulation tool or mobile device running the CySmart
*              mobile application, to transfer CapSense Proximity information.
*
* Related Document: CE218135_BLE_Proximity.pdf
*
* Hardware Dependency: CY8CKIT-062-BLE PSoC 6 BLE Pioneer Kit
*                      CY8CKIT-028-EPD E-INK Display Shield
*
*******************************************************************************
* Copyright (2017), Cypress Semiconductor Corporation. All rights reserved.
*******************************************************************************
* This software, including source code, documentation and related materials
* (“Software”), is owned by Cypress Semiconductor Corporation or one of its
* subsidiaries (“Cypress”) and is protected by and subject to worldwide patent
* protection (United States and foreign), United States copyright laws and
* international treaty provisions. Therefore, you may use this Software only
* as provided in the license agreement accompanying the software package from
* which you obtained this Software (“EULA”).
*
* If no EULA applies, Cypress hereby grants you a personal, nonexclusive,
* non-transferable license to copy, modify, and compile the Software source
* code solely for use in connection with Cypress’s integrated circuit products.
* Any reproduction, modification, translation, compilation, or representation
* of this Software except as specified above is prohibited without the express
* written permission of Cypress.
*
* Disclaimer: THIS SOFTWARE IS PROVIDED AS-IS, WITH NO WARRANTY OF ANY KIND, 
* EXPRESS OR IMPLIED, INCLUDING, BUT NOT LIMITED TO, NONINFRINGEMENT, IMPLIED 
* WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE. Cypress 
* reserves the right to make changes to the Software without notice. Cypress 
* does not assume any liability arising out of the application or use of the 
* Software or any product or circuit described in the Software. Cypress does 
* not authorize its products for use in any products where a malfunction or 
* failure of the Cypress product may reasonably be expected to result in 
* significant property damage, injury or death (“High Risk Product”). By 
* including Cypress’s product in a High Risk Product, the manufacturer of such 
* system or application assumes all risk of such use and in doing so agrees to 
* indemnify Cypress against all liability.
*******************************************************************************/
/******************************************************************************
* This project demonstrates the capabilities of the PSoC 6 BLE to communicate 
* with a BLE Central device over a custom service, sending CapSense proximity
* sensing inputs. This CapSense custom service allows notifications to be sent  
* to the central device when notifications are enabled.  
*******************************************************************************/

/* Header file includes */
#include "ble_application.h"
#include "led.h"
#include "proximity.h"
#include "low_power.h"
#include "display.h"

/*******************************************************************************
* Function Name: main
********************************************************************************
* Summary:
*  System entrance point. This function calls the initializing functions and
*  shows the instructions to use this code example on the E-INK display. The main
*  function then continuously processes BLE and CapSense events, while entering
*  low power modes if the conditions permit.
*
* Parameters:
*  void
*
* Return:
*  int
*
*******************************************************************************/
int main()
{
	/* Enable global interrupts */
	__enable_irq(); 
           
    /* Initialize the components used for E-INK display, CapSense proximity 
       sensing, BLE and power reduction techniques */
	InitDisplay();
    InitCapSense();
    InitBle();
    InitLowPower();

    /* Display the instructions to evaluate this code example on the E-INK 
       display */
    DisplayInstructions();
    	
    for(;;)
    {
        /* Continuously process BLE events and handle custom BLE services */
        ProcessBleEvents();
        
        /* Evaluate the status of the system and enter low power mode if 
           the conditions permit */
        HandleLowPowerMode();
    }	
}

/* [] END OF FILE */
