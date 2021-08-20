#ifndef _ROS_origarm_ros_Pose32_h
#define _ROS_origarm_ros_Pose32_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "origarm_ros/Point32.h"
#include "origarm_ros/Quaternion32.h"

namespace origarm_ros
{

  class Pose32 : public ros::Msg
  {
    public:
      typedef origarm_ros::Point32 _position_type;
      _position_type position;
      typedef origarm_ros::Quaternion32 _orientation_type;
      _orientation_type orientation;

    Pose32():
      position(),
      orientation()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->position.serialize(outbuffer + offset);
      offset += this->orientation.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->position.deserialize(inbuffer + offset);
      offset += this->orientation.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType() override { return "origarm_ros/Pose32"; };
    virtual const char * getMD5() override { return "1ec5a94781ee76f5aa190025baf9a1a4"; };

  };

}
#endif
