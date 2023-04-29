/*
 * File: encoder_arduino_test.c
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

/* Block signals (default storage) */
B_encoder_arduino_test_T encoder_arduino_test_B;

/* Block states (default storage) */
DW_encoder_arduino_test_T encoder_arduino_test_DW;

/* Real-time model */
static RT_MODEL_encoder_arduino_test_T encoder_arduino_test_M_;
RT_MODEL_encoder_arduino_test_T *const encoder_arduino_test_M =
  &encoder_arduino_test_M_;
real_T rt_roundd_snf(real_T u)
{
  real_T y;
  if (fabs(u) < 4.503599627370496E+15) {
    if (u >= 0.5) {
      y = floor(u + 0.5);
    } else if (u > -0.5) {
      y = u * 0.0;
    } else {
      y = ceil(u - 0.5);
    }
  } else {
    y = u;
  }

  return y;
}

/* Model step function */
void encoder_arduino_test_step(void)
{
  codertarget_arduinobase_inter_T *obj;
  real_T rtb_Integrator;
  real_T rtb_Integrator_e;
  real_T rtb_alpha;
  real_T rtb_direction1;
  real_T rtb_theta;
  real_T u0;
  int32_T rtb_MATLABSystem_0;
  uint8_T tmp;

  /* MATLABSystem: '<Root>/MATLAB System' */
  if (encoder_arduino_test_DW.obj_p.SampleTime !=
      encoder_arduino_test_P.MATLABSystem_SampleTime) {
    encoder_arduino_test_DW.obj_p.SampleTime =
      encoder_arduino_test_P.MATLABSystem_SampleTime;
  }

  /*         %% Define output properties */
  /*  Call: int enc_output(int enc) */
  rtb_MATLABSystem_0 = enc_output(0.0);

  /* Gain: '<Root>/Gain5' incorporates:
   *  MATLABSystem: '<Root>/MATLAB System'
   */
  rtb_theta = (real_T)encoder_arduino_test_P.Gain5_Gain * 3.637978807091713E-12 *
    (real_T)rtb_MATLABSystem_0;

  /* Gain: '<S3>/Minimum sampling to time constant ratio' */
  rtb_Integrator = encoder_arduino_test_P.FilteredDerivativeDiscreteorC_i *
    encoder_arduino_test_B.Probe[0];

  /* MinMax: '<S3>/MinMax' incorporates:
   *  Constant: '<S3>/Time constant'
   */
  if ((!(rtb_Integrator > encoder_arduino_test_P.FilteredDerivativeDiscreteor_hn))
      && (!rtIsNaN(encoder_arduino_test_P.FilteredDerivativeDiscreteor_hn))) {
    rtb_Integrator = encoder_arduino_test_P.FilteredDerivativeDiscreteor_hn;
  }

  /* End of MinMax: '<S3>/MinMax' */

  /* DiscreteIntegrator: '<S7>/Integrator' incorporates:
   *  Constant: '<S1>/Constant'
   */
  if (encoder_arduino_test_DW.Integrator_IC_LOADING != 0) {
    encoder_arduino_test_DW.Integrator_DSTATE = rtb_theta;
    if (encoder_arduino_test_DW.Integrator_DSTATE >=
        encoder_arduino_test_P.Integrator_UpperSat) {
      encoder_arduino_test_DW.Integrator_DSTATE =
        encoder_arduino_test_P.Integrator_UpperSat;
    } else if (encoder_arduino_test_DW.Integrator_DSTATE <=
               encoder_arduino_test_P.Integrator_LowerSat) {
      encoder_arduino_test_DW.Integrator_DSTATE =
        encoder_arduino_test_P.Integrator_LowerSat;
    }
  }

  if ((encoder_arduino_test_P.Constant_Value_e != 0.0) ||
      (encoder_arduino_test_DW.Integrator_PrevResetState != 0)) {
    encoder_arduino_test_DW.Integrator_DSTATE = rtb_theta;
    if (encoder_arduino_test_DW.Integrator_DSTATE >=
        encoder_arduino_test_P.Integrator_UpperSat) {
      encoder_arduino_test_DW.Integrator_DSTATE =
        encoder_arduino_test_P.Integrator_UpperSat;
    } else if (encoder_arduino_test_DW.Integrator_DSTATE <=
               encoder_arduino_test_P.Integrator_LowerSat) {
      encoder_arduino_test_DW.Integrator_DSTATE =
        encoder_arduino_test_P.Integrator_LowerSat;
    }
  }

  if (encoder_arduino_test_DW.Integrator_DSTATE >=
      encoder_arduino_test_P.Integrator_UpperSat) {
    encoder_arduino_test_DW.Integrator_DSTATE =
      encoder_arduino_test_P.Integrator_UpperSat;
  } else if (encoder_arduino_test_DW.Integrator_DSTATE <=
             encoder_arduino_test_P.Integrator_LowerSat) {
    encoder_arduino_test_DW.Integrator_DSTATE =
      encoder_arduino_test_P.Integrator_LowerSat;
  }

  /* Saturate: '<S7>/Saturation' incorporates:
   *  DiscreteIntegrator: '<S7>/Integrator'
   */
  if (encoder_arduino_test_DW.Integrator_DSTATE >
      encoder_arduino_test_P.Saturation_UpperSat) {
    rtb_direction1 = encoder_arduino_test_P.Saturation_UpperSat;
  } else if (encoder_arduino_test_DW.Integrator_DSTATE <
             encoder_arduino_test_P.Saturation_LowerSat) {
    rtb_direction1 = encoder_arduino_test_P.Saturation_LowerSat;
  } else {
    rtb_direction1 = encoder_arduino_test_DW.Integrator_DSTATE;
  }

  /* End of Saturate: '<S7>/Saturation' */

  /* Product: '<S1>/1//T' incorporates:
   *  Fcn: '<S3>/Avoid Divide by Zero'
   *  Sum: '<S1>/Sum1'
   */
  rtb_Integrator = 1.0 / ((real_T)(rtb_Integrator == 0.0) *
    2.2204460492503131e-16 + rtb_Integrator) * (rtb_theta - rtb_direction1);

  /* MATLABSystem: '<Root>/MATLAB System1' */
  if (encoder_arduino_test_DW.obj.SampleTime !=
      encoder_arduino_test_P.MATLABSystem1_SampleTime) {
    encoder_arduino_test_DW.obj.SampleTime =
      encoder_arduino_test_P.MATLABSystem1_SampleTime;
  }

  /*         %% Define output properties */
  /*  Call: int enc_output(int enc) */
  rtb_MATLABSystem_0 = enc_output(1.0);

  /* Gain: '<Root>/Gain1' incorporates:
   *  MATLABSystem: '<Root>/MATLAB System1'
   */
  rtb_alpha = (real_T)encoder_arduino_test_P.Gain1_Gain * 3.637978807091713E-12 *
    (real_T)rtb_MATLABSystem_0;

  /* Gain: '<S8>/Minimum sampling to time constant ratio' */
  rtb_Integrator_e = encoder_arduino_test_P.FilteredDerivativeDiscreteorC_n *
    encoder_arduino_test_B.Probe_f[0];

  /* MinMax: '<S8>/MinMax' incorporates:
   *  Constant: '<S8>/Time constant'
   */
  if ((!(rtb_Integrator_e >
         encoder_arduino_test_P.FilteredDerivativeDiscreteorC_g)) && (!rtIsNaN
       (encoder_arduino_test_P.FilteredDerivativeDiscreteorC_g))) {
    rtb_Integrator_e = encoder_arduino_test_P.FilteredDerivativeDiscreteorC_g;
  }

  /* End of MinMax: '<S8>/MinMax' */

  /* DiscreteIntegrator: '<S12>/Integrator' incorporates:
   *  Constant: '<S2>/Constant'
   */
  if (encoder_arduino_test_DW.Integrator_IC_LOADING_b != 0) {
    encoder_arduino_test_DW.Integrator_DSTATE_k = rtb_alpha;
    if (encoder_arduino_test_DW.Integrator_DSTATE_k >=
        encoder_arduino_test_P.Integrator_UpperSat_d) {
      encoder_arduino_test_DW.Integrator_DSTATE_k =
        encoder_arduino_test_P.Integrator_UpperSat_d;
    } else if (encoder_arduino_test_DW.Integrator_DSTATE_k <=
               encoder_arduino_test_P.Integrator_LowerSat_p) {
      encoder_arduino_test_DW.Integrator_DSTATE_k =
        encoder_arduino_test_P.Integrator_LowerSat_p;
    }
  }

  if ((encoder_arduino_test_P.Constant_Value_n != 0.0) ||
      (encoder_arduino_test_DW.Integrator_PrevResetState_c != 0)) {
    encoder_arduino_test_DW.Integrator_DSTATE_k = rtb_alpha;
    if (encoder_arduino_test_DW.Integrator_DSTATE_k >=
        encoder_arduino_test_P.Integrator_UpperSat_d) {
      encoder_arduino_test_DW.Integrator_DSTATE_k =
        encoder_arduino_test_P.Integrator_UpperSat_d;
    } else if (encoder_arduino_test_DW.Integrator_DSTATE_k <=
               encoder_arduino_test_P.Integrator_LowerSat_p) {
      encoder_arduino_test_DW.Integrator_DSTATE_k =
        encoder_arduino_test_P.Integrator_LowerSat_p;
    }
  }

  if (encoder_arduino_test_DW.Integrator_DSTATE_k >=
      encoder_arduino_test_P.Integrator_UpperSat_d) {
    encoder_arduino_test_DW.Integrator_DSTATE_k =
      encoder_arduino_test_P.Integrator_UpperSat_d;
  } else if (encoder_arduino_test_DW.Integrator_DSTATE_k <=
             encoder_arduino_test_P.Integrator_LowerSat_p) {
    encoder_arduino_test_DW.Integrator_DSTATE_k =
      encoder_arduino_test_P.Integrator_LowerSat_p;
  }

  /* Saturate: '<S12>/Saturation' incorporates:
   *  DiscreteIntegrator: '<S12>/Integrator'
   */
  if (encoder_arduino_test_DW.Integrator_DSTATE_k >
      encoder_arduino_test_P.Saturation_UpperSat_j) {
    rtb_direction1 = encoder_arduino_test_P.Saturation_UpperSat_j;
  } else if (encoder_arduino_test_DW.Integrator_DSTATE_k <
             encoder_arduino_test_P.Saturation_LowerSat_c) {
    rtb_direction1 = encoder_arduino_test_P.Saturation_LowerSat_c;
  } else {
    rtb_direction1 = encoder_arduino_test_DW.Integrator_DSTATE_k;
  }

  /* End of Saturate: '<S12>/Saturation' */

  /* Product: '<S2>/1//T' incorporates:
   *  Fcn: '<S8>/Avoid Divide by Zero'
   *  Sum: '<S2>/Sum1'
   */
  rtb_Integrator_e = 1.0 / ((real_T)(rtb_Integrator_e == 0.0) *
    2.2204460492503131e-16 + rtb_Integrator_e) * (rtb_alpha - rtb_direction1);

  /* Gain: '<S1>/Gain' */
  rtb_direction1 = encoder_arduino_test_P.FilteredDerivativeDiscreteorC_p *
    rtb_Integrator;

  /* Gain: '<S2>/Gain' */
  u0 = encoder_arduino_test_P.FilteredDerivativeDiscreteorC_j * rtb_Integrator_e;

  /* Saturate: '<S1>/[A,B]' */
  if (rtb_direction1 > encoder_arduino_test_P.FilteredDerivativeDiscreteorC_o) {
    rtb_direction1 = encoder_arduino_test_P.FilteredDerivativeDiscreteorC_o;
  } else if (rtb_direction1 <
             encoder_arduino_test_P.FilteredDerivativeDiscreteorCon) {
    rtb_direction1 = encoder_arduino_test_P.FilteredDerivativeDiscreteorCon;
  }

  /* End of Saturate: '<S1>/[A,B]' */

  /* Saturate: '<S2>/[A,B]' */
  if (u0 > encoder_arduino_test_P.FilteredDerivativeDiscreteorC_h) {
    u0 = encoder_arduino_test_P.FilteredDerivativeDiscreteorC_h;
  } else if (u0 < encoder_arduino_test_P.FilteredDerivativeDiscreteorC_c) {
    u0 = encoder_arduino_test_P.FilteredDerivativeDiscreteorC_c;
  }

  /* End of Saturate: '<S2>/[A,B]' */

  /* Gain: '<Root>/LQR gain ' incorporates:
   *  Constant: '<Root>/Constant'
   *  SignalConversion generated from: '<Root>/LQR gain '
   *  Sum: '<Root>/Sum1'
   */
  rtb_theta = (((rtb_theta - encoder_arduino_test_P.Constant_Value) *
                -encoder_arduino_test_P.K3[0] + -encoder_arduino_test_P.K3[1] *
                rtb_direction1) + -encoder_arduino_test_P.K3[2] * rtb_alpha) +
    -encoder_arduino_test_P.K3[3] * u0;

  /* Switch: '<Root>/direction1' incorporates:
   *  Constant: '<Root>/Constant1'
   *  Constant: '<Root>/Constant4'
   *  Gain: '<Root>/LQR gain '
   */
  if (rtb_theta > encoder_arduino_test_P.direction1_Threshold) {
    rtb_direction1 = encoder_arduino_test_P.Constant1_Value;
  } else {
    rtb_direction1 = encoder_arduino_test_P.Constant4_Value;
  }

  /* End of Switch: '<Root>/direction1' */

  /* MATLABSystem: '<Root>/Digital Output' incorporates:
   *  Logic: '<Root>/NOT'
   */
  writeDigitalPin(8, (uint8_T)!(rtb_direction1 != 0.0));

  /* MATLABSystem: '<Root>/Digital Output1' */
  rtb_direction1 = rt_roundd_snf(rtb_direction1);
  if (rtb_direction1 < 256.0) {
    if (rtb_direction1 >= 0.0) {
      tmp = (uint8_T)rtb_direction1;
    } else {
      tmp = 0U;
    }
  } else {
    tmp = MAX_uint8_T;
  }

  writeDigitalPin(7, tmp);

  /* End of MATLABSystem: '<Root>/Digital Output1' */

  /* MATLABSystem: '<Root>/PWM1' */
  obj = &encoder_arduino_test_DW.obj_l;
  obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(5UL);

  /* Abs: '<Root>/Abs' incorporates:
   *  Gain: '<Root>/LQR gain '
   */
  rtb_direction1 = fabs(rtb_theta);

  /* Saturate: '<Root>/Saturation 0-255' */
  if (rtb_direction1 > encoder_arduino_test_P.Saturation0255_UpperSat) {
    rtb_direction1 = encoder_arduino_test_P.Saturation0255_UpperSat;
  } else if (rtb_direction1 < encoder_arduino_test_P.Saturation0255_LowerSat) {
    rtb_direction1 = encoder_arduino_test_P.Saturation0255_LowerSat;
  }

  /* End of Saturate: '<Root>/Saturation 0-255' */

  /* MATLABSystem: '<Root>/PWM1' */
  if (!(rtb_direction1 < 255.0)) {
    rtb_direction1 = 255.0;
  }

  if (!(rtb_direction1 > 0.0)) {
    rtb_direction1 = 0.0;
  }

  MW_PWM_SetDutyCycle(encoder_arduino_test_DW.obj_l.PWMDriverObj.MW_PWM_HANDLE,
                      rtb_direction1);

  /* Update for DiscreteIntegrator: '<S7>/Integrator' incorporates:
   *  Constant: '<S1>/Constant'
   */
  encoder_arduino_test_DW.Integrator_IC_LOADING = 0U;
  if (encoder_arduino_test_P.Constant_Value_e == 0.0) {
    encoder_arduino_test_DW.Integrator_DSTATE +=
      encoder_arduino_test_P.Integrator_gainval * rtb_Integrator;
    if (encoder_arduino_test_DW.Integrator_DSTATE >=
        encoder_arduino_test_P.Integrator_UpperSat) {
      encoder_arduino_test_DW.Integrator_DSTATE =
        encoder_arduino_test_P.Integrator_UpperSat;
    } else if (encoder_arduino_test_DW.Integrator_DSTATE <=
               encoder_arduino_test_P.Integrator_LowerSat) {
      encoder_arduino_test_DW.Integrator_DSTATE =
        encoder_arduino_test_P.Integrator_LowerSat;
    }
  }

  if (encoder_arduino_test_P.Constant_Value_e > 0.0) {
    encoder_arduino_test_DW.Integrator_PrevResetState = 1;
  } else if (encoder_arduino_test_P.Constant_Value_e < 0.0) {
    encoder_arduino_test_DW.Integrator_PrevResetState = -1;
  } else if (encoder_arduino_test_P.Constant_Value_e == 0.0) {
    encoder_arduino_test_DW.Integrator_PrevResetState = 0;
  } else {
    encoder_arduino_test_DW.Integrator_PrevResetState = 2;
  }

  /* End of Update for DiscreteIntegrator: '<S7>/Integrator' */

  /* Update for DiscreteIntegrator: '<S12>/Integrator' incorporates:
   *  Constant: '<S2>/Constant'
   */
  encoder_arduino_test_DW.Integrator_IC_LOADING_b = 0U;
  if (encoder_arduino_test_P.Constant_Value_n == 0.0) {
    encoder_arduino_test_DW.Integrator_DSTATE_k +=
      encoder_arduino_test_P.Integrator_gainval_l * rtb_Integrator_e;
    if (encoder_arduino_test_DW.Integrator_DSTATE_k >=
        encoder_arduino_test_P.Integrator_UpperSat_d) {
      encoder_arduino_test_DW.Integrator_DSTATE_k =
        encoder_arduino_test_P.Integrator_UpperSat_d;
    } else if (encoder_arduino_test_DW.Integrator_DSTATE_k <=
               encoder_arduino_test_P.Integrator_LowerSat_p) {
      encoder_arduino_test_DW.Integrator_DSTATE_k =
        encoder_arduino_test_P.Integrator_LowerSat_p;
    }
  }

  if (encoder_arduino_test_P.Constant_Value_n > 0.0) {
    encoder_arduino_test_DW.Integrator_PrevResetState_c = 1;
  } else if (encoder_arduino_test_P.Constant_Value_n < 0.0) {
    encoder_arduino_test_DW.Integrator_PrevResetState_c = -1;
  } else if (encoder_arduino_test_P.Constant_Value_n == 0.0) {
    encoder_arduino_test_DW.Integrator_PrevResetState_c = 0;
  } else {
    encoder_arduino_test_DW.Integrator_PrevResetState_c = 2;
  }

  /* End of Update for DiscreteIntegrator: '<S12>/Integrator' */
}

