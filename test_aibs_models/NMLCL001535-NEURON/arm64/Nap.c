/* Created by Language version: 7.7.0 */
/* VECTORIZED */
#define NRN_VECTORIZED 1
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "mech_api.h"
#undef PI
#define nil 0
#include "md1redef.h"
#include "section.h"
#include "nrniv_mf.h"
#include "md2redef.h"
 
#if METHOD3
extern int _method3;
#endif

#if !NRNGPU
#undef exp
#define exp hoc_Exp
extern double hoc_Exp(double);
#endif
 
#define nrn_init _nrn_init__Nap
#define _nrn_initial _nrn_initial__Nap
#define nrn_cur _nrn_cur__Nap
#define _nrn_current _nrn_current__Nap
#define nrn_jacob _nrn_jacob__Nap
#define nrn_state _nrn_state__Nap
#define _net_receive _net_receive__Nap 
#define rates rates__Nap 
#define states states__Nap 
 
#define _threadargscomma_ _p, _ppvar, _thread, _nt,
#define _threadargsprotocomma_ double* _p, Datum* _ppvar, Datum* _thread, NrnThread* _nt,
#define _threadargs_ _p, _ppvar, _thread, _nt
#define _threadargsproto_ double* _p, Datum* _ppvar, Datum* _thread, NrnThread* _nt
 	/*SUPPRESS 761*/
	/*SUPPRESS 762*/
	/*SUPPRESS 763*/
	/*SUPPRESS 765*/
	 extern double *getarg();
 /* Thread safe. No static _p or _ppvar. */
 
#define t _nt->_t
#define dt _nt->_dt
#define gmax _p[0]
#define gmax_columnindex 0
#define conductance _p[1]
#define conductance_columnindex 1
#define m_instances _p[2]
#define m_instances_columnindex 2
#define m_SEC _p[3]
#define m_SEC_columnindex 3
#define m_steadyState_rate _p[4]
#define m_steadyState_rate_columnindex 4
#define m_steadyState_midpoint _p[5]
#define m_steadyState_midpoint_columnindex 5
#define m_steadyState_scale _p[6]
#define m_steadyState_scale_columnindex 6
#define h_instances _p[7]
#define h_instances_columnindex 7
#define h_forwardRate_rate _p[8]
#define h_forwardRate_rate_columnindex 8
#define h_forwardRate_midpoint _p[9]
#define h_forwardRate_midpoint_columnindex 9
#define h_forwardRate_scale _p[10]
#define h_forwardRate_scale_columnindex 10
#define h_reverseRate_rate _p[11]
#define h_reverseRate_rate_columnindex 11
#define h_reverseRate_midpoint _p[12]
#define h_reverseRate_midpoint_columnindex 12
#define h_reverseRate_scale _p[13]
#define h_reverseRate_scale_columnindex 13
#define h_steadyState_rate _p[14]
#define h_steadyState_rate_columnindex 14
#define h_steadyState_midpoint _p[15]
#define h_steadyState_midpoint_columnindex 15
#define h_steadyState_scale _p[16]
#define h_steadyState_scale_columnindex 16
#define h_q10Settings_q10Factor _p[17]
#define h_q10Settings_q10Factor_columnindex 17
#define h_q10Settings_experimentalTemp _p[18]
#define h_q10Settings_experimentalTemp_columnindex 18
#define h_q10Settings_TENDEGREES _p[19]
#define h_q10Settings_TENDEGREES_columnindex 19
#define gion _p[20]
#define gion_columnindex 20
#define m_steadyState_x _p[21]
#define m_steadyState_x_columnindex 21
#define m_inf _p[22]
#define m_inf_columnindex 22
#define m_tau _p[23]
#define m_tau_columnindex 23
#define m_q _p[24]
#define m_q_columnindex 24
#define m_fcond _p[25]
#define m_fcond_columnindex 25
#define h_forwardRate_x _p[26]
#define h_forwardRate_x_columnindex 26
#define h_forwardRate_r _p[27]
#define h_forwardRate_r_columnindex 27
#define h_reverseRate_x _p[28]
#define h_reverseRate_x_columnindex 28
#define h_reverseRate_r _p[29]
#define h_reverseRate_r_columnindex 29
#define h_steadyState_x _p[30]
#define h_steadyState_x_columnindex 30
#define h_q10Settings_q10 _p[31]
#define h_q10Settings_q10_columnindex 31
#define h_rateScale _p[32]
#define h_rateScale_columnindex 32
#define h_alpha _p[33]
#define h_alpha_columnindex 33
#define h_beta _p[34]
#define h_beta_columnindex 34
#define h_fcond _p[35]
#define h_fcond_columnindex 35
#define h_inf _p[36]
#define h_inf_columnindex 36
#define h_tau _p[37]
#define h_tau_columnindex 37
#define conductanceScale _p[38]
#define conductanceScale_columnindex 38
#define fopen0 _p[39]
#define fopen0_columnindex 39
#define fopen _p[40]
#define fopen_columnindex 40
#define g _p[41]
#define g_columnindex 41
#define h_q _p[42]
#define h_q_columnindex 42
#define temperature _p[43]
#define temperature_columnindex 43
#define ena _p[44]
#define ena_columnindex 44
#define ina _p[45]
#define ina_columnindex 45
#define rate_h_q _p[46]
#define rate_h_q_columnindex 46
#define Dh_q _p[47]
#define Dh_q_columnindex 47
#define v _p[48]
#define v_columnindex 48
#define _g _p[49]
#define _g_columnindex 49
#define _ion_ina	*_ppvar[0]._pval
#define _ion_dinadv	*_ppvar[1]._pval
 
