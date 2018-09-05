#include <phpx.h>
#include "Zend/zend_API.h"
#include "buffge.h"
using namespace std;
using namespace php;

//声明函数
PHPX_FUNCTION(buffge_test);
PHPX_FUNCTION(buffge_call_func);
void buff_call_func(Variant funcName, Args args);

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
        buffgeConstantCommon->addConstant("EXT_FLAG", true);
        buffgeConstantCommon->addConstant("VERSION", EXT_VERSION);
        buffgeConstantCommon->addConstant("SUCCESS", 0x0);
        buffgeConstantCommon->addConstant("DEFAULT", -1);
        buffgeConstantCommon->addConstant("DEFAULT_ERROR", -1);
        buffgeConstantCommon->addConstant("UNDEFINED", -1);
        buffgeConstantCommon->addConstant("NEED_COUNT", true);
        buffgeConstantCommon->addConstant("NOT_NEED_COUNT", false);
        buffgeConstantCommon->addConstant("SHOW_DEL", true);
        buffgeConstantCommon->addConstant("NOT_LIMIT", -1);
        buffgeConstantCommon->addConstant("FLAG", 0x1);
        buffgeConstantCommon->addConstant("EMPTY_STR", "");
        buffgeConstantCommon->addConstant("JSON_ERROR", 0xe1);
        buffgeConstantCommon->addConstant("DB_ERROR", 0x2);
        buffgeConstantCommon->addConstant("TP_DB_ERROR", 0x3);
        buffgeConstantCommon->addConstant("NOT_ALLOW_VALUE", 0x4);
        buffgeConstantCommon->addConstant("HIGH_FREQUENCY", 0x5);
        buffgeConstantCommon->addConstant("VALID_ERROR", 0x6);
        buffgeConstantCommon->addConstant("ERROR_PARAM", 0x7);
        buffgeConstantCommon->addConstant("INVAILD_PARAM", 0x8);
        buffgeConstantCommon->addConstant("MISSING_ARGUMENTS", 0x9);
        buffgeConstantCommon->addConstant("ERROR_METHOD", 0xa);
        buffgeConstantCommon->addConstant("SERVER_ERROR", 0xb);
        buffgeConstantCommon->addConstant("NO_CHANGE", 0x1);

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

void buff_call_func(Variant funcName, Args oriArgs) {
    Args myArgs;
    for (int i = 0; i < oriArgs.count() && i < 10; i++) {
        //        var_dump(oriArgs[i]);
        myArgs.append(oriArgs[i]);
    }
    call(funcName, myArgs);
}