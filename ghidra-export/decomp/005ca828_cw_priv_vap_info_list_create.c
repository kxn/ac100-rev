// func cw_priv_vap_info_list_create @ 005ca828 size=668

int cw_priv_vap_info_list_create(byte *param_1)

{
  char *pcVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  char *__format;
  undefined4 uVar5;
  uint uVar6;
  short sVar7;
  int iVar8;
  int iVar9;
  
  pcVar1 = (char *)cw_protocol_clone(param_1,8);
  if (pcVar1 == (char *)0x0) {
    if (capwap_err_switch == 0) {
      return 0;
    }
    iVar2 = is_target_debug_ap();
    if (iVar2 == 0) {
      return 0;
    }
    printf("[CW_ERROR]%32s():%4d failed to clone value\n","cw_priv_vap_info_list_create",0x150);
    return 0;
  }
  pcVar1[4] = '\0';
  pcVar1[5] = '\0';
  pcVar1[6] = '\0';
  pcVar1[7] = '\0';
  sVar7 = 1;
  if (*param_1 == 0) {
LAB_005ca9a4:
    iVar2 = cw_protocol_msg_ele_create(0x8c,sVar7,pcVar1);
    if (iVar2 != 0) {
      return iVar2;
    }
    if ((capwap_err_switch == 0) || (iVar2 = is_target_debug_ap(), iVar2 == 0)) goto LAB_005ca968;
    __format = "[CW_ERROR]%32s():%4d failed to create message eleemnt\n";
    uVar5 = 0x181;
  }
  else if (*(int *)(param_1 + 4) == 0) {
    if ((capwap_err_switch == 0) || (iVar2 = is_target_debug_ap(), iVar2 == 0)) goto LAB_005ca968;
    __format = "[CW_ERROR]%32s():%4d Input error\n";
    uVar5 = 0x159;
  }
  else {
    iVar2 = cw_protocol_clone(*(int *)(param_1 + 4),(uint)*param_1 << 5);
    *(int *)(pcVar1 + 4) = iVar2;
    if (iVar2 != 0) {
      *pcVar1 = '\0';
      sVar7 = 1;
      for (uVar6 = 0; uVar6 < *param_1; uVar6 = uVar6 + 1 & 0xffff) {
        iVar8 = uVar6 * 0x20;
        *pcVar1 = *pcVar1 + '\x01';
        iVar2 = *(int *)(param_1 + 4);
        iVar9 = *(int *)(pcVar1 + 4) + iVar8 + 0x14;
        FUN_0051ad88(iVar9);
        for (iVar2 = FUN_004081b0(iVar2 + iVar8 + 0x14); iVar2 != 0; iVar2 = FUN_00408680(iVar2)) {
          iVar3 = cw_protocol_clone(iVar2,0x14);
          FUN_004086b0(iVar9,iVar3);
          *(undefined4 *)(iVar3 + 0x10) = 0;
          if (*(short *)(iVar2 + 0xe) != 0) {
            iVar4 = cw_protocol_clone(*(undefined4 *)(iVar2 + 0x10));
            *(int *)(iVar3 + 0x10) = iVar4;
            if (iVar4 == 0) {
              if ((capwap_err_switch == 0) || (iVar2 = is_target_debug_ap(), iVar2 == 0))
              goto LAB_005ca968;
              __format = "[CW_ERROR]%32s():%4d Malloc failed\n";
              uVar5 = 0x174;
              goto LAB_005caa50;
            }
          }
        }
        sVar7 = sVar7 + *(short *)(*(int *)(pcVar1 + 4) + iVar8 + 0x10) + 0x10;
      }
      goto LAB_005ca9a4;
    }
    if ((capwap_err_switch == 0) || (iVar2 = is_target_debug_ap(), iVar2 == 0)) goto LAB_005ca968;
    __format = "[CW_ERROR]%32s():%4d failed to clone value\n";
    uVar5 = 0x15f;
  }
LAB_005caa50:
  printf(__format,"cw_priv_vap_info_list_create",uVar5);
LAB_005ca968:
  cw_priv_vap_info_list_destroy(pcVar1);
  return 0;
}

