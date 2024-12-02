; ModuleID = 'KSS'
source_filename = "KSS"

@0 = private unnamed_addr constant [4 x i8] c"%d\0A\00", align 1

define void @main() {
entry:
  %malloc_call = call i8* @malloc(i64 80000)
  %array_ptr = bitcast i8* %malloc_call to i32*
  %elementPointer = getelementptr i32, i32* %array_ptr, i32 202
  store i32 1, i32* %elementPointer, align 4
  %elementPointer1 = getelementptr i32, i32* %array_ptr, i32 201
  store i32 1, i32* %elementPointer1, align 4
  %elementPointer2 = getelementptr i32, i32* %array_ptr, i32 1005
  %loadArrayElement = load i32, i32* %elementPointer2, align 4
  %elementPointer3 = getelementptr i32, i32* %array_ptr, i32 1005
  %loadArrayElement4 = load i32, i32* %elementPointer3, align 4
  %0 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([4 x i8], [4 x i8]* @0, i32 0, i32 0), i32 %loadArrayElement)
  ret void
}

declare i8* @malloc(i64)

declare i32 @printf(i8*, ...)
