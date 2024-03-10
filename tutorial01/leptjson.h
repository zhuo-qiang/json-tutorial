#ifndef LEPTJSON_H__
#define LEPTJSON_H__
/*
    include guards防止多次定义头文件
    习惯是 _H__ 作为后缀
    大型工程可以用 项目名称_目录_文件名称_H__

    现在可以使用 #pragma once 代替, 这是一个非标准但是主流都支持的指令
*/


typedef enum { LEPT_NULL, LEPT_FALSE, LEPT_TRUE, LEPT_NUMBER, LEPT_STRING, LEPT_ARRAY, LEPT_OBJECT } lept_type;
/*
    json支持的所有数据类型, 声明一个枚举类型
    枚举类型通常全大写, 而且一般用项目简称为前缀 LEOT_XXX

    c++ 可以用命名空间功能代替
*/


typedef struct {
    lept_type type;
}lept_value;

enum {
    LEPT_PARSE_OK = 0,
    LEPT_PARSE_EXPECT_VALUE,
    /*若一个 JSON 只含有空白*/
    LEPT_PARSE_INVALID_VALUE,
    /*若一个值之后，在空白之后还有其他字符*/
    LEPT_PARSE_ROOT_NOT_SINGULAR
    /*若值不是那三种字面值*/
};

int lept_parse(lept_value* v, const char* json);
/*
    解析 JSON ,
    传入的 json 是 char* 格式, 由于内部不应该对json进行修改, 所以要 const 修饰
    lept_value* 是传出参数
    一般用法是
    lept_value v;
    const char json[] = ...;
    int ret = lept_parse(&v, json);
    返回值 int 对应的是上面的枚举类型
*/

lept_type lept_get_type(const lept_value* v);

#endif /* LEPTJSON_H__ */
