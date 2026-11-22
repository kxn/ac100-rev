// func serv_wtp_address_arg_add @ 0059a2d0 size=328

undefined4
serv_wtp_address_arg_add
          (int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,
          undefined4 param_6,short param_7,void *param_8,int param_9)

{
  undefined4 uVar1;
  void *__s;
  int iVar2;
  int iVar3;
  undefined4 local_res4;
  undefined4 local_res8;
  undefined4 local_resc;
  
  uVar1 = 0xffffffff;
  if ((((param_1 != (int *)0x0) && (local_res4._0_1_ = (char)((uint)param_2 >> 0x18), *param_1 != 0)
       ) && ((byte)(local_res4._0_1_ - 1U) < 2)) &&
     ((param_7 != 0 && ((param_9 == 0 || (param_8 != (void *)0x0)))))) {
    local_res4 = param_2;
    local_res8 = param_3;
    local_resc = param_4;
    __s = (void *)FUN_00408450(0x30,0x415);
    uVar1 = 0xffffffff;
    if (__s != (void *)0x0) {
      memset(__s,0,0x30);
      memcpy((void *)((int)__s + 0xc),&local_res4,0x14);
      *(short *)((int)__s + 0x20) = param_7;
      if (param_8 != (void *)0x0) {
        memcpy((void *)((int)__s + 0x28),param_8,6);
      }
      iVar2 = ip_to_ac_data(local_res4,local_res8,local_resc,param_5,param_6,param_7);
      if (param_9 == 0) {
        iVar3 = *param_1;
      }
      else {
        iVar3 = param_1[1];
      }
      FUN_004086b0(iVar3 + iVar2 * 0xc,__s);
      param_1[2] = param_1[2] + 1;
      uVar1 = 0;
      if (param_9 != 0) {
        param_1[3] = param_1[3] + 1;
      }
    }
  }
  return uVar1;
}

