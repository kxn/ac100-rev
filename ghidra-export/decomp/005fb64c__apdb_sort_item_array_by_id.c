// func _apdb_sort_item_array_by_id @ 005fb64c size=380

undefined4 _apdb_sort_item_array_by_id(int *param_1,int param_2)

{
  void *__s;
  int *piVar1;
  uint uVar2;
  char *__format;
  undefined4 uVar3;
  int *__src;
  uint uVar4;
  int *piVar5;
  
  if (param_2 == 0) {
    return 0;
  }
  if (param_1 == (int *)0x0) {
    if (apdb_err_switch == 0) {
      return 0xffffffff;
    }
    __format = "[APDB_ERROR]%s()/line %d : input array error\n";
    uVar3 = 0x4ed;
  }
  else {
    __s = (void *)FUN_00408450(0x58,0x4f6);
    if (__s != (void *)0x0) {
      memset(__s,0,0x58);
      piVar5 = param_1 + param_2 * 0x16 + -0x16;
      for (uVar4 = 0; piVar1 = piVar5, uVar2 = param_2 - 1U, __src = param_1, uVar4 < param_2 - 1U;
          uVar4 = uVar4 + 1) {
        do {
          uVar2 = uVar2 - 1;
          if (*piVar1 < *__src) {
            __src = piVar1;
          }
          piVar1 = piVar1 + -0x16;
        } while (uVar2 != uVar4);
        memset(__s,0,0x58);
        memcpy(__s,param_1,0x58);
        memcpy(param_1,__src,0x58);
        memcpy(__src,__s,0x58);
        param_1 = param_1 + 0x16;
      }
      FUN_00407df0(__s);
      return 0;
    }
    if (apdb_err_switch == 0) {
      return 0xffffffff;
    }
    __format = "[APDB_ERROR]%s()/line %d : malloc for ap_tmp failed.\n";
    uVar3 = 0x4f9;
  }
  printf(__format,"_apdb_sort_item_array_by_id",uVar3);
  return 0xffffffff;
}

