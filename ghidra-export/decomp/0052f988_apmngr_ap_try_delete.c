// func apmngr_ap_try_delete @ 0052f988 size=1140

void apmngr_ap_try_delete(ushort param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  ushort local_res0 [8];
  int local_340;
  char local_33c [84];
  undefined1 auStack_2e8 [12];
  undefined4 local_2dc;
  undefined4 local_2d4;
  int local_2c4;
  byte local_2a0;
  byte local_29f;
  byte local_29e;
  byte local_29d;
  byte local_29c;
  byte local_29b;
  undefined1 auStack_29a [542];
  undefined4 local_7c;
  undefined4 local_78;
  undefined4 local_74;
  undefined4 local_70;
  undefined4 local_6c;
  int local_3c;
  
  local_res0[0] = param_1;
  if ((apmngr_debug_switch != '\0') && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
    printf("[APMNGR_DEBUG]%s()/%d enter apmngr_ap_try_delete\n","apmngr_ap_try_delete",0xaa5);
  }
  memset(auStack_2e8,0,0x2d8);
  local_33c[0] = '\0';
  local_33c[1] = '\0';
  local_33c[2] = '\0';
  local_33c[3] = '\0';
  local_33c[4] = '\0';
  local_33c[5] = '\0';
  local_33c[6] = '\0';
  local_33c[7] = '\0';
  local_33c[8] = '\0';
  local_33c[9] = '\0';
  local_33c[10] = '\0';
  local_33c[0xb] = '\0';
  local_33c[0xc] = '\0';
  local_33c[0xd] = '\0';
  local_33c[0xe] = '\0';
  local_33c[0xf] = '\0';
  local_33c[0x10] = '\0';
  local_33c[0x11] = '\0';
  local_33c[0x12] = '\0';
  local_33c[0x13] = '\0';
  local_340 = 1;
  iVar1 = apmngr_db_entry_get_by_id(local_res0[0],auStack_2e8);
  if (iVar1 == 0) {
    remove_standby_ap(&local_2a0);
    if (local_3c - 2U < 2) {
      snprintf(local_33c,0x14,"%02X-%02X-%02X-%02X-%02X-%02X",(uint)local_2a0,(uint)local_29f,
               (uint)local_29e,(uint)local_29d,(uint)local_29c,(uint)local_29b);
      if (local_2c4 == 1) {
        memset(local_33c + 0x14,0,0x40);
        FUN_00408190(local_7c,local_78,local_74,local_70,local_6c,local_33c + 0x14,0x40,"---");
        uVar2 = apmngr_db_product_type_str_by_ap_role(local_2d4);
        uVar3 = 0x3cf9;
      }
      else if (local_2c4 == 2) {
        memset(local_33c + 0x14,0,0x40);
        FUN_00408190(local_7c,local_78,local_74,local_70,local_6c,local_33c + 0x14,0x40,"---");
        uVar2 = apmngr_db_product_type_str_by_ap_role(local_2d4);
        uVar3 = 0x3cf7;
      }
      else if (local_2c4 == 3) {
        memset(local_33c + 0x14,0,0x40);
        FUN_00408190(local_7c,local_78,local_74,local_70,local_6c,local_33c + 0x14,0x40,"---");
        uVar2 = apmngr_db_product_type_str_by_ap_role(local_2d4);
        uVar3 = 0x3cf8;
      }
      else if (local_2c4 == 4) {
        memset(local_33c + 0x14,0,0x40);
        FUN_00408190(local_7c,local_78,local_74,local_70,local_6c,local_33c + 0x14,0x40,"---");
        uVar2 = apmngr_db_product_type_str_by_ap_role(local_2d4);
        uVar3 = 0x3cf2;
      }
      else {
        memset(local_33c + 0x14,0,0x40);
        FUN_00408190(local_7c,local_78,local_74,local_70,local_6c,local_33c + 0x14,0x40,"---");
        uVar2 = apmngr_db_product_type_str_by_ap_role(local_2d4);
        uVar3 = 0x3cf3;
      }
      loggerk_reg(0x53,uVar3,1,uVar2,1,auStack_29a,1,local_33c + 0x14,1,local_33c,0);
    }
    iVar1 = apmngr_db_try_delete(local_res0[0],&local_340);
    if (iVar1 == 0) {
      if (local_3c - 2U < 2) {
        apmngr_evt_notify(1,auStack_2e8);
      }
      if (local_340 != 0) {
        apmngr_evt_notify(3,auStack_2e8);
        apmngr_db_entry_delete(local_res0[0]);
        apmngr_db_id_free(local_2dc,local_res0[0]);
        apmngr_db_sync_ap_entry_del(local_res0,1,0);
        apmngr_db_datasync_ap_entry_del(local_res0,1,0);
      }
    }
  }
  else if ((apmngr_warning_switch != '\0') && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
    printf("[APMNGR_WARNING]%s()/%d Failed to find the entry(%d).\n","apmngr_ap_try_delete",0xaac,
           (uint)local_res0[0]);
  }
  return;
}

