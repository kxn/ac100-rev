// func rrc_md5_create @ 0055e7f4 size=68

void * rrc_md5_create(void)

{
  void *__s;
  
  __s = (void *)FUN_00408450(0x48,0x136);
  if (__s != (void *)0x0) {
    memset(__s,0,0x48);
  }
  return __s;
}

