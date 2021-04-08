#!/bin/bash

echo check_s_h_link
mkdir link && cd link

touch a b c d e f g
#symb_link
ln -s a s 
#hard_link
ln b h

../../ft_mini_ls > ../diffs/test10_ft
ls -1tr > ../diffs/test10_ls

cd ..
diff diffs/test10_ft diffs/test10_ls
rm -rf link
