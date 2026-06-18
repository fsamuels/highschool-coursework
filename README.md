# Davidson County Community College — C/C++ Coursework (circa 1999)

A collection of C and C++ programs written for **CSC 134** (Introduction to C++)
at Davidson County Community College, completed while in high school around 1999.
The work ranges from introductory procedural exercises through object-oriented
class design, a bytecode virtual machine, and a few hardware-oriented projects.

The directory layout mirrors the author's account on the college's Linux/AFS
server (`linux.davidson.cc.nc.us`). Two areas hold the work:

- `linux.davidson.cc.nc.us/samuelsf/` — coursework organized by textbook chapter,
  plus the final project and some experiments.
- `linux.davidson.cc.nc.us/student/public/` — the author's public AFS folder
  containing textbook problem solutions, reusable classes, and larger projects.
  (Some files here are instructor- or textbook-provided framework code that the
  projects build on; see notes below.)

Everything is written for late-1990s C++ (pre-standard `iostream.h`-era idioms,
custom collection/string headers) and compiled in a Unix environment.

## Chapter Exercises (`samuelsf/Ch4`–`Ch10`)

- **What it is:** Per-chapter exercise sets (`4B.CPP`, `5A.CPP`, …) following a
  C++ textbook, progressing from basics to classes and file I/O.
- **What it does:**
  - **Ch4–Ch5:** Procedural fundamentals — I/O, arithmetic, string/name
    formatting, user-defined functions.
  - **Ch6–Ch8:** Introduction to classes and objects, with reusable
    class/header pairs: `COUNTER` (bounded counter), `BACCOUNT` (bank account
    with deposit/withdraw/transactions), `GRID` (2D directional-movement grid),
    `LIBBOOK` (library book borrow/return), `QUAD` (quadratic solver), and
    `ELEVATOR` (elevator floor control).
  - **Ch9:** File I/O and data analysis — wind-speed statistics (`WIND.DAT`)
    and payroll processing (`payroll.data`, `PAYROLL.RPT`).
  - **Ch10:** Final small exercises.
- **Tech:** C++ (classes, header/implementation pairs, file streams).

## SimpleTron (`samuelsf/SimpleTron`)

- **What it is:** The course's final project (April 1999), a software simulator
  for a small fictional computer ("Simpletron") and its machine language (SML).
- **What it does:** Implements a 100-word memory machine with an accumulator and
  instruction register. It loads `.SML` bytecode programs (memory-address /
  instruction pairs) and executes an instruction set covering I/O
  (READ/WRITE), memory (LOAD/STORE), arithmetic (ADD/SUBTRACT/MULTIPLY/DIVIDE),
  and control flow (BRANCH/BRANCHNEG/BRANCHZERO/HALT). On errors it prints a
  core dump of registers and memory. Sample programs are included
  (`DATA1.SML`, `DATA2.SML`, `DIVIDE.SML`, `CRASH.SML`, `JUNKDATA.SML`).
- **Tech:** C++ (`<fstream>`, `<string>`, a custom `VECTOR` header).

## Experiments (`samuelsf/Stuff`)

- **What it is:** Miscellaneous, mostly unfinished side programs outside the
  graded coursework.
- **What it does:**
  - `hexbinary.cpp` — hex/binary conversion (partial).
  - `test.cpp` — small file-read test that invokes shell commands via `system()`.
  - `scanner.c` — a TCP port scanner using C sockets.
  - `scan.cpp` — a telnet-connection wrapper stub (incomplete).
- **Tech:** C and C++; BSD-style networking sockets.

## Textbook Problem Solutions (`student/public/P###.CPP`)

- **What it is:** ~160 numbered solutions (`P017.CPP`–`P771.CPP`) to textbook
  problems, plus matching `TEST*.CPP` driver/test files.
- **What it does:** Spans the full course: basic I/O and arithmetic, selection
  and loops, functions with pre/post conditions, arrays and file I/O, and later
  templates, iterators, and STL-style containers.
- **Tech:** C++, exercising the custom collection/utility headers below.

## CD Jukebox System (`student/public`: `CD`, `CDPLAYER`, `CDCOLLEC`, `CDSTUFF`, `CDDEFS`, `JUKEBOX`, `TRACK`, `TRACKSEL`, `CARDREAD`)

- **What it is:** A larger object-oriented project modeling a card-activated CD
  jukebox that controls a real CD player.
