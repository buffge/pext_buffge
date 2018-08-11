#================================================================
#   Copyright (C) 2018 buffge All rights reserved.
#
#   文件名称：Makefile
#   创 建 者：buffge
#   创建日期：2018年08月10日 22:25:16
#   描    述：
#
#================================================================

PHP_INCLUDE = `php-config --includes`
PHP_LIBS = `php-config --libs`
PHP_LDFLAGS = `php-config --ldflags`
PHP_INCLUDE_DIR = `php-config --include-dir`
PHP_EXTENSION_DIR = `php-config --extension-dir`

buffge.so: buffge.cc
	c++ -DHAVE_CONFIG_H -g -o buffge.so -O0 -fPIC -shared buffge.cc -std=c++11 ${PHP_INCLUDE} -I${PHP_INCLUDE_DIR} -lphpx

install: buffge.so
	cp buffge.so ${PHP_EXTENSION_DIR}/

clean:
	rm *.so


