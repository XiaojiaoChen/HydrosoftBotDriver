#ifndef _ROS_origarm_ros_transdiffConfigSeg_h
#define _ROS_origarm_ros_transdiffConfigSeg_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace origarm_ros
{

  class transdiffConfigSeg : public ros::Msg
  {
    public:
      typedef int16_t _transMode_type;
      _transMode_type transMode;
      typedef int16_t _transSegment_type;
      _transSegment_type transSegment;
      typedef int16_t _transActuatorNum_type;
      _transActuatorNum_type transActuatorNum;
      typedef int16_t _transPassiveNum_type;
      _transPassiveNum_type transPassiveNum;
      int16_t transActuatorIndex[6];
      float transInitPressure[6];
      float transInitLength[6];

    transdiffConfigSeg():
      transMode(0),
      transSegment(0),
      transActuatorNum(0),
      transPassiveNum(0),
      transActuatorIndex(),
      transInitPressure(),
      transInitLength()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        int16_t real;
        uint16_t base;
      } u_transMode;
      u_transMode.real = this->transMode;
      *(outbuffer + offset + 0) = (u_transMode.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_transMode.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->transMode);
      union {
        int16_t real;
        uint16_t base;
      } u_transSegment;
      u_transSegment.real = this->transSegment;
      *(outbuffer + offset + 0) = (u_transSegment.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_transSegment.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->transSegment);
      union {
        int16_t real;
        uint16_t base;
      } u_transActuatorNum;
      u_transActuatorNum.real = this->transActuatorNum;
      *(outbuffer + offset + 0) = (u_transActuatorNum.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_transActuatorNum.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->transActuatorNum);
      union {
        int16_t real;
        uint16_t base;
      } u_transPassiveNum;
      u_transPassiveNum.real = this->transPassiveNum;
      *(outbuffer + offset + 0) = (u_transPassiveNum.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_transPassiveNum.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->transPassiveNum);
      for( uint32_t i = 0; i < 6; i++){
      union {
        int16_t real;
        uint16_t base;
      } u_transActuatorIndexi;
      u_transActuatorIndexi.real = this->transActuatorIndex[i];
      *(outbuffer + offset + 0) = (u_transActuatorIndexi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_transActuatorIndexi.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->transActuatorIndex[i]);
      }
      for( uint32_t i = 0; i < 6; i++){
      union {
        float real;
        uint32_t base;
      } u_transInitPressurei;
      u_transInitPressurei.real = this->transInitPressure[i];
      *(outbuffer + offset + 0) = (u_transInitPressurei.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_transInitPressurei.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_transInitPressurei.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_transInitPressurei.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->transInitPressure[i]);
      }
      for( uint32_t i = 0; i < 6; i++){
      union {
        float real;
        uint32_t base;
      } u_transInitLengthi;
      u_transInitLengthi.real = this->transInitLength[i];
      *(outbuffer + offset + 0) = (u_transInitLengthi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_transInitLengthi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_transInitLengthi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_transInitLengthi.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->transInitLength[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        int16_t real;
        uint16_t base;
      } u_transMode;
      u_transMode.base = 0;
      u_transMode.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_transMode.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->transMode = u_transMode.real;
      offset += sizeof(this->transMode);
      union {
        int16_t real;
        uint16_t base;
      } u_transSegment;
      u_transSegment.base = 0;
      u_transSegment.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_transSegment.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->transSegment = u_transSegment.real;
      offset += sizeof(this->transSegment);
      union {
        int16_t real;
        uint16_t base;
      } u_transActuatorNum;
      u_transActuatorNum.base = 0;
      u_transActuatorNum.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_transActuatorNum.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->transActuatorNum = u_transActuatorNum.real;
      offset += sizeof(this->transActuatorNum);
      union {
        int16_t real;
        uint16_t base;
      } u_transPassiveNum;
      u_transPassiveNum.base = 0;
      u_transPassiveNum.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_transPassiveNum.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->transPassiveNum = u_transPassiveNum.real;
      offset += sizeof(this->transPassiveNum);
      for( uint32_t i = 0; i < 6; i++){
      union {
        int16_t real;
        uint16_t base;
      } u_transActuatorIndexi;
      u_transActuatorIndexi.base = 0;
      u_transActuatorIndexi.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_transActuatorIndexi.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->transActuatorIndex[i] = u_transActuatorIndexi.real;
      offset += sizeof(this->transActuatorIndex[i]);
      }
      for( uint32_t i = 0; i < 6; i++){
      union {
        float real;
        uint32_t base;
      } u_transInitPressurei;
      u_transInitPressurei.base = 0;
      u_transInitPressurei.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_transInitPressurei.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_transInitPressurei.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_transInitPressurei.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->transInitPressure[i] = u_transInitPressurei.real;
      offset += sizeof(this->transInitPressure[i]);
      }
      for( uint32_t i = 0; i < 6; i++){
      union {
        float real;
        uint32_t base;
      } u_transInitLengthi;
      u_transInitLengthi.base = 0;
      u_transInitLengthi.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_transInitLengthi.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_transInitLengthi.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_transInitLengthi.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->transInitLength[i] = u_transInitLengthi.real;
      offset += sizeof(this->transInitLength[i]);
      }
     return offset;
    }

    virtual const char * getType() override { return "origarm_ros/transdiffConfigSeg"; };
    virtual const char * getMD5() override { return "cc765cba9d4b638e5f892499c2258c9e"; };

  };

}
#endif
