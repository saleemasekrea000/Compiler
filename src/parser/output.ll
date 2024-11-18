; ModuleID = 'KSS'
source_filename = "KSS"

@.str = private constant [4 x i8] c"%d\0A\00" ; Format string for printf: "%d\n"

declare i32 @printf(i8*, ...) ; Declare the external printf function

define void @main() {
entry:
  %x = alloca i32, align 4                  ; Allocate space for x
  store i32 5, i32* %x, align 4             ; Initialize x with 5
  br i1 true, label %if_false, label %if_true ; Conditional branch (always true)

if_true:                                    ; preds = %entry
  store i32 1, i32* %x, align 4             ; Store 1 in x
  br label %end_if                          ; Jump to end_if

if_false:                                   ; preds = %entry
  store i32 2, i32* %x, align 4             ; Store 2 in x
  br label %end_if                          ; Jump to end_if

end_if:                                     ; preds = %if_false, %if_true
  %val = load i32, i32* %x, align 4         ; Load the value of x
  %fmt_ptr = bitcast [4 x i8]* @.str to i8* ; Cast format string to i8*
  call i32 (i8*, ...) @printf(i8* %fmt_ptr, i32 %val) ; Call printf with x
  ret void                                  ; Return from main
}
