#ifndef _ROS_hydrosoft_ros_Command_Terminal_h
#define _ROS_hydrosoft_ros_Command_Terminal_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace hydrosoft_ros
{

  class Command_Terminal : public ros::Msg
  {
    public:
      typedef int16_t _cmdCode_type;
      _cmdCode_type cmdCode;
      uint32_t cmdData_length;
      typedef int16_t _cmdData_type;
      _cmdData_type st_cmdData;
      _cmdData_type * cmdData;

    Command_Terminal():
      cmdCode(0),
      cmdData_length(0), st_cmdData(), cmdData(nullptr)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        int16_t real;
        uint16_t base;
      } u_cmdCode;
      u_cmdCode.real = this->cmdCode;
      *(outbuffer + offset + 0) = (u_cmdCode.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_cmdCode.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->cmdCode);
      *(outbuffer + offset + 0) = (this->cmdData_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->cmdData_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->cmdData_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->cmdData_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->cmdData_length);
      for( uint32_t i = 0; i < cmdData_length; i++){
      union {
        int16_t real;
        uint16_t base;
      } u_cmdDatai;
      u_cmdDatai.real = this->cmdData[i];
      *(outbuffer + offset + 0) = (u_cmdDatai.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_cmdDatai.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->cmdData[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        int16_t real;
        uint16_t base;
      } u_cmdCode;
      u_cmdCode.base = 0;
      u_cmdCode.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_cmdCode.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->cmdCode = u_cmdCode.real;
      offset += sizeof(this->cmdCode);
      uint32_t cmdData_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      cmdData_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      cmdData_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      cmdData_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->cmdData_length);
      if(cmdData_lengthT > cmdData_length)
        this->cmdData = (int16_t*)realloc(this->cmdData, cmdData_lengthT * sizeof(int16_t));
      cmdData_length = cmdData_lengthT;
      for( uint32_t i = 0; i < cmdData_length; i++){
      union {
        int16_t real;
        uint16_t base;
      } u_st_cmdData;
      u_st_cmdData.base = 0;
      u_st_cmdData.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_cmdData.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->st_cmdData = u_st_cmdData.real;
      offset += sizeof(this->st_cmdData);
        memcpy( &(this->cmdData[i]), &(this->st_cmdData), sizeof(int16_t));
      }
     return offset;
    }

    virtual const char * getType() override { return "hydrosoft_ros/Command_Terminal"; };
    virtual const char * getMD5() override { return "51d2857ed2c528722a14137b16bf8599"; };

  };

}
#endif
