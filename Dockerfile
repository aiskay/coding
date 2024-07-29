# Codility
FROM python:3.7-slim-buster
# HackerRank
# FROM python:3.9-slim-buster 

# install libraries
RUN apt update && \
    apt upgrade -y && \
    apt install -y --no-install-recommends \
    build-essential \
    git-all \
    less \
    unzip \
    sudo \
    vim \
    wget \
    zsh && \
    apt clean && \
    rm -rf /var/lib/apt/lists/*

RUN pip install --upgrade pip & \
    pip install \
    jupyterlab \
    numpy \
    scikit-learn \
    seaborn \
    pandas