# You can find the new timestamped tags here: https://hub.docker.com/r/gitpod/workspace-base/tags
FROM ubuntu:latest

RUN apt-get update && apt-get install -yq \
    git \
    git-lfs \
    gcc \
    cmake \
    musl-dev \
    make \
    sudo \
    && apt-get clean && rm -rf /var/lib/apt/lists/* /tmp/*

WORKDIR /lingua-franca/HelloWorld
COPY src-gen/* src-gen
RUN echo $(ls -1 ./src-gen)
RUN set -ex && \
mkdir bin && \
cmake -DLF_REACTION_GRAPH_BREADTH=1 -DLF_THREADED=1 -DNUMBER_OF_WORKERS=0 -DSCHEDULER=NP -DLOG_LEVEL=2 -S src-gen -B bin && \
cd bin && \
make all

# Create the gitpod user. UID must be 33333.
RUN useradd -l -u 33333 -G sudo -md /home/gitpod -s /bin/bash -p gitpod gitpod
USER gitpod

RUN echo $(ls -1 /lingua-franca/HelloWorld/)

# Use ENTRYPOINT not CMD so that command-line arguments go through
CMD ["./bin/HelloWorld"]