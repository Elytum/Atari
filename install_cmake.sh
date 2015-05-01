#!/bin/sh
mkdir $HOME/Library/Caches/Homebrew
brew update && brew install cmake
tar -zxvf $HOME/Library/Caches/Homebrew/cmake-3.2.2.yosemite.bottle.3.tar.gz
