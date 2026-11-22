// func cw_priv_mesh_private_control_join_add @ 0057d960 size=1

undefined4 cw_priv_mesh_private_control_join_add(int param_1,uint param_2,int param_3,int param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  char *__format;
  undefined4 uVar4;
  int iVar5;
  undefined1 *puStack_28;
  
  param_2 = param_2 & 0xffff;
  if ((param_1 == 0) || (((0x35 < param_2 - 1 && (0x18 < param_2 - 0x400)) || (param_3 == 0)))) {
    if (capwap_err_switch == 0) {
      return 0xffffffff;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 0xffffffff;
    }
    printf("[CW_ERROR]%32s():%4d input parameter is wrong\n","cw_priv_mesh_private_control_join_add"
           ,0x9fa);
    return 0xffffffff;
  }
  iVar1 = cw_msg_ele_mngr_get(param_2);
  if (iVar1 == 0) {
    if (capwap_err_switch == 0) {
      return 0xffffffff;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 0xffffffff;
    }
    __format = "[CW_ERROR]%32s():%4d capwap message element(%d) doesn\'t have manager\n";
    uVar4 = 0xa02;
  }
  else {
    iVar2 = (**(code **)(iVar1 + 0x14))(param_3);
    if (iVar2 != 0) {
      if (param_2 == 0x25) {
        puStack_28 = &stack0x00000010;
        for (iVar5 = 0; iVar5 < param_4; iVar5 = iVar5 + 1) {
          iVar3 = cw_msg_ele_priv_add_with_create
                            (*(int *)(iVar2 + 0x10),*(undefined2 *)(puStack_28 + 2),
                             *(undefined4 *)(puStack_28 + 4));
          if (iVar3 == -1) {
            (**(code **)(iVar1 + 0x18))(iVar2);
            return 0xffffffff;
          }
          puStack_28 = puStack_28 + 8;
        }
        *(short *)(iVar2 + 0xe) = *(short *)(*(int *)(iVar2 + 0x10) + 6) + 6;
      }
      FUN_004086b0(param_1 + 8,iVar2);
      return 0;
    }
    if (capwap_err_switch == 0) {
      return 0xffffffff;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 0xffffffff;
    }
    __format = "[CW_ERROR]%32s():%4d failed to create message element(%d)\n";
    uVar4 = 0xa0a;
  }
  printf(__format,"cw_priv_mesh_private_control_join_add",uVar4,param_2);
  return 0xffffffff;
}

