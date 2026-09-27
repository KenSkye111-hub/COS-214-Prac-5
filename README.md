# CampusGuard — Build & Run

## Requirements
- Docker and Docker Compose installed

## Running the application

From the project root:
```
docker compose up --build
```

This builds the image, then starts the container, which runs
`make` and immediately runs `./campusguard`, printing the full demo scenario straight to the terminal.


To force a full rebuild (e.g. after code changes)
```
docker compose up --build
```

## Getting Valgrind evidence

Run the app under Valgrind inside the same container image

```
docker compose run --rm campusguard make valgrind
```

This uses the `valgrind` target already defined in the Makefile.

## Getting a GDB session going

```
docker compose run --rm campusguard gdb ./campusguard
```

This drops you into an interactive GDB prompt inside the container.
From here, standard GDB commands work as normal — e.g. `break`, `run`,
`next`, `print`.

## Cleaning up
If you want to clean object files before rebuilding locally
```
docker compose run --rm campusguard make clean
```