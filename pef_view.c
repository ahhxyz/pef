#include "php.h"
#include "php_ini.h"
#include "ext/standard/info.h"
#include "php_pef.h"
#include "pef_view.h"



zend_class_entry *pef_view_ce;


ZEND_METHOD(pef_view,__construct){
    php_printf("view类的构造函数");
}



ZEND_METHOD(pef_view,parseIf){
    php_printf("解析if标签");
}


ZEND_METHOD(pef_view,parseForeach){
    php_printf("解析foreach标签");
}

ZEND_METHOD(pef_view,parseVar){
    php_printf("解析变量");
}

static zend_function_entry pef_view_methods[]={
    ZEND_ME(pef_view,__construct,NULL,ZEND_ACC_PROTECTED)
    ZEND_ME(pef_view,parseIf,NULL,ZEND_ACC_PROTECTED)
    ZEND_ME(pef_view,parseForeach,NULL,ZEND_ACC_PROTECTED)
    ZEND_ME(pef_view,parseVar,NULL,ZEND_ACC_PROTECTED)
    {NULL,NULL,NULL}
};


PHP_MINIT_FUNCTION(pef_view)
{
    
    zend_class_entry ce;
      
    
    //初始化view类
    
    INIT_CLASS_ENTRY(ce, "pef_view",pef_view_methods);
    pef_view_ce = zend_register_internal_class(&ce TSRMLS_CC);  
    
    zend_declare_property_null(pef_view_ce,"_contents",strlen("_contents"),ZEND_ACC_PRIVATE);
    
    
    return SUCCESS;
}
