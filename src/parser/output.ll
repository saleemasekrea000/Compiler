; ModuleID = 'KSS'
source_filename = "KSS"

@0 = private unnamed_addr constant [4 x i8] c"%d\0A\00", align 1

define void @main() {
entry:
  %ans = alloca i32, align 4
  store i32 1, i32* %ans, align 4
  %n = alloca i32, align 4
  store i32 5, i32* %n, align 4
  %n1 = load i32, i32* %n, align 4
  %0 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([4 x i8], [4 x i8]* @0, i32 0, i32 0), i32 %n1)
  ret void
}

declare i32 @printf(i8*, ...)
