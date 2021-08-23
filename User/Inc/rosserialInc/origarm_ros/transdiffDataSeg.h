#ifndef _ROS_origarm_ros_transdiffDataSeg_h
#define _ROS_origarm_ros_transdiffDataSeg_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "ros/time.h"
#include "ros/duration.h"

namespace origarm_ros
{

  class transdiffDataSeg : public ros::Msg
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
      float initPressure[6];
      float initLength[6];
      typedef ros::Time _initTime0_type;
      _initTime0_type initTime0;
      typedef ros::Duration _passedDuration_type;
      _passedDuration_type passedDuration;
      float pressureDecayCoeff[6];
      float initPressureCompensated[6];
      float pressureCommand[6];
      float pressureCommandFiltered[6];
      float pressurefeedforwardTrans[6];
      float pressurefeedforward[6];
      float pressurefeedback[6];
      float pressure[6];
      float lengthFromPressure[6];
      float lengthFromLaser[6];
      int16_t pressureCommandType[6];
      typedef float _alphaCommand_type;
      _alphaCommand_type alphaCommand;
      typedef float _betaCommand_type;
      _betaCommand_type betaCommand;
      typedef float _lengthCommand_type;
      _lengthCommand_type lengthCommand;
      typedef float _alphaPassive_type;
      _alphaPassive_type alphaPassive;
      typedef float _betaPassive_type;
      _betaPassive_type betaPassive;
      typedef float _lengthPassive_type;
      _lengthPassive_type lengthPassive;
      typedef float _alphaPassiveFiltered_type;
      _alphaPassiveFiltered_type alphaPassiveFiltered;
      typedef float _betaPassiveFiltered_type;
      _betaPassiveFiltered_type betaPassiveFiltered;
      typedef float _lengthPassiveFiltered_type;
      _lengthPassiveFiltered_type lengthPassiveFiltered;
      typedef float _alphaLaser_type;
      _alphaLaser_type alphaLaser;
      typedef float _betaLaser_type;
      _betaLaser_type betaLaser;
      typedef float _lengthLaser_type;
      _lengthLaser_type lengthLaser;
      typedef float _alphaLaserFiltered_type;
      _alphaLaserFiltered_type alphaLaserFiltered;
      typedef float _betaLaserFiltered_type;
      _betaLaserFiltered_type betaLaserFiltered;
      typedef float _lengthLaserFiltered_type;
      _lengthLaserFiltered_type lengthLaserFiltered;
      typedef int16_t _transFFFlag_type;
      _transFFFlag_type transFFFlag;
      typedef float _transFFTalpha_type;
      _transFFTalpha_type transFFTalpha;
      typedef float _transFFTbeta_type;
      _transFFTbeta_type transFFTbeta;
      typedef float _dalphaRatio_type;
      _dalphaRatio_type dalphaRatio;
      typedef float _alphaP_type;
      _alphaP_type alphaP;
      typedef float _alphaI_type;
      _alphaI_type alphaI;
      typedef float _alphaD_type;
      _alphaD_type alphaD;
      typedef float _dbeta_type;
      _dbeta_type dbeta;
      typedef float _betaP_type;
      _betaP_type betaP;
      typedef float _betaI_type;
      _betaI_type betaI;
      typedef float _betaD_type;
      _betaD_type betaD;
      typedef float _dlength_type;
      _dlength_type dlength;
      typedef float _lengthP_type;
      _lengthP_type lengthP;
      typedef float _lengthI_type;
      _lengthI_type lengthI;
      typedef float _lengthD_type;
      _lengthD_type lengthD;
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

