; ModuleID = 'KSS'
source_filename = "KSS"

@.str = private constant [4 x i8] c"%d\0A\00"  ; Format string for printf: "%d\n"

declare i32 @printf(i8*, ...)                  ; Declare the external printf function
define void @main() {
entry:
  %ans = alloca i32, align 4
  store i32 1, i32* %ans, align 4
  %n = alloca i32, align 4
  store i32 5, i32* %n, align 4
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

loop_exit:                                     ; preds = %loop_cond
  %final_ans = load i32, i32* %ans, align 4    ; Load final value of ans
  %fmt_ptr = bitcast [4 x i8]* @.str to i8*    ; Cast format string to i8*
  call i32 (i8*, ...) @printf(i8* %fmt_ptr, i32 %final_ans) ; Print ans
  ret void                                     ; Return from main
}