<?php

/*
 * Author: buff <admin@buffge.com>
 * Created on : 2018-8-11, 2:40:56
 * QQ:1515888956
 */

#输出buffge ext is installed!\n
buffge_test();
#调用 var_dump([1,2]);
buffge_call_func("var_dump", [1, 2]);
$b = new Buffge;
var_dump($b);
var_dump(new ReflectionClass('Buffge'));
var_dump(new ReflectionObject($b));
//buffge
echo $b->publicProperty . "\n";
//buffge
echo Buffge::$publicStaticProperty . "\n";
//1.0.0
echo Buffge::VERSION . "\n";

//公有方法
$b->commonMethod();
Buffge::staticMethod();

