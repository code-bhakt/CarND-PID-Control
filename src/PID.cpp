#include "PID.h"

#include <iostream>
/**
 * TODO: Complete the PID class. You may add any additional desired functions.
 */
double tau_p;
double tau_i;
double tau_d;


PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp_, double Ki_, double Kd_) {
  /**
   * TODO: Initialize PID coefficients (and errors, if needed)
   */
  tau_p = Kp_;
  tau_i = Ki_;
  tau_d = Kd_;
  p_error = 0.0;
  
}

void PID::UpdateError(double cte) {
  /**
   * TODO: Update PID errors based on cte.
   */
  // if(cte < min_cte){
  //   for(int i = 0; i < 3; i++){
      
  //   }
  // }
  
  
  d_error = cte - p_error;
  p_error = cte;
  i_error += cte;
  
  
  std::cout << "p_error: " << p_error << " i_error: " << i_error <<" d_error" << d_error
                    << std::endl;
}

double PID::TotalError() {
  /**
   * TODO: Calculate and return the total error
   */
  return (-tau_p * p_error) - tau_d * d_error - tau_i * i_error ;  // TODO: Add your total error calc here!
}
