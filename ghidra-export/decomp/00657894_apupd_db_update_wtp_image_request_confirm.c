// func apupd_db_update_wtp_image_request_confirm @ 00657894 size=892

undefined4 apupd_db_update_wtp_image_request_confirm(int param_1,void *param_2)

{
  int iVar1;
  int iVar2;
  undefined4 extraout_v1;
  char *__format;
  int iVar3;
  undefined4 uVar4;
  void *__s2;
  
  if (((param_1 == 0) || (param_2 == (void *)0x0)) || (apupd_update_wtp_hash == 0)) {
    if (g_apupd_error == 0) {
      return 0xffffffff;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 0xffffffff;
    }
    printf("[APUPD_ERROR]%32s() %05d: inputs error.\r\n","apupd_db_update_wtp_image_request_confirm"
           ,0x2321);
    return 0xffffffff;
  }
  FUN_004082d0(apupd_db_mutex,0xffffffff);
  iVar1 = FUN_00407fa0(apupd_update_wtp_hash,param_1);
  if (iVar1 == 0) {
    if ((g_apupd_error == 0) || (iVar1 = is_target_debug_ap(apupd_db_mutex), iVar1 == 0))
    goto LAB_00657a60;
    __format = "[APUPD_ERROR]%32s() %05d: get update wtp by mac failed.\r\n";
    uVar4 = 0x232b;
  }
  else {
    if (1 < *(int *)(iVar1 + 0x20) - 1U) {
      if ((g_apupd_error != 0) && (iVar2 = is_target_debug_ap(apupd_db_mutex), iVar2 != 0)) {
        printf("[APUPD_ERROR]%32s() %05d: update wtp state(%d) is invalib\r\n",
               "apupd_db_update_wtp_image_request_confirm",0x2332,*(undefined4 *)(iVar1 + 0x20));
      }
      goto LAB_00657a60;
    }
    iVar3 = *(int *)(iVar1 + 0x30);
    iVar2 = *(int *)(*(int *)(iVar3 + 0x50) + 0x7ec);
    __s2 = (void *)(*(int *)(iVar3 + 0x50) + 0x1c4);
    if (iVar2 != 2) {
      if (iVar2 == 1) {
LAB_00657a08:
        iVar2 = FUN_00407fa0(*(undefined4 *)(*(int *)(iVar1 + 0x34) + 0x2c),iVar3 + 0x58);
        __s2 = (void *)(iVar2 + 0x164);
        if (iVar2 == 0) {
          if ((g_apupd_error == 0) || (iVar1 = is_target_debug_ap(apupd_db_mutex), iVar1 == 0))
          goto LAB_00657a60;
          __format = "[APUPD_ERROR]%32s() %05d: get wtp list failed.\r\n";
          uVar4 = 0x233f;
          goto LAB_00657a54;
        }
      }
      else if (iVar2 == 3) {
        __s2 = (void *)(iVar1 + 0x3c);
        if (*(int *)(iVar3 + 0x54) == 1) goto LAB_00657a08;
      }
      else {
        __s2 = (void *)(iVar1 + 0x3c);
      }
    }
    if ((*(char *)(*(int *)(*(int *)(iVar1 + 0x34) + 0x10) + 0x13a) == '\0') &&
       (iVar2 = memcmp(param_2,__s2,0x10), iVar2 != 0)) {
      if ((g_apupd_error != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
        printf("[APUPD_ERROR]%32s() %05d: current model type: %d, wtp type: %d\r\n",
               "apupd_db_update_wtp_image_request_confirm",0x234b,
               *(undefined4 *)(*(int *)(*(int *)(iVar1 + 0x30) + 0x50) + 0x7ec),
               *(undefined4 *)(*(int *)(iVar1 + 0x30) + 0x54));
      }
      if ((g_apupd_error != 0) && (iVar2 = is_target_debug_ap(apupd_db_mutex), iVar2 != 0)) {
        printf("[APUPD_ERROR]%32s() %05d: software version[%d&%d] isn\'t the same for %02X:%02X:%02X:%02X:%02X:%02X\r\n"
               ,"apupd_db_update_wtp_image_request_confirm",0x234e,*(undefined4 *)((int)param_2 + 8)
               ,*(undefined4 *)((int)__s2 + 8),(uint)*(byte *)(iVar1 + 0x18),
               (uint)*(byte *)(iVar1 + 0x19),(uint)*(byte *)(iVar1 + 0x1a),
               (uint)*(byte *)(iVar1 + 0x1b),(uint)*(byte *)(iVar1 + 0x1c),
               (uint)*(byte *)(iVar1 + 0x1d));
      }
      goto LAB_00657a60;
    }
    iVar2 = apupd_update_wtp_image_request_send(iVar1);
    if (iVar2 != -1) {
      *(undefined4 *)(iVar1 + 0x20) = 3;
      FUN_00407e70();
      *(undefined4 *)(iVar1 + 0x2c) = extraout_v1;
      if ((g_apupd_debug != 0) && (iVar1 = is_target_debug_ap(apupd_db_mutex), iVar1 != 0)) {
        printf("[APUPD_DEBUG]%32s() %05d: start sending image reqeust and enter to wait image response\r\n"
               ,"apupd_db_update_wtp_image_request_confirm",0x2359);
      }
      FUN_00407f30(apupd_db_mutex);
      return 0;
    }
    if ((g_apupd_error == 0) || (iVar1 = is_target_debug_ap(apupd_db_mutex), iVar1 == 0))
    goto LAB_00657a60;
    __format = "[APUPD_ERROR]%32s() %05d: send image request failed.\r\n";
    uVar4 = 0x2354;
  }
LAB_00657a54:
  printf(__format,"apupd_db_update_wtp_image_request_confirm",uVar4);
LAB_00657a60:
  FUN_00407f30(apupd_db_mutex);
  return 0xffffffff;
}

