#include "php.h"
#include "php_ini.h"
#include "ext/standard/info.h"
#include "php_pef.h"
#include "pef_db.h"


zend_class_entry *pef_db_ce;


ZEND_METHOD(__construct){
    php_printf("db类的构造函数");
}



ZEND_METHOD(getInstance){
    php_printf("获取单例");
}


ZEND_METHOD(select){
    php_printf("获取数据");
}


ZEND_METHOD(insert){
    php_printf("插入");
}

ZEND_METHOD(update){
    php_printf("更新");
}

ZEND_METHOD(delete){
    php_printf("删除");
}
static zend_function_entry pef_db_methods[]={
    ZEND_ME(pef_db,__construct,NULL,ZEND_ACC_PROTECTED)
    ZEND_ME(pef_db,getInstance,NULL,ZEND_ACC_PROTECTED|ZEND_ACC_STATIC)
    ZEND_ME(pef_db,select,NULL,ZEND_ACC_PROTECTED)
    ZEND_ME(pef_db,insert,NULL,ZEND_ACC_PROTECTED)
    ZEND_ME(pef_db,update,NULL,ZEND_ACC_PROTECTED)
    ZEND_ME(pef_db,delete,NULL,ZEND_ACC_PROTECTED)
    {NULL,NULL,NULL}
};


PHP_MINIT_FUNCTION(pef_db)
{
    
    zend_class_entry ce;
      
    
    //初始化db类
    
    INIT_CLASS_ENTRY(ce, "pef_db",pef_db_methods);
    pef_db_ce = zend_register_internal_class(&ce TSRMLS_CC);  
    
    zend_declare_property_null(pef_db_ce,"_vars",strlen("instance"),ZEND_ACC_PROTECTED|ZEND_ACC_STATIC);
    
    
    return SUCCESS;
}
