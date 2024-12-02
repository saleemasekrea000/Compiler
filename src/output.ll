; ModuleID = 'KSS'
source_filename = "KSS"

%circle = type { %point, i32 }
%point = type { i32, i32 }

@0 = private unnamed_addr constant [4 x i8] c"%d\0A\00", align 1

define void @main() {
entry:
  %cir = alloca %circle, align 8
  %center = getelementptr inbounds %circle, %circle* %cir, i32 0, i32 0
  %x = getelementptr inbounds %point, %point* %center, i32 0, i32 0
  store i32 0, i32* %x, align 4
  %y = getelementptr inbounds %point, %point* %center, i32 0, i32 1
  store i32 0, i32* %y, align 4
  %radius = getelementptr inbounds %circle, %circle* %cir, i32 0, i32 1
  store i32 0, i32* %radius, align 4
  %fieldPtr = getelementptr inbounds %circle, %circle* %cir, i32 0, i32 0
  %fieldPtr1 = getelementptr inbounds %point, %point* %fieldPtr, i32 0, i32 0
  store i32 1, i32* %fieldPtr1, align 4
  %fieldPtr2 = getelementptr inbounds %circle, %circle* %cir, i32 0, i32 0
  %fieldPtr3 = getelementptr inbounds %point, %point* %fieldPtr2, i32 0, i32 1
  store i32 2, i32* %fieldPtr3, align 4
  %cir4 = load %circle, %circle* %cir, align 4
  %calcDistance_call = call i32 @calcDistance(%circle %cir4)
  %cir5 = load %circle, %circle* %cir, align 4
  %calcDistance_call6 = call i32 @calcDistance(%circle %cir5)
  %0 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([4 x i8], [4 x i8]* @0, i32 0, i32 0), i32 %calcDistance_call)
  ret void
}

define i32 @calcDistance(%circle %0) {
entry:
  %curCir = alloca %circle, align 8
  store %circle %0, %circle* %curCir, align 4
  %fieldPtr = getelementptr inbounds %circle, %circle* %curCir, i32 0, i32 0
  %fieldPtr1 = getelementptr inbounds %point, %point* %fieldPtr, i32 0, i32 0
  %fieldValue = load i32, i32* %fieldPtr1, align 4
  %fieldPtr2 = getelementptr inbounds %circle, %circle* %curCir, i32 0, i32 0
  %fieldPtr3 = getelementptr inbounds %point, %point* %fieldPtr2, i32 0, i32 0
  %fieldValue4 = load i32, i32* %fieldPtr3, align 4
  %intMul = mul i32 %fieldValue, %fieldValue4
  %fieldPtr5 = getelementptr inbounds %circle, %circle* %curCir, i32 0, i32 0
  %fieldPtr6 = getelementptr inbounds %point, %point* %fieldPtr5, i32 0, i32 1
  %fieldValue7 = load i32, i32* %fieldPtr6, align 4
  %fieldPtr8 = getelementptr inbounds %circle, %circle* %curCir, i32 0, i32 0
  %fieldPtr9 = getelementptr inbounds %point, %point* %fieldPtr8, i32 0, i32 1
  %fieldValue10 = load i32, i32* %fieldPtr9, align 4
  %intMul11 = mul i32 %fieldValue7, %fieldValue10
  %intAdd = add i32 %intMul, %intMul11
  ret i32 %intAdd
}

declare i32 @printf(i8*, ...)