    transdiffDataSeg():
      transMode(0),
      transSegment(0),
      transActuatorNum(0),
      transPassiveNum(0),
      transActuatorIndex(),
      initPressure(),
      initLength(),
      initTime0(),
      passedDuration(),
      pressureDecayCoeff(),
      initPressureCompensated(),
      pressureCommand(),
      pressureCommandFiltered(),
      pressurefeedforwardTrans(),
      pressurefeedforward(),
      pressurefeedback(),
      pressure(),
      lengthFromPressure(),
      lengthFromLaser(),
      pressureCommandType(),
      alphaCommand(0),
      betaCommand(0),
      lengthCommand(0),
      alphaPassive(0),
      betaPassive(0),
      lengthPassive(0),
      alphaPassiveFiltered(0),
      betaPassiveFiltered(0),
      lengthPassiveFiltered(0),
      alphaLaser(0),
      betaLaser(0),
      lengthLaser(0),
      alphaLaserFiltered(0),
      betaLaserFiltered(0),
      lengthLaserFiltered(0),
      transFFFlag(0),
      transFFTalpha(0),
      transFFTbeta(0),
      dalphaRatio(0),
      alphaP(0),
      alphaI(0),
      alphaD(0),
      dbeta(0),
      betaP(0),
      betaI(0),
      betaD(0),
      dlength(0),
      lengthP(0),
      lengthI(0),
      lengthD(0),
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
      } u_initPressurei;
      u_initPressurei.real = this->initPressure[i];
      *(outbuffer + offset + 0) = (u_initPressurei.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_initPressurei.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_initPressurei.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_initPressurei.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->initPressure[i]);
      }
      for( uint32_t i = 0; i < 6; i++){
      union {
        float real;
        uint32_t base;
      } u_initLengthi;
      u_initLengthi.real = this->initLength[i];
      *(outbuffer + offset + 0) = (u_initLengthi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_initLengthi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_initLengthi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_initLengthi.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->initLength[i]);
      }
      *(outbuffer + offset + 0) = (this->initTime0.sec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->initTime0.sec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->initTime0.sec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->initTime0.sec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->initTime0.sec);
      *(outbuffer + offset + 0) = (this->initTime0.nsec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->initTime0.nsec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->initTime0.nsec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->initTime0.nsec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->initTime0.nsec);
      *(outbuffer + offset + 0) = (this->passedDuration.sec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->passedDuration.sec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->passedDuration.sec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->passedDuration.sec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->passedDuration.sec);
      *(outbuffer + offset + 0) = (this->passedDuration.nsec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->passedDuration.nsec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->passedDuration.nsec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->passedDuration.nsec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->passedDuration.nsec);
      for( uint32_t i = 0; i < 6; i++){
      union {
        float real;
        uint32_t base;
      } u_pressureDecayCoeffi;
      u_pressureDecayCoeffi.real = this->pressureDecayCoeff[i];
      *(outbuffer + offset + 0) = (u_pressureDecayCoeffi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_pressureDecayCoeffi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_pressureDecayCoeffi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_pressureDecayCoeffi.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->pressureDecayCoeff[i]);
      }
      for( uint32_t i = 0; i < 6; i++){
      union {
        float real;
        uint32_t base;
      } u_initPressureCompensatedi;
      u_initPressureCompensatedi.real = this->initPressureCompensated[i];
      *(outbuffer + offset + 0) = (u_initPressureCompensatedi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_initPressureCompensatedi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_initPressureCompensatedi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_initPressureCompensatedi.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->initPressureCompensated[i]);
      }
      for( uint32_t i = 0; i < 6; i++){
      union {
        float real;
        uint32_t base;
      } u_pressureCommandi;
      u_pressureCommandi.real = this->pressureCommand[i];
      *(outbuffer + offset + 0) = (u_pressureCommandi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_pressureCommandi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_pressureCommandi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_pressureCommandi.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->pressureCommand[i]);
      }
      for( uint32_t i = 0; i < 6; i++){
      union {
        float real;
        uint32_t base;
      } u_pressureCommandFilteredi;
      u_pressureCommandFilteredi.real = this->pressureCommandFiltered[i];
      *(outbuffer + offset + 0) = (u_pressureCommandFilteredi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_pressureCommandFilteredi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_pressureCommandFilteredi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_pressureCommandFilteredi.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->pressureCommandFiltered[i]);
      }
      for( uint32_t i = 0; i < 6; i++){
      union {
        float real;
        uint32_t base;
      } u_pressurefeedforwardTransi;
      u_pressurefeedforwardTransi.real = this->pressurefeedforwardTrans[i];
      *(outbuffer + offset + 0) = (u_pressurefeedforwardTransi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_pressurefeedforwardTransi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_pressurefeedforwardTransi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_pressurefeedforwardTransi.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->pressurefeedforwardTrans[i]);
      }
      for( uint32_t i = 0; i < 6; i++){
      union {
        float real;
        uint32_t base;
      } u_pressurefeedforwardi;
      u_pressurefeedforwardi.real = this->pressurefeedforward[i];
      *(outbuffer + offset + 0) = (u_pressurefeedforwardi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_pressurefeedforwardi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_pressurefeedforwardi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_pressurefeedforwardi.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->pressurefeedforward[i]);
      }
      for( uint32_t i = 0; i < 6; i++){
      union {
        float real;
        uint32_t base;
      } u_pressurefeedbacki;
      u_pressurefeedbacki.real = this->pressurefeedback[i];
      *(outbuffer + offset + 0) = (u_pressurefeedbacki.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_pressurefeedbacki.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_pressurefeedbacki.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_pressurefeedbacki.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->pressurefeedback[i]);
      }
      for( uint32_t i = 0; i < 6; i++){
      union {
        float real;
        uint32_t base;
      } u_pressurei;
      u_pressurei.real = this->pressure[i];
      *(outbuffer + offset + 0) = (u_pressurei.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_pressurei.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_pressurei.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_pressurei.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->pressure[i]);
      }
      for( uint32_t i = 0; i < 6; i++){
      union {
        float real;
        uint32_t base;
      } u_lengthFromPressurei;
      u_lengthFromPressurei.real = this->lengthFromPressure[i];
      *(outbuffer + offset + 0) = (u_lengthFromPressurei.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_lengthFromPressurei.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_lengthFromPressurei.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_lengthFromPressurei.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->lengthFromPressure[i]);
      }
      for( uint32_t i = 0; i < 6; i++){
      union {
        float real;
        uint32_t base;
      } u_lengthFromLaseri;
      u_lengthFromLaseri.real = this->lengthFromLaser[i];
      *(outbuffer + offset + 0) = (u_lengthFromLaseri.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_lengthFromLaseri.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_lengthFromLaseri.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_lengthFromLaseri.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->lengthFromLaser[i]);
      }
      for( uint32_t i = 0; i < 6; i++){
      union {
        int16_t real;
        uint16_t base;
      } u_pressureCommandTypei;
      u_pressureCommandTypei.real = this->pressureCommandType[i];
      *(outbuffer + offset + 0) = (u_pressureCommandTypei.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_pressureCommandTypei.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->pressureCommandType[i]);
      }
      union {
        float real;
        uint32_t base;
      } u_alphaCommand;
      u_alphaCommand.real = this->alphaCommand;
      *(outbuffer + offset + 0) = (u_alphaCommand.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_alphaCommand.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_alphaCommand.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_alphaCommand.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->alphaCommand);
      union {
        float real;
        uint32_t base;
      } u_betaCommand;
      u_betaCommand.real = this->betaCommand;
      *(outbuffer + offset + 0) = (u_betaCommand.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_betaCommand.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_betaCommand.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_betaCommand.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->betaCommand);
      union {
        float real;
        uint32_t base;
      } u_lengthCommand;
      u_lengthCommand.real = this->lengthCommand;
      *(outbuffer + offset + 0) = (u_lengthCommand.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_lengthCommand.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_lengthCommand.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_lengthCommand.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->lengthCommand);
      union {
        float real;
        uint32_t base;
      } u_alphaPassive;
      u_alphaPassive.real = this->alphaPassive;
      *(outbuffer + offset + 0) = (u_alphaPassive.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_alphaPassive.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_alphaPassive.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_alphaPassive.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->alphaPassive);
      union {
        float real;
        uint32_t base;
      } u_betaPassive;
      u_betaPassive.real = this->betaPassive;
      *(outbuffer + offset + 0) = (u_betaPassive.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_betaPassive.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_betaPassive.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_betaPassive.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->betaPassive);
      union {
        float real;
        uint32_t base;
      } u_lengthPassive;
      u_lengthPassive.real = this->lengthPassive;
      *(outbuffer + offset + 0) = (u_lengthPassive.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_lengthPassive.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_lengthPassive.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_lengthPassive.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->lengthPassive);
      union {
        float real;
        uint32_t base;
      } u_alphaPassiveFiltered;
      u_alphaPassiveFiltered.real = this->alphaPassiveFiltered;
      *(outbuffer + offset + 0) = (u_alphaPassiveFiltered.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_alphaPassiveFiltered.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_alphaPassiveFiltered.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_alphaPassiveFiltered.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->alphaPassiveFiltered);
      union {
        float real;
        uint32_t base;
      } u_betaPassiveFiltered;
      u_betaPassiveFiltered.real = this->betaPassiveFiltered;
      *(outbuffer + offset + 0) = (u_betaPassiveFiltered.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_betaPassiveFiltered.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_betaPassiveFiltered.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_betaPassiveFiltered.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->betaPassiveFiltered);
      union {
        float real;
        uint32_t base;
      } u_lengthPassiveFiltered;
      u_lengthPassiveFiltered.real = this->lengthPassiveFiltered;
      *(outbuffer + offset + 0) = (u_lengthPassiveFiltered.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_lengthPassiveFiltered.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_lengthPassiveFiltered.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_lengthPassiveFiltered.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->lengthPassiveFiltered);
      union {
        float real;
        uint32_t base;
      } u_alphaLaser;
      u_alphaLaser.real = this->alphaLaser;
      *(outbuffer + offset + 0) = (u_alphaLaser.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_alphaLaser.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_alphaLaser.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_alphaLaser.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->alphaLaser);
      union {
        float real;
        uint32_t base;
      } u_betaLaser;
      u_betaLaser.real = this->betaLaser;
      *(outbuffer + offset + 0) = (u_betaLaser.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_betaLaser.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_betaLaser.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_betaLaser.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->betaLaser);
      union {
        float real;
        uint32_t base;
      } u_lengthLaser;
      u_lengthLaser.real = this->lengthLaser;
      *(outbuffer + offset + 0) = (u_lengthLaser.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_lengthLaser.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_lengthLaser.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_lengthLaser.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->lengthLaser);
      union {
        float real;
        uint32_t base;
      } u_alphaLaserFiltered;
      u_alphaLaserFiltered.real = this->alphaLaserFiltered;
      *(outbuffer + offset + 0) = (u_alphaLaserFiltered.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_alphaLaserFiltered.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_alphaLaserFiltered.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_alphaLaserFiltered.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->alphaLaserFiltered);
      union {
        float real;
        uint32_t base;
      } u_betaLaserFiltered;
      u_betaLaserFiltered.real = this->betaLaserFiltered;
      *(outbuffer + offset + 0) = (u_betaLaserFiltered.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_betaLaserFiltered.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_betaLaserFiltered.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_betaLaserFiltered.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->betaLaserFiltered);
      union {
        float real;
        uint32_t base;
      } u_lengthLaserFiltered;
      u_lengthLaserFiltered.real = this->lengthLaserFiltered;
      *(outbuffer + offset + 0) = (u_lengthLaserFiltered.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_lengthLaserFiltered.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_lengthLaserFiltered.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_lengthLaserFiltered.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->lengthLaserFiltered);
      union {
        int16_t real;
        uint16_t base;
      } u_transFFFlag;
      u_transFFFlag.real = this->transFFFlag;
      *(outbuffer + offset + 0) = (u_transFFFlag.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_transFFFlag.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->transFFFlag);
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
      union {
        float real;
        uint32_t base;
      } u_dalphaRatio;
      u_dalphaRatio.real = this->dalphaRatio;
      *(outbuffer + offset + 0) = (u_dalphaRatio.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_dalphaRatio.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_dalphaRatio.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_dalphaRatio.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->dalphaRatio);
      union {
        float real;
        uint32_t base;
      } u_alphaP;
      u_alphaP.real = this->alphaP;
      *(outbuffer + offset + 0) = (u_alphaP.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_alphaP.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_alphaP.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_alphaP.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->alphaP);
      union {
        float real;
        uint32_t base;
      } u_alphaI;
      u_alphaI.real = this->alphaI;
      *(outbuffer + offset + 0) = (u_alphaI.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_alphaI.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_alphaI.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_alphaI.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->alphaI);
      union {
        float real;
        uint32_t base;
      } u_alphaD;
      u_alphaD.real = this->alphaD;
      *(outbuffer + offset + 0) = (u_alphaD.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_alphaD.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_alphaD.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_alphaD.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->alphaD);
      union {
        float real;
        uint32_t base;
      } u_dbeta;
      u_dbeta.real = this->dbeta;
      *(outbuffer + offset + 0) = (u_dbeta.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_dbeta.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_dbeta.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_dbeta.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->dbeta);
      union {
        float real;
        uint32_t base;
      } u_betaP;
      u_betaP.real = this->betaP;
      *(outbuffer + offset + 0) = (u_betaP.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_betaP.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_betaP.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_betaP.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->betaP);
      union {
        float real;
        uint32_t base;
      } u_betaI;
      u_betaI.real = this->betaI;
      *(outbuffer + offset + 0) = (u_betaI.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_betaI.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_betaI.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_betaI.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->betaI);
      union {
        float real;
        uint32_t base;
      } u_betaD;
      u_betaD.real = this->betaD;
      *(outbuffer + offset + 0) = (u_betaD.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_betaD.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_betaD.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_betaD.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->betaD);
      union {
        float real;
        uint32_t base;
      } u_dlength;
      u_dlength.real = this->dlength;
      *(outbuffer + offset + 0) = (u_dlength.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_dlength.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_dlength.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_dlength.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->dlength);
      union {
        float real;
        uint32_t base;
      } u_lengthP;
      u_lengthP.real = this->lengthP;
      *(outbuffer + offset + 0) = (u_lengthP.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_lengthP.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_lengthP.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_lengthP.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->lengthP);
      union {
        float real;
        uint32_t base;
      } u_lengthI;
      u_lengthI.real = this->lengthI;
      *(outbuffer + offset + 0) = (u_lengthI.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_lengthI.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_lengthI.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_lengthI.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->lengthI);
      union {
        float real;
        uint32_t base;
      } u_lengthD;
      u_lengthD.real = this->lengthD;
      *(outbuffer + offset + 0) = (u_lengthD.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_lengthD.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_lengthD.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_lengthD.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->lengthD);
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
      } u_initPressurei;
      u_initPressurei.base = 0;
      u_initPressurei.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_initPressurei.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_initPressurei.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_initPressurei.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->initPressure[i] = u_initPressurei.real;
      offset += sizeof(this->initPressure[i]);
      }
      for( uint32_t i = 0; i < 6; i++){
      union {
        float real;
        uint32_t base;
      } u_initLengthi;
      u_initLengthi.base = 0;
      u_initLengthi.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_initLengthi.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_initLengthi.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_initLengthi.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->initLength[i] = u_initLengthi.real;
      offset += sizeof(this->initLength[i]);
      }
      this->initTime0.sec =  ((uint32_t) (*(inbuffer + offset)));
      this->initTime0.sec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->initTime0.sec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->initTime0.sec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->initTime0.sec);
      this->initTime0.nsec =  ((uint32_t) (*(inbuffer + offset)));
      this->initTime0.nsec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->initTime0.nsec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->initTime0.nsec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->initTime0.nsec);
      this->passedDuration.sec =  ((uint32_t) (*(inbuffer + offset)));
      this->passedDuration.sec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->passedDuration.sec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->passedDuration.sec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->passedDuration.sec);
      this->passedDuration.nsec =  ((uint32_t) (*(inbuffer + offset)));
      this->passedDuration.nsec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->passedDuration.nsec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->passedDuration.nsec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->passedDuration.nsec);
      for( uint32_t i = 0; i < 6; i++){
      union {
        float real;
        uint32_t base;
      } u_pressureDecayCoeffi;
      u_pressureDecayCoeffi.base = 0;
      u_pressureDecayCoeffi.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_pressureDecayCoeffi.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_pressureDecayCoeffi.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_pressureDecayCoeffi.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->pressureDecayCoeff[i] = u_pressureDecayCoeffi.real;
      offset += sizeof(this->pressureDecayCoeff[i]);
      }
      for( uint32_t i = 0; i < 6; i++){
      union {
        float real;
        uint32_t base;
      } u_initPressureCompensatedi;
      u_initPressureCompensatedi.base = 0;
      u_initPressureCompensatedi.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_initPressureCompensatedi.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_initPressureCompensatedi.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_initPressureCompensatedi.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->initPressureCompensated[i] = u_initPressureCompensatedi.real;
      offset += sizeof(this->initPressureCompensated[i]);
      }
      for( uint32_t i = 0; i < 6; i++){
      union {
        float real;
        uint32_t base;
      } u_pressureCommandi;
      u_pressureCommandi.base = 0;
      u_pressureCommandi.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_pressureCommandi.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_pressureCommandi.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_pressureCommandi.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->pressureCommand[i] = u_pressureCommandi.real;
      offset += sizeof(this->pressureCommand[i]);
      }
      for( uint32_t i = 0; i < 6; i++){
      union {
        float real;
        uint32_t base;
      } u_pressureCommandFilteredi;
      u_pressureCommandFilteredi.base = 0;
      u_pressureCommandFilteredi.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_pressureCommandFilteredi.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_pressureCommandFilteredi.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_pressureCommandFilteredi.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->pressureCommandFiltered[i] = u_pressureCommandFilteredi.real;
      offset += sizeof(this->pressureCommandFiltered[i]);
      }
      for( uint32_t i = 0; i < 6; i++){
      union {
        float real;
        uint32_t base;
      } u_pressurefeedforwardTransi;
      u_pressurefeedforwardTransi.base = 0;
      u_pressurefeedforwardTransi.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_pressurefeedforwardTransi.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_pressurefeedforwardTransi.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_pressurefeedforwardTransi.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->pressurefeedforwardTrans[i] = u_pressurefeedforwardTransi.real;
      offset += sizeof(this->pressurefeedforwardTrans[i]);
      }
      for( uint32_t i = 0; i < 6; i++){
      union {
        float real;
        uint32_t base;
      } u_pressurefeedforwardi;
      u_pressurefeedforwardi.base = 0;
      u_pressurefeedforwardi.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_pressurefeedforwardi.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_pressurefeedforwardi.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_pressurefeedforwardi.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->pressurefeedforward[i] = u_pressurefeedforwardi.real;
      offset += sizeof(this->pressurefeedforward[i]);
      }
      for( uint32_t i = 0; i < 6; i++){
      union {
        float real;
        uint32_t base;
      } u_pressurefeedbacki;
      u_pressurefeedbacki.base = 0;
      u_pressurefeedbacki.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_pressurefeedbacki.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_pressurefeedbacki.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_pressurefeedbacki.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->pressurefeedback[i] = u_pressurefeedbacki.real;
      offset += sizeof(this->pressurefeedback[i]);
      }
      for( uint32_t i = 0; i < 6; i++){
      union {
        float real;
        uint32_t base;
      } u_pressurei;
      u_pressurei.base = 0;
      u_pressurei.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_pressurei.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_pressurei.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_pressurei.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->pressure[i] = u_pressurei.real;
      offset += sizeof(this->pressure[i]);
      }
      for( uint32_t i = 0; i < 6; i++){
      union {
        float real;
        uint32_t base;
      } u_lengthFromPressurei;
      u_lengthFromPressurei.base = 0;
      u_lengthFromPressurei.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_lengthFromPressurei.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_lengthFromPressurei.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_lengthFromPressurei.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->lengthFromPressure[i] = u_lengthFromPressurei.real;
      offset += sizeof(this->lengthFromPressure[i]);
      }
      for( uint32_t i = 0; i < 6; i++){
      union {
        float real;
        uint32_t base;
      } u_lengthFromLaseri;
      u_lengthFromLaseri.base = 0;
      u_lengthFromLaseri.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_lengthFromLaseri.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_lengthFromLaseri.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_lengthFromLaseri.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->lengthFromLaser[i] = u_lengthFromLaseri.real;
      offset += sizeof(this->lengthFromLaser[i]);
      }
      for( uint32_t i = 0; i < 6; i++){
      union {
        int16_t real;
        uint16_t base;
      } u_pressureCommandTypei;
      u_pressureCommandTypei.base = 0;
      u_pressureCommandTypei.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_pressureCommandTypei.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->pressureCommandType[i] = u_pressureCommandTypei.real;
      offset += sizeof(this->pressureCommandType[i]);
      }
      union {
        float real;
        uint32_t base;
      } u_alphaCommand;
      u_alphaCommand.base = 0;
      u_alphaCommand.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_alphaCommand.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_alphaCommand.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_alphaCommand.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->alphaCommand = u_alphaCommand.real;
      offset += sizeof(this->alphaCommand);
      union {
        float real;
        uint32_t base;
      } u_betaCommand;
      u_betaCommand.base = 0;
      u_betaCommand.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_betaCommand.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_betaCommand.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_betaCommand.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->betaCommand = u_betaCommand.real;
      offset += sizeof(this->betaCommand);
      union {
        float real;
        uint32_t base;
      } u_lengthCommand;
      u_lengthCommand.base = 0;
      u_lengthCommand.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_lengthCommand.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_lengthCommand.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_lengthCommand.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->lengthCommand = u_lengthCommand.real;
      offset += sizeof(this->lengthCommand);
      union {
        float real;
        uint32_t base;
      } u_alphaPassive;
      u_alphaPassive.base = 0;
      u_alphaPassive.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_alphaPassive.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_alphaPassive.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_alphaPassive.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->alphaPassive = u_alphaPassive.real;
      offset += sizeof(this->alphaPassive);
      union {
        float real;
        uint32_t base;
      } u_betaPassive;
      u_betaPassive.base = 0;
      u_betaPassive.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_betaPassive.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_betaPassive.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_betaPassive.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->betaPassive = u_betaPassive.real;
      offset += sizeof(this->betaPassive);
      union {
        float real;
        uint32_t base;
      } u_lengthPassive;
      u_lengthPassive.base = 0;
      u_lengthPassive.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_lengthPassive.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_lengthPassive.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_lengthPassive.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->lengthPassive = u_lengthPassive.real;
      offset += sizeof(this->lengthPassive);
      union {
        float real;
        uint32_t base;
      } u_alphaPassiveFiltered;
      u_alphaPassiveFiltered.base = 0;
      u_alphaPassiveFiltered.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_alphaPassiveFiltered.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_alphaPassiveFiltered.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_alphaPassiveFiltered.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->alphaPassiveFiltered = u_alphaPassiveFiltered.real;
      offset += sizeof(this->alphaPassiveFiltered);
      union {
        float real;
        uint32_t base;
      } u_betaPassiveFiltered;
      u_betaPassiveFiltered.base = 0;
      u_betaPassiveFiltered.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_betaPassiveFiltered.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_betaPassiveFiltered.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_betaPassiveFiltered.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->betaPassiveFiltered = u_betaPassiveFiltered.real;
      offset += sizeof(this->betaPassiveFiltered);
      union {
        float real;
        uint32_t base;
      } u_lengthPassiveFiltered;
      u_lengthPassiveFiltered.base = 0;
      u_lengthPassiveFiltered.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_lengthPassiveFiltered.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_lengthPassiveFiltered.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_lengthPassiveFiltered.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->lengthPassiveFiltered = u_lengthPassiveFiltered.real;
      offset += sizeof(this->lengthPassiveFiltered);
      union {
        float real;
        uint32_t base;
      } u_alphaLaser;
      u_alphaLaser.base = 0;
      u_alphaLaser.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_alphaLaser.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_alphaLaser.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_alphaLaser.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->alphaLaser = u_alphaLaser.real;
      offset += sizeof(this->alphaLaser);
      union {
        float real;
        uint32_t base;
      } u_betaLaser;
      u_betaLaser.base = 0;
      u_betaLaser.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_betaLaser.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_betaLaser.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_betaLaser.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->betaLaser = u_betaLaser.real;
      offset += sizeof(this->betaLaser);
      union {
        float real;
        uint32_t base;
      } u_lengthLaser;
      u_lengthLaser.base = 0;
      u_lengthLaser.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_lengthLaser.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_lengthLaser.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_lengthLaser.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->lengthLaser = u_lengthLaser.real;
      offset += sizeof(this->lengthLaser);
      union {
        float real;
        uint32_t base;
      } u_alphaLaserFiltered;
      u_alphaLaserFiltered.base = 0;
      u_alphaLaserFiltered.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_alphaLaserFiltered.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_alphaLaserFiltered.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_alphaLaserFiltered.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->alphaLaserFiltered = u_alphaLaserFiltered.real;
      offset += sizeof(this->alphaLaserFiltered);
      union {
        float real;
        uint32_t base;
      } u_betaLaserFiltered;
      u_betaLaserFiltered.base = 0;
      u_betaLaserFiltered.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_betaLaserFiltered.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_betaLaserFiltered.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_betaLaserFiltered.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->betaLaserFiltered = u_betaLaserFiltered.real;
      offset += sizeof(this->betaLaserFiltered);
      union {
        float real;
        uint32_t base;
      } u_lengthLaserFiltered;
      u_lengthLaserFiltered.base = 0;
      u_lengthLaserFiltered.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_lengthLaserFiltered.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_lengthLaserFiltered.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_lengthLaserFiltered.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->lengthLaserFiltered = u_lengthLaserFiltered.real;
      offset += sizeof(this->lengthLaserFiltered);
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
      union {
        float real;
        uint32_t base;
      } u_dalphaRatio;
      u_dalphaRatio.base = 0;
      u_dalphaRatio.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_dalphaRatio.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_dalphaRatio.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_dalphaRatio.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->dalphaRatio = u_dalphaRatio.real;
      offset += sizeof(this->dalphaRatio);
      union {
        float real;
        uint32_t base;
      } u_alphaP;
      u_alphaP.base = 0;
      u_alphaP.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_alphaP.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_alphaP.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_alphaP.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->alphaP = u_alphaP.real;
      offset += sizeof(this->alphaP);
      union {
        float real;
        uint32_t base;
      } u_alphaI;
      u_alphaI.base = 0;
      u_alphaI.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_alphaI.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_alphaI.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_alphaI.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->alphaI = u_alphaI.real;
      offset += sizeof(this->alphaI);
      union {
        float real;
        uint32_t base;
      } u_alphaD;
      u_alphaD.base = 0;
      u_alphaD.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_alphaD.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_alphaD.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_alphaD.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->alphaD = u_alphaD.real;
      offset += sizeof(this->alphaD);
      union {
        float real;
        uint32_t base;
      } u_dbeta;
      u_dbeta.base = 0;
      u_dbeta.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_dbeta.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_dbeta.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_dbeta.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->dbeta = u_dbeta.real;
      offset += sizeof(this->dbeta);
      union {
        float real;
        uint32_t base;
      } u_betaP;
      u_betaP.base = 0;
      u_betaP.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_betaP.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_betaP.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_betaP.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->betaP = u_betaP.real;
      offset += sizeof(this->betaP);
      union {
        float real;
        uint32_t base;
      } u_betaI;
      u_betaI.base = 0;
      u_betaI.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_betaI.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_betaI.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_betaI.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->betaI = u_betaI.real;
      offset += sizeof(this->betaI);
      union {
        float real;
        uint32_t base;
      } u_betaD;
      u_betaD.base = 0;
      u_betaD.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_betaD.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_betaD.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_betaD.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->betaD = u_betaD.real;
      offset += sizeof(this->betaD);
      union {
        float real;
        uint32_t base;
      } u_dlength;
      u_dlength.base = 0;
      u_dlength.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_dlength.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_dlength.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_dlength.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->dlength = u_dlength.real;
      offset += sizeof(this->dlength);
      union {
        float real;
        uint32_t base;
      } u_lengthP;
      u_lengthP.base = 0;
      u_lengthP.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_lengthP.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_lengthP.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_lengthP.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->lengthP = u_lengthP.real;
      offset += sizeof(this->lengthP);
      union {
        float real;
        uint32_t base;
      } u_lengthI;
      u_lengthI.base = 0;
      u_lengthI.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_lengthI.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_lengthI.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_lengthI.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->lengthI = u_lengthI.real;
      offset += sizeof(this->lengthI);
      union {
        float real;
        uint32_t base;
      } u_lengthD;
      u_lengthD.base = 0;
      u_lengthD.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_lengthD.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_lengthD.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_lengthD.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->lengthD = u_lengthD.real;
      offset += sizeof(this->lengthD);
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

    virtual const char * getType() override { return "origarm_ros/transdiffDataSeg"; };
    virtual const char * getMD5() override { return "773d40ea441e9cc1bbb753f284aefb54"; };

  };

}
#endif
