#ifndef _ROS_origarm_ros_PIDparam_h
#define _ROS_origarm_ros_PIDparam_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace origarm_ros
{

  class PIDparam : public ros::Msg
  {
    public:
      typedef int16_t _segIndex_type;
      _segIndex_type segIndex;
      typedef int16_t _ablIndex_type;
      _ablIndex_type ablIndex;
      typedef const char* _paraName_type;
      _paraName_type paraName;
      typedef float _paraValue_type;
      _paraValue_type paraValue;

    PIDparam():
      segIndex(0),
      ablIndex(0),
      paraName(""),
      paraValue(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        int16_t real;
        uint16_t base;
      } u_segIndex;
      u_segIndex.real = this->segIndex;
      *(outbuffer + offset + 0) = (u_segIndex.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_segIndex.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->segIndex);
      union {
        int16_t real;
        uint16_t base;
      } u_ablIndex;
      u_ablIndex.real = this->ablIndex;
      *(outbuffer + offset + 0) = (u_ablIndex.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_ablIndex.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->ablIndex);
      uint32_t length_paraName = strlen(this->paraName);
      varToArr(outbuffer + offset, length_paraName);
      offset += 4;
      memcpy(outbuffer + offset, this->paraName, length_paraName);
      offset += length_paraName;
      union {
        float real;
        uint32_t base;
      } u_paraValue;
      u_paraValue.real = this->paraValue;
      *(outbuffer + offset + 0) = (u_paraValue.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_paraValue.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_paraValue.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_paraValue.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->paraValue);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        int16_t real;
        uint16_t base;
      } u_segIndex;
      u_segIndex.base = 0;
      u_segIndex.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_segIndex.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->segIndex = u_segIndex.real;
      offset += sizeof(this->segIndex);
      union {
        int16_t real;
        uint16_t base;
      } u_ablIndex;
      u_ablIndex.base = 0;
      u_ablIndex.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_ablIndex.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->ablIndex = u_ablIndex.real;
      offset += sizeof(this->ablIndex);
      uint32_t length_paraName;
      arrToVar(length_paraName, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_paraName; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_paraName-1]=0;
      this->paraName = (char *)(inbuffer + offset-1);
      offset += length_paraName;
      union {
        float real;
        uint32_t base;
      } u_paraValue;
      u_paraValue.base = 0;
      u_paraValue.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_paraValue.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_paraValue.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_paraValue.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->paraValue = u_paraValue.real;
      offset += sizeof(this->paraValue);
     return offset;
    }

    virtual const char * getType() override { return "origarm_ros/PIDparam"; };
    virtual const char * getMD5() override { return "e472d57036828c01c42a93a327c3e393"; };

  };

}
#endif
