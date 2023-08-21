TITLE Mod file for component: Component(id=Kv2like type=ionChannelHH)

COMMENT

    This NEURON file has been generated by org.neuroml.export (see https://github.com/NeuroML/org.neuroml.export)
         org.neuroml.export  v1.5.3
         org.neuroml.model   v1.5.3
         jLEMS               v0.9.9.0

ENDCOMMENT

NEURON {
    SUFFIX Kv2like
    USEION k WRITE ik VALENCE 1 ? Assuming valence = 1; TODO check this!!
    
    RANGE gion                           
    RANGE gmax                              : Will be changed when ion channel mechanism placed on cell!
    RANGE conductance                       : parameter
    
    RANGE g                                 : exposure
    
    RANGE fopen                             : exposure
    RANGE m_instances                       : parameter
    
    RANGE m_alpha                           : exposure
    
    RANGE m_beta                            : exposure
    
    RANGE m_tau                             : exposure
    
    RANGE m_inf                             : exposure
    
    RANGE m_rateScale                       : exposure
    
    RANGE m_fcond                           : exposure
    RANGE m_forwardRate_rate                : parameter
    RANGE m_forwardRate_midpoint            : parameter
    RANGE m_forwardRate_scale               : parameter
    
    RANGE m_forwardRate_r                   : exposure
    RANGE m_reverseRate_rate                : parameter
    RANGE m_reverseRate_midpoint            : parameter
    RANGE m_reverseRate_scale               : parameter
    
    RANGE m_reverseRate_r                   : exposure
    RANGE m_q10Settings_q10Factor           : parameter
    RANGE m_q10Settings_experimentalTemp    : parameter
    RANGE m_q10Settings_TENDEGREES          : parameter
    
    RANGE m_q10Settings_q10                 : exposure
    RANGE h_instances                       : parameter
    
    RANGE h_rateScale                       : exposure
    
    RANGE h_fcond                           : exposure
    
    RANGE h_q                               : exposure
    RANGE h_q10Settings_q10Factor           : parameter
    RANGE h_q10Settings_experimentalTemp    : parameter
    RANGE h_q10Settings_TENDEGREES          : parameter
    
    RANGE h_q10Settings_q10                 : exposure
    RANGE h_h1_fractionalConductance        : parameter
    
    RANGE h_h1_tau                          : exposure
    
    RANGE h_h1_inf                          : exposure
    
    RANGE h_h1_qfrac                        : exposure
    RANGE h_h1_steadyState_rate             : parameter
    RANGE h_h1_steadyState_midpoint         : parameter
    RANGE h_h1_steadyState_scale            : parameter
    
    RANGE h_h1_steadyState_x                : exposure
    RANGE h_h1_timeCourse_TIME_SCALE        : parameter
    RANGE h_h1_timeCourse_VOLT_SCALE        : parameter
    RANGE h_h1_timeCourse_b0                : parameter
    RANGE h_h1_timeCourse_b11               : parameter
    RANGE h_h1_timeCourse_b2                : parameter
    RANGE h_h1_timeCourse_b3                : parameter
    RANGE h_h1_timeCourse_b4                : parameter
    RANGE h_h1_timeCourse_b5                : parameter
    
    RANGE h_h1_timeCourse_t                 : exposure
    RANGE h_h2_fractionalConductance        : parameter
    
    RANGE h_h2_tau                          : exposure
    
    RANGE h_h2_inf                          : exposure
    
    RANGE h_h2_qfrac                        : exposure
    RANGE h_h2_steadyState_rate             : parameter
    RANGE h_h2_steadyState_midpoint         : parameter
    RANGE h_h2_steadyState_scale            : parameter
    
    RANGE h_h2_steadyState_x                : exposure
    RANGE h_h2_timeCourse_TIME_SCALE        : parameter
    RANGE h_h2_timeCourse_VOLT_SCALE        : parameter
    RANGE h_h2_timeCourse_bb0               : parameter
    RANGE h_h2_timeCourse_bb1               : parameter
    RANGE h_h2_timeCourse_bb2               : parameter
    RANGE h_h2_timeCourse_bb3               : parameter
    RANGE h_h2_timeCourse_bb4               : parameter
    
    RANGE h_h2_timeCourse_t                 : exposure
    RANGE m_forwardRate_x                   : derived variable
    RANGE h_h1_timeCourse_V                 : derived variable
    RANGE h_h1_tauUnscaled                  : derived variable
    RANGE h_h2_timeCourse_V                 : derived variable
    RANGE h_h2_tauUnscaled                  : derived variable
    RANGE conductanceScale                  : derived variable
    RANGE fopen0                            : derived variable
    
}

UNITS {
    
    (nA) = (nanoamp)
    (uA) = (microamp)
    (mA) = (milliamp)
    (A) = (amp)
    (mV) = (millivolt)
    (mS) = (millisiemens)
    (uS) = (microsiemens)
    (molar) = (1/liter)
    (kHz) = (kilohertz)
    (mM) = (millimolar)
    (um) = (micrometer)
    (umol) = (micromole)
    (S) = (siemens)
    
}

PARAMETER {
    
    gmax = 0  (S/cm2)                       : Will be changed when ion channel mechanism placed on cell!
    
    conductance = 1.0E-5 (uS)
    m_instances = 2 
    m_forwardRate_rate = 0.528 (kHz)
    m_forwardRate_midpoint = 43 (mV)
    m_forwardRate_scale = 11 (mV)
    m_reverseRate_rate = 0.008 (kHz)
    m_reverseRate_midpoint = -1.27 (mV)
    m_reverseRate_scale = -120 (mV)
    m_q10Settings_q10Factor = 2.3 
    m_q10Settings_experimentalTemp = 294.15 (K)
    m_q10Settings_TENDEGREES = 10 (K)
    h_instances = 1 
    h_q10Settings_q10Factor = 2.3 
    h_q10Settings_experimentalTemp = 294.15 (K)
    h_q10Settings_TENDEGREES = 10 (K)
    h_h1_fractionalConductance = 0.5 
    h_h1_steadyState_rate = 1 
    h_h1_steadyState_midpoint = -58 (mV)
    h_h1_steadyState_scale = -11 (mV)
    h_h1_timeCourse_TIME_SCALE = 1 (ms)
    h_h1_timeCourse_VOLT_SCALE = 1 (mV)
    h_h1_timeCourse_b0 = 360 
    h_h1_timeCourse_b11 = 1010 
    h_h1_timeCourse_b2 = -75 
    h_h1_timeCourse_b3 = 48 
    h_h1_timeCourse_b4 = 23.7 
    h_h1_timeCourse_b5 = -54 
    h_h2_fractionalConductance = 0.5 
    h_h2_steadyState_rate = 1 
    h_h2_steadyState_midpoint = -58 (mV)
    h_h2_steadyState_scale = -11 (mV)
    h_h2_timeCourse_TIME_SCALE = 1 (ms)
    h_h2_timeCourse_VOLT_SCALE = 1 (mV)
    h_h2_timeCourse_bb0 = 2350 
    h_h2_timeCourse_bb1 = 1380 
    h_h2_timeCourse_bb2 = 0.011 
    h_h2_timeCourse_bb3 = -210 
    h_h2_timeCourse_bb4 = 0.03 
}

ASSIGNED {
    
    gion   (S/cm2)                          : Transient conductance density of the channel? Standard Assigned variables with ionChannel
    v (mV)
    celsius (degC)
    temperature (K)
    ek (mV)
    ik (mA/cm2)
    
    
    m_forwardRate_x                        : derived variable
    
    m_forwardRate_r (kHz)                  : conditional derived var...
    
    m_reverseRate_r (kHz)                  : derived variable
    
    m_q10Settings_q10                      : derived variable
    
    m_rateScale                            : derived variable
    
    m_alpha (kHz)                          : derived variable
    
    m_beta (kHz)                           : derived variable
    
    m_fcond                                : derived variable
    
    m_inf                                  : derived variable
    
    m_tau (ms)                             : derived variable
    
    h_q10Settings_q10                      : derived variable
    
    h_h1_steadyState_x                     : derived variable
    
    h_h1_timeCourse_V                      : derived variable
    
    h_h1_timeCourse_t (ms)                 : derived variable
    
    h_h1_inf                               : derived variable
    
    h_h1_tauUnscaled (ms)                  : derived variable
    
    h_h1_tau (ms)                          : derived variable
    
    h_h1_qfrac                             : derived variable
    
    h_h2_steadyState_x                     : derived variable
    
    h_h2_timeCourse_V                      : derived variable
    
    h_h2_timeCourse_t (ms)                 : derived variable
    
    h_h2_inf                               : derived variable
    
    h_h2_tauUnscaled (ms)                  : derived variable
    
    h_h2_tau (ms)                          : derived variable
    
    h_h2_qfrac                             : derived variable
    
    h_q                                    : derived variable
    
    h_fcond                                : derived variable
    
    h_rateScale                            : derived variable
    
    conductanceScale                       : derived variable
    
    fopen0                                 : derived variable
    
    fopen                                  : derived variable
    
    g (uS)                                 : derived variable
    rate_m_q (/ms)
    rate_h_h1_q (/ms)
    rate_h_h2_q (/ms)
    
}

STATE {
    m_q  
    h_h1_q  
    h_h2_q  
    
}

INITIAL {
    ek = -107.0
    
    temperature = celsius + 273.15
    
    rates()
    rates() ? To ensure correct initialisation.
    
    m_q = m_inf
    
    h_h1_q = h_h1_inf
    
    h_h2_q = h_h2_inf
    
}

BREAKPOINT {
    
    SOLVE states METHOD cnexp
    
    ? DerivedVariable is based on path: conductanceScaling[*]/factor, on: Component(id=Kv2like type=ionChannelHH), from conductanceScaling; null
    ? Path not present in component, using factor: 1
    
    conductanceScale = 1 
    
    ? DerivedVariable is based on path: gates[*]/fcond, on: Component(id=Kv2like type=ionChannelHH), from gates; Component(id=m type=gateHHrates)
    ? multiply applied to all instances of fcond in: <gates> ([Component(id=m type=gateHHrates), Component(id=h type=gateFractional)]))
    fopen0 = m_fcond * h_fcond ? path based, prefix = 
    
    fopen = conductanceScale  *  fopen0 ? evaluable
    g = conductance  *  fopen ? evaluable
    gion = gmax * fopen 
    
    ik = gion * (v - ek)
    
}

