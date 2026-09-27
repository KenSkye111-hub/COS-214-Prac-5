# CampusGuard — build image
# Uses Ubuntu so g++, make, and valgrind are all standard apt packages.
# The build happens at image-build time (docker compose up --build shows the compile output)

FROM ubuntu:22.04

# Avoid interactive prompts during apt installs
ENV DEBIAN_FRONTEND=noninteractive

RUN apt-get update && apt-get install -y --no-install-recommends \
    g++ \
    make \
    valgrind \
    gdb \
    && rm -rf /var/lib/apt/lists/*

WORKDIR /app

# Copy the whole project 
COPY . .

# Compile now (at image build time)
RUN make build

# Default action: run the application
CMD ["make"]