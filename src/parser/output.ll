; ModuleID = 'KSS'
source_filename = "KSS"

define void @main() {
entry:
  %ans1 = alloca i32, align 4
  store i32 28, i32* %ans1, align 4
}
