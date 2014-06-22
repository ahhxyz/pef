#include "php.h"
#include "php_ini.h"
#include "ext/standard/info.h"
#include "php_pef.h"
#include "pef_controller.h"


zend_class_entry *pef_controller_ce;


ZEND_METHOD(pef_controller,__construct){
    php_printf("controller类的构造函数");
}



ZEND_METHOD(pef_controller,assign){
    php_printf("给模板变量赋值");
}


ZEND_METHOD(pef_controller,display){
    php_printf("渲染模板，填充数据，然后输出");
}

ZEND_METHOD(pef_controller,render){
    php_printf("渲染模板不直接输出");
}

static zend_function_entry pef_controller_methods[]={
    ZEND_ME(pef_controller,__construct,NULL,ZEND_ACC_PUBLIC)
    ZEND_ME(pef_controller,assign,NULL,ZEND_ACC_PUBLIC)
    ZEND_ME(pef_controller,display,NULL,ZEND_ACC_PROTECTED)
    ZEND_ME(pef_controller,render,NULL,ZEND_ACC_PROTECTED)
    {NULL,NULL,NULL}
};


PHP_MINIT_FUNCTION(pef_controller)
{
    
    zend_class_entry ce;
      
    
    //初始化controller类
    
    INIT_CLASS_ENTRY(ce, "pef_controller",pef_controller_methods);
    pef_controller_ce = zend_register_internal_class(&ce TSRMLS_CC);  
    
    zend_declare_property_null(pef_controller_ce,"_vars",strlen("_vars"),ZEND_ACC_PROTECTED);
    
    
    return SUCCESS;
}
