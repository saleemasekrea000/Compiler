; ModuleID = 'KSS'
source_filename = "KSS"

@0 = private unnamed_addr constant [4 x i8] c"%f\0A\00", align 1

define void @main() {
entry:
  %tempF = alloca double, align 8
  store double 1.000000e+02, double* %tempF, align 8
  %tempC = alloca double, align 8
  %tempF1 = load double, double* %tempF, align 8
  %fahrenheit_to_celsius_call = call double @fahrenheit_to_celsius(double %tempF1)
  store double %fahrenheit_to_celsius_call, double* %tempC, align 8
  %tempC2 = load double, double* %tempC, align 8
  %tempC3 = load double, double* %tempC, align 8
  %0 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([4 x i8], [4 x i8]* @0, i32 0, i32 0), double %tempC2)
  ret void
}

define double @fahrenheit_to_celsius(double %0) {
entry:
  %fahrenheit = alloca double, align 8
  store double %0, double* %fahrenheit, align 8
  %celsius = alloca double, align 8
  store double 0.000000e+00, double* %celsius, align 8
  %fahrenheit1 = load double, double* %fahrenheit, align 8
  %realSub = fsub double %fahrenheit1, 3.200000e+01
  %realMul = fmul double %realSub, 5.000000e+00
  %realDiv = fdiv double %realMul, 9.000000e+00
  %fahrenheit2 = load double, double* %fahrenheit, align 8
  %realSub3 = fsub double %fahrenheit2, 3.200000e+01
  %realMul4 = fmul double %realSub3, 5.000000e+00
  %realDiv5 = fdiv double %realMul4, 9.000000e+00
  store double %realDiv, double* %celsius, align 8
  %celsius6 = load double, double* %celsius, align 8
  ret double %celsius6
}

declare i32 @printf(i8*, ...)
