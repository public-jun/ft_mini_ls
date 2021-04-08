#!/bin/bash

echo check chmod 111

mkdir chmod_111
chmod 111 chmod_111
cd chmod_111
../../ft_mini_ls
cd ..
rm -rf chmod111