#if MAC
#if !defined(v)
#define v _mlhv
#endif
#if !defined(h)
#define h _mlhh
#endif
#endif
 
#if defined(__cplusplus)
extern "C" {
#endif
 static int hoc_nrnpointerindex =  -1;
 static Datum* _extcall_thread;
 static Prop* _extcall_prop;
 /* external NEURON variables */
 extern double celsius;
 /* declaration of user functions */
 static void _hoc_rates(void);
 static int _mechtype;
extern void _nrn_cacheloop_reg(int, int);
extern void hoc_register_prop_size(int, int, int);
extern void hoc_register_limits(int, HocParmLimits*);
extern void hoc_register_units(int, HocParmUnits*);
extern void nrn_promote(Prop*, int, int);
extern Memb_func* memb_func;
 
#define NMODL_TEXT 1
#if NMODL_TEXT
static const char* nmodl_file_text;
static const char* nmodl_filename;
extern void hoc_reg_nmodl_text(int, const char*);
extern void hoc_reg_nmodl_filename(int, const char*);
#endif

 extern void _nrn_setdata_reg(int, void(*)(Prop*));
 static void _setdata(Prop* _prop) {
 _extcall_prop = _prop;
 }
 static void _hoc_setdata() {
 Prop *_prop, *hoc_getdata_range(int);
 _prop = hoc_getdata_range(_mechtype);
   _setdata(_prop);
 hoc_retpushx(1.);
}
 /* connect user functions to hoc names */
 static VoidFunc hoc_intfunc[] = {
 "setdata_Nap", _hoc_setdata,
 "rates_Nap", _hoc_rates,
 0, 0
};
 /* declare global and static user variables */
 /* some parameters have upper and lower limits */
 static HocParmLimits _hoc_parm_limits[] = {
 0,0,0
};
 static HocParmUnits _hoc_parm_units[] = {
 "gmax_Nap", "S/cm2",
 "conductance_Nap", "uS",
 "m_SEC_Nap", "ms",
 "m_steadyState_midpoint_Nap", "mV",
 "m_steadyState_scale_Nap", "mV",
 "h_forwardRate_rate_Nap", "kHz",
 "h_forwardRate_midpoint_Nap", "mV",
 "h_forwardRate_scale_Nap", "mV",
 "h_reverseRate_rate_Nap", "kHz",
 "h_reverseRate_midpoint_Nap", "mV",
 "h_reverseRate_scale_Nap", "mV",
 "h_steadyState_midpoint_Nap", "mV",
 "h_steadyState_scale_Nap", "mV",
 "h_q10Settings_experimentalTemp_Nap", "K",
 "h_q10Settings_TENDEGREES_Nap", "K",
 "gion_Nap", "S/cm2",
 "m_tau_Nap", "ms",
 "h_forwardRate_r_Nap", "kHz",
 "h_reverseRate_r_Nap", "kHz",
 "h_alpha_Nap", "kHz",
 "h_beta_Nap", "kHz",
 "h_tau_Nap", "ms",
 "g_Nap", "uS",
 0,0
};
 static double delta_t = 0.01;
 static double h_q0 = 0;
 /* connect global user variables to hoc */
 static DoubScal hoc_scdoub[] = {
 0,0
};
 static DoubVec hoc_vdoub[] = {
 0,0,0
};
 static double _sav_indep;
 static void nrn_alloc(Prop*);
static void  nrn_init(NrnThread*, _Memb_list*, int);
static void nrn_state(NrnThread*, _Memb_list*, int);
 static void nrn_cur(NrnThread*, _Memb_list*, int);
static void  nrn_jacob(NrnThread*, _Memb_list*, int);
 
static int _ode_count(int);
static void _ode_map(int, double**, double**, double*, Datum*, double*, int);
static void _ode_spec(NrnThread*, _Memb_list*, int);
static void _ode_matsol(NrnThread*, _Memb_list*, int);
 
#define _cvode_ieq _ppvar[2]._i
 static void _ode_matsol_instance1(_threadargsproto_);
 /* connect range variables in _p that hoc is supposed to know about */
 static const char *_mechanism[] = {
 "7.7.0",
"Nap",
 "gmax_Nap",
 "conductance_Nap",
 "m_instances_Nap",
 "m_SEC_Nap",
 "m_steadyState_rate_Nap",
 "m_steadyState_midpoint_Nap",
 "m_steadyState_scale_Nap",
 "h_instances_Nap",
 "h_forwardRate_rate_Nap",
 "h_forwardRate_midpoint_Nap",
 "h_forwardRate_scale_Nap",
 "h_reverseRate_rate_Nap",
 "h_reverseRate_midpoint_Nap",
 "h_reverseRate_scale_Nap",
 "h_steadyState_rate_Nap",
 "h_steadyState_midpoint_Nap",
 "h_steadyState_scale_Nap",
 "h_q10Settings_q10Factor_Nap",
 "h_q10Settings_experimentalTemp_Nap",
 "h_q10Settings_TENDEGREES_Nap",
 0,
 "gion_Nap",
 "m_steadyState_x_Nap",
 "m_inf_Nap",
 "m_tau_Nap",
 "m_q_Nap",
 "m_fcond_Nap",
 "h_forwardRate_x_Nap",
 "h_forwardRate_r_Nap",
 "h_reverseRate_x_Nap",
 "h_reverseRate_r_Nap",
 "h_steadyState_x_Nap",
 "h_q10Settings_q10_Nap",
 "h_rateScale_Nap",
 "h_alpha_Nap",
 "h_beta_Nap",
 "h_fcond_Nap",
 "h_inf_Nap",
 "h_tau_Nap",
 "conductanceScale_Nap",
 "fopen0_Nap",
 "fopen_Nap",
 "g_Nap",
 0,
 "h_q_Nap",
 0,
 0};
 static Symbol* _na_sym;
 
extern Prop* need_memb(Symbol*);

static void nrn_alloc(Prop* _prop) {
	Prop *prop_ion;
	double *_p; Datum *_ppvar;
 	_p = nrn_prop_data_alloc(_mechtype, 50, _prop);
 	/*initialize range parameters*/
 	gmax = 0;
 	conductance = 1e-05;
 	m_instances = 1;
 	m_SEC = 1000;
 	m_steadyState_rate = 1;
 	m_steadyState_midpoint = -52.6;
 	m_steadyState_scale = 4.6;
 	h_instances = 1;
 	h_forwardRate_rate = 1.33344e-05;
 	h_forwardRate_midpoint = -17;
 	h_forwardRate_scale = -4.63;
 	h_reverseRate_rate = 1.82522e-05;
 	h_reverseRate_midpoint = -64.4;
 	h_reverseRate_scale = 2.63;
 	h_steadyState_rate = 1;
 	h_steadyState_midpoint = -48.8;
 	h_steadyState_scale = -10;
 	h_q10Settings_q10Factor = 2.3;
 	h_q10Settings_experimentalTemp = 294.15;
 	h_q10Settings_TENDEGREES = 10;
 	_prop->param = _p;
 	_prop->param_size = 50;
 	_ppvar = nrn_prop_datum_alloc(_mechtype, 3, _prop);
 	_prop->dparam = _ppvar;
 	/*connect ionic variables to this model*/
 prop_ion = need_memb(_na_sym);
 	_ppvar[0]._pval = &prop_ion->param[3]; /* ina */
 	_ppvar[1]._pval = &prop_ion->param[4]; /* _ion_dinadv */
 
}
 static void _initlists();
  /* some states have an absolute tolerance */
 static Symbol** _atollist;
 static HocStateTolerance _hoc_state_tol[] = {
 0,0
};
 static void _update_ion_pointer(Datum*);
 extern Symbol* hoc_lookup(const char*);
extern void _nrn_thread_reg(int, int, void(*)(Datum*));
extern void _nrn_thread_table_reg(int, void(*)(double*, Datum*, Datum*, NrnThread*, int));
extern void hoc_register_tolerance(int, HocStateTolerance*, Symbol***);
extern void _cvode_abstol( Symbol**, double*, int);

 void _Nap_reg() {
	int _vectorized = 1;
  _initlists();
 	ion_reg("na", 1.0);
 	_na_sym = hoc_lookup("na_ion");
 	register_mech(_mechanism, nrn_alloc,nrn_cur, nrn_jacob, nrn_state, nrn_init, hoc_nrnpointerindex, 1);
 _mechtype = nrn_get_mechtype(_mechanism[1]);
     _nrn_setdata_reg(_mechtype, _setdata);
     _nrn_thread_reg(_mechtype, 2, _update_ion_pointer);
 #if NMODL_TEXT
  hoc_reg_nmodl_text(_mechtype, nmodl_file_text);
  hoc_reg_nmodl_filename(_mechtype, nmodl_filename);
#endif
  hoc_register_prop_size(_mechtype, 50, 3);
  hoc_register_dparam_semantics(_mechtype, 0, "na_ion");
  hoc_register_dparam_semantics(_mechtype, 1, "na_ion");
  hoc_register_dparam_semantics(_mechtype, 2, "cvodeieq");
 	hoc_register_cvode(_mechtype, _ode_count, _ode_map, _ode_spec, _ode_matsol);
 	hoc_register_tolerance(_mechtype, _hoc_state_tol, &_atollist);
 	hoc_register_var(hoc_scdoub, hoc_vdoub, hoc_intfunc);
 	ivoc_help("help ?1 Nap /Users/katedoxey/Desktop/research/CRCNS/code/Haynes2023_EAPs/test_aibs_models/NMLCL001535-NEURON/Nap.mod\n");
 hoc_register_limits(_mechtype, _hoc_parm_limits);
 hoc_register_units(_mechtype, _hoc_parm_units);
 }
static int _reset;
static char *modelname = "Mod file for component: Component(id=Nap type=ionChannelHH)";

static int error;
static int _ninits = 0;
static int _match_recurse=1;
static void _modl_cleanup(){ _match_recurse=1;}
static int rates(_threadargsproto_);
 
static int _ode_spec1(_threadargsproto_);
/*static int _ode_matsol1(_threadargsproto_);*/
 static int _slist1[1], _dlist1[1];
 static int states(_threadargsproto_);
 
/*CVODE*/
 static int _ode_spec1 (double* _p, Datum* _ppvar, Datum* _thread, NrnThread* _nt) {int _reset = 0; {
   rates ( _threadargs_ ) ;
   Dh_q = rate_h_q ;
   }
 return _reset;
}
 static int _ode_matsol1 (double* _p, Datum* _ppvar, Datum* _thread, NrnThread* _nt) {
 rates ( _threadargs_ ) ;
 Dh_q = Dh_q  / (1. - dt*( 0.0 )) ;
  return 0;
}
 /*END CVODE*/
 static int states (double* _p, Datum* _ppvar, Datum* _thread, NrnThread* _nt) { {
   rates ( _threadargs_ ) ;
    h_q = h_q - dt*(- ( rate_h_q ) ) ;
   }
  return 0;
}
 
static int  rates ( _threadargsproto_ ) {
   m_steadyState_x = m_steadyState_rate / ( 1.0 + exp ( 0.0 - ( v - m_steadyState_midpoint ) / m_steadyState_scale ) ) ;
   m_inf = m_steadyState_x ;
   m_tau = 0.0 * m_SEC ;
   m_q = m_inf ;
   m_fcond = pow( m_q , m_instances ) ;
   h_forwardRate_x = ( v - h_forwardRate_midpoint ) / h_forwardRate_scale ;
   if ( h_forwardRate_x  != 0.0 ) {
     h_forwardRate_r = h_forwardRate_rate * h_forwardRate_x / ( 1.0 - exp ( 0.0 - h_forwardRate_x ) ) ;
     }
   else if ( h_forwardRate_x  == 0.0 ) {
     h_forwardRate_r = h_forwardRate_rate ;
     }
   h_reverseRate_x = ( v - h_reverseRate_midpoint ) / h_reverseRate_scale ;
   if ( h_reverseRate_x  != 0.0 ) {
     h_reverseRate_r = h_reverseRate_rate * h_reverseRate_x / ( 1.0 - exp ( 0.0 - h_reverseRate_x ) ) ;
     }
   else if ( h_reverseRate_x  == 0.0 ) {
     h_reverseRate_r = h_reverseRate_rate ;
     }
   h_steadyState_x = h_steadyState_rate / ( 1.0 + exp ( 0.0 - ( v - h_steadyState_midpoint ) / h_steadyState_scale ) ) ;
   h_q10Settings_q10 = pow( h_q10Settings_q10Factor , ( ( temperature - h_q10Settings_experimentalTemp ) / h_q10Settings_TENDEGREES ) ) ;
   h_rateScale = h_q10Settings_q10 ;
   h_alpha = h_forwardRate_r ;
   h_beta = h_reverseRate_r ;
   h_fcond = pow( h_q , h_instances ) ;
   h_inf = h_steadyState_x ;
   h_tau = 1.0 / ( ( h_alpha + h_beta ) * h_rateScale ) ;
   rate_h_q = ( h_inf - h_q ) / h_tau ;
    return 0; }
 
static void _hoc_rates(void) {
  double _r;
   double* _p; Datum* _ppvar; Datum* _thread; NrnThread* _nt;
   if (_extcall_prop) {_p = _extcall_prop->param; _ppvar = _extcall_prop->dparam;}else{ _p = (double*)0; _ppvar = (Datum*)0; }
  _thread = _extcall_thread;
  _nt = nrn_threads;
 _r = 1.;
 rates ( _p, _ppvar, _thread, _nt );
 hoc_retpushx(_r);
}
 
static int _ode_count(int _type){ return 1;}
 
static void _ode_spec(NrnThread* _nt, _Memb_list* _ml, int _type) {
   double* _p; Datum* _ppvar; Datum* _thread;
   Node* _nd; double _v; int _iml, _cntml;
  _cntml = _ml->_nodecount;
  _thread = _ml->_thread;
  for (_iml = 0; _iml < _cntml; ++_iml) {
    _p = _ml->_data[_iml]; _ppvar = _ml->_pdata[_iml];
    _nd = _ml->_nodelist[_iml];
    v = NODEV(_nd);
     _ode_spec1 (_p, _ppvar, _thread, _nt);
  }}
 
static void _ode_map(int _ieq, double** _pv, double** _pvdot, double* _pp, Datum* _ppd, double* _atol, int _type) { 
	double* _p; Datum* _ppvar;
 	int _i; _p = _pp; _ppvar = _ppd;
	_cvode_ieq = _ieq;
	for (_i=0; _i < 1; ++_i) {
		_pv[_i] = _pp + _slist1[_i];  _pvdot[_i] = _pp + _dlist1[_i];
		_cvode_abstol(_atollist, _atol, _i);
	}
 }
 
static void _ode_matsol_instance1(_threadargsproto_) {
 _ode_matsol1 (_p, _ppvar, _thread, _nt);
 }
 
static void _ode_matsol(NrnThread* _nt, _Memb_list* _ml, int _type) {
   double* _p; Datum* _ppvar; Datum* _thread;
   Node* _nd; double _v; int _iml, _cntml;
  _cntml = _ml->_nodecount;
  _thread = _ml->_thread;
  for (_iml = 0; _iml < _cntml; ++_iml) {
    _p = _ml->_data[_iml]; _ppvar = _ml->_pdata[_iml];
    _nd = _ml->_nodelist[_iml];
    v = NODEV(_nd);
 _ode_matsol_instance1(_threadargs_);
 }}
 extern void nrn_update_ion_pointer(Symbol*, Datum*, int, int);
 static void _update_ion_pointer(Datum* _ppvar) {
   nrn_update_ion_pointer(_na_sym, _ppvar, 0, 3);
   nrn_update_ion_pointer(_na_sym, _ppvar, 1, 4);
 }

static void initmodel(double* _p, Datum* _ppvar, Datum* _thread, NrnThread* _nt) {
  int _i; double _save;{
  h_q = h_q0;
 {
   ena = 53.0 ;
   temperature = celsius + 273.15 ;
   rates ( _threadargs_ ) ;
   rates ( _threadargs_ ) ;
   h_q = h_inf ;
   }
 
}
}

static void nrn_init(NrnThread* _nt, _Memb_list* _ml, int _type){
double* _p; Datum* _ppvar; Datum* _thread;
Node *_nd; double _v; int* _ni; int _iml, _cntml;
#if CACHEVEC
    _ni = _ml->_nodeindices;
#endif
_cntml = _ml->_nodecount;
_thread = _ml->_thread;
for (_iml = 0; _iml < _cntml; ++_iml) {
 _p = _ml->_data[_iml]; _ppvar = _ml->_pdata[_iml];
#if CACHEVEC
  if (use_cachevec) {
    _v = VEC_V(_ni[_iml]);
  }else
#endif
  {
    _nd = _ml->_nodelist[_iml];
    _v = NODEV(_nd);
  }
 v = _v;
 initmodel(_p, _ppvar, _thread, _nt);
 }
}

static double _nrn_current(double* _p, Datum* _ppvar, Datum* _thread, NrnThread* _nt, double _v){double _current=0.;v=_v;{ {
   conductanceScale = 1.0 ;
   fopen0 = m_fcond * h_fcond ;
   fopen = conductanceScale * fopen0 ;
   g = conductance * fopen ;
   gion = gmax * fopen ;
   ina = gion * ( v - ena ) ;
   }
 _current += ina;

} return _current;
}

static void nrn_cur(NrnThread* _nt, _Memb_list* _ml, int _type) {
double* _p; Datum* _ppvar; Datum* _thread;
Node *_nd; int* _ni; double _rhs, _v; int _iml, _cntml;
#if CACHEVEC
    _ni = _ml->_nodeindices;
#endif
_cntml = _ml->_nodecount;
_thread = _ml->_thread;
for (_iml = 0; _iml < _cntml; ++_iml) {
 _p = _ml->_data[_iml]; _ppvar = _ml->_pdata[_iml];
#if CACHEVEC
  if (use_cachevec) {
    _v = VEC_V(_ni[_iml]);
  }else
#endif
  {
    _nd = _ml->_nodelist[_iml];
    _v = NODEV(_nd);
  }
 _g = _nrn_current(_p, _ppvar, _thread, _nt, _v + .001);
 	{ double _dina;
  _dina = ina;
 _rhs = _nrn_current(_p, _ppvar, _thread, _nt, _v);
  _ion_dinadv += (_dina - ina)/.001 ;
 	}
 _g = (_g - _rhs)/.001;
  _ion_ina += ina ;
#if CACHEVEC
  if (use_cachevec) {
	VEC_RHS(_ni[_iml]) -= _rhs;
  }else
#endif
  {
	NODERHS(_nd) -= _rhs;
  }
 
}
 
}

static void nrn_jacob(NrnThread* _nt, _Memb_list* _ml, int _type) {
double* _p; Datum* _ppvar; Datum* _thread;
Node *_nd; int* _ni; int _iml, _cntml;
#if CACHEVEC
    _ni = _ml->_nodeindices;
#endif
_cntml = _ml->_nodecount;
_thread = _ml->_thread;
for (_iml = 0; _iml < _cntml; ++_iml) {
 _p = _ml->_data[_iml];
#if CACHEVEC
  if (use_cachevec) {
	VEC_D(_ni[_iml]) += _g;
  }else
#endif
  {
     _nd = _ml->_nodelist[_iml];
	NODED(_nd) += _g;
  }
 
}
 
}

static void nrn_state(NrnThread* _nt, _Memb_list* _ml, int _type) {
double* _p; Datum* _ppvar; Datum* _thread;
Node *_nd; double _v = 0.0; int* _ni; int _iml, _cntml;
#if CACHEVEC
    _ni = _ml->_nodeindices;
#endif
_cntml = _ml->_nodecount;
_thread = _ml->_thread;
for (_iml = 0; _iml < _cntml; ++_iml) {
 _p = _ml->_data[_iml]; _ppvar = _ml->_pdata[_iml];
 _nd = _ml->_nodelist[_iml];
#if CACHEVEC
  if (use_cachevec) {
    _v = VEC_V(_ni[_iml]);
  }else
#endif
  {
    _nd = _ml->_nodelist[_iml];
    _v = NODEV(_nd);
  }
 v=_v;
{
 {   states(_p, _ppvar, _thread, _nt);
  } }}

}

static void terminal(){}

static void _initlists(){
 double _x; double* _p = &_x;
 int _i; static int _first = 1;
  if (!_first) return;
 _slist1[0] = h_q_columnindex;  _dlist1[0] = Dh_q_columnindex;
_first = 0;
}

#if defined(__cplusplus)
} /* extern "C" */
#endif

