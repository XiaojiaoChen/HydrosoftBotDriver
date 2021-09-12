#ifndef _ROS_hydrosoft_ros_Command_Joystick_h
#define _ROS_hydrosoft_ros_Command_Joystick_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace hydrosoft_ros
{

  class Command_Joystick : public ros::Msg
  {
    public:
      typedef int8_t _Back_type;
      _Back_type Back;
      typedef int8_t _Start_type;
      _Start_type Start;
      typedef int8_t _Enabled_type;
      _Enabled_type Enabled;
      typedef int8_t _ControlMode_type;
      _ControlMode_type ControlMode;
      typedef float _AnaLX_type;
      _AnaLX_type AnaLX;
      typedef float _AnaLY_type;
      _AnaLY_type AnaLY;
      typedef float _AnaRX_type;
      _AnaRX_type AnaRX;
      typedef float _AnaRY_type;
      _AnaRY_type AnaRY;
      typedef int8_t _CrossUp_type;
      _CrossUp_type CrossUp;
      typedef int8_t _CrossDown_type;
      _CrossDown_type CrossDown;
      typedef int8_t _CrossLeft_type;
      _CrossLeft_type CrossLeft;
      typedef int8_t _CrossRight_type;
      _CrossRight_type CrossRight;
      typedef float _LT_type;
      _LT_type LT;
      typedef float _RT_type;
      _RT_type RT;
      typedef int8_t _LB_type;
      _LB_type LB;
      typedef int8_t _RB_type;
      _RB_type RB;
      typedef int8_t _X_type;
      _X_type X;
      typedef int8_t _Y_type;
      _Y_type Y;
      typedef int8_t _A_type;
      _A_type A;
      typedef int8_t _B_type;
      _B_type B;
      typedef int8_t _XPressed_type;
      _XPressed_type XPressed;
      typedef int8_t _YPressed_type;
      _YPressed_type YPressed;
      typedef int8_t _APressed_type;
      _APressed_type APressed;
      typedef int8_t _BPressed_type;
      _BPressed_type BPressed;
      typedef int8_t _XReleased_type;
      _XReleased_type XReleased;
      typedef int8_t _YReleased_type;
      _YReleased_type YReleased;
      typedef int8_t _AReleased_type;
      _AReleased_type AReleased;
      typedef int8_t _BReleased_type;
      _BReleased_type BReleased;

    Command_Joystick():
      Back(0),
      Start(0),
      Enabled(0),
      ControlMode(0),
      AnaLX(0),
      AnaLY(0),
      AnaRX(0),
      AnaRY(0),
      CrossUp(0),
      CrossDown(0),
      CrossLeft(0),
      CrossRight(0),
      LT(0),
      RT(0),
      LB(0),
      RB(0),
      X(0),
      Y(0),
      A(0),
      B(0),
      XPressed(0),
      YPressed(0),
      APressed(0),
      BPressed(0),
      XReleased(0),
      YReleased(0),
      AReleased(0),
      BReleased(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        int8_t real;
        uint8_t base;
      } u_Back;
      u_Back.real = this->Back;
      *(outbuffer + offset + 0) = (u_Back.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->Back);
      union {
        int8_t real;
        uint8_t base;
      } u_Start;
      u_Start.real = this->Start;
      *(outbuffer + offset + 0) = (u_Start.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->Start);
      union {
        int8_t real;
        uint8_t base;
      } u_Enabled;
      u_Enabled.real = this->Enabled;
      *(outbuffer + offset + 0) = (u_Enabled.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->Enabled);
      union {
        int8_t real;
        uint8_t base;
      } u_ControlMode;
      u_ControlMode.real = this->ControlMode;
      *(outbuffer + offset + 0) = (u_ControlMode.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->ControlMode);
      union {
        float real;
        uint32_t base;
      } u_AnaLX;
      u_AnaLX.real = this->AnaLX;
      *(outbuffer + offset + 0) = (u_AnaLX.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_AnaLX.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_AnaLX.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_AnaLX.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->AnaLX);
      union {
        float real;
        uint32_t base;
      } u_AnaLY;
      u_AnaLY.real = this->AnaLY;
      *(outbuffer + offset + 0) = (u_AnaLY.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_AnaLY.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_AnaLY.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_AnaLY.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->AnaLY);
      union {
        float real;
        uint32_t base;
      } u_AnaRX;
      u_AnaRX.real = this->AnaRX;
      *(outbuffer + offset + 0) = (u_AnaRX.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_AnaRX.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_AnaRX.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_AnaRX.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->AnaRX);
      union {
        float real;
        uint32_t base;
      } u_AnaRY;
      u_AnaRY.real = this->AnaRY;
      *(outbuffer + offset + 0) = (u_AnaRY.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_AnaRY.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_AnaRY.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_AnaRY.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->AnaRY);
      union {
        int8_t real;
        uint8_t base;
      } u_CrossUp;
      u_CrossUp.real = this->CrossUp;
      *(outbuffer + offset + 0) = (u_CrossUp.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->CrossUp);
      union {
        int8_t real;
        uint8_t base;
      } u_CrossDown;
      u_CrossDown.real = this->CrossDown;
      *(outbuffer + offset + 0) = (u_CrossDown.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->CrossDown);
      union {
        int8_t real;
        uint8_t base;
      } u_CrossLeft;
      u_CrossLeft.real = this->CrossLeft;
      *(outbuffer + offset + 0) = (u_CrossLeft.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->CrossLeft);
      union {
        int8_t real;
        uint8_t base;
      } u_CrossRight;
      u_CrossRight.real = this->CrossRight;
      *(outbuffer + offset + 0) = (u_CrossRight.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->CrossRight);
      union {
        float real;
        uint32_t base;
      } u_LT;
      u_LT.real = this->LT;
      *(outbuffer + offset + 0) = (u_LT.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_LT.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_LT.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_LT.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->LT);
      union {
        float real;
        uint32_t base;
      } u_RT;
      u_RT.real = this->RT;
      *(outbuffer + offset + 0) = (u_RT.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_RT.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_RT.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_RT.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->RT);
      union {
        int8_t real;
        uint8_t base;
      } u_LB;
      u_LB.real = this->LB;
      *(outbuffer + offset + 0) = (u_LB.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->LB);
      union {
        int8_t real;
        uint8_t base;
      } u_RB;
      u_RB.real = this->RB;
      *(outbuffer + offset + 0) = (u_RB.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->RB);
      union {
        int8_t real;
        uint8_t base;
      } u_X;
      u_X.real = this->X;
      *(outbuffer + offset + 0) = (u_X.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->X);
      union {
        int8_t real;
        uint8_t base;
      } u_Y;
      u_Y.real = this->Y;
      *(outbuffer + offset + 0) = (u_Y.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->Y);
      union {
        int8_t real;
        uint8_t base;
      } u_A;
      u_A.real = this->A;
      *(outbuffer + offset + 0) = (u_A.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->A);
      union {
        int8_t real;
        uint8_t base;
      } u_B;
      u_B.real = this->B;
      *(outbuffer + offset + 0) = (u_B.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->B);
      union {
        int8_t real;
        uint8_t base;
      } u_XPressed;
      u_XPressed.real = this->XPressed;
      *(outbuffer + offset + 0) = (u_XPressed.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->XPressed);
      union {
        int8_t real;
        uint8_t base;
      } u_YPressed;
      u_YPressed.real = this->YPressed;
      *(outbuffer + offset + 0) = (u_YPressed.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->YPressed);
      union {
        int8_t real;
        uint8_t base;
      } u_APressed;
      u_APressed.real = this->APressed;
      *(outbuffer + offset + 0) = (u_APressed.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->APressed);
      union {
        int8_t real;
        uint8_t base;
      } u_BPressed;
      u_BPressed.real = this->BPressed;
      *(outbuffer + offset + 0) = (u_BPressed.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->BPressed);
      union {
        int8_t real;
        uint8_t base;
      } u_XReleased;
      u_XReleased.real = this->XReleased;
      *(outbuffer + offset + 0) = (u_XReleased.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->XReleased);
      union {
        int8_t real;
        uint8_t base;
      } u_YReleased;
      u_YReleased.real = this->YReleased;
      *(outbuffer + offset + 0) = (u_YReleased.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->YReleased);
      union {
        int8_t real;
        uint8_t base;
      } u_AReleased;
      u_AReleased.real = this->AReleased;
      *(outbuffer + offset + 0) = (u_AReleased.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->AReleased);
      union {
        int8_t real;
        uint8_t base;
      } u_BReleased;
      u_BReleased.real = this->BReleased;
      *(outbuffer + offset + 0) = (u_BReleased.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->BReleased);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        int8_t real;
        uint8_t base;
      } u_Back;
      u_Back.base = 0;
      u_Back.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->Back = u_Back.real;
      offset += sizeof(this->Back);
      union {
        int8_t real;
        uint8_t base;
      } u_Start;
      u_Start.base = 0;
      u_Start.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->Start = u_Start.real;
      offset += sizeof(this->Start);
      union {
        int8_t real;
        uint8_t base;
      } u_Enabled;
      u_Enabled.base = 0;
      u_Enabled.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->Enabled = u_Enabled.real;
      offset += sizeof(this->Enabled);
      union {
        int8_t real;
        uint8_t base;
      } u_ControlMode;
      u_ControlMode.base = 0;
      u_ControlMode.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->ControlMode = u_ControlMode.real;
      offset += sizeof(this->ControlMode);
      union {
        float real;
        uint32_t base;
      } u_AnaLX;
      u_AnaLX.base = 0;
      u_AnaLX.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_AnaLX.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_AnaLX.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_AnaLX.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->AnaLX = u_AnaLX.real;
      offset += sizeof(this->AnaLX);
      union {
        float real;
        uint32_t base;
      } u_AnaLY;
      u_AnaLY.base = 0;
      u_AnaLY.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_AnaLY.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_AnaLY.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_AnaLY.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->AnaLY = u_AnaLY.real;
      offset += sizeof(this->AnaLY);
      union {
        float real;
        uint32_t base;
      } u_AnaRX;
      u_AnaRX.base = 0;
      u_AnaRX.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_AnaRX.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_AnaRX.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_AnaRX.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->AnaRX = u_AnaRX.real;
      offset += sizeof(this->AnaRX);
      union {
        float real;
        uint32_t base;
      } u_AnaRY;
      u_AnaRY.base = 0;
      u_AnaRY.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_AnaRY.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_AnaRY.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_AnaRY.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->AnaRY = u_AnaRY.real;
      offset += sizeof(this->AnaRY);
      union {
        int8_t real;
        uint8_t base;
      } u_CrossUp;
      u_CrossUp.base = 0;
      u_CrossUp.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->CrossUp = u_CrossUp.real;
      offset += sizeof(this->CrossUp);
      union {
        int8_t real;
        uint8_t base;
      } u_CrossDown;
      u_CrossDown.base = 0;
      u_CrossDown.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->CrossDown = u_CrossDown.real;
      offset += sizeof(this->CrossDown);
      union {
        int8_t real;
        uint8_t base;
      } u_CrossLeft;
      u_CrossLeft.base = 0;
      u_CrossLeft.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->CrossLeft = u_CrossLeft.real;
      offset += sizeof(this->CrossLeft);
      union {
        int8_t real;
        uint8_t base;
      } u_CrossRight;
      u_CrossRight.base = 0;
      u_CrossRight.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->CrossRight = u_CrossRight.real;
      offset += sizeof(this->CrossRight);
      union {
        float real;
        uint32_t base;
      } u_LT;
      u_LT.base = 0;
      u_LT.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_LT.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_LT.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_LT.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->LT = u_LT.real;
      offset += sizeof(this->LT);
      union {
        float real;
        uint32_t base;
      } u_RT;
      u_RT.base = 0;
      u_RT.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_RT.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_RT.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_RT.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->RT = u_RT.real;
      offset += sizeof(this->RT);
      union {
        int8_t real;
        uint8_t base;
      } u_LB;
      u_LB.base = 0;
      u_LB.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->LB = u_LB.real;
      offset += sizeof(this->LB);
      union {
        int8_t real;
        uint8_t base;
      } u_RB;
      u_RB.base = 0;
      u_RB.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->RB = u_RB.real;
      offset += sizeof(this->RB);
      union {
        int8_t real;
        uint8_t base;
      } u_X;
      u_X.base = 0;
      u_X.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->X = u_X.real;
      offset += sizeof(this->X);
      union {
        int8_t real;
        uint8_t base;
      } u_Y;
      u_Y.base = 0;
      u_Y.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->Y = u_Y.real;
      offset += sizeof(this->Y);
      union {
        int8_t real;
        uint8_t base;
      } u_A;
      u_A.base = 0;
      u_A.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->A = u_A.real;
      offset += sizeof(this->A);
      union {
        int8_t real;
        uint8_t base;
      } u_B;
      u_B.base = 0;
      u_B.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->B = u_B.real;
      offset += sizeof(this->B);
      union {
        int8_t real;
        uint8_t base;
      } u_XPressed;
      u_XPressed.base = 0;
      u_XPressed.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->XPressed = u_XPressed.real;
      offset += sizeof(this->XPressed);
      union {
        int8_t real;
        uint8_t base;
      } u_YPressed;
      u_YPressed.base = 0;
      u_YPressed.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->YPressed = u_YPressed.real;
      offset += sizeof(this->YPressed);
      union {
        int8_t real;
        uint8_t base;
      } u_APressed;
      u_APressed.base = 0;
      u_APressed.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->APressed = u_APressed.real;
      offset += sizeof(this->APressed);
      union {
        int8_t real;
        uint8_t base;
      } u_BPressed;
      u_BPressed.base = 0;
      u_BPressed.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->BPressed = u_BPressed.real;
      offset += sizeof(this->BPressed);
      union {
        int8_t real;
        uint8_t base;
      } u_XReleased;
      u_XReleased.base = 0;
      u_XReleased.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->XReleased = u_XReleased.real;
      offset += sizeof(this->XReleased);
      union {
        int8_t real;
        uint8_t base;
      } u_YReleased;
      u_YReleased.base = 0;
      u_YReleased.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->YReleased = u_YReleased.real;
      offset += sizeof(this->YReleased);
      union {
        int8_t real;
        uint8_t base;
      } u_AReleased;
      u_AReleased.base = 0;
      u_AReleased.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->AReleased = u_AReleased.real;
      offset += sizeof(this->AReleased);
      union {
        int8_t real;
        uint8_t base;
      } u_BReleased;
      u_BReleased.base = 0;
      u_BReleased.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->BReleased = u_BReleased.real;
      offset += sizeof(this->BReleased);
     return offset;
    }

    virtual const char * getType() override { return "hydrosoft_ros/Command_Joystick"; };
    virtual const char * getMD5() override { return "557b1980d579ce8b433221dd5268e314"; };

  };

}
#endif
