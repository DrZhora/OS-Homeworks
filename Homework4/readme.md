# Linking and Executable Report

## 1. Symbol Resolution

1. `main.o` defines `main (T)` but references `square (U)` and `printf (U)`.
2. `math_utils.o` defines `square (T)`.
3. In the final executable `square_prog`, both `main (T)` and `square (T)` are defined, and external library functions (like `printf`) are resolved via **PLT/GOT** (e.g., `printf@GLIBC_2.2.5`).
4. Object files only have raw function implementations; calls to undefined symbols are **placeholders**.
5. The executable has all symbols resolved, plus **dynamic linking infrastructure**.

---

## 2. Feature Comparison: Object Files vs Executables

| Feature                  | Object Files                     | Executable                           |
|---------------------------|---------------------------------|-------------------------------------|
| **Code**                  | `.text` only for that module    | `.text` combined for all modules    |
| **Data**                  | `.data` and `.bss` per module   | `.data` and `.bss` combined         |
| **Symbols**               | `nm` shows undefined placeholders | All symbols resolved                 |
| **Relocations**           | `.rela.*` sections for linker   | Relocations applied                  |
| **Dynamic Linking**       | Not present                     | PLT/GOT for library calls           |
| **Entry Point**           | None                            | `_start` address defined             |
| **Initialization/Finalization** | Not present                 | `_init`, `_fini`, constructors      |

---

## 3. Role of the Linking Process

### Combining Object Files
The linker takes `main.o` and `math_utils.o`, resolves references like `main` calling `square`, and assigns final addresses for functions and global variables.

### Resolving Symbols
Undefined symbols in object files (`U`) are resolved to definitions (`T`) in other object files or libraries (e.g., `printf` in `libc`).

### Generating Executable
- Adds **dynamic linking sections** (PLT/GOT) for runtime library calls.
- Adds **initialization/finalization routines** (`_init`, `_fini`) and sets the **entry point** (`_start`).

### Relocations
Relocation entries in object files (`.rela.text`) guide the linker in patching addresses to final memory locations.

### Final ELF Type
Converts multiple **REL (relocatable) files** into a runnable **DYN (PIE) executable**.

---

## 4. Summary of Tools

- **nm**: Shows symbol definitions (`T`) and references (`U`). Useful to check which functions are defined in each object file and what is unresolved.
- **objdump**: Shows assembly instructions; can see actual call instructions, function code, and linking placeholders.
- **readelf**: Shows ELF structure, headers, and section info. Provides insight into memory layout and how object files are organized versus the executable.
