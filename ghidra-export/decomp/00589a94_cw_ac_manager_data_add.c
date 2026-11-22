// func cw_ac_manager_data_add @ 00589a94 size=156

undefined4
cw_ac_manager_data_add
          (int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,
          undefined4 param_6,undefined2 param_7)

{
  void *__s;
  undefined4 uVar1;
  undefined4 local_res4;
  undefined4 local_res8;
  undefined4 local_resc;
  
  uVar1 = 0xffffffff;
  if ((param_1 != 0) &&
     (local_res4 = param_2, local_res8 = param_3, local_resc = param_4,
     __s = (void *)FUN_00408450(0x30,0x4b4), __s != (void *)0x0)) {
    memset(__s,0,0x30);
    uVar1 = 0;
    memcpy((void *)((int)__s + 0xc),&local_res4,0x14);
    *(undefined2 *)((int)__s + 0x20) = param_7;
    FUN_004086b0(param_1,__s);
  }
  return uVar1;
}

