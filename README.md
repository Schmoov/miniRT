# MiniRT - My First RayTracer with MiniLibX

## Compilation Instructions

To compile the project, follow these steps:

1. Ensure you have the required dependencies installed:
   - `gcc` (GNU Compiler Collection)
   - `make` (Build automation tool)
   - MiniLibX library (for rendering)

2. Navigate to the project directory:
   ```bash
   cd /home/hsoysal/Documents/test
   ```

3. Compile the project using `make`:
   ```bash
   make
   ```

4. The executable will be created in the project directory. Run it with:
   ```bash
   ./miniRT <scene_file.rt>
   ```

## Example Usage

```bash
./miniRT example_scene.rt
```

## Cleaning Up

To clean up compiled files, run:
```bash
make clean
```

To remove all compiled files and the executable, run:
```bash
make fclean
```

To recompile the project from scratch, run:
```bash
make re
```
