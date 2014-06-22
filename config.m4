

 PHP_ARG_ENABLE(pef, whether to enable pef support,

 [  --enable-pef           Enable pef support])

if test "$PHP_PEF" != "no"; then
  
  PHP_NEW_EXTENSION(pef, 
    pef.c \
    pef_config.c \
    pef_db.c \
    pef_model.c \
    pef_view.c \
    pef_controller.c, $ext_shared)
fi
