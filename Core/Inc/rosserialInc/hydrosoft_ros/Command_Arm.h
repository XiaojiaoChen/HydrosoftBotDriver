#ifndef _ROS_hydrosoft_ros_Command_Arm_h
#define _ROS_hydrosoft_ros_Command_Arm_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace hydrosoft_ros
{

  class Command_Arm : public ros::Msg
  {
    public:
      uint32_t actuator_length;
      typedef int16_t _actuator_type;
      _actuator_type st_actuator;
      _actuator_type * actuator;
      typedef int16_t _pumpIn_type;
      _pumpIn_type pumpIn;
      typedef int16_t _pumpOut_type;
      _pumpOut_type pumpOut;
      typedef int16_t _gripper_type;
      _gripper_type gripper;
      typedef uint16_t _cmd_type;
      _cmd_type cmd;

    Command_Arm():
      actuator_length(0), st_actuator(), actuator(nullptr),
      pumpIn(0),
      pumpOut(0),
      gripper(0),
      cmd(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->actuator_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->actuator_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->actuator_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->actuator_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->actuator_length);
      for( uint32_t i = 0; i < actuator_length; i++){
      union {
        int16_t real;
        uint16_t base;
      } u_actuatori;
      u_actuatori.real = this->actuator[i];
      *(outbuffer + offset + 0) = (u_actuatori.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_actuatori.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->actuator[i]);
      }
      union {
        int16_t real;
        uint16_t base;
      } u_pumpIn;
      u_pumpIn.real = this->pumpIn;
      *(outbuffer + offset + 0) = (u_pumpIn.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_pumpIn.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->pumpIn);
      union {
        int16_t real;
        uint16_t base;
      } u_pumpOut;
      u_pumpOut.real = this->pumpOut;
      *(outbuffer + offset + 0) = (u_pumpOut.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_pumpOut.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->pumpOut);
      union {
        int16_t real;
        uint16_t base;
      } u_gripper;
      u_gripper.real = this->gripper;
      *(outbuffer + offset + 0) = (u_gripper.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_gripper.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->gripper);
      *(outbuffer + offset + 0) = (this->cmd >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->cmd >> (8 * 1)) & 0xFF;
      offset += sizeof(this->cmd);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      uint32_t actuator_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      actuator_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      actuator_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      actuator_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->actuator_length);
      if(actuator_lengthT > actuator_length)
        this->actuator = (int16_t*)realloc(this->actuator, actuator_lengthT * sizeof(int16_t));
      actuator_length = actuator_lengthT;
      for( uint32_t i = 0; i < actuator_length; i++){
      union {
        int16_t real;
        uint16_t base;
      } u_st_actuator;
      u_st_actuator.base = 0;
      u_st_actuator.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_actuator.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->st_actuator = u_st_actuator.real;
      offset += sizeof(this->st_actuator);
        memcpy( &(this->actuator[i]), &(this->st_actuator), sizeof(int16_t));
      }
      union {
        int16_t real;
        uint16_t base;
      } u_pumpIn;
      u_pumpIn.base = 0;
      u_pumpIn.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_pumpIn.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->pumpIn = u_pumpIn.real;
      offset += sizeof(this->pumpIn);
      union {
        int16_t real;
        uint16_t base;
      } u_pumpOut;
      u_pumpOut.base = 0;
      u_pumpOut.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_pumpOut.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->pumpOut = u_pumpOut.real;
      offset += sizeof(this->pumpOut);
      union {
        int16_t real;
        uint16_t base;
      } u_gripper;
      u_gripper.base = 0;
      u_gripper.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_gripper.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->gripper = u_gripper.real;
      offset += sizeof(this->gripper);
      this->cmd =  ((uint16_t) (*(inbuffer + offset)));
      this->cmd |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->cmd);
     return offset;
    }

    virtual const char * getType() override { return "hydrosoft_ros/Command_Arm"; };
    virtual const char * getMD5() override { return "b2e22b720533db37081218adfe851ec1"; };

  };

}
#endif
