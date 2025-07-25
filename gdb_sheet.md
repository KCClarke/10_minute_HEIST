# Compile with debug info
gcc -g test.c -o test

# Start GDB
gdb ./test

# Set a breakpoint at main
break main

# Run the program
run

# Step over the next line
next

# Step into a function call
step

# Print a variable
print x

# Show the call stack
backtrace

# Continue to the next breakpoint or end
continue

# Quit GDB
quit

# Enter GDB TUI mode (text user interface)
# In GDB, press:
Ctrl + X, then A

# Useful layout commands:
layout src     # Show source code only
layout asm     # Show assembly only
layout split   # Show source + assembly
layout regs    # Show registers

# Move to next layout
layout next

# Exit TUI mode:
Ctrl + X, then A   # (toggles it off)

# let me know what my breakpoints are
info break

# delete my breakpoints
delete breakpoints

# break a function in a different file
break my_func.c:5
