// func cw_msg_ele_priv_add @ 00582df4 size=1

undefined4 cw_msg_ele_priv_add(int param_1,ushort param_2,int param_3)

{
  int iVar1;
  void *__s;
  undefined2 uVar2;
  uint uVar3;
  undefined4 uVar4;
  
  uVar4 = 0xffffffff;
  uVar3 = (uint)param_2;
  if (((param_1 != 0) && (param_3 != 0)) &&
     (iVar1 = cw_msg_ele_priv_size(), (int)uVar3 <= iVar1 + -1)) {
    iVar1 = cw_msg_ele_priv_mngr_get(uVar3);
    if (iVar1 == 0) {
      if ((capwap_err_switch != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
        printf("[CW_ERROR]%32s():%4d private message element(%d)\'s manager is NULL\n",
               "cw_msg_ele_priv_add",0x2c6,uVar3);
      }
    }
    else {
      __s = (void *)FUN_00408450(0x18,0x2ca);
      if (__s != (void *)0x0) {
        memset(__s,0,0x18);
        *(ushort *)((int)__s + 0xc) = param_2;
        uVar4 = 0;
        uVar2 = (**(code **)(iVar1 + 0x20))(param_3);
        *(undefined2 *)((int)__s + 0xe) = uVar2;
        *(int *)((int)__s + 0x10) = param_3;
        FUN_004086b0(param_1 + 8,__s);
        *(short *)(param_1 + 6) = *(short *)(param_1 + 6) + *(short *)((int)__s + 0xe) + 4;
      }
    }
  }
  return uVar4;
}

