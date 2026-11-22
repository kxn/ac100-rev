// func uac_unicode_transfer_str_to_utf8 @ 005265ec size=496

undefined4 uac_unicode_transfer_str_to_utf8(char *param_1,size_t param_2)

{
  int iVar1;
  void *__s;
  char *__src;
  undefined4 uVar2;
  
  if ((param_1 != (char *)0x0) && (iVar1 = uac_unicode_is_str_utf8(), iVar1 == 0)) {
    __s = (void *)uac_mem_malloc_my(param_2 << 1,0xcd2b);
    if (__s != (void *)0x0) {
      memset(__s,0,param_2 << 1);
      iVar1 = uac_codeConv_gbk_to_unicode(param_1,__s,param_2,1);
      if (iVar1 == -1) {
        __src = (char *)0x0;
        uVar2 = 0xffffffff;
        puts("uac_codeConv_gbk_to_unicode() fail!");
      }
      else if ((int)param_2 < iVar1) {
        __src = (char *)0x0;
        uVar2 = 0xffffffff;
        printf("toUnicode, src gbk string is too long(error_len=%d)\n",iVar1);
      }
      else {
        uVar2 = 0xffffffff;
        __src = (char *)uac_mem_malloc_my(param_2,0xcd42);
        if (__src != (char *)0x0) {
          memset(__src,0,param_2);
          iVar1 = uac_codeConv_unicode_to_utf8(__s,__src,param_2,0);
          if (iVar1 == -1) {
            printf("uac_codeConv_unicode_to_utf8() fail!");
          }
          else if ((int)param_2 < iVar1) {
            printf("toGbk src utf8 string is too long(error_len=%d)\n",iVar1);
          }
          else {
            strncpy(param_1,__src,param_2 - 1);
            uVar2 = 0;
          }
        }
      }
      uac_mem_free_my(__s);
      if (__src == (char *)0x0) {
        return uVar2;
      }
      uac_mem_free_my(__src);
      return uVar2;
    }
  }
  return 0xffffffff;
}

