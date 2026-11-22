// func cw_msg_eles_free @ 0058787c size=256

undefined4 cw_msg_eles_free(int param_1)

{
  int iVar1;
  int iVar2;
  
  if (param_1 == 0) {
    if ((capwap_err_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
      printf("[CW_ERROR]%32s():%4d input parameter is wrong\n","cw_msg_eles_free",0x13a);
    }
  }
  else {
    while (iVar2 = FUN_004081b0(param_1 + 0x1c), iVar2 != 0) {
      iVar1 = cw_msg_ele_mngr_get(*(undefined2 *)(iVar2 + 0xc));
      if (iVar1 == 0) {
        if (capwap_err_switch == 0) {
          return 0xffffffff;
        }
        iVar1 = is_target_debug_ap();
        if (iVar1 != 0) {
          printf("[CW_ERROR]%32s():%4d capwap message element(%d) doesn\'t have manager\n",
                 "cw_msg_eles_free",0x146,(uint)*(ushort *)(iVar2 + 0xc));
          return 0xffffffff;
        }
        return 0xffffffff;
      }
      FUN_00408500(iVar2);
      (**(code **)(iVar1 + 0x18))(iVar2);
      FUN_00407df0(iVar2);
    }
  }
  return 0;
}

