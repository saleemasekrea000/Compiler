; ModuleID = 'KSS'
source_filename = "KSS"

define void @main() {
entry:
  %Factorial_call = call i32 @Factorial(i32 5)
  ret void
}

define i32 @Factorial(i32 %0) {
entry:
  %n = alloca i32, align 4
  store i32 %0, i32* %n, align 4
  %n1 = load i32, i32* %n, align 4
  ret i32 %n1
  ret i32 0
}
