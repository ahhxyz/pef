#include "php.h"
#include "php_ini.h"
#include "ext/standard/info.h"
#include "php_pef.h"
#include "pef_config.h"


zend_class_entry *pef_config_ce;

static zend_function_entry pef_config_methods[]={
    {NULL,NULL,NULL}
};


PHP_MINIT_FUNCTION(pef_config)
{
    
    zend_class_entry ce;
      
    
    //初始化config类
    
    INIT_CLASS_ENTRY(ce, "pef_config",pef_config_methods);
    pef_config_ce = zend_register_internal_class(&ce TSRMLS_CC);  
    
    
    
    return SUCCESS;
}
