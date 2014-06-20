#pef:PHP扩展框架
=========================================================================
目前还在开发中，部分代码并未提交。
###编译方法：

    $ phpize
    $ ./configure --with-php-config=/usr/bin/php-config
    # make
    # make test
    # make install

然后在php.ini中增加一行：

    extension=pef.so

