/* USER CODE BEGIN Header */
/**
 ******************************************************************************
 * File Name          : freertos.c
 * Description        : Code for freertos applications
 ******************************************************************************
 * @attention
 *
 * <h2><center>&copy; Copyright (c) 2021 STMicroelectronics.
 * All rights reserved.</center></h2>
 *
 * This software component is licensed by ST under Ultimate Liberty license
 * SLA0044, the "License"; You may not use this file except in compliance with
 * the License. You may obtain a copy of the License at:
 *                             www.st.com/SLA0044
 *
 ******************************************************************************
 */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "FreeRTOS.h"
#include "task.h"
#include "main.h"
#include "cmsis_os.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "myMain.h"
#include "HydroDriveLL.h"
int32_t globalSensorTaskPeriod = 10;      //10 ms period for loop()  (100Hz)
int32_t globalCommunicationTaskPeriod = 5;     //5 ms period for loop2()  (200Hz)

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
/* USER CODE BEGIN Variables */

/* USER CODE END Variables */
osThreadId sensorTaskHandle;
uint32_t sensorTaskBuffer[ 1024 ];
osStaticThreadDef_t sensorTaskControlBlock;
osThreadId communicationTaHandle;
uint32_t communicationTaskBuffer[ 1024 ];
osStaticThreadDef_t communicationTaskControlBlock;

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN FunctionPrototypes */

/* USER CODE END FunctionPrototypes */

void sensorTaskFunc(void const * argument);
void communicationTaskFunc(void const * argument);

void MX_FREERTOS_Init(void); /* (MISRA C 2004 rule 8.1) */

/* GetIdleTaskMemory prototype (linked to static allocation support) */
void vApplicationGetIdleTaskMemory( StaticTask_t **ppxIdleTaskTCBBuffer, StackType_t **ppxIdleTaskStackBuffer, uint32_t *pulIdleTaskStackSize );

/* USER CODE BEGIN GET_IDLE_TASK_MEMORY */
static StaticTask_t xIdleTaskTCBBuffer;
static StackType_t xIdleStack[configMINIMAL_STACK_SIZE];

void vApplicationGetIdleTaskMemory(StaticTask_t **ppxIdleTaskTCBBuffer,
		StackType_t **ppxIdleTaskStackBuffer, uint32_t *pulIdleTaskStackSize) {
	*ppxIdleTaskTCBBuffer = &xIdleTaskTCBBuffer;
	*ppxIdleTaskStackBuffer = &xIdleStack[0];
	*pulIdleTaskStackSize = configMINIMAL_STACK_SIZE;
	/* place for user code */
}
/* USER CODE END GET_IDLE_TASK_MEMORY */

/**
  * @brief  FreeRTOS initialization
  * @param  None
  * @retval None
  */
void MX_FREERTOS_Init(void) {
  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* USER CODE BEGIN RTOS_MUTEX */
	/* add mutexes, ... */
  /* USER CODE END RTOS_MUTEX */

  /* USER CODE BEGIN RTOS_SEMAPHORES */
	/* add semaphores, ... */
  /* USER CODE END RTOS_SEMAPHORES */

  /* USER CODE BEGIN RTOS_TIMERS */
	/* start timers, add new ones, ... */
  /* USER CODE END RTOS_TIMERS */

  /* USER CODE BEGIN RTOS_QUEUES */
	/* add queues, ... */
  /* USER CODE END RTOS_QUEUES */

  /* Create the thread(s) */
  /* definition and creation of sensorTask */
  osThreadStaticDef(sensorTask, sensorTaskFunc, osPriorityHigh, 0, 1024, sensorTaskBuffer, &sensorTaskControlBlock);
  sensorTaskHandle = osThreadCreate(osThread(sensorTask), NULL);

  /* definition and creation of communicationTa */
  osThreadStaticDef(communicationTa, communicationTaskFunc, osPriorityAboveNormal, 0, 1024, communicationTaskBuffer, &communicationTaskControlBlock);
  communicationTaHandle = osThreadCreate(osThread(communicationTa), NULL);

  /* USER CODE BEGIN RTOS_THREADS */
	/* add threads, ... */
  /* USER CODE END RTOS_THREADS */

}

/* USER CODE BEGIN Header_sensorTaskFunc */
/**
 * @brief Function implementing the sensorTask thread.
 * @param argument: Not used
 * @retval None
 */
/* USER CODE END Header_sensorTaskFunc */
void sensorTaskFunc(void const * argument)
{
  /* USER CODE BEGIN sensorTaskFunc */
	TickType_t xLastWakeTime = xTaskGetTickCount();
	TickType_t sensorTaskPeriod = pdMS_TO_TICKS(1);
	static int32_t loopTick = 0;

	/* Infinite loop */
	for (;;) {

		if (++loopTick >= globalSensorTaskPeriod) {
			loopTick = 0;
			loop();
			PWMWriteFlush();
		}
		vTaskDelayUntil(&xLastWakeTime, sensorTaskPeriod);

	}
  /* USER CODE END sensorTaskFunc */
}

/* USER CODE BEGIN Header_communicationTaskFunc */
/**
 * @brief Function implementing the communicationTa thread.
 * @param argument: Not used
 * @retval None
 */
/* USER CODE END Header_communicationTaskFunc */
void communicationTaskFunc(void const * argument)
{
  /* USER CODE BEGIN communicationTaskFunc */
	TickType_t xLastWakeTime = xTaskGetTickCount();
	TickType_t communicationTaskPeriod = pdMS_TO_TICKS(1);
	static int32_t loopTick = 0;

	/* Infinite loop */
	for (;;) {

		if (++loopTick >= globalCommunicationTaskPeriod) {
			loopTick = 0;
			loop2();
		}
		vTaskDelayUntil(&xLastWakeTime, communicationTaskPeriod);

	}
  /* USER CODE END communicationTaskFunc */
}

/* Private application code --------------------------------------------------*/
/* USER CODE BEGIN Application */

/* USER CODE END Application */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
