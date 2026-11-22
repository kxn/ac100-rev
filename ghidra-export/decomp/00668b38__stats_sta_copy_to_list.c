// func _stats_sta_copy_to_list @ 00668b38 size=144

void _stats_sta_copy_to_list(void *param_1,int param_2)

{
  void *__s;
  
  if (((param_1 != (void *)0x0) && (param_2 != 0)) &&
     (__s = (void *)FUN_00408450(0x1d0,0xab0), __s != (void *)0x0)) {
    memset(__s,0,0x1d0);
    memcpy((void *)((int)__s + 0x10),param_1,0x1c0);
    FUN_004086b0(param_2,__s);
    return;
  }
  return;
}

