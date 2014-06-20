#include "php.h"
#include "php_ini.h"
#include "ext/standard/info.h"
#include "php_pef.h"
#include "pef_config.h"


zend_class_entry *pef_config_ce;

/**
 * 声明构造函数
 * @param 
 * @return 
 */
ZEND_METHOD(pef_config,__construct){
    php_printf("构造函数");
}



ZEND_METHOD(pef_config,getInstance){
    php_printf("获取config类的单例");
}

ZEND_METHOD(pef_config,getConfig){
    php_printf("获取配置信息");
}


static zend_function_entry pef_config_methods[]={
    ZEND_ME(pef_config,getInstance,NULL,ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
    ZEND_ME(pef_config,getConfig,NULL,ZEND_ACC_PUBLIC)
    {NULL,NULL,NULL}
};


PHP_MINIT_FUNCTION(pef_config)
{
    
    zend_class_entry ce;
      
    
    //初始化config类
    
    INIT_CLASS_ENTRY(ce, "pef_config",pef_config_methods);
    pef_config_ce = zend_register_internal_class(&ce TSRMLS_CC);  
    
    zend_declare_property_null(pef_config_ce,"instance",strlen("instance"),ZEND_ACC_PRIVATE|ZEND_ACC_STATIC);
    zend_declare_property_null(pef_config_ce,"config",strlen("config"),ZEND_ACC_PRIVATE);
    return SUCCESS;
}
