#!/bin/bash

echo check_timestanp

mkdir time && cd time
touch a b c d e f 

touch -t 194204242420 c  
touch -t 204004242420 d

../../ft_mini_ls > ../diffs/test8_ft
ls -1tr > ../diffs/test8_ls

cd ..
diff diffs/test8_ft diffs/test8_ls
rm -rf time
