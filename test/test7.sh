#!/bin/bash

echo check_many_files
mkdir many && cd many

touch {0..1000}.txt
../../ft_mini_ls > ../diffs/test7_ft
ls -1tr > ../diffs/test7_ls

cd ..
diff diffs/test7_ft diffs/test7_ls
rm -rf many
