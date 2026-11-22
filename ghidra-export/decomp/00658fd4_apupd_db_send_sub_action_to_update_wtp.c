// func apupd_db_send_sub_action_to_update_wtp @ 00658fd4 size=572

int apupd_db_send_sub_action_to_update_wtp
              (undefined4 param_1,uint param_2,uint param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 local_res0 [4];
  undefined1 auStack_300 [16];
  undefined2 local_2f0;
  
  local_res0[0] = param_1;
  memset(auStack_300,0,0x2d8);
  if ((g_apupd_debug != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
    printf("[APUPD_DEBUG]%32s() %05d: model_id = %d, type = %d, file_num = %d, result = %d\r\n",
           "apupd_db_send_sub_action_to_update_wtp",0x2872,local_res0[0],param_2 & 0xff,
           param_3 & 0xff,param_4);
  }
  iVar1 = FUN_00407fa0(apupd_update_model_hash,local_res0);
  if (iVar1 == 0) {
    iVar3 = -1;
    if ((g_apupd_debug != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      printf("[APUPD_DEBUG]%32s() %05d: no update model need delete.\r\n",
             "apupd_db_send_sub_action_to_update_wtp",0x2877);
    }
  }
  else {
    iVar1 = FUN_004081b0(iVar1 + 0x14);
    while (iVar3 = iVar1, iVar3 != 0) {
      iVar1 = FUN_00408680(iVar3);
      iVar2 = apmngr_db_entry_get_by_mac(*(int *)(iVar3 + 0x24) + 0x2e,auStack_300);
      if (iVar2 == 0) {
        iVar2 = apupd_sub_image_action_send(local_2f0,param_2 & 0xff,param_3 & 0xff,param_4);
        if (((iVar2 == -1) && (g_apupd_error != 0)) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
          printf("[APUPD_ERROR]%32s() %05d: send sub image action packet failed.\r\n",
                 "apupd_db_send_sub_action_to_update_wtp",0x288a);
          *(undefined4 *)(iVar3 + 0x18) = 7;
        }
        else {
          *(undefined4 *)(iVar3 + 0x18) = 7;
        }
      }
      else if ((g_apupd_error != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
        printf("[APUPD_ERROR]%32s() %05d: get ap_entry by mac[%02X:%02X:%02X:%02X:%02X:%02X] failed.\r\n"
               ,"apupd_db_send_sub_action_to_update_wtp",0x2883,(uint)*(byte *)(iVar3 + 0xc),
               (uint)*(byte *)(iVar3 + 0xd),(uint)*(byte *)(iVar3 + 0xe),
               (uint)*(byte *)(iVar3 + 0xf),(uint)*(byte *)(iVar3 + 0x10),
               (uint)*(byte *)(iVar3 + 0x11));
      }
    }
  }
  return iVar3;
}

