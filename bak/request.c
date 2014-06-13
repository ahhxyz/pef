/*
 * fw_request.c
 *
 *  Created on: 2012-6-19
 *      Author: jy
 */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_ini.h"
#include "main/SAPI.h"
#include "Zend/zend_exceptions.h"
#include "Zend/zend_alloc.h"
/*


zval *getQuery()
{
	zval **carrier;
	zval *key, *ret;

	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &key) == FAILURE){
		RETURN_FALSE;
	}

	return ret = request_query(TRACK_VARS_GET, Z_STRVAL_P(key), Z_STRLEN_P(key) TSRMLS_CC);

	//RETURN_ZVAL(ret, 0, NULL);
}

zval  *getPost()
{
	zval **carrier;
	zval *key, *ret;

	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &key) == FAILURE){
		RETURN_FALSE;
	}

	return ret = request_query(TRACK_VARS_POST, Z_STRVAL_P(key), Z_STRLEN_P(key) TSRMLS_CC);

	//RETURN_ZVAL(ret, 0, NULL);
}

/*
定义request_query来完成内核中读取$_GET\$_POST\$_SERVER\$_FILES\$_COOKIE\$_REQUEST
其中只有$_REQUEST的值是可修改的
*/
zval * request_query(uint type, char * name, uint len TSRMLS_DC) {
	zval 	**carrier, **ret;

	zend_bool jit_initialization = (PG(auto_globals_jit) && !PG(register_globals) && !PG(register_long_arrays));

	switch (type) {
		case TRACK_VARS_POST:
		case TRACK_VARS_GET:
		case TRACK_VARS_FILES:
		case TRACK_VARS_COOKIE:
			carrier = &PG(http_globals)[type];
			break;
		case TRACK_VARS_ENV:
			if (jit_initialization) {
				zend_is_auto_global(ZEND_STRL("_ENV") TSRMLS_CC);
			}
			carrier = &PG(http_globals)[type];
			break;
		case TRACK_VARS_SERVER:
			if (jit_initialization) {
				zend_is_auto_global(ZEND_STRL("_SERVER") TSRMLS_CC);
			}
			carrier = &PG(http_globals)[type];
			break;
		case TRACK_VARS_REQUEST:
			if (jit_initialization) {
				zend_is_auto_global(ZEND_STRL("_REQUEST") TSRMLS_CC);
			}
			(void)zend_hash_find(&EG(symbol_table), ZEND_STRS("_REQUEST"), (void **)&carrier);
			break;
		default:
			break;
	}

	if (!carrier || !(*carrier)) {
		zval *empty;
		MAKE_STD_ZVAL(empty);
		ZVAL_NULL(empty);
		return empty;
	}

	if (!len) {
		Z_ADDREF_P(*carrier);
		return *carrier;
	}

	if (zend_hash_find(Z_ARRVAL_PP(carrier), name, len + 1, (void **)&ret) == FAILURE) {
		zval *empty;
		MAKE_STD_ZVAL(empty);
		ZVAL_NULL(empty);
		return empty;
	}

	Z_ADDREF_P(*ret);
	return *ret;
}