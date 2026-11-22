// func apupd_db_update_wtp_image_response_confirm_by_mac @ 00657c10 size=1048

undefined4 apupd_db_update_wtp_image_response_confirm_by_mac(int param_1)

{
  char cVar1;
  int iVar2;
  int iVar3;
  undefined4 extraout_v1;
  char *pcVar4;
  int iVar5;
  undefined4 uVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  
  if ((param_1 == 0) || (apupd_update_wtp_hash == 0)) {
    if (g_apupd_error == 0) {
      return 0xffffffff;
    }
    iVar2 = is_target_debug_ap();
    if (iVar2 == 0) {
      return 0xffffffff;
    }
    printf("[APUPD_ERROR]%32s() %05d: inputs error.\r\n",
           "apupd_db_update_wtp_image_response_confirm_by_mac",0x258b);
    return 0xffffffff;
  }
  FUN_004082d0(apupd_db_mutex,0xffffffff);
  iVar2 = FUN_00407fa0(apupd_update_wtp_hash,param_1);
  if (iVar2 == 0) {
    if ((g_apupd_debug != 0) && (iVar2 = is_target_debug_ap(apupd_db_mutex), iVar2 != 0)) {
      printf("[APUPD_DEBUG]%32s() %05d: get update wtp failed.\r\n",
             "apupd_db_update_wtp_image_response_confirm_by_mac",0x2595);
    }
    goto LAB_00657cf4;
  }
  if (*(int *)(iVar2 + 0x20) == 3) {
    iVar5 = *(int *)(iVar2 + 0x30);
    if ((*(int *)(iVar5 + 0x48) == 6) || (*(int *)(iVar5 + 0x48) == 0x16)) {
      iVar8 = *(int *)(iVar5 + 0x50);
      iVar3 = *(int *)(iVar8 + 0x7ec);
      uVar9 = *(uint *)(iVar5 + 0x4c);
      if (iVar3 == 2) {
        uVar7 = *(uint *)(iVar8 + 0x1ac);
LAB_00657ccc:
        if (uVar9 != uVar7) {
          if (uVar9 < uVar7) {
            iVar5 = apupd_update_wtp_image_request_send(iVar2);
            if (iVar5 != -1) {
              FUN_00407e70();
              *(undefined4 *)(iVar2 + 0x2c) = extraout_v1;
              goto LAB_00657cf4;
            }
            if ((g_apupd_error != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
              pcVar4 = "[APUPD_ERROR]%32s() %05d: send image request failed.\r\n";
              uVar6 = 0x19b2;
              goto LAB_00657f2c;
            }
            goto LAB_00657d84;
          }
          if ((g_apupd_error == 0) || (iVar2 = is_target_debug_ap(), iVar2 == 0)) goto LAB_00657cf4;
          pcVar4 = "[APUPD_ERROR]%32s() %05d: offset(%d) is bigger than file size(%d)\r\n";
          uVar6 = 0x19ba;
LAB_00657e70:
          printf(pcVar4,"apupd_update_wtp_image_response_handle",uVar6,uVar9,uVar7);
LAB_00657cf4:
          FUN_00407f30(apupd_db_mutex);
          return 0;
        }
        if (*(char *)(iVar8 + 0x13a) == '\0') {
          iVar5 = apupd_update_wtp_last_image_response_handle(iVar2);
          if (iVar5 != -1) {
            cVar1 = *(char *)(iVar8 + 0x13a);
            goto LAB_00657e30;
          }
          if ((g_apupd_error == 0) || (iVar2 = is_target_debug_ap(), iVar2 == 0)) goto LAB_00657d84;
          pcVar4 = "[APUPD_ERROR]%32s() %05d: handle last image response failed.\r\n";
          uVar6 = 0x19a2;
        }
        else {
          cVar1 = *(char *)(iVar8 + 0x13a);
LAB_00657e30:
          if ((cVar1 != '\x01') ||
             (iVar2 = apupd_update_wtp_sub_last_image_response_handle(iVar2), iVar2 != -1)) {
            if ((g_apupd_debug == 0) || (iVar2 = is_target_debug_ap(apupd_db_mutex), iVar2 == 0))
            goto LAB_00657cf4;
            pcVar4 = "[APUPD_DEBUG]%32s() %05d: send offset = %d, file size = %d\r\n";
            uVar6 = 0x19ab;
            goto LAB_00657e70;
          }
          if ((g_apupd_error == 0) || (iVar2 = is_target_debug_ap(), iVar2 == 0)) goto LAB_00657d84;
          pcVar4 = "[APUPD_ERROR]%32s() %05d: handle sub last image response failed.\r\n";
          uVar6 = 0x19a7;
        }
LAB_00657f2c:
        printf(pcVar4,"apupd_update_wtp_image_response_handle",uVar6);
      }
      else {
        if (iVar3 != 1) {
          if (iVar3 == 3) {
            if (*(int *)(iVar5 + 0x54) == 1) goto LAB_00657dc8;
            cVar1 = *(char *)(iVar8 + 0x13a);
          }
          else {
            cVar1 = *(char *)(iVar8 + 0x13a);
          }
          if (cVar1 == '\0') {
            uVar7 = **(uint **)(iVar2 + 0x38);
          }
          else {
            uVar7 = *(uint *)(iVar8 + 0x1ac);
          }
          goto LAB_00657ccc;
        }
LAB_00657dc8:
        iVar5 = FUN_00407fa0(*(undefined4 *)(*(int *)(iVar2 + 0x34) + 0x2c),iVar5 + 0x58);
        if (iVar5 != 0) {
          uVar7 = *(uint *)(iVar5 + 0x44);
          goto LAB_00657ccc;
        }
        if ((g_apupd_error != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
          pcVar4 = "[APUPD_ERROR]%32s() %05d: get wtp list from hash failed\r\n";
          uVar6 = 0x198e;
          goto LAB_00657f2c;
        }
      }
LAB_00657d84:
      if ((g_apupd_error != 0) && (iVar2 = is_target_debug_ap(apupd_db_mutex), iVar2 != 0)) {
        printf("[APUPD_ERROR]%32s() %05d: send next packet failed.\r\n",
               "apupd_db_update_wtp_image_response_confirm_by_mac",0x25a4);
      }
      goto LAB_00657df8;
    }
  }
  if ((g_apupd_error != 0) && (iVar5 = is_target_debug_ap(apupd_db_mutex), iVar5 != 0)) {
    printf("[APUPD_ERROR]%32s() %05d: update wtp state(%d) or wtp state(%d) is invalib\r\n",
           "apupd_db_update_wtp_image_response_confirm_by_mac",0x259d,*(undefined4 *)(iVar2 + 0x20),
           *(undefined4 *)(*(int *)(iVar2 + 0x30) + 0x48));
  }
LAB_00657df8:
  FUN_00407f30(apupd_db_mutex);
  return 0xffffffff;
}

