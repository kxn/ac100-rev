// func apupd_model_from_struct_to_json @ 006428a8 size=2044

/* WARNING: Removing unreachable block (ram,0x006429a0) */

undefined4 apupd_model_from_struct_to_json(int param_1,int param_2)

{
  ushort uVar1;
  ushort uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  size_t sVar7;
  int iVar8;
  char *pcVar9;
  int iVar10;
  uint uVar11;
  undefined4 local_488;
  undefined4 local_484;
  undefined4 local_480;
  undefined4 local_47c;
  undefined4 local_478;
  undefined1 auStack_474 [44];
  char acStack_448 [68];
  char acStack_404 [260];
  undefined1 auStack_300 [18];
  ushort local_2ee;
  
  memset(acStack_448,0,0x41);
  memset(auStack_300,0,0x2d8);
  local_484 = 0;
  local_480 = 0;
  local_47c = 0;
  local_478 = 0;
  memset(auStack_474,0,0x2c);
  local_488 = 0;
  if ((param_1 == 0) || (param_2 == 0)) {
    if (g_apupd_error == 0) {
      return 0xffffffff;
    }
    iVar3 = is_target_debug_ap();
    if (iVar3 == 0) {
      return 0xffffffff;
    }
    pcVar9 = "[APUPD_ERROR]%32s() %05d: inputs error.\r\n";
    uVar6 = 0x166;
  }
  else {
    iVar3 = apupd_db_config_get_without_lock(&local_488);
    if (iVar3 == -1) {
      if (g_apupd_error == 0) {
        return 0xffffffff;
      }
      iVar3 = is_target_debug_ap();
      if (iVar3 == 0) {
        return 0xffffffff;
      }
      pcVar9 = "[APUPD_ERROR]%32s() %05d: get config failed.\r\n";
      uVar6 = 0x16c;
    }
    else {
      iVar3 = json_object_new_array();
      if (iVar3 == 0) {
        if (g_apupd_error == 0) {
          return 0xffffffff;
        }
        iVar3 = is_target_debug_ap();
        if (iVar3 == 0) {
          return 0xffffffff;
        }
        pcVar9 = "[APUPD_ERROR]%32s() %05d: malloc json obj failed.\r\n";
        uVar6 = 0x172;
      }
      else {
        iVar10 = 0;
        if ((*(uint *)(param_1 + 0x18) & 1) == 0) {
          while (iVar4 = apmngr_db_get_group_max(), iVar10 < iVar4) {
            if ((*(uint *)(param_1 + 0x18) & 1) == 0) {
              if (iVar10 < 0x200) {
                iVar5 = iVar10 + 1;
                iVar4 = iVar10 + 0x20;
                if (-1 < iVar5) {
                  iVar4 = iVar5;
                }
                if ((*(uint *)(param_1 + ((iVar4 >> 5) + 6) * 4) >> (iVar5 % 0x20 & 0x1fU) & 1) != 0
                   ) goto LAB_006429d8;
                iVar10 = iVar10 + 1;
              }
              else {
                iVar10 = iVar10 + 1;
              }
            }
            else {
LAB_006429d8:
              memset(acStack_404,0,0x100);
              snprintf(acStack_404,0x100,"%d",iVar10);
              uVar6 = json_object_new_string(acStack_404);
              json_object_array_add(iVar3,uVar6);
              iVar10 = iVar10 + 1;
            }
          }
        }
        else {
          uVar6 = json_object_new_string(&DAT_00677878);
          json_object_array_add(iVar3,uVar6);
        }
        json_object_object_add(param_2,"group_id",iVar3);
        memset(acStack_404,0,0x100);
        snprintf(acStack_404,0x100,"%d",*(undefined4 *)(param_1 + 0x58));
        uVar6 = json_object_new_string(acStack_404);
        json_object_object_add(param_2,"model_id",uVar6);
        uVar6 = json_object_new_string(param_1 + 0x5c);
        json_object_object_add(param_2,"model",uVar6);
        memset(acStack_448,0,0x41);
        iVar3 = param_1;
        for (uVar11 = 0; uVar11 < *(uint *)(param_1 + 0xa0); uVar11 = uVar11 + 1) {
          if (uVar11 == 0) {
            sVar7 = strlen(acStack_448);
            pcVar9 = "%d.%d";
            uVar1 = *(ushort *)(param_1 + 0xa4);
            uVar2 = *(ushort *)(param_1 + 0xa6);
          }
          else {
            sVar7 = strlen(acStack_448);
            uVar1 = *(ushort *)(iVar3 + 0xa4);
            uVar2 = *(ushort *)(iVar3 + 0xa6);
            pcVar9 = "/%d.%d";
          }
          sprintf(acStack_448 + sVar7,pcVar9,(uint)uVar1,(uint)uVar2);
          iVar3 = iVar3 + 4;
        }
        uVar6 = json_object_new_string();
        json_object_object_add(param_2,"hw_version",uVar6);
        memset(acStack_448,0,0x41);
        iVar3 = memcmp(&local_484,(void *)(param_1 + 0x1c4),0x10);
        if (iVar3 != 0) {
          uVar11 = *(uint *)(param_1 + 0x1cc);
          sprintf(acStack_448,"%d.%d.%d Build %02d%02d%02d Rel.%05d",
                  (uint)*(ushort *)(param_1 + 0x1c4),(uint)*(ushort *)(param_1 + 0x1c6),
                  (uint)*(ushort *)(param_1 + 0x1c8),uVar11 >> 0x10,(uVar11 << 0x10) >> 0x18,
                  uVar11 & 0xff,*(undefined4 *)(param_1 + 0x1d0));
        }
        uVar6 = json_object_new_string(acStack_448);
        json_object_object_add(param_2,"sw_version",uVar6);
        iVar3 = memcmp((void *)(param_1 + 0x150),auStack_474,0x2c);
        if (iVar3 == 0) {
          uVar6 = json_object_new_string(&DAT_00688af8);
          json_object_object_add(param_2,"upgrade_date",uVar6);
          pcVar9 = "";
        }
        else {
          memset(acStack_448,0,0x41);
          iVar3 = *(int *)(param_1 + 0x15c);
          if (iVar3 == 0) {
            iVar3 = 1;
          }
          sprintf(acStack_448,"%04d/%02d/%02d",*(int *)(param_1 + 0x164) + 0x76c,
                  *(int *)(param_1 + 0x160) + 1,iVar3);
          uVar6 = json_object_new_string(acStack_448);
          json_object_object_add(param_2,"upgrade_date",uVar6);
          memset(acStack_448,0,0x41);
          sprintf(acStack_448,"%02d:%02d:%02d",*(undefined4 *)(param_1 + 0x158),
                  *(undefined4 *)(param_1 + 0x154),*(undefined4 *)(param_1 + 0x150));
          pcVar9 = acStack_448;
        }
        uVar6 = json_object_new_string(pcVar9);
        json_object_object_add(param_2,"upgrade_start_time",uVar6);
        memset(acStack_404,0,0x100);
        snprintf(acStack_404,0x100,"%d",*(undefined4 *)(param_1 + 0x7ec));
        uVar6 = json_object_new_string(acStack_404);
        json_object_object_add(param_2,"upgrade_type",uVar6);
        if (*(int *)(param_1 + 0x7f0) == 1) {
          pcVar9 = "immediately";
        }
        else {
          pcVar9 = "timing";
        }
        uVar6 = json_object_new_string(pcVar9);
        json_object_object_add(param_2,"upgrade_datetime_type",uVar6);
        iVar5 = FUN_004081b0(param_1 + 0x7f4);
        iVar3 = 0;
        iVar10 = 0;
        iVar4 = 0;
        for (; iVar5 != 0; iVar5 = FUN_00408680(iVar5)) {
          iVar8 = apmngr_db_entry_get_by_mac(iVar5 + 0x2e,auStack_300);
          if (iVar8 == -1) {
            if ((g_apupd_error != 0) && (iVar8 = is_target_debug_ap(), iVar8 != 0)) {
              printf("[APUPD_ERROR]%32s() %05d: get ap entry by mac failed.\r\n",
                     "apupd_model_from_struct_to_json",0x1cb);
            }
          }
          else {
            if ((*(uint *)(param_1 + 0x18) & 1) == 0) {
              uVar11 = local_2ee + 1;
              if ((0x1ff < local_2ee) ||
                 ((*(uint *)(param_1 + (((int)uVar11 >> 5) + 6) * 4) >> (uVar11 & 0x1f) & 1) == 0))
              goto LAB_00642e04;
              iVar8 = *(int *)(iVar5 + 0x48);
            }
            else {
              iVar8 = *(int *)(iVar5 + 0x48);
            }
            iVar4 = iVar4 + 1;
            if (iVar8 == 8) {
              iVar10 = iVar10 + 1;
            }
            else {
              iVar3 = iVar3 + (uint)(iVar8 - 1U < 7);
            }
          }
LAB_00642e04:
        }
        memset(acStack_404,0,0x100);
        snprintf(acStack_404,0x100,"%d",iVar10);
        uVar6 = json_object_new_string(acStack_404);
        json_object_object_add(param_2,"finish_upgrade",uVar6);
        memset(acStack_404,0,0x100);
        snprintf(acStack_404,0x100,"%d",iVar3);
        uVar6 = json_object_new_string(acStack_404);
        json_object_object_add(param_2,"need_upgrade",uVar6);
        memset(acStack_404,0,0x100);
        snprintf(acStack_404,0x100,"%d",iVar4);
        uVar6 = json_object_new_string(acStack_404);
        json_object_object_add(param_2,"total_upgrade",uVar6);
        uVar6 = FUN_00407fe0(param_1 + 0x17c);
        memset(acStack_404,0,0x100);
        snprintf(acStack_404,0x100,"%d",uVar6);
        uVar6 = json_object_new_string(acStack_404);
        json_object_object_add(param_2,"fail_upgrade",uVar6);
        iVar3 = apupd_db_model_real_state_get(param_1,&local_488);
        if (iVar3 != -1) {
          memset(acStack_404,0,0x100);
          snprintf(acStack_404,0x100,"%d",iVar3);
          uVar6 = json_object_new_string(acStack_404);
          json_object_object_add(param_2,"status",uVar6);
          return 0;
        }
        if (g_apupd_error == 0) {
          return 0xffffffff;
        }
        iVar3 = is_target_debug_ap();
        if (iVar3 == 0) {
          return 0xffffffff;
        }
        pcVar9 = "[APUPD_ERROR]%32s() %05d: get state failed.\r\n";
        uVar6 = 0x1e9;
      }
    }
  }
  printf(pcVar9,"apupd_model_from_struct_to_json",uVar6);
  return 0xffffffff;
}

