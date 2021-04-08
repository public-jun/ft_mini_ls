#!/bin/bash

echo  content_new_line
mkdir new_line
cd new_line

touch "a


"

touch b
../../ft_mini_ls > ../diffs/test6_ft
ls -1tr > ../diffs/test6_ls

cd ..
diff diffs/test6_ft diffs/test6_ls
rm -rf new_line
