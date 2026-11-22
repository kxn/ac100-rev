// func cw_discovery_type_create @ 00575048 size=220

int cw_discovery_type_create(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = cw_protocol_clone(param_1,1);
  if (iVar1 == 0) {
    iVar2 = 0;
    if ((capwap_err_switch != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      printf("[CW_ERROR]%32s():%4d failed to clone value\n","cw_discovery_type_create",0xbd);
    }
  }
  else {
    iVar2 = cw_protocol_msg_ele_create(0x14,1,iVar1);
    if (iVar2 == 0) {
      if ((capwap_err_switch != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
        printf("[CW_ERROR]%32s():%4d failed to create message eleemnt\n","cw_discovery_type_create",
               0xc5);
      }
      FUN_00407df0(iVar1);
    }
  }
  return iVar2;
}

