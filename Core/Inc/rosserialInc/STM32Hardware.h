/* 
 * Software License Agreement (BSD License)
 *
 * Copyright (c) 2018, Kenta Yonekura (a.k.a. yoneken)
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 *  * Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *  * Redistributions in binary form must reproduce the above
 *    copyright notice, this list of conditions and the following
 *    disclaimer in the documentation and/or other materials provided
 *    with the distribution.
 *  * Neither the name of Willow Garage, Inc. nor the names of its
 *    contributors may be used to endorse or promote prducts derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 * COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef ROS_STM32_HARDWARE_H_
#define ROS_STM32_HARDWARE_H_


//try #include "stm32f1xx_hal.h" if this doesn't work
#include "main.h"

/**********************************  Configuration    ************************************/

#define RxBufLen  256     //suit your needs

#define TxBufLen  256     //suit your needs

/**********************************  Configuration end************************************/


class STM32Hardware {
  protected:
    UART_HandleTypeDef *roshuart;

    const static int rbuflen = RxBufLen;
    uint8_t rbuf[rbuflen];
    int rind;
    inline int getRdmaInd(void){ return (rbuflen - (int)__HAL_DMA_GET_COUNTER(roshuart->hdmarx)) & (rbuflen - 1); }

    const static int tbuflen = TxBufLen;
    uint8_t tbuf[tbuflen];
    int twind, tfind;

  public:

    STM32Hardware():
      roshuart(0), rind(0), twind(0), tfind(0){ //we dont define port here, but addtionally call setPort()
    }

    STM32Hardware(UART_HandleTypeDef *huart_):
      roshuart(huart_), rind(0), twind(0), tfind(0){
    }
  
    void init(){
      reset_rbuf();
    }

    void reset_rbuf(void){
      HAL_UART_Receive_DMA(roshuart, rbuf, rbuflen);
    }

    int read(){
      int c = -1;
      if(rind != getRdmaInd()){
        c = rbuf[rind++];
        rind &= rbuflen - 1;
      }
      return c;
    }

    void flush(void){
      static bool mutex = false;

      if((roshuart->gState == HAL_UART_STATE_READY) && !mutex){
        mutex = true;

        if(twind != tfind){
        	int32_t len = tfind < twind ? twind - tfind : tbuflen - tfind;
          HAL_UART_Transmit_DMA(roshuart, &(tbuf[tfind]), len);
          tfind = (tfind + len) & (tbuflen - 1);
        }
        mutex = false;
      }
    }

    void write(uint8_t* data, int length){
      int n = length;
      n = n <= tbuflen ? n : tbuflen;

      int n_tail = n <= tbuflen - twind ? n : tbuflen - twind;
      memcpy(&(tbuf[twind]), data, n_tail);
      twind = (twind + n) & (tbuflen - 1);

      if(n != n_tail){
        memcpy(tbuf, &(data[n_tail]), n - n_tail);
      }

      flush();
    }

    void setPort(UART_HandleTypeDef *huart_){
    	roshuart = huart_;
    	init();
    }



    unsigned long time(){ return HAL_GetTick();; }

  protected:
};

#endif