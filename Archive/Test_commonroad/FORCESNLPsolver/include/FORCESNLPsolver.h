#ifndef FORCESNLPsolver_H
#define FORCESNLPsolver_H
/* Generated by FORCESPRO v5.1.0 on Tuesday, December 14, 2021 at 10:20:35 PM */

#ifndef SOLVER_STDIO_H
#define SOLVER_STDIO_H
#include <stdio.h>
#include <stddef.h>
#endif


/* DATA TYPE ------------------------------------------------------------*/
typedef double FORCESNLPsolver_float;
typedef double FORCESNLPsolver_callback_float;
typedef double FORCESNLPsolverinterface_float;
typedef int FORCESNLPsolver_int;

#ifndef SOLVER_STANDARD_TYPES
#define SOLVER_STANDARD_TYPES

typedef signed char solver_int8_signed;
typedef unsigned char solver_int8_unsigned;
typedef char solver_int8_default;
typedef signed short int solver_int16_signed;
typedef unsigned short int solver_int16_unsigned;
typedef short int solver_int16_default;
typedef signed int solver_int32_signed;
typedef unsigned int solver_int32_unsigned;
typedef int solver_int32_default;
typedef signed long long int solver_int64_signed;
typedef unsigned long long int solver_int64_unsigned;
typedef long long int solver_int64_default;

#endif

/* SOLVER SETTINGS ------------------------------------------------------*/

/* MISRA-C compliance */
#ifndef MISRA_C_FORCESNLPsolver
#define MISRA_C_FORCESNLPsolver (0)
#endif

/* restrict code */
#ifndef RESTRICT_CODE_FORCESNLPsolver
#define RESTRICT_CODE_FORCESNLPsolver (0)
#endif

/* print level */
#ifndef SET_PRINTLEVEL_FORCESNLPsolver
#define SET_PRINTLEVEL_FORCESNLPsolver    (0)
#endif

/* timing */
#ifndef SET_TIMING_FORCESNLPsolver
#define SET_TIMING_FORCESNLPsolver    (1)
#endif

/* Numeric Warnings */
/* #define PRINTNUMERICALWARNINGS */

/* maximum number of iterations  */
#define SET_MAXIT_FORCESNLPsolver			(200)	 

/* desired maximum residual on equality constraints */
#define SET_ACC_RESEQ_FORCESNLPsolver		(FORCESNLPsolver_float)(1E-06)


/* RETURN CODES----------------------------------------------------------*/
/* solver has converged within desired accuracy */
#define OPTIMAL_FORCESNLPsolver      (1)

/* maximum number of iterations has been reached */
#define MAXITREACHED_FORCESNLPsolver (0)

/* solver has stopped due to a timeout */
#define TIMEOUT_FORCESNLPsolver   (2)

/* NaN encountered in function evaluations */
#define BADFUNCEVAL_FORCESNLPsolver  (-6)

/* no progress in method possible */
#define NOPROGRESS_FORCESNLPsolver   (-7)

/* regularization error */
#define REGULARIZATION_ERROR_FORCESNLPsolver   (-9)

/* invalid values in parameters */
#define PARAM_VALUE_ERROR_FORCESNLPsolver   (-11)

/* too small timeout given */
#define INVALID_TIMEOUT_FORCESNLPsolver   (-12)

/* error in linesearch */
#define LINESEARCH_ERROR_FORCESNLPsolver   (-13)

/* thread error */
#define THREAD_FAILURE_FORCESNLPsolver  (-98)

/* locking mechanism error */
#define LOCK_FAILURE_FORCESNLPsolver  (-99)

/* licensing error - solver not valid on this machine */
#define LICENSE_ERROR_FORCESNLPsolver  (-100)

/* qp solver error */
#define QP_SOLVER_FAILURE_FORCESNLPsolver (-8)


/* INTEGRATORS RETURN CODE ------------*/
/* Integrator ran successfully */
#define INTEGRATOR_SUCCESS (11)
/* Number of steps set by user exceeds maximum number of steps allowed */
#define INTEGRATOR_MAXSTEPS_EXCEEDED (12)

/* PARAMETERS -----------------------------------------------------------*/
/* fill this with data before calling the solver! */
typedef struct
{
	    /* vector of size 5 */
    FORCESNLPsolver_float xinit[5];

    /* vector of size 70 */
    FORCESNLPsolver_float x0[70];

    /* vector of size 20 */
    FORCESNLPsolver_float all_parameters[20];

    /* scalar */
    FORCESNLPsolver_int reinitialize;


} FORCESNLPsolver_params;


/* OUTPUTS --------------------------------------------------------------*/
/* the desired variables are put here by the solver */
typedef struct
{
	    /* vector of size 7 */
    FORCESNLPsolver_float x01[7];

    /* vector of size 7 */
    FORCESNLPsolver_float x02[7];

    /* vector of size 7 */
    FORCESNLPsolver_float x03[7];

    /* vector of size 7 */
    FORCESNLPsolver_float x04[7];

    /* vector of size 7 */
    FORCESNLPsolver_float x05[7];

    /* vector of size 7 */
    FORCESNLPsolver_float x06[7];

    /* vector of size 7 */
    FORCESNLPsolver_float x07[7];

    /* vector of size 7 */
    FORCESNLPsolver_float x08[7];

    /* vector of size 7 */
    FORCESNLPsolver_float x09[7];

    /* vector of size 7 */
    FORCESNLPsolver_float x10[7];


} FORCESNLPsolver_output;


/* SOLVER INFO ----------------------------------------------------------*/
/* diagnostic data from last interior point step */
typedef struct
{
	/* iteration number */
	solver_int32_default it;

	/* inf-norm of equality constraint residuals */
	FORCESNLPsolver_float res_eq;

	/* norm of stationarity condition */
	FORCESNLPsolver_float rsnorm;

	/* primal objective */
	FORCESNLPsolver_float pobj;

	/* total solve time */
	FORCESNLPsolver_float solvetime;

	/* time spent in function evaluations */
	FORCESNLPsolver_float fevalstime;

	/* time spent solving QPs */
	FORCESNLPsolver_float QPtime;
} FORCESNLPsolver_info;



/* SOLVER FUNCTION DEFINITION -------------------------------------------*/
/* Time of Solver Generation: (UTC) Tuesday, December 14, 2021 10:20:35 PM */
/* User License expires on: (UTC) Wednesday, May 18, 2022 10:00:00 PM (approx.) (at the time of code generation) */
/* Solver Static License expires on: (UTC) Wednesday, May 18, 2022 10:00:00 PM (approx.) */
/* Solver Generation Request Id: 95378b4d-5e63-4f32-abe2-020105f552ce */
/* examine exitflag before using the result! */
#ifdef __cplusplus
extern "C" {
#endif		

typedef void(*FORCESNLPsolver_extfunc)(FORCESNLPsolver_float* x, FORCESNLPsolver_float* y, FORCESNLPsolver_float* lambda, FORCESNLPsolver_float* params, FORCESNLPsolver_float* pobj, FORCESNLPsolver_float* g, FORCESNLPsolver_float* c, FORCESNLPsolver_float* Jeq, FORCESNLPsolver_float* h, FORCESNLPsolver_float* Jineq, FORCESNLPsolver_float* H, solver_int32_default stage, solver_int32_default iterations, solver_int32_default threadID);

extern solver_int32_default FORCESNLPsolver_solve(FORCESNLPsolver_params *params, FORCESNLPsolver_output *output, FORCESNLPsolver_info *info, FILE *fs, FORCESNLPsolver_extfunc evalextfunctions_FORCESNLPsolver);







#ifdef __cplusplus
}
#endif

#endif
