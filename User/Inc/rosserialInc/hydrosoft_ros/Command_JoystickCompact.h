#ifndef _ROS_hydrosoft_ros_Command_JoystickCompact_h
#define _ROS_hydrosoft_ros_Command_JoystickCompact_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace hydrosoft_ros
{

  class Command_JoystickCompact : public ros::Msg
  {
    public:
      typedef uint16_t _btnCross_type;
      _btnCross_type btnCross;
      typedef uint8_t _btnMode_type;
      _btnMode_type btnMode;
      typedef uint16_t _btnEdge_type;
      _btnEdge_type btnEdge;
      typedef int16_t _LX_type;
      _LX_type LX;
      typedef int16_t _LY_type;
      _LY_type LY;
      typedef int16_t _RX_type;
      _RX_type RX;
      typedef int16_t _RY_type;
      _RY_type RY;
      typedef int16_t _LT_type;
      _LT_type LT;
      typedef int16_t _RT_type;
      _RT_type RT;

    Command_JoystickCompact():
      btnCross(0),
      btnMode(0),
      btnEdge(0),
      LX(0),
      LY(0),
      RX(0),
      RY(0),
      LT(0),
      RT(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->btnCross >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->btnCross >> (8 * 1)) & 0xFF;
      offset += sizeof(this->btnCross);
      *(outbuffer + offset + 0) = (this->btnMode >> (8 * 0)) & 0xFF;
      offset += sizeof(this->btnMode);
      *(outbuffer + offset + 0) = (this->btnEdge >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->btnEdge >> (8 * 1)) & 0xFF;
      offset += sizeof(this->btnEdge);
      union {
        int16_t real;
        uint16_t base;
      } u_LX;
      u_LX.real = this->LX;
      *(outbuffer + offset + 0) = (u_LX.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_LX.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->LX);
      union {
        int16_t real;
        uint16_t base;
      } u_LY;
      u_LY.real = this->LY;
      *(outbuffer + offset + 0) = (u_LY.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_LY.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->LY);
      union {
        int16_t real;
        uint16_t base;
      } u_RX;
      u_RX.real = this->RX;
      *(outbuffer + offset + 0) = (u_RX.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_RX.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->RX);
      union {
        int16_t real;
        uint16_t base;
      } u_RY;
      u_RY.real = this->RY;
      *(outbuffer + offset + 0) = (u_RY.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_RY.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->RY);
      union {
        int16_t real;
        uint16_t base;
      } u_LT;
      u_LT.real = this->LT;
      *(outbuffer + offset + 0) = (u_LT.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_LT.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->LT);
      union {
        int16_t real;
        uint16_t base;
      } u_RT;
      u_RT.real = this->RT;
      *(outbuffer + offset + 0) = (u_RT.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_RT.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->RT);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      this->btnCross =  ((uint16_t) (*(inbuffer + offset)));
      this->btnCross |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->btnCross);
      this->btnMode =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->btnMode);
      this->btnEdge =  ((uint16_t) (*(inbuffer + offset)));
      this->btnEdge |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->btnEdge);
      union {
        int16_t real;
        uint16_t base;
      } u_LX;
      u_LX.base = 0;
      u_LX.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_LX.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->LX = u_LX.real;
      offset += sizeof(this->LX);
      union {
        int16_t real;
        uint16_t base;
      } u_LY;
      u_LY.base = 0;
      u_LY.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_LY.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->LY = u_LY.real;
      offset += sizeof(this->LY);
      union {
        int16_t real;
        uint16_t base;
      } u_RX;
      u_RX.base = 0;
      u_RX.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_RX.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->RX = u_RX.real;
      offset += sizeof(this->RX);
      union {
        int16_t real;
        uint16_t base;
      } u_RY;
      u_RY.base = 0;
      u_RY.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_RY.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->RY = u_RY.real;
      offset += sizeof(this->RY);
      union {
        int16_t real;
        uint16_t base;
      } u_LT;
      u_LT.base = 0;
      u_LT.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_LT.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->LT = u_LT.real;
      offset += sizeof(this->LT);
      union {
        int16_t real;
        uint16_t base;
      } u_RT;
      u_RT.base = 0;
      u_RT.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_RT.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->RT = u_RT.real;
      offset += sizeof(this->RT);
     return offset;
    }

    virtual const char * getType() override { return "hydrosoft_ros/Command_JoystickCompact"; };
    virtual const char * getMD5() override { return "b8a7429384ce3bfa7eb1cba19acdfe12"; };

  };

}
#endif
