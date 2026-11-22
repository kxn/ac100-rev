// func apmngr_ap_delete @ 0052e7d8 size=1316

undefined4 apmngr_ap_delete(ushort *param_1,int param_2,int param_3,undefined4 param_4,int param_5)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  ushort *puVar5;
  undefined4 local_378;
  undefined4 local_374;
  undefined4 local_370;
  undefined4 local_36c;
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
    printf("[APMNGR_DEBUG]%s()/%d enter apmngr_ap_delete\n","apmngr_ap_delete",0x93d);
  }
  memset(auStack_300,0,0x2d8);
  local_368 = 0;
  local_364 = 0;
  local_360 = 0;
  local_35c = 0;
  local_378 = 0;
  local_374 = 0;
  local_370 = 0;
  local_36c = 0;
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
    puVar4 = &local_368;
    if (iVar1 == 0) {
      iVar1 = serv_wtp_address_arg_init(&local_378);
      puVar4 = &local_378;
      if (iVar1 == 0) {
        iVar1 = 0;
        puVar5 = param_1;
        do {
          iVar2 = apmngr_db_entry_get_by_id(*puVar5,auStack_300);
          if (iVar2 == 0) {
            if (local_2ec == 5) {
              iVar2 = apmngr_db_get_cap_addr(local_2f0,&local_368,1);
              if (((iVar2 != 0) && (apmngr_err_switch != '\0')) &&
                 (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
                printf("[APMNGR_ERROR]%s()/%d Failed to add entry ip-addr to struct.\n",
                       "apmngr_ap_delete",0x986);
              }
              if ((local_54 != 0) && (param_3 != 0)) {
                memset(local_358 + 0x14,0,0x40);
LAB_0052eac4:
                FUN_00408190(local_94,local_90,local_8c,local_88,local_84,local_358 + 0x14,0x40,
                             "---");
                snprintf(local_358,0x14,"%02X-%02X-%02X-%02X-%02X-%02X",(uint)local_2b8,
                         (uint)local_2b7,(uint)local_2b6,(uint)local_2b5,(uint)local_2b4,
                         (uint)local_2b3);
                uVar3 = apmngr_db_product_type_str_by_ap_role(local_2ec);
                loggerk_reg(0x53,param_4,1,uVar3,1,auStack_2b2,1,local_358 + 0x14,1,local_358,0);
              }
            }
            else if (local_54 != 0) {
              if (local_2ec - 2U < 2) {
                iVar2 = serv_wtp_address_arg_add
                                  (&local_378,local_94,local_90,local_8c,local_88,local_84,local_80,
                                   &local_2b8,0);
                if (((iVar2 != 0) && (apmngr_err_switch != '\0')) &&
                   (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
                  uVar3 = 0x96a;
                  goto LAB_0052ec84;
                }
              }
              else {
                iVar2 = serv_wtp_address_arg_add
                                  (&local_368,local_94,local_90,local_8c,local_88,local_84,local_80,
                                   &local_2b8,0);
                if (((iVar2 != 0) && (apmngr_err_switch != '\0')) &&
                   (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
                  uVar3 = 0x971;
LAB_0052ec84:
                  printf("[APMNGR_ERROR]%s()/%d Failed to add entry ip-addr to struct.\n",
                         "apmngr_ap_delete",uVar3);
                }
              }
              if (param_3 != 0) {
                memset(local_358 + 0x14,0,0x40);
                goto LAB_0052eac4;
              }
            }
            apmngr_db_active_ap_dec(*puVar5);
            iVar2 = apmngr_db_entry_delete(*puVar5);
            if (iVar2 == 0) {
              apmngr_evt_notify(1,auStack_300);
              apmngr_evt_notify(3,auStack_300);
              apmngr_db_id_free(local_2f4,*puVar5);
            }
          }
          else {
            if ((apmngr_warning_switch != '\0') && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
              printf("[APMNGR_WARNING]%s()/%d Failed to find the entry(%d).\n","apmngr_ap_delete",
                     0x95b,(uint)*puVar5);
            }
            *puVar5 = 0xffff;
          }
          iVar1 = iVar1 + 1;
          puVar5 = puVar5 + 1;
          if (iVar1 == param_2) {
            if (param_5 != 0) {
              apmngr_db_sync_ap_entry_del(param_1,iVar1,0);
              apmngr_db_datasync_ap_entry_del(param_1,iVar1,0);
            }
            iVar1 = apmngr_pkt_reset_pkt_send(&local_368,1);
            if (((iVar1 != 0) && (apmngr_warning_switch != '\0')) &&
               (iVar1 = is_target_debug_ap(&local_378), iVar1 != 0)) {
              printf("[APMNGR_WARNING]%s()/%d Send Reset-Packet failed, delete ap-entry now.\n",
                     "apmngr_ap_delete",0x9aa);
            }
            iVar1 = apmngr_pkt_reset_pkt_send(&local_378,3);
            if (((iVar1 != 0) && (apmngr_warning_switch != '\0')) &&
               (iVar1 = is_target_debug_ap(&local_368), iVar1 != 0)) {
              printf("[APMNGR_WARNING]%s()/%d Send Reset-Packet failed, delete ap-entry now.\n",
                     "apmngr_ap_delete",0x9ae);
            }
            serv_wtp_address_arg_destroy(&local_368);
            serv_wtp_address_arg_destroy(&local_378);
            return 0;
          }
        } while( true );
      }
    }
    serv_wtp_address_arg_destroy(puVar4);
  }
  return 0xffffffff;
}

