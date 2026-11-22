// func cloud_mngt_get_cert_or_key @ 004916a8 size=520

undefined4 cloud_mngt_get_cert_or_key(undefined4 *param_1,char *param_2)

{
  FILE *__stream;
  size_t sVar1;
  void *__s;
  char *__format;
  undefined4 uVar2;
  undefined4 uVar3;
  
  if (cloud_mngt_debug_switch != '\0') {
    printf("[CLOUD_MNGT_DEBUG]%s()/%d the file name is %s\n","cloud_mngt_get_cert_or_key",0x1b7b,
           param_2);
  }
  if (param_2 == (char *)0x0) {
    if (cloud_mngt_err_switch == '\0') {
      return 0xffffffff;
    }
    printf("[CLOUD_MNGT_ERROR]%s()/%d filename is empty!!!!!\n","cloud_mngt_get_cert_or_key",0x1b7e)
    ;
    return 0xffffffff;
  }
  __stream = fopen(param_2,"r");
  if (__stream == (FILE *)0x0) {
    if (cloud_mngt_err_switch == '\0') {
      return 0xffffffff;
    }
    printf("[CLOUD_MNGT_ERROR]%s()/%d open cert_file[%s] fail!\n","cloud_mngt_get_cert_or_key",
           0x1b84,param_2);
    return 0xffffffff;
  }
  fseek(__stream,0,2);
  sVar1 = ftell(__stream);
  if ((int)sVar1 < 0x80000) {
    rewind(__stream);
    __s = (void *)FUN_00408450(sVar1 + 1,0x1b8f);
    *param_1 = __s;
    if (__s == (void *)0x0) {
      uVar3 = 0xffffffff;
      if (cloud_mngt_err_switch == '\0') goto LAB_00491730;
      __format = "[CLOUD_MNGT_ERROR]%s()/%d malloc fail!\n";
      uVar2 = 0x1b91;
    }
    else {
      memset(__s,0,sVar1 + 1);
      uVar3 = 0;
      sVar1 = fread((void *)*param_1,sVar1,1,__stream);
      if ((sVar1 == 1) || (uVar3 = 0xffffffff, cloud_mngt_err_switch == '\0')) goto LAB_00491730;
      __format = "[CLOUD_MNGT_ERROR]%s()/%d read file fail!\n";
      uVar2 = 0x1b98;
    }
    uVar3 = 0xffffffff;
    printf(__format,"cloud_mngt_get_cert_or_key",uVar2);
  }
  else {
    uVar3 = 0xffffffff;
    if (cloud_mngt_err_switch != '\0') {
      printf("[CLOUD_MNGT_ERROR]%s()/%d too long file info %d !\n","cloud_mngt_get_cert_or_key",
             0x1b8b,sVar1);
    }
  }
LAB_00491730:
  fclose(__stream);
  return uVar3;
}

