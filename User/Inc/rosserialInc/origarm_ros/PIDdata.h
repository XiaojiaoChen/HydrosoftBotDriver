#ifndef _ROS_origarm_ros_PIDdata_h
#define _ROS_origarm_ros_PIDdata_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace origarm_ros
{

  class PIDdata : public ros::Msg
  {
    public:
      float dalphaRatio[9];
      float alphaP[9];
      float alphaI[9];
      float alphaD[9];
      float dbeta[9];
      float betaP[9];
      float betaI[9];
      float betaD[9];
      float dlength[9];
      float lengthP[9];
      float lengthI[9];
      float lengthD[9];

    PIDdata():
      dalphaRatio(),
      alphaP(),
      alphaI(),
      alphaD(),
      dbeta(),
      betaP(),
      betaI(),
      betaD(),
      dlength(),
      lengthP(),
      lengthI(),
      lengthD()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      for( uint32_t i = 0; i < 9; i++){
      union {
        float real;
        uint32_t base;
      } u_dalphaRatioi;
      u_dalphaRatioi.real = this->dalphaRatio[i];
      *(outbuffer + offset + 0) = (u_dalphaRatioi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_dalphaRatioi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_dalphaRatioi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_dalphaRatioi.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->dalphaRatio[i]);
      }
      for( uint32_t i = 0; i < 9; i++){
      union {
        float real;
        uint32_t base;
      } u_alphaPi;
      u_alphaPi.real = this->alphaP[i];
      *(outbuffer + offset + 0) = (u_alphaPi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_alphaPi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_alphaPi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_alphaPi.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->alphaP[i]);
      }
      for( uint32_t i = 0; i < 9; i++){
      union {
        float real;
        uint32_t base;
      } u_alphaIi;
      u_alphaIi.real = this->alphaI[i];
      *(outbuffer + offset + 0) = (u_alphaIi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_alphaIi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_alphaIi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_alphaIi.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->alphaI[i]);
      }
      for( uint32_t i = 0; i < 9; i++){
      union {
        float real;
        uint32_t base;
      } u_alphaDi;
      u_alphaDi.real = this->alphaD[i];
      *(outbuffer + offset + 0) = (u_alphaDi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_alphaDi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_alphaDi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_alphaDi.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->alphaD[i]);
      }
      for( uint32_t i = 0; i < 9; i++){
      union {
        float real;
        uint32_t base;
      } u_dbetai;
      u_dbetai.real = this->dbeta[i];
      *(outbuffer + offset + 0) = (u_dbetai.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_dbetai.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_dbetai.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_dbetai.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->dbeta[i]);
      }
      for( uint32_t i = 0; i < 9; i++){
      union {
        float real;
        uint32_t base;
      } u_betaPi;
      u_betaPi.real = this->betaP[i];
      *(outbuffer + offset + 0) = (u_betaPi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_betaPi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_betaPi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_betaPi.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->betaP[i]);
      }
      for( uint32_t i = 0; i < 9; i++){
      union {
        float real;
        uint32_t base;
      } u_betaIi;
      u_betaIi.real = this->betaI[i];
      *(outbuffer + offset + 0) = (u_betaIi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_betaIi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_betaIi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_betaIi.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->betaI[i]);
      }
      for( uint32_t i = 0; i < 9; i++){
      union {
        float real;
        uint32_t base;
      } u_betaDi;
      u_betaDi.real = this->betaD[i];
      *(outbuffer + offset + 0) = (u_betaDi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_betaDi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_betaDi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_betaDi.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->betaD[i]);
      }
      for( uint32_t i = 0; i < 9; i++){
      union {
        float real;
        uint32_t base;
      } u_dlengthi;
      u_dlengthi.real = this->dlength[i];
      *(outbuffer + offset + 0) = (u_dlengthi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_dlengthi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_dlengthi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_dlengthi.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->dlength[i]);
      }
      for( uint32_t i = 0; i < 9; i++){
      union {
        float real;
        uint32_t base;
      } u_lengthPi;
      u_lengthPi.real = this->lengthP[i];
      *(outbuffer + offset + 0) = (u_lengthPi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_lengthPi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_lengthPi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_lengthPi.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->lengthP[i]);
      }
      for( uint32_t i = 0; i < 9; i++){
      union {
        float real;
        uint32_t base;
      } u_lengthIi;
      u_lengthIi.real = this->lengthI[i];
      *(outbuffer + offset + 0) = (u_lengthIi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_lengthIi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_lengthIi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_lengthIi.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->lengthI[i]);
      }
      for( uint32_t i = 0; i < 9; i++){
      union {
        float real;
        uint32_t base;
      } u_lengthDi;
      u_lengthDi.real = this->lengthD[i];
      *(outbuffer + offset + 0) = (u_lengthDi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_lengthDi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_lengthDi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_lengthDi.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->lengthD[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      for( uint32_t i = 0; i < 9; i++){
      union {
        float real;
        uint32_t base;
      } u_dalphaRatioi;
      u_dalphaRatioi.base = 0;
      u_dalphaRatioi.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_dalphaRatioi.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_dalphaRatioi.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_dalphaRatioi.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->dalphaRatio[i] = u_dalphaRatioi.real;
      offset += sizeof(this->dalphaRatio[i]);
      }
      for( uint32_t i = 0; i < 9; i++){
      union {
        float real;
        uint32_t base;
      } u_alphaPi;
      u_alphaPi.base = 0;
      u_alphaPi.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_alphaPi.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_alphaPi.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_alphaPi.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->alphaP[i] = u_alphaPi.real;
      offset += sizeof(this->alphaP[i]);
      }
      for( uint32_t i = 0; i < 9; i++){
      union {
        float real;
        uint32_t base;
      } u_alphaIi;
      u_alphaIi.base = 0;
      u_alphaIi.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_alphaIi.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_alphaIi.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_alphaIi.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->alphaI[i] = u_alphaIi.real;
      offset += sizeof(this->alphaI[i]);
      }
      for( uint32_t i = 0; i < 9; i++){
      union {
        float real;
        uint32_t base;
      } u_alphaDi;
      u_alphaDi.base = 0;
      u_alphaDi.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_alphaDi.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_alphaDi.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_alphaDi.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->alphaD[i] = u_alphaDi.real;
      offset += sizeof(this->alphaD[i]);
      }
      for( uint32_t i = 0; i < 9; i++){
      union {
        float real;
        uint32_t base;
      } u_dbetai;
      u_dbetai.base = 0;
      u_dbetai.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_dbetai.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_dbetai.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_dbetai.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->dbeta[i] = u_dbetai.real;
      offset += sizeof(this->dbeta[i]);
      }
      for( uint32_t i = 0; i < 9; i++){
      union {
        float real;
        uint32_t base;
      } u_betaPi;
      u_betaPi.base = 0;
      u_betaPi.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_betaPi.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_betaPi.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_betaPi.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->betaP[i] = u_betaPi.real;
      offset += sizeof(this->betaP[i]);
      }
      for( uint32_t i = 0; i < 9; i++){
      union {
        float real;
        uint32_t base;
      } u_betaIi;
      u_betaIi.base = 0;
      u_betaIi.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_betaIi.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_betaIi.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_betaIi.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->betaI[i] = u_betaIi.real;
      offset += sizeof(this->betaI[i]);
      }
      for( uint32_t i = 0; i < 9; i++){
      union {
        float real;
        uint32_t base;
      } u_betaDi;
      u_betaDi.base = 0;
      u_betaDi.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_betaDi.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_betaDi.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_betaDi.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->betaD[i] = u_betaDi.real;
      offset += sizeof(this->betaD[i]);
      }
      for( uint32_t i = 0; i < 9; i++){
      union {
        float real;
        uint32_t base;
      } u_dlengthi;
      u_dlengthi.base = 0;
      u_dlengthi.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_dlengthi.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_dlengthi.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_dlengthi.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->dlength[i] = u_dlengthi.real;
      offset += sizeof(this->dlength[i]);
      }
      for( uint32_t i = 0; i < 9; i++){
      union {
        float real;
        uint32_t base;
      } u_lengthPi;
      u_lengthPi.base = 0;
      u_lengthPi.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_lengthPi.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_lengthPi.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_lengthPi.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->lengthP[i] = u_lengthPi.real;
      offset += sizeof(this->lengthP[i]);
      }
      for( uint32_t i = 0; i < 9; i++){
      union {
        float real;
        uint32_t base;
      } u_lengthIi;
      u_lengthIi.base = 0;
      u_lengthIi.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_lengthIi.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_lengthIi.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_lengthIi.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->lengthI[i] = u_lengthIi.real;
      offset += sizeof(this->lengthI[i]);
      }
      for( uint32_t i = 0; i < 9; i++){
      union {
        float real;
        uint32_t base;
      } u_lengthDi;
      u_lengthDi.base = 0;
      u_lengthDi.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_lengthDi.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_lengthDi.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_lengthDi.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->lengthD[i] = u_lengthDi.real;
      offset += sizeof(this->lengthD[i]);
      }
     return offset;
    }

    virtual const char * getType() override { return "origarm_ros/PIDdata"; };
    virtual const char * getMD5() override { return "88263321d5be1e3b7c01ef1996576115"; };

  };

}
#endif