/* Model initialize function */
void encoder_arduino_test_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* non-finite (run-time) assignments */
  encoder_arduino_test_P.FilteredDerivativeDiscreteorCon = rtMinusInf;
  encoder_arduino_test_P.FilteredDerivativeDiscreteorC_c = rtMinusInf;
  encoder_arduino_test_P.FilteredDerivativeDiscreteorC_o = rtInf;
  encoder_arduino_test_P.FilteredDerivativeDiscreteorC_h = rtInf;
  encoder_arduino_test_P.Integrator_UpperSat = rtInf;
  encoder_arduino_test_P.Integrator_LowerSat = rtMinusInf;
  encoder_arduino_test_P.Saturation_UpperSat = rtInf;
  encoder_arduino_test_P.Saturation_LowerSat = rtMinusInf;
  encoder_arduino_test_P.Integrator_UpperSat_d = rtInf;
  encoder_arduino_test_P.Integrator_LowerSat_p = rtMinusInf;
  encoder_arduino_test_P.Saturation_UpperSat_j = rtInf;
  encoder_arduino_test_P.Saturation_LowerSat_c = rtMinusInf;

  {
    codertarget_arduinobase_inter_T *obj;

    /* Start for MATLABSystem: '<Root>/MATLAB System' */
    /*  Constructor */
    /*  Support name-value pair arguments when constructing the object. */
    encoder_arduino_test_DW.obj_p.matlabCodegenIsDeleted = false;

    /*  Do not generate code for sprintf */
    /*  Do not generate code for sprintf */
    encoder_arduino_test_DW.obj_p.SampleTime =
      encoder_arduino_test_P.MATLABSystem_SampleTime;
    encoder_arduino_test_DW.obj_p.isInitialized = 1L;

    /*         %% Define output properties */
    /*  Call: void enc_init(int enc, int pinA, int pinB) */
    enc_init(0.0, 19.0, 18.0);
    encoder_arduino_test_DW.obj_p.isSetupComplete = true;

    /* Start for Probe: '<S3>/Probe' */
    encoder_arduino_test_B.Probe[0] = 0.001;
    encoder_arduino_test_B.Probe[1] = 0.0;

    /* Start for MATLABSystem: '<Root>/MATLAB System1' */
    /*  Constructor */
    /*  Support name-value pair arguments when constructing the object. */
    encoder_arduino_test_DW.obj.matlabCodegenIsDeleted = false;

    /*  Do not generate code for sprintf */
    /*  Do not generate code for sprintf */
    encoder_arduino_test_DW.obj.SampleTime =
      encoder_arduino_test_P.MATLABSystem1_SampleTime;
    encoder_arduino_test_DW.obj.isInitialized = 1L;

    /*         %% Define output properties */
    /*  Call: void enc_init(int enc, int pinA, int pinB) */
    enc_init(1.0, 3.0, 2.0);
    encoder_arduino_test_DW.obj.isSetupComplete = true;

    /* Start for Probe: '<S8>/Probe' */
    encoder_arduino_test_B.Probe_f[0] = 0.001;
    encoder_arduino_test_B.Probe_f[1] = 0.0;

    /* Start for MATLABSystem: '<Root>/Digital Output' */
    encoder_arduino_test_DW.obj_j.matlabCodegenIsDeleted = false;
    encoder_arduino_test_DW.obj_j.isInitialized = 1L;
    digitalIOSetup(8, 1);
    encoder_arduino_test_DW.obj_j.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/Digital Output1' */
    encoder_arduino_test_DW.obj_m.matlabCodegenIsDeleted = false;
    encoder_arduino_test_DW.obj_m.isInitialized = 1L;
    digitalIOSetup(7, 1);
    encoder_arduino_test_DW.obj_m.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/PWM1' */
    encoder_arduino_test_DW.obj_l.matlabCodegenIsDeleted = true;
    encoder_arduino_test_DW.obj_l.isInitialized = 0L;
    encoder_arduino_test_DW.obj_l.matlabCodegenIsDeleted = false;
    obj = &encoder_arduino_test_DW.obj_l;
    encoder_arduino_test_DW.obj_l.isSetupComplete = false;
    encoder_arduino_test_DW.obj_l.isInitialized = 1L;
    obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_Open(5UL, 0.0, 0.0);
    encoder_arduino_test_DW.obj_l.isSetupComplete = true;

    /* InitializeConditions for DiscreteIntegrator: '<S7>/Integrator' */
    encoder_arduino_test_DW.Integrator_IC_LOADING = 1U;

    /* InitializeConditions for DiscreteIntegrator: '<S12>/Integrator' */
    encoder_arduino_test_DW.Integrator_IC_LOADING_b = 1U;
  }
}