DERIVATIVE states {
    rates()
    m_q' = rate_m_q 
    h_h1_q' = rate_h_h1_q 
    h_h2_q' = rate_h_h2_q 
    
}

PROCEDURE rates() {
    
    m_forwardRate_x = (v -  m_forwardRate_midpoint ) /  m_forwardRate_scale ? evaluable
    if (m_forwardRate_x  != 0)  { 
        m_forwardRate_r = m_forwardRate_rate  *  m_forwardRate_x  / (1 - exp(0 -  m_forwardRate_x )) ? evaluable cdv
    } else if (m_forwardRate_x  == 0)  { 
        m_forwardRate_r = m_forwardRate_rate ? evaluable cdv
    }
    
    m_reverseRate_r = m_reverseRate_rate  * exp((v -  m_reverseRate_midpoint )/ m_reverseRate_scale ) ? evaluable
    m_q10Settings_q10 = m_q10Settings_q10Factor ^((temperature -  m_q10Settings_experimentalTemp )/ m_q10Settings_TENDEGREES ) ? evaluable
    ? DerivedVariable is based on path: q10Settings[*]/q10, on: Component(id=m type=gateHHrates), from q10Settings; Component(id=null type=q10ExpTemp)
    ? multiply applied to all instances of q10 in: <q10Settings> ([Component(id=null type=q10ExpTemp)]))
    m_rateScale = m_q10Settings_q10 ? path based, prefix = m_
    
    ? DerivedVariable is based on path: forwardRate/r, on: Component(id=m type=gateHHrates), from forwardRate; Component(id=null type=HHExpLinearRate)
    m_alpha = m_forwardRate_r ? path based, prefix = m_
    
    ? DerivedVariable is based on path: reverseRate/r, on: Component(id=m type=gateHHrates), from reverseRate; Component(id=null type=HHExpRate)
    m_beta = m_reverseRate_r ? path based, prefix = m_
    
    m_fcond = m_q ^ m_instances ? evaluable
    m_inf = m_alpha /( m_alpha + m_beta ) ? evaluable
    m_tau = 1/(( m_alpha + m_beta ) *  m_rateScale ) ? evaluable
    h_q10Settings_q10 = h_q10Settings_q10Factor ^((temperature -  h_q10Settings_experimentalTemp )/ h_q10Settings_TENDEGREES ) ? evaluable
    h_h1_steadyState_x = h_h1_steadyState_rate  / (1 + exp(0 - (v -  h_h1_steadyState_midpoint )/ h_h1_steadyState_scale )) ? evaluable
    h_h1_timeCourse_V = v /  h_h1_timeCourse_VOLT_SCALE ? evaluable
    h_h1_timeCourse_t = ( h_h1_timeCourse_b0 +( h_h1_timeCourse_b11 + h_h1_timeCourse_b4 *( h_h1_timeCourse_V - h_h1_timeCourse_b5 ))*exp(-( h_h1_timeCourse_V - h_h1_timeCourse_b2 )*( h_h1_timeCourse_V - h_h1_timeCourse_b2 )/( h_h1_timeCourse_b3 * h_h1_timeCourse_b3 ))) *  h_h1_timeCourse_TIME_SCALE ? evaluable
    ? DerivedVariable is based on path: steadyState/x, on: Component(id=h1 type=subGate), from steadyState; Component(id=null type=HHSigmoidVariable)
    h_h1_inf = h_h1_steadyState_x ? path based, prefix = h_h1_
    
    ? DerivedVariable is based on path: timeCourse/t, on: Component(id=h1 type=subGate), from timeCourse; Component(id=null type=h1_tau)
    h_h1_tauUnscaled = h_h1_timeCourse_t ? path based, prefix = h_h1_
    
    h_h1_tau = h_h1_tauUnscaled  /  h_rateScale ? evaluable
    h_h1_qfrac = h_h1_q  *  h_h1_fractionalConductance ? evaluable
    h_h2_steadyState_x = h_h2_steadyState_rate  / (1 + exp(0 - (v -  h_h2_steadyState_midpoint )/ h_h2_steadyState_scale )) ? evaluable
    h_h2_timeCourse_V = v /  h_h2_timeCourse_VOLT_SCALE ? evaluable
    h_h2_timeCourse_t = ( h_h2_timeCourse_bb0 + h_h2_timeCourse_bb1 *exp(- h_h2_timeCourse_bb2 * h_h2_timeCourse_V )+ h_h2_timeCourse_bb3 *exp(- h_h2_timeCourse_bb4 * h_h2_timeCourse_V )) *  h_h2_timeCourse_TIME_SCALE ? evaluable
    ? DerivedVariable is based on path: steadyState/x, on: Component(id=h2 type=subGate), from steadyState; Component(id=null type=HHSigmoidVariable)
    h_h2_inf = h_h2_steadyState_x ? path based, prefix = h_h2_
    
    ? DerivedVariable is based on path: timeCourse/t, on: Component(id=h2 type=subGate), from timeCourse; Component(id=null type=h2_tau)
    h_h2_tauUnscaled = h_h2_timeCourse_t ? path based, prefix = h_h2_
    
    h_h2_tau = h_h2_tauUnscaled  /  h_rateScale ? evaluable
    h_h2_qfrac = h_h2_q  *  h_h2_fractionalConductance ? evaluable
    ? DerivedVariable is based on path: subGate[*]/qfrac, on: Component(id=h type=gateFractional), from subGate; Component(id=h1 type=subGate)
    ? add applied to all instances of qfrac in: <subGate> ([Component(id=h1 type=subGate), Component(id=h2 type=subGate)]))
    h_q = h_h1_qfrac + h_h2_qfrac ? path based, prefix = h_
    
    h_fcond = h_q ^ h_instances ? evaluable
    ? DerivedVariable is based on path: q10Settings[*]/q10, on: Component(id=h type=gateFractional), from q10Settings; Component(id=null type=q10ExpTemp)
    ? multiply applied to all instances of q10 in: <q10Settings> ([Component(id=null type=q10ExpTemp)]))
    h_rateScale = h_q10Settings_q10 ? path based, prefix = h_
    
    
     
    
     
    
     
    
     
    
     
    
     
    
     
    
     
    
     
    
     
    
     
    
     
    rate_m_q = ( m_inf  -  m_q ) /  m_tau ? Note units of all quantities used here need to be consistent!
    
     
    
     
    
     
    
     
    
     
    
     
    rate_h_h1_q = ( h_h1_inf  -  h_h1_q ) /  h_h1_tau ? Note units of all quantities used here need to be consistent!
    
     
    
     
    
     
    rate_h_h2_q = ( h_h2_inf  -  h_h2_q ) /  h_h2_tau ? Note units of all quantities used here need to be consistent!
    
     
    
     
    
     
    
}

