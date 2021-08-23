#ifndef _ROS_origarm_ros_transFFCompensateData_h
#define _ROS_origarm_ros_transFFCompensateData_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "origarm_ros/transFFCompensateDataSeg.h"

namespace origarm_ros
{

  class transFFCompensateData : public ros::Msg
  {
    public:
      origarm_ros::transFFCompensateDataSeg transFFCData[9];

    transFFCompensateData():
      transFFCData()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      for( uint32_t i = 0; i < 9; i++){
      offset += this->transFFCData[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      for( uint32_t i = 0; i < 9; i++){
      offset += this->transFFCData[i].deserialize(inbuffer + offset);
      }
     return offset;
    }

    virtual const char * getType() override { return "origarm_ros/transFFCompensateData"; };
    virtual const char * getMD5() override { return "fd6bdc9a919f2a2e98f6337598c274f1"; };

  };

}
#endif
