; ModuleID = 'KSS'
source_filename = "KSS"

@0 = private unnamed_addr constant [4 x i8] c"%d\0A\00", align 1

define void @main() {
entry:
  %malloc_call = call i8* @malloc(i64 400)
  %array_ptr = bitcast i8* %malloc_call to i32*
  %0 = getelementptr i32, i32* %array_ptr, i32 1
  store i32 1, i32* %0, align 4
  %1 = getelementptr i32, i32* %array_ptr, i32 2
  store i32 3, i32* %1, align 4
  %x = alloca i32, align 4
  store i32 0, i32* %x, align 4
  %2 = getelementptr i32, i32* %array_ptr, i32 2
  %a = load i32, i32* %2, align 4
  %3 = getelementptr i32, i32* %array_ptr, i32 1
  %a1 = load i32, i32* %3, align 4
  %sum = add i32 %a, %a1
  store i32 %sum, i32* %x, align 4
  %x2 = load i32, i32* %x, align 4
  %4 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([4 x i8], [4 x i8]* @0, i32 0, i32 0), i32 %x2)
  ret void
}

declare i8* @malloc(i64)

declare i32 @printf(i8*, ...)
