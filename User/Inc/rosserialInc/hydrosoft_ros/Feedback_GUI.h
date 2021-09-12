#ifndef _ROS_hydrosoft_ros_Feedback_GUI_h
#define _ROS_hydrosoft_ros_Feedback_GUI_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace hydrosoft_ros
{

  class Feedback_GUI : public ros::Msg
  {
    public:
      typedef uint8_t _modeStatus_type;
      _modeStatus_type modeStatus;
      typedef int32_t _armStatus_type;
      _armStatus_type armStatus;
      typedef int16_t _pSourcePressure_type;
      _pSourcePressure_type pSourcePressure;
      typedef int16_t _pSinkPressure_type;
      _pSinkPressure_type pSinkPressure;
      uint32_t quaternions_length;
      typedef int16_t _quaternions_type;
      _quaternions_type st_quaternions;
      _quaternions_type * quaternions;

    Feedback_GUI():
      modeStatus(0),
      armStatus(0),
      pSourcePressure(0),
      pSinkPressure(0),
      quaternions_length(0), st_quaternions(), quaternions(nullptr)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->modeStatus >> (8 * 0)) & 0xFF;
      offset += sizeof(this->modeStatus);
      union {
        int32_t real;
        uint32_t base;
      } u_armStatus;
      u_armStatus.real = this->armStatus;
      *(outbuffer + offset + 0) = (u_armStatus.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_armStatus.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_armStatus.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_armStatus.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->armStatus);
      union {
        int16_t real;
        uint16_t base;
      } u_pSourcePressure;
      u_pSourcePressure.real = this->pSourcePressure;
      *(outbuffer + offset + 0) = (u_pSourcePressure.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_pSourcePressure.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->pSourcePressure);
      union {
        int16_t real;
        uint16_t base;
      } u_pSinkPressure;
      u_pSinkPressure.real = this->pSinkPressure;
      *(outbuffer + offset + 0) = (u_pSinkPressure.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_pSinkPressure.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->pSinkPressure);
      *(outbuffer + offset + 0) = (this->quaternions_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->quaternions_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->quaternions_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->quaternions_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->quaternions_length);
      for( uint32_t i = 0; i < quaternions_length; i++){
      union {
        int16_t real;
        uint16_t base;
      } u_quaternionsi;
      u_quaternionsi.real = this->quaternions[i];
      *(outbuffer + offset + 0) = (u_quaternionsi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_quaternionsi.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->quaternions[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      this->modeStatus =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->modeStatus);
      union {
        int32_t real;
        uint32_t base;
      } u_armStatus;
      u_armStatus.base = 0;
      u_armStatus.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_armStatus.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_armStatus.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_armStatus.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->armStatus = u_armStatus.real;
      offset += sizeof(this->armStatus);
      union {
        int16_t real;
        uint16_t base;
      } u_pSourcePressure;
      u_pSourcePressure.base = 0;
      u_pSourcePressure.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_pSourcePressure.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->pSourcePressure = u_pSourcePressure.real;
      offset += sizeof(this->pSourcePressure);
      union {
        int16_t real;
        uint16_t base;
      } u_pSinkPressure;
      u_pSinkPressure.base = 0;
      u_pSinkPressure.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_pSinkPressure.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->pSinkPressure = u_pSinkPressure.real;
      offset += sizeof(this->pSinkPressure);
      uint32_t quaternions_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      quaternions_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      quaternions_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      quaternions_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->quaternions_length);
      if(quaternions_lengthT > quaternions_length)
        this->quaternions = (int16_t*)realloc(this->quaternions, quaternions_lengthT * sizeof(int16_t));
      quaternions_length = quaternions_lengthT;
      for( uint32_t i = 0; i < quaternions_length; i++){
      union {
        int16_t real;
        uint16_t base;
      } u_st_quaternions;
      u_st_quaternions.base = 0;
      u_st_quaternions.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_quaternions.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->st_quaternions = u_st_quaternions.real;
      offset += sizeof(this->st_quaternions);
        memcpy( &(this->quaternions[i]), &(this->st_quaternions), sizeof(int16_t));
      }
     return offset;
    }

    virtual const char * getType() override { return "hydrosoft_ros/Feedback_GUI"; };
    virtual const char * getMD5() override { return "b5d166c5e4df66218eee085d673c5f40"; };

  };

}
#endif
