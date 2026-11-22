// func wserv_db_for_each_vlan_bind_ap @ 005f3120 size=1100

undefined4
wserv_db_for_each_vlan_bind_ap(uint param_1,uint param_2,code *param_3,undefined4 param_4)

{
  bool bVar1;
  int iVar2;
  uint uVar3;
  uint *puVar4;
  int iVar5;
  undefined4 *puVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  uint uVar12;
  uint uVar13;
  char *pcVar14;
  undefined4 uVar15;
  int iVar16;
  undefined4 *puVar17;
  int iVar18;
  uint *puVar19;
  int local_38;
  
  uVar15 = 0;
  iVar2 = apmngr_db_capacity_support(param_1 & 0xffff,1,0x3f);
  if (param_3 != (code *)0x0) {
    uVar3 = rdmngr_profile_get_max_rd_per_ap();
    if (uVar3 < param_2) {
      uVar15 = 0xffffffff;
      if ((g_wserv_error != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
        printf("<wserv>[warning]%s(): %d  -> invalid rd_cnt[%d]!\r\n",
               "wserv_db_for_each_vlan_bind_ap",0x1463,param_2);
      }
    }
    else {
      uVar15 = rdmngr_profile_get_max_rd_per_ap();
      puVar4 = (uint *)wserv_calloc(uVar15,4);
      if (puVar4 == (uint *)0x0) {
        uVar15 = 0xffffffff;
        if ((g_wserv_error != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
          printf("<wserv>[warning]%s(): %d  -> no memory!\r\n","wserv_db_for_each_vlan_bind_ap",
                 0x146a);
        }
      }
      else {
        iVar16 = 1;
        iVar18 = 0;
        while (iVar16 <= (int)param_2) {
          uVar3 = rdmngr_db_generate_rd_id(param_1,iVar16);
          iVar5 = _wserv_is_rd_enable(uVar3);
          iVar16 = iVar16 + 1;
          if (iVar5 != 0) {
            puVar4[iVar18] = uVar3;
            iVar18 = iVar18 + 1;
          }
        }
        iVar16 = rdmngr_profile_get_max_rd_per_ap();
        iVar5 = rdmngr_profile_get_max_wlan_per_rd();
        puVar6 = (undefined4 *)wserv_calloc(iVar5 * iVar16,4);
        if (puVar6 == (undefined4 *)0x0) {
          if ((g_wserv_error != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
            printf("<wserv>[warning]%s(): %d  -> no memory!\r\n","wserv_db_for_each_vlan_bind_ap",
                   0x147b);
          }
          FUN_00407df0(puVar4);
          uVar15 = 0xffffffff;
        }
        else {
          iVar5 = rdmngr_profile_get_max_rd_per_ap();
          iVar7 = rdmngr_profile_get_max_wlan_per_rd();
          iVar16 = 0;
          FUN_004082d0(DAT_007cbef0,0xffffffff);
          puVar19 = puVar4;
          for (local_38 = 0; local_38 < iVar18; local_38 = local_38 + 1) {
            uVar13 = *puVar19;
            uVar3 = rdmngr_db_generate_rd_idx_by_rd_id();
            if ((int)uVar3 < 0) {
LAB_005f335c:
              if ((g_wserv_warning != 0) && (iVar11 = is_target_debug_ap(), iVar11 != 0)) {
                pcVar14 = "<wserv>[warning]%s(): %d  -> rd_id[%d] is invalid!\r\n";
                uVar15 = 0x148b;
                uVar3 = uVar13;
LAB_005f338c:
                printf(pcVar14,"wserv_db_for_each_vlan_bind_ap",uVar15,uVar3);
              }
            }
            else {
              iVar11 = apmngr_db_get_ap_max();
              iVar8 = apmngr_db_get_template_max();
              iVar9 = apmngr_db_get_sensor_max();
              iVar10 = rdmngr_profile_get_max_rd_per_ap();
              if ((uint)((iVar11 + iVar8 + iVar9) * iVar10) <= uVar3) goto LAB_005f335c;
              uVar13 = 0;
              if (*(char *)(DAT_007cbf04 + uVar3 * 0xc) != '\0') {
LAB_005f33a0:
                do {
                  uVar12 = rdmngr_profile_get_max_wlan_per_rd();
                  if (uVar12 <= uVar13) goto LAB_005f3328;
                  pcVar14 = (char *)(*(int *)(DAT_007cbf04 + uVar3 * 0xc + 8) + uVar13 * 6);
                  if (*pcVar14 == '\0') {
                    uVar13 = uVar13 + 1;
                    goto LAB_005f33a0;
                  }
                  uVar12 = (uint)*(short *)(pcVar14 + 2);
                  iVar11 = iVar16;
                  if (-1 < (int)uVar12) {
                    if (l_wserv_profile <= uVar12) {
                      uVar13 = uVar13 + 1;
                      goto LAB_005f33a0;
                    }
                    iVar11 = DAT_007cbefc + uVar12 * 0x21c;
                    if (((*(int *)(iVar11 + 0xc) == 0) || (*(int *)(iVar11 + 299) == 0)) &&
                       (iVar2 == 0)) {
                      uVar13 = uVar13 + 1;
                      goto LAB_005f33a0;
                    }
                    if (iVar7 * iVar5 <= iVar16) {
                      uVar13 = uVar13 + 1;
                      goto LAB_005f33a0;
                    }
                    iVar11 = iVar16 + 1;
                    puVar6[iVar16] = (int)*(short *)(pcVar14 + 4);
                  }
                  uVar13 = uVar13 + 1;
                  iVar16 = iVar11;
                } while( true );
              }
              if ((g_wserv_warning != 0) && (iVar11 = is_target_debug_ap(), iVar11 != 0)) {
                pcVar14 = "<wserv>[warning]%s(): %d  -> idx[%d] is not used!\r\n";
                uVar15 = 0x1491;
                goto LAB_005f338c;
              }
            }
LAB_005f3328:
            puVar19 = puVar19 + 1;
          }
          iVar2 = 0;
          FUN_00407f30(DAT_007cbef0);
          bVar1 = 0 < iVar16;
          puVar17 = puVar6;
          while (bVar1) {
            uVar15 = *puVar17;
            iVar2 = iVar2 + 1;
            puVar17 = puVar17 + 1;
            (*param_3)(uVar15,param_4);
            bVar1 = iVar2 < iVar16;
          }
          FUN_00407df0(puVar6);
          uVar15 = 0;
          FUN_00407df0(puVar4);
        }
      }
    }
  }
  return uVar15;
}

