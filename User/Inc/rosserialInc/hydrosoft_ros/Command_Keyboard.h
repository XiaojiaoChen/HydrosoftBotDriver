#ifndef _ROS_hydrosoft_ros_Command_Keyboard_h
#define _ROS_hydrosoft_ros_Command_Keyboard_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace hydrosoft_ros
{

  class Command_Keyboard : public ros::Msg
  {
    public:
      typedef uint16_t _keyName_type;
      _keyName_type keyName;
      typedef int32_t _keyValue_type;
      _keyValue_type keyValue;

    Command_Keyboard():
      keyName(0),
      keyValue(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->keyName >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->keyName >> (8 * 1)) & 0xFF;
      offset += sizeof(this->keyName);
      union {
        int32_t real;
        uint32_t base;
      } u_keyValue;
      u_keyValue.real = this->keyValue;
      *(outbuffer + offset + 0) = (u_keyValue.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_keyValue.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_keyValue.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_keyValue.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->keyValue);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      this->keyName =  ((uint16_t) (*(inbuffer + offset)));
      this->keyName |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->keyName);
      union {
        int32_t real;
        uint32_t base;
      } u_keyValue;
      u_keyValue.base = 0;
      u_keyValue.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_keyValue.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_keyValue.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_keyValue.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->keyValue = u_keyValue.real;
      offset += sizeof(this->keyValue);
     return offset;
    }

    virtual const char * getType() override { return "hydrosoft_ros/Command_Keyboard"; };
    virtual const char * getMD5() override { return "7d408783e7699e178c8b6a9253f1c203"; };

  };

}
#endif
