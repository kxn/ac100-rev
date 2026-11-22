// func cw_80211_station_create @ 00568448 size=372

int cw_80211_station_create(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  
  iVar1 = cw_protocol_clone(param_1,0x14);
  if (iVar1 == 0) {
    iVar2 = 0;
    if ((capwap_err_switch != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      printf("[CW_ERROR]%32s():%4d failed to clone value\n","cw_80211_station_create",0xed);
    }
  }
  else {
    *(undefined4 *)(iVar1 + 0x10) = 0;
    if (*(char *)(param_1 + 0xf) == '\0') {
      uVar4 = (uint)*(byte *)(iVar1 + 0xf);
    }
    else if (*(int *)(param_1 + 0x10) == 0) {
      uVar4 = (uint)*(byte *)(iVar1 + 0xf);
    }
    else {
      iVar2 = cw_protocol_clone();
      *(int *)(iVar1 + 0x10) = iVar2;
      if (iVar2 == 0) {
        if ((capwap_err_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
          printf("[CW_ERROR]%32s():%4d failed to clone supported rates\n","cw_80211_station_create",
                 0xf8);
        }
        FUN_00407df0(iVar1);
        return 0;
      }
      uVar4 = (uint)*(byte *)(iVar1 + 0xf);
    }
    iVar2 = cw_protocol_msg_ele_create(0x40c,uVar4 + 0xd,iVar1);
    if (iVar2 == 0) {
      if (capwap_err_switch == 0) {
        iVar3 = *(int *)(iVar1 + 0x10);
      }
      else {
        iVar3 = is_target_debug_ap();
        if (iVar3 == 0) {
          iVar3 = *(int *)(iVar1 + 0x10);
        }
        else {
          printf("[CW_ERROR]%32s():%4d failed to create message element\n","cw_80211_station_create"
                 ,0x102);
          iVar3 = *(int *)(iVar1 + 0x10);
        }
      }
      if (iVar3 != 0) {
        FUN_00407df0();
      }
      FUN_00407df0(iVar1);
    }
  }
  return iVar2;
}

