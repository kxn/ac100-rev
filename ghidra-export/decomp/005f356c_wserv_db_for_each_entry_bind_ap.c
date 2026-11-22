// func wserv_db_for_each_entry_bind_ap @ 005f356c size=1160

undefined4
wserv_db_for_each_entry_bind_ap(uint param_1,uint param_2,code *param_3,undefined4 param_4)

{
  undefined2 uVar1;
  uint uVar2;
  int iVar3;
  uint *puVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  char *pcVar9;
  int iVar10;
  undefined4 uVar11;
  char cVar12;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  int local_40;
  uint local_3c;
  uint *local_38;
  int local_34;
  int local_30;
  int local_2c;
  
  uVar11 = 0;
  local_50 = 0;
  local_4c = 0;
  local_48 = 0;
  local_2c = apmngr_db_capacity_support(param_1 & 0xffff,1,0x3f);
  if (param_3 != (code *)0x0) {
    uVar2 = rdmngr_profile_get_max_rd_per_ap();
    if (uVar2 < param_2) {
      uVar11 = 0xffffffff;
      if ((g_wserv_error != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
        printf("<wserv>[warning]%s(): %d  -> invalid rd_cnt[%d]!\r\n",
               "wserv_db_for_each_entry_bind_ap",0x14df,param_2);
      }
    }
    else {
      uVar11 = rdmngr_profile_get_max_rd_per_ap();
      puVar4 = (uint *)wserv_calloc(uVar11,4);
      if (puVar4 == (uint *)0x0) {
        uVar11 = 0xffffffff;
        if ((g_wserv_error != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
          printf("<wserv>[warning]%s(): %d  -> no memory!\r\n","wserv_db_for_each_entry_bind_ap",
                 0x14e6);
        }
      }
      else {
        iVar10 = 1;
        iVar3 = 0;
        while (iVar10 <= (int)param_2) {
          uVar2 = rdmngr_db_generate_rd_id(param_1,iVar10);
          iVar5 = _wserv_is_rd_enable(uVar2);
          iVar10 = iVar10 + 1;
          if (iVar5 != 0) {
            puVar4[iVar3] = uVar2;
            iVar3 = iVar3 + 1;
          }
        }
        FUN_0051ad88(&local_50);
        FUN_004082d0(DAT_007cbef0,0xffffffff);
        local_38 = puVar4;
        for (local_40 = 0; uVar11 = 0, local_40 < iVar3; local_40 = local_40 + 1) {
          local_3c = *local_38;
          uVar2 = rdmngr_db_generate_rd_idx_by_rd_id(local_3c);
          if ((int)uVar2 < 0) {
LAB_005f3788:
            if ((g_wserv_warning != 0) && (iVar10 = is_target_debug_ap(), iVar10 != 0)) {
              pcVar9 = "<wserv>[warning]%s(): %d  -> rd_id[%d] is invalid!\r\n";
              uVar11 = 0x14fc;
              uVar2 = local_3c;
LAB_005f37b8:
              printf(pcVar9,"wserv_db_for_each_entry_bind_ap",uVar11,uVar2);
            }
          }
          else {
            iVar10 = apmngr_db_get_ap_max();
            iVar5 = apmngr_db_get_template_max();
            iVar6 = apmngr_db_get_sensor_max();
            iVar7 = rdmngr_profile_get_max_rd_per_ap();
            if ((uint)((iVar10 + iVar5 + iVar6) * iVar7) <= uVar2) goto LAB_005f3788;
            iVar10 = uVar2 * 0xc;
            cVar12 = '\x01';
            if (*(char *)(DAT_007cbf04 + iVar10) == '\0') {
              if ((g_wserv_warning == 0) || (iVar10 = is_target_debug_ap(), iVar10 == 0))
              goto LAB_005f3744;
              pcVar9 = "<wserv>[warning]%s(): %d  -> idx[%d] is not used!\r\n";
              uVar11 = 0x1502;
              goto LAB_005f37b8;
            }
            uVar2 = 0;
            while (uVar8 = rdmngr_profile_get_max_wlan_per_rd(), uVar2 < uVar8) {
              local_30 = uVar2 * 6;
              pcVar9 = (char *)(*(int *)(DAT_007cbf04 + iVar10 + 8) + local_30);
              uVar8 = (uint)*(short *)(pcVar9 + 2);
              if (((*pcVar9 == '\0') || ((int)uVar8 < 0)) || (l_wserv_profile <= uVar8)) {
LAB_005f38c8:
                uVar2 = uVar2 + 1;
                cVar12 = cVar12 + '\x01';
              }
              else {
                local_34 = uVar8 * 0x21c;
                if (((*(int *)(DAT_007cbefc + local_34 + 0xc) != 0) &&
                    (*(int *)(DAT_007cbefc + local_34 + 299) != 0)) || (local_2c != 0)) {
                  iVar5 = wserv_calloc(1,0x21c);
                  if (iVar5 != 0) {
                    memcpy((void *)(iVar5 + 0xc),(void *)(DAT_007cbefc + local_34 + 0x10),0x205);
                    uVar1 = *(undefined2 *)(*(int *)(DAT_007cbf04 + iVar10 + 8) + local_30 + 4);
                    *(uint *)(iVar5 + 0x214) = local_3c;
                    *(char *)(iVar5 + 0x218) = cVar12;
                    *(undefined2 *)(iVar5 + 0x204) = uVar1;
                    FUN_004086b0(&local_50,iVar5);
                    goto LAB_005f38c8;
                  }
                  uVar11 = 0xffffffff;
                  if ((g_wserv_warning != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
                    printf("<wserv>[warning]%s(): %d  -> no memory!!\r\n",
                           "wserv_db_for_each_entry_bind_ap",0x1512);
                  }
                  goto LAB_005f38e8;
                }
                uVar2 = uVar2 + 1;
                cVar12 = cVar12 + '\x01';
              }
            }
          }
LAB_005f3744:
          local_38 = local_38 + 1;
        }
LAB_005f38e8:
        FUN_00407f30(DAT_007cbef0);
        iVar3 = FUN_004081b0(&local_50);
        while (iVar3 != 0) {
          iVar10 = FUN_00408680(iVar3);
          (*param_3)(iVar3 + 0xc,param_4,iVar3 + 0x214);
          FUN_00407df0(iVar3);
          iVar3 = iVar10;
        }
        FUN_00407df0(puVar4);
      }
    }
  }
  return uVar11;
}

