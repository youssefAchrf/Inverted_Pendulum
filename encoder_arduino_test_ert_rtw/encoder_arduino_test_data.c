/*
 * File: encoder_arduino_test_data.c
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

#include "encoder_arduino_test.h"
#include "encoder_arduino_test_private.h"

/* Block parameters (default storage) */
P_encoder_arduino_test_T encoder_arduino_test_P = {
  /* Variable: K3
   * Referenced by: '<Root>/LQR gain '
   */
  { 3.1622776601683436, 36.6444904020695, 540.90843370553159, 68.551018010033317
  },

  /* Mask Parameter: FilteredDerivativeDiscreteorCon
   * Referenced by: '<S1>/[A,B]'
   */
  0.0,

  /* Mask Parameter: FilteredDerivativeDiscreteorC_c
   * Referenced by: '<S2>/[A,B]'
   */
  0.0,

  /* Mask Parameter: FilteredDerivativeDiscreteorC_o
   * Referenced by: '<S1>/[A,B]'
   */
  0.0,

  /* Mask Parameter: FilteredDerivativeDiscreteorC_h
   * Referenced by: '<S2>/[A,B]'
   */
  0.0,

  /* Mask Parameter: FilteredDerivativeDiscreteorC_p
   * Referenced by: '<S1>/Gain'
   */
  1.0,

  /* Mask Parameter: FilteredDerivativeDiscreteorC_j
   * Referenced by: '<S2>/Gain'
   */
  1.0,

  /* Mask Parameter: FilteredDerivativeDiscreteor_hn
   * Referenced by: '<S3>/Time constant'
   */
  0.001,

  /* Mask Parameter: FilteredDerivativeDiscreteorC_g
   * Referenced by: '<S8>/Time constant'
   */
  0.001,

  /* Mask Parameter: FilteredDerivativeDiscreteorC_i
   * Referenced by: '<S3>/Minimum sampling to time constant ratio'
   */
  10.0,

  /* Mask Parameter: FilteredDerivativeDiscreteorC_n
   * Referenced by: '<S8>/Minimum sampling to time constant ratio'
   */
  10.0,

  /* Expression: 0.001
   * Referenced by: '<Root>/MATLAB System'
   */
  0.001,

  /* Expression: 0.001
   * Referenced by: '<Root>/MATLAB System1'
   */
  0.001,

  /* Expression: 0
   * Referenced by: '<Root>/Constant1'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<Root>/Constant4'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<Root>/Constant'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S1>/Constant'
   */
  0.0,

  /* Computed Parameter: Integrator_gainval
   * Referenced by: '<S7>/Integrator'
   */
  0.001,

  /* Expression: antiwindupUpperLimit
   * Referenced by: '<S7>/Integrator'
   */
  0.0,

  /* Expression: antiwindupLowerLimit
   * Referenced by: '<S7>/Integrator'
   */
  0.0,

  /* Expression: windupUpperLimit
   * Referenced by: '<S7>/Saturation'
   */
  0.0,

  /* Expression: windupLowerLimit
   * Referenced by: '<S7>/Saturation'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S2>/Constant'
   */
  0.0,

  /* Computed Parameter: Integrator_gainval_l
   * Referenced by: '<S12>/Integrator'
   */
  0.001,

  /* Expression: antiwindupUpperLimit
   * Referenced by: '<S12>/Integrator'
   */
  0.0,

  /* Expression: antiwindupLowerLimit
   * Referenced by: '<S12>/Integrator'
   */
  0.0,

  /* Expression: windupUpperLimit
   * Referenced by: '<S12>/Saturation'
   */
  0.0,

  /* Expression: windupLowerLimit
   * Referenced by: '<S12>/Saturation'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<Root>/direction1'
   */
  0.0,

  /* Expression: 255
   * Referenced by: '<Root>/Saturation 0-255'
   */
  255.0,

  /* Expression: 80
   * Referenced by: '<Root>/Saturation 0-255'
   */
  80.0,

  /* Computed Parameter: Gain5_Gain
   * Referenced by: '<Root>/Gain5'
   */
  1100069316,

  /* Computed Parameter: Gain1_Gain
   * Referenced by: '<Root>/Gain1'
   */
  1199381129
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
