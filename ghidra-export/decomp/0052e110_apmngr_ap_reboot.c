// func apmngr_ap_reboot @ 0052e110 size=964

undefined4 apmngr_ap_reboot(ushort *param_1,int param_2,undefined4 param_3)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  char local_378 [36];
  undefined1 auStack_354 [16];
  undefined1 auStack_344 [68];
  undefined1 auStack_300 [12];
  undefined4 local_2f4;
  undefined2 local_2f0;
  undefined4 local_2ec;
  int local_2c4;
  byte local_2b8;
  byte local_2b7;
  byte local_2b6;
  byte local_2b5;
  byte local_2b4;
  byte local_2b3;
  undefined1 auStack_2b2 [542];
  undefined4 local_94;
  undefined4 local_90;
  undefined4 local_8c;
  undefined4 local_88;
  undefined4 local_84;
  int local_54;
  
  memset(auStack_300,0,0x2d8);
  memset(local_378 + 0x14,0,0x20);
  uVar1 = 0xffffffff;
  local_378[0] = '\0';
  local_378[1] = '\0';
  local_378[2] = '\0';
  local_378[3] = '\0';
  local_378[4] = '\0';
  local_378[5] = '\0';
  local_378[6] = '\0';
  local_378[7] = '\0';
  local_378[8] = '\0';
  local_378[9] = '\0';
  local_378[10] = '\0';
  local_378[0xb] = '\0';
  local_378[0xc] = '\0';
  local_378[0xd] = '\0';
  local_378[0xe] = '\0';
  local_378[0xf] = '\0';
  local_378[0x10] = '\0';
  local_378[0x11] = '\0';
  local_378[0x12] = '\0';
  local_378[0x13] = '\0';
  if ((param_1 != (ushort *)0x0) && (0 < param_2)) {
    iVar2 = serv_wtp_address_arg_init(local_378 + 0x14);
    if ((iVar2 == 0) && (iVar2 = serv_wtp_address_arg_init(auStack_354), iVar2 == 0)) {
      iVar2 = 0;
      do {
        iVar3 = apmngr_db_entry_get_by_id(*param_1,auStack_300);
        if (iVar3 == 0) {
          if (local_54 - 2U < 2) {
            iVar3 = multi_link_status_get(local_2f0);
            iVar4 = apmngr_db_get_addr_by_capacity
                              (local_2f0,auStack_354 + (uint)(iVar3 == 1) * 0x10 + -0x10,1,0,
                               0xffffffff,0);
            if (iVar4 == 0) {
              if (local_2c4 == 0) {
                memset(auStack_344,0,0x40);
                uVar1 = 0x3cf9;
                FUN_00408190(local_94,local_90,local_8c,local_88,local_84,auStack_344,0x40,"---");
                snprintf(local_378,0x14,"%02X-%02X-%02X-%02X-%02X-%02X",(uint)local_2b8,
                         (uint)local_2b7,(uint)local_2b6,(uint)local_2b5,(uint)local_2b4,
                         (uint)local_2b3);
                if ((iVar3 == 1) == 0) {
                  uVar1 = 0x3cf2;
                }
                uVar5 = apmngr_db_product_type_str_by_ap_role(local_2ec);
                loggerk_reg(0x53,uVar1,1,uVar5,1,auStack_2b2,1,auStack_344,1,local_378,0);
                apmngr_db_active_ap_dec(*param_1);
                iVar3 = apmngr_db_entry_delete(*param_1);
                if (iVar3 == 0) {
                  apmngr_evt_notify(1,auStack_300);
                  apmngr_evt_notify(3,auStack_300);
                  apmngr_db_id_free(local_2f4,*param_1);
                  apmngr_db_sync_ap_entry_del(param_1,1,0);
                  apmngr_db_datasync_ap_entry_del(param_1,1,0);
                }
              }
              else {
                apmngr_db_ap_reset_op_set(*param_1,param_3);
              }
            }
            else if ((apmngr_err_switch != '\0') && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
              printf("[APMNGR_ERROR]%s()/%d Failed to add entry ip-addr to struct.\n",
                     "apmngr_ap_reboot",0x909);
            }
          }
        }
        else {
          if ((apmngr_warning_switch != '\0') && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
            printf("[APMNGR_WARNING]%s()/%d Failed to find the entry(%d).\n","apmngr_ap_reboot",
                   0x8f3,(uint)*param_1);
          }
          *param_1 = 0xffff;
        }
        iVar2 = iVar2 + 1;
        param_1 = param_1 + 1;
      } while (iVar2 != param_2);
      iVar2 = 0;
      do {
        uVar1 = 2;
        if (iVar2 != 1) {
          uVar1 = 1;
        }
        iVar3 = apmngr_pkt_reset_pkt_send(auStack_354 + iVar2 * 0x10 + -0x10,uVar1);
        if (((iVar3 != 0) && (apmngr_warning_switch != '\0')) &&
           (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
          printf("[APMNGR_WARNING]%s()/%d Send Reset-Packet failed, delete ap-entry now.\n",
                 "apmngr_ap_reboot",0x932);
        }
        serv_wtp_address_arg_destroy(auStack_354 + iVar2 * 0x10 + -0x10);
        iVar2 = iVar2 + 1;
      } while (iVar2 != 2);
      uVar1 = 0;
    }
    else {
      serv_wtp_address_arg_destroy(local_378 + 0x14);
      serv_wtp_address_arg_destroy(auStack_354);
      uVar1 = 0xffffffff;
    }
  }
  return uVar1;
}

