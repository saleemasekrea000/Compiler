; ModuleID = 'KSS'
source_filename = "KSS"

@0 = private unnamed_addr constant [4 x i8] c"%d\0A\00", align 1

define void @main() {
entry:
  %"point point1 x" = alloca i32, align 4
  store i32 9, i32* %"point point1 x", align 4
  %"point point1 y" = alloca i32, align 4
  store i32 4, i32* %"point point1 y", align 4
  %"point1 y" = load i32, i32* %"point point1 y", align 4
  store i32 %"point1 y", i32* %"point point1 x", align 4
  %"point1 x" = load i32, i32* %"point point1 x", align 4
  %0 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([4 x i8], [4 x i8]* @0, i32 0, i32 0), i32 %"point1 x")
  ret void
}

declare i32 @printf(i8*, ...)
