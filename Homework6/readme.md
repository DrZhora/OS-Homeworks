## Homework 6 — Notes on alignment, struct padding and packing

This document summarizes the three tasks (data alignment, struct padding, and packing).

### Task 1 — Basic data alignment

- On a typical x86_64 system each variable's address is a multiple of its alignment: `char` aligns to 1, `short` to 2, `int` to 4 and `double` to 8. When you declare several variables in sequence the compiler inserts padding bytes so each variable begins at an address satisfying its alignment. As a result you will often see small gaps (padding) before larger types when smaller types are declared earlier. Ordering fields from largest to smallest alignment reduces internal padding and therefore the overall memory footprint.

- Typical sizes and alignment on a common x86_64 system:
  - `char`: size=1, alignment=1
  - `short`: size=2, alignment=2
  - `int`: size=4, alignment=4
  - `double`: size=8, alignment=8

### Task 2 — Struct padding and field order

Given these two structs:

```c
struct S1 { char a; int b; double c; };
struct S2 { double c; int b; char a; };
```

- Typical layout and sizes on x86_64 (gcc/clang):
  - `sizeof(struct S1) == 16`
    - offsets: `a=0`, `b=4` (3 bytes padding after `a`), `c=8`
  - `sizeof(struct S2) == 16`
    - offsets: `c=0`, `b=8`, `a=12` (3 bytes trailing padding to make total size a multiple of 8)

- Does changing order change size?
  - Yes — it can. In these particular examples both end up 16 bytes, but the padding is distributed differently (internal padding in `S1`, trailing padding in `S2`). In general, ordering members from largest alignment to smallest (e.g. `double`, `int`, `char`) minimizes internal padding and often produces the smallest `sizeof`.

- Why padding exists:
  - Each field must start at an address satisfying its alignment. The compiler inserts padding between fields (and possibly at the end of the struct) so the struct itself satisfies the alignment requirement of its most strictly aligned member.

### Task 3 — Effect of `#pragma pack(1)` (packing)

- What `#pragma pack(1)` does:
  - It reduces the alignment requirement of the struct members to 1 byte for the duration of the pragma. In effect, the compiler will not insert padding between members (members are tightly packed).

- Example with the same fields `char a; int b; double c;`:
  - Unpacked (natural alignment): `sizeof == 16`, offsets typically `a=0`, `b=4`, `c=8` (padding inserted to align `b` and `c`).
  - Packed (`#pragma pack(push,1)` / `#pragma pack(pop)`): `sizeof == 13`, offsets `a=0`, `b=1`, `c=5` (no padding between fields; total bytes = 1 + 4 + 8 = 13).

- Consequences of packing:
  - Pros: reduces memory footprint and produces a compact, predictable layout useful for on-disk or network formats.
  - Cons: access to unaligned members can be slower; on some architectures unaligned accesses can cause hardware faults. Packed structs may also break ABI expectations and should be used only when necessary.



