#include "php.h"
#include "php_ini.h"
#include "ext/standard/info.h"
#include "php_pef.h"
#include "pef_model.h"


zend_class_entry *pef_model_ce;


ZEND_METHOD(__construct){

    php_printf("model类的构造函数");
}



ZEND_METHOD(getColumns){
    php_printf("获取模型对应数据表的所有字段名称");
}


ZEND_METHOD(select){
    php_printf("查");
}

ZEND_METHOD(insert){
    php_printf("增");
}


ZEND_METHOD(update){
    php_printf("改");
}


ZEND_METHOD(delete){
    php_printf("删");
}

static zend_function_entry pef_model_methods[]={
    ZEND_ME(pef_model,__construct,NULL,ZEND_ACC_PROTECTED)
    ZEND_ME(pef_model,getColumns,NULL,ZEND_ACC_PROTECTED)
    ZEND_ME(pef_model,select,NULL,ZEND_ACC_PROTECTED)
    ZEND_ME(pef_model,insert,NULL,ZEND_ACC_PROTECTED)
    ZEND_ME(pef_model,update,NULL,ZEND_ACC_PROTECTED)
    ZEND_ME(pef_model,delete,NULL,ZEND_ACC_PROTECTED)
    {NULL,NULL,NULL}
};


PHP_MINIT_FUNCTION(pef_model)
{
    
    zend_class_entry ce;
      
    
    //初始化model类
    
    INIT_CLASS_ENTRY(ce, "pef_model",pef_model_methods);
    pef_model_ce = zend_register_internal_class(&ce TSRMLS_CC);  
    
    //声明一个静态属性：$_db，表示当前模型的数据库连接，通过config类的getInstance()来获取
    zend_declare_property_null(pef_model_ce,"_db",strlen("_db"),ZEND_ACC_PROTECTED|ZEND_ACC_STATIC);
    
    
    return SUCCESS;
}
