/*
 * buttonMaps.h
 *
 *  Created on: 10 Dec 2021
 *      Author: hydrosoft
 */

#ifndef BUTTONMAPS_H_
#define BUTTONMAPS_H_

//
//#include <map>
//
//std::map<std::string, uint32_t> bitMaskDict = {
//	'ActInValveBtn_seg_0': 21,
//    'ActInValveBtn_seg_1': 1344,
//    'ActInValveBtn_seg_2': 86016,
//    'ActOutValveBtn_seg_0': 42,
//    'ActOutValveBtn_seg_1': 2688,
//    'ActOutValveBtn_seg_2': 172032,
//    'PSinkBtn': 12582912,
//    'PSourceBtn': 3145728,
//    'actInValveBtn_seg_0_act_0': 1,
//    'actInValveBtn_seg_0_act_1': 4,
//    'actInValveBtn_seg_0_act_2': 16,
//    'actInValveBtn_seg_1_act_0': 64,
//    'actInValveBtn_seg_1_act_1': 256,
//    'actInValveBtn_seg_1_act_2': 1024,
//    'actInValveBtn_seg_2_act_0': 4096,
//    'actInValveBtn_seg_2_act_1': 16384,
//    'actInValveBtn_seg_2_act_2': 65536,
//    'actOutValveBtn_seg_0_act_0': 2,
//    'actOutValveBtn_seg_0_act_1': 8,
//    'actOutValveBtn_seg_0_act_2': 32,
//    'actOutValveBtn_seg_1_act_0': 128,
//    'actOutValveBtn_seg_1_act_1': 512,
//    'actOutValveBtn_seg_1_act_2': 2048,
//    'actOutValveBtn_seg_2_act_0': 8192,
//    'actOutValveBtn_seg_2_act_1': 32768,
//    'actOutValveBtn_seg_2_act_2': 131072,
//    'gripperInValveBtn': 262144,
//    'gripperOutValveBtn': 524288,
//    'joystick3DBtn': 4,
//    'joystickBtn': 2,
//    'manualControlBtn': 1,
//    'pSinkPumpBtn': 8388608,
//    'pSinkValveBtn': 4194304,
//    'pSourcePumpBtn': 2097152,
//    'pSourceValveBtn': 1048576,
//    'radioBtn_autoControl': 32,
//    'radioBtn_feedbackControl': 8,
//    'radioBtn_pressureControl': 16};
//
//111100000000101001010110
//111100000000000001000010
#include <map>

std::map<std::string, uint32_t> bitMaskDict = {
    {"ActInValveBtn_seg_0", 21},
    {"ActInValveBtn_seg_1", 1344},
    {"ActInValveBtn_seg_2", 86016},
    {"ActOutValveBtn_seg_0", 42},
    {"ActOutValveBtn_seg_1", 2688},
    {"ActOutValveBtn_seg_2", 172032},
    {"PSinkBtn", 12582912},
    {"PSourceBtn", 3145728},
    {"actInValveBtn_seg_0_act_0", 1},
    {"actInValveBtn_seg_0_act_1", 4},
    {"actInValveBtn_seg_0_act_2", 16},
    {"actInValveBtn_seg_1_act_0", 64},
    {"actInValveBtn_seg_1_act_1", 256},
    {"actInValveBtn_seg_1_act_2", 1024},
    {"actInValveBtn_seg_2_act_0", 4096},
    {"actInValveBtn_seg_2_act_1", 16384},
    {"actInValveBtn_seg_2_act_2", 65536},
    {"actOutValveBtn_seg_0_act_0", 2},
    {"actOutValveBtn_seg_0_act_1", 8},
    {"actOutValveBtn_seg_0_act_2", 32},
    {"actOutValveBtn_seg_1_act_0", 128},
    {"actOutValveBtn_seg_1_act_1", 512},
    {"actOutValveBtn_seg_1_act_2", 2048},
    {"actOutValveBtn_seg_2_act_0", 8192},
    {"actOutValveBtn_seg_2_act_1", 32768},
    {"actOutValveBtn_seg_2_act_2", 131072},
    {"gripperInValveBtn", 262144},
    {"gripperOutValveBtn", 524288},
    {"joystick3DBtn", 4},
    {"joystickBtn", 2},
    {"manualControlBtn", 1},
    {"pSinkPumpBtn", 8388608},
    {"pSinkValveBtn", 4194304},
    {"pSourcePumpBtn", 2097152},
    {"pSourceValveBtn", 1048576},
    {"radioBtn_autoControl", 32},
    {"radioBtn_feedbackControl", 8},
    {"radioBtn_pressureControl", 16}
};


#endif /* BUTTONMAPS_H_ */
