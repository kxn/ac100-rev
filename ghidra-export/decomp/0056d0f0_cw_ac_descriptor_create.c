// func cw_ac_descriptor_create @ 0056d0f0 size=524

int cw_ac_descriptor_create(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  char *__format;
  undefined4 uVar5;
  short sVar6;
  
  iVar1 = cw_protocol_clone(param_1,0x18);
  if (iVar1 == 0) {
    iVar2 = 0;
    if ((capwap_err_switch != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      printf("[CW_ERROR]%32s():%4d failed to clone value\n","cw_ac_descriptor_create",0x19b);
    }
  }
  else {
    sVar6 = 0xc;
    FUN_0051ad88(iVar1 + 0xc);
    for (iVar2 = FUN_004081b0(param_1 + 0xc); iVar2 != 0; iVar2 = FUN_00408680(iVar2)) {
      iVar3 = cw_protocol_clone(iVar2,0x18);
      if (iVar3 == 0) {
        if ((capwap_err_switch == 0) || (iVar2 = is_target_debug_ap(), iVar2 == 0))
        goto LAB_0056d23c;
        __format = "[CW_ERROR]%32s():%4d failed to clone subelement value\n";
        uVar5 = 0x1a9;
LAB_0056d26c:
        printf(__format,"cw_ac_descriptor_create",uVar5);
LAB_0056d23c:
        cw_ac_descriptor_val_free(iVar1);
        return 0;
      }
      *(undefined4 *)(iVar3 + 0x14) = 0;
      if ((*(short *)(iVar2 + 0x12) != 0) && (*(int *)(iVar2 + 0x14) != 0)) {
        iVar4 = cw_protocol_duplicate_string();
        *(int *)(iVar3 + 0x14) = iVar4;
        if (iVar4 == 0) {
          if ((capwap_err_switch == 0) || (iVar2 = is_target_debug_ap(), iVar2 == 0))
          goto LAB_0056d23c;
          __format = "[CW_ERROR]%32s():%4d failed to clone subelement data\n";
          uVar5 = 0x1b5;
          goto LAB_0056d26c;
        }
      }
      FUN_004086b0(iVar1 + 0xc,iVar3);
      sVar6 = sVar6 + *(short *)(iVar3 + 0x12) + 8;
    }
    iVar2 = cw_protocol_msg_ele_create(1,sVar6,iVar1);
    if (iVar2 == 0) {
      if ((capwap_err_switch != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
        printf("[CW_ERROR]%32s():%4d failed to create message element\n","cw_ac_descriptor_create",
               0x1c2);
      }
      cw_ac_descriptor_val_free(iVar1);
    }
  }
  return iVar2;
}