#if NMODL_TEXT
static const char* nmodl_filename = "/Users/katedoxey/Desktop/research/CRCNS/code/Haynes2023_EAPs/test_aibs_models/NMLCL001535-NEURON/Nap.mod";
static const char* nmodl_file_text = 
  "TITLE Mod file for component: Component(id=Nap type=ionChannelHH)\n"
  "\n"
  "COMMENT\n"
  "\n"
  "    This NEURON file has been generated by org.neuroml.export (see https://github.com/NeuroML/org.neuroml.export)\n"
  "         org.neuroml.export  v1.5.3\n"
  "         org.neuroml.model   v1.5.3\n"
  "         jLEMS               v0.9.9.0\n"
  "\n"
  "ENDCOMMENT\n"
  "\n"
  "NEURON {\n"
  "    SUFFIX Nap\n"
  "    USEION na WRITE ina VALENCE 1 ? Assuming valence = 1; TODO check this!!\n"
  "    \n"
  "    RANGE gion                           \n"
  "    RANGE gmax                              : Will be changed when ion channel mechanism placed on cell!\n"
  "    RANGE conductance                       : parameter\n"
  "    \n"
  "    RANGE g                                 : exposure\n"
  "    \n"
  "    RANGE fopen                             : exposure\n"
  "    RANGE m_instances                       : parameter\n"
  "    RANGE m_SEC                             : parameter\n"
  "    \n"
  "    RANGE m_tau                             : exposure\n"
  "    \n"
  "    RANGE m_inf                             : exposure\n"
  "    \n"
  "    RANGE m_fcond                           : exposure\n"
  "    \n"
  "    RANGE m_q                               : exposure\n"
  "    RANGE m_steadyState_rate                : parameter\n"
  "    RANGE m_steadyState_midpoint            : parameter\n"
  "    RANGE m_steadyState_scale               : parameter\n"
  "    \n"
  "    RANGE m_steadyState_x                   : exposure\n"
  "    RANGE h_instances                       : parameter\n"
  "    \n"
  "    RANGE h_alpha                           : exposure\n"
  "    \n"
  "    RANGE h_beta                            : exposure\n"
  "    \n"
  "    RANGE h_tau                             : exposure\n"
  "    \n"
  "    RANGE h_inf                             : exposure\n"
  "    \n"
  "    RANGE h_rateScale                       : exposure\n"
  "    \n"
  "    RANGE h_fcond                           : exposure\n"
  "    RANGE h_forwardRate_rate                : parameter\n"
  "    RANGE h_forwardRate_midpoint            : parameter\n"
  "    RANGE h_forwardRate_scale               : parameter\n"
  "    \n"
  "    RANGE h_forwardRate_r                   : exposure\n"
  "    RANGE h_reverseRate_rate                : parameter\n"
  "    RANGE h_reverseRate_midpoint            : parameter\n"
  "    RANGE h_reverseRate_scale               : parameter\n"
  "    \n"
  "    RANGE h_reverseRate_r                   : exposure\n"
  "    RANGE h_steadyState_rate                : parameter\n"
  "    RANGE h_steadyState_midpoint            : parameter\n"
  "    RANGE h_steadyState_scale               : parameter\n"
  "    \n"
  "    RANGE h_steadyState_x                   : exposure\n"
  "    RANGE h_q10Settings_q10Factor           : parameter\n"
  "    RANGE h_q10Settings_experimentalTemp    : parameter\n"
  "    RANGE h_q10Settings_TENDEGREES          : parameter\n"
  "    \n"
  "    RANGE h_q10Settings_q10                 : exposure\n"
  "    RANGE h_forwardRate_x                   : derived variable\n"
  "    RANGE h_reverseRate_x                   : derived variable\n"
  "    RANGE conductanceScale                  : derived variable\n"
  "    RANGE fopen0                            : derived variable\n"
  "    \n"
  "}\n"
  "\n"
  "UNITS {\n"
  "    \n"
  "    (nA) = (nanoamp)\n"
  "    (uA) = (microamp)\n"
  "    (mA) = (milliamp)\n"
  "    (A) = (amp)\n"
  "    (mV) = (millivolt)\n"
  "    (mS) = (millisiemens)\n"
  "    (uS) = (microsiemens)\n"
  "    (molar) = (1/liter)\n"
  "    (kHz) = (kilohertz)\n"
  "    (mM) = (millimolar)\n"
  "    (um) = (micrometer)\n"
  "    (umol) = (micromole)\n"
  "    (S) = (siemens)\n"
  "    \n"
  "}\n"
  "\n"
  "PARAMETER {\n"
  "    \n"
  "    gmax = 0  (S/cm2)                       : Will be changed when ion channel mechanism placed on cell!\n"
  "    \n"
  "    conductance = 1.0E-5 (uS)\n"
  "    m_instances = 1 \n"
  "    m_SEC = 1000 (ms)\n"
  "    m_steadyState_rate = 1 \n"
  "    m_steadyState_midpoint = -52.6 (mV)\n"
  "    m_steadyState_scale = 4.6 (mV)\n"
  "    h_instances = 1 \n"
  "    h_forwardRate_rate = 1.3334401E-5 (kHz)\n"
  "    h_forwardRate_midpoint = -17 (mV)\n"
  "    h_forwardRate_scale = -4.63 (mV)\n"
  "    h_reverseRate_rate = 1.8252202E-5 (kHz)\n"
  "    h_reverseRate_midpoint = -64.4 (mV)\n"
  "    h_reverseRate_scale = 2.63 (mV)\n"
  "    h_steadyState_rate = 1 \n"
  "    h_steadyState_midpoint = -48.8 (mV)\n"
  "    h_steadyState_scale = -10 (mV)\n"
  "    h_q10Settings_q10Factor = 2.3 \n"
  "    h_q10Settings_experimentalTemp = 294.15 (K)\n"
  "    h_q10Settings_TENDEGREES = 10 (K)\n"
  "}\n"
  "\n"
  "ASSIGNED {\n"
  "    \n"
  "    gion   (S/cm2)                          : Transient conductance density of the channel? Standard Assigned variables with ionChannel\n"
  "    v (mV)\n"
  "    celsius (degC)\n"
  "    temperature (K)\n"
  "    ena (mV)\n"
  "    ina (mA/cm2)\n"
  "    \n"
  "    \n"
  "    m_steadyState_x                        : derived variable\n"
  "    \n"
  "    m_inf                                  : derived variable\n"
  "    \n"
  "    m_tau (ms)                             : derived variable\n"
  "    \n"
  "    m_q                                    : derived variable\n"
  "    \n"
  "    m_fcond                                : derived variable\n"
  "    \n"
  "    h_forwardRate_x                        : derived variable\n"
  "    \n"
  "    h_forwardRate_r (kHz)                  : conditional derived var...\n"
  "    \n"
  "    h_reverseRate_x                        : derived variable\n"
  "    \n"
  "    h_reverseRate_r (kHz)                  : conditional derived var...\n"
  "    \n"
  "    h_steadyState_x                        : derived variable\n"
  "    \n"
  "    h_q10Settings_q10                      : derived variable\n"
  "    \n"
  "    h_rateScale                            : derived variable\n"
  "    \n"
  "    h_alpha (kHz)                          : derived variable\n"
  "    \n"
  "    h_beta (kHz)                           : derived variable\n"
  "    \n"
  "    h_fcond                                : derived variable\n"
  "    \n"
  "    h_inf                                  : derived variable\n"
  "    \n"
  "    h_tau (ms)                             : derived variable\n"
  "    \n"
  "    conductanceScale                       : derived variable\n"
  "    \n"
  "    fopen0                                 : derived variable\n"
  "    \n"
  "    fopen                                  : derived variable\n"
  "    \n"
  "    g (uS)                                 : derived variable\n"
  "    rate_h_q (/ms)\n"
  "    \n"
  "}\n"
  "\n"
  "STATE {\n"
  "    h_q  \n"
  "    \n"
  "}\n"
  "\n"
  "INITIAL {\n"
  "    ena = 53.0\n"
  "    \n"
  "    temperature = celsius + 273.15\n"
  "    \n"
  "    rates()\n"
  "    rates() ? To ensure correct initialisation.\n"
  "    \n"
  "    h_q = h_inf\n"
  "    \n"
  "}\n"
  "\n"
  "BREAKPOINT {\n"
  "    \n"
  "    SOLVE states METHOD cnexp\n"
  "    \n"
  "    ? DerivedVariable is based on path: conductanceScaling[*]/factor, on: Component(id=Nap type=ionChannelHH), from conductanceScaling; null\n"
  "    ? Path not present in component, using factor: 1\n"
  "    \n"
  "    conductanceScale = 1 \n"
  "    \n"
  "    ? DerivedVariable is based on path: gates[*]/fcond, on: Component(id=Nap type=ionChannelHH), from gates; Component(id=m type=gateHHInstantaneous)\n"
  "    ? multiply applied to all instances of fcond in: <gates> ([Component(id=m type=gateHHInstantaneous), Component(id=h type=gateHHratesInf)]))\n"
  "    fopen0 = m_fcond * h_fcond ? path based, prefix = \n"
  "    \n"
  "    fopen = conductanceScale  *  fopen0 ? evaluable\n"
  "    g = conductance  *  fopen ? evaluable\n"
  "    gion = gmax * fopen \n"
  "    \n"
  "    ina = gion * (v - ena)\n"
  "    \n"
  "}\n"
  "\n"
  "DERIVATIVE states {\n"
  "    rates()\n"
  "    h_q' = rate_h_q \n"
  "    \n"
  "}\n"
  "\n"
  "PROCEDURE rates() {\n"
  "    \n"
  "    m_steadyState_x = m_steadyState_rate  / (1 + exp(0 - (v -  m_steadyState_midpoint )/ m_steadyState_scale )) ? evaluable\n"
  "    ? DerivedVariable is based on path: steadyState/x, on: Component(id=m type=gateHHInstantaneous), from steadyState; Component(id=null type=HHSigmoidVariable)\n"
  "    m_inf = m_steadyState_x ? path based, prefix = m_\n"
  "    \n"
  "    m_tau = 0 *  m_SEC ? evaluable\n"
  "    m_q = m_inf ? evaluable\n"
  "    m_fcond = m_q ^ m_instances ? evaluable\n"
  "    h_forwardRate_x = (v -  h_forwardRate_midpoint ) /  h_forwardRate_scale ? evaluable\n"
  "    if (h_forwardRate_x  != 0)  { \n"
  "        h_forwardRate_r = h_forwardRate_rate  *  h_forwardRate_x  / (1 - exp(0 -  h_forwardRate_x )) ? evaluable cdv\n"
  "    } else if (h_forwardRate_x  == 0)  { \n"
  "        h_forwardRate_r = h_forwardRate_rate ? evaluable cdv\n"
  "    }\n"
  "    \n"
  "    h_reverseRate_x = (v -  h_reverseRate_midpoint ) /  h_reverseRate_scale ? evaluable\n"
  "    if (h_reverseRate_x  != 0)  { \n"
  "        h_reverseRate_r = h_reverseRate_rate  *  h_reverseRate_x  / (1 - exp(0 -  h_reverseRate_x )) ? evaluable cdv\n"
  "    } else if (h_reverseRate_x  == 0)  { \n"
  "        h_reverseRate_r = h_reverseRate_rate ? evaluable cdv\n"
  "    }\n"
  "    \n"
  "    h_steadyState_x = h_steadyState_rate  / (1 + exp(0 - (v -  h_steadyState_midpoint )/ h_steadyState_scale )) ? evaluable\n"
  "    h_q10Settings_q10 = h_q10Settings_q10Factor ^((temperature -  h_q10Settings_experimentalTemp )/ h_q10Settings_TENDEGREES ) ? evaluable\n"
  "    ? DerivedVariable is based on path: q10Settings[*]/q10, on: Component(id=h type=gateHHratesInf), from q10Settings; Component(id=null type=q10ExpTemp)\n"
  "    ? multiply applied to all instances of q10 in: <q10Settings> ([Component(id=null type=q10ExpTemp)]))\n"
  "    h_rateScale = h_q10Settings_q10 ? path based, prefix = h_\n"
  "    \n"
  "    ? DerivedVariable is based on path: forwardRate/r, on: Component(id=h type=gateHHratesInf), from forwardRate; Component(id=null type=HHExpLinearRate)\n"
  "    h_alpha = h_forwardRate_r ? path based, prefix = h_\n"
  "    \n"
  "    ? DerivedVariable is based on path: reverseRate/r, on: Component(id=h type=gateHHratesInf), from reverseRate; Component(id=null type=HHExpLinearRate)\n"
  "    h_beta = h_reverseRate_r ? path based, prefix = h_\n"
  "    \n"
  "    h_fcond = h_q ^ h_instances ? evaluable\n"
  "    ? DerivedVariable is based on path: steadyState/x, on: Component(id=h type=gateHHratesInf), from steadyState; Component(id=null type=HHSigmoidVariable)\n"
  "    h_inf = h_steadyState_x ? path based, prefix = h_\n"
  "    \n"
  "    h_tau = 1/(( h_alpha + h_beta ) *  h_rateScale ) ? evaluable\n"
  "    \n"
  "     \n"
  "    \n"
  "     \n"
  "    \n"
  "     \n"
  "    \n"
  "     \n"
  "    \n"
  "     \n"
  "    \n"
  "     \n"
  "    \n"
  "     \n"
  "    \n"
  "     \n"
  "    \n"
  "     \n"
  "    \n"
  "     \n"
  "    \n"
  "     \n"
  "    \n"
  "     \n"
  "    \n"
  "     \n"
  "    \n"
  "     \n"
  "    rate_h_q = ( h_inf  -  h_q ) /  h_tau ? Note units of all quantities used here need to be consistent!\n"
  "    \n"
  "     \n"
  "    \n"
  "     \n"
  "    \n"
  "     \n"
  "    \n"
  "     \n"
  "    \n"
  "     \n"
  "    \n"
  "}\n"
  "\n"
  ;
#endif
