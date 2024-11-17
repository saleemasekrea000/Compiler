; ModuleID = 'KSS'
source_filename = "KSS"

define void @main() {
entry:
  %ans = alloca i32, align 4
  store i32 1, i32* %ans, align 4
}
