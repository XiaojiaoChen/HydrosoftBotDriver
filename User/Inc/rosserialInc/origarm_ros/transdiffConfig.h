#ifndef _ROS_origarm_ros_transdiffConfig_h
#define _ROS_origarm_ros_transdiffConfig_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "origarm_ros/transdiffConfigSeg.h"

namespace origarm_ros
{

  class transdiffConfig : public ros::Msg
  {
    public:
      origarm_ros::transdiffConfigSeg transdiff_Configuration[9];

    transdiffConfig():
      transdiff_Configuration()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      for( uint32_t i = 0; i < 9; i++){
      offset += this->transdiff_Configuration[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      for( uint32_t i = 0; i < 9; i++){
      offset += this->transdiff_Configuration[i].deserialize(inbuffer + offset);
      }
     return offset;
    }

    virtual const char * getType() override { return "origarm_ros/transdiffConfig"; };
    virtual const char * getMD5() override { return "e149306263f7e5f00adb8e6895e575ec"; };

  };

}
#endif
