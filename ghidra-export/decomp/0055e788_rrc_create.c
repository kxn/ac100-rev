// func rrc_create @ 0055e788 size=68

void * rrc_create(void)

{
  void *__s;
  
  __s = (void *)FUN_00408450(0x1b4,0x113);
  if (__s != (void *)0x0) {
    memset(__s,0,0x1b4);
  }
  return __s;
}

