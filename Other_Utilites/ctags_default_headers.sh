# sed -n -e 'H;${x;s/\n/ /g;s/^ //;p;}'`
# gcc -xc++ -E -v -
ctags -R --sort=yes --c++-kinds=+pl --fields=+iaS --extra=+q -f cpp /usr/lib/gcc/i386-redhat-linux/4.1.2/../../../../include/c++/4.1.2/* 
ctags -R --sort=yes --c++-kinds=+pl --fields=+iaS --extra=+q -a -f cpp /usr/lib/gcc/i386-redhat-linux/4.1.2/../../../../include/c++/4.1.2/i386-redhat-linux/*
ctags -R --sort=yes --c++-kinds=+pl --fields=+iaS --extra=+q -a -f cpp /usr/lib/gcc/i386-redhat-linux/4.1.2/../../../../include/c++/4.1.2/backward/*
ctags -R --sort=yes --c++-kinds=+pl --fields=+iaS --extra=+q -a -f cpp /usr/local/include
ctags -R --sort=yes --c++-kinds=+pl --fields=+iaS --extra=+q -a -f cpp /usr/lib/gcc/i386-redhat-linux/4.1.2/include
ctags -R --sort=yes --c++-kinds=+pl --fields=+iaS --extra=+q -a -f cpp /usr/include
