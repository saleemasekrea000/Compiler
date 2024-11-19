; ModuleID = 'KSS'
source_filename = "KSS"

@0 = private unnamed_addr constant [4 x i8] c"%d\0A\00", align 1

define void @main() {
entry:
  %Factorial_call = call i32 @Factorial(i32 5)
  %0 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([4 x i8], [4 x i8]* @0, i32 0, i32 0), i32 %Factorial_call)
  ret void
}

define i32 @Factorial(i32 %0) {
entry:
  %n = alloca i32, align 4
  store i32 %0, i32* %n, align 4
  %ans = alloca i32, align 4
  store i32 1, i32* %ans, align 4
  br label %loop_cond

loop_cond:                                        ; preds = %loop_body, %entry
  %n1 = load i32, i32* %n, align 4
  %gt = icmp sgt i32 %n1, 0
  br i1 %gt, label %loop_body, label %loop_exit

loop_body:                                        ; preds = %loop_cond
  %ans2 = load i32, i32* %ans, align 4
  %n3 = load i32, i32* %n, align 4
  %mul = mul i32 %ans2, %n3
  store i32 %mul, i32* %ans, align 4
  %n4 = load i32, i32* %n, align 4
  %diff = sub i32 %n4, 1
  store i32 %diff, i32* %n, align 4
  br label %loop_cond

loop_exit:                                        ; preds = %loop_cond
  %ans5 = load i32, i32* %ans, align 4
  ret i32 %ans5
}

declare i32 @printf(i8*, ...)
