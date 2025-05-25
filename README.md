- Project for COMP354 @ UNIC, Spring 2025 Semester.
- Implementing the Programming Project at the end of Chapter 5 in the Operating
 Systems Concepts 10ed, Silberschatz, Galvin, Gagne
- Based on source code from https://github.com/greggagne/osc10e/tree/master/ch5/project/posix
- Some files are used as-is, some are updated for CPP.

### Building and Running

1. Create and enter the build directory:
```bash
mkdir build
cd build
```
2. Configure and build all executables:

```bash
cmake ..
cmake --build .
```
3. Run the schedulers with the sample input:

```bash
./fcfs ../inputs/schedule.txt
./sjf ../inputs/schedule.txt
./rr ../inputs/schedule.txt
./priority ../inputs/schedule.txt
./priority_rr ../inputs/schedule.txt
```