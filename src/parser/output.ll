; ModuleID = 'KSS'
source_filename = "KSS"

@0 = private unnamed_addr constant [4 x i8] c"%d\0A\00", align 1

define void @main() {
entry:
  %x = alloca i32, align 4
  store i32 1, i32* %x, align 4
  br label %loop_init

loop_init:                                        ; preds = %entry
  %i = alloca i32, align 4
  store i32 5, i32* %i, align 4
  br label %loop_cond

loop_cond:                                        ; preds = %loop_body, %loop_init
  %current_iter = load i32, i32* %i, align 4
  %loop_cond1 = icmp sge i32 %current_iter, 1
  br i1 %loop_cond1, label %loop_body, label %loop_exit

loop_body:                                        ; preds = %loop_cond
  %i2 = load i32, i32* %i, align 4
  %0 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([4 x i8], [4 x i8]* @0, i32 0, i32 0), i32 %i2)
  %decrement = add i32 %current_iter, -1
  store i32 %decrement, i32* %i, align 4
  br label %loop_cond

loop_exit:                                        ; preds = %loop_cond
  ret void
}

declare i32 @printf(i8*, ...)
