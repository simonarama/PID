#include "PID.h"

using namespace std;

/*
* TODO: Complete the PID class.
*/
//David Simon Lecture code and dsilver video, modified with optimization of Kp, Ki, Kd constants
PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd) {
    this->Kp = Kp;
    this->Ki = Ki;
    this->Kd = Kd;
    //cte = 0.0;
    p_error = 0.0;
    i_error = 0.0;
    d_error = 0.0;
    //steer_value = 0.0;
    //TotalError() = 0.0;
}

void PID::UpdateError(double cte) {
    d_error = cte - p_error;
    i_error +=cte;
    p_error = cte;
}

double PID::TotalError() {
	//Ki attempts for over 80mph
	if (p_error > 3.0){
		Ki = -0.0015;}
	else if (p_error < -3.0){
		Ki = -0.0015;}
	else{Ki = 0.0;}
	//Ki = -.00001 * p_error; 
	return Kp * p_error + Ki * i_error + Kd * d_error;
}

