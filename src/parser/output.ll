; ModuleID = 'KSS'
source_filename = "KSS"

define void @main() {
entry:
  %x = alloca i32, align 4
  store i32 5, i32* %x, align 4
  %ans1 = alloca i32, align 4
  %x1 = load i32, i32* %x, align 4
  %sum = add i32 %x1, 5
  store i32 %sum, i32 %x1, align 4
  store i32 %sum, i32* %ans1, align 4
  ret void
}
