// func apupd_db_model_set @ 006565a8 size=1584

undefined4 apupd_db_model_set(int param_1,uint param_2)

{
  char cVar1;
  int iVar2;
  int iVar3;
  undefined1 uVar4;
  char *pcVar5;
  undefined4 uVar6;
  
  if ((param_1 == 0) || (apupd_model_hash == 0)) {
    if (g_apupd_error == 0) {
      return 0xffffffff;
    }
    iVar2 = is_target_debug_ap();
    if (iVar2 == 0) {
      return 0xffffffff;
    }
    printf("[APUPD_ERROR]%32s() %05d: inputs error.\r\n","apupd_db_model_set",0x1f5f);
    return 0xffffffff;
  }
  FUN_004082d0(apupd_db_mutex,0xffffffff);
  iVar2 = FUN_00407fa0(apupd_model_hash,param_1 + 0x58);
  if (iVar2 == 0) {
    if ((g_apupd_error == 0) || (iVar2 = is_target_debug_ap(apupd_db_mutex), iVar2 == 0))
    goto LAB_0065662c;
    pcVar5 = "[APUPD_ERROR]%32s() %05d: get model from hash by id failed.\r\n";
    uVar6 = 0x1f69;
    goto LAB_006567e0;
  }
  if ((g_apupd_debug != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
    printf("[APUPD_DEBUG]%32s() %05d: model(%s) type = %d\r\n","apupd_db_model_set",0x1f6d,
           param_1 + 0x5c,param_2 & 0xffff);
  }
  switch(param_2 & 0xffff) {
  case 0:
    iVar2 = apupd_model_entry_basic_set(iVar2,param_1);
    if (iVar2 != -1) goto LAB_006566e8;
    if ((g_apupd_error == 0) || (iVar2 = is_target_debug_ap(), iVar2 == 0)) goto LAB_0065662c;
    pcVar5 = "[APUPD_ERROR]%32s() %05d: set model basic failed.\r\n";
    uVar6 = 0x1f76;
    break;
  case 1:
    iVar2 = apupd_model_entry_image_set(iVar2,param_1);
    if (iVar2 != -1) goto LAB_006566e8;
    if ((g_apupd_error == 0) || (iVar2 = is_target_debug_ap(apupd_db_mutex), iVar2 == 0))
    goto LAB_0065662c;
    pcVar5 = "[APUPD_ERROR]%32s() %05d: set model image failed.\r\n";
    uVar6 = 0x1f81;
    break;
  case 2:
    iVar2 = apupd_model_entry_time_set(iVar2,param_1);
    if (iVar2 != -1) goto LAB_006566e8;
    if ((g_apupd_error == 0) || (iVar2 = is_target_debug_ap(apupd_db_mutex), iVar2 == 0))
    goto LAB_0065662c;
    pcVar5 = "[APUPD_ERROR]%32s() %05d: set model time failed.\r\n";
    uVar6 = 0x1f8c;
    break;
  case 3:
    if (g_apupd_debug == 0) {
      iVar3 = *(int *)(iVar2 + 0x58);
    }
    else {
      iVar3 = is_target_debug_ap();
      if (iVar3 == 0) {
        iVar3 = *(int *)(iVar2 + 0x58);
      }
      else {
        printf("[APUPD_DEBUG]%32s() %05d: apupd_model_entry_all_set\r\n","apupd_model_entry_all_set"
               ,0xb7e);
        iVar3 = *(int *)(iVar2 + 0x58);
      }
    }
    if (iVar3 == *(int *)(param_1 + 0x58)) {
      iVar3 = apupd_model_entry_image_set(iVar2,param_1);
      if (((iVar3 != -1) && (iVar3 = apupd_model_entry_time_set(iVar2,param_1), iVar3 != -1)) &&
         (iVar3 = apupd_model_entry_basic_set(iVar2,param_1), iVar2 = apupd_db_mutex, iVar3 != -1))
      goto LAB_006566e8;
      if ((g_apupd_error != 0) && (iVar2 = is_target_debug_ap(iVar2), iVar2 != 0)) {
        pcVar5 = "[APUPD_ERROR]%32s() %05d: set model all failed.\r\n";
        uVar6 = 0xb8a;
        goto LAB_00656a68;
      }
    }
    else if ((g_apupd_error != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
      pcVar5 = "[APUPD_ERROR]%32s() %05d: inputs error.\r\n";
      uVar6 = 0xb82;
LAB_00656a68:
      printf(pcVar5,"apupd_model_entry_all_set",uVar6);
    }
    if ((g_apupd_error == 0) || (iVar2 = is_target_debug_ap(apupd_db_mutex), iVar2 == 0))
    goto LAB_0065662c;
    pcVar5 = "[APUPD_ERROR]%32s() %05d: set model all failed.\r\n";
    uVar6 = 0x1f97;
    break;
  case 4:
    if (*(int *)(iVar2 + 0x58) == *(int *)(param_1 + 0x58)) {
      if ((g_apupd_debug != 0) && (iVar3 = is_target_debug_ap(iVar2), iVar3 != 0)) {
        printf("[APUPD_DEBUG]%32s() %05d: apupd_model_entry_image_and_time_set\r\n",
               "apupd_model_entry_image_and_time_set",0xba3);
      }
      iVar3 = apupd_model_entry_image_set(iVar2,param_1);
      if ((iVar3 != -1) &&
         (iVar3 = apupd_model_entry_time_set(iVar2,param_1), iVar2 = apupd_db_mutex, iVar3 != -1))
      goto LAB_006566e8;
      if ((g_apupd_error != 0) && (iVar2 = is_target_debug_ap(iVar2), iVar2 != 0)) {
        pcVar5 = "[APUPD_ERROR]%32s() %05d: set model all failed.\r\n";
        uVar6 = 0xba8;
        goto LAB_00656a88;
      }
    }
    else if ((g_apupd_error != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
      pcVar5 = "[APUPD_ERROR]%32s() %05d: inputs error.\r\n";
      uVar6 = 0xba0;
LAB_00656a88:
      printf(pcVar5,"apupd_model_entry_image_and_time_set",uVar6);
    }
    if ((g_apupd_error == 0) || (iVar2 = is_target_debug_ap(apupd_db_mutex), iVar2 == 0))
    goto LAB_0065662c;
    pcVar5 = "[APUPD_ERROR]%32s() %05d: set model all failed.\r\n";
    uVar6 = 0x1fa0;
    break;
  case 5:
    memset((void *)(iVar2 + 0x18),0,0x40);
    memcpy((void *)(iVar2 + 0x18),(void *)(param_1 + 0x18),0x40);
    goto LAB_006566e8;
  case 6:
    *(undefined1 *)(iVar2 + 0x139) = *(undefined1 *)(param_1 + 0x139);
    goto LAB_006566e8;
  case 7:
    cVar1 = *(char *)(param_1 + 0x13a);
    *(char *)(iVar2 + 0x13a) = cVar1;
    if (cVar1 == '\x01') {
      *(undefined4 *)(iVar2 + 0x188) = *(undefined4 *)(param_1 + 0x188);
      *(undefined4 *)(iVar2 + 0x18c) = *(undefined4 *)(param_1 + 0x18c);
      memcpy((void *)(iVar2 + 400),(void *)(param_1 + 400),0x10);
    }
    else {
      *(undefined4 *)(iVar2 + 0x188) = 0;
      *(undefined4 *)(iVar2 + 0x18c) = 0;
      memset((void *)(iVar2 + 400),0,0x10);
    }
    if (g_apupd_debug == 0) {
      *(undefined1 *)(iVar2 + 0x1a0) = 0;
    }
    else {
      iVar3 = is_target_debug_ap();
      if (iVar3 == 0) {
        *(undefined1 *)(iVar2 + 0x1a0) = 0;
      }
      else {
        printf("[APUPD_DEBUG]%32s() %05d: model: %s, total_image_piece = %d, is_large_fw = %d\r\n",
               "apupd_model_entry_is_large_image_set",0xb69,iVar2 + 0x5c,
               *(undefined4 *)(iVar2 + 0x18c),(uint)*(byte *)(iVar2 + 0x13a));
        *(undefined1 *)(iVar2 + 0x1a0) = 0;
      }
    }
    *(undefined4 *)(iVar2 + 0x1a4) = 0;
    *(undefined4 *)(iVar2 + 0x1a8) = 0;
    goto LAB_006566e8;
  case 8:
    if (g_apupd_debug == 0) {
      uVar4 = *(undefined1 *)(param_1 + 0x1a1);
    }
    else {
      iVar3 = is_target_debug_ap();
      if (iVar3 == 0) {
        uVar4 = *(undefined1 *)(param_1 + 0x1a1);
      }
      else {
        printf("[APUPD_DEBUG]%32s() %05d: set model can_down_sub_image = %d.\r\n",
               "apupd_db_model_set",0x1fb9,(uint)*(byte *)(param_1 + 0x1a1));
        uVar4 = *(undefined1 *)(param_1 + 0x1a1);
      }
    }
    *(undefined1 *)(iVar2 + 0x1a1) = uVar4;
LAB_006566e8:
    FUN_00407f30(apupd_db_mutex);
    return 0;
  default:
    if ((g_apupd_error == 0) || (iVar2 = is_target_debug_ap(apupd_db_mutex), iVar2 == 0))
    goto LAB_0065662c;
    pcVar5 = "[APUPD_ERROR]%32s() %05d: model set type error.\r\n";
    uVar6 = 0x1fbf;
  }
LAB_006567e0:
  printf(pcVar5,"apupd_db_model_set",uVar6);
LAB_0065662c:
  FUN_00407f30(apupd_db_mutex);
  return 0xffffffff;
}

