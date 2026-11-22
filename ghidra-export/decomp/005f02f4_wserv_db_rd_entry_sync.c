// func wserv_db_rd_entry_sync @ 005f02f4 size=1628

undefined4
wserv_db_rd_entry_sync
          (int param_1,undefined4 param_2,int param_3,undefined4 param_4,undefined4 param_5,
          int *param_6,int param_7)

{
  bool bVar1;
  bool bVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  void *__s;
  undefined4 uVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  int *piVar10;
  int iVar11;
  void *pvVar12;
  uint uVar13;
  int iVar14;
  int iVar15;
  int iVar16;
  undefined4 local_60;
  short local_5c;
  undefined4 local_58;
  short local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  uint local_44;
  int local_40;
  int local_3c;
  int local_38;
  int local_34;
  int local_30;
  
  if ((g_wserv_debug != 0) && (iVar14 = is_target_debug_ap(), iVar14 != 0)) {
    printf("<wserv>[debug]%s(): %d  -> wserv_db_rd_entry_sync cap_rd_id: %d, re_rd_id: %d\r\n",
           "wserv_db_rd_entry_sync",0xedf,param_1,param_2);
  }
  local_58 = 0;
  local_54 = 0;
  iVar14 = 0;
  local_60 = 0;
  local_5c = 0;
  local_48 = 0;
  local_44 = 0;
  local_40 = 0;
  local_3c = 0;
  local_50 = 0;
  local_4c = 0;
  if (param_1 != -1) {
    iVar14 = rdmngr_db_rd_entry_max_ssid_get(param_1);
  }
  iVar3 = rdmngr_db_rd_entry_max_ssid_get(param_2);
  iVar15 = 0;
  if (param_1 != -1) {
    iVar15 = rdmngr_db_generate_rd_idx_by_rd_id(param_1);
  }
  iVar4 = rdmngr_db_generate_rd_idx_by_rd_id(param_2);
  iVar5 = rdmngr_profile_get_max_wlan_per_rd();
  __s = (void *)FUN_00408450(iVar5 * 6,0xef0);
  uVar6 = 0xffffffff;
  if (__s != (void *)0x0) {
    iVar5 = rdmngr_profile_get_max_wlan_per_rd();
    memset(__s,0,iVar5 * 6);
    if (param_3 == 0) {
      local_38 = iVar4 * 0xc;
      iVar5 = iVar14 * 6;
      for (iVar4 = iVar14; iVar4 < iVar3; iVar4 = iVar4 + 1) {
        FUN_004082d0(DAT_007cbef0,0xffffffff);
        memcpy(&local_60,(void *)(*(int *)(DAT_007cbf04 + local_38 + 8) + iVar5),6);
        FUN_00407f30(DAT_007cbef0);
        if (local_60._2_2_ != -1) {
          wserv_db_rd_unbind(param_2,(int)local_60._2_2_,param_5);
          local_4c = CONCAT13((char)iVar4 + '\x01',local_4c._1_3_);
          local_50 = param_2;
          wserv_sqlite_notify(3,&local_50,8);
        }
        iVar5 = iVar5 + 6;
      }
      iVar4 = 0;
      local_34 = iVar15 * 0xc;
      uVar13 = 0;
      while (((uVar8 = rdmngr_profile_get_max_wlan_per_rd(), uVar13 < uVar8 &&
              ((int)uVar13 < iVar14)) && ((int)uVar13 < iVar3))) {
        FUN_004082d0(DAT_007cbef0,0xffffffff);
        iVar15 = DAT_007cbf04;
        memcpy(&local_58,(void *)(*(int *)(DAT_007cbf04 + local_34 + 8) + uVar13 * 6),6);
        memcpy(&local_60,(void *)(*(int *)(iVar15 + local_38 + 8) + uVar13 * 6),6);
        iVar5 = (int)local_58._2_2_;
        iVar16 = *(int *)(DAT_007cbefc + iVar5 * 0x21c + 299);
        FUN_00407f30(DAT_007cbef0);
        iVar15 = (int)local_60._2_2_;
        if ((iVar5 == iVar15) && (local_54 == local_5c)) {
          uVar13 = uVar13 + 1;
        }
        else {
          if (iVar15 != -1) {
            wserv_db_rd_unbind(param_2,iVar15,param_5);
            local_4c = CONCAT13(local_58._1_1_,local_4c._1_3_);
            local_50 = param_2;
            wserv_sqlite_notify(3,&local_50,8);
          }
          if ((iVar5 == -1) || (iVar16 != 1)) {
            uVar13 = uVar13 + 1;
          }
          else {
            iVar15 = iVar4 * 6;
            iVar4 = iVar4 + 1;
            uVar13 = uVar13 + 1;
            memcpy((void *)((int)__s + iVar15),&local_58,6);
          }
        }
      }
      pvVar12 = __s;
      for (iVar14 = 0; iVar14 < iVar4; iVar14 = iVar14 + 1) {
        wserv_db_rd_bind_with_wlan_id
                  (param_2,*(undefined1 *)((int)pvVar12 + 1),(int)*(short *)((int)pvVar12 + 2),
                   (int)*(short *)((int)pvVar12 + 4),param_4);
        local_44 = (uint)*(byte *)((int)pvVar12 + 1);
        local_40 = (int)*(short *)((int)pvVar12 + 2);
        local_3c = (int)*(short *)((int)pvVar12 + 4);
        pvVar12 = (void *)((int)pvVar12 + 6);
        local_48 = param_2;
        wserv_sqlite_notify(2,&local_48,0x10);
      }
    }
    else {
      local_30 = iVar15 * 0xc;
      iVar5 = 0;
      iVar16 = 0;
      local_38 = iVar4 * 0xc;
      iVar15 = param_7;
      while ((iVar5 < iVar14 && (iVar15 < iVar3))) {
        FUN_004082d0(DAT_007cbef0,0xffffffff);
        iVar4 = DAT_007cbf04;
        memcpy(&local_58,(void *)(*(int *)(DAT_007cbf04 + local_30 + 8) + iVar5 * 6),6);
        iVar7 = 0;
        iVar9 = (int)local_58._2_2_;
        piVar10 = param_6;
        do {
          if (param_7 <= iVar7) {
            bVar1 = false;
            goto LAB_005f048c;
          }
          iVar11 = *piVar10;
          iVar7 = iVar7 + 1;
          piVar10 = piVar10 + 1;
        } while (iVar11 != iVar9);
        bVar1 = true;
LAB_005f048c:
        bVar2 = false;
        if (((iVar9 != -1) && (*(int *)(DAT_007cbefc + iVar9 * 0x21c + 299) != 0)) && (!bVar1)) {
          bVar2 = true;
          memcpy(&local_60,(void *)(*(int *)(iVar4 + local_38 + 8) + iVar15 * 6),6);
        }
        FUN_00407f30(DAT_007cbef0);
        if (bVar2) {
          iVar4 = (int)local_60._2_2_;
          if ((local_58._2_2_ != iVar4) || (local_54 != local_5c)) {
            if (iVar4 != -1) {
              wserv_db_rd_unbind_with_wlan_id(param_2,iVar15 + 1U & 0xff,iVar4,param_5);
              local_4c = CONCAT13((char)(iVar15 + 1U),local_4c._1_3_);
              local_50 = param_2;
              wserv_sqlite_notify(3,&local_50,8);
            }
            iVar4 = iVar16 * 6;
            iVar16 = iVar16 + 1;
            pvVar12 = (void *)((int)__s + iVar4);
            memcpy(pvVar12,&local_58,6);
            *(char *)((int)pvVar12 + 1) = (char)iVar15 + '\x01';
          }
          iVar15 = iVar15 + 1;
          iVar5 = iVar5 + 1;
        }
        else {
          iVar5 = iVar5 + 1;
        }
      }
      iVar14 = iVar15 * 6;
      for (; iVar15 < iVar3; iVar15 = iVar15 + 1) {
        FUN_004082d0(DAT_007cbef0,0xffffffff);
        memcpy(&local_60,(void *)(*(int *)(DAT_007cbf04 + local_38 + 8) + iVar14),6);
        FUN_00407f30(DAT_007cbef0);
        if (local_60._2_2_ != -1) {
          wserv_db_rd_unbind_with_wlan_id(param_2,iVar15 + 1U & 0xff,(int)local_60._2_2_,param_5);
          local_4c = CONCAT13((char)(iVar15 + 1U),local_4c._1_3_);
          local_50 = param_2;
          wserv_sqlite_notify(3,&local_50,8);
        }
        iVar14 = iVar14 + 6;
      }
      pvVar12 = __s;
      for (iVar14 = 0; iVar14 < iVar16; iVar14 = iVar14 + 1) {
        wserv_db_rd_bind_with_wlan_id
                  (param_2,*(undefined1 *)((int)pvVar12 + 1),(int)*(short *)((int)pvVar12 + 2),
                   (int)*(short *)((int)pvVar12 + 4),param_4);
        local_44 = (uint)*(byte *)((int)pvVar12 + 1);
        local_40 = (int)*(short *)((int)pvVar12 + 2);
        local_3c = (int)*(short *)((int)pvVar12 + 4);
        pvVar12 = (void *)((int)pvVar12 + 6);
        local_48 = param_2;
        wserv_sqlite_notify(2,&local_48,0x10);
      }
    }
    FUN_00407df0(__s);
    uVar6 = 0;
  }
  return uVar6;
}

