// func sensor_di_db_add_new_sensor_to_cached_list @ 004dda28 size=1072

void sensor_di_db_add_new_sensor_to_cached_list(int param_1)

{
  bool bVar1;
  void *__s;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  undefined2 uVar5;
  undefined1 uVar6;
  int *piVar7;
  int iVar8;
  void *pvVar9;
  undefined1 auStack_d0 [5];
  undefined1 local_cb;
  
  if (sensor_di_debug_switch != 0) {
    printf("[SENSOR_DI_DEBUG]%s()/line %d : sensor_di_db_add_new_sensor_to_cached_list ENTER\n",
           "sensor_di_db_add_new_sensor_to_cached_list",0x844);
  }
  FUN_004082d0(l_sensor_di_data_mutex,0xffffffff);
  __s = (void *)_sensor_di_db_check_sensor_exists_in_cached_list(param_1);
  if (__s != (void *)0x0) {
    FUN_00408500(__s);
LAB_004dda98:
    FUN_004086b0(&l_sensor_di_cached_sensor_list,__s);
    goto LAB_004ddaa0;
  }
  iVar2 = 0;
  piVar7 = l_sensor_di_setting;
  do {
    if (l_sensor_di_setting_cnt <= iVar2) goto LAB_004ddaa0;
    iVar8 = *piVar7;
    iVar2 = iVar2 + 1;
    piVar7 = piVar7 + 0x29;
  } while (param_1 != iVar8);
  while (uVar4 = FUN_00407fe0(&l_sensor_di_cached_sensor_list),
        l_sensor_di_cache_sensor_max <= uVar4) {
    if (sensor_di_debug_switch != 0) {
      printf("[SENSOR_DI_DEBUG]%s()/line %d : sensor num over the maximum, delete one\n",
             "sensor_di_db_add_new_sensor_to_cached_list",0x862);
    }
    uVar3 = FUN_004081b0(&l_sensor_di_cached_sensor_list);
    FUN_00408500(uVar3);
    _sensor_di_db_sensor_di_data_free(uVar3);
  }
  __s = (void *)FUN_00408450(0x1c548,0x869);
  if (__s == (void *)0x0) {
    if (sensor_di_err_switch != 0) {
      printf("[SENSOR_DI_ERROR]%s()/line %d : malloc new sensor node fail.\n",
             "sensor_di_db_add_new_sensor_to_cached_list",0x86c);
    }
    goto LAB_004ddaa0;
  }
  memset(__s,0,0x1c548);
  *(int *)((int)__s + 0xc) = param_1;
  memset(auStack_d0,0,0xa4);
  FUN_0051ad88((int)__s + 0x18);
  *(undefined2 *)((int)__s + 0x1c514) = 0xffff;
  *(undefined4 *)((int)__s + 0x1c520) = 0;
  FUN_0051ad88((int)__s + 0x1c530);
  *(undefined4 *)((int)__s + 0x1c53c) = 0;
  iVar2 = FUN_004080a0(_sensor_di_ssid_hash_obj,_sensor_di_ssid_hash_key,_sensor_di_ssid_hash_cmp,
                       1000);
  *(int *)((int)__s + 0x1c53c) = iVar2;
  if (iVar2 == 0) {
    if (sensor_di_err_switch != 0) {
      uVar3 = 0x6c7;
LAB_004dddec:
      printf("[SENSOR_DI_ERROR]%s()/line %d : hash create fail\n",
             "_sensor_di_db_new_sensor_data_node_init",uVar3);
    }
LAB_004ddd10:
    if (*(int *)((int)__s + 0x1c53c) != 0) {
      FUN_00408310();
      *(undefined4 *)((int)__s + 0x1c53c) = 0;
    }
    if (*(int *)((int)__s + 0x1c540) != 0) {
      FUN_00408310();
      *(undefined4 *)((int)__s + 0x1c540) = 0;
    }
    if (*(int *)((int)__s + 0x1c544) != 0) {
      FUN_00408310();
      *(undefined4 *)((int)__s + 0x1c544) = 0;
    }
  }
  else {
    *(undefined4 *)((int)__s + 0x1c540) = 0;
    iVar2 = FUN_004080a0(_sensor_di_bssid_hash_obj,_sensor_di_bssid_hash_key,
                         _sensor_di_bssid_hash_cmp,1000);
    *(int *)((int)__s + 0x1c540) = iVar2;
    if (iVar2 == 0) {
      if (sensor_di_err_switch != 0) {
        uVar3 = 0x6cf;
        goto LAB_004dddec;
      }
      goto LAB_004ddd10;
    }
    *(undefined4 *)((int)__s + 0x1c544) = 0;
    iVar2 = FUN_004080a0(_sensor_di_sta_hash_obj,_sensor_di_sta_hash_key,_sensor_di_sta_hash_cmp,
                         1000);
    *(int *)((int)__s + 0x1c544) = iVar2;
    if (iVar2 == 0) {
      if (sensor_di_err_switch != 0) {
        uVar3 = 0x6d7;
        goto LAB_004dddec;
      }
      goto LAB_004ddd10;
    }
    iVar2 = sensor_di_db_get_specified_di_setting(*(undefined4 *)((int)__s + 0xc),auStack_d0);
    if (iVar2 != -1) {
      uVar5 = _sensor_di_db_get_chnl_cnt(local_cb);
      bVar1 = sensor_di_debug_switch != 0;
      *(undefined2 *)((int)__s + 0x10) = uVar5;
      if (bVar1) {
        printf("[SENSOR_DI_DEBUG]%s()/line %d : new_sensor_data_ptr->util_info_chnl_cnt=%d\n",
               "_sensor_di_db_new_sensor_data_node_init",0x6e2);
      }
      pvVar9 = __s;
      for (iVar2 = 0; (iVar2 < *(short *)((int)__s + 0x10) && (iVar2 != 0x19)); iVar2 = iVar2 + 1) {
        uVar6 = _sensor_di_db_get_chnl_by_idx(iVar2,local_cb);
        *(undefined1 *)((int)pvVar9 + 0x26) = uVar6;
        pvVar9 = (void *)((int)pvVar9 + 0x1c);
      }
      goto LAB_004dda98;
    }
  }
  if (sensor_di_err_switch != 0) {
    printf("[SENSOR_DI_ERROR]%s()/line %d : new_sensor_data_node_init fail.\n",
           "sensor_di_db_add_new_sensor_to_cached_list",0x875);
  }
  _sensor_di_db_sensor_di_data_free(__s);
LAB_004ddaa0:
  FUN_00407f30(l_sensor_di_data_mutex);
  return;
}

