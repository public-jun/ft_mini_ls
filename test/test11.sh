#!/bin/bash

echo check_hid_file
mkdir hid_file && cd hid_file

touch .a b .c d

../../ft_mini_ls > ../diffs/test11_ft
ls -1tr > ../diffs/test11_ls

cd ..
diff diffs/test11_ft diffs/test11_ls
rm -rf hid_file
