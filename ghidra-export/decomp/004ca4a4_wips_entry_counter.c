// func wips_entry_counter @ 004ca4a4 size=1472

undefined4 wips_entry_counter(int param_1,int param_2,int param_3)

{
  void *pvVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  char *pcVar6;
  undefined4 uVar7;
  undefined1 *puVar8;
  int iVar9;
  undefined4 uVar10;
  int iVar11;
  void *pvVar12;
  void *pvVar13;
  undefined4 local_78;
  undefined4 local_74;
  undefined4 local_70;
  undefined4 local_6c;
  undefined2 local_68;
  undefined1 auStack_64 [44];
  undefined4 local_38;
  int local_30;
  
  uVar10 = 0;
  local_78 = 0;
  local_74 = 0;
  local_70 = 0;
  local_6c = 0;
  local_68 = 0;
  memset(auStack_64,0,0x30);
  if ((param_2 != 0) && (param_1 != 0)) {
    pvVar1 = (void *)FUN_00408450(param_2 * 6,0x39b);
    if (pvVar1 == (void *)0x0) {
      uVar10 = 0xffffffff;
      if (sensor_err_switch != '\0') {
        printf("[SENSOR_ERROR]%s()/%d out of memory\n","wips_entry_counter",0x39e);
      }
    }
    else {
      iVar11 = 0;
      for (local_30 = 0; local_30 < param_2; local_30 = local_30 + 1) {
        pvVar13 = (void *)(param_1 + 0x48);
        wips_mac2str(pvVar13,&local_78);
        if (sensor_debug_switch == '\0') {
          iVar2 = *(int *)(param_1 + 0xac);
        }
        else {
          puVar8 = &DAT_006a733c;
          if (param_3 != 0) {
            puVar8 = &DAT_00688af8;
          }
          printf("[SENSOR_DEBUG]%s()/%d %scounter dev %s\n","wips_entry_counter",0x3a8,puVar8,
                 &local_78);
          iVar2 = *(int *)(param_1 + 0xac);
        }
        if (iVar2 == 0) {
          if (sensor_warning_switch == '\0') goto LAB_004ca54c;
          uVar7 = 0x3ad;
          pcVar6 = "[SENSOR_WARNING]%s()/%d dev[mac=%s] could not counter/discounter\n";
LAB_004ca758:
          uVar10 = 0xffffffff;
          printf(pcVar6,"wips_entry_counter",uVar7,&local_78);
          goto LAB_004ca550;
        }
        pvVar12 = pvVar1;
        if (param_3 == 0) {
          if (iVar2 != 2) {
LAB_004ca5e4:
            iVar9 = 0;
            goto LAB_004ca604;
          }
LAB_004ca714:
          if (sensor_warning_switch != '\0') {
            pcVar6 = "[SENSOR_WARNING]%s()/%d dev[mac=%s] is already counter/discounter\n";
            uVar7 = 0x3c0;
            goto LAB_004ca758;
          }
LAB_004ca54c:
          uVar10 = 0xffffffff;
        }
        else {
          if (*(int *)(param_1 + 0xa8) == 2) {
            if (sensor_warning_switch != '\0') {
              pcVar6 = "[SENSOR_WARNING]%s()/%d dev[mac=%s] in whitelist\n";
              uVar7 = 0x3b5;
              goto LAB_004ca758;
            }
            goto LAB_004ca54c;
          }
          if (param_3 != 1) goto LAB_004ca5e4;
          iVar9 = 0;
          if (iVar2 == 1) goto LAB_004ca714;
LAB_004ca604:
          for (; iVar9 < iVar11; iVar9 = iVar9 + 1) {
            iVar2 = memcmp(pvVar12,pvVar13,6);
            if (iVar2 == 0) {
              if (iVar9 != -1) goto LAB_004ca550;
              break;
            }
            pvVar12 = (void *)((int)pvVar12 + 6);
          }
          iVar2 = iVar11 * 6;
          iVar11 = iVar11 + 1;
          memcpy((void *)((int)pvVar1 + iVar2),(void *)(param_1 + 0x48),6);
          if (param_3 != 0) {
            memcpy(auStack_64,(void *)(param_1 + 0x48),6);
            local_38 = wips_local_time_get();
            iVar2 = FUN_00407fa0(g_counter_info_hash,pvVar13);
            if (iVar2 == 0) {
              pvVar13 = (void *)FUN_00408450(0x30,0x3d3);
              if (pvVar13 == (void *)0x0) {
                uVar10 = 0xffffffff;
                if (sensor_err_switch != '\0') {
                  pcVar6 = "[SENSOR_ERROR]%s()/%d malloc counter_info hash node fail\n";
                  uVar7 = 0x3d6;
                  goto LAB_004ca68c;
                }
              }
              else {
                memcpy(pvVar13,auStack_64,0x30);
                FUN_0051ad88((int)pvVar13 + 8);
                iVar2 = FUN_00408380(g_counter_info_hash,pvVar13);
                if (iVar2 == 0) goto LAB_004ca550;
                if (sensor_err_switch != '\0') {
                  printf("[SENSOR_ERROR]%s()/%d add counter info into g_counter_info_hash failed.\n"
                         ,"wips_entry_counter",0x3de);
                }
                FUN_00407df0(pvVar13);
              }
              goto LAB_004ca54c;
            }
            if (sensor_err_switch != '\0') {
              uVar7 = 1000;
              pcVar6 = "[SENSOR_ERROR]%s()/%d counter info not clear before\n";
LAB_004ca68c:
              printf(pcVar6,"wips_entry_counter",uVar7);
            }
          }
        }
LAB_004ca550:
        param_1 = param_1 + 0xb0;
      }
      FUN_004082d0(wips_global_mutex,0xffffffff);
      for (iVar2 = FUN_004081b0(&g_wips_list); iVar2 != 0; iVar2 = FUN_00408680(iVar2)) {
        pvVar13 = pvVar1;
        for (iVar9 = 0; iVar9 < iVar11; iVar9 = iVar9 + 1) {
          iVar3 = memcmp(pvVar13,(void *)(iVar2 + 0x48),6);
          pvVar13 = (void *)((int)pvVar13 + 6);
          if (iVar3 == 0) {
            if ((iVar9 != -1) &&
               (iVar9 = FUN_00407fa0(g_counter_info_hash,(void *)(iVar2 + 0x48)), iVar9 != 0)) {
              if (param_3 == 0) {
                iVar3 = FUN_004081b0(iVar9 + 8);
                if (iVar3 != 0) {
                  iVar4 = *(int *)(iVar3 + 0xc);
                  while( true ) {
                    *(undefined4 *)(*(int *)(g_wips_id2entry + iVar4 * 4) + 0xac) = 2;
                    iVar5 = FUN_00408680(iVar3);
                    FUN_00407df0(iVar3);
                    if (iVar5 == 0) break;
                    iVar4 = *(int *)(iVar5 + 0xc);
                    iVar3 = iVar5;
                  }
                }
                iVar3 = FUN_00407f40(g_counter_info_hash,iVar9);
                if ((iVar3 != 0) && (sensor_err_switch != '\0')) {
                  printf("[SENSOR_ERROR]%s()/%d remove item from hash failed.\n",
                         "wips_entry_counter",0x428);
                }
                FUN_00407df0(iVar9);
              }
              else if (*(int *)(iVar2 + 0xac) == 1) {
                if (sensor_err_switch != '\0') {
                  printf("[SENSOR_ERROR]%s()/%d wips[id=%d] already in counter status\n",
                         "wips_entry_counter",0x404,*(undefined4 *)(iVar2 + 0xc));
                }
              }
              else {
                iVar3 = FUN_00408450(0x10,0x409);
                if (iVar3 == 0) {
                  uVar10 = 0xffffffff;
                  if (sensor_err_switch != '\0') {
                    printf("[SENSOR_ERROR]%s()/%d out of memory\n","wips_entry_counter",0x40c);
                  }
                }
                else {
                  *(undefined4 *)(iVar3 + 0xc) = *(undefined4 *)(iVar2 + 0xc);
                  FUN_004086b0(iVar9 + 8,iVar3);
                  iVar3 = FUN_004081b0(iVar2 + 0x9c);
                  if (iVar3 == 0) {
                    iVar9 = *(int *)(iVar2 + 0xc);
                  }
                  else {
                    uVar7 = *(undefined4 *)(iVar3 + 0x34);
                    while( true ) {
                      wips_channel_set(iVar9 + 0x14,uVar7);
                      iVar3 = FUN_00408680(iVar3);
                      if (iVar3 == 0) break;
                      uVar7 = *(undefined4 *)(iVar3 + 0x34);
                    }
                    iVar9 = *(int *)(iVar2 + 0xc);
                  }
                  *(undefined4 *)(*(int *)(g_wips_id2entry + iVar9 * 4) + 0xac) = 1;
                }
              }
            }
            break;
          }
        }
      }
      FUN_00407f30(wips_global_mutex);
      wips_counter_send(pvVar1,iVar11,param_3);
      FUN_00407df0(pvVar1);
    }
  }
  return uVar10;
}

