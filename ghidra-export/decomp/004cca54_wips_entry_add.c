// func wips_entry_add @ 004cca54 size=1548

void wips_entry_add(void *param_1,char *param_2,undefined4 param_3,int param_4,char *param_5)

{
  undefined2 uVar1;
  bool bVar2;
  int iVar3;
  void *__s;
  int iVar4;
  uint uVar5;
  void *__dest;
  undefined4 uVar6;
  uint uVar7;
  int iVar8;
  undefined4 local_res8 [2];
  undefined4 local_528;
  uint local_524;
  undefined2 local_520;
  undefined4 local_51c;
  undefined4 local_518;
  undefined4 local_514;
  undefined4 local_510;
  undefined2 local_50c;
  undefined1 auStack_508 [520];
  undefined1 auStack_300 [16];
  undefined2 local_2f0;
  int local_2c4;
  
  if (g_wips_enable == 0) {
    return;
  }
  local_51c = 0;
  local_518 = 0;
  local_514 = 0;
  local_510 = 0;
  local_50c = 0;
  local_res8[0] = param_3;
  wips_mac2str(param_1,&local_51c);
  if (sensor_debug_switch != '\0') {
    printf("[SENSOR_DEBUG]%s()/%d receive wips. type: %d, dev_mac: %s, ssid: %s[%d]\n",
           "wips_entry_add",0xd6a,*(undefined4 *)(param_4 + 0x28),&local_51c,param_2,local_res8[0]);
  }
  uVar7 = *(uint *)(param_4 + 0x28);
  memset(auStack_508,0,0x205);
  local_528 = 0;
  local_524 = 0;
  local_520 = 0;
  memset(auStack_300,0,0x2d8);
  iVar3 = apmngr_db_entry_get_by_id(*(undefined2 *)(param_4 + 0x38),auStack_300);
  if (iVar3 == -1) {
    return;
  }
  if (local_2c4 == 0) {
    return;
  }
  iVar3 = sensor_is_bh_testing(local_2f0);
  if (iVar3 == 1) {
    return;
  }
  if (*(int *)(param_4 + 0x28) + 0xfecea7fcU < 2) {
    memcpy(&local_528,param_1,6);
    iVar3 = stats_db_bssid_get(&local_528);
    if (iVar3 == 0) {
      if (sensor_debug_switch == '\0') {
        uVar1 = *(undefined2 *)(param_4 + 0x38);
      }
      else {
        printf("[SENSOR_DEBUG]%s()/%d bssid_info: ap_id: %d, radio_id: %d, wlan_id: %d\n",
               "wips_entry_add",0xd8c,local_524 & 0xffff,(uint)local_520._0_1_,(uint)(byte)local_520
              );
        uVar1 = *(undefined2 *)(param_4 + 0x38);
      }
      FUN_004c8a08(&local_528,1,uVar1);
      return;
    }
  }
  iVar3 = whitelist_check_match(param_1,param_2,local_res8[0],param_4);
  if (iVar3 == 1) {
    return;
  }
  if ((*(int *)(param_4 + 0x28) == 0x1315804) &&
     (iVar3 = wserv_db_get_entry_by_ssid(param_2,local_res8[0],auStack_508), iVar3 == 0)) {
    wips_ssid_whitelist_add_send(param_2,local_res8,1,*(undefined2 *)(param_4 + 0x38));
    return;
  }
  FUN_004082d0(wips_global_mutex,0xffffffff);
  for (__s = (void *)FUN_004081b0(&g_wips_list); __s != (void *)0x0; __s = (void *)FUN_00408680(__s)
      ) {
    iVar3 = wips_info_match(__s,uVar7,param_1,param_2,local_res8[0]);
    if (iVar3 != 0) {
      iVar8 = (int)__s + 0x9c;
      iVar3 = FUN_004081b0(iVar8);
      goto LAB_004ccd00;
    }
  }
  if (sensor_debug_switch != '\0') {
    printf("[SENSOR_DEBUG]%s()/%d add new info to wips list\n","wips_entry_add",0xdd4);
  }
  __s = (void *)FUN_00408450(0xb0,0xdd5);
  if (__s != (void *)0x0) {
    memset(__s,0,0xb0);
    iVar3 = FUN_004085b0(g_wips_id_allocator);
    *(int *)((int)__s + 0xc) = iVar3;
    if (iVar3 == -1) {
      if (sensor_err_switch != '\0') {
        printf("[SENSOR_ERROR]%s()/%d alloc wips info id error\n","wips_entry_add",0xde2);
      }
      bVar2 = false;
      FUN_00407df0(__s);
      goto LAB_004cccc0;
    }
    strcpy((char *)((int)__s + 0x10),param_2);
    *(undefined4 *)((int)__s + 0x44) = local_res8[0];
    if (0x13157f9 < uVar7) {
      __dest = (void *)((int)__s + 0x4e);
      if (0x13157fe < uVar7) {
        if (3 < uVar7 + 0xfecea7fe) goto LAB_004ccee0;
        __dest = (void *)((int)__s + 0x48);
      }
      memcpy(__dest,param_1,6);
    }
LAB_004ccee0:
    strcpy((char *)((int)__s + 0x54),param_5);
    uVar6 = 1;
    if ((uVar7 != 0x13157f9) && (uVar6 = 3, uVar7 != 0x1315805)) {
      uVar6 = 2;
    }
    *(undefined4 *)((int)__s + 0x94) = uVar6;
    uVar5 = 0;
    if (uVar7 + 0xfecea807 < 0xd) {
      uVar5 = (uint)*(byte *)(uVar7 - 0xc6d429);
    }
    *(uint *)((int)__s + 0x98) = uVar5;
    FUN_0051ad88((int)__s + 0x9c);
    *(undefined4 *)((int)__s + 0xa8) = 1;
    uVar6 = 2;
    if (1 < uVar7 + 0xfecea7fc) {
      uVar6 = 0;
    }
    *(undefined4 *)((int)__s + 0xac) = uVar6;
    wips_detail_entry_add((int)__s + 0x9c,param_4);
    *(void **)(g_wips_id2entry + *(int *)((int)__s + 0xc) * 4) = __s;
    FUN_004c7c60(__s);
    iVar3 = *(int *)((int)__s + 0x98);
    goto LAB_004ccdb8;
  }
  bVar2 = false;
  if (sensor_err_switch == '\0') goto LAB_004cccc0;
  uVar6 = 0xdd8;
LAB_004ccfc4:
  bVar2 = false;
  printf("[SENSOR_ERROR]%s()/%d out of memory\n","wips_entry_add",uVar6);
  goto LAB_004cccc0;
LAB_004ccd00:
  if (iVar3 == 0) goto LAB_004ccd98;
  iVar4 = strcmp((char *)(iVar3 + 0xc),(char *)(param_4 + 0xc));
  if (iVar4 == 0) {
    *(undefined4 *)(iVar3 + 0x20) = *(undefined4 *)(param_4 + 0x20);
    *(undefined4 *)(iVar3 + 0x24) = *(undefined4 *)(param_4 + 0x24);
    *(undefined4 *)(iVar3 + 0x34) = *(undefined4 *)(param_4 + 0x34);
    *(undefined4 *)(iVar3 + 0x30) = *(undefined4 *)(param_4 + 0x30);
    FUN_00408500(iVar3);
    wips_detail_insert_to_list(iVar8,iVar3);
    goto LAB_004ccda4;
  }
  iVar3 = FUN_00408680(iVar3);
  goto LAB_004ccd00;
LAB_004ccd98:
  wips_detail_entry_add(iVar8,param_4);
LAB_004ccda4:
  FUN_00408500(__s);
  FUN_004c7c60(__s);
  iVar3 = *(int *)((int)__s + 0x98);
LAB_004ccdb8:
  bVar2 = false;
  if ((1 < iVar3 - 5U) || (iVar3 = FUN_00407fa0(g_counter_info_hash,(int)__s + 0x48), iVar3 == 0))
  goto LAB_004cccc0;
  if (*(int *)((int)__s + 0xac) == 2) {
    *(undefined4 *)((int)__s + 0xac) = 1;
    iVar8 = FUN_00408450(0x10,0xe18);
    if (iVar8 == 0) {
      if (sensor_err_switch == '\0') goto LAB_004cccc0;
      uVar6 = 0xe1b;
      goto LAB_004ccfc4;
    }
    *(undefined4 *)(iVar8 + 0xc) = *(undefined4 *)((int)__s + 0xc);
    FUN_004086b0(iVar3 + 8,iVar8);
    uVar6 = *(undefined4 *)(param_4 + 0x34);
  }
  else {
    uVar6 = *(undefined4 *)(param_4 + 0x34);
  }
  bVar2 = false;
  iVar8 = wips_channel_contain(iVar3 + 0x14,uVar6);
  if (iVar8 != 1) {
    wips_channel_set(iVar3 + 0x14,uVar6);
    bVar2 = true;
  }
LAB_004cccc0:
  FUN_00407f30(wips_global_mutex);
  if (bVar2) {
    if (sensor_debug_switch != '\0') {
      printf("[SENSOR_DEBUG]%s()/%d counter[mac=%s] due to channel change\n","wips_entry_add",0xe31,
             &local_51c);
    }
    wips_counter_send(param_1,1,1);
  }
  return;
}

