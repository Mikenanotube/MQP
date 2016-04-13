/* File: advection_1D_ptwisemodule.c
 * This file is auto-generated with f2py (version:2).
 * f2py is a Fortran to Python Interface Generator (FPIG), Second Edition,
 * written by Pearu Peterson <pearu@cens.ioc.ee>.
 * See http://cens.ioc.ee/projects/f2py2e/
 * Generation date: Tue Apr 12 21:47:25 2016
 * $Revision:$
 * $Date:$
 * Do not edit this file directly unless you know what you are doing!!!
 */
#ifdef __cplusplus
extern "C" {
#endif

/*********************** See f2py2e/cfuncs.py: includes ***********************/
#include "Python.h"
#include <stdarg.h>
#include "fortranobject.h"
#include <math.h>

/**************** See f2py2e/rules.py: mod_rules['modulebody'] ****************/
static PyObject *advection_1D_ptwise_error;
static PyObject *advection_1D_ptwise_module;

/*********************** See f2py2e/cfuncs.py: typedefs ***********************/
/*need_typedefs*/

/****************** See f2py2e/cfuncs.py: typedefs_generated ******************/
/*need_typedefs_generated*/

/********************** See f2py2e/cfuncs.py: cppmacros **********************/
#if defined(PREPEND_FORTRAN)
#if defined(NO_APPEND_FORTRAN)
#if defined(UPPERCASE_FORTRAN)
#define F_FUNC(f,F) _##F
#else
#define F_FUNC(f,F) _##f
#endif
#else
#if defined(UPPERCASE_FORTRAN)
#define F_FUNC(f,F) _##F##_
#else
#define F_FUNC(f,F) _##f##_
#endif
#endif
#else
#if defined(NO_APPEND_FORTRAN)
#if defined(UPPERCASE_FORTRAN)
#define F_FUNC(f,F) F
#else
#define F_FUNC(f,F) f
#endif
#else
#if defined(UPPERCASE_FORTRAN)
#define F_FUNC(f,F) F##_
#else
#define F_FUNC(f,F) f##_
#endif
#endif
#endif
#if defined(UNDERSCORE_G77)
#define F_FUNC_US(f,F) F_FUNC(f##_,F##_)
#else
#define F_FUNC_US(f,F) F_FUNC(f,F)
#endif

#define rank(var) var ## _Rank
#define shape(var,dim) var ## _Dims[dim]
#define old_rank(var) (((PyArrayObject *)(capi_ ## var ## _tmp))->nd)
#define old_shape(var,dim) (((PyArrayObject *)(capi_ ## var ## _tmp))->dimensions[dim])
#define fshape(var,dim) shape(var,rank(var)-dim-1)
#define len(var) shape(var,0)
#define flen(var) fshape(var,0)
#define old_size(var) PyArray_SIZE((PyArrayObject *)(capi_ ## var ## _tmp))
/* #define index(i) capi_i ## i */
#define slen(var) capi_ ## var ## _len
#define size(var, ...) f2py_size((PyArrayObject *)(capi_ ## var ## _tmp), ## __VA_ARGS__, -1)

#define CHECKSCALAR(check,tcheck,name,show,var)\
  if (!(check)) {\
    char errstring[256];\
    sprintf(errstring, "%s: "show, "("tcheck") failed for "name, var);\
    PyErr_SetString(advection_1D_ptwise_error,errstring);\
    /*goto capi_fail;*/\
  } else 
#ifdef DEBUGCFUNCS
#define CFUNCSMESS(mess) fprintf(stderr,"debug-capi:"mess);
#define CFUNCSMESSPY(mess,obj) CFUNCSMESS(mess) \
  PyObject_Print((PyObject *)obj,stderr,Py_PRINT_RAW);\
  fprintf(stderr,"\n");
#else
#define CFUNCSMESS(mess)
#define CFUNCSMESSPY(mess,obj)
#endif

#ifndef max
#define max(a,b) ((a > b) ? (a) : (b))
#endif
#ifndef min
#define min(a,b) ((a < b) ? (a) : (b))
#endif
#ifndef MAX
#define MAX(a,b) ((a > b) ? (a) : (b))
#endif
#ifndef MIN
#define MIN(a,b) ((a < b) ? (a) : (b))
#endif


/************************ See f2py2e/cfuncs.py: cfuncs ************************/
static int f2py_size(PyArrayObject* var, ...)
{
  npy_int sz = 0;
  npy_int dim;
  npy_int rank;
  va_list argp;
  va_start(argp, var);
  dim = va_arg(argp, npy_int);
  if (dim==-1)
    {
      sz = PyArray_SIZE(var);
    }
  else
    {
      rank = PyArray_NDIM(var);
      if (dim>=1 && dim<=rank)
        sz = PyArray_DIM(var, dim-1);
      else
        fprintf(stderr, "f2py_size: 2nd argument value=%d fails to satisfy 1<=value<=%d. Result will be 0.\n", dim, rank);
    }
  va_end(argp);
  return sz;
}

static int int_from_pyobj(int* v,PyObject *obj,const char *errmess) {
  PyObject* tmp = NULL;
  if (PyInt_Check(obj)) {
    *v = (int)PyInt_AS_LONG(obj);
    return 1;
  }
  tmp = PyNumber_Int(obj);
  if (tmp) {
    *v = PyInt_AS_LONG(tmp);
    Py_DECREF(tmp);
    return 1;
  }
  if (PyComplex_Check(obj))
    tmp = PyObject_GetAttrString(obj,"real");
  else if (PyString_Check(obj) || PyUnicode_Check(obj))
    /*pass*/;
  else if (PySequence_Check(obj))
    tmp = PySequence_GetItem(obj,0);
  if (tmp) {
    PyErr_Clear();
    if (int_from_pyobj(v,tmp,errmess)) {Py_DECREF(tmp); return 1;}
    Py_DECREF(tmp);
  }
  {
    PyObject* err = PyErr_Occurred();
    if (err==NULL) err = advection_1D_ptwise_error;
    PyErr_SetString(err,errmess);
  }
  return 0;
}


/********************* See f2py2e/cfuncs.py: userincludes *********************/
/*need_userincludes*/

/********************* See f2py2e/capi_rules.py: usercode *********************/


/* See f2py2e/rules.py */
extern void F_FUNC(rp1,RP1)(int*,int*,int*,int*,int*,int*,double*,double*,double*,double*,double*,double*,double*,double*);
extern void F_FUNC_US(rp1_ptwise,RP1_PTWISE)(int*,int*,int*,double*,double*,double*,double*,double*,double*,double*,double*);
/*eof externroutines*/

/******************** See f2py2e/capi_rules.py: usercode1 ********************/


/******************* See f2py2e/cb_rules.py: buildcallback *******************/
/*need_callbacks*/

/*********************** See f2py2e/rules.py: buildapi ***********************/

/************************************ rp1 ************************************/
static char doc_f2py_rout_advection_1D_ptwise_rp1[] = "\
rp1(maxm,maux,mbc,mx,ql,qr,auxl,auxr,wave,s,amdq,apdq,[meqn,mwaves])\n\nWrapper for ``rp1``.\
\n\nParameters\n----------\n"
"maxm : input int\n"
"maux : input int\n"
"mbc : input int\n"
"mx : input int\n"
"ql : input rank-2 array('d') with bounds (meqn,maxm+mbc-(1-mbc)+1)\n"
"qr : input rank-2 array('d') with bounds (meqn,maxm+mbc-(1-mbc)+1)\n"
"auxl : input rank-2 array('d') with bounds (meqn,maxm+mbc-(1-mbc)+1)\n"
"auxr : input rank-2 array('d') with bounds (meqn,maxm+mbc-(1-mbc)+1)\n"
"wave : input rank-3 array('d') with bounds (meqn,mwaves,maxm+mbc-(1-mbc)+1)\n"
"s : input rank-2 array('d') with bounds (mwaves,maxm+mbc-(1-mbc)+1)\n"
"amdq : input rank-2 array('d') with bounds (meqn,maxm+mbc-(1-mbc)+1)\n"
"apdq : input rank-2 array('d') with bounds (meqn,maxm+mbc-(1-mbc)+1)\n"
"\nOther Parameters\n----------------\n"
"meqn : input int, optional\n    Default: shape(ql,0)\n"
"mwaves : input int, optional\n    Default: shape(wave,1)";
/* extern void F_FUNC(rp1,RP1)(int*,int*,int*,int*,int*,int*,double*,double*,double*,double*,double*,double*,double*,double*); */
static PyObject *f2py_rout_advection_1D_ptwise_rp1(const PyObject *capi_self,
                           PyObject *capi_args,
                           PyObject *capi_keywds,
                           void (*f2py_func)(int*,int*,int*,int*,int*,int*,double*,double*,double*,double*,double*,double*,double*,double*)) {
  PyObject * volatile capi_buildvalue = NULL;
  volatile int f2py_success = 1;
/*decl*/

  int maxm = 0;
  PyObject *maxm_capi = Py_None;
  int meqn = 0;
  PyObject *meqn_capi = Py_None;
  int mwaves = 0;
  PyObject *mwaves_capi = Py_None;
  int maux = 0;
  PyObject *maux_capi = Py_None;
  int mbc = 0;
  PyObject *mbc_capi = Py_None;
  int mx = 0;
  PyObject *mx_capi = Py_None;
  double *ql = NULL;
  npy_intp ql_Dims[2] = {-1, -1};
  const int ql_Rank = 2;
  PyArrayObject *capi_ql_tmp = NULL;
  int capi_ql_intent = 0;
  PyObject *ql_capi = Py_None;
  double *qr = NULL;
  npy_intp qr_Dims[2] = {-1, -1};
  const int qr_Rank = 2;
  PyArrayObject *capi_qr_tmp = NULL;
  int capi_qr_intent = 0;
  PyObject *qr_capi = Py_None;
  double *auxl = NULL;
  npy_intp auxl_Dims[2] = {-1, -1};
  const int auxl_Rank = 2;
  PyArrayObject *capi_auxl_tmp = NULL;
  int capi_auxl_intent = 0;
  PyObject *auxl_capi = Py_None;
  double *auxr = NULL;
  npy_intp auxr_Dims[2] = {-1, -1};
  const int auxr_Rank = 2;
  PyArrayObject *capi_auxr_tmp = NULL;
  int capi_auxr_intent = 0;
  PyObject *auxr_capi = Py_None;
  double *wave = NULL;
  npy_intp wave_Dims[3] = {-1, -1, -1};
  const int wave_Rank = 3;
  PyArrayObject *capi_wave_tmp = NULL;
  int capi_wave_intent = 0;
  PyObject *wave_capi = Py_None;
  double *s = NULL;
  npy_intp s_Dims[2] = {-1, -1};
  const int s_Rank = 2;
  PyArrayObject *capi_s_tmp = NULL;
  int capi_s_intent = 0;
  PyObject *s_capi = Py_None;
  double *amdq = NULL;
  npy_intp amdq_Dims[2] = {-1, -1};
  const int amdq_Rank = 2;
  PyArrayObject *capi_amdq_tmp = NULL;
  int capi_amdq_intent = 0;
  PyObject *amdq_capi = Py_None;
  double *apdq = NULL;
  npy_intp apdq_Dims[2] = {-1, -1};
  const int apdq_Rank = 2;
  PyArrayObject *capi_apdq_tmp = NULL;
  int capi_apdq_intent = 0;
  PyObject *apdq_capi = Py_None;
  static char *capi_kwlist[] = {"maxm","maux","mbc","mx","ql","qr","auxl","auxr","wave","s","amdq","apdq","meqn","mwaves",NULL};

/*routdebugenter*/
#ifdef F2PY_REPORT_ATEXIT
f2py_start_clock();
#endif
  if (!PyArg_ParseTupleAndKeywords(capi_args,capi_keywds,\
    "OOOOOOOOOOOO|OO:advection_1D_ptwise.rp1",\
    capi_kwlist,&maxm_capi,&maux_capi,&mbc_capi,&mx_capi,&ql_capi,&qr_capi,&auxl_capi,&auxr_capi,&wave_capi,&s_capi,&amdq_capi,&apdq_capi,&meqn_capi,&mwaves_capi))
    return NULL;
/*frompyobj*/
  /* Processing variable maux */
    f2py_success = int_from_pyobj(&maux,maux_capi,"advection_1D_ptwise.rp1() 2nd argument (maux) can't be converted to int");
  if (f2py_success) {
  /* Processing variable mx */
    f2py_success = int_from_pyobj(&mx,mx_capi,"advection_1D_ptwise.rp1() 4th argument (mx) can't be converted to int");
  if (f2py_success) {
  /* Processing variable maxm */
    f2py_success = int_from_pyobj(&maxm,maxm_capi,"advection_1D_ptwise.rp1() 1st argument (maxm) can't be converted to int");
  if (f2py_success) {
  /* Processing variable mbc */
    f2py_success = int_from_pyobj(&mbc,mbc_capi,"advection_1D_ptwise.rp1() 3rd argument (mbc) can't be converted to int");
  if (f2py_success) {
  /* Processing variable ql */
  ql_Dims[1]=maxm+mbc-(1-mbc)+1;
  capi_ql_intent |= F2PY_INTENT_IN;
  capi_ql_tmp = array_from_pyobj(NPY_DOUBLE,ql_Dims,ql_Rank,capi_ql_intent,ql_capi);
  if (capi_ql_tmp == NULL) {
    if (!PyErr_Occurred())
      PyErr_SetString(advection_1D_ptwise_error,"failed in converting 5th argument `ql' of advection_1D_ptwise.rp1 to C/Fortran array" );
  } else {
    ql = (double *)(capi_ql_tmp->data);

  /* Processing variable meqn */
  if (meqn_capi == Py_None) meqn = shape(ql,0); else
    f2py_success = int_from_pyobj(&meqn,meqn_capi,"advection_1D_ptwise.rp1() 1st keyword (meqn) can't be converted to int");
  if (f2py_success) {
  CHECKSCALAR(shape(ql,0)==meqn,"shape(ql,0)==meqn","1st keyword meqn","rp1:meqn=%d",meqn) {
  /* Processing variable amdq */
  amdq_Dims[0]=meqn,amdq_Dims[1]=maxm+mbc-(1-mbc)+1;
  capi_amdq_intent |= F2PY_INTENT_IN;
  capi_amdq_tmp = array_from_pyobj(NPY_DOUBLE,amdq_Dims,amdq_Rank,capi_amdq_intent,amdq_capi);
  if (capi_amdq_tmp == NULL) {
    if (!PyErr_Occurred())
      PyErr_SetString(advection_1D_ptwise_error,"failed in converting 11st argument `amdq' of advection_1D_ptwise.rp1 to C/Fortran array" );
  } else {
    amdq = (double *)(capi_amdq_tmp->data);

  /* Processing variable apdq */
  apdq_Dims[0]=meqn,apdq_Dims[1]=maxm+mbc-(1-mbc)+1;
  capi_apdq_intent |= F2PY_INTENT_IN;
  capi_apdq_tmp = array_from_pyobj(NPY_DOUBLE,apdq_Dims,apdq_Rank,capi_apdq_intent,apdq_capi);
  if (capi_apdq_tmp == NULL) {
    if (!PyErr_Occurred())
      PyErr_SetString(advection_1D_ptwise_error,"failed in converting 12nd argument `apdq' of advection_1D_ptwise.rp1 to C/Fortran array" );
  } else {
    apdq = (double *)(capi_apdq_tmp->data);

  /* Processing variable qr */
  qr_Dims[0]=meqn,qr_Dims[1]=maxm+mbc-(1-mbc)+1;
  capi_qr_intent |= F2PY_INTENT_IN;
  capi_qr_tmp = array_from_pyobj(NPY_DOUBLE,qr_Dims,qr_Rank,capi_qr_intent,qr_capi);
  if (capi_qr_tmp == NULL) {
    if (!PyErr_Occurred())
      PyErr_SetString(advection_1D_ptwise_error,"failed in converting 6th argument `qr' of advection_1D_ptwise.rp1 to C/Fortran array" );
  } else {
    qr = (double *)(capi_qr_tmp->data);

  /* Processing variable auxl */
  auxl_Dims[0]=meqn,auxl_Dims[1]=maxm+mbc-(1-mbc)+1;
  capi_auxl_intent |= F2PY_INTENT_IN;
  capi_auxl_tmp = array_from_pyobj(NPY_DOUBLE,auxl_Dims,auxl_Rank,capi_auxl_intent,auxl_capi);
  if (capi_auxl_tmp == NULL) {
    if (!PyErr_Occurred())
      PyErr_SetString(advection_1D_ptwise_error,"failed in converting 7th argument `auxl' of advection_1D_ptwise.rp1 to C/Fortran array" );
  } else {
    auxl = (double *)(capi_auxl_tmp->data);

  /* Processing variable wave */
  wave_Dims[0]=meqn,wave_Dims[2]=maxm+mbc-(1-mbc)+1;
  capi_wave_intent |= F2PY_INTENT_IN;
  capi_wave_tmp = array_from_pyobj(NPY_DOUBLE,wave_Dims,wave_Rank,capi_wave_intent,wave_capi);
  if (capi_wave_tmp == NULL) {
    if (!PyErr_Occurred())
      PyErr_SetString(advection_1D_ptwise_error,"failed in converting 9th argument `wave' of advection_1D_ptwise.rp1 to C/Fortran array" );
  } else {
    wave = (double *)(capi_wave_tmp->data);

  /* Processing variable auxr */
  auxr_Dims[0]=meqn,auxr_Dims[1]=maxm+mbc-(1-mbc)+1;
  capi_auxr_intent |= F2PY_INTENT_IN;
  capi_auxr_tmp = array_from_pyobj(NPY_DOUBLE,auxr_Dims,auxr_Rank,capi_auxr_intent,auxr_capi);
  if (capi_auxr_tmp == NULL) {
    if (!PyErr_Occurred())
      PyErr_SetString(advection_1D_ptwise_error,"failed in converting 8th argument `auxr' of advection_1D_ptwise.rp1 to C/Fortran array" );
  } else {
    auxr = (double *)(capi_auxr_tmp->data);

  /* Processing variable mwaves */
  if (mwaves_capi == Py_None) mwaves = shape(wave,1); else
    f2py_success = int_from_pyobj(&mwaves,mwaves_capi,"advection_1D_ptwise.rp1() 2nd keyword (mwaves) can't be converted to int");
  if (f2py_success) {
  CHECKSCALAR(shape(wave,1)==mwaves,"shape(wave,1)==mwaves","2nd keyword mwaves","rp1:mwaves=%d",mwaves) {
  /* Processing variable s */
  s_Dims[0]=mwaves,s_Dims[1]=maxm+mbc-(1-mbc)+1;
  capi_s_intent |= F2PY_INTENT_IN;
  capi_s_tmp = array_from_pyobj(NPY_DOUBLE,s_Dims,s_Rank,capi_s_intent,s_capi);
  if (capi_s_tmp == NULL) {
    if (!PyErr_Occurred())
      PyErr_SetString(advection_1D_ptwise_error,"failed in converting 10th argument `s' of advection_1D_ptwise.rp1 to C/Fortran array" );
  } else {
    s = (double *)(capi_s_tmp->data);

/*end of frompyobj*/
#ifdef F2PY_REPORT_ATEXIT
f2py_start_call_clock();
#endif
/*callfortranroutine*/
        (*f2py_func)(&maxm,&meqn,&mwaves,&maux,&mbc,&mx,ql,qr,auxl,auxr,wave,s,amdq,apdq);
if (PyErr_Occurred())
  f2py_success = 0;
#ifdef F2PY_REPORT_ATEXIT
f2py_stop_call_clock();
#endif
/*end of callfortranroutine*/
    if (f2py_success) {
/*pyobjfrom*/
/*end of pyobjfrom*/
    CFUNCSMESS("Building return value.\n");
    capi_buildvalue = Py_BuildValue("");
/*closepyobjfrom*/
/*end of closepyobjfrom*/
    } /*if (f2py_success) after callfortranroutine*/
/*cleanupfrompyobj*/
  if((PyObject *)capi_s_tmp!=s_capi) {
    Py_XDECREF(capi_s_tmp); }
  }  /*if (capi_s_tmp == NULL) ... else of s*/
  /* End of cleaning variable s */
  } /*CHECKSCALAR(shape(wave,1)==mwaves)*/
  } /*if (f2py_success) of mwaves*/
  /* End of cleaning variable mwaves */
  if((PyObject *)capi_auxr_tmp!=auxr_capi) {
    Py_XDECREF(capi_auxr_tmp); }
  }  /*if (capi_auxr_tmp == NULL) ... else of auxr*/
  /* End of cleaning variable auxr */
  if((PyObject *)capi_wave_tmp!=wave_capi) {
    Py_XDECREF(capi_wave_tmp); }
  }  /*if (capi_wave_tmp == NULL) ... else of wave*/
  /* End of cleaning variable wave */
  if((PyObject *)capi_auxl_tmp!=auxl_capi) {
    Py_XDECREF(capi_auxl_tmp); }
  }  /*if (capi_auxl_tmp == NULL) ... else of auxl*/
  /* End of cleaning variable auxl */
  if((PyObject *)capi_qr_tmp!=qr_capi) {
    Py_XDECREF(capi_qr_tmp); }
  }  /*if (capi_qr_tmp == NULL) ... else of qr*/
  /* End of cleaning variable qr */
  if((PyObject *)capi_apdq_tmp!=apdq_capi) {
    Py_XDECREF(capi_apdq_tmp); }
  }  /*if (capi_apdq_tmp == NULL) ... else of apdq*/
  /* End of cleaning variable apdq */
  if((PyObject *)capi_amdq_tmp!=amdq_capi) {
    Py_XDECREF(capi_amdq_tmp); }
  }  /*if (capi_amdq_tmp == NULL) ... else of amdq*/
  /* End of cleaning variable amdq */
  } /*CHECKSCALAR(shape(ql,0)==meqn)*/
  } /*if (f2py_success) of meqn*/
  /* End of cleaning variable meqn */
  if((PyObject *)capi_ql_tmp!=ql_capi) {
    Py_XDECREF(capi_ql_tmp); }
  }  /*if (capi_ql_tmp == NULL) ... else of ql*/
  /* End of cleaning variable ql */
  } /*if (f2py_success) of mbc*/
  /* End of cleaning variable mbc */
  } /*if (f2py_success) of maxm*/
  /* End of cleaning variable maxm */
  } /*if (f2py_success) of mx*/
  /* End of cleaning variable mx */
  } /*if (f2py_success) of maux*/
  /* End of cleaning variable maux */
/*end of cleanupfrompyobj*/
  if (capi_buildvalue == NULL) {
/*routdebugfailure*/
  } else {
/*routdebugleave*/
  }
  CFUNCSMESS("Freeing memory.\n");
/*freemem*/
#ifdef F2PY_REPORT_ATEXIT
f2py_stop_clock();
#endif
  return capi_buildvalue;
}
/********************************* end of rp1 *********************************/

/********************************* rp1_ptwise *********************************/
static char doc_f2py_rout_advection_1D_ptwise_rp1_ptwise[] = "\
rp1_ptwise(q_l,q_r,aux_l,aux_r,wave,s,amdq,apdq,[num_eqn,num_aux,num_waves])\n\nWrapper for ``rp1_ptwise``.\
\n\nParameters\n----------\n"
"q_l : input rank-1 array('d') with bounds (num_eqn)\n"
"q_r : input rank-1 array('d') with bounds (num_eqn)\n"
"aux_l : input rank-1 array('d') with bounds (num_aux)\n"
"aux_r : input rank-1 array('d') with bounds (num_aux)\n"
"wave : input rank-2 array('d') with bounds (num_eqn,num_waves)\n"
"s : input rank-1 array('d') with bounds (num_waves)\n"
"amdq : input rank-1 array('d') with bounds (num_eqn)\n"
"apdq : input rank-1 array('d') with bounds (num_eqn)\n"
"\nOther Parameters\n----------------\n"
"num_eqn : input int, optional\n    Default: len(q_l)\n"
"num_aux : input int, optional\n    Default: len(aux_l)\n"
"num_waves : input int, optional\n    Default: shape(wave,1)";
/* extern void F_FUNC_US(rp1_ptwise,RP1_PTWISE)(int*,int*,int*,double*,double*,double*,double*,double*,double*,double*,double*); */
static PyObject *f2py_rout_advection_1D_ptwise_rp1_ptwise(const PyObject *capi_self,
                           PyObject *capi_args,
                           PyObject *capi_keywds,
                           void (*f2py_func)(int*,int*,int*,double*,double*,double*,double*,double*,double*,double*,double*)) {
  PyObject * volatile capi_buildvalue = NULL;
  volatile int f2py_success = 1;
/*decl*/

  int num_eqn = 0;
  PyObject *num_eqn_capi = Py_None;
  int num_aux = 0;
  PyObject *num_aux_capi = Py_None;
  int num_waves = 0;
  PyObject *num_waves_capi = Py_None;
  double *q_l = NULL;
  npy_intp q_l_Dims[1] = {-1};
  const int q_l_Rank = 1;
  PyArrayObject *capi_q_l_tmp = NULL;
  int capi_q_l_intent = 0;
  PyObject *q_l_capi = Py_None;
  double *q_r = NULL;
  npy_intp q_r_Dims[1] = {-1};
  const int q_r_Rank = 1;
  PyArrayObject *capi_q_r_tmp = NULL;
  int capi_q_r_intent = 0;
  PyObject *q_r_capi = Py_None;
  double *aux_l = NULL;
  npy_intp aux_l_Dims[1] = {-1};
  const int aux_l_Rank = 1;
  PyArrayObject *capi_aux_l_tmp = NULL;
  int capi_aux_l_intent = 0;
  PyObject *aux_l_capi = Py_None;
  double *aux_r = NULL;
  npy_intp aux_r_Dims[1] = {-1};
  const int aux_r_Rank = 1;
  PyArrayObject *capi_aux_r_tmp = NULL;
  int capi_aux_r_intent = 0;
  PyObject *aux_r_capi = Py_None;
  double *wave = NULL;
  npy_intp wave_Dims[2] = {-1, -1};
  const int wave_Rank = 2;
  PyArrayObject *capi_wave_tmp = NULL;
  int capi_wave_intent = 0;
  PyObject *wave_capi = Py_None;
  double *s = NULL;
  npy_intp s_Dims[1] = {-1};
  const int s_Rank = 1;
  PyArrayObject *capi_s_tmp = NULL;
  int capi_s_intent = 0;
  PyObject *s_capi = Py_None;
  double *amdq = NULL;
  npy_intp amdq_Dims[1] = {-1};
  const int amdq_Rank = 1;
  PyArrayObject *capi_amdq_tmp = NULL;
  int capi_amdq_intent = 0;
  PyObject *amdq_capi = Py_None;
  double *apdq = NULL;
  npy_intp apdq_Dims[1] = {-1};
  const int apdq_Rank = 1;
  PyArrayObject *capi_apdq_tmp = NULL;
  int capi_apdq_intent = 0;
  PyObject *apdq_capi = Py_None;
  static char *capi_kwlist[] = {"q_l","q_r","aux_l","aux_r","wave","s","amdq","apdq","num_eqn","num_aux","num_waves",NULL};

/*routdebugenter*/
#ifdef F2PY_REPORT_ATEXIT
f2py_start_clock();
#endif
  if (!PyArg_ParseTupleAndKeywords(capi_args,capi_keywds,\
    "OOOOOOOO|OOO:advection_1D_ptwise.rp1_ptwise",\
    capi_kwlist,&q_l_capi,&q_r_capi,&aux_l_capi,&aux_r_capi,&wave_capi,&s_capi,&amdq_capi,&apdq_capi,&num_eqn_capi,&num_aux_capi,&num_waves_capi))
    return NULL;
/*frompyobj*/
  /* Processing variable q_l */
  ;
  capi_q_l_intent |= F2PY_INTENT_IN;
  capi_q_l_tmp = array_from_pyobj(NPY_DOUBLE,q_l_Dims,q_l_Rank,capi_q_l_intent,q_l_capi);
  if (capi_q_l_tmp == NULL) {
    if (!PyErr_Occurred())
      PyErr_SetString(advection_1D_ptwise_error,"failed in converting 1st argument `q_l' of advection_1D_ptwise.rp1_ptwise to C/Fortran array" );
  } else {
    q_l = (double *)(capi_q_l_tmp->data);

  /* Processing variable aux_l */
  ;
  capi_aux_l_intent |= F2PY_INTENT_IN;
  capi_aux_l_tmp = array_from_pyobj(NPY_DOUBLE,aux_l_Dims,aux_l_Rank,capi_aux_l_intent,aux_l_capi);
  if (capi_aux_l_tmp == NULL) {
    if (!PyErr_Occurred())
      PyErr_SetString(advection_1D_ptwise_error,"failed in converting 3rd argument `aux_l' of advection_1D_ptwise.rp1_ptwise to C/Fortran array" );
  } else {
    aux_l = (double *)(capi_aux_l_tmp->data);

  /* Processing variable num_aux */
  if (num_aux_capi == Py_None) num_aux = len(aux_l); else
    f2py_success = int_from_pyobj(&num_aux,num_aux_capi,"advection_1D_ptwise.rp1_ptwise() 2nd keyword (num_aux) can't be converted to int");
  if (f2py_success) {
  CHECKSCALAR(len(aux_l)>=num_aux,"len(aux_l)>=num_aux","2nd keyword num_aux","rp1_ptwise:num_aux=%d",num_aux) {
  /* Processing variable num_eqn */
  if (num_eqn_capi == Py_None) num_eqn = len(q_l); else
    f2py_success = int_from_pyobj(&num_eqn,num_eqn_capi,"advection_1D_ptwise.rp1_ptwise() 1st keyword (num_eqn) can't be converted to int");
  if (f2py_success) {
  CHECKSCALAR(len(q_l)>=num_eqn,"len(q_l)>=num_eqn","1st keyword num_eqn","rp1_ptwise:num_eqn=%d",num_eqn) {
  /* Processing variable wave */
  wave_Dims[0]=num_eqn;
  capi_wave_intent |= F2PY_INTENT_IN;
  capi_wave_tmp = array_from_pyobj(NPY_DOUBLE,wave_Dims,wave_Rank,capi_wave_intent,wave_capi);
  if (capi_wave_tmp == NULL) {
    if (!PyErr_Occurred())
      PyErr_SetString(advection_1D_ptwise_error,"failed in converting 5th argument `wave' of advection_1D_ptwise.rp1_ptwise to C/Fortran array" );
  } else {
    wave = (double *)(capi_wave_tmp->data);

  /* Processing variable q_r */
  q_r_Dims[0]=num_eqn;
  capi_q_r_intent |= F2PY_INTENT_IN;
  capi_q_r_tmp = array_from_pyobj(NPY_DOUBLE,q_r_Dims,q_r_Rank,capi_q_r_intent,q_r_capi);
  if (capi_q_r_tmp == NULL) {
    if (!PyErr_Occurred())
      PyErr_SetString(advection_1D_ptwise_error,"failed in converting 2nd argument `q_r' of advection_1D_ptwise.rp1_ptwise to C/Fortran array" );
  } else {
    q_r = (double *)(capi_q_r_tmp->data);

  /* Processing variable amdq */
  amdq_Dims[0]=num_eqn;
  capi_amdq_intent |= F2PY_INTENT_IN;
  capi_amdq_tmp = array_from_pyobj(NPY_DOUBLE,amdq_Dims,amdq_Rank,capi_amdq_intent,amdq_capi);
  if (capi_amdq_tmp == NULL) {
    if (!PyErr_Occurred())
      PyErr_SetString(advection_1D_ptwise_error,"failed in converting 7th argument `amdq' of advection_1D_ptwise.rp1_ptwise to C/Fortran array" );
  } else {
    amdq = (double *)(capi_amdq_tmp->data);

  /* Processing variable apdq */
  apdq_Dims[0]=num_eqn;
  capi_apdq_intent |= F2PY_INTENT_IN;
  capi_apdq_tmp = array_from_pyobj(NPY_DOUBLE,apdq_Dims,apdq_Rank,capi_apdq_intent,apdq_capi);
  if (capi_apdq_tmp == NULL) {
    if (!PyErr_Occurred())
      PyErr_SetString(advection_1D_ptwise_error,"failed in converting 8th argument `apdq' of advection_1D_ptwise.rp1_ptwise to C/Fortran array" );
  } else {
    apdq = (double *)(capi_apdq_tmp->data);

  /* Processing variable aux_r */
  aux_r_Dims[0]=num_aux;
  capi_aux_r_intent |= F2PY_INTENT_IN;
  capi_aux_r_tmp = array_from_pyobj(NPY_DOUBLE,aux_r_Dims,aux_r_Rank,capi_aux_r_intent,aux_r_capi);
  if (capi_aux_r_tmp == NULL) {
    if (!PyErr_Occurred())
      PyErr_SetString(advection_1D_ptwise_error,"failed in converting 4th argument `aux_r' of advection_1D_ptwise.rp1_ptwise to C/Fortran array" );
  } else {
    aux_r = (double *)(capi_aux_r_tmp->data);

  /* Processing variable num_waves */
  if (num_waves_capi == Py_None) num_waves = shape(wave,1); else
    f2py_success = int_from_pyobj(&num_waves,num_waves_capi,"advection_1D_ptwise.rp1_ptwise() 3rd keyword (num_waves) can't be converted to int");
  if (f2py_success) {
  CHECKSCALAR(shape(wave,1)==num_waves,"shape(wave,1)==num_waves","3rd keyword num_waves","rp1_ptwise:num_waves=%d",num_waves) {
  /* Processing variable s */
  s_Dims[0]=num_waves;
  capi_s_intent |= F2PY_INTENT_IN;
  capi_s_tmp = array_from_pyobj(NPY_DOUBLE,s_Dims,s_Rank,capi_s_intent,s_capi);
  if (capi_s_tmp == NULL) {
    if (!PyErr_Occurred())
      PyErr_SetString(advection_1D_ptwise_error,"failed in converting 6th argument `s' of advection_1D_ptwise.rp1_ptwise to C/Fortran array" );
  } else {
    s = (double *)(capi_s_tmp->data);

/*end of frompyobj*/
#ifdef F2PY_REPORT_ATEXIT
f2py_start_call_clock();
#endif
/*callfortranroutine*/
        (*f2py_func)(&num_eqn,&num_aux,&num_waves,q_l,q_r,aux_l,aux_r,wave,s,amdq,apdq);
if (PyErr_Occurred())
  f2py_success = 0;
#ifdef F2PY_REPORT_ATEXIT
f2py_stop_call_clock();
#endif
/*end of callfortranroutine*/
    if (f2py_success) {
/*pyobjfrom*/
/*end of pyobjfrom*/
    CFUNCSMESS("Building return value.\n");
    capi_buildvalue = Py_BuildValue("");
/*closepyobjfrom*/
/*end of closepyobjfrom*/
    } /*if (f2py_success) after callfortranroutine*/
/*cleanupfrompyobj*/
  if((PyObject *)capi_s_tmp!=s_capi) {
    Py_XDECREF(capi_s_tmp); }
  }  /*if (capi_s_tmp == NULL) ... else of s*/
  /* End of cleaning variable s */
  } /*CHECKSCALAR(shape(wave,1)==num_waves)*/
  } /*if (f2py_success) of num_waves*/
  /* End of cleaning variable num_waves */
  if((PyObject *)capi_aux_r_tmp!=aux_r_capi) {
    Py_XDECREF(capi_aux_r_tmp); }
  }  /*if (capi_aux_r_tmp == NULL) ... else of aux_r*/
  /* End of cleaning variable aux_r */
  if((PyObject *)capi_apdq_tmp!=apdq_capi) {
    Py_XDECREF(capi_apdq_tmp); }
  }  /*if (capi_apdq_tmp == NULL) ... else of apdq*/
  /* End of cleaning variable apdq */
  if((PyObject *)capi_amdq_tmp!=amdq_capi) {
    Py_XDECREF(capi_amdq_tmp); }
  }  /*if (capi_amdq_tmp == NULL) ... else of amdq*/
  /* End of cleaning variable amdq */
  if((PyObject *)capi_q_r_tmp!=q_r_capi) {
    Py_XDECREF(capi_q_r_tmp); }
  }  /*if (capi_q_r_tmp == NULL) ... else of q_r*/
  /* End of cleaning variable q_r */
  if((PyObject *)capi_wave_tmp!=wave_capi) {
    Py_XDECREF(capi_wave_tmp); }
  }  /*if (capi_wave_tmp == NULL) ... else of wave*/
  /* End of cleaning variable wave */
  } /*CHECKSCALAR(len(q_l)>=num_eqn)*/
  } /*if (f2py_success) of num_eqn*/
  /* End of cleaning variable num_eqn */
  } /*CHECKSCALAR(len(aux_l)>=num_aux)*/
  } /*if (f2py_success) of num_aux*/
  /* End of cleaning variable num_aux */
  if((PyObject *)capi_aux_l_tmp!=aux_l_capi) {
    Py_XDECREF(capi_aux_l_tmp); }
  }  /*if (capi_aux_l_tmp == NULL) ... else of aux_l*/
  /* End of cleaning variable aux_l */
  if((PyObject *)capi_q_l_tmp!=q_l_capi) {
    Py_XDECREF(capi_q_l_tmp); }
  }  /*if (capi_q_l_tmp == NULL) ... else of q_l*/
  /* End of cleaning variable q_l */
/*end of cleanupfrompyobj*/
  if (capi_buildvalue == NULL) {
/*routdebugfailure*/
  } else {
/*routdebugleave*/
  }
  CFUNCSMESS("Freeing memory.\n");
/*freemem*/
#ifdef F2PY_REPORT_ATEXIT
f2py_stop_clock();
#endif
  return capi_buildvalue;
}
/***************************** end of rp1_ptwise *****************************/
/*eof body*/

/******************* See f2py2e/f90mod_rules.py: buildhooks *******************/
/*need_f90modhooks*/

/************** See f2py2e/rules.py: module_rules['modulebody'] **************/

/******************* See f2py2e/common_rules.py: buildhooks *******************/

static FortranDataDef f2py_cparam_def[] = {
  {"u",0,{{-1}},NPY_DOUBLE},
  {NULL}
};
static void f2py_setup_cparam(char *u) {
  int i_f2py=0;
  f2py_cparam_def[i_f2py++].data = u;
}
extern void F_FUNC(f2pyinitcparam,F2PYINITCPARAM)(void(*)(char*));
static void f2py_init_cparam(void) {
  F_FUNC(f2pyinitcparam,F2PYINITCPARAM)(f2py_setup_cparam);
}

/*need_commonhooks*/

/**************************** See f2py2e/rules.py ****************************/

static FortranDataDef f2py_routine_defs[] = {
  {"rp1",-1,{{-1}},0,(char *)F_FUNC(rp1,RP1),(f2py_init_func)f2py_rout_advection_1D_ptwise_rp1,doc_f2py_rout_advection_1D_ptwise_rp1},
  {"rp1_ptwise",-1,{{-1}},0,(char *)F_FUNC_US(rp1_ptwise,RP1_PTWISE),(f2py_init_func)f2py_rout_advection_1D_ptwise_rp1_ptwise,doc_f2py_rout_advection_1D_ptwise_rp1_ptwise},

/*eof routine_defs*/
  {NULL}
};

static PyMethodDef f2py_module_methods[] = {

  {NULL,NULL}
};

#if PY_VERSION_HEX >= 0x03000000
static struct PyModuleDef moduledef = {
  PyModuleDef_HEAD_INIT,
  "advection_1D_ptwise",
  NULL,
  -1,
  f2py_module_methods,
  NULL,
  NULL,
  NULL,
  NULL
};
#endif

#if PY_VERSION_HEX >= 0x03000000
#define RETVAL m
PyMODINIT_FUNC PyInit_advection_1D_ptwise(void) {
#else
#define RETVAL
PyMODINIT_FUNC initadvection_1D_ptwise(void) {
#endif
  int i;
  PyObject *m,*d, *s;
#if PY_VERSION_HEX >= 0x03000000
  m = advection_1D_ptwise_module = PyModule_Create(&moduledef);
#else
  m = advection_1D_ptwise_module = Py_InitModule("advection_1D_ptwise", f2py_module_methods);
#endif
  Py_TYPE(&PyFortran_Type) = &PyType_Type;
  import_array();
  if (PyErr_Occurred())
    {PyErr_SetString(PyExc_ImportError, "can't initialize module advection_1D_ptwise (failed to import numpy)"); return RETVAL;}
  d = PyModule_GetDict(m);
  s = PyString_FromString("$Revision: $");
  PyDict_SetItemString(d, "__version__", s);
#if PY_VERSION_HEX >= 0x03000000
  s = PyUnicode_FromString(
#else
  s = PyString_FromString(
#endif
    "This module 'advection_1D_ptwise' is auto-generated with f2py (version:2).\nFunctions:\n"
"  rp1(maxm,maux,mbc,mx,ql,qr,auxl,auxr,wave,s,amdq,apdq,meqn=shape(ql,0),mwaves=shape(wave,1))\n"
"  rp1_ptwise(q_l,q_r,aux_l,aux_r,wave,s,amdq,apdq,num_eqn=len(q_l),num_aux=len(aux_l),num_waves=shape(wave,1))\n"
"COMMON blocks:\n""  /cparam/ u\n"".");
  PyDict_SetItemString(d, "__doc__", s);
  advection_1D_ptwise_error = PyErr_NewException ("advection_1D_ptwise.error", NULL, NULL);
  Py_DECREF(s);
  for(i=0;f2py_routine_defs[i].name!=NULL;i++)
    PyDict_SetItemString(d, f2py_routine_defs[i].name,PyFortranObject_NewAsAttr(&f2py_routine_defs[i]));


/*eof initf2pywraphooks*/
/*eof initf90modhooks*/

  F2PyDict_SetItemString(d, "cparam", PyFortranObject_New(f2py_cparam_def,f2py_init_cparam));
/*eof initcommonhooks*/


#ifdef F2PY_REPORT_ATEXIT
  if (! PyErr_Occurred())
    on_exit(f2py_report_on_exit,(void*)"advection_1D_ptwise");
#endif

  return RETVAL;
}
#ifdef __cplusplus
}
#endif
