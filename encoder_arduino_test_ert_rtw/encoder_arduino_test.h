/*
 * File: encoder_arduino_test.h
 *
 * Code generated for Simulink model 'encoder_arduino_test'.
 *
 * Model version                  : 13.1
 * Simulink Coder version         : 9.5 (R2021a) 14-Nov-2020
 * C/C++ source code generated on : Tue Jan  3 13:45:23 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_encoder_arduino_test_h_
#define RTW_HEADER_encoder_arduino_test_h_
#include <math.h>
#include <stddef.h>
#ifndef encoder_arduino_test_COMMON_INCLUDES_
#define encoder_arduino_test_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "MW_arduino_digitalio.h"
#include "encoder_arduino.h"
#include "MW_PWM.h"
#endif                               /* encoder_arduino_test_COMMON_INCLUDES_ */

#include "encoder_arduino_test_types.h"
#include "MW_target_hardware_resources.h"
#include "rt_nonfinite.h"
#include "rtGetInf.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

/* Block signals (default storage) */
typedef struct {
  real_T Probe[2];                     /* '<S3>/Probe' */
  real_T Probe_f[2];                   /* '<S8>/Probe' */
} B_encoder_arduino_test_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  Encoder_arduino_encoder_ardui_T obj; /* '<Root>/MATLAB System1' */
  Encoder_arduino_encoder_ardui_T obj_p;/* '<Root>/MATLAB System' */
  codertarget_arduinobase_block_T obj_m;/* '<Root>/Digital Output1' */
  codertarget_arduinobase_block_T obj_j;/* '<Root>/Digital Output' */
  codertarget_arduinobase_inter_T obj_l;/* '<Root>/PWM1' */
  real_T Integrator_DSTATE;            /* '<S7>/Integrator' */
  real_T Integrator_DSTATE_k;          /* '<S12>/Integrator' */
  int8_T Integrator_PrevResetState;    /* '<S7>/Integrator' */
  int8_T Integrator_PrevResetState_c;  /* '<S12>/Integrator' */
  uint8_T Integrator_IC_LOADING;       /* '<S7>/Integrator' */
  uint8_T Integrator_IC_LOADING_b;     /* '<S12>/Integrator' */
} DW_encoder_arduino_test_T;