/* Model terminate function */
void encoder_arduino_test_terminate(void)
{
  codertarget_arduinobase_inter_T *obj;

  /* Terminate for MATLABSystem: '<Root>/MATLAB System' */
  if (!encoder_arduino_test_DW.obj_p.matlabCodegenIsDeleted) {
    encoder_arduino_test_DW.obj_p.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/MATLAB System' */

  /* Terminate for MATLABSystem: '<Root>/MATLAB System1' */
  if (!encoder_arduino_test_DW.obj.matlabCodegenIsDeleted) {
    encoder_arduino_test_DW.obj.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/MATLAB System1' */

  /* Terminate for MATLABSystem: '<Root>/Digital Output' */
  if (!encoder_arduino_test_DW.obj_j.matlabCodegenIsDeleted) {
    encoder_arduino_test_DW.obj_j.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Output' */

  /* Terminate for MATLABSystem: '<Root>/Digital Output1' */
  if (!encoder_arduino_test_DW.obj_m.matlabCodegenIsDeleted) {
    encoder_arduino_test_DW.obj_m.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Output1' */

  /* Terminate for MATLABSystem: '<Root>/PWM1' */
  obj = &encoder_arduino_test_DW.obj_l;
  if (!encoder_arduino_test_DW.obj_l.matlabCodegenIsDeleted) {
    encoder_arduino_test_DW.obj_l.matlabCodegenIsDeleted = true;
    if ((encoder_arduino_test_DW.obj_l.isInitialized == 1L) &&
        encoder_arduino_test_DW.obj_l.isSetupComplete) {
      obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(5UL);
      MW_PWM_SetDutyCycle
        (encoder_arduino_test_DW.obj_l.PWMDriverObj.MW_PWM_HANDLE, 0.0);
      obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(5UL);
      MW_PWM_Close(encoder_arduino_test_DW.obj_l.PWMDriverObj.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/PWM1' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
