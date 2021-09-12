#ifndef _ROS_hydrosoft_ros_Command_GUI_h
#define _ROS_hydrosoft_ros_Command_GUI_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace hydrosoft_ros
{

  class Command_GUI : public ros::Msg
  {
    public:
      typedef uint8_t _modeCmd_type;
      _modeCmd_type modeCmd;
      typedef uint32_t _armCmd_type;
      _armCmd_type armCmd;
      typedef int16_t _pSourceCmd_type;
      _pSourceCmd_type pSourceCmd;
      typedef int16_t _pSinkCmd_type;
      _pSinkCmd_type pSinkCmd;

    Command_GUI():
      modeCmd(0),
      armCmd(0),
      pSourceCmd(0),
      pSinkCmd(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->modeCmd >> (8 * 0)) & 0xFF;
      offset += sizeof(this->modeCmd);
      *(outbuffer + offset + 0) = (this->armCmd >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->armCmd >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->armCmd >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->armCmd >> (8 * 3)) & 0xFF;
      offset += sizeof(this->armCmd);
      union {
        int16_t real;
        uint16_t base;
      } u_pSourceCmd;
      u_pSourceCmd.real = this->pSourceCmd;
      *(outbuffer + offset + 0) = (u_pSourceCmd.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_pSourceCmd.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->pSourceCmd);
      union {
        int16_t real;
        uint16_t base;
      } u_pSinkCmd;
      u_pSinkCmd.real = this->pSinkCmd;
      *(outbuffer + offset + 0) = (u_pSinkCmd.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_pSinkCmd.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->pSinkCmd);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      this->modeCmd =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->modeCmd);
      this->armCmd =  ((uint32_t) (*(inbuffer + offset)));
      this->armCmd |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->armCmd |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->armCmd |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->armCmd);
      union {
        int16_t real;
        uint16_t base;
      } u_pSourceCmd;
      u_pSourceCmd.base = 0;
      u_pSourceCmd.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_pSourceCmd.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->pSourceCmd = u_pSourceCmd.real;
      offset += sizeof(this->pSourceCmd);
      union {
        int16_t real;
        uint16_t base;
      } u_pSinkCmd;
      u_pSinkCmd.base = 0;
      u_pSinkCmd.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_pSinkCmd.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->pSinkCmd = u_pSinkCmd.real;
      offset += sizeof(this->pSinkCmd);
     return offset;
    }

    virtual const char * getType() override { return "hydrosoft_ros/Command_GUI"; };
    virtual const char * getMD5() override { return "3a8988ba084b7382634875a516127ac7"; };

  };

}
#endif