/* Parameters (default storage) */
struct P_encoder_arduino_test_T_ {
  real_T K3[4];                        /* Variable: K3
                                        * Referenced by: '<Root>/LQR gain '
                                        */
  real_T FilteredDerivativeDiscreteorCon;
                              /* Mask Parameter: FilteredDerivativeDiscreteorCon
                               * Referenced by: '<S1>/[A,B]'
                               */
  real_T FilteredDerivativeDiscreteorC_c;
                              /* Mask Parameter: FilteredDerivativeDiscreteorC_c
                               * Referenced by: '<S2>/[A,B]'
                               */
  real_T FilteredDerivativeDiscreteorC_o;
                              /* Mask Parameter: FilteredDerivativeDiscreteorC_o
                               * Referenced by: '<S1>/[A,B]'
                               */
  real_T FilteredDerivativeDiscreteorC_h;
                              /* Mask Parameter: FilteredDerivativeDiscreteorC_h
                               * Referenced by: '<S2>/[A,B]'
                               */
  real_T FilteredDerivativeDiscreteorC_p;
                              /* Mask Parameter: FilteredDerivativeDiscreteorC_p
                               * Referenced by: '<S1>/Gain'
                               */
  real_T FilteredDerivativeDiscreteorC_j;
                              /* Mask Parameter: FilteredDerivativeDiscreteorC_j
                               * Referenced by: '<S2>/Gain'
                               */
  real_T FilteredDerivativeDiscreteor_hn;
                              /* Mask Parameter: FilteredDerivativeDiscreteor_hn
                               * Referenced by: '<S3>/Time constant'
                               */
  real_T FilteredDerivativeDiscreteorC_g;
                              /* Mask Parameter: FilteredDerivativeDiscreteorC_g
                               * Referenced by: '<S8>/Time constant'
                               */
  real_T FilteredDerivativeDiscreteorC_i;
                              /* Mask Parameter: FilteredDerivativeDiscreteorC_i
                               * Referenced by: '<S3>/Minimum sampling to time constant ratio'
                               */
  real_T FilteredDerivativeDiscreteorC_n;
                              /* Mask Parameter: FilteredDerivativeDiscreteorC_n
                               * Referenced by: '<S8>/Minimum sampling to time constant ratio'
                               */
  real_T MATLABSystem_SampleTime;      /* Expression: 0.001
                                        * Referenced by: '<Root>/MATLAB System'
                                        */
  real_T MATLABSystem1_SampleTime;     /* Expression: 0.001
                                        * Referenced by: '<Root>/MATLAB System1'
                                        */
  real_T Constant1_Value;              /* Expression: 0
                                        * Referenced by: '<Root>/Constant1'
                                        */
  real_T Constant4_Value;              /* Expression: 1
                                        * Referenced by: '<Root>/Constant4'
                                        */
  real_T Constant_Value;               /* Expression: 0
                                        * Referenced by: '<Root>/Constant'
                                        */
  real_T Constant_Value_e;             /* Expression: 0
                                        * Referenced by: '<S1>/Constant'
                                        */
  real_T Integrator_gainval;           /* Computed Parameter: Integrator_gainval
                                        * Referenced by: '<S7>/Integrator'
                                        */
  real_T Integrator_UpperSat;          /* Expression: antiwindupUpperLimit
                                        * Referenced by: '<S7>/Integrator'
                                        */
  real_T Integrator_LowerSat;          /* Expression: antiwindupLowerLimit
                                        * Referenced by: '<S7>/Integrator'
                                        */
  real_T Saturation_UpperSat;          /* Expression: windupUpperLimit
                                        * Referenced by: '<S7>/Saturation'
                                        */
  real_T Saturation_LowerSat;          /* Expression: windupLowerLimit
                                        * Referenced by: '<S7>/Saturation'
                                        */
  real_T Constant_Value_n;             /* Expression: 0
                                        * Referenced by: '<S2>/Constant'
                                        */
  real_T Integrator_gainval_l;       /* Computed Parameter: Integrator_gainval_l
                                      * Referenced by: '<S12>/Integrator'
                                      */
  real_T Integrator_UpperSat_d;        /* Expression: antiwindupUpperLimit
                                        * Referenced by: '<S12>/Integrator'
                                        */
  real_T Integrator_LowerSat_p;        /* Expression: antiwindupLowerLimit
                                        * Referenced by: '<S12>/Integrator'
                                        */
  real_T Saturation_UpperSat_j;        /* Expression: windupUpperLimit
                                        * Referenced by: '<S12>/Saturation'
                                        */
  real_T Saturation_LowerSat_c;        /* Expression: windupLowerLimit
                                        * Referenced by: '<S12>/Saturation'
                                        */
  real_T direction1_Threshold;         /* Expression: 0
                                        * Referenced by: '<Root>/direction1'
                                        */
  real_T Saturation0255_UpperSat;      /* Expression: 255
                                        * Referenced by: '<Root>/Saturation 0-255'
                                        */
  real_T Saturation0255_LowerSat;      /* Expression: 80
                                        * Referenced by: '<Root>/Saturation 0-255'
                                        */
  int32_T Gain5_Gain;                  /* Computed Parameter: Gain5_Gain
                                        * Referenced by: '<Root>/Gain5'
                                        */
  int32_T Gain1_Gain;                  /* Computed Parameter: Gain1_Gain
                                        * Referenced by: '<Root>/Gain1'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_encoder_arduino_test_T {
  const char_T *errorStatus;
};

/* Block parameters (default storage) */
extern P_encoder_arduino_test_T encoder_arduino_test_P;

/* Block signals (default storage) */
extern B_encoder_arduino_test_T encoder_arduino_test_B;

/* Block states (default storage) */
extern DW_encoder_arduino_test_T encoder_arduino_test_DW;

/* Model entry point functions */
extern void encoder_arduino_test_initialize(void);
extern void encoder_arduino_test_step(void);
extern void encoder_arduino_test_terminate(void);

/* Real-time Model object */
extern RT_MODEL_encoder_arduino_test_T *const encoder_arduino_test_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<Root>/Scope' : Unused code path elimination
 * Block '<Root>/Scope1' : Unused code path elimination
 * Block '<Root>/alpha' : Unused code path elimination
 * Block '<Root>/arduino' : Unused code path elimination
 * Block '<Root>/control action ' : Unused code path elimination
 * Block '<Root>/theta' : Unused code path elimination
 */

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'encoder_arduino_test'
 * '<S1>'   : 'encoder_arduino_test/Filtered Derivative (Discrete or Continuous)'
 * '<S2>'   : 'encoder_arduino_test/Filtered Derivative (Discrete or Continuous)1'
 * '<S3>'   : 'encoder_arduino_test/Filtered Derivative (Discrete or Continuous)/Enable//disable time constant'
 * '<S4>'   : 'encoder_arduino_test/Filtered Derivative (Discrete or Continuous)/Initialization'
 * '<S5>'   : 'encoder_arduino_test/Filtered Derivative (Discrete or Continuous)/Integrator (Discrete or Continuous)'
 * '<S6>'   : 'encoder_arduino_test/Filtered Derivative (Discrete or Continuous)/Initialization/Init_u'
 * '<S7>'   : 'encoder_arduino_test/Filtered Derivative (Discrete or Continuous)/Integrator (Discrete or Continuous)/Discrete'
 * '<S8>'   : 'encoder_arduino_test/Filtered Derivative (Discrete or Continuous)1/Enable//disable time constant'
 * '<S9>'   : 'encoder_arduino_test/Filtered Derivative (Discrete or Continuous)1/Initialization'
 * '<S10>'  : 'encoder_arduino_test/Filtered Derivative (Discrete or Continuous)1/Integrator (Discrete or Continuous)'
 * '<S11>'  : 'encoder_arduino_test/Filtered Derivative (Discrete or Continuous)1/Initialization/Init_u'
 * '<S12>'  : 'encoder_arduino_test/Filtered Derivative (Discrete or Continuous)1/Integrator (Discrete or Continuous)/Discrete'
 */
#endif                                 /* RTW_HEADER_encoder_arduino_test_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
