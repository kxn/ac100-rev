// func _apdb_read_file @ 005fb7c8 size=664

undefined4 _apdb_read_file(undefined4 *param_1,size_t *param_2,char *param_3)

{
  FILE *__stream;
  size_t __n;
  void *__s;
  size_t sVar1;
  char *__format;
  undefined4 uVar2;
  
  if (((param_3 == (char *)0x0) || (param_1 == (undefined4 *)0x0)) || (param_2 == (size_t *)0x0)) {
    if (apdb_err_switch == 0) {
      return 0xffffffff;
    }
    printf("[APDB_ERROR]%s()/line %d : input error\n","_apdb_read_file",0x163);
    return 0xffffffff;
  }
  FUN_004082d0(l_apdb_mutex,0xffffffff);
  __stream = fopen(param_3,"rb");
  if (__stream == (FILE *)0x0) {
    if (apdb_debug_switch != 0) {
      printf("[APDB_DEBUG]%s()/line %d : Failed to open file[%s]\n","_apdb_read_file",0x16b,param_3)
      ;
    }
    goto LAB_005fb9b8;
  }
  fseek(__stream,0,2);
  __n = ftell(__stream);
  if (((int)__n < 0x100000) && (__n != 0)) {
    fseek(__stream,0,0);
    __s = (void *)FUN_00408450(__n + 1,0x179);
    if (__s == (void *)0x0) {
      if (apdb_err_switch != 0) {
        __format = "[APDB_ERROR]%s()/line %d : failed to malloc.\n";
        uVar2 = 0x17c;
        goto LAB_005fb9dc;
      }
    }
    else {
      memset(__s,0,__n + 1);
      if (apdb_debug_switch != 0) {
        printf("[APDB_DEBUG]%s()/line %d : success malloc %d bytes memory.\n","_apdb_read_file",
               0x180,__n);
      }
      sVar1 = fread(__s,1,__n,__stream);
      if (__n == sVar1) {
        if (apdb_debug_switch == 0) {
          *param_1 = __s;
        }
        else {
          printf("[APDB_DEBUG]%s()/line %d : read file %d bytes success\n","_apdb_read_file",0x188,
                 __n);
          *param_1 = __s;
        }
        *param_2 = __n;
        fclose(__stream);
        FUN_00407f30(l_apdb_mutex);
        return 0;
      }
      if (apdb_debug_switch != 0) {
        __format = "[APDB_DEBUG]%s()/line %d : read apdb data failed.\n";
        uVar2 = 0x185;
LAB_005fb9dc:
        printf(__format,"_apdb_read_file",uVar2);
      }
    }
  }
  else {
    __s = (void *)0x0;
    if (apdb_err_switch != 0) {
      __format = "[APDB_ERROR]%s()/line %d : file is too large or zero.\n";
      uVar2 = 0x174;
      goto LAB_005fb9dc;
    }
  }
  fclose(__stream);
  if (__s != (void *)0x0) {
    FUN_00407df0(__s);
  }
LAB_005fb9b8:
  FUN_00407f30(l_apdb_mutex);
  return 0xffffffff;
}

