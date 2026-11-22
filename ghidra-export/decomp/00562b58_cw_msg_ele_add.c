// func cw_msg_ele_add @ 00562b58 size=316

undefined4 cw_msg_ele_add(int param_1,ushort param_2,int param_3)

{
  int iVar1;
  void *__s;
  undefined2 uVar2;
  uint uVar3;
  undefined4 uVar4;
  
  uVar4 = 0xffffffff;
  uVar3 = (uint)param_2;
  if ((param_1 != 0) && (param_3 != 0)) {
    if ((uVar3 - 1 < 0x36) || (uVar3 - 0x400 < 0x19)) {
      iVar1 = cw_msg_ele_mngr_get(uVar3);
      if (iVar1 == 0) {
        uVar4 = 0xffffffff;
        if ((capwap_err_switch != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
          printf("[CW_ERROR]%32s():%4d message element(%d)\'s manager is NULL\n","cw_msg_ele_add",
                 0x159,uVar3);
        }
      }
      else {
        uVar4 = 0xffffffff;
        __s = (void *)FUN_00408450(0x18,0x15d);
        if (__s != (void *)0x0) {
          memset(__s,0,0x18);
          *(ushort *)((int)__s + 0xc) = param_2;
          uVar4 = 0;
          uVar2 = (**(code **)(iVar1 + 0x20))(param_3);
          *(undefined2 *)((int)__s + 0xe) = uVar2;
          *(int *)((int)__s + 0x10) = param_3;
          FUN_004086b0(param_1 + 0x1c,__s);
          *(short *)(param_1 + 0x16) = *(short *)(param_1 + 0x16) + *(short *)((int)__s + 0xe) + 4;
        }
      }
    }
    else {
      uVar4 = 0xffffffff;
    }
  }
  return uVar4;
}

