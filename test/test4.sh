#!/bin/bash

echo check_empty_dir
mkdir empty
cd empty
../../ft_mini_ls > ../diffs/test4_ft
ls -1tr          > ../diffs/test4_ls
cd ..
diff diffs/test4_ft diffs/test4_ls
rm -rf empty
