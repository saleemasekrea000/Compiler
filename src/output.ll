; ModuleID = 'KSS'
source_filename = "KSS"

%point = type { i32, i32 }

@0 = private unnamed_addr constant [4 x i8] c"%d\0A\00", align 1

define void @main() {
entry:
  %point2 = alloca %point, align 8
  %x = getelementptr inbounds %point, %point* %point2, i32 0, i32 0
  store i32 0, i32* %x, align 4
  %y = getelementptr inbounds %point, %point* %point2, i32 0, i32 1
  store i32 0, i32* %y, align 4
  %fieldPtr = getelementptr inbounds %point, %point* %point2, i32 0, i32 0
  store i32 1, i32* %fieldPtr, align 4
  %fieldPtr1 = getelementptr inbounds %point, %point* %point2, i32 0, i32 1
  store i32 2, i32* %fieldPtr1, align 4
  %point3 = alloca %point, align 8
  %x2 = getelementptr inbounds %point, %point* %point3, i32 0, i32 0
  store i32 0, i32* %x2, align 4
  %y3 = getelementptr inbounds %point, %point* %point3, i32 0, i32 1
  store i32 0, i32* %y3, align 4
  %point24 = load %point, %point* %point2, align 4
  %Factorial_call = call %point @Factorial(%point %point24)
  store %point %Factorial_call, %point* %point3, align 4
  %fieldPtr5 = getelementptr inbounds %point, %point* %point3, i32 0, i32 1
  %fieldValue = load i32, i32* %fieldPtr5, align 4
  %0 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([4 x i8], [4 x i8]* @0, i32 0, i32 0), i32 %fieldValue)
  ret void
}

define %point @Factorial(%point %0) {
entry:
  %point1 = alloca %point, align 8
  store %point %0, %point* %point1, align 4
  %point11 = load %point, %point* %point1, align 4
  ret %point %point11
}

declare i32 @printf(i8*, ...)
