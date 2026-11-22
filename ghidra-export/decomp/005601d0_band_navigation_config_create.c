// func band_navigation_config_create @ 005601d0 size=68

void * band_navigation_config_create(void)

{
  void *__s;
  
  __s = (void *)FUN_00408450(0x14,0x3c);
  if (__s != (void *)0x0) {
    memset(__s,0,0x14);
  }
  return __s;
}

