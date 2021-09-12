#ifndef _ROS_hydrosoft_ros_Command_Joystick3D_h
#define _ROS_hydrosoft_ros_Command_Joystick3D_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace hydrosoft_ros
{

  class Command_Joystick3D : public ros::Msg
  {
    public:
      typedef int8_t _Enabled_type;
      _Enabled_type Enabled;
      typedef int16_t _X_type;
      _X_type X;
      typedef int16_t _Y_type;
      _Y_type Y;
      typedef int16_t _Z_type;
      _Z_type Z;
      typedef int16_t _A_type;
      _A_type A;
      typedef int16_t _B_type;
      _B_type B;
      typedef int16_t _C_type;
      _C_type C;

    Command_Joystick3D():
      Enabled(0),
      X(0),
      Y(0),
      Z(0),
      A(0),
      B(0),
      C(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        int8_t real;
        uint8_t base;
      } u_Enabled;
      u_Enabled.real = this->Enabled;
      *(outbuffer + offset + 0) = (u_Enabled.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->Enabled);
      union {
        int16_t real;
        uint16_t base;
      } u_X;
      u_X.real = this->X;
      *(outbuffer + offset + 0) = (u_X.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_X.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->X);
      union {
        int16_t real;
        uint16_t base;
      } u_Y;
      u_Y.real = this->Y;
      *(outbuffer + offset + 0) = (u_Y.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_Y.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->Y);
      union {
        int16_t real;
        uint16_t base;
      } u_Z;
      u_Z.real = this->Z;
      *(outbuffer + offset + 0) = (u_Z.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_Z.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->Z);
      union {
        int16_t real;
        uint16_t base;
      } u_A;
      u_A.real = this->A;
      *(outbuffer + offset + 0) = (u_A.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_A.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->A);
      union {
        int16_t real;
        uint16_t base;
      } u_B;
      u_B.real = this->B;
      *(outbuffer + offset + 0) = (u_B.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_B.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->B);
      union {
        int16_t real;
        uint16_t base;
      } u_C;
      u_C.real = this->C;
      *(outbuffer + offset + 0) = (u_C.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_C.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->C);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        int8_t real;
        uint8_t base;
      } u_Enabled;
      u_Enabled.base = 0;
      u_Enabled.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->Enabled = u_Enabled.real;
      offset += sizeof(this->Enabled);
      union {
        int16_t real;
        uint16_t base;
      } u_X;
      u_X.base = 0;
      u_X.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_X.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->X = u_X.real;
      offset += sizeof(this->X);
      union {
        int16_t real;
        uint16_t base;
      } u_Y;
      u_Y.base = 0;
      u_Y.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_Y.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->Y = u_Y.real;
      offset += sizeof(this->Y);
      union {
        int16_t real;
        uint16_t base;
      } u_Z;
      u_Z.base = 0;
      u_Z.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_Z.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->Z = u_Z.real;
      offset += sizeof(this->Z);
      union {
        int16_t real;
        uint16_t base;
      } u_A;
      u_A.base = 0;
      u_A.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_A.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->A = u_A.real;
      offset += sizeof(this->A);
      union {
        int16_t real;
        uint16_t base;
      } u_B;
      u_B.base = 0;
      u_B.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_B.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->B = u_B.real;
      offset += sizeof(this->B);
      union {
        int16_t real;
        uint16_t base;
      } u_C;
      u_C.base = 0;
      u_C.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_C.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->C = u_C.real;
      offset += sizeof(this->C);
     return offset;
    }

    virtual const char * getType() override { return "hydrosoft_ros/Command_Joystick3D"; };
    virtual const char * getMD5() override { return "389e4217c12e690c336a2df8d859ff52"; };

  };

}
#endif
