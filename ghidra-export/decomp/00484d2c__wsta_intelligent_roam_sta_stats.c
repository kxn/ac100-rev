// func _wsta_intelligent_roam_sta_stats @ 00484d2c size=676

/* WARNING: Removing unreachable block (ram,0x00484e18) */

undefined4 _wsta_intelligent_roam_sta_stats(int param_1)

{
  int iVar1;
  ushort *puVar2;
  char *__format;
  uint uVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  ulonglong uVar6;
  undefined1 auStack_c8 [4];
  int aiStack_c4 [2];
  char local_bc;
  int local_b8;
  int local_b4;
  ushort local_b0;
  char local_ae [30];
  byte local_90;
  undefined4 local_88;
  undefined4 local_84;
  undefined4 local_80;
  undefined4 local_7c;
  undefined4 local_78;
  undefined4 local_74;
  undefined4 local_70;
  undefined4 local_6c;
  int local_68;
  int local_64;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 auStack_58 [6];
  undefined4 auStack_40 [6];
  undefined4 auStack_28 [7];
  
  memset(auStack_c8,0,0x40);
  memset(&local_88,0,0x78);
  if (param_1 == 0) {
    if (wsta_roam_err_switch == '\0') goto LAB_00484d80;
    __format = "[WSTA_ROAM_ERROR]%s()/%d inputs error.\n";
    uVar5 = 0xd01;
  }
  else if (*(char *)(param_1 + 0x34) == '\0') {
    if (wsta_roam_debug_switch == '\0') goto LAB_00484d80;
    __format = "[WSTA_ROAM_DEBUG]%s()/%d Not roam station, ignore.\n";
    uVar5 = 0xd07;
  }
  else {
    iVar1 = wsta_roam_db_sta_tmprcd_get(param_1 + 0x68,auStack_c8);
    if (iVar1 == 0) {
      uVar6 = FUN_004081f0();
      if (CONCAT44(local_b8,local_b4) < uVar6) {
        uVar3 = (uint)uVar6 - local_b4;
        if ((int)(uVar6 >> 0x20) - local_b8 == (uint)((uint)uVar6 < uVar3)) {
          if (uVar3 < 500) goto LAB_00484efc;
          if (uVar3 < 1000) {
            local_7c = 1;
            local_80 = 0;
          }
          else {
            if (2999 < uVar3) goto LAB_00484e3c;
            local_74 = 1;
            local_78 = 0;
          }
        }
        else {
LAB_00484e3c:
          local_6c = 1;
          local_70 = 0;
        }
      }
      else {
LAB_00484efc:
        local_84 = 1;
        local_88 = 0;
      }
      puVar2 = &local_b0;
      for (iVar1 = 0; iVar1 < (int)(uint)local_90; iVar1 = iVar1 + 1) {
        if ((((uint)*puVar2 == *(uint *)(param_1 + 0x20)) &&
            (*(char *)(puVar2 + 1) == *(char *)(param_1 + 0x24))) &&
           (*(char *)((int)puVar2 + 3) == *(char *)(param_1 + 0x25))) {
          local_64 = 1;
          local_68 = 0;
          goto LAB_00484ec8;
        }
        puVar2 = puVar2 + 4;
      }
      iVar1 = 0;
LAB_00484ec8:
      if ((local_68 == 0) && (local_64 == 1)) {
        puVar4 = auStack_28;
        if (aiStack_c4[1] != aiStack_c4[(iVar1 + 3) * 2]) {
          puVar4 = auStack_58;
          if (aiStack_c4[(iVar1 + 3) * 2] != 1) {
            puVar4 = auStack_40;
          }
        }
        local_bc = *(char *)(param_1 + 0x35) - local_bc;
        if (local_bc < '\x01') {
          puVar4[1] = 1;
          *puVar4 = 0;
        }
        else if (local_bc < '\x05') {
          puVar4[3] = 1;
          puVar4[2] = 0;
        }
        else {
          puVar4[5] = 1;
          puVar4[4] = 0;
        }
      }
      else {
        local_5c = 1;
        local_60 = 0;
      }
      wsta_roam_db_global_stats_cumulate(&local_88);
      wsta_roam_db_sta_tmprcd_del(param_1 + 0x68);
      goto LAB_00484d80;
    }
    if (wsta_roam_strategy_switch == '\0') goto LAB_00484d80;
    __format = "[WSTA_ROAM_STRATEGY]%s()/%d sta tmprcd not found, skip it...\n";
    uVar5 = 0xd0d;
  }
  printf(__format,"local_wsta_intelligent_roam_sta_stats",uVar5);
LAB_00484d80:
  _wsta_intelligent_roam_sta_change_ap_info(param_1);
  return 0;
}