- **What it does:** `CD`/`TRACK` model discs and their tracks; `CDCOLLEC` holds
  the collection; `CDPLAYER` drives a Kenwood DP-M7740 player over an infrared
  link; `TRACKSEL` provides track-selection UI; `CARDREAD` handles student-ID
  card swipes; and `JUKEBOX` composes these into the full system. Collection data
  lives in `CD.DAT`/`ONECD.DAT`/`BOOK.DAT`.
- **Tech:** C++ (composition, iterators, vectors) with hardware/IR control.

## Infrared Remote Control (`student/public`: `IRDEV`, `IRUTILS`, `SITE`)

- **What it is:** Low-level infrared signal generation used by the jukebox/CD
  player, plus a related reporting program.
- **What it does:** `IRDEV` reads device signal definitions from `IRINFO.DAT` and
  emits IR codes to the PC parallel port (including inline x86 assembly in
  `IRUTILS`). `SITE` is an HOV/carpool-lane reporting program built on the
  matrix class.
- **Tech:** C++ with embedded Pentium-era assembly and parallel-port I/O.

## Library Lending System (`student/public`: `LIBBOOK`, `LENDABLE`, `LENDLIST`, `LLIST`)

- **What it is:** An OOP library/media lending model.
- **What it does:** `LENDABLE` is an abstract base for lendable items (books,
  videos) with type-specific due dates and late fees; `LENDLIST` manages a
  collection of items with persistent storage (`book.dat`, `video.dat`,
  `cdrom.dat`); `LIBBOOK` is the book class; `LLIST` is a templated linked list.
- **Tech:** C++ (inheritance/polymorphism, templates, file persistence).

## Reusable Classes and Data Structures (`student/public`)

- **What it is:** Standalone classes used by exercises and projects.
- **What it does:**
  - **Numeric:** `QUAD` (quadratic solver), `LTCOMPLX`/`COMPLEX` (complex
    numbers), `MATRIX`/`MAT2` (2D table templates).
  - **Collections:** `GENBAG`/`BAG` (bag), `SET` (unique-element set),
    `MYARRAY` (bounds-checked dynamic array), `LTSTRING` (lightweight string).
  - **Domain models:** `BACCOUNT` (bank account), `WEEKEMP` (weekly-payroll
    employee), `STUDENT` (GPA/standing), `RETAIL` (tax/change), `QUIZDATA`
    (quiz-score statistics), `GRID`, `COUNTER`, `ELEVATOR`, `WITHDEST`
    (destructor demo).
  - **`DATE`:** Owen Astrachan's Gregorian-calendar `Date` class (from *A
    Computer Science Tapestry*), used for lending due dates.
- **Tech:** C++ (operator overloading, templates, iterator patterns).

## Custom Standard-Library Headers (`student/public`)

- **What it is:** Local, course-provided substitutes for standard headers,
  predating widespread standard-library support.
- **What it does:** Provides drop-in headers such as `IOSTREAM`, `VECTOR`,
  `STRING`, `BOOL`, `CMATH.H`, `CSTDIO`, `CSTDLIB.H`, `CASSERT.H`, and similar,
  which the exercises and projects include.
- **Tech:** C++ wrappers over the C standard library and early C++ facilities.

## Data Files

Sample/input data used by the programs, including `BANK.DAT` (accounts),
`QUIZ.DAT` (quiz scores), `IRINFO.DAT` (IR signal definitions), `WIND.DAT`
(wind speeds), payroll data, and the `.SML` Simpletron programs.

## Notes / Ambiguities

- **`samuelsf/` vs. `student/public/`:** These are two areas of the *same*
  author's account (the AFS include paths reference the user `dfsamuel`), not two
  separate authors. `samuelsf/` holds chapter work and the final project;
  `student/public/` holds problem solutions, reusable classes, and the larger
  projects.
- **Mixed authorship in `student/public/`:** Some files are clearly
  textbook/instructor framework code (e.g., the `DATE` class and several
  standard-library substitute headers) rather than original work. They are
  included because the exercises depend on them.
- **CD jukebox / IR project scope:** It is unclear whether the jukebox, CD
  player, and IR-control code were part of CSC 134 or a separate/advanced
  effort; they are noticeably more involved (and hardware-specific) than the
  chapter exercises.
- **`Stuff/` programs** are experiments, several incomplete, and not part of the
  graded coursework.
