#!/bin/bash

echo name_sort
mkdir name && cd name

touch {0..100}
touch {0..100}

touch 42 54 64
../../ft_mini_ls > ../diffs/test9_ft
ls -1tr > ../diffs/test9_ls

cd ..
diff diffs/test9_ft diffs/test9_ls
rm -rf name
