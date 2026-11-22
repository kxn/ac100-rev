// func _apdb_add_ap_to_item_list_force @ 00606180 size=1308

int _apdb_add_ap_to_item_list_force(undefined4 param_1,int param_2,int param_3)

{
  int iVar1;
  void *__s;
  int iVar2;
  void *pvVar3;
  char *pcVar4;
  undefined4 uVar5;
  size_t sVar6;
  int iVar7;
  void *pvVar8;
  int iVar9;
  int unaff_s5;
  code *pcVar10;
  undefined1 auStack_58 [32];
  int local_38;
  int local_34;
  int local_30;
  
  memset(auStack_58,0,0x20);
  iVar1 = l_apdb_ap_item_cnt_cur;
  if ((param_2 == 0) || (param_3 == 0)) {
    if (apdb_err_switch == 0) {
      return -1;
    }
    pcVar4 = "[APDB_ERROR]%s()/line %d : input para is null.\n";
    uVar5 = 0x1fa6;
LAB_00606444:
    printf(pcVar4,"_apdb_add_ap_to_item_list_force",uVar5);
    return -1;
  }
  if (l_apdb_ap_item_cnt_cur < 1) {
    __s = (void *)0x0;
  }
  else {
    sVar6 = l_apdb_ap_item_cnt_cur * 0x58;
    __s = (void *)FUN_00408450(sVar6,0x1fae);
    if (__s == (void *)0x0) {
      if (apdb_err_switch == 0) {
        return -1;
      }
      printf("[APDB_ERROR]%s()/line %d : malloc error.\n","_apdb_add_ap_to_item_list_force",0x1fb1);
      return -1;
    }
    memset(__s,0,sVar6);
    _apdb_ap_item_copy(__s,l_apdb_ap_item_cur,iVar1);
  }
  FUN_004082d0(l_apdb_mutex,0xffffffff);
  iVar2 = _apdb_ap_item_get_index_by_id(param_1);
  if (iVar2 == -1) {
    if (apdb_warning_switch != 0) {
      pcVar4 = "[APDB_WARNING]%s()/line %d : get ap index failed.\n";
      uVar5 = 0x1fc0;
LAB_0060647c:
      printf(pcVar4,"_apdb_add_ap_to_item_list_force",uVar5);
    }
  }
  else {
    iVar2 = l_apdb_ap_item_cur + iVar2 * 0x58;
    if (*(int *)(iVar2 + 0x50) == 0) {
      if (apdb_debug_switch != 0) {
        pcVar4 = "[APDB_DEBUG]%s()/line %d : the hash is NULL\n";
        uVar5 = 0x1fc8;
        goto LAB_0060647c;
      }
    }
    else {
      iVar9 = FUN_00407fa0(*(int *)(iVar2 + 0x50),param_2);
      if (iVar9 != 0) {
        _apdb_md5_calc(auStack_58,param_3);
        for (local_34 = 0; local_34 < *(int *)(iVar2 + 0x4c); local_34 = local_34 + 1) {
          pvVar3 = (void *)(*(int *)(iVar2 + 0x54) + local_34 * 0x168);
          if ((pvVar3 != (void *)0x0) && (iVar7 = memcmp(pvVar3,auStack_58,0x10), iVar7 == 0)) {
            local_38 = 1;
            goto LAB_0060632c;
          }
        }
        local_34 = 0;
        local_38 = 0;
LAB_0060632c:
        local_30 = *(int *)(iVar2 + 0x54);
        iVar7 = *(int *)(iVar9 + 0x10);
        pvVar3 = (void *)FUN_00408450(0x168,0x1fe2);
        if (pvVar3 == (void *)0x0) {
          FUN_00407f30(l_apdb_mutex);
          if (apdb_err_switch == 0) {
            return -1;
          }
          pcVar4 = "[APDB_ERROR]%s()/line %d : Failed to malloc memory for apdb_ap.\n";
          uVar5 = 0x1fe6;
          goto LAB_00606444;
        }
        pvVar8 = (void *)(local_30 + iVar7 * 0x168);
        memset(pvVar3,0,0x168);
        _apdb_ap_copy(pvVar3,pvVar8,1);
        if (local_38 == 0) {
          _apdb_ap_copy(pvVar8,param_3,1);
          memcpy(pvVar8,auStack_58,0x10);
        }
        else {
          if (apdb_debug_switch != 0) {
            printf("[APDB_DEBUG]%s()/line %d : apdb md5 existed.\n",
                   "_apdb_add_ap_to_item_list_force",0x1ff1);
          }
          *(int *)(iVar9 + 0x10) = local_34;
        }
        FUN_00407f30(l_apdb_mutex);
        iVar9 = _ap_item_add_to_config(iVar2,0);
        iVar2 = l_apdb_ap_item_cnt_cur;
        if (iVar9 == 0) {
          if (l_apdb_ap_item_cnt_cur < 1) {
            pvVar8 = (void *)0x0;
          }
          else {
            sVar6 = l_apdb_ap_item_cnt_cur * 0x58;
            pvVar8 = (void *)FUN_00408450(sVar6,0x200b);
            if (pvVar8 == (void *)0x0) {
              iVar9 = -1;
              if (apdb_err_switch == 0) goto LAB_006063d0;
              printf("[APDB_ERROR]%s()/line %d : malloc error.\n","_apdb_add_ap_to_item_list_force",
                     0x200e);
              goto LAB_006063d4;
            }
            memset(pvVar8,0,sVar6);
            _apdb_ap_item_copy(pvVar8,l_apdb_ap_item_cur,iVar2);
          }
          for (iVar9 = FUN_004081b0(&l_apdb_callback_list); iVar9 != 0; iVar9 = FUN_00408680(iVar9))
          {
            if ((*(code **)(iVar9 + 0x10) == (code *)0x0) ||
               (iVar7 = (**(code **)(iVar9 + 0x10))(pvVar8,iVar2,__s,iVar1), iVar7 != -1)) {
              pcVar10 = *(code **)(iVar9 + 0x14);
            }
            else if (apdb_debug_switch == 0) {
              pcVar10 = *(code **)(iVar9 + 0x14);
            }
            else {
              printf("[APDB_DEBUG]%s()/line %d : process callback update_all for module[%s] failed.\n"
                     ,"_apdb_add_ap_to_item_list_force",0x2022,*(undefined4 *)(iVar9 + 0xc));
              pcVar10 = *(code **)(iVar9 + 0x14);
            }
            if (pcVar10 != (code *)0x0) {
              (*pcVar10)(param_3,pvVar3,2);
            }
          }
        }
        else {
          if (apdb_err_switch != 0) {
            printf("[APDB_ERROR]%s()/line %d : add item to config failed !\n",
                   "_apdb_add_ap_to_item_list_force",0x2002);
          }
          pvVar8 = (void *)0x0;
          iVar2 = unaff_s5;
LAB_006063d0:
          iVar9 = -1;
        }
LAB_006063d4:
        _apdb_ap_free(pvVar3,1);
        if (pvVar8 != (void *)0x0) {
          _apdb_ap_item_free(pvVar8,iVar2);
        }
        goto LAB_006063f0;
      }
      if (apdb_warning_switch != 0) {
        pcVar4 = "[APDB_WARNING]%s()/line %d : get  fwid  ap failed.\n";
        uVar5 = 0x1fcf;
        goto LAB_0060647c;
      }
    }
  }
  iVar9 = -1;
  FUN_00407f30(l_apdb_mutex);
LAB_006063f0:
  if (__s != (void *)0x0) {
    _apdb_ap_item_free(__s,iVar1);
  }
  return iVar9;
}

