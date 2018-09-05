#================================================================
#   Copyright (C) 2018 buffge All rights reserved.
#
#   文件名称：Makefile
#   创 建 者：buffge
#   创建日期：2018年08月10日 22:25:16
#   描    述：
#
#================================================================

PHP_INCLUDE70 = `/usr/bin/php-config7.0 --includes`
PHP_LIBS70 = `/usr/bin/php-config7.0 --libs`
PHP_LDFLAGS70 = `/usr/bin/php-config7.0 --ldflags`
PHP_INCLUDE_DIR70 = `/usr/bin/php-config7.0 --include-dir`
PHP_EXTENSION_DIR70 = `/usr/bin/php-config7.0 --extension-dir`

PHP_INCLUDE71 = `/usr/bin/php-config7.1 --includes`
PHP_LIBS71 = `/usr/bin/php-config7.1 --libs`
PHP_LDFLAGS71 = `/usr/bin/php-config7.1 --ldflags`
PHP_INCLUDE_DIR71 = `/usr/bin/php-config7.1 --include-dir`
PHP_EXTENSION_DIR71 = `/usr/bin/php-config7.1 --extension-dir`

PHP_INCLUDE72 = `/usr/bin/php-config7.2 --includes`
PHP_LIBS72 = `/usr/bin/php-config7.2 --libs`
PHP_LDFLAGS72 = `/usr/bin/php-config7.2 --ldflags`
PHP_INCLUDE_DIR72 = `/usr/bin/php-config7.2 --include-dir`
PHP_EXTENSION_DIR72 = `/usr/bin/php-config7.2 --extension-dir`


buffge.so.7.0: buffge.cc
	rm -f /usr/local/lib/libphpx.so
	ln -s /usr/local/lib/libphpx.so7.0 /usr/local/lib/libphpx.so
#	ldconfig
	c++ -DHAVE_CONFIG_H -g -o buffge.so.7.0 -O2 -fPIC -shared buffge.cc -std=c++11 ${PHP_INCLUDE70} -I${PHP_INCLUDE_DIR70} -lphpx
buffge.so.7.1: buffge.cc
	rm -f /usr/local/lib/libphpx.so
	ln -s /usr/local/lib/libphpx.so7.1 /usr/local/lib/libphpx.so
#	ldconfig
	c++ -DHAVE_CONFIG_H -g -o buffge.so.7.1 -O2 -fPIC -shared buffge.cc -std=c++11 ${PHP_INCLUDE71} -I${PHP_INCLUDE_DIR71} -lphpx
buffge.so.7.2: buffge.cc
	rm -f /usr/local/lib/libphpx.so
	ln -s /usr/local/lib/libphpx.so7.2 /usr/local/lib/libphpx.so
#	ldconfig
	c++ -DHAVE_CONFIG_H -g -o buffge.so.7.2 -O2 -fPIC -shared buffge.cc -std=c++11 ${PHP_INCLUDE72} -I${PHP_INCLUDE_DIR72} -lphpx
install: buffge.so.7.0 buffge.so.7.1 buffge.so.7.2
	cp buffge.so.7.0 ${PHP_EXTENSION_DIR70}/buffge.so
	cp buffge.so.7.1 ${PHP_EXTENSION_DIR71}/buffge.so
	cp buffge.so.7.2 ${PHP_EXTENSION_DIR72}/buffge.so

clean:
	rm buffge.so*


