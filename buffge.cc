#include <phpx.h>
#include "Zend/zend_API.h"
#include "buffge.h"
using namespace std;
using namespace php;

//声明函数
PHPX_FUNCTION(buffge_test);
PHPX_FUNCTION(buffge_call_func);
Variant* buff_call_func(Variant funcName, Args args);

PHPX_METHOD(Buffge, __construct) {
    _this.set("tips", "此扩展为buffge开发,有任何问题请联系 admin@buffge.com");
}

PHPX_METHOD(Buffge, commonMethod) {
    echo("this is commonMethod\n");
}

PHPX_METHOD(Buffge, staticMethod) {
    echo("this is staticMethod");

}

PHPX_EXTENSION() {
    Extension *ext = new Extension("buffge", EXT_VERSION);
    ext->registerFunction(PHPX_FN(buffge_test)); //测试函数
    ext->registerFunction(PHPX_FN(buffge_call_func)); //调用函数

    ext->onStart = [ext]() {
        Class *buffge = new Class("Buffge");
        //注册构造方法
        buffge->addMethod(PHPX_ME(Buffge, __construct), CONSTRUCT);
        //公有方法
        buffge->addMethod(PHPX_ME(Buffge, commonMethod));
        //公有静态方法
        buffge->addMethod(PHPX_ME(Buffge, staticMethod), STATIC);
        //添加公有属性
        buffge->addProperty("publicProperty", "buffge");
        //添加保护属性
        buffge->addProperty("protectedProperty", "buffge", PROTECTED);
        //添加私有属性
        buffge->addProperty("privateProperty", "buffge", PRIVATE);
        //添加公有静态属性
        buffge->addProperty("publicStaticProperty", "buffge", STATIC);

        //添加常量
        buffge->addConstant("VERSION", EXT_VERSION);

        Class *buffgeConstantCommon = new Class("buffge\\constant\\Common");
        buffgeConstantCommon->addConstant("VERSION", EXT_VERSION);
        buffgeConstantCommon->addConstant("EXT_FLAG", true);
        //注册类
        ext->registerClass(buffge);
        ext->registerClass(buffgeConstantCommon);
    };
    ext->info({
              "key", "value",
    },
    {
        {
              "buffge support", "enabled"
        },
        {
              "version", ext->version
        },
        {
              "author", "buffge"
        },
        {
              "email", "admin@buffge.com"
        },
        {
              "qq", "1515888956"
        },
    });
    return ext;
}

//实现函数

PHPX_FUNCTION(buffge_test) {
    echo("buffge ext is installed!\n");
}

PHPX_FUNCTION(buffge_call_func) {
    Args myArgs;
    for (int i = 1; i < args.count() && i < 10; i++) {
        myArgs.append(args[i]);
    }
    buff_call_func(args[0], myArgs);
}

Variant* buff_call_func(Variant funcName, Args args) {
    Args myArgs;
    for (int i = 0; i < args.count() && i < 10; i++) {
        myArgs.append(args[i]);
    }
    Variant* _retval = new Variant;
    call(funcName, myArgs);
    return _retval;
}