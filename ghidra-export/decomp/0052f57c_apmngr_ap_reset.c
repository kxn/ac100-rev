// func apmngr_ap_reset @ 0052f57c size=1036

undefined4 apmngr_ap_reset(ushort *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  ushort *puVar4;
  undefined4 local_368;
  undefined4 local_364;
  undefined4 local_360;
  undefined4 local_35c;
  char local_358 [88];
  undefined1 auStack_300 [12];
  undefined4 local_2f4;
  undefined2 local_2f0;
  int local_2ec;
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
  undefined2 local_80;
  int local_54;
  
  if ((apmngr_debug_switch != '\0') && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
    printf("[APMNGR_DEBUG]%s()/%d enter apmngr_ap_reset\n","apmngr_ap_reset",0xa47);
  }
  uVar3 = 0xffffffff;
  memset(auStack_300,0,0x2d8);
  local_368 = 0;
  local_364 = 0;
  local_360 = 0;
  local_35c = 0;
  local_358[0] = '\0';
  local_358[1] = '\0';
  local_358[2] = '\0';
  local_358[3] = '\0';
  local_358[4] = '\0';
  local_358[5] = '\0';
  local_358[6] = '\0';
  local_358[7] = '\0';
  local_358[8] = '\0';
  local_358[9] = '\0';
  local_358[10] = '\0';
  local_358[0xb] = '\0';
  local_358[0xc] = '\0';
  local_358[0xd] = '\0';
  local_358[0xe] = '\0';
  local_358[0xf] = '\0';
  local_358[0x10] = '\0';
  local_358[0x11] = '\0';
  local_358[0x12] = '\0';
  local_358[0x13] = '\0';
  if ((param_1 != (ushort *)0x0) && (0 < param_2)) {
    iVar1 = serv_wtp_address_arg_init(&local_368);
    if (iVar1 == 0) {
      iVar1 = 0;
      puVar4 = param_1;
      do {
        iVar2 = apmngr_db_entry_get_by_id(*puVar4,auStack_300);
        if (iVar2 == 0) {
          if (local_2ec == 5) {
            iVar2 = apmngr_db_get_cap_addr(local_2f0,&local_368,1);
            if (((iVar2 != 0) && (apmngr_err_switch != '\0')) &&
               (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
              printf("[APMNGR_ERROR]%s()/%d Failed to add entry ip-addr to struct.\n",
                     "apmngr_ap_reset",0xa7e);
            }
            if (local_54 != 0) {
              memset(local_358 + 0x14,0,0x40);
              goto LAB_0052f7c4;
            }
          }
          else if (local_54 != 0) {
            iVar2 = serv_wtp_address_arg_add
                              (&local_368,local_94,local_90,local_8c,local_88,local_84,local_80,
                               &local_2b8,0);
            if (((iVar2 != 0) && (apmngr_err_switch != '\0')) &&
               (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
              printf("[APMNGR_ERROR]%s()/%d Failed to add entry ip-addr to struct.\n",
                     "apmngr_ap_reset",0xa6c);
            }
            memset(local_358 + 0x14,0,0x40);
LAB_0052f7c4:
            FUN_00408190(local_94,local_90,local_8c,local_88,local_84,local_358 + 0x14,0x40,"---");
            snprintf(local_358,0x14,"%02X-%02X-%02X-%02X-%02X-%02X",(uint)local_2b8,(uint)local_2b7,
                     (uint)local_2b6,(uint)local_2b5,(uint)local_2b4,(uint)local_2b3);
            uVar3 = apmngr_db_product_type_str_by_ap_role(local_2ec);
            loggerk_reg(0x53,0x3d0a,1,uVar3,1,auStack_2b2,1,local_358 + 0x14,1,local_358,0);
          }
          apmngr_db_active_ap_dec(*puVar4);
          iVar2 = apmngr_db_entry_delete(*puVar4);
          if (iVar2 == 0) {
            apmngr_evt_notify(1,auStack_300);
            apmngr_evt_notify(3,auStack_300);
            apmngr_db_id_free(local_2f4,*puVar4);
          }
        }
        else {
          if ((apmngr_warning_switch != '\0') && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
            printf("[APMNGR_WARNING]%s()/%d Failed to find the entry(%d).\n","apmngr_ap_reset",0xa5f
                   ,(uint)*puVar4);
          }
          *puVar4 = 0xffff;
        }
        iVar1 = iVar1 + 1;
        puVar4 = puVar4 + 1;
      } while (iVar1 != param_2);
      apmngr_db_sync_ap_entry_del(param_1,iVar1,0);
      apmngr_db_datasync_ap_entry_del(param_1,iVar1,0);
      iVar1 = apmngr_pkt_reset_pkt_send(&local_368,3);
      if (((iVar1 != 0) && (apmngr_warning_switch != '\0')) &&
         (iVar1 = is_target_debug_ap(&local_368), iVar1 != 0)) {
        printf("[APMNGR_WARNING]%s()/%d Send Reset-Packet failed, delete ap-entry now.\n",
               "apmngr_ap_reset",0xa9c);
      }
      uVar3 = 0;
      serv_wtp_address_arg_destroy(&local_368);
    }
    else {
      serv_wtp_address_arg_destroy(&local_368);
    }
  }
  return uVar3;
}

