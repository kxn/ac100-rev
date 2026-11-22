// func cw_priv_vap_info_list_destroy @ 005ca6c4 size=356

undefined4 cw_priv_vap_info_list_destroy(byte *param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  
  if (param_1 == (byte *)0x0) {
    uVar3 = 0xffffffff;
    if ((capwap_err_switch != 0) && (iVar4 = is_target_debug_ap(), iVar4 != 0)) {
      printf("[CW_ERROR]%32s():%4d input parameter is wrong\n","cw_priv_vap_info_list_destroy",0x7e)
      ;
    }
  }
  else {
    iVar4 = 0;
    if (*(int *)(param_1 + 4) != 0) {
      while (iVar4 < (int)(uint)*param_1) {
        iVar2 = *(int *)(param_1 + 4) + iVar4 * 0x20;
        if (iVar2 == 0) {
          if (capwap_err_switch == 0) {
            iVar4 = iVar4 + 1;
          }
          else {
            iVar2 = is_target_debug_ap();
            if (iVar2 == 0) {
              iVar4 = iVar4 + 1;
            }
            else {
              printf("[CW_ERROR]%32s():%4d input parameter is wrong\n","cw_priv_vap_info_free",0x68)
              ;
              iVar4 = iVar4 + 1;
            }
          }
        }
        else {
          while (iVar1 = FUN_004081b0(iVar2 + 0x14), iVar1 != 0) {
            FUN_00408500(iVar1);
            if (*(int *)(iVar1 + 0x10) != 0) {
              FUN_00407df0();
              *(undefined4 *)(iVar1 + 0x10) = 0;
            }
            FUN_00407df0(iVar1);
          }
          iVar4 = iVar4 + 1;
        }
      }
      FUN_00407df0();
    }
    uVar3 = 0;
    FUN_00407df0(param_1);
  }
  return uVar3;
}

