#ifndef _ROS_origarm_ros_transFFCompensateDataSeg_h
#define _ROS_origarm_ros_transFFCompensateDataSeg_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace origarm_ros
{

  class transFFCompensateDataSeg : public ros::Msg
  {
    public:
      typedef int16_t _transFFFlag_type;
      _transFFFlag_type transFFFlag;
      typedef int16_t _transSegment_type;
      _transSegment_type transSegment;
      typedef float _transFFTalpha_type;
      _transFFTalpha_type transFFTalpha;
      typedef float _transFFTbeta_type;
      _transFFTbeta_type transFFTbeta;
      float FFPressure[6];
      float transFFPressure[6];
      typedef float _vectorAB_Dx_type;
      _vectorAB_Dx_type vectorAB_Dx;
      typedef float _vectorAB_Dy_type;
      _vectorAB_Dy_type vectorAB_Dy;
      typedef float _vectorAB_rx_type;
      _vectorAB_rx_type vectorAB_rx;
      typedef float _vectorAB_ry_type;
      _vectorAB_ry_type vectorAB_ry;
      typedef float _vectorAB_Errx_type;
      _vectorAB_Errx_type vectorAB_Errx;
      typedef float _vectorAB_Erry_type;
      _vectorAB_Erry_type vectorAB_Erry;
      typedef float _vectorAB_ErrProjx_type;
      _vectorAB_ErrProjx_type vectorAB_ErrProjx;
      typedef float _vectorAB_ErrProjy_type;
      _vectorAB_ErrProjy_type vectorAB_ErrProjy;
      typedef float _vectorAB_FBx_type;
      _vectorAB_FBx_type vectorAB_FBx;
      typedef float _vectorAB_FBy_type;
      _vectorAB_FBy_type vectorAB_FBy;

    transFFCompensateDataSeg():
      transFFFlag(0),
      transSegment(0),
      transFFTalpha(0),
      transFFTbeta(0),
      FFPressure(),
      transFFPressure(),
      vectorAB_Dx(0),
      vectorAB_Dy(0),
      vectorAB_rx(0),
      vectorAB_ry(0),
      vectorAB_Errx(0),
      vectorAB_Erry(0),
      vectorAB_ErrProjx(0),
      vectorAB_ErrProjy(0),
      vectorAB_FBx(0),
      vectorAB_FBy(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        int16_t real;
        uint16_t base;
      } u_transFFFlag;
      u_transFFFlag.real = this->transFFFlag;
      *(outbuffer + offset + 0) = (u_transFFFlag.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_transFFFlag.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->transFFFlag);
      union {
        int16_t real;
        uint16_t base;
      } u_transSegment;
      u_transSegment.real = this->transSegment;
      *(outbuffer + offset + 0) = (u_transSegment.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_transSegment.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->transSegment);
      union {
        float real;
        uint32_t base;
      } u_transFFTalpha;
      u_transFFTalpha.real = this->transFFTalpha;
      *(outbuffer + offset + 0) = (u_transFFTalpha.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_transFFTalpha.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_transFFTalpha.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_transFFTalpha.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->transFFTalpha);
      union {
        float real;
        uint32_t base;
      } u_transFFTbeta;
      u_transFFTbeta.real = this->transFFTbeta;
      *(outbuffer + offset + 0) = (u_transFFTbeta.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_transFFTbeta.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_transFFTbeta.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_transFFTbeta.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->transFFTbeta);
      for( uint32_t i = 0; i < 6; i++){
      union {
        float real;
        uint32_t base;
      } u_FFPressurei;
      u_FFPressurei.real = this->FFPressure[i];
      *(outbuffer + offset + 0) = (u_FFPressurei.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_FFPressurei.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_FFPressurei.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_FFPressurei.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->FFPressure[i]);
      }
      for( uint32_t i = 0; i < 6; i++){
      union {
        float real;
        uint32_t base;
      } u_transFFPressurei;
      u_transFFPressurei.real = this->transFFPressure[i];
      *(outbuffer + offset + 0) = (u_transFFPressurei.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_transFFPressurei.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_transFFPressurei.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_transFFPressurei.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->transFFPressure[i]);
      }
      union {
        float real;
        uint32_t base;
      } u_vectorAB_Dx;
      u_vectorAB_Dx.real = this->vectorAB_Dx;
      *(outbuffer + offset + 0) = (u_vectorAB_Dx.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_vectorAB_Dx.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_vectorAB_Dx.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_vectorAB_Dx.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->vectorAB_Dx);
      union {
        float real;
        uint32_t base;
      } u_vectorAB_Dy;
      u_vectorAB_Dy.real = this->vectorAB_Dy;
      *(outbuffer + offset + 0) = (u_vectorAB_Dy.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_vectorAB_Dy.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_vectorAB_Dy.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_vectorAB_Dy.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->vectorAB_Dy);
      union {
        float real;
        uint32_t base;
      } u_vectorAB_rx;
      u_vectorAB_rx.real = this->vectorAB_rx;
      *(outbuffer + offset + 0) = (u_vectorAB_rx.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_vectorAB_rx.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_vectorAB_rx.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_vectorAB_rx.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->vectorAB_rx);
      union {
        float real;
        uint32_t base;
      } u_vectorAB_ry;
      u_vectorAB_ry.real = this->vectorAB_ry;
      *(outbuffer + offset + 0) = (u_vectorAB_ry.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_vectorAB_ry.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_vectorAB_ry.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_vectorAB_ry.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->vectorAB_ry);
      union {
        float real;
        uint32_t base;
      } u_vectorAB_Errx;
      u_vectorAB_Errx.real = this->vectorAB_Errx;
      *(outbuffer + offset + 0) = (u_vectorAB_Errx.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_vectorAB_Errx.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_vectorAB_Errx.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_vectorAB_Errx.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->vectorAB_Errx);
      union {
        float real;
        uint32_t base;
      } u_vectorAB_Erry;
      u_vectorAB_Erry.real = this->vectorAB_Erry;
      *(outbuffer + offset + 0) = (u_vectorAB_Erry.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_vectorAB_Erry.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_vectorAB_Erry.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_vectorAB_Erry.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->vectorAB_Erry);
      union {
        float real;
        uint32_t base;
      } u_vectorAB_ErrProjx;
      u_vectorAB_ErrProjx.real = this->vectorAB_ErrProjx;
      *(outbuffer + offset + 0) = (u_vectorAB_ErrProjx.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_vectorAB_ErrProjx.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_vectorAB_ErrProjx.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_vectorAB_ErrProjx.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->vectorAB_ErrProjx);
      union {
        float real;
        uint32_t base;
      } u_vectorAB_ErrProjy;
      u_vectorAB_ErrProjy.real = this->vectorAB_ErrProjy;
      *(outbuffer + offset + 0) = (u_vectorAB_ErrProjy.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_vectorAB_ErrProjy.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_vectorAB_ErrProjy.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_vectorAB_ErrProjy.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->vectorAB_ErrProjy);
      union {
        float real;
        uint32_t base;
      } u_vectorAB_FBx;
      u_vectorAB_FBx.real = this->vectorAB_FBx;
      *(outbuffer + offset + 0) = (u_vectorAB_FBx.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_vectorAB_FBx.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_vectorAB_FBx.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_vectorAB_FBx.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->vectorAB_FBx);
      union {
        float real;
        uint32_t base;
      } u_vectorAB_FBy;
      u_vectorAB_FBy.real = this->vectorAB_FBy;
      *(outbuffer + offset + 0) = (u_vectorAB_FBy.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_vectorAB_FBy.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_vectorAB_FBy.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_vectorAB_FBy.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->vectorAB_FBy);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        int16_t real;
        uint16_t base;
      } u_transFFFlag;
      u_transFFFlag.base = 0;
      u_transFFFlag.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_transFFFlag.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->transFFFlag = u_transFFFlag.real;
      offset += sizeof(this->transFFFlag);
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
        float real;
        uint32_t base;
      } u_transFFTalpha;
      u_transFFTalpha.base = 0;
      u_transFFTalpha.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_transFFTalpha.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_transFFTalpha.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_transFFTalpha.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->transFFTalpha = u_transFFTalpha.real;
      offset += sizeof(this->transFFTalpha);
      union {
        float real;
        uint32_t base;
      } u_transFFTbeta;
      u_transFFTbeta.base = 0;
      u_transFFTbeta.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_transFFTbeta.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_transFFTbeta.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_transFFTbeta.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->transFFTbeta = u_transFFTbeta.real;
      offset += sizeof(this->transFFTbeta);
      for( uint32_t i = 0; i < 6; i++){
      union {
        float real;
        uint32_t base;
      } u_FFPressurei;
      u_FFPressurei.base = 0;
      u_FFPressurei.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_FFPressurei.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_FFPressurei.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_FFPressurei.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->FFPressure[i] = u_FFPressurei.real;
      offset += sizeof(this->FFPressure[i]);
      }
      for( uint32_t i = 0; i < 6; i++){
      union {
        float real;
        uint32_t base;
      } u_transFFPressurei;
      u_transFFPressurei.base = 0;
      u_transFFPressurei.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_transFFPressurei.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_transFFPressurei.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_transFFPressurei.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->transFFPressure[i] = u_transFFPressurei.real;
      offset += sizeof(this->transFFPressure[i]);
      }
      union {
        float real;
        uint32_t base;
      } u_vectorAB_Dx;
      u_vectorAB_Dx.base = 0;
      u_vectorAB_Dx.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_vectorAB_Dx.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_vectorAB_Dx.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_vectorAB_Dx.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->vectorAB_Dx = u_vectorAB_Dx.real;
      offset += sizeof(this->vectorAB_Dx);
      union {
        float real;
        uint32_t base;
      } u_vectorAB_Dy;
      u_vectorAB_Dy.base = 0;
      u_vectorAB_Dy.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_vectorAB_Dy.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_vectorAB_Dy.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_vectorAB_Dy.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->vectorAB_Dy = u_vectorAB_Dy.real;
      offset += sizeof(this->vectorAB_Dy);
      union {
        float real;
        uint32_t base;
      } u_vectorAB_rx;
      u_vectorAB_rx.base = 0;
      u_vectorAB_rx.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_vectorAB_rx.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_vectorAB_rx.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_vectorAB_rx.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->vectorAB_rx = u_vectorAB_rx.real;
      offset += sizeof(this->vectorAB_rx);
      union {
        float real;
        uint32_t base;
      } u_vectorAB_ry;
      u_vectorAB_ry.base = 0;
      u_vectorAB_ry.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_vectorAB_ry.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_vectorAB_ry.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_vectorAB_ry.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->vectorAB_ry = u_vectorAB_ry.real;
      offset += sizeof(this->vectorAB_ry);
      union {
        float real;
        uint32_t base;
      } u_vectorAB_Errx;
      u_vectorAB_Errx.base = 0;
      u_vectorAB_Errx.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_vectorAB_Errx.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_vectorAB_Errx.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_vectorAB_Errx.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->vectorAB_Errx = u_vectorAB_Errx.real;
      offset += sizeof(this->vectorAB_Errx);
      union {
        float real;
        uint32_t base;
      } u_vectorAB_Erry;
      u_vectorAB_Erry.base = 0;
      u_vectorAB_Erry.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_vectorAB_Erry.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_vectorAB_Erry.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_vectorAB_Erry.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->vectorAB_Erry = u_vectorAB_Erry.real;
      offset += sizeof(this->vectorAB_Erry);
      union {
        float real;
        uint32_t base;
      } u_vectorAB_ErrProjx;
      u_vectorAB_ErrProjx.base = 0;
      u_vectorAB_ErrProjx.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_vectorAB_ErrProjx.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_vectorAB_ErrProjx.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_vectorAB_ErrProjx.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->vectorAB_ErrProjx = u_vectorAB_ErrProjx.real;
      offset += sizeof(this->vectorAB_ErrProjx);
      union {
        float real;
        uint32_t base;
      } u_vectorAB_ErrProjy;
      u_vectorAB_ErrProjy.base = 0;
      u_vectorAB_ErrProjy.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_vectorAB_ErrProjy.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_vectorAB_ErrProjy.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_vectorAB_ErrProjy.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->vectorAB_ErrProjy = u_vectorAB_ErrProjy.real;
      offset += sizeof(this->vectorAB_ErrProjy);
      union {
        float real;
        uint32_t base;
      } u_vectorAB_FBx;
      u_vectorAB_FBx.base = 0;
      u_vectorAB_FBx.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_vectorAB_FBx.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_vectorAB_FBx.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_vectorAB_FBx.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->vectorAB_FBx = u_vectorAB_FBx.real;
      offset += sizeof(this->vectorAB_FBx);
      union {
        float real;
        uint32_t base;
      } u_vectorAB_FBy;
      u_vectorAB_FBy.base = 0;
      u_vectorAB_FBy.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_vectorAB_FBy.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_vectorAB_FBy.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_vectorAB_FBy.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->vectorAB_FBy = u_vectorAB_FBy.real;
      offset += sizeof(this->vectorAB_FBy);
     return offset;
    }

    virtual const char * getType() override { return "origarm_ros/transFFCompensateDataSeg"; };
    virtual const char * getMD5() override { return "04fd87df20c26a1565c17c1c3cf295b3"; };

  };

}
#endif
