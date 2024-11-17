; ModuleID = 'my cool jit'
source_filename = "my cool jit"

define void @myFunction() {
entry:
  %ans = alloca i32, align 4
  store i32 6, i32* %ans, align 4
}
