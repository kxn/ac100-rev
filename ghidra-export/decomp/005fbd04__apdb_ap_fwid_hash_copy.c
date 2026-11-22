// func _apdb_ap_fwid_hash_copy @ 005fbd04 size=236

void _apdb_ap_fwid_hash_copy(void *param_1,int param_2)

{
  void *__dest;
  char *__format;
  undefined4 uVar1;
  
  if ((param_2 == 0) || (param_1 == (void *)0x0)) {
    if (apdb_err_switch == 0) {
      return;
    }
    __format = "[APDB_ERROR]%s()/line %d : para is null!\n";
    uVar1 = 0x395;
  }
  else {
    __dest = (void *)FUN_00408450(0x14,0x399);
    if (__dest != (void *)0x0) {
      *(undefined4 *)((int)__dest + 0x10) = *(undefined4 *)((int)param_1 + 0x10);
      memcpy(__dest,param_1,0x10);
      FUN_00408380(param_2,__dest);
      return;
    }
    if (apdb_err_switch == 0) {
      return;
    }
    __format = "[APDB_ERROR]%s()/line %d : mallco error\n";
    uVar1 = 0x39b;
  }
  printf(__format,"_apdb_ap_fwid_hash_copy",uVar1);
  return;
}

