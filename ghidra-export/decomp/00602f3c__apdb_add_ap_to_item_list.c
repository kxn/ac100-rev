// func _apdb_add_ap_to_item_list @ 00602f3c size=2468

int _apdb_add_ap_to_item_list(undefined4 param_1,void *param_2,void *param_3,int param_4)

{
  int iVar1;
  void *__s;
  int iVar2;
  void *__s_00;
  void *pvVar3;
  void *__s_01;
  char *pcVar4;
  undefined4 uVar5;
  size_t sVar6;
  undefined4 *puVar7;
  int iVar8;
  int unaff_s6;
  undefined4 local_60;
  undefined1 auStack_5c [36];
  void *local_38;
  void *local_34;
  int local_30;
  
  memset(auStack_5c,0,0x20);
  local_60 = 0;
  if ((param_2 == (void *)0x0) || (param_3 == (void *)0x0)) {
    if (apdb_err_switch == 0) {
      return -1;
    }
    printf("[APDB_ERROR]%s()/line %d : input para is null.\n","_apdb_add_ap_to_item_list",0x1e7e);
    return -1;
  }
  local_30 = l_apdb_ap_item_cnt_cur;
  if ((param_4 == 0) && (0 < l_apdb_ap_item_cnt_cur)) {
    sVar6 = l_apdb_ap_item_cnt_cur * 0x58;
    __s = (void *)FUN_00408450(sVar6,0x1e86);
    if (__s != (void *)0x0) {
      memset(__s,0,sVar6);
      _apdb_ap_item_copy(__s,l_apdb_ap_item_cur,local_30);
      goto LAB_00602ffc;
    }
    __s_00 = (void *)0x0;
    if (apdb_err_switch != 0) {
      printf("[APDB_ERROR]%s()/line %d : malloc error.\n","_apdb_add_ap_to_item_list",0x1e89);
      __s_00 = (void *)0x0;
    }
LAB_00603170:
    iVar2 = 0;
    iVar8 = -1;
    pvVar3 = (void *)0x0;
    goto LAB_006030a4;
  }
  __s = (void *)0x0;
LAB_00602ffc:
  iVar2 = _apdb_ap_item_get_index_by_id(param_1);
  if (iVar2 == -1) {
    if (apdb_debug_switch != 0) {
      printf("[APDB_DEBUG]%s()/line %d : the id not existed\n","_apdb_add_ap_to_item_list",0x1f04);
    }
    unaff_s6 = l_apdb_ap_item_cnt_cur + 1;
    if (unaff_s6 < 1) {
      __s_00 = (void *)0x0;
    }
    else {
      __s_00 = (void *)FUN_00408450(unaff_s6 * 0x58,0x1f0a);
      if (__s_00 == (void *)0x0) {
        if (apdb_err_switch != 0) {
          pcVar4 = "[APDB_ERROR]%s()/line %d : mallcl error.\n";
          uVar5 = 0x1f0d;
          goto LAB_006032c0;
        }
        goto LAB_00603170;
      }
      memset(__s_00,0,unaff_s6 * 0x58);
      _apdb_ap_item_copy(__s_00,l_apdb_ap_item_cur,l_apdb_ap_item_cnt_cur);
    }
    if (apdb_debug_switch != 0) {
      printf("[APDB_DEBUG]%s()/line %d : copy success\n","_apdb_add_ap_to_item_list",0x1f16);
    }
    puVar7 = (undefined4 *)FUN_00408450(0x58,0x1f18);
    if (puVar7 == (undefined4 *)0x0) {
      if (apdb_err_switch != 0) {
        pcVar4 = "[APDB_ERROR]%s()/line %d : dst_item malloc failed\n";
        uVar5 = 0x1f1c;
        goto LAB_006032c0;
      }
      goto LAB_00603170;
    }
    *puVar7 = *(undefined4 *)((int)param_3 + 0x10);
    puVar7[1] = *(undefined4 *)((int)param_3 + 0x18);
    puVar7[0x13] = 1;
    memcpy(puVar7 + 2,(void *)((int)param_3 + 0xda),0x41);
    _apdb_md5_calc(auStack_5c,param_3);
    memcpy(param_3,auStack_5c,0x10);
    iVar2 = _apdb_fwid_hash_init(puVar7 + 0x14);
    if (iVar2 == 0) {
      pvVar3 = (void *)FUN_00408450(0x14,0x1f34);
      if (pvVar3 == (void *)0x0) {
        if (apdb_err_switch != 0) {
          pcVar4 = "[APDB_ERROR]%s()/line %d : fwid_hash_node malloc failed\n";
          uVar5 = 0x1f38;
          goto LAB_00603408;
        }
        goto LAB_00603260;
      }
      memcpy(pvVar3,param_2,0x10);
      *(undefined4 *)((int)pvVar3 + 0x10) = 0;
      FUN_00408380(puVar7[0x14],pvVar3);
      pvVar3 = (void *)FUN_00408450(0x168,0x1f45);
      puVar7[0x15] = pvVar3;
      if (pvVar3 == (void *)0x0) {
        if (apdb_err_switch != 0) {
          pcVar4 = "[APDB_ERROR]%s()/line %d : apdb_list malloc failed\n";
          uVar5 = 0x1f49;
          goto LAB_00603408;
        }
        goto LAB_00603260;
      }
      memset(pvVar3,0,0x168);
      _apdb_ap_copy(puVar7[0x15],param_3,1);
      if ((param_4 == 0) && (iVar2 = _ap_item_add_to_config(puVar7,1), iVar2 != 0)) {
        if (apdb_err_switch != 0) {
          pcVar4 = "[APDB_ERROR]%s()/line %d : add item to config failed! \n";
          uVar5 = 0x1f57;
          goto LAB_00603408;
        }
        goto LAB_00603260;
      }
      iVar2 = 0;
      pvVar3 = (void *)0x0;
      _apdb_ap_item_copy((void *)((int)__s_00 + l_apdb_ap_item_cnt_cur * 0x58),puVar7,1);
      _apdb_sort_item_array_by_id(__s_00,unaff_s6);
      local_38 = (void *)0x0;
      if (param_4 == 0) goto LAB_006035f4;
LAB_00603504:
      iVar8 = 0;
LAB_00603508:
      if ((__s_00 == (void *)0x0) || (unaff_s6 < 1)) {
        if (apdb_err_switch != 0) {
          printf("[APDB_ERROR]%s()/line %d : you haven\'t loaded new ap item.\n",
                 "_apdb_ap_item_merge_finish",0x49c);
        }
      }
      else {
        if (l_apdb_ap_item_cur != (void *)0x0) {
          _apdb_ap_item_free(l_apdb_ap_item_cur,l_apdb_ap_item_cnt_cur);
          l_apdb_ap_item_cur = (void *)0x0;
        }
        l_apdb_ap_item_cnt_cur = unaff_s6;
        l_apdb_ap_item_cur = (void *)FUN_00408450(unaff_s6 * 0x58,0x4ad);
        iVar1 = l_apdb_ap_item_cnt_cur;
        local_34 = l_apdb_ap_item_cur;
        if (l_apdb_ap_item_cur == (void *)0x0) {
          if (apdb_err_switch == 0) {
            l_apdb_ap_item_cnt_cur = 0;
          }
          else {
            printf("[APDB_ERROR]%s()/line %d : malloc l_apdb_ap_item_cur failed.\n",
                   "_apdb_ap_item_merge_finish",0x4b0);
            l_apdb_ap_item_cnt_cur = 0;
          }
        }
        else {
          memset(l_apdb_ap_item_cur,0,l_apdb_ap_item_cnt_cur * 0x58);
          _apdb_ap_item_copy(local_34,__s_00,iVar1);
        }
      }
      if (apdb_debug_switch != 0) {
        pcVar4 = "[APDB_DEBUG]%s()/line %d : success add one item to list\n";
        uVar5 = 0x1f72;
LAB_00603640:
        printf(pcVar4,"_apdb_add_ap_to_item_list",uVar5);
      }
LAB_00603594:
      if (local_38 != (void *)0x0) goto LAB_006030a4;
    }
    else {
      if (apdb_err_switch != 0) {
        pcVar4 = "[APDB_ERROR]%s()/line %d : init hash failed!\n";
        uVar5 = 0x1f2f;
LAB_00603408:
        printf(pcVar4,"_apdb_add_ap_to_item_list",uVar5);
      }
LAB_00603260:
      iVar2 = 0;
      iVar8 = -1;
      pvVar3 = (void *)0x0;
    }
    _apdb_ap_item_free(puVar7,1);
  }
  else {
    if (apdb_debug_switch != 0) {
      printf("[APDB_DEBUG]%s()/line %d : the id existed\n","_apdb_add_ap_to_item_list",0x1e97);
    }
    unaff_s6 = l_apdb_ap_item_cnt_cur;
    if (0 < l_apdb_ap_item_cnt_cur) {
      sVar6 = l_apdb_ap_item_cnt_cur * 0x58;
      __s_00 = (void *)FUN_00408450(sVar6,0x1e9f);
      if (__s_00 != (void *)0x0) {
        memset(__s_00,0,sVar6);
        _apdb_ap_item_copy(__s_00,l_apdb_ap_item_cur,unaff_s6);
        goto LAB_0060306c;
      }
      if (apdb_err_switch == 0) goto LAB_00603170;
      pcVar4 = "[APDB_ERROR]%s()/line %d : mallcl error.\n";
      uVar5 = 0x1ea2;
LAB_006032c0:
      printf(pcVar4,"_apdb_add_ap_to_item_list",uVar5);
      goto LAB_00603170;
    }
    __s_00 = (void *)0x0;
LAB_0060306c:
    puVar7 = (undefined4 *)((int)__s_00 + iVar2 * 0x58);
    iVar2 = FUN_00407fa0(puVar7[0x14],param_2);
    if (iVar2 != 0) {
      if (apdb_debug_switch != 0) {
        printf("[APDB_DEBUG]%s()/line %d : the id and fwid already exist\n",
               "_apdb_add_ap_to_item_list",0x1efe);
      }
      iVar2 = 0;
      iVar8 = 0;
      pvVar3 = (void *)0x0;
      goto LAB_006030a4;
    }
    local_38 = (void *)FUN_00408450(0x14,0x1eaf);
    if (local_38 == (void *)0x0) {
      if (apdb_err_switch == 0) goto LAB_00603170;
      pcVar4 = "[APDB_ERROR]%s()/line %d : fwid_hash_node malloc failed\n";
      uVar5 = 0x1eb2;
      goto LAB_006032c0;
    }
    memcpy(local_38,param_2,0x10);
    _apdb_md5_calc(auStack_5c,param_3);
    for (iVar8 = 0; iVar8 < (int)puVar7[0x13]; iVar8 = iVar8 + 1) {
      pvVar3 = (void *)(puVar7[0x15] + iVar8 * 0x168);
      if ((pvVar3 != (void *)0x0) && (iVar2 = memcmp(pvVar3,auStack_5c,0x10), iVar2 == 0)) {
        if (apdb_debug_switch != 0) {
          printf("[APDB_DEBUG]%s()/line %d : md5 existed!\n","_apdb_add_ap_to_item_list",0x1ec9);
        }
        iVar2 = 0;
        *(int *)((int)local_38 + 0x10) = iVar8;
        pvVar3 = (void *)0x0;
        goto LAB_006034e4;
      }
    }
    memcpy(param_3,auStack_5c,0x10);
    *(undefined4 *)((int)local_38 + 0x10) = puVar7[0x13];
    iVar2 = puVar7[0x13] + 1;
    local_34 = (void *)(iVar2 * 0x168);
    pvVar3 = (void *)FUN_00408450(local_34,0x1ed6);
    if (pvVar3 == (void *)0x0) {
      iVar8 = -1;
      if (apdb_err_switch == 0) goto LAB_006030a4;
      pcVar4 = "[APDB_ERROR]%s()/line %d : apdb_ap_cur malloc failed\n";
      uVar5 = 0x1ed9;
    }
    else {
      memset(pvVar3,0,(size_t)local_34);
      _apdb_ap_copy(pvVar3,puVar7[0x15],puVar7[0x13]);
      _apdb_ap_copy((void *)((int)pvVar3 + puVar7[0x13] * 0x168),param_3,1);
      _apdb_ap_free(puVar7[0x15],puVar7[0x13]);
      if (iVar2 < 1) {
        __s_01 = (void *)0x0;
        if (apdb_err_switch != 0) {
          pcVar4 = "[APDB_ERROR]%s()/line %d : you haven\'t loaded new apdb.\n";
          uVar5 = 0x4c9;
LAB_0060386c:
          printf(pcVar4,"_apdb_ap_merge_finish",uVar5);
        }
LAB_00603710:
        iVar8 = puVar7[0x13];
      }
      else {
        __s_01 = (void *)FUN_00408450(local_34,0x4d0);
        if (__s_01 != (void *)0x0) {
          memset(__s_01,0,(size_t)local_34);
          _apdb_ap_copy(__s_01,pvVar3,iVar2);
          goto LAB_00603710;
        }
        if (apdb_err_switch != 0) {
          pcVar4 = "[APDB_ERROR]%s()/line %d : malloc apdb_ap failed.\n";
          uVar5 = 0x4d3;
          goto LAB_0060386c;
        }
        iVar8 = puVar7[0x13];
      }
      puVar7[0x15] = __s_01;
      puVar7[0x13] = iVar8 + 1;
LAB_006034e4:
      FUN_00408380(puVar7[0x14],local_38);
      if (param_4 != 0) {
        local_38 = (void *)0x1;
        goto LAB_00603504;
      }
      iVar8 = _ap_item_add_to_config(puVar7,0);
      local_38 = (void *)0x1;
      if (iVar8 == 0) {
LAB_006035f4:
        iVar8 = _apdb_proc_callback_list(__s,local_30,__s_00,unaff_s6,&local_60);
        if (iVar8 != -1) goto LAB_00603508;
        if (apdb_err_switch != 0) {
          pcVar4 = "[APDB_ERROR]%s()/line %d : process apdb callback function list failed.\n";
          uVar5 = 0x1f69;
          goto LAB_00603640;
        }
        goto LAB_00603594;
      }
      iVar8 = -1;
      if (apdb_err_switch == 0) goto LAB_006030a4;
      pcVar4 = "[APDB_ERROR]%s()/line %d : add item to config failed !\n";
      uVar5 = 0x1ef5;
    }
    iVar8 = -1;
    printf(pcVar4,"_apdb_add_ap_to_item_list",uVar5);
  }
LAB_006030a4:
  if (__s_00 != (void *)0x0) {
    _apdb_ap_item_free(__s_00,unaff_s6);
  }
  if (pvVar3 != (void *)0x0) {
    _apdb_ap_free(pvVar3,iVar2);
  }
  if (__s != (void *)0x0) {
    _apdb_ap_item_free(__s,local_30);
  }
  return iVar8;
}

