#ifndef _ROS_hydrosoft_ros_Sensor_Arm_h
#define _ROS_hydrosoft_ros_Sensor_Arm_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace hydrosoft_ros
{

  class Sensor_Arm : public ros::Msg
  {
    public:
      typedef int16_t _controlModeStatus_type;
      _controlModeStatus_type controlModeStatus;
      uint32_t actuatorStatus_length;
      typedef int16_t _actuatorStatus_type;
      _actuatorStatus_type st_actuatorStatus;
      _actuatorStatus_type * actuatorStatus;
      typedef int16_t _gripperStatus_type;
      _gripperStatus_type gripperStatus;
      typedef int16_t _pSourceStatus_type;
      _pSourceStatus_type pSourceStatus;
      typedef int16_t _pSinkStatus_type;
      _pSinkStatus_type pSinkStatus;
      uint32_t quaternions_length;
      typedef int16_t _quaternions_type;
      _quaternions_type st_quaternions;
      _quaternions_type * quaternions;

    Sensor_Arm():
      controlModeStatus(0),
      actuatorStatus_length(0), st_actuatorStatus(), actuatorStatus(nullptr),
      gripperStatus(0),
      pSourceStatus(0),
      pSinkStatus(0),
      quaternions_length(0), st_quaternions(), quaternions(nullptr)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        int16_t real;
        uint16_t base;
      } u_controlModeStatus;
      u_controlModeStatus.real = this->controlModeStatus;
      *(outbuffer + offset + 0) = (u_controlModeStatus.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_controlModeStatus.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->controlModeStatus);
      *(outbuffer + offset + 0) = (this->actuatorStatus_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->actuatorStatus_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->actuatorStatus_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->actuatorStatus_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->actuatorStatus_length);
      for( uint32_t i = 0; i < actuatorStatus_length; i++){
      union {
        int16_t real;
        uint16_t base;
      } u_actuatorStatusi;
      u_actuatorStatusi.real = this->actuatorStatus[i];
      *(outbuffer + offset + 0) = (u_actuatorStatusi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_actuatorStatusi.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->actuatorStatus[i]);
      }
      union {
        int16_t real;
        uint16_t base;
      } u_gripperStatus;
      u_gripperStatus.real = this->gripperStatus;
      *(outbuffer + offset + 0) = (u_gripperStatus.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_gripperStatus.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->gripperStatus);
      union {
        int16_t real;
        uint16_t base;
      } u_pSourceStatus;
      u_pSourceStatus.real = this->pSourceStatus;
      *(outbuffer + offset + 0) = (u_pSourceStatus.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_pSourceStatus.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->pSourceStatus);
      union {
        int16_t real;
        uint16_t base;
      } u_pSinkStatus;
      u_pSinkStatus.real = this->pSinkStatus;
      *(outbuffer + offset + 0) = (u_pSinkStatus.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_pSinkStatus.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->pSinkStatus);
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
      union {
        int16_t real;
        uint16_t base;
      } u_controlModeStatus;
      u_controlModeStatus.base = 0;
      u_controlModeStatus.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_controlModeStatus.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->controlModeStatus = u_controlModeStatus.real;
      offset += sizeof(this->controlModeStatus);
      uint32_t actuatorStatus_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      actuatorStatus_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      actuatorStatus_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      actuatorStatus_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->actuatorStatus_length);
      if(actuatorStatus_lengthT > actuatorStatus_length)
        this->actuatorStatus = (int16_t*)realloc(this->actuatorStatus, actuatorStatus_lengthT * sizeof(int16_t));
      actuatorStatus_length = actuatorStatus_lengthT;
      for( uint32_t i = 0; i < actuatorStatus_length; i++){
      union {
        int16_t real;
        uint16_t base;
      } u_st_actuatorStatus;
      u_st_actuatorStatus.base = 0;
      u_st_actuatorStatus.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_actuatorStatus.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->st_actuatorStatus = u_st_actuatorStatus.real;
      offset += sizeof(this->st_actuatorStatus);
        memcpy( &(this->actuatorStatus[i]), &(this->st_actuatorStatus), sizeof(int16_t));
      }
      union {
        int16_t real;
        uint16_t base;
      } u_gripperStatus;
      u_gripperStatus.base = 0;
      u_gripperStatus.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_gripperStatus.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->gripperStatus = u_gripperStatus.real;
      offset += sizeof(this->gripperStatus);
      union {
        int16_t real;
        uint16_t base;
      } u_pSourceStatus;
      u_pSourceStatus.base = 0;
      u_pSourceStatus.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_pSourceStatus.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->pSourceStatus = u_pSourceStatus.real;
      offset += sizeof(this->pSourceStatus);
      union {
        int16_t real;
        uint16_t base;
      } u_pSinkStatus;
      u_pSinkStatus.base = 0;
      u_pSinkStatus.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_pSinkStatus.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->pSinkStatus = u_pSinkStatus.real;
      offset += sizeof(this->pSinkStatus);
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

    virtual const char * getType() override { return "hydrosoft_ros/Sensor_Arm"; };
    virtual const char * getMD5() override { return "1e8353ed362cc5c1cb8a961b34c6c836"; };

  };

}
#endif
