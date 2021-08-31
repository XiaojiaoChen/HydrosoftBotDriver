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
      typedef int16_t _controlModeCommand_type;
      _controlModeCommand_type controlModeCommand;
      uint32_t actuatorCommand_length;
      typedef int16_t _actuatorCommand_type;
      _actuatorCommand_type st_actuatorCommand;
      _actuatorCommand_type * actuatorCommand;
      typedef int16_t _gripperCommand_type;
      _gripperCommand_type gripperCommand;
      typedef int16_t _pSourceCommand_type;
      _pSourceCommand_type pSourceCommand;
      typedef int16_t _pSinkCommand_type;
      _pSinkCommand_type pSinkCommand;

    Command_Arm():
      controlModeCommand(0),
      actuatorCommand_length(0), st_actuatorCommand(), actuatorCommand(nullptr),
      gripperCommand(0),
      pSourceCommand(0),
      pSinkCommand(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        int16_t real;
        uint16_t base;
      } u_controlModeCommand;
      u_controlModeCommand.real = this->controlModeCommand;
      *(outbuffer + offset + 0) = (u_controlModeCommand.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_controlModeCommand.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->controlModeCommand);
      *(outbuffer + offset + 0) = (this->actuatorCommand_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->actuatorCommand_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->actuatorCommand_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->actuatorCommand_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->actuatorCommand_length);
      for( uint32_t i = 0; i < actuatorCommand_length; i++){
      union {
        int16_t real;
        uint16_t base;
      } u_actuatorCommandi;
      u_actuatorCommandi.real = this->actuatorCommand[i];
      *(outbuffer + offset + 0) = (u_actuatorCommandi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_actuatorCommandi.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->actuatorCommand[i]);
      }
      union {
        int16_t real;
        uint16_t base;
      } u_gripperCommand;
      u_gripperCommand.real = this->gripperCommand;
      *(outbuffer + offset + 0) = (u_gripperCommand.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_gripperCommand.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->gripperCommand);
      union {
        int16_t real;
        uint16_t base;
      } u_pSourceCommand;
      u_pSourceCommand.real = this->pSourceCommand;
      *(outbuffer + offset + 0) = (u_pSourceCommand.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_pSourceCommand.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->pSourceCommand);
      union {
        int16_t real;
        uint16_t base;
      } u_pSinkCommand;
      u_pSinkCommand.real = this->pSinkCommand;
      *(outbuffer + offset + 0) = (u_pSinkCommand.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_pSinkCommand.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->pSinkCommand);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        int16_t real;
        uint16_t base;
      } u_controlModeCommand;
      u_controlModeCommand.base = 0;
      u_controlModeCommand.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_controlModeCommand.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->controlModeCommand = u_controlModeCommand.real;
      offset += sizeof(this->controlModeCommand);
      uint32_t actuatorCommand_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      actuatorCommand_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      actuatorCommand_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      actuatorCommand_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->actuatorCommand_length);
      if(actuatorCommand_lengthT > actuatorCommand_length)
        this->actuatorCommand = (int16_t*)realloc(this->actuatorCommand, actuatorCommand_lengthT * sizeof(int16_t));
      actuatorCommand_length = actuatorCommand_lengthT;
      for( uint32_t i = 0; i < actuatorCommand_length; i++){
      union {
        int16_t real;
        uint16_t base;
      } u_st_actuatorCommand;
      u_st_actuatorCommand.base = 0;
      u_st_actuatorCommand.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_actuatorCommand.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->st_actuatorCommand = u_st_actuatorCommand.real;
      offset += sizeof(this->st_actuatorCommand);
        memcpy( &(this->actuatorCommand[i]), &(this->st_actuatorCommand), sizeof(int16_t));
      }
      union {
        int16_t real;
        uint16_t base;
      } u_gripperCommand;
      u_gripperCommand.base = 0;
      u_gripperCommand.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_gripperCommand.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->gripperCommand = u_gripperCommand.real;
      offset += sizeof(this->gripperCommand);
      union {
        int16_t real;
        uint16_t base;
      } u_pSourceCommand;
      u_pSourceCommand.base = 0;
      u_pSourceCommand.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_pSourceCommand.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->pSourceCommand = u_pSourceCommand.real;
      offset += sizeof(this->pSourceCommand);
      union {
        int16_t real;
        uint16_t base;
      } u_pSinkCommand;
      u_pSinkCommand.base = 0;
      u_pSinkCommand.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_pSinkCommand.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->pSinkCommand = u_pSinkCommand.real;
      offset += sizeof(this->pSinkCommand);
     return offset;
    }

    virtual const char * getType() override { return "hydrosoft_ros/Command_Arm"; };
    virtual const char * getMD5() override { return "36f0809d92e060c19f205ca26715d3a2"; };

  };

}
#endif
